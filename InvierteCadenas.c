#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char* invertir_str(char * str)
{
	int len;
	int i;
	char *invstr;
	len = strlen(str);
	invstr = (char*)malloc((len + 1) * sizeof(char));
	for (i=0; i<len; i++)
	invstr[i] = str[len-1 - i];
	invstr[len] = '\0';
	return invstr;
}

/*int generador() {
srand(time(NULL));
return ( rand() %2);
} */

int main()
{
	 FILE* miarchivo;
    char* nombrearchivo= "Programa11.txt";
   // char cadena[1000];
    miarchivo= fopen(nombrearchivo,"w");
    if (miarchivo == NULL)
    { printf("Archivo no existente");}



   int n, reverse = 0, temp, x, log,num;
   char cadena[20];


   printf("\n\t\t****Programa que produce palindromos*****\n\n");

   printf("Longitud:\n\n");
   printf("1) Definida por el usuario\n\n");
   printf("2) Aleatoria\n");
   scanf("%d",&x);
   srand(time(NULL));
   if(x == 1)
     {
     printf("\n\n\tIntroduzca la longitud:\t");
     scanf("%d",&log);
     for(n=0;n<log;n++){

			cadena[n] = rand() %2+49;
			char* cadena2 = invertir_str(cadena);
			printf("%s%s\n", cadena,cadena2);
			fprintf(miarchivo,"%s%s\n", cadena,cadena2);

     }

	}
	else if(x == 2)
	{
		for (n = 0; n <4; n++){
			cadena[n] = rand() %100;
		}

		char* cadena2 = invertir_str(cadena);
		printf("%s%s\n", cadena,cadena2);
		fprintf(miarchivo,"%s%s\n", cadena,cadena2);
		//srand(time(NULL));
		//log = rand()%1000;
		//printf("Numero aleatorio de la longitud es : %d\n", log);


	/*	temp = n;

  		 while( temp != 0 )
   		{
      	reverse = reverse * 10;
      	reverse = reverse + temp%10;
      	temp = temp/10;
   		}

   		if ( n == reverse )
     	 printf("\n%d is a palindrome number.\n", n);
  	 	else
      	printf("%d is not a palindrome number.\n", n);
	*/
		}

  /* printf("Enter a number to check if it is a palindrome or not\n\n");
   scanf("%d",&n);

   temp = n;

   while( temp != 0 )
   {
      reverse = reverse * 10;
      reverse = reverse + temp%10;
      temp = temp/10;
   }

   if ( n == reverse )
      printf("\n%d is a palindrome number.\n", n);
   else
      printf("%d is not a palindrome number.\n", n);*/

   return 0;
    fclose(miarchivo);
   getch();
}