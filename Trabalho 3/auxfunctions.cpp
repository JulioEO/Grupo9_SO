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

//aloca o quadro a pagina i e coloca a pagina na fila do second chance
void auxfunctions::frameallocationsecond(Processo& pro,std::vector<Quadro> &quadros, int i, int idquadro,std::queue<Pagina*> &filasecond){

		//"Remove" a pagina da RAM
		pro.getPagina(i).setFramepos(idquadro);
		pro.getPagina(i).setReference(true);
		pro.getPagina(i).setInRAM(true);
		//libera o quadro
		quadros[idquadro].setProcessid(pro.getId());
		quadros[idquadro].setinUse(true);
		//adiciona a pagina i a fila circular do relogio
		filasecond.push(&pro.getPagina(i));
		std::cout << "Pagina " << i << " do processo "<< pro.getId() << " alocada ao quadro "<< idquadro<<"\n";

	return;
}

//utiliza o algoritmo secondchance para encontrar um quadro vazio
int auxfunctions::algoritmosecondchance(std::vector<Quadro> &quadros , std::queue<Pagina*> &filasecond){
	int id = -1;

	//se existe um quadro livre, retorna seu indice
	for (std::vector<int>::size_type i = 0; i < quadros.size();i++){
		if(!quadros[i].inUse()){
			return i;
		}
	}
	//caso contrario aciona um page fault
	std::cout << "Page fault!\n";
	for (std::queue<int>::size_type i = 0 ; i<= filasecond.size();i++){
		//checa se o bit de referencia esta em 1 ou 0
		if(filasecond.front()->getReference()){
			//se for 1, muda para zero e coloca a pagina no final da fila
			filasecond.front()->setReference(false);
			filasecond.push(filasecond.front());
			filasecond.pop();


		}else{
			id =filasecond.front()->getFrameposition();
			quadros[id].setProcessid(0);
			quadros[id].setinUse(false);
			filasecond.front()->setFramepos(-1);
			filasecond.front()->setInRAM(false);
			std::cout << "Swap-out da pagina do processo " << filasecond.front()->getOwner() << " alocada ao quadro "<<id<<"\n";
			filasecond.pop();
			break;
		}
	}

	return id;
}

//encontra um processo no vetor de processos a partir de seu id
int auxfunctions::findprocess(int processid, std::vector<Processo> &processos){

	for(std::vector<int>::size_type i = 0; i < processos.size();i++){
		if(processos[i].getId()==processid){
			return i;
		}
	}

	return -1;
}


//aloca o quadro a pagina i
void auxfunctions::frameallocationclock(Processo& pro,std::vector<Quadro> &quadros, int i, int idquadro){

		//"Remove" a pagina da RAM
		pro.getPagina(i).setFramepos(idquadro);
		pro.getPagina(i).setReference(true);
		pro.getPagina(i).setInRAM(true);

		//libera o quadro
		quadros[idquadro].setProcessid(pro.getId());
		quadros[idquadro].setinUse(true);



		std::cout << "Pagina " << i << " do processo "<< pro.getId() << " alocada ao quadro "<< idquadro<<"\n";

	return;
}

//utiliza o algoritmo relogio para encontrar um quadro vazio
int auxfunctions::algoritmorelogio(std::vector<Quadro> &quadros , std::vector<Pagina*> &relogio,unsigned int& iterator, int idpagina,Processo& pro){
	int id = -1;

	//se existe um quadro livre, retorna seu indice
	for (std::vector<int>::size_type i = 0; i < quadros.size();i++){

		if(!quadros[i].inUse()){
			for (std::vector<int>::size_type j =0 ; j<relogio.size();j++){

				if(relogio.at(j) ==NULL){

					relogio[j] = &pro.getPagina(idpagina);
					break;
				}
			}

			return i;
		}
	}
	//caso contrario aciona um page fault
	std::cout << "Page fault!\n";
	for (std::vector<int>::size_type i = 0 ; i<= relogio.size();i++){
		//std::cout<<"here3";
		//checa se o bit de referencia esta em 1 ou 0
		if(relogio.at(iterator)->getReference()){
			//se for 1, muda para zero e coloca a move a cabeca para a proxima pagina
			relogio.at(iterator)->setReference(false);
			if (iterator< (relogio.size() - 1)){
				iterator++;
			}
			else {
				iterator =0;
			}
			//std::cout<<"here4";

		}else{
			id =relogio.at(iterator)->getFrameposition();
			
			//std::cout << relogio.at(iterator)->getFrameposition() <<" !"<< iterator;
			
			quadros[id].setProcessid(0);
			quadros[id].setinUse(false);
			relogio.at(iterator)->setFramepos(-1);
			relogio.at(iterator)->setInRAM(false);
			std::cout << "Swap-out da pagina do processo " << relogio.at(iterator)->getOwner() << " alocada ao quadro "<<id<<"\n";
			relogio.at(iterator) = &pro.getPagina(idpagina);
			if (iterator< (relogio.size() - 1)){
				iterator++;
			}
			else {
				iterator =0;
			}
			//std::cout << iterator<<"esse eh o taual\n";
			break;
		}
	}

	return id;
}
