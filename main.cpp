#include <iostream>
#include <stack>
#include <string>
#include <fstream>
/*
Fazer um código em C++ capaz de lê um arquivo contendo apenas 0's e 1's. O programa deverá ler esse arquivo e a cada 8 bits deverá converter 
o código binário em decimal e de decimal para o código ASCII correspondente. Exemplo:
conteúdo do arquivo: 010000010110110001101111
separando de oito em oito bits teremos:
01000001 = A
01101100 = l
01101111 = o

formando então a palavra "Alo".

é obrigatório a utilização de pelo menos uma pilha no código.
*/
using namespace std;

string converter; // protótipo da classe
// joga os conjuntos de 8 numa pilha e depois lê a pilha de cima pra baixo, convertendo
int main()
{
    string nome;
    ifstream ler;
    stack <string> binario_invertido, binario_correto, copia;
    string numeros;
    
    cout << "Digite o nome do arquivo: ";
    getline(cin, nome);
    
    ler.open(nome); ;// abre arquivo para gravação
    if(ler.is_open()){
        while(ler >> numeros){  // lê os números até o final do arquivo
            binario_invertido.push(numeros); // adiciona os números a uma pilha
        }
        ler.close();
        while(!binario_invertido.empty()){
            binario_correto.push(binario_invertido.top());
            binario_invertido.pop();
        }
    }else {
        cerr << "Erro ao abrir o arquivo";
    }
    
    
    cout<<"Hello World";

    return 0;
}
