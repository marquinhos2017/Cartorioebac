#include <stdlib.h> //bibloteca de comunicacao com o usuario
#include <stdio.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s",cpf);

    strcpy(arquivo,cpf); //Responsvael por copiar os valores das strings

    FILE *file; 
    file = fopen(arquivo,"w"); //cria o arquivo
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);

    file= fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);

    file= fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo ser cadastrado: ");
    scanf("%s",cargo);

    file= fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);






    system("pause");
}

int consulta()
{
    char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo, nao localizado !.\n");
    }

    while(fgets(conteudo, 100, file) != NULL)
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    printf("Voce escolheu deletar nomes nomes!\n");
    system("pause");
}

int main()
{
    int opcao=0;
    int laco=1;
    int aux=1;

  
    for(laco=1;laco=1;)
    {
        setlocale(LC_ALL, "Portuguese");

        system("cls");

        printf("### Cartorio da EBAC ### \n\n");
        printf("### Escolha a opcao desejada do menu: ###\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Esse software e de livre uso dos alunos\n");

        scanf("%d",&opcao);

        system("cls");

        switch(opcao)
        {
            case 1:
            registro();
            for(aux=1;aux=1;){
                printf("Adicionar outro usuario ? (Y = 1 / N = 0)");
                scanf("%d",&aux);
                if(aux==0){
                    break;
                }else{
                    registro();
                }
            }
            
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado  por utilizar o sistema/n");
            return 0;
            break;

            default:
            printf("Essa opcao nao esta disponivel!\n");
            system("pause");
            break;

        }
    }

    
}
