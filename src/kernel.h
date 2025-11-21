#ifndef KERNEL_H
#define KERNEL_H

#include "sobel.h"


extern "C" {
void sobel_accel(pixel_t *in, pixel_t *out);
}

#endif

