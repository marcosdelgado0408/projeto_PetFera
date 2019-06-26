#include "veterinario.h"

Veterinario::Veterinario(){
    this->m_crm = "";
}


Veterinario::Veterinario(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade, string m_crm){
    this->m_nome = m_nome; 
    this->m_cpf = m_cpf;
    this->m_idade = m_idade;
    this->m_tipo_sanguineo = m_tipo_sanguineo;
    this->m_fator_rh = m_fator_rh;
    this->m_especialidade = m_especialidade;

    this->m_crm = m_crm;
}

Veterinario::~Veterinario(){
    this->m_crm = "";
}


string Veterinario::get_m_crm(){
    return this->m_crm;
}