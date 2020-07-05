#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "auxfunctions.h"
#include "Quadro.h"
#include "Pagina.h"
#include "Processo.h"


using namespace std;
using namespace auxfunctions;
using namespace Quadro_obj;
using namespace Processo_obj;
using namespace Pagina_obj;


int main(int argc, char const *argv[])
{
	int tampag, tamendlog, tammemfis, tammemsec, numpag, numquad;//declaracao dos tamanho necessarios
	ifstream file;
	queue<Pagina*> filasecond;//fila para a execucao do algoritmo do second chance
	//para algoritmo relogio
    vector<Pagina*> relogio;
    unsigned int clockiterator=0;

	int processid = 0;//contem o ID do processo relacionado a instrucao
	int address=0;//contem o endereco da instrucao do arquivo de entrada ou o tamanho da imagem do processo se for criado
	char instruction='0';//contem o tipo de instrucao do arquivo de entrada
	string auxstring;//string auxiliar para obtencao de entrada do usuario
	stringstream auxstream;//stream auxiliar para obtencao de entrada do usuario

	//blocos para receber os tamanhos do usuario
	cout << "Digite o tamanho das paginas\n";
	while(true){
        auxstream.clear();
		getline(cin, auxstring);
		auxstream << auxstring;
		auxstream >> tampag;


		if(auxstream.fail()){//valor nao eh numero

            auxstream.str("");
			cout<<"Digite um numero\n";
		}
		else if(tampag<1){//valor menor que 1
			cout << "Digite um valor maior que zero\n";
		}
		else{//valor valido, sai do loop
			break;
		}
	}

	cout << "Digite o tamanho em bits do endereco logico\n";
	while(true){
        auxstream.clear();
		getline(cin, auxstring);
		auxstream << auxstring;
		auxstream >> tamendlog;

		if(auxstream.fail()){//valor nao eh numero
            auxstream.str("");
			cout<<"Digite um numero\n";
		}
		else if(tamendlog<1){//valor menor que 1
			cout << "Digite um valor maior que zero\n";
		}
		else{//valor valido, sai do loop
			break;
		}
	}

	cout << "Digite o tamanho da memoria fisica\n";
	while(true){
        auxstream.clear();
		getline(cin, auxstring);
		auxstream << auxstring;
		auxstream >> tammemfis;

		if(auxstream.fail()){//valor nao eh numero
            auxstream.str("");
			cout<<"Digite um numero\n";
		}
		else if(tammemfis<1){//valor menor que 1
			cout << "Digite um valor maior que zero\n";
		}
		else{//valor valido, sai do loop
			break;
		}
	}

	cout << "Digite o tamanho em bits da memoria secundaria\n";
	while(true){
        auxstream.clear();
		getline(cin, auxstring);
		auxstream << auxstring;
		auxstream >> tammemsec;

		if(auxstream.fail()){//valor nao eh numero
            auxstream.str("");
			cout<<"Digite um numero\n";
		}
		else if(tammemsec<1){//valor menor que 1
			cout << "Digite um valor maior que zero\n";
		}
		else{//valor valido, sai do loop
			break;
		}
	}

	//definicao do numero de paginas
	numpag = tamendlog/tampag;
	//definicao do numero de quadros
	numquad = tammemfis/tampag;

	//testa se o tamanho da memoria fisica eh multiplo do tamanho de quadro
	if (tammemfis % tampag != 0){
		cout <<  "Tamanho da memoria fisica nao eh multiplo do tamanho de quadro/pagina";
		return -1;
	}


	//inicializacao dos quadros
    vector<Quadro> quadros(numquad,Quadro(tampag));

    //inicializacao do vetor de processos
    vector<Processo> processos;

    relogio.resize(numquad,NULL);

	file.open("arquivo.txt");//abertura do arquivo de leitura
	//testa se o arquivo esta aberto
	if (!file.is_open()) {
		cout << "Erro na abertura do arquivo";
		return -1;
	}

	//loop principal do simulador
	//funcao readfileline le uma linha do arquivo. Retorna true se leu uma linha e false caso o contrario
	//Tambem retorna o id do processo em processid, o tipo de instrucao em instruction
	//e o endereco a ser acessado em addres; se a instrucao for de criacao, address contem o tamanho da imagem do processo
	//se a instrucao for de CPU ou de E/S, address contem o numero da instrucao ou dispositivo
	while(readfileline(file,&processid,&instruction, &address)){

		switch(instruction){
			//operacao de criacao de processo
			case('C'):{

				int idquadro;//indice do quadro que sera alocado
				int framesalocados = address/tampag;//quantidade de quadros que serao alocados

				//se o processo couber em menos de um  quadro, aloca um quadro
				if(framesalocados <1){framesalocados =1;}

				cout<<"Criando processo "<< processid<<"...\n";

				//inicializa um processo eo coloca no vetor de processos
				processos.push_back(Processo(processid,address,numpag,tampag));

				//loop que aloca os quadros
				for (int i = 0; i<framesalocados;i++){

					//utiliza o algoritmo relogio para encontrar um quadro vazio
					idquadro = algoritmorelogio(quadros,relogio,clockiterator,i,processos.back());

					if(idquadro == -1){cout << "Algo de errado ocorreu!(relogio)"; return 1;}
					//aloca o quadro a pagina i
					frameallocationclock(processos.back(),quadros,i,idquadro);
				}
				cout << "Processo "<< processid<< " criado com sucesso!\n\n";
				break;
			}
			//operacao de escrita
			case('W'):{

					//indice do processo que vai escrever
					int indice = findprocess(processid,processos);
					if(indice ==-1){cout << "Algo de errado ocorreu!(find)"; return 1;}

					//checa se o endereco eh valido
					if (address > (processos.at(indice).getSize()-1)){
						cout<< "Acesso indevido! Processo "<<processid<<" tentou acessar endereco "<< address<<" sendo que seu tamanho eh "<<processos.at(indice).getSize() <<"\n";
					}
					//se for valido continua
					else{
						int idpagina = address/tampag;
						int idquadro = processos.at(indice).getPagina(idpagina).getFrameposition();
						//pagina nao esta na ram, tem que colocar
						if(!processos.at(indice).getPagina(idpagina).isinRAM()){

							//utiliza o algoritmo relogio para encontrar um quadro vazio
							idquadro = algoritmorelogio(quadros,relogio,clockiterator,idpagina,processos.at(indice));
							if(idquadro == -1){cout << "Algo de errado ocorreu!(relogio)"; return 1;}

							//aloca o quadro a pagina idpagina
							frameallocationclock(processos.at(indice),quadros,idpagina,idquadro);
						}
						processos.at(indice).getPagina(idpagina).setReference(true);
						cout << "Processo " << processid << " realizou escrita do endereco "<<address<<" na pagina "<<idpagina<<" no quadro "<<idquadro<<"\n\n";
					}


				break;
			}
			//operacao de leitura
			case ('R'):{
					//indice do processo que vai ler
					int indice = findprocess(processid,processos);
					if(indice ==-1){cout << "Algo de errado ocorreu!(find)"; return 1;}

					//checa se o endereco eh valido
					if (address > (processos.at(indice).getSize()-1)){
						cout<< "Acesso indevido! Processo " <<processid <<" tentou acessar endereco "<< address<<" sendo que seu tamanho eh "<<processos.at(indice).getSize() <<"\n";
					}
					//se for valido continua
					else{
						int idpagina = address/tampag;
						int idquadro = processos.at(indice).getPagina(idpagina).getFrameposition();
						//pagina nao esta na ram, tem que colocar
						if(!processos.at(indice).getPagina(idpagina).isinRAM()){

							//utiliza o algoritmo relogio para encontrar um quadro vazio
							idquadro = algoritmorelogio(quadros,relogio,clockiterator,idpagina,processos.at(indice));
							if(idquadro == -1){cout << "Algo de errado ocorreu!(relogio)"; return 1;}

							//aloca o quadro a pagina idpagina
							frameallocationclock(processos.at(indice),quadros,idpagina,idquadro);
						}
						processos.at(indice).getPagina(idpagina).setReference(true);
						cout << "Processo " << processid << " realizou leitura do endereco "<<address<<" na pagina "<<idpagina<<" no quadro "<<idquadro<<"\n\n";
					}

				break;
			}

			//operacao na CPU
			case ('P'):{
				cout<<"Processo "<< processid << " realizou operacao " << address << " na CPU.\n\n";
				break;
			}
			//operacao de E/S
			case('I'):{
				cout<<"Processo "<< processid << " realizou operacao de E/S no dispositivo " << address << "\n\n";
				break;
			}
			default:{
				cout<< "Erro na leitura do arquivo";
				return -1;
			}

		}


	}
	file.close();

	return 0;
}
