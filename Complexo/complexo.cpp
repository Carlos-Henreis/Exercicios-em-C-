#include <iostream>
#include "complexo.h"

using namespace std;

Complexo::Complexo(){
	//Construtor sem parâmetro
}

Complexo::Complexo(double r, double i){
	//Construtor com parâmetros
	real = r;
	imaginaria = i;
}

Complexo::~Complexo(){
	//Destrutor
}

void Complexo::setReal (double pReal) {
	real = pReal;
}

void Complexo::setImaginario (double pImaginaria){
	imaginaria = pImaginaria;
}

double Complexo::getReal (void){ 
	return real;
}
double Complexo::getImaginario (void){
	return imaginaria;
}


void Complexo::somar(Complexo c1, Complexo c2){
	real = c1.real + c2. real;
	imaginaria = c1.imaginaria + c2.imaginaria;
	imprimir();
}

void Complexo::subtrair(Complexo c1, Complexo c2){
	real = c1.real - c2. real;
	imaginaria = c1.imaginaria - c2.imaginaria;
	imprimir();
}

void Complexo::multiplicar(Complexo c1, Complexo c2){
	real = c1.real * c2.real - c1.imaginaria * c2.imaginaria;
	imaginaria = c1.real * c2.imaginaria + c1.imaginaria * c2.real;
	imprimir();

}

void Complexo::dividir(){

}

void Complexo::modulo(){

}

void Complexo::imprimir(){
		cout<<real<<"+"<<imaginaria<<"i"<<endl;
}