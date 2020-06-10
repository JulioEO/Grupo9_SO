#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	int tampag, tamendlog, tammemfis, tammemsec, numpag, numquad;//declaracao dos tamanho necessarios
	string auxstring;//string auxiliar para obtencao de entrada do usuario
	stringstream auxstream;//stream auxiliar para obtencao de entrada do usuario

	//blocos para receber os tamanhos do usuario
	cout << "Digite o tamanho das paginas\n";
	while(true){
        auxstream.clear();
		getline(cin, auxstring);
		auxstream << auxstring;
		cout <<auxstream <<"\n";
		auxstream >> tampag;
		cout <<auxstream<< "\n";

		if(auxstream.fail()){//valor nao eh numero

            cout <<auxstream;
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
            auxstream.clear();
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
            auxstream.clear();
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
            auxstream.clear();
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


	ifstream file("arquivo.txt");
	file.close();

	return 0;
}
