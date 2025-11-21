#include "kernel.h"

extern "C" {
void sobel_accel(pixel_t *in, pixel_t *out) {
#pragma HLS INTERFACE m_axi port=in  offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=in     bundle=control
#pragma HLS INTERFACE s_axilite port=out    bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    pixel_t in_img[IMG_HEIGHT][IMG_WIDTH];
    pixel_t out_img[IMG_HEIGHT][IMG_WIDTH];

#pragma HLS DATAFLOW


LoadLoop:
    for(int r=0; r<IMG_HEIGHT; r++) {
        for(int c=0; c<IMG_WIDTH; c++) {
#pragma HLS PIPELINE II=1
            in_img[r][c] = in[r*IMG_WIDTH + c];
        }
    }


    sobel_filter(in_img, out_img);


StoreLoop:
    for(int r=0; r<IMG_HEIGHT; r++) {
        for(int c=0; c<IMG_WIDTH; c++) {
#pragma HLS PIPELINE II=1
            out[r*IMG_WIDTH + c] = out_img[r][c];
        }
    }
}
}
