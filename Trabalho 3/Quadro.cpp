//Quadro.cpp
#include <iostream>
#include "Quadro.h"
using namespace Quadro_obj;

Quadro_obj::Quadro(int s, bool u){
	setSize(s);
	setUse(u);
	setProcessid(0);
}

void Quadro_obj::setProcessid(int pid){
	processid = pid;
}

int Quadro_obj::getProcessid(){
	return processid;
}

void Quadro_obj::setSize(int s){
	size = s;
}

int Quadro_obj::getSize(){
	return s;
}

void Quadro_obj::setinUse(bool u){
	inuse = u;
}

bool Quadro_obj::inUse(){
	return inuse;
}