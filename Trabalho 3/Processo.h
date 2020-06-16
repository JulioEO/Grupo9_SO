//Processo.h
#pragma once
//#include "Pagina.h"
//#include <vector>
//using namespace Pagina_obj;

namespace Processo_obj{

	class Processo
	{
	public:
		Processo(int m_id,int m_size);
		int getId();
		int getSize();

	private:
		int id;//id do processo
		int size;//imagem ou tamanho do processo
		//std::vector<Pagina*> pagetable;//atributo que aponta para as paginas alocadas ao processo
	};

}
