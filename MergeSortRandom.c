#include <stdio.h>
#include <stdlib.h>

#define TAM 10 /* Tamaño del arreglo de datos */

void CargarDatos(int *,int);
void MostrarDatos(int *,int );
void Fusion(int *, int, int *, int, int *, FILE *,int *);
void Insertar(int *, int,int *,FILE *);
void MergeSort(int *, int, FILE *,int *);

int main()
{
	int arreglo[TAM],comparaciones;
	FILE *fi;
	comparaciones=0;
	if((fi=fopen("resultado_mergesort.txt","w"))!=NULL){
		CargarDatos(arreglo, TAM);/* Se genera un arreglo de datos aleatorios */
		printf("El arreglo desordenado es: \n");/* Se muestra por pantalla el arreglo generado */
		MostrarDatos(arreglo, TAM);
		MergeSort(arreglo, TAM,fi,&comparaciones);/* Se aplica el algoritmo mergesort al arreglo */
		printf("\nEl arreglo despues del algoritmo de mergesort es: \n");/* Se muestra por pantalla el arreglo después de aplicarle mergesort */
		MostrarDatos(arreglo, TAM);
		fclose(fi);/* Se cierra el fichero */
		printf("\nEl numero de comparaciones realizadas es: %d\n",comparaciones);
	}
	else
		printf("\nError al crear el fichero \"resultado_mergesort.txt\".\n");
return 0;
}

/* FUNCIONES UTILIZADAS */
/* Función que ordena un arreglo utilizando mergesort */
void MergeSort(int *arreglo, int tam,FILE *fichero,int *comparaciones)
{
	int *c,*s,*n,*p,i;

	if (tam<2) /* Si el arreglo es suficientemente pequeño se aplica inserción directa */
		Insertar(arreglo, tam,comparaciones,fichero);
	else {
		fprintf(fichero,"\nEl arreglo que hay que partir en dos es:\n");
		for(i=0;i<=tam-1;i++)
    		fprintf(fichero,"%5d",arreglo[i]);
		fprintf(fichero,"\n");
		c= (int *)calloc(tam/2,sizeof(int));/* Se crea un subarreglo que contiene la mitad izquierda del arreglo */
		s=c;
		fprintf(fichero,"\nLas mitades que se generan son: \n");
		for(i=0;i<tam/2;i++){
			s[i]=arreglo[i];
			fprintf(fichero,"%5d",s[i]);
		}
		n= (int *)calloc(tam-tam/2,sizeof(int));/* Se crea un subarreglo que contiene la mitad derecha del arreglo */
		s=n;
		fprintf(fichero,"      y   ");
		for(i=0;i<tam-tam/2;i++){
			s[i]=arreglo[tam/2+i];
			fprintf(fichero,"%5d",s[i]);
		}
		fprintf(fichero,"\n");
		s=c;
		p=n;
		/* Se llama recursivamente a mergesort para ordenar cada una de las mitades */
		MergeSort(s,tam/2,fichero,comparaciones); /* mitad izquierda */
		MergeSort(p,tam-tam/2,fichero,comparaciones); /* mitad derecha */
		/* Se fusionan dos subarreglo ordenados */
		Fusion(s,tam/2,p,tam-tam/2,arreglo,fichero,comparaciones);
		/* Se libera la memoria dinámica utilizada */
		free(c);
		free(n);
	}
}

/* Función que ordena un arreglo mediante el método de inserción directa */
void Insertar(int *arreglo, int tam,int *comparaciones,FILE *fichero)
{
	int i, j,k, aux;

	fprintf(fichero,"\nALGORITMO INSERTAR\n");
	fprintf(fichero,"Areglo de entrada\n");
	for(k=0;k<=tam-1;k++)
    	fprintf(fichero,"%5d",arreglo[k]);
	fprintf(fichero,"\n");


	for(i=1;i<tam;i++){
		aux=arreglo[i]; /* Elemento a insertar en su posición correcta */
		j=i-1;
		while((aux<=arreglo[j])&&(j>0)){
			arreglo[j+1]=arreglo[j]; /* Hago sitio */
			j=j-1; /* Retrocedo */
			*comparaciones=*comparaciones+1;
		}
		/* Se inserta el elemento en la posición que le corresponde */
		if (aux>arreglo[j]){
			arreglo[j+1]=aux;
			*comparaciones=*comparaciones+1;
		}
		else {
			arreglo[j+1]=arreglo[j];
			arreglo[j]=aux;
		}
        *comparaciones=*comparaciones+2;
		fprintf(fichero,"\nVector tras iteración %d\n",i);
		for(k=0;k<=tam-1;k++)
    		fprintf(fichero,"%5d",arreglo[k]);
		fprintf(fichero,"\n");
	}
	fprintf(fichero,"\nVector al final\n");
	for(k=0;k<=tam-1;k++)
    	fprintf(fichero,"%5d",arreglo[k]);
	fprintf(fichero,"\n");
}

/* Función que fusiona dos subarreglo ordenados en uno también ordenado */
void Fusion(int *u, int tamu, int *v, int tamv, int *w,FILE *fichero,int *comparaciones)
{
	int i, j, k;
	i=0;
	j=0;

	fprintf(fichero,"\nLos vectores a fusionar son:\n");
	for(k=0;k<tamu;k++)
    	fprintf(fichero,"%5d",u[k]);
	fprintf(fichero,"        y   ");
	for(k=0;k<tamv;k++)
    	fprintf(fichero,"%5d",v[k]);
	fprintf(fichero,"\n");
	k=0;
	/* Se comparan los elementos de los dos subarreglo y se va eligiendo el menor */
	while((i<=tamu-1)&&(j<=tamv-1)){
		if (u[i]<v[j]){
			w[k]=u[i];
			k++;
			i++;
			*comparaciones=*comparaciones+1;
		}
		else if (u[i]>v[j]){
			w[k]=v[j];
			k++;
			j++;
			*comparaciones=*comparaciones+1;
		}
		else{
			w[k]=u[i];
			w[k+1]=v[j];
			k=k+2;
			i++;
			j++;
		}
    }
    *comparaciones=*comparaciones+2;
	/* Se añaden los elementos del subarreglo que no se haya terminado */
	while(i<=tamu-1){
		w[k]=u[i];
		k++;
		i++;
	}
	while(j<=tamv-1){
		w[k]=v[j];
		k++;
		j++;
	}
	/* Se escribe en el fichero el arreglo que resulta de fusionar los dos subvectores */
	fprintf(fichero,"Vector fusionado\n");
	for(k=0;k<tamu+tamv;k++)
    	fprintf(fichero,"%5d",w[k]);
	fprintf(fichero,"\n\n");
}

/* Funcion que genera un arreglo de numeros aleatorios del tamaño que se especifique */
void CargarDatos(int *arreglo, int tam)
{
  int i;
  srand(tam);
  for(i=0;i<=tam-1;i++)
    arreglo[i]=(int ) TAM*(rand()*1.0/RAND_MAX);
}

/* Funcion que muestra por pantalla los elementos de un arreglo que se especifiquen */
void MostrarDatos(int *arreglo,int tam)
{
	int i;
	for(i=0;i<=tam-1;i++){
		printf("%7d",arreglo[i]);
		if ((i+1)%10==0)
			printf("\n");
	}
	printf("\n");
}