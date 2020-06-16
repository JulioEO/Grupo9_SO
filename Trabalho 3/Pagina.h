//Pagina.h
#pragma once


namespace Pagina_obj{

	class Pagina
	{
	public:
		Pagina(int s);
		~Pagina();
		int getSize();
		void setInRAM(bool b);
		bool isinRAM();
		void setOwner(int owner);
		int getOwner();
		void setFramepos(int framepos);
		int getFrameposition();
		bool getReference();
		void setReference(bool r);
	//TODO other functions
	private:
		bool inRAM;
		int size;
		int ownerprocess;
		int frameposition;
		bool reference;
	};
}