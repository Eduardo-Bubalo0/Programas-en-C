#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_TOTAL 100
int cont;
// Funciones
void gen_rand(int v[], int tam);
void imprime_arreglo(int v[], int tam);
void swap(int v[], int o, int d);
void bubble_sort(int v[], int tam);

int main(int argc, char *argv[])
{
 int v[TAM_TOTAL];

 printf("\n");
 printf("------- Ordenando numeros aleatorios con ordenamiento Burbuja -------\n");
 gen_rand(v, TAM_TOTAL);
 printf("\n");
 printf("No. Aleatorios: ");
 printf("\n");
 printf("Se generaron %d numeros aleatorios\n",TAM_TOTAL);
 printf("\n");
 imprime_arreglo(v, TAM_TOTAL);

 bubble_sort(v, TAM_TOTAL);
 printf("\n");
 printf("No. Ordenados : ");
 printf("\n");

 imprime_arreglo(v, TAM_TOTAL);
 printf("\n");
 return 0;
}

void gen_rand(int v[], int tam)
{
 int i;

 cont = cont + 1;
 srand(time(NULL)*cont);
 for(i=0; i<tam; i++)
  v[i]=rand()%1000;
}


void imprime_arreglo(int v[], int tam)
{
 int i;
 printf("[ ");
 for(i=0; i<tam; i++)
  printf("%d ", v[i]);
 printf("]\n");
}

void swap(int v[], int o, int d)
{
 int temp;
 temp=v[d];
 v[d]=v[o];
 v[o]=temp;
}

void bubble_sort(int v[], int tam)
{
 int i, j;
 for (j=0; j<tam; j++)
  for (i=0; i<tam-1; i++)
   if(v[i]>v[i+1])
    swap(v, i, i+1);
}
