#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <cstdio>

#include "IMagicSign.hh"
#include "JPEG.hh"
#include "PNG.hh"
#include "GIF.hh"
#include "Unknown.hh"

#include <dirent.h>

int main(int argc, const char * argv[])
{
    struct dirent *dirst;
    std::regex regex("\\.");
    std::string basedir("/Users/ek/Desktop/miko");
    
    std::vector<IMagicSign*> ms;
    ms.push_back(new JPEG());
    ms.push_back(new PNG());
    ms.push_back(new GIF());
    ms.push_back(new Unknown());
    
    DIR *dp = opendir(basedir.c_str());
    
    while((dirst = readdir(dp)) != NULL)
    {
        if (dirst->d_type == DT_REG and !std::regex_search(dirst->d_name, regex)) {
            unsigned char header[16];
            std::ifstream fin(basedir + "/" + dirst->d_name, std::ios::in | std::ios::binary);
            
            fin.read(reinterpret_cast<char*>(header), sizeof(header));
            std::cout << dirst->d_name;
            
            for (int i = 0; i < ms.size(); i++) {
                if (ms[i]->isThis(header)) {
                    if (ms[i]->getFileExtension() != "") {
                        std::cout << " : " << ms[i]->getFileExtension() << std::endl;
                        
                        std::string old(basedir + "/" + dirst->d_name), newName(old + "." + ms[i]->getFileExtension());
                        
                        rename(old.c_str(), newName.c_str());
                        
                        break;
                    } else {
                        std::cout << " : Unknown | ";
                        
                        for (int i = 0; i < sizeof(header) / sizeof(header[0]); i++) {
                            std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(header[i]) << " ";
                        }
                        
                        std::cout << std::endl;
                        
                        break;
                    }
                }
            }
        }
    }
    
    closedir(dp);
    
    return 0;
}