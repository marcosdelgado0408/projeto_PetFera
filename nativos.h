#ifndef _nativos_h_
#define _nativos_h_

#include "sub_animal.h"
#include "animal_silvestre.h"

class AnimalNativo: public AnimalSilvestre{
	protected:
		string m_uf_origem;
		string m_autorizacao;
	public:
		AnimalNativo(string m_uf_origem, string m_autorizacao);
		~AnimalNativo();
};

class MamiferoNativo: public Mamifero, public AnimalNativo{
	public:
		MamiferoNativo();
		~MamiferoNativo();
};

class ReptilNativo: public Reptil, public AnimalNativo{
	public:
		ReptilNativo();
		~ReptilNativo();
};

class AnfibioNativo: public Anfibio, public AnimalNativo{
	public:
		AnfibioNativo();
		~AnfibioNativo();
};

class AveNativo: public Ave, public AnimalNativo{
	public:
		AveNativo();
		~AveNativo();
};

#endif
