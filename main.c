/*
 * Grupo HMR
 * Integrantes
 * Hugo Sousa Nasciutti - 11621BSI260
 * Matheus Santiago Neto - 11621BSI252
 * Rodrigo Souza Rezende - 
*/

#include <stdio.h>
#include <stdlib.h> // atoi

int main()
{
    int i;
    char str[10];

    printf ("Digite um numero: ");
    fgets(str, 10, stdin);
    i = atoi (str);
    printf ("O valor que voce digitou eh %d \n",i);
    return 0;
}
