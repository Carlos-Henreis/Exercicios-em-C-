
/*
* Referencias: Algoritmos de Euclides: https://www.ime.usp.n2r/~mms/mac1222s2013/12%20-%20algoritmos%20e%20funcoes%20recursivas.pdf
*              Algoritmos de Stein: http://www.geeksforgeeks.org/steins-algorithm-for-finding-gcd/
*              Medir o Tempo de Execução: http://www.qnx.com/developers/docs/6.3.0SP3/neutrino/lib_ref/c/clock_gettime.html
*/

#include <iostream>//Leitura e escrita (cout cin, etc)
#include <string>//Manipular strings
#include <fstream>//Manipular arquivos externos
#include <ctime>//Efetuar as medidas de tempos
#include <cstdlib>

#define BILLION  1000000000L;

using namespace std;

class MDC  {
   public:
      //atrinbutos
      int num1;//entrada 1
      int num2;//entrada 2
      int mdc;//valor do mdc

      //construtores
      MDC();
      MDC(int pNum1, int pNum2);
      //destrutor
      ~MDC();
      //Usando algoritmo de Euclides
      int mdcEuclidesIterativo (int n1, int n2);
      int mdcEuclidesRecursivo (int n1, int n2);
      //algoritmo de Stein
      int mdcIterativo (int n1, int n2);
      int mdcRecursivo (int n1, int n2);
      //Demais métodos
      void carga ();
      void testaCarga();
      void serializaTestes ();
};
//Construtor que inicializa os dados com zeros
MDC::MDC() {
   mdc = num1 = num2 = 0;

}
//Construtor com parametros
MDC::MDC(int pNum1, int pNum2) {
   num1 = pNum1;
   num2 = pNum2;
   //Calculo do mdc dos parametros
   mdc = mdcEuclidesRecursivo (num1, num2);
}
//Destrutor
MDC::~MDC(){
   // chamada quando destrutor é utilizado
}
//Da Literatura: mdc(a, n2) = n2 se n2 divide n1 ou seja a%n2 = 0 ou mdc(n2, a%n2) caso contrário
int MDC::mdcEuclidesIterativo (int n1, int n2) {
   int r;
   r = n1 % n2;
   while (r != 0) {
      n1 = n2;
      n2 = r;
      r = n1 % n2;
   }
   return n2;
}
int MDC::mdcEuclidesRecursivo (int n1, int n2){
   //Critério de parada da função recursiva
   if (n1 % n2 == 0) 
      return n2;
   return mdcEuclidesRecursivo (n2, n1 % n2);

}
//Método com a implementação do algoritmo de Stein Iterativo
int MDC::mdcIterativo (int n1, int n2) {
   /* Note que MDC(0, num2 == num2; MDC(num1,0) == num1, MDC(0,0) == 0 */
   if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    int k;
    //Manipulação dos bits
    for (k = 0; ((n1 | n2) & 1) == 0; ++k){
        n1 >>= 1;
        n2 >>= 1;
    }
    while ((n1 & 1) == 0)
        n1 >>= 1;
    do{
        while ((n2 & 1) == 0)
            n2 >>= 1;

        if (n1 > n2)
            swap(n1, n2);

        n2 = (n2 - n1);
    }   while (n2 != 0);

    return n1 << k;
}

int MDC::mdcRecursivo (int n1, int n2) {
   if (n1 == n2)
      return n1;
   if (n1 == 0)
      return n2;
   if (n2 == 0)
      return n1;

   if (~n1 & 1 ) {
      if (n2 & 1)   
         return mdcRecursivo (n1 >> 1, n2);
      else      
         return mdcRecursivo (n1 >> 1, n2 >> 1) << 1;
   }

   if (~n2 & 1)     
      return mdcRecursivo(n1, n2 >> 1);

   if  (n1 > n2)
      return mdcRecursivo( (n1 - n2) >> 1, n2);

   return mdcRecursivo((n2 - n1) >> 1, n1);
}

void MDC::carga () {
   //gera valores entre 0 e 10⁴
   int maior = 10000;
   int menor = 0;
   num1 = rand()%(maior-menor+1);
   //para num2 gera valores de 2x10⁴ até 10⁵
   maior = 100000;
   menor = 20000;
   num2 = rand()%(maior-menor+1);
}

void MDC::testaCarga() {
   //Teste 1000 vezes os quatro algoritmos
   for (int i =0; i< 1000; i++){
      MDC::carga ();//gera os valores aleatórios
      cout << num1<<","<<num2 << endl;
      cout << "Saidas\n";
      cout << "======================\n";
      mdc = mdcEuclidesIterativo(num1, num2);
      cout << "\n Euclides iterativo: " << mdc << endl;
      mdc = mdcEuclidesRecursivo(num1, num2);
      cout << "\n Euclides recursivo: " << mdc << endl;
      mdc = mdcIterativo(num1, num2);
      cout << "\n mdc Stein  iterativo: " << mdc << endl;
      mdc =  mdcRecursivo(num1, num2);
      cout << "\n mdc Strin recursivo: " << mdc << endl;
   }
   return;
}
void MDC::serializaTestes () {
    //O arquivo vai ter 1000 linhas
    //cada linha numero da iteração num1, num2, resultado de tempos dos 4 métodos
    ofstream fout ("resultado.txt");//Cria arquivo
    //Variáveis para calcular o tempo de execução
    struct timespec start, stop;
    double accum;
    for (int i = 0; i < 1000; ++i){
      MDC::carga ();//gera os valores aleatórios
      fout << i+1 << "  ";
      fout << num1<<" "<<num2;//Persiste num1 e num2
      //Começa a marcar o tempo
      if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      mdc = mdcEuclidesIterativo(num1, num2);
      //Finaliza a marcação
      if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      //Calcula o tempo em milisegundos
      accum = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;
      //Persiste o tempo no arquivo
      fout << " " << accum;
      //Repete para os outro 3 métodos
      if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      mdc = mdcEuclidesRecursivo(num1, num2);
      if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      accum = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;

      fout << " " << accum;

      if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      mdc = mdcIterativo(num1, num2);
      if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      accum = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;

      fout << " " << accum;

      if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      mdc =  mdcRecursivo(num1, num2);
      if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
         perror( "clock gettime" );
         return ;
      }
      accum = ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec ) / (double)BILLION;

      fout << " " << accum << endl;
   }
   return;
}



 int main (void) {
   MDC m1;//intancia um objeto da classe MDC
   //Faz os teste com as 1000 cargas
   m1.testaCarga();
   //Persisti os dados em um arquivo
   m1.serializaTestes();
   return 0;
 }
