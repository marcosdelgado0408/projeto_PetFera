#include "animal.h"

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
