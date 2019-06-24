#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    ofstream ArqExt; //usuario escolhe o nome do arquivo
    ifstream dataBase;
    string classe, vet, trat;
    cin >> classe;
    cin >> vet;
    cin >> trat;
    
    
    

    dataBase.open ("database.csv", ios::in);// Abertura dos arquivos de base
    ArqExt.open("teste.csv", ios::app); // Abertura do arquivo de exportação


    while (dataBase.good()){
        string expo_classe;
        string expo_vet;    
        string expo_trat;

        if (getline(dataBase,",") == classe){ // Comparando e copiando, case true, o 1 elemento da linha         
            getline(dataBase,expo_classe,",");
        }
        else if (getline(dataBase,",") == vet){// Comparando e copiando, case true, o 2 elemento da linha
            getline(dataBase,expo_vet,",");
        }
        else if (getline(dataBase,"\n") == trat){// Comparando e copiando, case true, o 3 elemento da linha
            getline(dataBase,expo_trat,"\n");
        }
        ArqExt << expo_classe << "," << expo_vet << "," << expo_trat << "," << "\n";
    }
    
    return 0;

}