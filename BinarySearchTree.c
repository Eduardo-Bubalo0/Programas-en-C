#include <stdio.h>
#include <stdlib.h>
 typedef struct BST
 {
 	int dato;
 	struct BST *HijoIzq, *HijoDer;
 } nodo; 

 void insertar(nodo*, nodo*);
 void inorder(nodo*);
 void preorder(nodo *);
 void postorder(nodo *);
 nodo *buscar(nodo *, int, nodo **);

 int main(){
 	int select;
 	char ans = 'N';
 	int key;
 	nodo *new_nodo, *root, *tmp, *padre;
 	nodo *get_nodo();
 	root=NULL;

 	printf("Programa para un Arbol de Busqueda Binaria\n");
 	do{
 		printf("1.Crear\n");
 		printf("2.Buscar\n");
 		printf("3.Transicion recursiva\n");
 		printf("4.Salir\n");
 		printf("Ingresa tu opcion: \n");
 		scanf("%d", &select);

 		switch(select){
 			case 1:
 			do{
 				new_nodo = get_nodo();
 				printf("Ingresa el elemento\n");
 				scanf("%d", &new_nodo -> dato);

 				if(root==NULL){//El arbol no esta creado
 					root = new_nodo;
 				}
 				else
 					insertar(root, new_nodo);

 				printf("Desea añadir mas elementos? (y/n)\n");
 				ans = getchar();

 			} while (ans == 'y');
 			break;

 			case 2:
 				printf("Ingresa el elemento que quieres buscar\n");
 				scanf("%d", &key);

 				tmp=buscar(root, key, &padre);
 				printf("Padre del nodo %d es %d\n", tmp->dato, padre->dato);
 				break;

 			case 3:
 				if(root==NULL)
 					printf("El arbol no esta creado\n");
 				else{
 					printf("inorder: \n");
 					inorder(root);
 					printf("preorder: \n");
 					preorder(root);
 					printf("postorder: \n");
 					postorder(root);
 				}
 				break;
 		}
 	} while (select != 4);
 	return 0;
 }

 //Get new_nodo
 nodo *get_nodo(){
 	nodo *temp;
 	temp = (nodo *) malloc(sizeof(nodo));
 	temp->HijoIzq = NULL;
 	temp->HijoDer = NULL;
 	return temp;
 }

 //Funcion para crear el arbol de busqueda binaria
 void insertar(nodo *root, nodo *new_nodo){
 	if(new_nodo->dato < root->dato){
 		if(root->HijoIzq == NULL)
 			root->HijoIzq = new_nodo;
 		else
 			insertar(root->HijoIzq, new_nodo);
 	}
 	if(new_nodo->dato > root->dato){
 		if(root->HijoDer == NULL)
 			root->HijoDer = new_nodo;
 		else
 			insertar(root->HijoDer, new_nodo);
 	}
 }

 //Fubcion de busqueda en el BST
nodo *buscar(nodo *root, int key, nodo **padre){
	nodo *temp;
	temp = root;
	while(temp != NULL){
		if(temp->dato == key){
			printf("El elemento %d existe\n", temp->dato);
			return temp;
		}
		*padre = temp;

		if(temp->dato > key)
			temp = temp->HijoIzq;
		else
			temp = temp->HijoDer;
	}
	return NULL;
}

//Funcion inorder
void inorder(nodo *temp){
	if(temp != NULL){
		inorder(temp->HijoIzq);
		printf("%d ", temp->dato);
		inorder(temp->HijoDer);
	}
}

//Funcion Preorder
void preorder(nodo *temp){
	if(temp != NULL){
		printf("%d ", temp->dato);
		preorder(temp->HijoIzq);
		preorder(temp->HijoDer);
	}
}

//Funcion Postorder
void postorder(nodo *temp){
	if(temp != NULL){
		postorder(temp->HijoIzq);
		postorder(temp->HijoDer);
		printf("%d ", temp->dato);
	}
}