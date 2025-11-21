#include <iostream>
#include <fstream>
#include <vector>
#include <CL/cl2.hpp>

#define IMG_WIDTH 512
#define IMG_HEIGHT 512

int main(int argc, char** argv) {
    if(argc != 3){
        std::cout << "Usage: ./host <xclbin> <input.raw>\n";
        return -1;
    }

    std::string xclbin = argv[1];
    std::string input_file = argv[2];


    std::vector<unsigned char> input(IMG_WIDTH*IMG_HEIGHT);
    std::ifstream fin(input_file, std::ios::binary);
    fin.read((char*)input.data(), input.size());
    fin.close();


    std::ifstream bx(xclbin, std::ios::binary);
    std::string bin((std::istreambuf_iterator<char>(bx)),
                     std::istreambuf_iterator<char>());

    cl::Context context;
    cl::Device device;
    {
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        platforms[0].getDevices(CL_DEVICE_TYPE_ACCELERATOR, &devices);
        device = devices[0];
        context = cl::Context(device);
    }

    cl::Program::Binaries binaries{{bin.data(), bin.size()}};
    cl::Program program(context, {device}, binaries);

    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    cl::Kernel kernel(program, "sobel_accel");

    cl::Buffer in_buf(context, CL_MEM_READ_ONLY, input.size());
    cl::Buffer out_buf(context, CL_MEM_WRITE_ONLY, input.size());

    q.enqueueWriteBuffer(in_buf, CL_TRUE, 0, input.size(), input.data());

    kernel.setArg(0, in_buf);
    kernel.setArg(1, out_buf);

    q.enqueueTask(kernel);
    q.finish();

    std::vector<unsigned char> output(input.size());
    q.enqueueReadBuffer(out_buf, CL_TRUE, 0, output.size(), output.data());

    std::ofstream fout("output.raw", std::ios::binary);
    fout.write((char*)output.data(), output.size());
    fout.close();

    std::cout << "Execution completed. Output saved to output.raw\n";

    return 0;
}
