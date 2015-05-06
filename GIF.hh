#ifndef __extc__GIF__
#define __extc__GIF__

#include "IMagicSign.hh"

class GIF : public IMagicSign {
public:
    bool isThis(const unsigned char*);
    std::string getFileExtension();
};

#endif /* defined(__extc__GIF__) */
