#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10005 //Numero maximo de vertices
#define Nodo pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas

struct C_Prio {
    bool operator() ( const Nodo &a , const Nodo &b ) {
        return a.second > b.second;
    }
};
vector< Nodo > ady[ MAX ]; //lista de adyacencia
int distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool visitado[ MAX ];      //para vértices visitados
priority_queue< Nodo , vector<Nodo> , C_Prio > Q;
int V;                     //numero de vertices
int previo[ MAX ];         //Impreson de caminos

//función de inicialización
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //"relajamos" el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //tambien se actualiza el vertice previo
        Q.push( Nodo( adyacente , distancia[ adyacente ] ) ); //agregamos el vertice a la cola de prioridad
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void Imprime( int destino ){
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        Imprime( previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void DIJKSTRA( int inicial ){
    init(); //inicializamos nuestros arreglos
    Q.push( Nodo( inicial , 0 ) ); //Se inserta el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0;      //Inicializamos la distancia del inicial como 0
    int actual , adyacente , peso;
    while( !Q.empty() ){
        actual = Q.top().first;            //Se obtiene de la cola el nodo con menor peso, al principio será el inicial
        Q.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //se revisan sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //ID del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }


    printf( "Distancias mas cortas iniciando en el vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }

    puts("\n**************Impresion de camino mas corto**************");
    int z;
	do{
	printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    Imprime( destino );
    printf("\n");
	printf("desea calcular otro camino? \n1.- si \n2.-  no ");
	scanf("%d",&z);
	}while(z=!2);

}


int main(){
    int E , origen, destino , peso , inicial;
    printf("Ingrese cuantos vertices y cuantas aristas contendra el grafo\n");
    scanf("%d %d" , &V , &E );
    while( E-- ){
        printf("Ingresa el nodo origen, el nodo final y el peso de la arista\n");
        scanf("%d %d %d" , &origen , &destino , &peso );
        ady[ origen ].push_back( Nodo( destino , peso ) ); //consideremos grafo dirigido
        ady[ destino ].push_back( Nodo( origen , peso ) ); //grafo no dirigido
    }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    DIJKSTRA( inicial );
    return 0;
}