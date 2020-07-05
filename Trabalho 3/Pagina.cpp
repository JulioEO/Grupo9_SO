//Pagina.cpp
#include "Pagina.h"
using namespace Pagina_obj;

//inicializa o tamanho, o processo dono da pagina e as flags necessarias
Pagina::Pagina(int s, int owner){
	size= s;
	inRAM = false;
	ownerprocess = owner;
	frameposition = -1;
	reference =false;
}


int Pagina::getSize(){
	return size;
}

void Pagina::setInRAM(bool b){
	inRAM = b;
}

bool Pagina::isinRAM(){
	return inRAM;
}

void Pagina::setOwner(int owner){
	ownerprocess = owner;
}

int Pagina::getOwner(){
	return ownerprocess;
}

void Pagina::setFramepos(int framepos){
	frameposition =framepos;
}

int Pagina::getFrameposition(){
	return frameposition;
}

bool Pagina::getReference(){
	return reference;
}

void Pagina::setReference(bool r){
	reference =r;
}
