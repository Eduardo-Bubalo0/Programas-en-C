#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int width = 80, anio= 2017;
int cols, lead, gap;

const char *DiasSemana[] = {"Do", "Lu", "Ma", "Mi", "Ju", "Vi", "Sa"};
struct meses {
	const char *nombre;
	int dias, start_DiaSem, at;
}meses[12] = {
	{"Enero", 31,0,0},
	{"Febrero", 28,0,0},
	{"Marzo", 31,0,0},
	{"Abril", 30,0,0},
	{"Mayo", 31,0,0},
	{"Junio", 30,0,0},
	{"Julio", 31,0,0},
	{"Agosto", 31,0,0},
	{"Septiembre", 30,0,0},
	{"Octubre", 31,0,0},
	{"Noviembre", 30,0,0},
	{"Diciembre", 31,0,0}
};

void espacio(int n) {
	while (n-- >0) putchar(' ');
}

void inicia_meses(){
	int i;
	if((!(anio % 4) && (anio % 100)) || !(anio % 400))
		meses[1].dias = 29;

	anio--;
	meses[0].start_DiaSem = (anio * 365 + anio/4 - anio/100 + anio/400 + 1) %7;

	for(i=1; i<12; i++)
		meses[i].start_DiaSem = (meses[i-1].start_DiaSem + meses[i-1].dias) % 7;

	cols=(width+2)/22;
	while(12%cols)cols--;
	gap = cols-1 ? (width - 20 * cols) / (cols - 1) : 0;
	if(gap>4)gap=4;
	lead=(width-(20+gap)*cols+gap+1)/2;
	anio++;
}

void imprime_fila(int fila){
	int c, i, from= fila *cols, to = from + cols;
	espacio(lead);
	for(c=from; c<to;c++){
		i=strlen(meses[c].nombre);
		espacio((20-i)/2);
		printf("%s", meses[c].nombre);
		espacio(20-i-(20-i)/2+((c==to-1)?0:gap));
	}
	putchar('\n');

	espacio(lead);
	for(c=from;c<to;c++){
		for(i=0;i<7;i++)
			printf("%s%s", DiasSemana[i], i==6 ? "":" ");
		if(c<to-1)espacio(gap);
		else putchar('\n');
	}

	while(1){
		for(c=from;c<to;c++)
			if(meses[c].at <meses[c].dias) break;
		if(c==to)break;

		espacio(lead);
		for(c=from;c<to;c++){
			for(i=0;i<meses[c].start_DiaSem;i++)espacio(3);
				while(i++<7 && meses[c].at <meses[c].dias){
					printf("%2d", ++meses[c].at);
					if(i<7 || c<to-1) putchar(' ');
				}
				while(i++ <= 7 && c<to-1)espacio(3);
				if(c<to-1) espacio(gap-1);
				meses[c].start_DiaSem=0;
		}
		putchar('\n');
	}
	putchar('\n');
}

void imprime_anio(){
	int fila;
	char buf[32];
	sprintf(buf, "%d", anio);
	espacio((width - strlen(buf))/2);
	printf("%s\n\n", buf);
	for(fila=0; fila*cols <12;fila++)
		imprime_fila(fila);
}

int main(int c, char **v){
	int i, anio_set=0;
	for(i=1;i<c;i++){
		if(!strcmp(v[i],"w")){
			if(++i==c || (width = atoi(v[i]))< 20)
				goto bail;
		}
		else if(!anio_set){
			if(!sscanf(v[i], "%d", &anio) || anio<=0)
				anio=2016;
			anio_set=1;
		}
		else
			goto bail;
	}
	inicia_meses();
	imprime_anio();
	return 0;

	bail: fprintf(stderr, "bad args\nUsage: %s anio [-w width (>=20)]\n", v[0]);
	exit(1);
}