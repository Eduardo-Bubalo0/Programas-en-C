/*  Decia Méndez Jorge Ignacio
    Monroy Garcia Jose Eduardo
    Olvera Aguila Leonardo Daniel
    21/09/16
    lab4 seccion1 3cm4
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int longitud(string &cadena1, string &cadena2)
{
    int len1 = cadena1.size();
    int len2 = cadena2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            cadena1 = '0' + cadena1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            cadena2 = '0' + cadena2;
    }
    return len1;
}


string bitcadena(string primero, string segundo )
{
    string result;
    int tam = longitud(primero, segundo);
    int acarreo = 0;
    for (int i = tam-1 ; i >= 0 ; i--)
    {
        int primerBit = primero.at(i) - '0';
        int segundoBit = segundo.at(i) - '0';
        int sum = (primerBit ^ segundoBit ^ acarreo)+'0';
        result = (char)sum + result;
        acarreo = (primerBit&segundoBit) | (segundoBit&acarreo) | (primerBit&acarreo);
    }
    if (acarreo)  result = '1' + result;
    return result;
}

int multiplicaBit(string a, string b)
{  return (a[0] - '0')*(b[0] - '0');  }

long int multiplica(string X, string Y)
{

    int n = longitud(X, Y);
    if (n == 0) return 0;
    if (n == 1) return multiplicaBit(X, Y);
    int fh = n/2;
    int sh = (n-fh);
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
    long int P1 = multiplica(Xl, Yl);
    long int P2 = multiplica(Xr, Yr);
    long int P3 = multiplica(bitcadena(Xl, Xr), bitcadena(Yl, Yr));
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}

int main()
{
    printf ("El resultado de los valores X y Y es : %ld\n", multiplica("1111111", "1111"));
}