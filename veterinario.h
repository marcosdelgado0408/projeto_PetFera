#ifndef _veterinario_h_
#define _veterinario_h_

#include <string>
#include "funcionario.h"

class Veterinario: public Funcionario{
	private:
		string m_crm;
	public:
		Veterinario();
		Veterinario(string m_nome, string m_cpf, short m_idade, string m_tipo_sanguineo, char m_fator_rh, string m_especialidade, string m_crm);
		~Veterinario();

		string get_nome_vet();
};

#endif
