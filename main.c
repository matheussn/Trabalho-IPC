#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int vlr(char);

void predig(char c1,char c2);
void posdig(char c,int n);

char n_romano[1000];
int i=0, j=0;

int main(){	
	setlocale(LC_ALL, "");
    char romano[1000];
    long int numero =0;
    int j;
    
    printf("Digite um valor para converter: ");
    scanf("%s",romano);
    
    if(atoi(romano) == 0){

	    while(romano[i]){

	         if(vlr(romano[i]) < 0){
	             printf("Número inválido, inserir um número > 0 e < 4000.\n");
	             return 0;
	         }

	         if((strlen(romano) -i) > 2){
	             if(vlr(romano[i]) < vlr(romano[i+2])){
	                 printf("Número inválido, inserir um número > 0 e < 4000.\n");
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

    	printf("O número convertido é: %ld\n",numero);

    }else{

	    numero = atoi(romano);

	    if(numero <= 0 || numero > 3999){
	         printf("Número inválido, inserir um número > 0 e < 3999.\n");
	         return 0;
	    }

	    while(numero != 0){

	        if(numero >= 1000){
	            posdig('M',numero/1000);
	            numero = numero - (numero/1000) * 1000;
	        }
	        else if(numero >=500){
	            if(numero < (500 + 4 * 100)){
	                posdig('D',numero/500);
	                numero = numero - (numero/500) * 500;
	            }
	            else{
	                predig('C','M');
	                numero = numero - (1000-100);
	            }
	        }
	        else if(numero >=100){
	            if(numero < (100 + 3 * 100)){
	                posdig('C',numero/100);
	                numero = numero - (numero/100) * 100;
	            }
	            else{
	                predig('L','D');
	                numero = numero - (500-100);
	            }
	        }
	        else if(numero >=50){
	            if(numero < (50 + 4 * 10)){
	                posdig('L',numero/50);
	                numero = numero - (numero/50) * 50;
	            }
	            else{
	                predig('X','C');
	                numero = numero - (100-10);
	            }
	        }
	        else if(numero >=10){
	            if(numero < (10 + 3 * 10)){
	                posdig('X',numero/10);
	                numero = numero - (numero/10) * 10;
	            }
	            else{
	                predig('X','L');
	                numero = numero - (50-10);
	            }
	        }
	        else if(numero >=5){
	            if(numero < (5 + 4 * 1)){
	                posdig('V',numero/5);
	                numero = numero - (numero/5) * 5;
	            }
	            else{
	                predig('I','X');
	                numero = numero - (10-1);
	            }
	        }
	        else if(numero >=1){
	            if(numero < 4){
	                posdig('I',numero/1);
	               numero = numero - (numero/1) * 1;
	            }
	            else{
	                predig('I','V');
	                numero = numero - (5-1);
	            }
	        }
	    }

	    printf("Em romano é: ");

	    for(j=0;j<i;j++)
	        printf("%c",n_romano[j]);
    }
    	printf("\n");

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
