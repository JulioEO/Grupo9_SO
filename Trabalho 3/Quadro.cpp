//Quadro.cpp
#include <iostream>
#include "Quadro.h"
using namespace Quadro_obj;

//construtor recebe o tamanho do quadro, coloca a flag de uso em falso e zera o id do processo
Quadro::Quadro(int s){
	size = s;
	setinUse(false);
	setProcessid(0);
}

void Quadro::setProcessid(int pid){
	processid = pid;
}

int Quadro::getProcessid(){
	return processid;
}


int Quadro::getSize(){
	return size;
}

void Quadro::setinUse(bool u){
	inuse = u;
}

//retorna true se o quadro estiver um uso, ou seja, tem uma pagina alocada
bool Quadro::inUse(){
	return inuse;
}
