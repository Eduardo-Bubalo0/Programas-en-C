#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

int main(){
	
	//archivo
	 FILE* miarchivo;
    char* nombrearchivo= "Programa1.txt";
   // char cadena[1000];
    miarchivo= fopen(nombrearchivo,"w"); 
    if (miarchivo == NULL)
    
     printf("Archivo no existente");
    //archivo
    while(1){
		char x;
		int k;
     int numero, i, conver, bin, lugares=0, unos=0, ceros, pot, l, dis, m;
     printf("\n\n\t**Programa que muestra las cadenas posibles dependiendo de su potencia de un alfabeto**\n\n");     
     printf("\n\n\tDesea Introducir Manualmente la potencia: N /Y \t");
     scanf("%c", &x);
     if(x == 'y')
     {
     printf("\n\n\tIntroduzca la potencia:\t");
     scanf("%d",&numero);
	}
	else if(x == 'n')
	{
		srand(time(NULL));
		numero = rand()%10;	 
		printf("Numero aleatorio es : %d\n", numero);
	
		}
	//archivo
      fflush(stdin);
      //archivo
      for(l=0; l<=numero; l++){
     dis=l;
     
     pot=pow(2,l);
     ceros=l;     
     
     if(l==0) printf("\n\n\tEl alfabeto es nulo");
      else{
               printf("\n\n\nz^%d es: ", l);
               //archivo
               fprintf(miarchivo,"\n\n\nz^%d es: ", l);
               //archivo
               
               pot=pow(2,l);
          printf("\n\t{");
          //archivo
          fprintf(miarchivo,"\n\t{");
          //archivo
          
          for(i=0;i<pot;i++){  
               conver=i; unos=0;
               while(conver!=0){
                    bin= conver%2;
                    conver=conver/2;
                    printf("%d",bin);
                    //archivo
                    fprintf(miarchivo,"%d",bin);
                    //archivo
                    unos++;
               }
               ceros=ceros-unos; 
               
               while(lugares<ceros){
                    printf("0");
                    //archivo
                    fprintf(miarchivo,"0");
                    //archivo
                    lugares++;
               }                    
               if(i<pot-1) {
               	printf(",");
               	//archivo
               	fprintf(miarchivo,",");
               	//archivo
               }
                 else printf(""); 
				 //archivo
				 fprintf(miarchivo,"");
				 //archivo 
                 
                                
               ceros=numero;
               lugares=0;
          }
      
     printf("}"); 
     //archivo
     fprintf(miarchivo,"}"); 
     //archivo
      } 
      }
      printf("\n\n\nSi desea continuar presione cualquier tecla, de lo contrario presione Ctrl + C");
     //system('cls');
     //archivo
     fclose(miarchivo);
     //archivo
	
     
     getch();
     }
}