#include "administrador.h"

#include <string>
#include <iostream>

using namespace std;

void Administrador::cadastrar_animal(Animal *a){
    int id_atual = Animal::id_atual_animal;
    Animal::id_atual_animal++;

    cout << "Adicionando " << a->getNomebatismo() << " de classe " << a->getClasse() << endl;
    lista_animais.insert(pair<int, Animal>(id_atual, *a)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}

//TODO
void Administrador::cadastrar_funcionario(Veterinario *vet){ // tipo 1-> veteterinario, tipo 2-> tratador
    int id_atual = Funcionario::id_atual_funcionario;
    Funcionario::id_atual_funcionario++;

    cout << "Adicionando " << vet->getNome() << " de especialidade " << vet->getEspecialidade() << endl;
    this->lista_veterinarios.insert(pair<int, Veterinario>(id_atual, *vet)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}

void Administrador::cadastrar_funcionario(Tratador *trat){
    int id_atual = Funcionario::id_atual_funcionario;
    Funcionario::id_atual_funcionario++;

    cout << "Adicionando " << trat->getNome() << " de especialidade " << trat->getEspecialidade() << endl;
    this->lista_tratadores.insert(pair<int, Tratador>(id_atual, *trat)); /*O controle do id_atual atraves da variavel estatica permite que adicionar seja feito em apenas uma linha de comando*/
}


//alterei a funcao pra receber so o id de um animal ao inves de um objeto
void Administrador::remover_animal(int id){
    int tam = this->lista_animais.size();
    if(!this->lista_animais.empty()){
        map<int, Animal>::iterator it = this->lista_animais.find(id);
        this->lista_animais.erase(it);
    }
    if(tam > lista_animais.size()){
        cout << "Este animal foi apagado com sucesso!" << endl;
    }else{
        cout << "Nao foi possivel remover esse animal!" << endl;
    }
}

void Administrador::remover_funcionario(int tipo, int id){ /*Tipo 1 = veterinario; tipo 2 = tratador */
    if (tipo == 1){
        int tam = this->lista_veterinarios.size();
        if(!this->lista_veterinarios.empty()){
            map<int, Veterinario>::iterator it = this->lista_veterinarios.find(id);
            this->lista_veterinarios.erase(it);
        }
        if(tam > lista_veterinarios.size()){
            cout << "Este veterinario foi apagado com sucesso!" << endl;
        }else{
            cout << "Nao foi possivel remover esse veterinario!" << endl;
        }
    }else if (tipo == 2){
        int tam = this->lista_tratadores.size();
        if(!this->lista_tratadores.empty()){
            map<int, Tratador>::iterator it = this->lista_tratadores.find(id);
            this->lista_tratadores.erase(it);
        }
        if(tam > lista_tratadores.size()){
            cout << "Este tratador foi apagado com sucesso!" << endl;
        }else{
            cout << "Nao foi possivel remover esse tratador!" << endl;
        }
    }
}

void Administrador::listar_funcionarios(int param){
    if (param == 1){
        map<int, Veterinario>::iterator it;
        for(it = this->lista_veterinarios.begin(); it != this->lista_veterinarios.end(); it++){
            cout << it->first << " - " << it->second.getNome() << " - " << it->second.getEspecialidade() << endl;
        }
    }else if(param == 2){
        map<int, Tratador>::iterator it;
        for(it = this->lista_tratadores.begin(); it != this->lista_tratadores.end(); it++){
            cout << it->first << " - " << it->second.getNome() << " - " << it->second.getEspecialidade() << endl;
        }
    }
}


void Administrador::jogar_conteudo_arquivo_animais(Animal *a,Veterinario *v, Tratador *t){ // vai ter um funcionario atrelado ao animal
    ofstream jogar_no_arquivo;

    jogar_no_arquivo.open("animais.csv",ios::app); // modo de adicionar no arquivo

    jogar_no_arquivo << Animal::id_atual_animal << ";" << a->getClasse() << ";" << a->getNomecientifico() << ";" << a->getSexo() << ";" << a->getTamnho();

    jogar_no_arquivo << ";" << a->getDieta() << ";" << v->id_atual_funcionario << ";" << t->id_atual_funcionario << ";" << a->getNomebatismo() << endl;

    jogar_no_arquivo.close();    

}

void Administrador::jogar_conteudo_arquivo_funcionarios(Veterinario *v){ 
    ofstream jogar_no_arquivo;

    jogar_no_arquivo.open("funcionarios.csv",ios::app); // modo de adicionar no arquivo

    jogar_no_arquivo << v->id_atual_funcionario << ";" << "Veterinário" << ";" << v->getNome() << ";" << v->getCpf(); 
    jogar_no_arquivo << ";" << v->getIdade() << ";" << v->getTipoSanguineo() << ";" << v->getFatorRh() << ";" << v->getEspecialidade();
    jogar_no_arquivo << ";" << v->getCrm() << endl;

    jogar_no_arquivo.close();


}

void Administrador::jogar_conteudo_arquivo_funcionarios(Tratador *t){ 
    ofstream jogar_no_arquivo;

    jogar_no_arquivo.open("funcionarios.csv",ios::app); // modo de adicionar no arquivo

    jogar_no_arquivo << t->id_atual_funcionario << ";" << "Tratador" << ";" << t->getNome() << ";" << t->getCpf(); 
    jogar_no_arquivo << ";" << t->getIdade() << ";" << t->getTipoSanguineo() << ";" << t->getFatorRh() << ";" << t->getEspecialidade();
    jogar_no_arquivo << ";" << t->getNivelSeguranca() << endl;

    jogar_no_arquivo.close();

}



void Administrador::carregar_animais_memoria(){
    ifstream ler_arquivo;

    string id;
    string classe;
    string nome_cientifico;
    string sexo;
    string altura;
    string dieta;
    string veterinario;
    string tratador;
    string nome_batismo;

    ler_arquivo.open("animais.csv");
    

    while(ler_arquivo.good()){
       
        getline(ler_arquivo,id,';');
        getline(ler_arquivo,classe,';');
        getline(ler_arquivo,nome_cientifico,';');
        getline(ler_arquivo,sexo,';');
        getline(ler_arquivo,altura,';');
        getline(ler_arquivo,dieta,';');
        getline(ler_arquivo,veterinario,';');
        getline(ler_arquivo,tratador,';');
        getline(ler_arquivo,nome_batismo,'\n');

        
        int int_id = stoi(id);
        char char_sexo = sexo[0];
        double double_altura = stod(altura);
        int int_vet = stoi(veterinario);
        int int_trat = stoi(tratador);

        //------------------------------------
        Veterinario *v = new Veterinario();
        map<int, Veterinario>::iterator it; 

        if(!this->lista_veterinarios.empty() || int_vet != 0){
            it =  this->lista_veterinarios.find(int_vet);
            if(it!=this->lista_veterinarios.end()){
                *v = it->second;
            }
        }
        //-------------------------------------

        Tratador *t = new Tratador();
        map<int, Tratador>::iterator it2 ;

        if(!this->lista_tratadores.empty() || int_trat != 0){
            it2 =  this->lista_tratadores.find(int_trat);
            if(it2 != this->lista_tratadores.end()){
                *t = it2->second;
            }
        }

        //-------------------------------------


        Animal *a = new Animal(classe,nome_cientifico,char_sexo,double_altura, dieta, *v, *t,nome_batismo);
        
        this->cadastrar_animal(a);


    }

    




    ler_arquivo.close();

}


void carregar_veterinarios_memoria(){

}

void carregar_tratadores_memoria(){

}











void Administrador::listar_animais(){
    map<int, Animal>::iterator it;
        for(it = this->lista_animais.begin(); it != this->lista_animais.end(); it++){
            cout << it->first << " - " << it->second.getNomebatismo() << " - " << it->second.getClasse() << endl;
        }
}

void Administrador::mostrar_menu(){
    int choice = 4545;

    this->carregar_animais_memoria();
   
    while (choice != 0){
        cout << "*** Bem-vindo a administracao do PetFera... O que deseja fazer?" << endl;
        cout << "1 - Cadastrar um animal" << endl;
        cout << "2 - Remover um animal" << endl;
        cout << "3 - Consultar um animal" << endl;
        cout << "4 - Alterar um animal" << endl;
        cout << "5 - Cadastrar um funcionario" << endl;
        cout << "6 - Remover um funcionario" << endl;
        cout << "7 - Consultar um funcionario" << endl;
        cout << "8 - Alterar um funcionario" << endl;
        cout << "0 - Sair" << endl;
        cin >> choice;

        int escolha_vet, escolha_trat;
        if (choice == 1){ /*CADASTRAR ANIMAIS */
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

            //ajeitei a sequencia de exibicao aqui
            cout << "Veterinario responsavel (selecione um ID da lista): ";
            this->listar_funcionarios(1);
            cout << "0 - sem veterinario atrelado" << endl << endl;
            cin >> escolha_vet;
            
            Veterinario *v = new Veterinario();
            map<int, Veterinario>::iterator it; 
            
            if(!this->lista_veterinarios.empty() || escolha_vet != 0){
                it = this->lista_veterinarios.find(escolha_vet);
                *v = it->second;
            }
            
            //----------------------------------------------------------

            cout << "Tratador responsavel (selecione um ID da lista): " << endl;
            this->listar_funcionarios(2);
            cout << "0 - sem tratador atrelado" << endl << endl;
            cin >> escolha_trat;

            Tratador *t = new Tratador();
            map<int, Tratador>::iterator it2 ;

            if(!this->lista_tratadores.empty() || escolha_vet != 0){
               it2 =  this->lista_tratadores.find(escolha_trat);
                *t = it2->second;
            }

            cout << "Nome de batismo: ";
            cin >> m_nome_batismo;

            /* colocar os dados aqui dentro*/
            Animal *a = new Animal(m_classe, m_nome_cientifico, m_sexo, m_tamanho, m_dieta, *v, *t, m_nome_batismo);
            this->cadastrar_animal(a);
            this->jogar_conteudo_arquivo_animais(a,v,t);
            
            free(a);
            free(v);
            free(t);

            cout << "ANIMAL CADASTRADO COM SUCESSO" << endl << endl;

        }else if(choice == 2){ /*REMOVER ANIMAIS */
            int escolha;
            cout << "Selecione o ID do animal que deseja remover" << endl;
            this->listar_animais();
            cin >> escolha;

            if (!this->lista_animais.empty()){
                map<int, Animal>::iterator it = this->lista_animais.find(escolha);
                if(it != lista_animais.end()){
                    remover_animal(escolha);
                }
            }
            
        }else if(choice == 3){ /*CONSULTAR ANIMAIS */
            int escolha;
            cout << "Animais cadastrados ate o momento: " << endl;
            this->listar_animais();
            cout << "Para consultar todos os dados de um animal especifico, digite o ID desse animal: " << endl;
            cin >> escolha;

            if (!this->lista_animais.empty()){
                map<int, Animal>::iterator it = this->lista_animais.find(escolha);
                if(it != lista_animais.end()){
                    cout << it->first << " - ";
                    cout << it->second.getClasse() << " - ";
                    cout << it->second.getNomebatismo() << " - ";
                    cout << it->second.getNomecientifico() << " - ";
                    cout << it->second.getSexo() << " - ";
                    cout << it->second.getTamnho() << " - ";
                    cout << it->second.getTratador().getNome() << " (Tratador) - ";
                    cout << it->second.getVeterinario().getNome() << " (Veterinario) " << endl << endl;
                }
            }
        }else if(choice == 4){
            string m_classe;
            string m_nome_cientifico;
            char m_sexo;
            double m_tamanho;
            string m_dieta;
            Veterinario m_veterinario; 
            Tratador m_tratador;       
            string m_nome_batismo;



            int escolha, escolha_loop, escolha_vet, escolha_trat;
            cout << "Animais cadastrados ate o momento: " << endl;
            this->listar_animais();
            cout << "Para alterar todos os dados de um animal especifico, digite o ID desse animal: " << endl;
            cin >> escolha;
            cout << endl;

            if (!this->lista_animais.empty()){
                map<int, Animal>::iterator it = this->lista_animais.find(escolha);
                if(it != lista_animais.end()){
                    do{
                        cout << "1 "<< it->second.getClasse() << endl;
                        cout << "2 "<< it->second.getDieta() << endl;
                        cout << "3 "<< it->second.getNomebatismo() << endl;
                        cout << "4 "<< it->second.getNomecientifico() << endl;
                        cout << "5 "<< it->second.getSexo() << endl;
                        cout << "6 "<< it->second.getTamnho() << endl;
                        cout << "7 "<< it->second.getTratador().getNome() << " (Tratador) " << endl;
                        cout << "8 "<< it->second.getVeterinario().getNome() << " (Veterinario) " << endl << endl;

                        cout << "Digite o numero do dado que deseja alterar ou 0 para sair: ";
                        cin >> escolha_loop;

                        if(escolha_loop == 1){
                            cout << "Digite a nova classe:" << endl;
                            cin >> m_classe;
                            it->second.setClasses(m_classe);
                        }
                        if(escolha_loop == 2){
                            cout << "Digite a nova Dieta:" << endl;
                            cin >> m_dieta;
                            it->second.setDieta(m_dieta);
                        }
                        if(escolha_loop == 3){
                            cout << "Digite o novo nome de batismo:" << endl;
                            cin >> m_nome_batismo;
                            it->second.setNomebatismo(m_nome_batismo);
                        }
                        if(escolha_loop == 4){
                            cout << "Digite o novo nome cientifico:" << endl;
                            cin >> m_nome_cientifico;
                            it->second.setNomecientifico(m_nome_cientifico);
                        }
                        if(escolha_loop == 5){
                            cout << "Digite o novo sexo:" << endl;
                            cin >> m_sexo;
                            it->second.setSexo(m_sexo);
                        }
                        if(escolha_loop == 6){
                            cout << "Digite o novo tamanho:" << endl;
                            cin >> m_tamanho;
                            it->second.setTamnho(m_tamanho);
                        }
                        if(escolha_loop == 7){
                            cout << "Selecione o novo tratador da lista abaixo: " << endl;
                            this->listar_funcionarios(2);
                            cin >> escolha_trat;
                            if(!this->lista_tratadores.empty()){
                                map<int, Tratador>::iterator it2 = this->lista_tratadores.find(escolha_trat);
                                if(it2 != this->lista_tratadores.end()){
                                    it->second.setTratador(it2->second);
                                }
                            }
                        }
                        if(escolha_loop == 8){
                            cout << "Selecione o novo veterinario da lista abaixo: " << endl;
                            this->listar_funcionarios(1);
                            cin >> escolha_vet;
                            if(!this->lista_veterinarios.empty()){
                                map<int, Veterinario>::iterator it2 = this->lista_veterinarios.find(escolha_vet);
                                if(it2 != this->lista_veterinarios.end()){
                                    it->second.setVeterinario(it2->second);
                                }
                            }
                        }
                    }while(escolha_loop != 0);
                }
            }
        }else if(choice == 5){ /*ADICIONAR UM FUNCIONARIO */
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
                this->cadastrar_funcionario(vet);
                this->jogar_conteudo_arquivo_funcionarios(vet);
                free(vet);
            }
            else if(type == 2){
                cout << "Nível de segurança: " << endl;
                cin >> m_nivel_de_seguranca;

                Tratador *trat = new Tratador(m_nome, m_cpf, m_idade, m_tipo_sanguineo,m_fator_rh,m_especialidade, m_nivel_de_seguranca);
                this->cadastrar_funcionario(trat);
                this->jogar_conteudo_arquivo_funcionarios(trat);

                free(trat);
            }
        }else if(choice == 6){ /*REMOVER FUNCIONARIOS */
            int escolha, escolha2;
            cout << "Digite 1 para remover um Veterinario ou 2 para remover um tratador" << endl;
            cin >> escolha2;
            
            if (escolha2 == 1){
                cout << "Selecione o ID de um Veterinario para remove-lo" << endl;
                this->listar_funcionarios(1);
                cin >> escolha;
                if (!this->lista_veterinarios.empty()){
                    map<int, Veterinario>::iterator it = this->lista_veterinarios.find(escolha);
                    if(it != lista_veterinarios.end()){
                        remover_funcionario(1, escolha);
                    }
                }
            }else if(escolha2 == 2){
                cout << "Selecione o ID de um Tratador para remove-lo" << endl;
                this->listar_funcionarios(2);
                cin >> escolha;
                if (!this->lista_tratadores.empty()){
                    map<int, Tratador>::iterator it = this->lista_tratadores.find(escolha);
                    if(it != lista_tratadores.end()){
                        remover_funcionario(2, escolha);
                    }
                }
            }
        }else if(choice == 7){  /*CONSULTAR FUNCIONARIOS */
            int escolha, escolha2;
            cout << "Digite 1 para consultar um Veterinario ou 2 para consultar um tratador" << endl;
            cin >> escolha2;
            
            if (escolha2 == 1){
                cout << "Selecione o ID de um Veterinario para saber informacoes detalhadas sobre ele" << endl;
                this->listar_funcionarios(1);
                cin >> escolha;
                if (!this->lista_veterinarios.empty()){
                    map<int, Veterinario>::iterator it = this->lista_veterinarios.find(escolha);
                    if(it != lista_veterinarios.end()){
                        cout << it->first << " - ";
                        cout << it->second.getNome() << " - ";
                        cout << it->second.getIdade() << " - ";
                        cout << it->second.getTipoSanguineo() << " - ";
                        cout << it->second.getEspecialidade() << " - ";
                        cout << it->second.getFatorRh() << " - ";
                        cout << it->second.getCpf() << " - ";
                        cout << it->second.getCrm() << endl << endl;
                    }
                }
            }else if(escolha2 == 2){
                cout << "Selecione o ID de um Tratador para saber informacoes detalhadas sobre ele" <<endl;
                this->listar_funcionarios(2);
                cin >> escolha;
                if (!this->lista_tratadores.empty()){
                    map<int, Tratador>::iterator it = this->lista_tratadores.find(escolha);
                    if(it != lista_tratadores.end()){
                        cout << it->first << " - ";
                        cout << it->second.getNome() << " - ";
                        cout << it->second.getIdade() << " - ";
                        cout << it->second.getTipoSanguineo() << " - ";
                        cout << it->second.getEspecialidade() << " - ";
                        cout << it->second.getFatorRh() << " - ";
                        cout << it->second.getCpf() << " - ";
                        cout << it->second.getNivelSeguranca() << endl << endl;
                    }
                }
            }
        }else if(choice == 8){
            int type;

            string m_nome;  
            string m_cpf;
            short m_idade;
            string m_tipo_sanguineo;
            char m_fator_rh;
            string m_especialidade;

            int m_nivel_de_seguranca;/* Nivel de seguranca do tratador */

            string m_crm; /*crm do veterinario*/

            int escolha, escolha_loop;
            cout << "Digite 1 para alterar um Veterinario ou 2 para alterar um Tratador: ";
            cin >> type;

            if(type == 1){
                cout << "Veterinarios cadastrados ate o momento: " << endl;
                this->listar_funcionarios(1);
                cout << "Para alterar todos os dados de um veterinario especifico, digite o ID desse funcionario: " << endl;
                cin >> escolha;
                cout << endl;

                if (!this->lista_veterinarios.empty()){
                    map<int, Veterinario>::iterator it = this->lista_veterinarios.find(escolha);
                    if(it != lista_veterinarios.end()){
                        do{
                            cout << "1 "<< it->second.getNome() << endl;
                            cout << "2 "<< it->second.getCpf() << endl;
                            cout << "3 "<< it->second.getEspecialidade() << endl;
                            cout << "4 "<< it->second.getTipoSanguineo() << endl;
                            cout << "5 "<< it->second.getFatorRh() << endl;
                            cout << "6 "<< it->second.getIdade() << endl;
                            cout << "7 "<< it->second.getCrm() << endl;

                            cout << "Digite o numero do dado que deseja alterar ou 0 para sair: ";
                            cin >> escolha_loop;

                            if(escolha_loop == 1){
                                cout << "Digite a nova classe:" << endl;
                                cin >> m_nome;
                                it->second.setNome(m_nome);
                            }
                            if(escolha_loop == 2){
                                cout << "Digite o novo cpf:" << endl;
                                cin >> m_cpf;
                                it->second.setCpf(m_cpf);
                            }
                            if(escolha_loop == 3){
                                cout << "Digite a nova especialidade:" << endl;
                                cin >> m_especialidade;
                                it->second.setEspecialidade(m_especialidade);
                            }
                            if(escolha_loop == 4){
                                cout << "Digite o novo tipo sanguineo:" << endl;
                                cin >> m_tipo_sanguineo;
                                it->second.setTipoSanguineo(m_tipo_sanguineo);
                            }
                            if(escolha_loop == 5){
                                cout << "Digite o novo fator RH:" << endl;
                                cin >> m_fator_rh;
                                it->second.setFatorRh(m_fator_rh);
                            }
                            if(escolha_loop == 6){
                                cout << "Digite a nova idade:" << endl;
                                cin >> m_idade;
                                it->second.setIdade(m_idade);
                            }
                            if(escolha_loop == 7){
                                cout << "Digite o novo crm:" << endl;
                                cin >> m_crm;
                                it->second.setCrm(m_crm);
                            }
                        }while(escolha_loop != 0);
                    }
                }
            }else if(type == 2){
                cout << "Tratadores cadastrados ate o momento: " << endl;
                this->listar_funcionarios(2);
                cout << "Para alterar todos os dados de um tratador especifico, digite o ID desse funcionario: " << endl;
                cin >> escolha;
                cout << endl;

                if (!this->lista_tratadores.empty()){
                map<int, Tratador>::iterator it = this->lista_tratadores.find(escolha);
                if(it != lista_tratadores.end()){
                    do{
                        cout << "1 "<< it->second.getNome() << endl;
                        cout << "2 "<< it->second.getCpf() << endl;
                        cout << "3 "<< it->second.getEspecialidade() << endl;
                        cout << "4 "<< it->second.getTipoSanguineo() << endl;
                        cout << "5 "<< it->second.getFatorRh() << endl;
                        cout << "6 "<< it->second.getIdade() << endl;
                        cout << "7 "<< it->second.getNivelSeguranca() << endl;

                        cout << "Digite o numero do dado que deseja alterar ou 0 para sair: ";
                        cin >> escolha_loop;

                        if(escolha_loop == 1){
                            cout << "Digite a nova classe:" << endl;
                            cin >> m_nome;
                            it->second.setNome(m_nome);
                        }
                        if(escolha_loop == 2){
                            cout << "Digite o novo cpf:" << endl;
                            cin >> m_cpf;
                            it->second.setCpf(m_cpf);
                        }
                        if(escolha_loop == 3){
                            cout << "Digite a nova especialidade:" << endl;
                            cin >> m_especialidade;
                            it->second.setEspecialidade(m_especialidade);
                        }
                        if(escolha_loop == 4){
                            cout << "Digite o novo tipo sanguineo:" << endl;
                            cin >> m_tipo_sanguineo;
                            it->second.setTipoSanguineo(m_tipo_sanguineo);
                        }
                        if(escolha_loop == 5){
                            cout << "Digite o novo fator RH:" << endl;
                            cin >> m_fator_rh;
                            it->second.setFatorRh(m_fator_rh);
                        }
                        if(escolha_loop == 6){
                            cout << "Digite a nova idade:" << endl;
                            cin >> m_idade;
                            it->second.setIdade(m_idade);
                        }
                        if(escolha_loop == 7){
                            cout << "Digite o novo nivel de seguranca:" << endl;
                            cin >> m_nivel_de_seguranca;
                            it->second.setNivelSeguranca(m_nivel_de_seguranca);
                        }
                    }while(escolha_loop != 0);
                }
            }
        }else if(choice == 0){
            exit(1);
        }
   }
   
}
