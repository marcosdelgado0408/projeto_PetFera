#ifndef _tratador_h_
#define _tratador_h_

#include "funcionario.h"

class Tratador: public Funcionario{
	private:
		int m_nivel_de_seguranca;
	public:
		Tratador();
		Tratador(int m_nivel_de_seguranca);
		~Tratador();
};


#endif
