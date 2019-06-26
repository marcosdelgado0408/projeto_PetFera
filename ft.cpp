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


    for (int i = 1; i < argc; i++){ //loop nos args salvando-os em variaveis de apoio para compara-los dps
        ca = argv[i];
        n = argv[i];    
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


    while (dataBase.good()){ //loop dentro do arquivo base de dados
        string expo_classe;
        string expo_vet;    
        string expo_trat;
        string aux;

        getline(dataBase,aux,','); //iniciando a variavel auxiliar que servira que apoio para leitura e comparação do item da base de dados


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
                        ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n'; // inserindo no arquivo de exportação a nova linha, já que ela deu "match" com oq foi solicitado   
                    }
                }
                
            }
        }
        //fim do primeiro caso


        //segundo caso, somente os dois primeiros inseridos
        if(classe!= "" && vet != "" && trat = ""){
            if (aux == classe){ //comparando e copiando
                expo_classe = aux;
                getline(dataBase,aux,',');
                if (aux == vet){ //comparando e copiando
                    expo_vet = aux;
                    getline(dataBase,expo_trat,'\n');
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n'; //inserindo no arquivo de exportação 
                }
            }
        }
        //fim do segundo caso


        //terceiro caso, somento o primeiro atributo
        if(classe != "" && vet = "" && trat = ""){
            if (aux == classe){ //comparando e copiando
                expo_classe = aux;
                getline(dataBase,aux,','); //copiando direto pois n tem argumento para comparar
                expo_vet = aux;
                getline(dataBase,aux,'\n');//copiando direto pois n tem argumento para comparar
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat <<'\n'; //inserindo no arquivo de exportação 
            }
        }
        //fim do terceiro caso

        //comeco do quarto caso, somente o primeiro e o terceito
        if(classe != "" && vet = "" && trat != ""){
            if (aux == classe){//comparando e copiando
                expo_classe = aux;
                getline(dataBase,aux,',');
                expo_vet = aux;
                getline(dataBase,aux,'\n');
                if(aux == trat){//comparando e copiando
                    expo_trat = aux;
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat <<'\n';//inserindo no arquivo de exportação 
                }
            }
        }
        //fim do quarto caso

        //comeco do quinto caso, somente o segundo e o terceiro atributo
        if(classe = "" && vet != "" && trat != ""){
            expo_classe = aux;//copiando direto o primeiro pois n necessita comparação
            getline(dataBase,aux,',');
            if(aux == vet){ //comparando e copiando 
                expo_vet = aux;
                getline(dataBase,aux,'\n');
                if (aux == trat){ //comparando e copiando
                    expo_trat = aux;
                    ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n';//inserindo no arquivo de exportação 
                }
            }
        }
        //fim do quinto caso

        //comeco do sexto, somente o segundo atributo
        if(classe = "" && vet != "" && trat = ""){
            expo_classe = aux;//copiando direto o primeiro pois n necessita comparação
            getline(dataBase,aux,',');
            if(aux == vet){ //comparando e copiando
                expo_vet = aux;
                getline(dataBase,aux,'\n'); //copiando direto o primeiro pois n necessita comparação
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat<<'\n';//inserindo no arquivo de exportação    
            }
        }
        // fim do quinto caso

        //comeco do setimo caso, somente o terceiro atributo
        if(classe = "" && vet = "" && trat != ""){
            expo_classe = aux;//copiando direto o primeiro pois n necessita comparação
            getline(dataBase,aux,',');
            expo_vet = aux;//copiando direto o primeiro pois n necessita comparação
            getline(dataBase,aux,'\n');
            if(aux == trat){ //comparando e copiando
                expo_trat = aux;
                ArqExt << expo_classe << ',' << expo_vet << ',' << expo_trat << '\n';//inserindo no arquivo de exportação    
            }

        }
        // fim do setimo caso
    }
    
    return 0;

}