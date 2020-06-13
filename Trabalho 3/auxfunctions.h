//auxfunctions header
#pragma once
#include<iostream>
#include<fstream>



namespace auxfunctions{

    void readfileline(std::ifstream& file ,int* pid,char* inst,int* addr);
}
