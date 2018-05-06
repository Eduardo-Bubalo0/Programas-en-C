#include <stdio.h> 
#include <stdlib.h> 

void main(void) 
{ 
     /* DECLARACIÓN DE VARIABLES (realice tabla de objetos) */ 
     int M[10][10];  /* Matriz de dimension máxima 10x10*/ 
     int i,j;          /* Índices para la indexación de la matriz*/ 
     int nc;           /* Número de columnas de la matriz cuadrada*/ 
     int resultado;  
     /* LECTURA DE DATOS */ 
     printf("Introduzca el numero de columnas de la matriz (<11): "); 
     scanf("%d",&nc); 
     printf("El primer elemento de la matriz es el M11\n");           
     for(i=1;i<=nc;i++) /* lectura de matriz */ 
     { 
        for(j=1;j<=nc;j++) 
        {               
            printf("M%d%d = ",i,j); 
            scanf("%d",&M[i-1][j-1]);  
        } 
    }
    for(i=1;i<=nc;i++) /* muestra matriz */ 
     {
     	printf("\n"); 
        for(j=1;j<=nc;j++) 
        {
        	printf("%d ", M[i-1][j-1]);
        }
    }
    printf("\n");
} 