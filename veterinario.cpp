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

<<<<<<< HEAD

string Veterinario::get_m_crm(){
    return this->m_crm;
}
=======
string Veterinario::getCrm(){
    return this->m_crm;
}

void Veterinario::setCrm(string crm){
    this->m_crm = crm;
}
>>>>>>> 86a2f884261b153ac0907e27fd37997caa9b6379
