#include <stdio.h>
#define MAXSIZE 5

struct pila{
	int stk[MAXSIZE];
	int top;
};
typedef struct pila PILA;
PILA s;

void push(void);
int pop(void);
void muestra(void);

int main(){
	int eleccion;
	int opcion = 1;
	s.top = -1;

	printf("Operacion Cola \n");
	while(opcion){
		printf("-------------------------\n");
		printf("1 -----------------> Push\n");
		printf("2 -----------------> Pop\n");
		printf("3 -----------------> Muestra\n");
		printf("4 -----------------> Salir\n");
		printf("-------------------------\n");
		printf("Ingresa tu opcion\n");
		scanf("%d", &eleccion);
		switch(eleccion){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				muestra();
				break;
			case 4:
			return 0;
		}
		fflush (stdin);
		printf("Deseas continuar(teclea 0 = no o 1 = si)?\n");
		scanf("%d",&opcion);
	}
	return 0;
}

//--------------------------Funciones

void push(){
	int num;
	if(s.top == (MAXSIZE - 1)){
		printf("La pila esta llena\n");
		return;
	}
	else{
		printf("Ingresa el elemento que se añadira a la pila\n");
		scanf("%d", &num);
		s.top+=1;
		s.stk[s.top] = num;
	}
	return;
}

int pop(){
	int num;
	if(s.top == -1){
		printf("La pila esta vacia\n");
		return (s.top);
	}
	else{
		num = s.stk[s.top];
		printf("El elemento q se dejo la pila es %d\n", s.stk[s.top]);
		s.top-=1;
	}
	return (num);
}

void muestra(){
	int i;
	if(s.top == -1){
		printf("La pila esta vacia\n");
		return;
	}
	else{
		printf("El estado de la pila es \n");
		for(i=s.top;i>=0;i--){
			printf("%d\n", s.stk[i]);
		}
	}
	printf("\n");
}