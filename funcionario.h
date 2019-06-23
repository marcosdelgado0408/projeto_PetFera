#ifndef _funcionario_h_
#define _funcionario_h_

#include <string>
#include <iostream>

using namespace std;

class Funcionario{

	protected:
		int m_id;
		string m_nome;  
		string m_cpf;
		short m_idade;
		string m_tipo_sanguineo;
		char m_fator_rh;
		string m_especialidade;

	public:
		static int id_atual_funcionario;

		Funcionario();
		Funcionario(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade);
		~Funcionario();
		
		string getNome();
		void setNome(string nome);

		string getCpf();
		void setCpf(string cpf);

		short getIdade();
		void setIdade(short idade);

		string getTipoSanguineo();
		void setTipoSanguineo(string tipo_sanguineo);
		
		char getFatorRh();
		void setFatorRh(char fator_rh);
		
		string getEspecialidade();
		void setEspecialidade(string especialidade);
};

#endif
