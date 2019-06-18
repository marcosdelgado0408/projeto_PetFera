#ifndef _administrador_h_
#define _administrador_h_

#include <iostream>
#include <string>
#include <map>

#include "exoticos.h"
#include "veterinario.h"
#include "tratador.h"

using namespace std;

class Administrador{
	protected:
		map<int, Animal> lista_animais> lista_animais; /* informações a serem adicionadas no arquivo texto */
		map<int, Veterinario> lista_veterinarios;
		map<int, Tratador> lista_tratadores;
	public:
		int cadastrar_animal(Animal *a);
		int remover_animal(Animal *a);
		int alterar_animal(Animal *a);
		int consultar_animal(int id);

		int cadastrar_funcionario(Funcionario *f);
		int remover_funcionario(Funcionario *f);
		int alterar_funcionario(Funcionario *f);
		int consultar_animal(int id);
		
}	

#endif
