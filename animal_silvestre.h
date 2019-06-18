#ifndef _animal_silvestre_h_
#define _animal_silvestre_h_

#include <string>

class AnimalSilvestre{
	protected:
		string  m_autorizacao_ibama;
	public:
		AnimalSilvestre(string m_autorizacao_ibama);
		~AnimalSilvestre();
}

#endif 
