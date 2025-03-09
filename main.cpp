#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

void converter_para_decimal(stack<int>& a) 
{
    int potencia = 1;
    int n = 0;
    int matriz_dec[100];

    while (!a.empty()) {
        int decimal = 0;
        for (int i = 0; i < 8; i++) {
            decimal += a.top() * potencia;
            potencia *= 2;
            a.pop();
        }

        matriz_dec[n] = decimal;
        cout << "Decimal: " << matriz_dec[n] << " | Caracter ASCII: " << char(matriz_dec[n]) << "\n";
        n++;
        potencia = 1;
    }
}

int main() {
    string nome;
    ifstream ler;
    stack<int> binario_invertido, binario_correto;
    char numeros;

    cout << "Digite o nome do arquivo: ";
    getline(cin, nome);
    
    ler.open(nome);
    if (ler.is_open()) {

        while (ler >> numeros) {
            if(numeros == '0') {
                binario_invertido.push(0);
            } else if(numeros == '1') {
                binario_invertido.push(1);
            }
        }
        ler.close();

        if (binario_invertido.size() % 8 != 0) {
            cerr << "Erro: o número de bits no arquivo não é um múltiplo de 8!" << endl;
            return 1;
        }

        converter_para_decimal(binario_invertido);
    } else {
        cerr << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    return 0;
}
