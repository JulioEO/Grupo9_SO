//Processo.cpp
//#include "Pagina.h"
//#include <vector>
using namespace Processo_obj;

Processo::Processo(int m_id,int m_size){
	id = m_id;
	size = m_size;

	//TODO initialize page table?
}

int Processo::getId(){
	return id;
}

int Processo::getSize(){
	return size;
}