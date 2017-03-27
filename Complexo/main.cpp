#include <iostream>
#include "complexo.h"

using namespace std;


int main(void){

	Complexo num1;
	Complexo num2;
	Complexo num3;
	int sair = 1;
	double preal, pimaginaria;
	int op;
	do{
		cout<<("1 - Somar\n");
		cout<<("2 - Subtrair\n");
		cout<<("3 - Multiplicar\n");
		cout<<("4 - Dividir\n");
		cout<<("5 - Modulo\n");
		cout<<("6 - Imprimir resposta\n");
		cout<<("7 - Sair\n");

		cout<<("Opcao: ");
		cin >> op;


		switch(op){
			case 1:
				cout<<"Primeiro numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num1.setReal(preal);
				num1.setImaginario(pimaginaria);

				cout<<"Segundo numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num2.setReal(preal);
				num2.setImaginario(pimaginaria);

				num3.somar(num1, num2);
				break;

			case 2:
				cout<<"Primeiro numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num1.setReal(preal);
				num1.setImaginario(pimaginaria);

				cout<<"Segundo numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num2.setReal(preal);
				num2.setImaginario(pimaginaria);

				num3.subtrair(num1, num2);
				break;

			case 3:
				cout<<"Primeiro numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num1.setReal(preal);
				num1.setImaginario(pimaginaria);

				cout<<"Segundo numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num2.setReal(preal);
				num2.setImaginario(pimaginaria);

				num3.multiplicar(num1, num2);
				break;
			case 6://não intendi aqui
				cout<<"Primeiro numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num1.setReal(preal);
				num1.setImaginario(pimaginaria);

				cout<<"Segundo numero"<<endl;
				cout<<"Real: ";
				cin>>preal;
				cout<<"Imaginaria: ";
				cin>>pimaginaria;
				num2.setReal(preal);
				num2.setImaginario(pimaginaria);

				num1.imprimir();
				num2.imprimir();

			default:
				sair = 0; 
				break;
				
		}
	}while (sair == 1);
	
	return 0;
}