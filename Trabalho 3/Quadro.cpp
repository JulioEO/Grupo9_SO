//Quadro.cpp
#include <iostream>
#include "Quadro.h"
using namespace Quadro_obj;

Quadro::Quadro(int s){//construtor recebe o tamanho do quadro,
	setSize(s);
	setinUse(false);
	setProcessid(0);
}

void Quadro::setProcessid(int pid){
	processid = pid;
}

int Quadro::getProcessid(){
	return processid;
}

void Quadro::setSize(int s){
	size = s;
}

int Quadro::getSize(){
	return size;
}

void Quadro::setinUse(bool u){
	inuse = u;
}

bool Quadro::inUse(){
	return inuse;
}
