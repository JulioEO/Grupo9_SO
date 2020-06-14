//Quadro.h
#pragma once


namespace Quadro_obj{

	class Quadro
	{
	public:
		Quadro(int s,bool u);
		void setProcessid(int pid);
		int getProcessid();
		void setSize(int s);
		int getSize();
		void setinUse(bool u);
		bool inUse();
	private:
		int processid;
		bool inuse;
		int size;	
	};
	
}