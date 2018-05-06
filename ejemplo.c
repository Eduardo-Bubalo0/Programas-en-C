#include <stdio.h>
#include <math.h>

int main(){
    int a;
    int b;
    int sum, rest, mult,pot;
    float div;
    int opcion;
    do{
        printf("\n\n1. Multiplicacion \n");
        printf("2. Suma \n");
        printf("3. Division \n");
        printf("4. Resta \n");
        printf("5. Potencia \n");
        printf("6. Salir\n");
        printf("Ingresa la opcion que desee \t");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("Ingresa el primer numero\n");
                scanf("%d",&a);
                printf("Ingresa el segundo numero\n");
                scanf("%d",&b);
                mult = a * b;
                printf("La multiplicacion de %d y %d es: %d\n",a,b,mult);
                break;
            case 2:
                printf("Ingresa el primer numero\n");
                scanf("%d",&a);
                printf("Ingresa el segundo numero\n");
                scanf("%d",&b);
                sum = a + b;
                printf("La suma de %d y %d es: %d\n",a,b,sum);
                break;
            case 3:
                printf("Ingresa el primer numero\n");
                scanf("%d",&a);
                printf("Ingresa el segundo numero\n");
                scanf("%d",&b);
                div = a / b;
                printf("La division de %d y %d es: %f\n",a,b,div);
                break;
            case 4:
                printf("Ingresa el primer numero\n");
                scanf("%d",&a);
                printf("Ingresa el segundo numero\n");
                scanf("%d",&b);
                rest = a - b;
                printf("La resta de %d y %d es: %d\n",a,b,rest);
                break;
            case 5:
                printf("Ingresa el primer numero\n");
                scanf("%d",&a);
                printf("Ingresa el segundo numero\n");
                scanf("%d",&b);
                pot = pow(a,b);
                printf("La potencia de %d a la %d es: %d\n",a,b,pot);
                break;
        }
    }while(opcion != 6);
    return 0;
}
