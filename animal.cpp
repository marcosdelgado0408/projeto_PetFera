#include "animal.h"

/*static*/ int Animal::id_atual_animal = 1;

Animal::Animal(){
    this->m_classe = "";
    this->m_nome_cientifico = "";
    this->m_sexo = 'm';
    this->m_tamanho = 0.0;
    this->m_dieta = "";
    this->m_veterinario = m_veterinario;
    this->m_tratador = m_tratador;
    this->m_nome_batismo = "";
}

Animal::Animal(string m_classe, string m_nome_cientifico, char m_sexo, double m_tamanho, string m_dieta 
, Veterinario m_veterinario, Tratador m_tratador, string m_nome_batismo){
    this->m_classe = m_classe;
    this->m_nome_cientifico = m_nome_cientifico;
    this->m_sexo = m_sexo;
    this->m_tamanho = m_tamanho;
    this->m_dieta = m_dieta;
    this->m_veterinario = m_veterinario;
    this->m_tratador = m_tratador;
    this->m_nome_batismo = m_nome_batismo;
}

Animal::~Animal(){
    this->m_classe = "";
    this->m_nome_cientifico = "";
    this->m_sexo = 'm';
    this->m_tamanho = 0.0;
    this->m_dieta = "";
    this->m_veterinario = m_veterinario;
    this->m_tratador = m_tratador;
    this->m_nome_batismo = "";
}


int Animal::getId(){
    return this->m_id;
}

void Animal::setId(int id){
    this->m_id = id;
}



string Animal::getClasse(){
    return this->m_classe;
}

void Animal::setClasses(string classe){
    this->m_classe = classe;
}



string Animal::getNomecientifico(){
    return this->m_nome_cientifico;    
}
void Animal::setNomecientifico(string nomecientifico){
    this->m_nome_cientifico = nomecientifico;
}



char Animal::getSexo(){
    return m_sexo;
}
void Animal::setSexo(char sexo){
    this->m_sexo = sexo;
}



double Animal::getTamnho(){
    return this->m_tamanho;
}
void Animal::setTamnho(double tamanho){
    this->m_tamanho = tamanho;
}



string Animal::getDieta(){
    return this->m_dieta;
}
void Animal::setDieta(string dieta){
    this->m_dieta = dieta;
}



Veterinario Animal::getVeterinario(){
    return this->m_veterinario;
}
void Animal::setVeterinario(Veterinario veterinariozinho){
    this->m_veterinario = veterinariozinho;
}



Tratador Animal::getTratador(){
    return this->m_tratador;
}

void Animal::setTratador(Tratador tratadorzinho){
    this->m_tratador = tratadorzinho;
}



string Animal::getNomebatismo(){
    return this->m_nome_batismo;
}
void Animal::setNomebatismo(string nome_batismo){
    this->m_nome_batismo = nome_batismo;
}
