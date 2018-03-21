#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>  //permite a utilização de acentos e marcas gráficas
#include <stdbool.h> //permite a utilização do tipo boolean

#define true 1    //define o valor 1 como "true"
#define false 0   //define o valor 0 como "false"

int main(){

    setlocale(LC_ALL, "Portuguese"); //Permite a utilização de acentos e marcações gráficas
    int opcao=0, numero, numeroValidacao,i=0, quociente[80], resto[80], auxiliar = 0, resultadoDecimal = 0;

    bool ehValido = true;

    while(opcao != 5){

        //Inicializa e redefine os valores após um uso do programa
        system("CLS");
        for(i=0; i < 80; i++){
            quociente[i] = 0;
            resto[i] = 0;
        }
        i = 0;
        auxiliar = 0;
        numero = 0;

        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para binário");
        printf("\n2 - Binário para decimal");
        printf("\n3 - Decimal para octal");
        printf("\n4 - Octal para decimal");
        printf("\n5 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        system("CLS");

        switch(opcao){
            case 1:
                printf("-----Decimal para binário-----");
                printf("\nDigite o número: ");
                scanf("%d", &numero);
                printf("\n %d em binários: ",numero);
                //Algoritmo para o cálculo
                while (numero != 1){              // enquanto o quociente for diferente de 1, o programa continuará calculando
                    quociente[i]= numero / 2;    //array que calcula e armazena os quocientes
                    resto[i] = numero % 2;      //array que calcula e armazena os restos
                    numero=quociente[i];       //atribuindo novo valor para q[i], pra que seja possível a continuação do cálculo
                    i++;
                }
                //Imprimindo o último quociente mais os restos de "trás pra frente" (número em binários)
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
                printf("-----Binário para decimal-----");
                printf("\nDigite o número: ");
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
                    printf("\nO número inserido é inválido! Tente novamente!!");
                }

                system("PAUSE");
            break;

            case 3:
                printf("-----Decimal para octal-----");
                printf("\nDigite o número: ");
                scanf("%d", &numero);
                printf("\n %d em octal: ",numero);
                //Algoritmo para o cálculo
                while (numero != 1){               // enquanto o quociente for diferente de 1, o programa continuará calculando
                    quociente[i]= numero / 8;     //array que calcula e armazena os quocientes
                    resto[i] = numero % 8;       //array que calcula e armazena os restos
                    numero=quociente[i];        //atribuindo novo valor para q[i], pra que seja possível a continuação do cálculo
                    i++;
                }

                //Imprimindo o último quociente mais os restos de "trás pra frente" (número em octal)
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
                printf("O programa será encerrado.\n");
                system("PAUSE");
            break;

            default:
                printf("Opção inválida, tente novamente.\n");
                system("PAUSE");
            break;

        }
    }

    return 0;
}
