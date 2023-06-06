#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

const std::vector<char> MP4_SIGNATURE = {0x66, 0x74, 0x79, 0x70};
const long MP4_SIGNATURE_OFFSET = 4;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [filename]" << std::endl;
        return EXIT_FAILURE;
    };

    std::string fileName = argv[1];
    FILE *fp = fopen(fileName.c_str(), "rb");

    if (fp == nullptr) {
        std::cerr << "Sorry, could not open file " << fileName << std::endl;
        return EXIT_FAILURE;
    };

    if(fseek(fp, MP4_SIGNATURE_OFFSET, SEEK_SET) != 0) {
        std::cerr << "Error seeking to the desired offset." << std::endl;
        return EXIT_FAILURE;
    };

    std::vector<char> buffer(MP4_SIGNATURE.size());
    size_t numRead = fread(buffer.data(), sizeof(char), MP4_SIGNATURE.size(), fp);
    
    if(numRead != MP4_SIGNATURE.size()) {
        std::cerr << "Couldn't read the first " << MP4_SIGNATURE.size() << " bytes" << std::endl;
        return EXIT_FAILURE;
    };

    if(buffer == MP4_SIGNATURE) {
        std::cout << "Yes!" << std::endl;
    } else {
        std::cout << "No!" << std::endl;
    }
    
    fclose(fp);
    return 0;
}