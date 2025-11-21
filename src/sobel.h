#ifndef SOBEL_H
#define SOBEL_H

#include <ap_int.h>
#include <hls_stream.h>

#define IMG_WIDTH   512
#define IMG_HEIGHT  512

typedef ap_uint<8>   pixel_t;
typedef ap_uint<16>  grad_t;


void sobel_filter(pixel_t in_img[IMG_HEIGHT][IMG_WIDTH],
                  pixel_t out_img[IMG_HEIGHT][IMG_WIDTH]);

#endif
