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
	public:
		static map<int, Animal> lista_animais; /* informações a serem adicionadas no arquivo texto */
		static map<int, Veterinario> lista_veterinarios;
		static map<int, Tratador> lista_tratadores;

		int cadastrar_animal(Animal *a);
		int remover_animal(Animal *a);
		int alterar_animal(Animal *a);
		int consultar_animal(int id);

		int cadastrar_funcionario(Funcionario *f, int tipo);
		int remover_funcionario(Funcionario *f, int tipo);
		int alterar_funcionario(Funcionario *f, int tipo);
		int consultar_funcionario(int id);
		
		void listar_funcionarios(int param);
		void mostrar_menu();
};	

#endif
