#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>  //permite a utiliza��o de acentos e marcas gr�ficas
#include <stdbool.h> //permite a utiliza��o do tipo boolean

#define true 1    //define o valor 1 como "true"
#define false 0   //define o valor 0 como "false"

int main(){

    setlocale(LC_ALL, "Portuguese"); //Permite a utiliza��o de acentos e marca��es gr�ficas
    int opcao=0, numero, numeroValidacao,i=0, quociente[80], resto[80], auxiliar = 0, resultadoDecimal = 0;

    bool ehValido = true;

    while(opcao != 5){

        //Inicializa e redefine os valores ap�s um uso do programa
        system("CLS");
        for(i=0; i < 80; i++){
            quociente[i] = 0;
            resto[i] = 0;
        }
        i = 0;
        auxiliar = 0;
        numero = 0;

        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para bin�rio");
        printf("\n2 - Bin�rio para decimal");
        printf("\n3 - Decimal para octal");
        printf("\n4 - Octal para decimal");
        printf("\n5 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        system("CLS");

        switch(opcao){
            case 1:
                printf("-----Decimal para bin�rio-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);
                printf("\n %d em bin�rios: ",numero);
                //Algoritmo para o c�lculo
                while (numero != 1){              // enquanto o quociente for diferente de 1, o programa continuar� calculando
                    quociente[i]= numero / 2;    //array que calcula e armazena os quocientes
                    resto[i] = numero % 2;      //array que calcula e armazena os restos
                    numero=quociente[i];       //atribuindo novo valor para q[i], pra que seja poss�vel a continua��o do c�lculo
                    i++;
                }
                //Imprimindo o �ltimo quociente mais os restos de "tr�s pra frente" (n�mero em bin�rios)
                auxiliar = i;
                if(quociente[auxiliar] == 0){
                    i--;
                }


                while (i>=0){
                    if (quociente[i] == 1){
                      printf("1%d",resto[i]);
                    }else {
                        printf("%d",resto[i]);
                    }
                    i--;
                }
                printf("\n");
                system("PAUSE");

            break;

            case 2:
                printf("-----Bin�rio para decimal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);
                numeroValidacao = numero;

                while(numeroValidacao != 0 || ehValido == true){
                    if(numeroValidacao % 10 != 0 && numeroValidacao % 10 != 1){
                        ehValido = false;
                    } else{
                        ehValido = true;
                    }
                    numeroValidacao /= 10;
                }

                if(ehValido == true){
                    while(numero!=0){
                        resultadoDecimal = resultadoDecimal + pow(2,i) * (numero % 10);
                        numero /= 10;
                        i++;
                    }
                    printf("\n %d em decimal: ", resultadoDecimal);
                } else {
                    printf("\nO n�mero inserido � inv�lido! Tente novamente!!");
                }

                system("PAUSE");
            break;

            case 3:
                printf("-----Decimal para octal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);
                printf("\n %d em octal: ",numero);
                //Algoritmo para o c�lculo
                while (numero != 1){               // enquanto o quociente for diferente de 1, o programa continuar� calculando
                    quociente[i]= numero / 8;     //array que calcula e armazena os quocientes
                    resto[i] = numero % 8;       //array que calcula e armazena os restos
                    numero=quociente[i];        //atribuindo novo valor para q[i], pra que seja poss�vel a continua��o do c�lculo
                    i++;
                }

                //Imprimindo o �ltimo quociente mais os restos de "tr�s pra frente" (n�mero em octal)
                auxiliar = i;
                if(quociente[auxiliar] == 0){
                    i--;
                }

                while (i>=0){
                    if (quociente[i] == 1){
                      printf("1%d",resto[i]);
                     }else {
                        printf("%d",resto[i]);
                    }
                    i--;
                }
                printf("\n");
                system("PAUSE");
            break;

            case 4:
                printf("-----Octal para decimal-----");
                //TODO
                system("PAUSE");
            break;

            case 5:
                printf("O programa ser� encerrado.\n");
                system("PAUSE");
            break;

            default:
                printf("Op��o inv�lida, tente novamente.\n");
                system("PAUSE");
            break;

        }
    }

    return 0;
}
