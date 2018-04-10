#include <stdio.h>
#include <stdlib.h>
#include <math.h>                                                                             //Permite a utilização de funções matemáticas como pow, para potências
#include <locale.h>                                                                           //permite a utilização de acentos e marcas gráficas
#define tamanho 100                                                                            //define o valor fixo (80) para tamanho de array

int main(){
    setlocale(LC_ALL, "Portuguese");                                                          //Permite a utilização de acentos e marcações gráficas
    int opcao=0;                                                                              //Variável para escolha da opção
    long int numero, auxiliar = 0, numValido = 1, resultado;                                  //Variáveis para numero a ser inserido e resultado, auxiliar, validação do número
    long int numBinario[tamanho], quociente[tamanho], resto[tamanho];                         //Vetores utilizados na conversão de bases
    int tamanhoArray, expoente=0;                                                             //Variáveis para definir o tamanho do vetor e o expoente na conversão
    int  a=0, n, i=0;                                                                         //Variáveis utilizadas em laços de repetição para incremento/decremento

    while(opcao != 5){
        //Inicializa e redefine os valores após um uso do programa
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
        //Final das inicializações e redefinição de valores
        //Impressão do menu inicial
        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para binário");
        printf("\n2 - Binário para decimal");
        printf("\n3 - Decimal para octal");
        printf("\n4 - Octal para decimal");
        printf("\n5 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma opção: ");                                                      //Solicitação de escolha de opção
        scanf("%d", &opcao);                                                                  //Leitura para receber a opção escolhida
        fflush(stdin);                                                                        //Limpa o buffer do scanf para evitar erros ao inserir valores do tipo Char
        system("CLS");                                                                        //Limpa a tela, removendo todos os caracteres

        switch(opcao){                                                                        //Verifica a opção e permite a execução das instruções referentes à opção escolhida
            case 1:
                //Seleciona conversão de base 10 para base 2
                printf("-----Decimal para binário-----");
                printf("\nDigite o número: ");
                scanf("%ld", &numero);                                                        //Leitura para receber o número a ser convertido
                printf("\n%ld em binários: ",numero);                                        //Imprime o número digitado e, após as seguintes instruções, imprimirá o resultado

                //Algoritmo de divisões sucessivas para a conversão
                auxiliar = numero;                                                            //Grava o número recebido em uma variável auxiliar para efetuar comparações futuras
                if(numero == 1){                                                              //caso o número seja 1, executa a lógica apenas uma vez
                    quociente[i]= numero / 2;                                                 //Vetor que calcula e armazena os quocientes
                    resto[i] = numero % 2;                                                    //Vetor que calcula e armazena os restos
                    numero=quociente[i];                                                      //atribuindo novo valor para que seja possível a continuação do cálculo
                } else {                                                                      //caso não seja, converte normalmente
                    while (numero != 1){                                                      // enquanto o quociente for diferente de 1, o programa continuará calculando
                        quociente[i]= numero / 2;                                             //Vetor que calcula e armazena os quocientes
                        resto[i] = numero % 2;                                                //Vetor que calcula e armazena os restos
                        numero=quociente[i];                                                  //atribuindo novo valor para que seja possível a continuação do cálculo
                        i++;                                                                  //Incrementa variável i para continuar percorrendo o número
                    }
                }

                //Imprimindo o último quociente mais os restos de "trás pra frente" (número em binários)
                if(auxiliar != 1){
                    auxiliar = i;                                                             //Utiliza a variável incrementada para saber buscar o último digito
                    if(quociente[auxiliar] == 0){                                             //Caso o último digito seja 0
                        i--;                                                                  //Remove o último digito, para impedir a exibição de zero a esquerda
                    }
                }
                //Inicia a impressão do número convertido
                while (i>=0){                                                                 //Percorre o vetor para imprimir
                    if (quociente[i] == 1){                                                   //Caso o primeiro digito seja 1, imprime o número 1 primeiro
                      printf("1%ld",resto[i]);
                    }else {
                        printf("%ld",resto[i]);                                                //Realiza impressão do vetor com o resultado convertido
                    }
                    i--;                                                                      //Decrementa a variável i para percorrer o vetor
                }
                printf(" (2)\n");                                                             //Imprime a base do número e salta uma linha
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;
            case 2:
                //Seleciona conversão de base 2 para base 10
                printf("-----Binário para decimal-----");
                printf("\nDigite o número: ");
                scanf("%ld", &numero);                                                        //Leitura para receber o número a ser convertido
                printf("\n");                                                                 //Quebra uma linha
                //Validação para verificar se o número binário possui apenas zeros e uns
                for (n = numero; n != 0; n /= 10) {                                           //percorre o número dividindo-o por 10 para eliminar o último digito
                    auxiliar = n % 10;                                                        //pega o resto da divisão por dez, sendo ele o último digito do número
                    if (auxiliar != 0 && auxiliar != 1) {                                     //verifica se o número possui apenas 0s e 1s
                        numValido = 0;                                                        //caso não possua, o número é marcado como inválido
                        break;                                                                //quebra o loop for através do break
                    } else{
                        numValido = 1;                                                        //Caso passe na validação, o número é marcado como válido
                    }
                }

                if(numValido == 1){                                                           //caso o número seja válido, executa a conversão
                    //Transfere o número binário inserido para um vetor
                    while (numero != 1){
                        numBinario[i] = numero%10;                                            //Armazena o último digito em um vetor
                        numero /= 10;                                                         //Divide o número por 10 para remover o último digito e buscar o próximo
                        i++;                                                                  //Incrementa para continuar percorrendo o número
                    }
                    numBinario[i]= numero;                                                    //Transfere o último bit para o vetor
                    numero = 0;                                                               //limpa a variável para exibir o resultado no final
                    tamanhoArray = i;                                                         //define o tamanho do array como o número de iterações necessárias para percorrer o número
                    long int numConversao[tamanhoArray];                                      //cria o vetor do tamanho necessário

                   //inverte o número binário utilizando um vetor auxiliar (já que o número é invertido ao ser transferido para string)
                    for (a = i, i=0; a >= 0; a--, i++){
                        numConversao[i] = numBinario[a];                                      //transfere o último digito de um vetor para o primeiro do outro (invertendo e colocando na ordem certa)
                        printf("%ld", numConversao[i]);                                       //imprime o número digitado em binário
                    }

                    //inicia conversão de dados
                    for (a = tamanhoArray; a >= 0; a--){
                        numConversao[a] = numConversao[a] * pow(2, expoente);                 //multiplica o digito pela base elevada à posição
                        numero += numConversao[a];                                            //Soma o valor multiplicado para exibir o resultado
                        expoente++;                                                           //incrementa o expoente
                    }
                    //Inicia a impressão do número convertido
                    printf(" em decimal: %ld", numero);                                       //Imprime o número já convertido
                } else {
                    printf("\nO número inserido não pertence a base 2! Tente novamente!");    //Caso o número seja inválido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;
            case 3:
                //Seleciona conversão de base 10 para base 8
                printf("-----Decimal para octal-----");
                printf("\nDigite o número: ");
                scanf("%ld", &numero);                                                        //Leitura para receber o número a ser convertido
                printf("\n%ld em octal: ", numero);                                           //Imprime o número digitado e, após as seguintes instruções, imprimirá o resultado

                //Algoritmo de divisões sucessivas para a conversão
                auxiliar = numero;                                                            //Grava o número recebido em uma variável auxiliar para efetuar comparações futuras
                if(numero == 1){                                                              //caso o número seja 1, executa a lógica apenas uma vez
                    quociente[i]= numero / 8;                                                 //Vetor que calcula e armazena os quocientes
                    resto[i] = numero % 8;                                                    //Vetor que calcula e armazena os restos
                    numero=quociente[i];                                                      //atribuindo novo valor para que seja possível a continuação do cálculo
                } else {                                                                      //caso não seja, converte normalmente
                    while (numero != 1){                                                      //enquanto o quociente for diferente de 1, o programa continuará calculando
                        quociente[i]= numero / 8;                                             //Vetor que calcula e armazena os quocientes
                        resto[i] = numero % 8;                                                //Vetor que calcula e armazena os restos
                        numero=quociente[i];                                                  //atribuindo novo valor para que seja possível a continuação do cálculo
                        i++;                                                                  //Incrementa variável i para continuar percorrendo o número
                    }
                }

                //Imprimindo o último quociente mais os restos de "trás pra frente" (número em octal)
                if(auxiliar != 1){
                    auxiliar = i;                                                             //Utiliza a variável incrementada para saber buscar o último digito
                    if(quociente[auxiliar] == 0){                                             //Caso o último digito seja 0
                        i--;                                                                  //Remove o último digito, para impedir a exibição de zero a esquerda
                    }
                }
                //Inicia a impressão do número convertido
                while (i>=0){                                                                 //Percorre o vetor para imprimir
                    if (quociente[i] == 1){                                                   //Caso o primeiro digito seja 1, imprime o número 1 primeiro
                      printf("1%ld",resto[i]);
                     }else {
                        printf("%ld",resto[i]);                                               //Realiza impressão do vetor com o resultado convertido
                    }
                    i--;                                                                      //Decrementa a variável i para percorrer o vetor
                }
                printf(" (8)\n");                                                             //Imprime a base do número e salta uma linha
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;

            case 4:
                //Seleciona conversão de base 8 para base 10
                printf("-----Octal para decimal-----");
                printf("\nDigite o número: ");
                scanf("%ld", &numero);                                                        //Leitura para receber o número a ser convertido
                printf("\n");                                                                 //Quebra uma linha
                auxiliar = numero;                                                            //Iguala a variável auxiliar ao número recebido

                while (auxiliar != 0){                                                        //Laço de repetição para percorrer o número inserido
                    if (auxiliar % 10 < 0 || auxiliar % 10 > 7){                              //Verifica se o último digito é valido (entre 0 e 7)
                        numValido = 0;                                                        //Caso não seja, o número é marcado como inválido
                        break;                                                                //Força a saída do loop
                    } else {
                      numValido = 1;                                                          //Caso seja válido, o número é marcado como válido
                    }
                    auxiliar /= 10;                                                           //Divide por 10, eliminando o último digito e permitindo a iteração
                }
                if (numValido == 1){                                                          //Caso o número seja válido, executa a conversão
                    while(numero != 0){                                                       //Percorre o número
                        resultado =  resultado +(numero % 10)* pow(8, i++);                   //Realiza a conversão, obtendo o último digito, multiplicando-o por 8 elevado à posição e somando o resultado
                        numero /= 10;                                                         //Divide o número por 10 para eliminar o último digito e continuar a iteração
                    }
                    printf(" em decimal: %ld", resultado);                                    //Imprime o número já convertido
                }else {
                    printf("\nO número inserido não pertence a base 8! Tente novamente!");    //Caso o número seja inválido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;

            case 5:
                //Seleciona opção de sair
                printf("O programa será encerrado.\n");                                       //Mensagem indicando a finalização do programa
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;

            default:
                //Seleciona opção padrão, caso o valor inserido não atenda nenhuma condição dos 'cases'
                printf("Opção inválida, tente novamente.\n");                                 //Mensagem indicando que a opção escolhida é inválida
                system("PAUSE");                                                              //Aguarda o usuário para continuar
            break;
        }
    }
    return 0;                                                                                 //Encerra o programa, retornando 0 na função main
}
