#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include<string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream> 
#include <fstream>
int main(){
	int opt;
	std::string linea;
	//Pila p = empty();
	printf("\t**** Programa que ejecuta un automata de pila****\n");
	printf("\n1.-Introducir cadena manualmente\n");
	printf("2.-Pedir una cadena desde un archivo\n");
	printf("3.-Cadena Aleatoria\n");
	scanf(" %d",&opt);
	if(opt ==1){
		printf("Ingrese su cadena:\t ");
		std::cin >> linea;	
	}
	else if(opt ==2){
		std::cout << "Escriba el nombre del archivo:\t ";
		std::string filename;
		std::cin >> filename;
		std::ifstream file(filename.c_str());
		if(!file)
		{
			std::cout << "Error archivo invalido: " << filename;
					return 1;
		}
		getline(file, linea);
		std::cout << linea;
	}
	else if(opt==3){
		int i;
		srand(time(NULL));
    	for(i = 0; i < 10; i++){
        printf("%d", rand() % (('49' - '48') + 1));
		
		}
		
	}
	
	int balance =0;
	int card = linea.length();
	char *cadena = (char *)calloc(card,sizeof(char));
	strcpy(cadena,linea.c_str());
	printf("\n%S       Z0\n",cadena);
	for(int i =0; i<card;i++){
			printf("Paso siguiente....\n\n");
			Sleep(2000);
		for(int j =i;j<card;j++){
			if(j==i)
				printf("|");
			printf("%c",cadena[j]);
			if(j==i)
				printf("|");
		}
		printf("    ");
		if(cadena[i]=='0'){
			for(int p=0;p<i;p++)
				printf("X");
			printf("Z0\n");
			balance++;
		}else{
			for(int p=0;p<balance;p++)
				printf("X");
			printf("Z0\n");
			balance--;
		}
	}
	if(balance ==0){
		printf("\nZ0\n");
		std::cout << "\n\nLa cadena esta balanceada ";
	}
	else
		std::cout << "La cadena no esta balanceada ";
}