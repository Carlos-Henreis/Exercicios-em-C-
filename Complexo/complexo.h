#ifndef COMPLEXO_H
#define COMPLEXO_H


class Complexo{

private:
	double real, imaginaria;
	int static contador;


public:
	Complexo();
	Complexo(double, double);
	~Complexo();
	//necessário para 'manipular' os atributos
	void setReal (double);
	void setImaginario (double);
	double getReal (void);
	double getImaginario (void);
	void somar(Complexo, Complexo);
	void subtrair(Complexo, Complexo);
	void multiplicar(Complexo, Complexo);
	void dividir();
	void modulo();
	void imprimir();

};


#endif