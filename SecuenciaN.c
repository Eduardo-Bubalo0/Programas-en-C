#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

main(){
       while(1){
			char x;
       int sec, i, j, k, h;
       
       FILE*miarchivo;
	char* nombrearchivo= "Programa3.txt";
	miarchivo=fopen(nombrearchivo,"w");
	 if (miarchivo == NULL)
    
     printf("Archivo no existente");
             
       printf("\n\n\t***Programa que imprime genera secuencia de n***");
       printf("\n\n\tDesea Introducir Manualmente la potencia: N /Y \t");
       scanf("%c", &x);
       if(x == 'y')
       {
       printf("\n\nIntroduzca la potencia de la secuencia: \t");
       scanf("%d", &sec);
		}
		else if(x == 'n')
		{
			sec=rand()%100;
			printf("El numero aleatorio es: %d\n\n", sec);
			
			}
       k=sec;
       printf("{");
       fprintf(miarchivo,"{");
       
       for(i=0; i<sec; i++){
           for(j=0; j<k; j++)
                    printf("0");
                    fprintf(miarchivo,"0");
                    
           for(h=0; h<k; h++)
                    printf("1");
                    fprintf(miarchivo,"1");
           printf(",");
           fprintf(miarchivo,",");
           k=k-1;
       
       }
       printf("}");
       fprintf(miarchivo,"}");
            
       
       printf("\n\n\nSi desea continuar presione cualquier tecla, de lo contrario presione Ctrl + C\n\n");
     //system('cls');
       getch();
       
}
}