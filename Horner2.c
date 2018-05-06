/*MONROY GARCIA JOSE EDUARDO
  OLVERA AGUILA LEONARDO DANIEL*/

#include <stdio.h>


float evaluar(float *, int, float);

int main(void)
{
	int n, i;
	float x, coef[11], p;


	printf("\nGrado ");
	scanf("%d", &n);
	printf("\nevaluar  ");
	scanf("%f", &x);

	printf("\ncoeficientes\n");
	for(i=n; i >= 0; i--)
	{
		/*printf("\nCoeficientes\n");*/
		scanf("%f", &coef[i]);
	}
	p = evaluar(coef, n, x);

	printf("\n\np(%.2f) = %.2f\n\n", x, p);

	return 1;
}


float evaluar(float *coef, int n, float x)
{
	int i;
	float p;

	/*horner*/
	for(p=coef[n], i=n; i>0; i--)
		p = p*x + coef[i-1];
	return p;
}