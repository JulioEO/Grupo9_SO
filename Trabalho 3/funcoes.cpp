// algumas funcoes que podem ser necessarias

#include <string>
#include <vector>
using namespace std;

// tem algumas mencoes de binario, entao talvez essas funcoes ajudem
int bin2dec(string bin){
    int d = 0;
    int n = 1;

    for (int i = bin.size()-1; i >= 0; i--)
    {
        d += n * ( bin[i] - '0');
        n *=2;
    }
    return d;
    
};

string dec2bin(int d){
    if (d < 0) return "ERRO";
    if (d == 0) return "0";
    vector<int> aux;
    string bin = "";
    while(0 < d)
    {
        bin = to_string(d % 2) + bin;
        d = d/2;
    }
    
    return bin;
};

