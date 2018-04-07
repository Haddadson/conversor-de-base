#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>                                                                           //permite a utiliza��o de acentos e marcas gr�ficas
#define tamanho 80                                                                            //define o valor fixo (80) para tamanho de array

int main(){
    setlocale(LC_ALL, "Portuguese");                                                          //Permite a utiliza��o de acentos e marca��es gr�ficas
    int opcao=0, numero, auxiliar = 0, numValido = 1;                                         //Vari�veis para op��o do menu, numero a ser inserido e resultado, auxiliar, valida��o do n�mero
    int numBinario[tamanho], quociente[tamanho], resto[tamanho];                              //Vetores utilizados na convers�o de bases
    int tamanhoArray, expoente=0, resultado;                                                  //Vari�veis para definir o tamanho do vetor e o expoente na convers�o
    int  a=0, n, i=0;                                                                         //Vari�veis utilizadas em la�os de repeti��o para incremento/decremento

    while(opcao != 5){
        //Inicializa e redefine os valores ap�s um uso do programa
        system("CLS");                                                                        //Limpa a tela, removendo todos os caracteres
        for(i=0; i < tamanho; i++){
            quociente[i] = 0;
            resto[i] = 0;
            numBinario[i] = 0;
        }
        a=0;
        i = 0;
        auxiliar = 0;
        numero = 0;
        expoente=0;
        n=0;
        numValido = 1;
        resultado = 0;
        //Final das inicializa��es e redefini��o de valores

        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para bin�rio");
        printf("\n2 - Bin�rio para decimal");
        printf("\n3 - Decimal para octal");
        printf("\n4 - Octal para decimal");
        printf("\n5 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);                                                                  //Leitura para receber a op��o escolhida

        system("CLS");                                                                        //Limpa a tela, removendo todos os caracteres

        switch(opcao){                                                                        //Verifica a op��o e permite a execu��o das instru��es referentes � op��o escolhida
            case 1:
                printf("-----Decimal para bin�rio-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);                                                         //Leitura para receber o n�mero a ser convertido
                printf("\n %d em bin�rios: ",numero);                                         //Imprime o n�mero digitado e, ap�s as seguintes instru��es, imprimir� o resultado
                //Algoritmo de divis�es sucessivas para a convers�o
                while (numero != 1){                                                          // enquanto o quociente for diferente de 1, o programa continuar� calculando
                    quociente[i]= numero / 2;                                                 //Vetor que calcula e armazena os quocientes
                    resto[i] = numero % 2;                                                    //Vetor que calcula e armazena os restos
                    numero=quociente[i];                                                      //atribuindo novo valor para que seja poss�vel a continua��o do c�lculo
                    i++;                                                                      //Incrementa vari�vel i para continuar percorrendo o n�mero
                }

                //Imprimindo o �ltimo quociente mais os restos de "tr�s pra frente" (n�mero em bin�rios)
                auxiliar = i;                                                                 //Utiliza a vari�vel incrementada para saber buscar o �ltimo digito
                if(quociente[auxiliar] == 0){                                                 //Caso o �ltimo digito seja 0
                    i--;                                                                      //Remove o �ltimo digito, para impedir a exibi��o de zero a esquerda
                }


                while (i>=0){                                                                 //Percorre o vetor para imprimir
                    if (quociente[i] == 1){                                                   //Caso o primeiro digito seja 1, imprime o n�mero 1 primeiro
                      printf("1%d",resto[i]);
                    }else {
                        printf("%d",resto[i]);                                                //Realiza impress�o do vetor com o resultado convertido
                    }
                    i--;                                                                      //Decrementa a vari�vel i para percorrer o vetor
                }
                printf(" (2)\n");
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar

            break;

            case 2:
                printf("-----Bin�rio para decimal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);                                                         //Leitura para receber o n�mero a ser convertido
                printf("\n");                                                                 //Quebra uma linha

                //Valida��o para verificar se o n�mero bin�rio possui apenas zeros e uns
                for (n = numero; n != 0; n /= 10) {                                           //percorre o n�mero dividindo-o por 10 para eliminar o �ltimo digito
                    auxiliar = n % 10;                                                        //pega o resto da divis�o por dez, sendo ele o �ltimo digito do n�mero
                    if (auxiliar != 0 && auxiliar != 1) {                                     //verifica se o n�mero possui apenas 0s e 1s
                        numValido = 0;                                                        //caso n�o possua, o n�mero � marcado como inv�lido
                        break;                                                                //quebra o loop for atrav�s do break
                    } else{
                        numValido = 1;                                                        //Caso passe na valida��o, o n�mero � marcado como v�lido
                    }
                }

                if(numValido == 1){                                                           //caso o n�mero seja v�lido, executa a convers�o
                    //Transfere o n�mero bin�rio inserido para um vetor
                    while (numero != 1){
                        numBinario[i] = numero%10;                                            //Armazena o �ltimo digito em um vetor
                        numero /= 10;                                                         //Divide o n�mero por 10 para remover o �ltimo digito e buscar o pr�ximo
                        i++;                                                                  //Incrementa para continuar percorrendo o n�mero
                    }

                    numBinario[i]= numero;                                                    //Transfere o �ltimo bit para o vetor
                    numero = 0;                                                               //limpa a vari�vel para exibir o resultado no final
                    tamanhoArray = i;                                                         //define o tamanho do array como o n�mero de itera��es necess�rias para percorrer o n�mero
                    int numConversao[tamanhoArray];                                           //cria o vetor do tamanho necess�rio

                   //inverte o n�mero bin�rio utilizando um vetor auxiliar (j� que o n�mero � invertido ao ser transferido para string)
                    for (a = i, i=0; a >= 0; a--, i++){
                        numConversao[i] = numBinario[a];                                      //transfere o �ltimo digito de um vetor para o primeiro do outro (invertendo e colocando na ordem certa)
                        printf("%d", numConversao[i]);                                        //imprime o n�mero digitado em bin�rio
                    }

                    //inicia convers�o de dados
                    for (a = tamanhoArray; a >= 0; a--){
                        numConversao[a] = numConversao[a] * pow(2, expoente);                 //multiplica o digito pela base elevada � posi��o
                        numero += numConversao[a];                                            //Soma o valor multiplicado para exibir o resultado
                        expoente++;                                                           //incrementa o expoente
                    }

                    printf(" em decimal: %d", numero);                                        //Imprime o n�mero j� convertido
                } else {
                    printf("\nO n�mero inserido n�o pertence a base 2! Tente novamente!");    //Caso o n�mero seja inv�lido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar

            break;

            case 3:
                printf("-----Decimal para octal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);                                                         //Leitura para receber o n�mero a ser convertido
                printf("\n %d em octal: ", numero);                                           //Imprime o n�mero digitado e, ap�s as seguintes instru��es, imprimir� o resultado
                //Algoritmo de divis�es sucessivas para a convers�o
                while (numero != 1){                                                          // enquanto o quociente for diferente de 1, o programa continuar� calculando
                    quociente[i]= numero / 8;                                                 //Vetor que calcula e armazena os quocientes
                    resto[i] = numero % 8;                                                    //Vetor que calcula e armazena os restos
                    numero=quociente[i];                                                      //atribuindo novo valor para que seja poss�vel a continua��o do c�lculo
                    i++;
                }

                //Imprimindo o �ltimo quociente mais os restos de "tr�s pra frente" (n�mero em octal)
                auxiliar = i;                                                                 //Utiliza a vari�vel incrementada para saber buscar o �ltimo digito
                if(quociente[auxiliar] == 0){                                                 //Caso o �ltimo digito seja 0
                    i--;                                                                      //Remove o �ltimo digito, para impedir a exibi��o de zero a esquerda
                }

                while (i>=0){                                                                 //Percorre o vetor para imprimir
                    if (quociente[i] == 1){                                                   //Caso o primeiro digito seja 1, imprime o n�mero 1 primeiro
                      printf("1%d",resto[i]);
                     }else {
                        printf("%d",resto[i]);                                                //Realiza impress�o do vetor com o resultado convertido
                    }
                    i--;                                                                      //Decrementa a vari�vel i para percorrer o vetor
                }
                printf(" (8)\n");
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar
            break;

            case 4:
                printf("-----Octal para decimal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero);                                                         //Leitura para receber o n�mero a ser convertido
                printf("\n");                                                                 //Quebra uma linha
                auxiliar = numero;                                                            //Iguala a vari�vel auxiliar ao n�mero recebido

                while (auxiliar != 0){                                                        //La�o de repeti��o para percorrer o n�mero inserido
                    if (auxiliar % 10 < 0 || auxiliar % 10 > 7){                              //Verifica se o �ltimo digito � valido (entre 0 e 7)
                        numValido = 0;                                                        //Caso n�o seja, o n�mero � marcado como inv�lido
                        break;                                                                //For�a a sa�da do loop
                    } else {
                      numValido = 1;                                                          //Caso seja v�lido, o n�mero � marcado como v�lido
                    }
                    auxiliar /= 10;                                                           //Divide por 10, eliminando o �ltimo digito e permitindo a itera��o
                }
                if (numValido == 1){                                                          //Caso o n�mero seja v�lido, executa a convers�o
                    while(numero != 0){                                                       //Percorre o n�mero
                        resultado =  resultado +(numero % 10)* pow(8, i++);                   //Realiza a convers�o, obtendo o �ltimo digito, multiplicando-o por 8 elevado � posi��o e somando o resultado
                        numero /= 10;                                                         //Divide o n�mero por 10 para eliminar o �ltimo digito e continuar a itera��o
                    }
                    printf(" em decimal: %d", resultado);                                     //Imprime o n�mero j� convertido
                }else {
                    printf("\nO n�mero inserido n�o pertence a base 8! Tente novamente!");    //Caso o n�mero seja inv�lido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar
            break;

            case 5:                                                                           //Op��o de sair
                printf("O programa ser� encerrado.\n");                                       //Mensagem indicando a finaliza��o do programa
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar
            break;

            default:                                                                          //Op��o padr�o, caso o valor inserido n�o encaixe em nenhum case
                printf("Op��o inv�lida, tente novamente.\n");                                 //Mensagem indicando que a op��o escolhida � inv�lida
                system("PAUSE");                                                              //Aguarda o usu�rio para continuar
            break;

        }
    }

    return 0;
}
