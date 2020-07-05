//Quadro.h
#pragma once

namespace Quadro_obj{
    //classe Quadro: representa um quadro na memoria principal do simulador. Contem o id do processo alocado ao quadro, uma flag se estiver em uso
    //e o tamanho do quadro. Um id de processo igual a zero indica que nenhum processo esta alocado
	class Quadro
	{
	public:
		Quadro(int s);
		void setProcessid(int pid);
		int getProcessid();
		int getSize();
		void setinUse(bool u);
		bool inUse();

	private:
		int processid;
		bool inuse;
		int size;
	};

}
