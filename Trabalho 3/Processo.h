//Processo.h
#pragma once
#include "Pagina.h"
#include <vector>
using namespace Pagina_obj;

namespace Processo_obj{

	class Processo
	{
	public:
		Processo(int m_id,int m_size,int pagenumber, int pagesize);
		Pagina getPagina(int i);
		int getId();
		int getSize();

	private:
		int id;//id do processo
		int size;//imagem ou tamanho do processo
		std::vector<Pagina> pagetable;//tabela de paginas do processo
	};

}
