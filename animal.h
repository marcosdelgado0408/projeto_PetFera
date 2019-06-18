#ifndef _animal_h_
#define _animal_h_

#include <string>

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
		Animal(string m_classe, string m_nome_cientifico, char m_sexo, double m_tamanho, string m_dieta, Veterinario m_veterinario, Tratador m_tratador, string m_nome_batismo);
		~Animal();
}

#endif
