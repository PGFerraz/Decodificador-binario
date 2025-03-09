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

void converter_para_decimal(stack <string>& a){
    int decimal = 0;
    int potencia = 1;
    while(!a.empty()){  // Enquanto a pilha não estiver vazia
        for(int i=0;i<7;i++){
            decimal += a.top() * potencia;// Pega o topo da pilha (um número inteiro)
            potencia *= 2; // multiplica por 2^0, 2^1,...
            a.pop();
        }
        cout << "\nValor decimal: " << decimal;
    }
}

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
        converter_para_decimal(binario_correto);
    }else {
        cerr << "Erro ao abrir o arquivo";
    }
    
    
    cout<<"Hello World";

    return 0;
}
