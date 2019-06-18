#include "funcionario.h"

static int id = 0; /* variável que vai armazenar incrementalmente o id de um funcionário, fazendo com que seja automatizado */

Funcionario::Funcionario(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade){
	this->m_nome = m_nome;
	this->m_cpf = m_cpf;
	this->m_idade = m_idade;
	this->m_tipo_sanguineo = m_tipo_sanguineo;
	this->m_fator_rh = m_fator_rh);
	this->m_especialidade = m_especialidade;
}

Funcionario::getNome(){
	return this->m_nome;
}

Funcionario::setNome(string nome){
	this->m_nome = nome;
}

Funcionario::getCpf(){
	return this-m_cpf;
}

Funcionario::setCpf(string cpf){
	this->m_cpf = cpf
}

Funcionario::getIdade(){
	return this->m_idade;
}

Funcionario::setIdade(short idade){
	this->m_idade = idade;
}

Funcionario::getTipoSanguineo(){
	return this->m_tipo_sanguineo;
}

Funcionario::setTipoSanguineo(string tipo_sanguineo){
	this->m_tipo_sanguineo = tipo_sanguineo;
}

Funcionario::getFatorRh(){
	return this->m_fator_rh;
}

Funcionario::setFatorRh(char fator_rh){
	this->m_fator_rh = fator_rh;
}

Funcionario::getEspecialidade(){
	return this->m_especialidade;
}

Funcionario::setEspecialidade(string especialidade){
	this->m_especial
idade = especialidade;
}		


















	
