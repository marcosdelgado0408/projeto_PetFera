#include "tratador.h"


Tratador::Tratador(){
    this->m_nivel_de_seguranca = 0;
}

Tratador::Tratador(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade, int nivel_de_seguranca){
    this->m_nome = m_nome;
    this->m_cpf = m_cpf;
    this->m_idade = m_idade;
    this->m_tipo_sanguineo = m_tipo_sanguineo;
    this->m_fator_rh = m_fator_rh;
    this->m_especialidade = m_especialidade;
    
    this->m_nivel_de_seguranca = nivel_de_seguranca;
}

Tratador::~Tratador(){
    this->m_nivel_de_seguranca = 0;
}

<<<<<<< HEAD
int Tratador::get_nivel_de_seguranca(){
    return this->m_nivel_de_seguranca;
=======
int Tratador::getNivelSeguranca(){
    return this->m_nivel_de_seguranca;
}

void Tratador::setNivelSeguranca(int nivel){
    this->m_nivel_de_seguranca = nivel;
>>>>>>> 86a2f884261b153ac0907e27fd37997caa9b6379
}