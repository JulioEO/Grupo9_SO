//auxfunctions.cpp
#include "auxfunctions.h"
#include <iostream>
#include <fstream>
#include <string>


//le uma linha do arquivo. Retorna true se leu uma linha e false caso o contrario
//Tambem retorna o id do processo em processid, o tipo de instrucao em instruction
//e o endereco a ser acessado em addres; se a instrucao for de criacao, address contem o tamanho da imagem do processo
//se a instrucao for de CPU ou de E/S, address contem o numero da instrucao ou dispositivo
bool auxfunctions::readfileline(std::ifstream &file,int* pid, char* inst, int* addr){
    std::string auxstr;

    if(file.eof()==true){ return false;}

    getline(file,auxstr);
    *pid = auxstr.at(1) - '0';
    *inst = auxstr.at(3);

    if (*inst =='C'){
        *addr = std::stoi(auxstr.substr(5));
    }
    else{
        *addr = std::stoi(auxstr.substr(6));
    }

    return true;
}

//aloca o quadro a pagina i
void auxfunctions::frameallocation(Processo& pro,std::vector<Quadro> &quadros, int i, int idquadro,std::queue<Pagina*> &filarelogio){

		pro.getPagina(i).setFramepos(idquadro);
		pro.getPagina(i).setReference(true);
		pro.getPagina(i).setInRAM(true);
		quadros[idquadro].setProcessid(pro.getId());
		quadros[idquadro].setinUse(true);
		filarelogio.push(&pro.getPagina(i));
		std::cout << "Pagina " << i << " do processo "<< pro.getId() << " alocada ao quadro "<< idquadro<<"\n";
	return;
}

//utiliza o algoritmo relogio para encontrar um quadro vazio
int auxfunctions::algoritmorelogio(int numquad,std::vector<Quadro> &quadros , std::queue<Pagina*> &filarelogio){
	int id = -1;

	//se existe um quadro livre, retorna seu indice
	for (std::vector<int>::size_type i = 0; i < quadros.size();i++){
		if(!quadros[i].inUse()){
			return i;
		}
	}
	std::cout << "Page fault!\n";
	for (std::queue<int>::size_type i = 0 ; i<= filarelogio.size();i++){
		//checa se o bit de referencia esta em 1 ou 0
		if(filarelogio.front()->getReference()){

			filarelogio.front()->setReference(false);
			filarelogio.push(filarelogio.front());
			//std::cout << filarelogio.front()->getReference();
			filarelogio.pop();
	        //std::cout << filarelogio.front()->getReference();

		}else{
			id =filarelogio.front()->getFrameposition();
			quadros[id].setProcessid(0);
			quadros[id].setinUse(false);
			filarelogio.front()->setFramepos(-1);
			filarelogio.front()->setInRAM(false);
			std::cout << "Swap-out da pagina do processo " << filarelogio.front()->getOwner() << " alocada ao quadro "<<id<<"\n";
			filarelogio.pop();
			break;
		}
	}

	return id;
}

int auxfunctions::findprocess(int processid, std::vector<Processo> &processos){

	for(std::vector<int>::size_type i = 0; i < processos.size();i++){
		if(processos[i].getId()==processid){
			return i;
		}
	}

	return -1;
}
