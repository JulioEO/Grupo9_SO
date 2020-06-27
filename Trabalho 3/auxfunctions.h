//auxfunctions.h
#pragma once
#include <fstream>

namespace auxfunctions{

    bool readfileline(std::ifstream &file ,int* pid,char* inst,int* addr);
    //int frameallocation(processos.back(),quadros,numquad,address,tampag);
}
