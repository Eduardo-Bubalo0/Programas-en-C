#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

void binario(bin){
     
    while(bin!=0){                  
         printf("%d", bin%2);
         bin=bin/2;
    }
    
}

void primo (int num, int div, int cont){
    for(div=2;div<num;div++){
                             cont=num%div;                             
                             if(cont==0)  break;
                             }
     if(cont!=0){
                 
                 printf("\n\t\t\t%d  --  ", num);      
                 binario(num);
                 //printf(",");
                 }
}


main(){
	FILE*miarchivo;
	char* nombrearchivo= "Programa2.txt";
	miarchivo=fopen(nombrearchivo,"w");
	 if (miarchivo == NULL)
    
     printf("Archivo no existente");
     
       while(1){
			char x;
			int in, lim, j;
       printf("\n\t\t****Programa que calcula numeros primos dentro de un rango****\n\n");
        printf("\n\n\tDesea Introducir Manualmente la potencia: N /Y \t");
       scanf("%c", &x);
       if(x == 'y')
       {
       printf("\n\n\tIngrese desde donde quiere empezar a buscar: \t");
       scanf("%d", &in);
       
       printf("\n\n\t Ingrese hasta donde quiere buscar: \t");
       scanf("%d", &lim); 
		}
		else if(x == 'n')
		{
		in = rand()%10;	
		lim = rand()%100; 
		printf("Primer numero aleatorio desde donde quiere empezar a buscar: %d\n\n", in);
		printf("Segundo numero aleatorio desde donde quiere empezar a buscar: %d\n\n", lim);
	
		}
       printf("\n\n\tLos numeros primos dentro rango %d a %d son: \n\n\t", in, lim);
          fprintf(miarchivo,"\n\n\tLos numeros primos dentro rango %d a %d son: \n\n\t", in, lim);
       for(j=in; j<=lim; j++){                 
                 primo(j, 2, 0);
                             
       }
         
       printf("\n\n\nSi desea continuar presione cualquier tecla, de lo contrario presione Ctrl + C\n\n");
     //system('cls');
     fclose(miarchivo);
       getch();
   }
}