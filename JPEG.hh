#ifndef __extc__JPEG__
#define __extc__JPEG__

#include "IMagicSign.hh"

class JPEG : public IMagicSign {
public:
    bool isThis(const unsigned char*);
    std::string getFileExtension();
};

#endif /* defined(__extc__JPEG__) */
