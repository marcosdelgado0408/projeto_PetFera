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

<<<<<<< HEAD
		string get_m_crm();
=======
		string getCrm();
		void setCrm(string crm);
>>>>>>> 86a2f884261b153ac0907e27fd37997caa9b6379
};

#endif
