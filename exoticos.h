#ifndef _exoticos_h_
#define _exoticos_h_

#include "sub_animal.h"
#include "animal_silvestre.h"

class AnimalExotico: public AnimalSilvestre{
	protected:
		string m_pais_origem;
	public:
		AnimalExotico(string m_pais_origem);
		~AnimalExotico();
};

class MamiferoExotico: public Mamifero, public AnimalExotico{
	public:
		MamiferoExotico();
		~MamiferoExotico();
};

class ReptilExotico: public Reptil, public AnimalExotico{
	public:
		ReptilExotico();
		~ReptilExotico();
};

class AnfibioExotico: public Anfibio, public AnimalExotico{
	public:
		AnfibioExotico();
		~AnfibioExotico();
};

class AveExotico: public Ave, public AnimalExotico{
	public:
		AveExotico();
		~AveExotico();
};

#endif
