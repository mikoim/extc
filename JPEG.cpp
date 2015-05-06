#include "JPEG.hh"

bool JPEG::isThis(const unsigned char* file) {
    const unsigned char magic[] = {0xff, 0xd8};
    
    for (int i = 0; i < sizeof(magic) / sizeof(magic[0]); i++) {
        if (file[i] != magic[i]) {
            return false;
        }
    }
    
    return true;
}

std::string JPEG::getFileExtension() {
    return "jpg";
}