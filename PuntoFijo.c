/*
* FIXED-POINT ALGORITHM 2.2
*
* To find a solution to p = g(p) given an
* initial approximation p0
*
* INPUT:  initial approximation; tolerance TOL;
*         maximum number of iterations NO.
*
* OUTPUT: approximate solution p or
*         a message that the method fails.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double TOL,P0,P;
   int I,NO,FLAG,OK;
   char AA;
   FILE *OUP[1];

   void INPUT(int *, double *, double *, int *);
   void OUTPUT(FILE **, int *);
   double absval(double);
   double G(double );

   INPUT(&OK, &P0, &TOL, &NO);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */
      I = 1; OK = true;
      /* STEP 2 */
      while((I<=NO) && OK) {
         /* STEP 3 */
         /* compute P(I) */
         P = G(P0);
         if (FLAG == 2) fprintf(*OUP, "%3d   %15.8e\n", I, P);
         /* STEP 4 */
         if (absval(P-P0) < TOL) {
            /* procedure completed successfully */
            fprintf(*OUP, "\nSolucion aproximada P = %12.8f\n", P);
            fprintf(*OUP, "Numero de iteraciones = %3d", I);
            fprintf(*OUP, "    Tolerancia = %14.8e\n",TOL);
            OK = false;
         }
         else {
            /* STEP 5 */
            I++;
            /* STEP 6 */
            /* update P0 */
            P0 = P;
         }
      }
      if (OK) {
         /* STEP 7 */
         /* procedure completed unsuccessfully */
         fprintf(*OUP, "\nNumero de iteraciones %3d", NO);
         fprintf(*OUP, " aproximacion dada %12.8f\n", P);
         fprintf(*OUP, "fuera de la tolerancia %14.8e\n",TOL);
      }
      fclose(*OUP);
   }
}
/* Change function G for a new problem */
double G(double X)
{
   double g;

   g = sqrt(10.0 / (4.0 + X));
   return g;
}

void INPUT(int *OK, double *P0, double *TOL, int *NO)
{
   char AA;

   printf("Metodo de punto fijo.\n");
/*   printf("Has the function G been created in the program immediately preceding\n");*/
   printf("¿Esta la funcion definida en el programa?\n");
   printf("Ingrese S Ã³ N \n");
   scanf("%c",&AA);
   if ((AA == 'S') || (AA == 's')) {
      *OK = false;
      printf("Ingrese la aproximacion inicial\n");
      scanf("%lf",P0);
      while(!(*OK)) {
         printf("Ingrese la torelancia\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0) printf("La tolerancia debe ser positiva\n");
         else *OK = true;
      }
      *OK = false;
      while (!(*OK)) {
         printf("Ingrese el numero maximo de iteraciones (entero positivo)\n");
         scanf("%d", NO);
         if (*NO <= 0) printf("Debe ser un entero positivo\n");
         else *OK = true;
      }
   }
   else {
      printf("Defina la funcion y ejecute el programa de nuevo\n");
      *OK = false;
   }
}

void OUTPUT(FILE **OUP, int *FLAG)
{
   char NAME[30];

   printf("Seleccion el destino de los calculos\n");
   printf("1. Pantalla\n");
   printf("2. Archivo de texto\n");
   printf("Ingrese 1 o 2\n");
   scanf("%d", FLAG);
   if (*FLAG == 2) {
      printf("Ingrese el nombre del archivo de la forma - nombre.ext\n");
      printf("Por ejemplo:   puntofijo.txt\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   printf("Seleccione la cantidad a generar\n");
   printf("1. Solo la respuesta\n");
   printf("2. Todas las aproximaciones intermedias\n");
   printf("Ingrese 1 o 2\n");
   scanf("%d", FLAG);
   fprintf(*OUP, "Metodo de punto fijo\n");
   if (*FLAG == 2) fprintf(*OUP, "  I                 P\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
