#ifndef _veterinario_h_
#define _veterinario_h_

#include <string>
#include "funcionario.h"

class Veterinario: public Funcionario{
	private:
		string m_crm;
	public:
		Veterinario(string m_crm);
		~Veterinario();
}

#endif
