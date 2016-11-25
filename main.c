/*
 * Grupo HMR

 * Integrantes:

 * Hugo Sousa Nasciutti - 11621BSI260
 * Matheus Santiago Neto - 11621BSI252
 * Rodrigo Souza Rezende - 11621BSI245
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int vlr(char);

void predig(char c1,char c2);
void posdig(char c,int n);

char n_romano[1000];
int i=0;



int main(){
    setlocale(LC_ALL, "");
    char romano[1000];
    long int numero =0;
    int j;
    long int number;
    int count_limite=0;

    printf("Digite um valor para converter: ");
    scanf("%s", &romano);

    /* Transformando todas as letras em maiúsculas para comparação.*/
    for(j=0; j<strlen(romano); j++){
        if(romano[j] >= 97 && romano[j]<=122){
            romano[j] -= 32;
    	}
    	if(romano[j] == 'm' || romano[j] == 'M'){
    		count_limite++;
    	}
    	if(count_limite >= 4){
    		printf("Número romano maior que 3999, inserir um número inteiro entre 1 e 3999.\n");
    		return 1;
    	}

    }

    if(atoi(romano) == 0){
        while(romano[i]){
            if(vlr(romano[i]) < 0){
                printf("Número inválido, inserir um número inteiro entre 1 e 3999.\n");
                return 0;
            }

            if((strlen(romano) -i) > 2){
	            if(vlr(romano[i]) < vlr(romano[i+2])){// Verifica a posição correta dos números romanos.
	                printf("Número inválido, a ordem dos romanos está errada.\n");
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

        printf("O número convertido é: %ld",numero);

    }else{

	    numero = atoi(romano);

	    if(numero <= 0 || numero > 3999){
            printf("Número inválido, inserir um número inteiro entre 1 e 3999.\n");
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

	    printf("O número em romano é: ");

	    for(j=0;j<i;j++)
	        printf("%c",n_romano[j]);
    }


    	printf("\n");
    return 0;
}

/*
    Comentário da função
*/
void predig(char c1,char c2){
    n_romano[i++] = c1;
    n_romano[i++] = c2;
}

/*
    Comentário da função
*/
void posdig(char c,int n){
    int j;
    for(j=0;j<n;j++)
    	n_romano[i++] = c;

}

/*
    Função para atribuição de cada posição da string (romano), para com seu respectivo valor em inteiro
*/
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
