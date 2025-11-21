<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="sobel_hls" top="sobel_accel">
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="false" ldflags="" mflags=""/>
    </Simulation>
    <files>
        <file name="../src/sobel.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../src/kernel.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../src/sobel.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../src/kernel.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions>
        <solution name="solution1" status=""/>
    </solutions>
</AutoPilot:project>

