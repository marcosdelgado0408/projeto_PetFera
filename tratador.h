#ifndef _tratador_h_
#define _tratador_h_

#include "funcionario.h"

class Tratador: public Funcionario{
	private:
		int m_nivel_de_seguranca;
	public:
		Tratador();
		Tratador(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade, int m_nivel_de_seguranca);
		~Tratador();

		int get_nivel_de_seguranca();
};


#endif
