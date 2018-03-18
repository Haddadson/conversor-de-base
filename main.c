#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Permite a utilização de acentos e marcações gráficas
    int opcao=0;


    while(opcao != 5){
        system("CLS");
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
                //TODO
                system("PAUSE");
            break;

            case 2:
                printf("-----Binário para decimal-----");
                //TODO
                system("PAUSE");
            break;

            case 3:
                printf("-----Decimal para octal-----");
                //TODO
                system("PAUSE");
            break;

            case 4:
                printf("-----Octal para decimal-----");
                //TODO
                system("PAUSE");
            break;

            case 5:
                printf("O programa será encerrado.");
                system("PAUSE");
            break;

            default:
                printf("Opção inválida, tente novamente.");
            break;

        }
    }

    return 0;
}
