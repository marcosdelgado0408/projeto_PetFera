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
    
    
    

    dataBase.open ("database.csv");// Abertura dos arquivos de base
    ArqExt.open("teste.csv", ios::app); // Abertura do arquivo de exportação


    while (dataBase.good()){
        string expo_classe;
        string expo_vet;    
        string expo_trat;
        string aux;

        getline(dataBase,aux,',');


        //primeiro caso, todos os atributos inseridos
        if (aux == classe){ // Comparando e copiando, case true, o 1 elemento da linha         
            expo_classe = aux;
            getline(dataBase,aux,',');
            if (aux == vet){// Comparando e copiando, case true, o 2 elemento da linha
                expo_vet = aux;
                getline(dataBase,aux,'\n');
                if (aux == trat){// Comparando e copiando, case true, o 3 elemento da linha
                    expo_trat = aux;
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n'; 
                }
            }
               
        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        //fim do primeiro caso


        //segundo caso, somente os dois primeiros inseridos
        if (aux == classe){
            expo_classe = aux;
            getline(dataBase,aux,',');
            if (aux == vet){
                expo_vet = aux;
                getline(dataBase,expo_trat,'\n');
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n'; 
            }
            
        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        //fim do segundo caso


        //terceiro caso, somento o primeiro atributo
        if (aux == classe){
            expo_classe = aux;
            getline(dataBase,expo_vet,',');
            getline(dataBase,expo_trat,'\n');
            ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n'; 
        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        //fim do terceiro caso

        //comeco do quarto caso, somente o segundo e o terceiro atributo
        
        if (true){ // acrescentar que este caso so pode ocorrer quando escolhido 2 (usar contador?) por enquanto esta sendo reutilizado para o 5 caso
            expo_classe = aux;
            getline(dataBase,aux,',');
            if(aux == vet){
                expo_vet = aux;
                getline(dataBase,aux,'\n');
                if (aux == trat){
                    expo_trat = aux;
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n';
                }
                
            }
        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        //fim do quarto caso

        //comeco do quinto caso, somente o segundo atributo ((reutilizando o getline do 4 caso))
        if(aux == vet){
            expo_vet = aux;
            getline(dataBase,aux,'\n');
            expo_trat = aux;
            ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n';
        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        // fim do quinto caso

        //comeco do sexto caso, somente o terceiro atributo
        if(true){
            expo_vet = aux;
            getline(dataBase,aux,'\n');
            if(aux == trat){
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << ',' << '\n';
            }

        }else{
            cout << "Não foram encontrados dados no banco de dados com os registros inseridos" << endl;
        }
        // fim do sexto caso
        
        
    }
    
    return 0;

}