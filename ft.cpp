#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    ofstream ArqExt; 
    ifstream dataBase;
    string classe, vet, trat;
    string n;
    string ca;
    n = argv[argc];
    for (int i = 1; i < argc; i++){
        ca = argv[i];    
        if(ca == "-c"){
            classe = argv[i+1];
        }
        
        if (ca == "-v"){
            vet = argv[i+1];
        }
        if (ca == "-t"){
            trat = argv[i+1];
        }
    }

   

    dataBase.open ("database.csv");// Abertura dos arquivos de base
    ArqExt.open(n + ".csv", ios::app); // Abertura do arquivo de exportação


    while (dataBase.good()){
        string expo_classe;
        string expo_vet;    
        string expo_trat;
        string aux;

        getline(dataBase,aux,',');


        //primeiro caso, todos os atributos inseridos
        if (classe != "" && vet != "" && trat != ""){
            if (aux == classe){ // Comparando e copiando, case true, o 1 elemento da linha         
                expo_classe = aux;
                getline(dataBase,aux,',');
                if (aux == vet){// Comparando e copiando, case true, o 2 elemento da linha
                    expo_vet = aux;
                    getline(dataBase,aux,'\n');
                    if (aux == trat){// Comparando e copiando, case true, o 3 elemento da linha
                        expo_trat = aux;
                        ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n'; 
                        break;
                    }
                }
                
            }
        }
        //fim do primeiro caso


        //segundo caso, somente os dois primeiros inseridos
        else if (aux == classe){
            expo_classe = aux;
            getline(dataBase,aux,',');
            if (aux == vet){
                expo_vet = aux;
                getline(dataBase,expo_trat,'\n');
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n'; 
                break;
            }
            
        }
        //fim do segundo caso


        //terceiro caso, somento o primeiro atributo
        else if (aux == classe){
            expo_classe = aux;
            getline(dataBase,expo_vet,',');
            getline(dataBase,expo_trat,'\n');
            ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat <<'\n'; 
            break;
        }
        //fim do terceiro caso

        //comeco do quarto caso, somente o primeiro e o terceito
        else if (aux == classe){
            expo_classe = aux;
            getline(dataBase,aux,',');
            expo_vet = aux;
            getline(dataBase,aux,'\n');
            if(aux == trat){
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat <<'\n'; 
                break;
            }
        }
        
        //fim do quarto caso

        //comeco do quinto caso, somente o segundo e o terceiro atributo
        
        else if (true){ // acrescentar que este caso so pode ocorrer quando escolhido 2 (usar contador?) por enquanto esta sendo reutilizado para o 5 caso
            expo_classe = aux;
            getline(dataBase,aux,',');
            if(aux == vet){
                expo_vet = aux;
                getline(dataBase,aux,'\n');
                if (aux == trat){
                    expo_trat = aux;
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n';
                    break;
                }
                
            }
        }
        //fim do quinto caso

        //comeco do sexto, somente o segundo atributo ((reutilizando o getline do 4 caso))
        else if(aux == vet){
            expo_vet = aux;
            getline(dataBase,aux,'\n');
            expo_trat = aux;
            ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat<<'\n';
            break;
        }
        // fim do quinto caso

        //comeco do setimo caso, somente o terceiro atributo
        else if(true){
            expo_vet = aux;
            getline(dataBase,aux,'\n');
            if(aux == trat){
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n';
                break;
            }

        }
        // fim do sexto caso
        else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
            break;
        }
    }
    
    return 0;

}