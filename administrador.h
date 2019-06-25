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

		void cadastrar_animal(Animal *a);
		void remover_animal(int id);
		void alterar_animal(Animal *a);
		void consultar_animal(int id);

		void cadastrar_funcionario(Veterinario *vet);
		void cadastrar_funcionario(Tratador *trat);

		void remover_funcionario(int tipo, int id);
		void alterar_funcionario(int tipo, int id);
		void consultar_funcionario(int tipo, int id);
				
		void listar_funcionarios(int param);
		void listar_animais();
		void mostrar_menu();
};	

#endif
