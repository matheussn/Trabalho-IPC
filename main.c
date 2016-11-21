#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vlr(char);

void predig(char c1,char c2);
void posdig(char c,int n);

char n_romano[1000];
int i=0;

int main(){

    char romano[1000];
    long int numero =0;
    int j;
    long int number;

    printf("Digite um valor para converter: ");
    scanf("%s",romano);

    if(atoi(romano) == 0){

    while(romano[i]){

         if(vlr(romano[i]) < 0){
             printf("Numero invalido : %c",romano[i]);
             return 0;
         }

         if((strlen(romano) -i) > 2){
             if(vlr(romano[i]) < vlr(romano[i+2])){
                 printf("Numero invalido");
                 return 0;
             }
         }

         if(vlr(romano[i]) >= vlr(romano[i+1]))
             numero = numero + vlr(romano[i]);
         else{
             numero = numero + (vlr(romano[i+1]) - vlr(romano[i]));
             i++;
         }
         i++;
    }

    printf("O numero convertido e: %ld\n",numero);

    }else{

    number = atoi(romano);

    if(number <= 0){
         printf("Numero invalido\n");
         return 0;
    }

    while(number != 0){

          if(number >= 1000){
             posdig('M',number/1000);
             number = number - (number/1000) * 1000;
         }
         else if(number >=500){
             if(number < (500 + 4 * 100)){
                 posdig('D',number/500);
                 number = number - (number/500) * 500;
             }
             else{
                 predig('C','M');
                 number = number - (1000-100);
             }
         }
         else if(number >=100){
             if(number < (100 + 3 * 100)){
                 posdig('C',number/100);
                 number = number - (number/100) * 100;
             }
             else{
                 predig('L','D');
                 number = number - (500-100);
             }
         }
         else if(number >=50){
             if(number < (50 + 4 * 10)){
                 posdig('L',number/50);
                 number = number - (number/50) * 50;
             }
             else{
                 predig('X','C');
                 number = number - (100-10);
             }
         }
         else if(number >=10){
             if(number < (10 + 3 * 10)){
                 posdig('X',number/10);
                 number = number - (number/10) * 10;
             }
             else{
                 predig('X','L');
                 number = number - (50-10);
             }
         }
         else if(number >=5){
             if(number < (5 + 4 * 1)){
                 posdig('V',number/5);
                 number = number - (number/5) * 5;
             }
             else{
                 predig('I','X');
                 number = number - (10-1);
             }
         }
         else if(number >=1){
             if(number < 4){
                 posdig('I',number/1);
                 number = number - (number/1) * 1;
             }
             else{
                 predig('I','V');
                 number = number - (5-1);
             }
         }
    }

    printf("Em romano e: ");
    for(j=0;j<i;j++)
         printf("%c\n",n_romano[j]);
    }

    return 0;

}

void predig(char c1,char c2){
    n_romano[i++] = c1;
    n_romano[i++] = c2;
}

void posdig(char c,int n){
    int j;
    for(j=0;j<n;j++)
         n_romano[i++] = c;

}

int vlr(char c){

    int n_inteiro=0;

    switch(c){
         case 'I': n_inteiro = 1; break;
         case 'V': n_inteiro = 5; break;
         case 'X': n_inteiro = 10; break;
         case 'L': n_inteiro = 50; break;
         case 'C': n_inteiro = 100; break;
         case 'D': n_inteiro = 500; break;
         case 'M': n_inteiro = 1000; break;
         case '\0': n_inteiro = 0; break;
         default: n_inteiro = -1;
    }

    return n_inteiro;
}
