//auxfunctions.h
#pragma once
#include <fstream>

namespace auxfunctions{

    void readfileline(std::ifstream& file ,int* pid,char* inst,int* addr);
}
