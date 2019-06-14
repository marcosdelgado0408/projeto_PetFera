#include <iostream>
#include <string>

#ifndef _include_
#define _include_


using namespace std;

class Funcionario{

    protected:
        int m_id;
        string m_nome;  
        string m_cpf;
        short m_idade;
        short m_tipo_sanguineo;
        char m_fator_rh;
        string m_especialidade;

    public:
        //method(type):type ??

};





class Veterinario: public Funcionario{

    private:
        string m_crm;
    public:
        Veterinario();
        ~Veterinario();

};

class Tratador: public Funcionario{
    private:
        int m_nivel_de_seguranca;
    public:
        Tratador();
        ~Tratador();
};





// associatividade das classes Tratador e Vetrinario com a classe Animal
class Animal{
    protected:
        int m_id;
        string m_classe;
        string m_nome_cientifico;
        char m_sexo;
        double m_tamanho;
        string m_dieta;
        Veterinario m_veterinario; // associatividade da classe Vetrinario com a classe Animal
        Tratador m_tratador;       // associatividade da classe Tratador com a classe Animal
        string m_nome_batismo;
        

    public:
        Animal();
        ~Animal();
        // Animal(...) ???
};





class Anfibio: public Animal{
    protected:
        int m_total_de_mudas;
        //m_ultima_muda:date ??
    public:
        Anfibio();
        ~Anfibio();
};

class Mamifero: public Animal{
        protected:
            string m_cor_pelo;
        public:
            Mamifero();
            ~Mamifero();
};

class Reptil: public Animal{
    protected:
        bool m_venenoso;
        string m_tipo_veneno;
    
    public:
        Reptil();
        ~Reptil();
};

class Ave: public Animal{
    protected:
        double m_tamanho_do_bico_cm;
        double m_envergadura_das_asas;

    public:
        Ave();
        ~Ave();
};





class AnfibioNativo: public Anfibio{
    public:
        AnfibioNativo();
        ~AnfibioNativo();
};

class AnfibioExotico: public Anfibio{
    public:
        AnfibioExotico(); // no diagrama está assim mas n sei se está certo
        ~AnfibioExotico();
};

class MamiferoNativo: public Mamifero{
    public:
        MamiferoNativo();
        ~MamiferoNativo(); // no diagrama ta bugado assim
};

class MamiferoExotico: public Mamifero{
    public:
        MamiferoExotico();
        ~MamiferoExotico();
};

class ReptilNativo: public Reptil{
    public:
        ReptilNativo();
        ~ReptilNativo();
};

class ReptilExotico: public Reptil{
    public:
        ReptilExotico();
        ~ReptilExotico();
};

class AveNativo: public Ave{
    public:
        AveNativo();
        ~AveNativo();
};

class AveExotico: public Ave{
    public:
        AveExotico();
        ~AveExotico();
};






class AnimalNativo: public AnfibioNativo, MamiferoNativo, ReptilNativo, AveNativo{
    protected:
        string m_uf_origem;
        string m_autorizacao;
    public:
        AnimalNativo();
        ~AnimalNativo();
};

class AnimalExotico: public AnfibioExotico, MamiferoExotico, ReptilExotico, AveExotico{
    protected:
        string m_pais_origem;
        //string m_pais_origem;
    public:
        AnimalExotico();
        ~AnimalExotico();
};





class AnimalSilvestre: public AnimalNativo, AnimalExotico{
    protected:
        string  m_autorizacao_ibama;
    public:
        AnimalSilvestre();
        ~AnimalSilvestre();
};  



class Adimistracao{
    public:
        
    private:


};


#endif