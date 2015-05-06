#ifndef __extc__Unknown__
#define __extc__Unknown__

#include "IMagicSign.hh"

class Unknown : public IMagicSign {
public:
    bool isThis(const unsigned char*);
    std::string getFileExtension();
};

#endif /* defined(__extc__Unknown__) */
