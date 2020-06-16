//auxfunctions.cpp
#include <iostream>
#include <fstream>
#include "auxfunctions.h"

//le uma linha do arquivo. Retorna true se leu uma linha e false caso o contrario
//Tambem retorna o id do processo em processid, o tipo de instrucao em instruction
//e o endereco a ser acessado em addres; se a instrucao for de criacao, address contem o tamanho da imagem do processo
//se a instrucao for de CPU ou de E/S, address contem o numero da instrucao ou dispositivo
bool auxfunctions::readfileline(std::ifstream& file,int* pid, char* inst, int* addr){
    //para efeitos de teste
    *inst = 'P';
    *addr = 2;
    *pid = 1;

    return true;
}


