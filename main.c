#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); //Permite a utiliza��o de acentos e marca��es gr�ficas
    int opcao=0;


    while(opcao != 5){
        system("CLS");
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
                //TODO
                system("PAUSE");
            break;

            case 2:
                printf("-----Bin�rio para decimal-----");
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
                printf("O programa ser� encerrado.");
                system("PAUSE");
            break;

            default:
                printf("Op��o inv�lida, tente novamente.");
            break;

        }
    }

    return 0;
}
