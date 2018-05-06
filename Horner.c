// Decia Mendez Jorge Ignacio    3cm4  2014630555
//Olvera Aguila Leonardo Daniel 3cm4  2014630623
//JOSÉ EDUARDO MONROY GARCÍA	3cm4   2015630311

#include<stdio.h>
#include<stdlib.h>

float evaluar(float *, int, int);

int main()
{
    int numgrado, numevalua, i;
    float coef[10],p;
    char grado[10];
    char evalua[10];
    char numcoef[10];

    FILE * archivo = fopen("ecuacion.txt","r");
    if(archivo == NULL)
    {
        perror("Error de apertura del archivo");
        return 1;
    }
    fscanf(archivo,"%s%d", &grado, &numgrado);

    fscanf(archivo,"%s%d", &evalua, &numevalua);

    fscanf(archivo,"%s",&numcoef);

    for(i=numgrado; i>=1; i--)
    {
        fscanf(archivo,"%f",&coef[i]);
    }
    printf("%s %d\n", grado, numgrado);

    printf("%s %d\n", evalua, numevalua);

    printf("%s\n", numcoef);
    for(i=numgrado; i>=1; i--)
    {
        printf("%.2f\n", coef[i]);
    }

    /*REGLA DE HORNER*/
    p = evaluar(coef, numgrado, numevalua);
    printf("\n\np(%d) = %.2f\n\n", numevalua, p);

    fclose(archivo);
    printf("El archivo se ha leido correctamente ..\n");
}

float evaluar(float *coef, int numgrado, int numevalua)
{
	int i;
	float p;

	/*horner*/
	for(p=coef[numgrado], i=numgrado; i>0; i--)
		p = p*numevalua + coef[i-1];
	return p;
}