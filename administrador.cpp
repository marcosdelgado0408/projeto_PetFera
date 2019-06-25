#include "administrador.h"

#include <string>
#include <iostream>

using namespace std;

int Administrador::cadastrar_animal(Animal *a){
    int id_atual = Animal::id_atual_animal;
    Animal::id_atual_animal++;

    cout << "Adicionando " << a->getNomebatismo() << " de classe " << a->getClasse() << endl;
    lista_animais.insert(pair<int, Animal>(id_atual, *a)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}

//TODO
int Administrador::cadastrar_funcionario(Veterinario *vet){ // tipo 1-> veteterinario, tipo 2-> tratador
    int id_atual = Funcionario::id_atual_funcionario;
    Funcionario::id_atual_funcionario++;

    cout << "Adicionando " << vet->getNome() << " de especialidade " << vet->getEspecialidade() << endl;
    this->lista_veterinarios.insert(pair<int, Veterinario>(id_atual, *vet)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}

int Administrador::cadastrar_funcionario(Tratador *trat){
    int id_atual = Funcionario::id_atual_funcionario;
    Funcionario::id_atual_funcionario++;

    cout << "Adicionando " << trat->getNome() << " de especialidade " << trat->getEspecialidade() << endl;
    this->lista_tratadores.insert(pair<int, Tratador>(id_atual, *trat)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}

int Administrador::remover_animal(Animal *a){

}

void Administrador::listar_funcionarios(int param){
    if (param == 1){
        map<int, Veterinario>::iterator it;
        for(it = this->lista_veterinarios.begin(); it != this->lista_veterinarios.end(); it++){
            cout << it->first << " - " << it->second.getNome() << " - " << it->second.getEspecialidade();
        }
    }else if(param == 2){
        map<int, Tratador>::iterator it;
        for(it = this->lista_tratadores.begin(); it != this->lista_tratadores.end(); it++){
            cout << it->first << " - " << it->second.getNome() << " - " << it->second.getEspecialidade();
        }
    }
}

void Administrador::mostrar_menu(){
    cout << "*** Bem-vindo a administracao do PetFera... O que deseja fazer?" << endl;
    cout << "1 - Cadastrar um animal" << endl;
    cout << "2 - Remover um animal" << endl;
    cout << "3 - Consultar um animal" << endl;
    cout << "4 - Alterar um animal" << endl;
    cout << "5 - Cadastrar um funcionario" << endl;
    cout << "6 - Remover um funcionario" << endl;
    cout << "7 - Consultar um funcionario" << endl;
    cout << "8 - Alterar um funcionario" << endl;
    int choice;
    cin >> choice;

    int escolha_vet, escolha_trat;
    if (choice == 1){
        string m_classe;
        string m_nome_cientifico;
        char m_sexo;
        double m_tamanho;
        string m_dieta;
        Veterinario m_veterinario; 
        Tratador m_tratador;       
        string m_nome_batismo;

        cout << "*** Digite os dados abaixo para cadastrar um animal ***" << endl;
        cout << "Classe: ";
        cin >> m_classe;

        cout << "Nome cientifico: ";
        cin >> m_nome_cientifico;

        cout << "Sexo: ";
        cin >> m_sexo;

        cout << "Tamanho: ";
        cin >> m_tamanho;

        cout << "Dieta: ";
        cin >> m_dieta;

        
        listar_funcionarios(1);
        cout << "0 - sem veterinario atrelado";
        

        cout << "Veterinario responsavel (selecione um ID da lista): ";
        cin >> escolha_vet;
        
        Veterinario *v = new Veterinario();
        map<int, Veterinario>::iterator it; 
        
        if(!this->lista_veterinarios.empty()){
            this->lista_veterinarios.find(escolha_vet);
            *v = it->second;
        }
        
        //----------------------------------------------------------
      
        listar_funcionarios(2); 
        cout << "0 - sem tratador atrelado";

        cout << "Tratador responsavel (selecione um ID da lista): ";
        cin >> escolha_trat;

            
        Tratador *t = new Tratador();
        map<int, Tratador>::iterator it2 ;

        if(!this->lista_tratadores.empty()){
            this->lista_tratadores.find(escolha_trat);
            *t = it2->second;
        }

        cout << "Nome de batismo: ";
        cin >> m_nome_batismo;

        //colocar os dados aqui dentro
        Animal *a = new Animal(m_classe, m_nome_cientifico, m_sexo, m_tamanho, m_dieta, *v, *t, m_nome_batismo);
        this->cadastrar_animal(a);
        free(a);
        free(v);
        free(t);

        cout << "ANIMAL CADASTRADO COM SUCESSO" << endl << endl;

    }else if(choice == 2){
        //remover_animal();
    }else if(choice == 5){
        int type;

        string m_nome;  
		string m_cpf;
		short m_idade;
		string m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;

        int m_nivel_de_seguranca;/* Nivel de seguranca do tratador */

        string m_crm; /*crm do veterinario*/
        cout << "*** Digite os dados abaixo para cadastrar um funcionario ***" << endl;
        cout << "Tipo do funcionario (1 - veterinario, 2 - tratador)"<< endl;
        cin >> type;

        cout << "Nome:" << endl;
        cin >> m_nome;

        cout << "CPF:" << endl;
        cin >> m_cpf;

        cout << "Idade:" << endl;
        cin >> m_idade;
        
        cout << "Tipo sanguineo:" << endl;
        cin >> m_tipo_sanguineo;
        
        cout << "Fator RH:" << endl;
        cin >> m_fator_rh;
        
        cout << "Especialidade:" << endl;
        cin >> m_especialidade;

        if(type == 1){
            cout << "CRM: " << endl;
            cin >> m_crm;
            Veterinario *vet = new Veterinario(m_nome, m_cpf, m_idade, m_tipo_sanguineo,m_fator_rh,m_especialidade,m_crm);
            cadastrar_funcionario(vet);
            free(vet);
        }
        else if(type == 2){
            cout << "Nível de segurança: " << endl;
            cin >> m_nivel_de_seguranca;
            cout << endl << endl;
            Tratador *trat = new Tratador(m_nome, m_cpf, m_idade, m_tipo_sanguineo,m_fator_rh,m_especialidade, m_nivel_de_seguranca);
            cadastrar_funcionario(trat);
            free(trat);
        }
    }
}
