//Processo.cpp
#include "Pagina.h"
#include "Processo.h"
#include <vector>
using namespace Processo_obj;

//construtor define o id, tamanho e incializa a tabela de paginas com o numero de paginas de um processo
Processo::Processo(int m_id,int m_size,int pagenumber, int pagesize){
	id = m_id;
	size = m_size;
	pagetable.resize(pagenumber,Pagina(pagesize,m_id));

}

//acessa a pagina i da tabela de paginas do processo
Pagina &Processo::getPagina(int i){
	return pagetable.at(i);
}

int Processo::getId(){
	return id;
}

int Processo::getSize(){
	return size;
}


