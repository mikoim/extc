#ifndef __extc__PNG__
#define __extc__PNG__

#include "IMagicSign.hh"

class PNG : public IMagicSign {
public:
    bool isThis(const unsigned char*);
    std::string getFileExtension();
};

#endif /* defined(__extc__PNG__) */
