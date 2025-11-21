# Sobel Edge Detection Accelerator – Project Update 2
**Venkatesh Pandey

## 1. Project Description
This project implements a Sobel edge-detection accelerator using Vitis HLS and targets FPGA hardware (Versal / U280). The accelerator processes grayscale image data and produces edge-detected output using Sobel gradient kernels (Gx and Gy) on the hardware pipeline.

## 2. What I Completed in Update 2
- Set up Vitis HLS project environment.
- Implemented Sobel accelerator kernel in C++.
- Added AXI4-Stream and AXI-Lite interfaces for HLS synthesis.
- Wrote run_hls.tcl script to automate project creation and synthesis.
- Successfully generated RTL and exported the kernel as an .xo file.
- Organized the project into `src/`, `scripts/`, and `README.md`.

## 3. Input / Output Description
### Input:
- Grayscale pixel stream (AXI4-Stream)
- Image dimensions (rows and columns)

### Output:
- Edge-detected pixel stream (AXI4-Stream)
The generated edge map highlights strong intensity transitions, making image boundaries clearly visible.

### Interpretation:
The output image has bright values at sharp intensity changes (edges) and darker values elsewhere.

## 4. Performance Metrics (for next update)
These metrics will be reported in Update 3:
- Initiation Interval (II)
- Latency (cycles)
- LUT, FF, BRAM, DSP usage
- Achieved clock frequency (Fmax)
- Throughput in pixels/second

## 5. Instructions to Run the Code
1. Load Vitis HLS environment:
   source /tools/Xilinx/Vitis_HLS/2023.2/settings64.sh

2. Navigate to the scripts directory:
   cd sobel_hls/scripts/

3. Run HLS synthesis:
   vitis_hls -f run_hls.tcl

4. The synthesized kernel will appear at:
   sobel_hls/solution1/sobel.xo

## 6. Plan for Next Project Update
- Integrate accelerator into the Vitis flow.
- Build host application to stream images to the FPGA.
- Run full hardware tests on U280 or Versal.
- Measure and compare performance results against CPU implementation.
- Add full design report and optimizations (pipelining, resource balancing).

## 7. AI Assistance Statement
ChatGPT was used for:
- Organizing the project structure
- Writing documentation and explanations
- Assisting with debugging HLS errors
- Generating initial boilerplate code

All coding decisions, implementation, and execution steps were performed manually.

## 8. References
- Xilinx Vitis HLS User Guide (UG1399)
- Xilinx Image Processing Examples
- EECE 5698 Course Material
