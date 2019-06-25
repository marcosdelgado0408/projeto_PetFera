#ifndef _administrador_h_
#define _administrador_h_

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

using namespace std;

class Administrador{
	public:
		map<int, Animal> lista_animais; /* informações a serem adicionadas no arquivo texto */
		map<int, Veterinario> lista_veterinarios;
		map<int, Tratador> lista_tratadores;

		int cadastrar_animal(Animal *a);
		int remover_animal(Animal *a);
		int alterar_animal(Animal *a);
		int consultar_animal(int id);

		int cadastrar_funcionario(Veterinario *vet);
		int cadastrar_funcionario(Tratador *trat);

		int remover_funcionario(Funcionario *f, int tipo);
		int alterar_funcionario(Funcionario *f, int tipo);
		int consultar_funcionario(int id);
		
		void listar_funcionarios(int param);
		void mostrar_menu();
};	

#endif
