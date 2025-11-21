#!/bin/bash

v++ -l --platform xilinx_u280_xdma_201920_3 \
    sobel.xo -o sobel_u280.xclbin \
    --kernel_frequency 300
