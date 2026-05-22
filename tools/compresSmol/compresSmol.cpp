#include <filesystem>
#include <mutex>
#include <thread>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "fileDispatcher.h"
#include "compressAlgo.h"

enum Option
{
    OPTION_WRITE,
    OPTION_FRAME_WRITE,
    OPTION_DECODE,
    OPTION_USAGE,
};

size_t totalAllocated = 0;
size_t totalFreed = 0;
size_t allocationCount = 0;

void* operator new(size_t size)
{
    totalAllocated += size;
    allocationCount++;
    return std::malloc(size);
}

static Option getOptionFromStr(const std::string& str);

void operator delete(void* ptr, size_t size) noexcept
{
    totalFreed += size;
    std::free(ptr);
}

void printMemoryReport()
{
    std::cout << "\n--- Memory Report ---\n";
    std::cout << "Total allocations: " << allocationCount << "\n";
    std::cout << "Total allocated:   " << totalAllocated << " bytes\n";
    std::cout << "Total freed:       " << totalFreed << " bytes\n";
    std::cout << "Leaked:            " << (totalAllocated - totalFreed) << " bytes\n";
}



int main(int argc, char *argv[])
{
    Option option = OPTION_USAGE;
    bool printUsage = false;
    std::string input;
    std::string output;
    InputSettings settings(true, true, true);
    std::atexit(printMemoryReport);

    if (argc > 1)
    {
        std::string argument = argv[1];
        option = getOptionFromStr(argument);
    }

    switch (option)
    {
    case OPTION_FRAME_WRITE:
        //  Not implemented yet
        std::fprintf(stderr, "Frame writing isn't implemented yet\n");
        settings.useFrames = true;
        option = OPTION_WRITE;
        return 1;
    case OPTION_WRITE:
        if (argc > 3)
        {
            input = argv[2];
            output = argv[3];
            if (argc > 6)
            {
                std::string setting1 = argv[4];
                std::string setting2 = argv[5];
                std::string setting3 = argv[6];
                if (setting1.compare("true") == 0)
                    settings.canEncodeLO = true;
                else if (setting1.compare("false") == 0)
                    settings.canEncodeLO = false;
                else
                    std::fprintf(stderr, "Unrecognized setting1 \"%s\", defaulting to \"true\"\n", setting1.c_str());
                if (setting2.compare("true") == 0)
                    settings.canEncodeSyms = true;
                else if (setting2.compare("false") == 0)
                    settings.canEncodeSyms = false;
                else
                    std::fprintf(stderr, "Unrecognized setting2 \"%s\", defaulting to \"true\"\n", setting2.c_str());
                if (setting3.compare("true") == 0)
                    settings.canDeltaSyms = true;
                else if (setting3.compare("false") == 0)
                    settings.canDeltaSyms = false;
                else
                    std::fprintf(stderr, "Unrecognized setting3 \"%s\", defaulting to \"true\"\n", setting3.c_str());
            }
        }
        else
        {
            printUsage = true;
        }
        break;
    case OPTION_DECODE:
        if (argc > 3)
        {
            input = argv[2];
            output = argv[3];
        }
        else
        {
            printUsage = true;
        }
        break;
    case OPTION_USAGE:
        printUsage = true;
        break;
    }

    if (printUsage)
    {
        std::printf("Usage:\n\
                %s -w \"path/to/some/file.4bpp\" \"path/to/some/file.4bpp.smol\"\
                    Compresses the first argument and writes the result to the second argument.\n\
                These modes can also be appended with 4 true/false statements that control the following settings of the compression:\n\
                    - If the compression instructions can be tANS encoded.\n\
                    - If the raw symbols in the compression can be tANS encoded.\n\
                    - If the compression instructions can be delta encoded.\n\
                    - If the raw symbols in the compression can be delta encoded.\n\
                %s -d \"path/to/some/file.4bpp.smol\" \"path/to/some/file.4bpp\"\n\
                    Decompresses the first argument and writes it to the second argument.", argv[0], argv[0]);

        return 0;
    }

    if (option == OPTION_WRITE)
    {
        if (std::filesystem::exists(input))
        {
            CompressedImage image;
            if (settings.useFrames)
                image = processImageFrames(input, settings);
            else
                image = processImage(input, settings);
                
            if (image.isValid)
            {
                std::ofstream fileOut(output.c_str(), std::ios::out | std::ios::binary);
                fileOut.write(reinterpret_cast<const char *>(image.writeVec.data()), image.writeVec.size()*4);
                fileOut.close();
            }
            else
            {
                std::fprintf(stderr, "Failed to compress image %s\n", image.fileName.c_str());
            }
        }
        else
        {
            std::fprintf(stderr, "Input file %s doesn't exist\n", input.c_str());
        }
    }
    if (option == OPTION_DECODE)
    {
        if (std::filesystem::exists(input))
        {
            std::vector<unsigned int> inData;
            if (!readFileAsUInt(input, &inData))
            {
                return 0;
            }
            std::vector<unsigned short> image4bpp;
            readRawDataVecs(&inData, &image4bpp);
            std::vector<unsigned char> charVec(image4bpp.size()*2);
            for (size_t i = 0; i < image4bpp.size(); i++)
            {
                charVec[2*i] = image4bpp[i] & 0xff;
                charVec[2*i + 1] = (image4bpp[i] >> 8) & 0xff;
            }
            std::ofstream fileOut(output.c_str(), std::ios::out | std::ios::binary);
            std::copy(charVec.begin(), charVec.end(), std::ostreambuf_iterator<char>(fileOut));
            fileOut.close();
        }
        else
        {
            std::fprintf(stderr, "Input file %s doesn't exist\n", input.c_str());
        }
    }

    return 0;
}

static Option getOptionFromStr(const std::string& str)
{
    if (str == "-w")  return OPTION_WRITE;
    if (str == "-fw") return OPTION_FRAME_WRITE;
    if (str == "-d")  return OPTION_DECODE;

    return OPTION_USAGE;
}
