//Pagina.h
#pragma once


namespace Pagina_obj{

	class Pagina
	{
	public:
		Pagina(int s);//ainda falta coisas para inicializar nesse construtor
		int getSize();
		void setInRAM(bool b);
		bool isinRAM();
		void setOwner(int owner);
		int getOwner();
		void setFramepos(int framepos);
		int getFrameposition();
		bool getReference();
		void setReference(bool r);
	private:
		bool inRAM;
		int size;
		int ownerprocess;
		int frameposition;
		bool reference;
	};
}
