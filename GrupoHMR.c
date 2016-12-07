/*
 * Grupo HMR

 * Integrantes:

 * Hugo Sousa Nasciutti - 11621BSI260
 * Matheus Santiago Neto - 11621BSI252
 * Rodrigo Souza Rezende - 11621BSI245
 *
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

int i=0, j=0, k=0; //i global pois é utilizada para situar a posição da leitura

int main(){
    setlocale(LC_ALL, "");
    char romano[1000];
    long int numero =0;
    printf("Insira somente Algarismos Arábicos ou Números Romanos.\n");
    printf("A leitura do tipo da entrada será automática.\n");
    printf("Digite um valor para converter: ");
    scanf("%s", romano); //Nome da variável char é romano mas a entrada pode ser dos 2 tipos.

    /* Transformando todas as letras em maiúsculas para comparação.*/
    for(j=0; j<strlen(romano); j++){
        if(romano[j] >= 97 && romano[j]<=122){
            romano[j] -= 32;
    	}    		
    }

	//Corrigindo formato da entrada da string, evitando mesclagem de formatos de números.
	if(romano[0] > 48 && romano[0] <= 57){ //Intervalo de 1 a 9, conversão tabela ASCII, >0 && <=9;
		for(j=1; j<strlen(romano); j++){
			if(romano[j] < 48 || romano[j] > 57){
				printf("Erro 1: Formato de entrada inválido, insira apenas um único formato para conversão automática, execução do programa encerrado.\n");
				return 1;
			}
		}
	}

	//Corrigindo formato da entrada da string, evitando mesclagem de formatos de números.
	if(vlr(romano[0]) != -1 && vlr(romano[0] != 0)){ //Número Romano identificado, verifica se é válido.
		for(j=1; j<strlen(romano); j++){
			if(vlr(romano[j]) == -1 || vlr(romano[j]) == 0){ //Se o resto da entrada não for número romano válido, encerra o programa.
				printf("Erro 2: Formato de entrada inválido, insira apenas um único formato para conversão automática, execução do programa encerrado.\n");
				return 1;
			}
		}
	}

/*Corrigindo entrada de valores para apenas a quantidade correta de romanos*/
	int count_I=0;
    int count_V=0;
    int count_X=0;
    int count_L=0;
    int count_C=0;
    int count_D=0;
    int count_M=0;

    for(k=0; k<strlen(romano);k++){
    	if(romano[k] == 'I')
    		count_I++;
    	else if(romano[k] == 'V')
    		count_V++;
    	else if(romano[k] == 'X')
    		count_X++;
    	else if(romano[k] == 'L')
    		count_L++;
    	else if(romano[k] == 'C')
    		count_C++;
    	else if(romano[k] == 'D')
    		count_D++;
    	else if(romano[k] == 'M')
    		count_M++;
    }

	if(count_I++ > 3){
		printf("Erro 3: Formato inválido, é permitido até no máximo III, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_V > 1){
		printf("Erro 4: Formato inválido, é permitido até no máximo um único V, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_X > 3){
		printf("Erro 5: Formato inválido, é permitido até no máximo XXX, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_L > 1){
		printf("Erro 6: Formato inválido, é permitido até no máximo um único L, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_C > 3){
		printf("Erro 7: Formato inválido, é permitido até no máximo CCC, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_D > 1){
		printf("Erro 8: Formato inválido, é permitido até no máximo um único D, execução do programa encerrada.\n");
		return 1;
	}
	else if(count_M > 3){
		printf("Erro 9: Formato inválido, é permitido até no máximo MMM vide limitação do programa à 3999, execução do programa encerrada.\n");
		return 1;
	}



    if(atoi(romano) == 0){
        while(romano[i]){
            if(vlr(romano[i]) < 0){ //Verifica se o valor inserido é inválido de acordo com o que retorna na função vlr(), se -1 é inválido.        	
                printf("Entrada de '%c' é inválida, inserir apenas Algarismos Arábicos ou Números Romanos, programa encerrado.\n", romano[i]);
                return 1;
            }
            if((strlen(romano) -i) > 2){
	            if(vlr(romano[i]) < vlr(romano[i+2])){// Verifica a posição correta dos números romanos.
	                printf("Número inválido, a ordem dos romanos está errada, execução do programa encerrada.\n");
	                return 1;
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
	        
        printf("O número romano em arábico é: %ld",numero);

    }else{

	    numero = atoi(romano);

	    if(numero <= 0 || numero > 3999){
            printf("Número inválido, inserir um número inteiro entre 1 e 3999.\n");
	        return 0;
	    }

	    while(numero != 0){

	        if(numero >= 1000){
	            posdig('M',numero/1000); 
	            numero = numero - (numero/1000) * 1000; //Garantindo a subtração apenas do número que está na casa do milhar. Se a entrada for 2500, subtrair apenas 2000 e assim por diante no código abaixo.
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
	                predig('C','D');
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

	    
	    printf("O número arábico em romano é: ");

	    for(j=0;j<i;j++)
	        printf("%c",n_romano[j]);
    }


    	printf("\n");
    return 0;
}


/*
    void posdig(){
    	Insere na variável char n_romano o valor correspondente em romano do valor lido e anda 
    	uma posição com i++, não há IV ou XC, apenas um único valor representante.	
    }
*/
void posdig(char c,int n){
    for(j=0;j<n;j++)
    	n_romano[i++] = c;
}

/*
	void predrig(){

    Adiciona na variável n_romano[i] a letra que representa o número inserido pelo usuário.
    Na ordem correta, como no caso de representar o número 9, será representado como 'IX',
    e assim para os outros elementos de acordo com as regras que foram definadas nas condições acima
    que estão dentro do caso 'else' e assim que atribuido o valor c1 incrementar +1 em i para 
    adicionar o valor de c2 corretamente e também depois de atribuído c2 na variável, incrementar +1 em i
    para a análise das outras funções. ;
    Lembrando que n_romano é uma variável char global.

    }

*/

void predig(char c1,char c2){
    n_romano[i++] = c1; //i e n_romano Global.
    n_romano[i++] = c2; 
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
