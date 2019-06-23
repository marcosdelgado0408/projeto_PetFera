#ifndef _animal_h_
#define _animal_h_

#include <iostream>
#include <string>
#include "veterinario.h"
#include "tratador.h"

using namespace std;

class Animal{
	protected:
		int m_id;
		string m_classe;
		string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		string m_dieta;
		Veterinario m_veterinario; /* associatividade da classe Vetrinario com a classe Animal*/
		Tratador m_tratador;       /* associatividade da classe Tratador com a classe Animal*/
		string m_nome_batismo;
        

	public:
		static int id_atual_animal;

		Animal();
		Animal(string m_classe, string m_nome_cientifico, char m_sexo, double m_tamanho, string m_dieta, Veterinario m_veterinario, Tratador m_tratador, string m_nome_batismo);
		~Animal();

		int getId();
		void setId(int id);

		string getClasse();
		void setClasses(string classe);

		string getNomecientifico();
		void setNomecientifico(string nomecientifico);

		char getSexo();
		void setSexo(char sexo);

		double getTamnho();
		void setTamnho(double tamanho);

		string getDieta();
		void setDieta(string dieta);

		Veterinario getVeterinario();
		void setVeterinario(Veterinario veterinariozinho);

		Tratador getTratador();
		void setTratador(Tratador tratadorzinho);

		string getNomebatismo();
		void setNomebatismo(string nome_batismo);


};

#endif
