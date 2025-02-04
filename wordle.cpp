#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string compareStr(string& str1, string& str2, string& usados) {
    string resultado;

   
    for (int i = 0; i < 5; ++i) {
        
        if (str1[i] == str2[i]){
            resultado += str1[i];
        }
        
        if (str1[i] != str2[i]) {
            bool encontrado = false;
            for (int j = 0; j < 5; ++j) {
                
                if (str1[i] == str2[j]) {
                   
                    resultado += tolower(str1[i]);
                    encontrado = true;
                    break;
                }
            }
          
            if (!encontrado) {
                usados += str1[i];
                resultado += '*';
            }
        }
    }
    return resultado;
}

int main(){
    string string01, string02, stringR, usados;
    
ifstream inputFile ("palavras.txt");
 if (!inputFile.is_open ()) {
 cerr << "Erro ao abrir o arquivo.!" << endl;
 return 1;
 }

int n;
cin >> n;
int i = 0;
string linhasArQ;
do{
    getline(inputFile, linhasArQ);
    i++;
} while(i <= n);

string02 = linhasArQ;

    
    int z = 0;
    
    while(z < 5){

    cin >> string01;
    
    if(string01 == string02){
        cout << string02 << " (" << usados << " )" << endl;
        cout << "GANHOU!" << endl;
        break;
    }

    stringR = compareStr(string01, string02, usados);

    cout << stringR << " (" << usados << ")" << endl;
    
    
    z++;
}
    if (z == 5){
    cout << "PERDEU! " << string02 << endl;
    };
    return 0;
}