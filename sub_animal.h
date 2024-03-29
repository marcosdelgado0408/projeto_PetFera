#ifndef _sub_animal_h_
#define _sub_animal_h_

#include <iostream>
#include <string>
#include "animal.h"


/* Classe que armazenará todas as subclasses de animal.h */

typedef struct data{
	int dia;
	int mes;
	int ano;
}date;

class Anfibio: public Animal{
	protected:
		int m_total_de_mudas;
		date m_ultima_muda;
	public:
		Anfibio(int m_total_de_mudas, date m_ultima_muda);
		~Anfibio();

		int getTotalmudas();
		void setTotalmudas(int total_mudas);

		date getUltimamuda();
		void setUltimamuda(date ultima_muda);
};

class Mamifero: public Animal{
	protected:
		string m_cor_pelo;
	public:
		Mamifero(string m_cor_pelo);
		~Mamifero();

		void setCorPelo(string cor_pelo);
		string getCorPelo();
};

class Reptil: public Animal{
	protected:
		bool m_venenoso;
		string m_tipo_veneno;
    
	public:
		Reptil(bool m_venenoso, string m_tipo_veneno);
		~Reptil();

		bool getVenenoso();
		void setVenenoso(bool venenoso);
};

class Ave: public Animal{
	protected:
		double m_tamanho_do_bico_cm;
		double m_envergadura_das_asas;

	public:
		Ave(double m_tamanho_do_bico_cm, double m_envergadura_das_asas);
		~Ave();

		void setTamanhobico();
		double getTamanhobico(double tamanho_bico);

		void setEnvergaduraAsas();
		double getEnvergaduraAsas(double envergadura_asas);
};


#endif
