#include "sobel.h"


void sobel_filter(pixel_t in_img[IMG_HEIGHT][IMG_WIDTH],
                  pixel_t out_img[IMG_HEIGHT][IMG_WIDTH])
{
#pragma HLS INTERFACE m_axi port=in_img  offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=out_img offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=in_img   bundle=control
#pragma HLS INTERFACE s_axilite port=out_img  bundle=control
#pragma HLS INTERFACE s_axilite port=return   bundle=control

    const int Gx[3][3] = {
        { -1,  0,  1 },
        { -2,  0,  2 },
        { -1,  0,  1 }
    };

    const int Gy[3][3] = {
        {  1,  2,  1 },
        {  0,  0,  0 },
        { -1, -2, -1 }
    };

    pixel_t linebuf[3][IMG_WIDTH];
#pragma HLS ARRAY_PARTITION variable=linebuf complete dim=1

    pixel_t window[3][3];
#pragma HLS ARRAY_PARTITION variable=window complete dim=0

RowLoop:
    for (int r = 0; r < IMG_HEIGHT; r++) {
    ColLoop:
        for (int c = 0; c < IMG_WIDTH; c++) {
#pragma HLS PIPELINE II=1

            if (r == 0) {
                linebuf[0][c] = (pixel_t)0;
            } else {
                linebuf[0][c] = linebuf[1][c];
            }

            if (r <= 1) {
                linebuf[1][c] = (pixel_t)0;
            } else {
                linebuf[1][c] = linebuf[2][c];
            }

            linebuf[2][c] = in_img[r][c];

            window[0][0] = window[0][1];
            window[0][1] = window[0][2];
            window[1][0] = window[1][1];
            window[1][1] = window[1][2];
            window[2][0] = window[2][1];
            window[2][1] = window[2][2];

            window[0][2] = linebuf[0][c];
            window[1][2] = linebuf[1][c];
            window[2][2] = linebuf[2][c];

            if (r < 2 || c < 2) {
                out_img[r][c] = (pixel_t)0;
                continue;
            }

            int gx = 0;
            int gy = 0;

        Compute:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int pix = (int)window[i][j];
                    gx += pix * Gx[i][j];
                    gy += pix * Gy[i][j];
                }
            }

            int abs_gx = (gx < 0) ? -gx : gx;
            int abs_gy = (gy < 0) ? -gy : gy;

            int mag = abs_gx + abs_gy;
            if (mag > 255) mag = 255;

            out_img[r][c] = (pixel_t)mag;
        }
    }
}
