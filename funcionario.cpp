#include "funcionario.h"

/*static*/ int Funcionario::id_atual_funcionario = 1; /* variável que vai armazenar incrementalmente o id de um funcionário, fazendo com que seja automatizado */

Funcionario::Funcionario(){
	this->m_nome = "";
	this->m_cpf = "";
	this->m_idade = 0;
	this->m_tipo_sanguineo = "";
	this->m_fator_rh = 'x';
	this->m_especialidade = "";
}

Funcionario::Funcionario(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade){
	this->m_nome = m_nome;
	this->m_cpf = m_cpf;
	this->m_idade = m_idade;
	this->m_tipo_sanguineo = m_tipo_sanguineo;
	this->m_fator_rh = m_fator_rh;
	this->m_especialidade = m_especialidade;
}

Funcionario::~Funcionario(){
	this->m_nome = "";
	this->m_cpf = "";
	this->m_idade = 0;
	this->m_tipo_sanguineo = "";
	this->m_fator_rh = 'x';
	this->m_especialidade = "";
}

int Funcionario::getId(){
	return this->m_id;
}

string Funcionario::getNome(){
	return this->m_nome;
}

void Funcionario::setNome(string nome){
	this->m_nome = nome;
}



string Funcionario::getCpf(){
	return this->m_cpf;
}

void Funcionario::setCpf(string cpf){
	this->m_cpf = cpf;
}



short Funcionario::getIdade(){
	return this->m_idade;
}

void Funcionario::setIdade(short idade){
	this->m_idade = idade;
}



string  Funcionario::getTipoSanguineo(){
	return this->m_tipo_sanguineo;
}

void Funcionario::setTipoSanguineo(string tipo_sanguineo){
	this->m_tipo_sanguineo = tipo_sanguineo;
}



char Funcionario::getFatorRh(){
	return this->m_fator_rh;
}

void Funcionario::setFatorRh(char fator_rh){
	this->m_fator_rh = fator_rh;
}



string Funcionario::getEspecialidade(){
	return this->m_especialidade;
}

void Funcionario::setEspecialidade(string especialidade){
	this->m_especialidade = especialidade;
}		