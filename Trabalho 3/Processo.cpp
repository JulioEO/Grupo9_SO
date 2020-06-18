//Processo.cpp
#include "Pagina.h"
#include "Processo.h"
#include <vector>
using namespace Processo_obj;

Processo::Processo(int m_id,int m_size,int pagenumber, int pagesize){
	id = m_id;
	size = m_size;
	pagetable.resize(pagenumber,Pagina(pagesize));

}

int Processo::getId(){
	return id;
}

int Processo::getSize(){
	return size;
}


