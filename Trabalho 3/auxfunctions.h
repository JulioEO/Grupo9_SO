//auxfunctions.h
#pragma once
#include <fstream>
#include <vector>
#include <queue>
#include "Pagina.h"
#include "Processo.h"
#include "Quadro.h"

using namespace Pagina_obj;
using namespace Processo_obj;
using namespace Quadro_obj;


namespace auxfunctions{

    bool readfileline(std::ifstream &file ,int* pid,char* inst,int* addr);
    void frameallocationclock(Processo& pro, std::vector<Quadro> &quadros, int i, int idquadro);
    int algoritmorelogio(std::vector<Quadro> &quadros , std::vector<Pagina*> &relogio,unsigned int& iterator, int idpagina,Processo& pro);
	int findprocess(int processid, std::vector<Processo> &process);
	void frameallocationsecond(Processo& pro,std::vector<Quadro> &quadros, int i, int idquadro,std::queue<Pagina*> &filasecond);
	int algoritmosecondchance(std::vector<Quadro> &quadros , std::queue<Pagina*> &filasecond);
}
