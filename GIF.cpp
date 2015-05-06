#include "GIF.hh"

bool GIF::isThis(const unsigned char* file) {
    const unsigned char magic[] = {0x47, 0x49, 0x46};
    
    for (int i = 0; i < sizeof(magic) / sizeof(magic[0]); i++) {
        if (file[i] != magic[i]) {
            return false;
        }
    }
    
    return true;
}

std::string GIF::getFileExtension() {
    return "gif";
}