#include "PNG.hh"

bool PNG::isThis(const unsigned char* file) {
    const unsigned char magic[] = {0x89, 'P', 'N', 'G', 0x0d, 0x0a, 0x1a, 0x0a};
    
    for (int i = 0; i < sizeof(magic) / sizeof(magic[0]); i++) {
        if (file[i] != magic[i]) {
            return false;
        }
    }
    
    return true;
}

std::string PNG::getFileExtension() {
    return "png";
}