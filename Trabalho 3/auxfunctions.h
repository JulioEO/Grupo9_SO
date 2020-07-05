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
    void frameallocation(Processo& pro, std::vector<Quadro> &quadros, int i, int idquadro,std::queue<Pagina*> &filarelogio);
    int algoritmorelogio(int numquad,std::vector<Quadro> &quadros , std::queue<Pagina*> &filarelogio);
	int findprocess(int processid, std::vector<Processo> &process);
}