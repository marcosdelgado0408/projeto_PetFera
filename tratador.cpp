#include "tratador.h"

Tratador::Tratador(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade, int nivel_de_seguranca){
    Funcionario(m_nome, m_cpf, m_idade, m_tipo_sanguineo, m_fator_rh, m_especialidade);
    this->m_nivel_de_seguranca = nivel_de_seguranca;
}