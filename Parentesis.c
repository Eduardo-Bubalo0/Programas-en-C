#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define LIMIT 10000

FILE *fp;
char pila[LIMIT];
int topPila = 0;
char cadena[LIMIT];
char entrada[LIMIT];
char temp[LIMIT];

void push(char c)
{
	pila[topPila++] = c;
}

char pop()
{
	if (topPila != 0)
		return pila[--topPila];
	return 0;
}

int Empty()
{
	return topPila == 0;
}

void mostrar()
{
	printf("%s", cadena);
	fprintf(fp,"%s", cadena);
	int top = topPila;
	while (top)
	{
		printf("%c", pila[--top]);
	}
	printf("\n");
	fprintf(fp,"\n");
}

void Error(char c)
{
	printf("Error. La cadena no esta balanceada: %c\n", c);
	fprintf(fp,"Error. La cadena no esta balanceada: %c\n", c);
	getchar(); //getchar();
}

void reversa(char *rev)
{
	int len = strlen(rev);
	temp[len] = '\0';
	for (int i = 0; i < len; i++)
	{
		temp[i] = rev[len - i - 1];
	}
}

char B[2][5]; 
char R[2][5]; 

int main(int argc, char *argv[])
{	
	char x;
	int i;
	fp=fopen("parsing.txt","wt");
	printf("\t****Programa que balancea parentesis mediante Parsing Process*****\n\n");
	fprintf(fp,"\t\t****Programa que balancea parentesis mediante Parsing Process*****\n\n");
	
	printf("Desea Introducir los datos: Y / N \t\n");
	scanf("%c",&x);
	 if(x=='y'){
		
	printf("Introduce una cadena de parentesis: \t");	
	scanf("%s", entrada);		
			
	 }
	 else if(x=='n'){
	srand(time(NULL));
    for(i = 0; i < 1000; i++){
        printf("'%c'", 'a' + rand() % (('z' - 'A') + 1));		
	 }
	}
	
	
	// Load the rules
	strcpy(B[0], "(RB");
	strcpy(B[1], "\0");
	strcpy(R[0], ")");
	strcpy(R[1], "(RR");
	strcpy(cadena, "");

	// Initialize the stack	
	push('B');
	
	int imprime = 1;
	char *siguiente = entrada;

	while (!Empty())
	{
		if (imprime)
			mostrar();

		imprime = 1;
		char produccion = pop();

		if (produccion == 'B')
		{
			int encontrar = 0;
			for (int n = 0; n < 2; n++)
			{
				if (*siguiente == B[n][0])
				{
					reversa(B[n]);
					for (int i = 0; i < strlen(temp); i++)
					{
						push(temp[i]);
					}
					encontrar = 1;
				}
			}
			if (!encontrar){
				Error(*siguiente);
				return 0;
			}			
		}
		else if (produccion == 'R')
		{
			int encontrar = 0;
			for (int n = 0; n < 2; n++)
			{
				if (*siguiente == R[n][0])
				{
					reversa(R[n]);
					for (int i = 0; i < strlen(temp); i++)
					{
						push(temp[i]);
					}
					encontrar = 1;
				}
			}
			if (!encontrar){
				Error(*siguiente);
				return 0;
			}
		}
		else if (produccion == *siguiente)
		{
			char tmp[2];
			tmp[0] = produccion;
			tmp[1] = '\0';
			strcat(cadena, tmp);
			siguiente++;
			imprime = 0;
		}
		else
		{
			Error(*siguiente);
			return 0;
		}
	}

	printf("La cadena esta balanceada: ");
	fprintf(fp, "La cadena esta balanceada: ");
	mostrar();
	return 0;
	(fp);
}