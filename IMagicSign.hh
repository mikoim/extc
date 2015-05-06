#ifndef __extc__IMagicSign__
#define __extc__IMagicSign__

#include <string>

class IMagicSign {
public:
    virtual bool isThis(const unsigned char*) = 0;
    virtual std::string getFileExtension() = 0;
};

#endif /* defined(__extc__IMagicSign__) */
