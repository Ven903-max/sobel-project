open_project sobel_hls

set_top sobel_accel

add_files ../src/kernel.cpp
add_files ../src/sobel.cpp
add_files ../src/kernel.h
add_files ../src/sobel.h

open_solution "solution1"
set_part {xcu280-fsvh2892-2L-e}
create_clock -period 3.33 -name default

csynth_design
export_design -format xo -output sobel.xo

exit

