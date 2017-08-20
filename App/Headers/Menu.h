#ifndef MENU_INCLUDED
#define MENU_INCLUDED

//Assinaturas de Funções do Menu

int mainExecute(int command, void * Tads[]); //Execução dos Principais Comandos
int validadeCommand(int start, int end); //Valida os Comandos Recebidos da Faixa [start, end]
void showMenu(int level); //Função para mostrar o Menu
void giveCommand(void * Tads[]); //Recebe internamente algum comando e encaminha para a função da ação
void giveDelete(void * Tads[], int choose); //Recebe qual Tad irá ser editado e encaminha para a ação
void giveUpdate (void * Tads[], int choose); //Recebe qual Tad irá ser editado e encaminha para a ação

//Dependências
#include "File.h"
#include "Data.h"
#include "Menu.h"
#include "Unissex.h"
#include "Time.h"
#include <stdio.h>


//Execução dos Comandos Principais
int mainExecute(int command, void * Tads[]) {
    switch (command) {
        case 1:
            giveFile(Tads);
            return 1;
        case 2:
            giveData(Tads);
            //Função para Criar NodeData
            //FunçãO para Ligar o NodeData a algum Nó de alguma Tad que o Usuario escolher
            return 1;
        case 3:
            giveCommand(Tads);
            //Função que Recebe qual estrutura irá editar como parâmetro, e pergunta se deseja Editar ou Excluir os Dados
            return 1;
        case 4:
            showMenu(1);
            validadeCommand(1, 4);//Função que recebe qual a Estrutura irá ser visualizada
            //Função que Recebe qual Tad será visualizado, quantos serão visualizados e exibe na tela
            return 1;
        case 5:
            return 0;
    }
}

//Função que Valida os Dados que Recebe do Menu
int validadeCommand(int start, int end) {

    int res;

    printf("Digite o comando: ");
    scanf("%d", &res);

    while ( res < start || res > end ) {
        printf("Comando não identificado! Por favor, digite novamente: ");
        scanf("%d", &res);
    }

    return res;
}

//Função que Apresenta o Menu
void showMenu(int level) {

    switch ( level ) {
        case 0:
            printf("Lista de Opções: \n\n1 - Importar Arquivo CSV\n2 - Importar Dados\n3 - Editar Dados\n4 - Visualizar Dados\n5 - Sair\n\n");
            break;
        case 1:
            printf("Qual Estrutura deseja utilizar? \n\n1 - Lista Duplamente Encadeada\n2 - Árvore AVL\n3 - Ambas\n4 - Voltar\n\n");
            break;
        case 2:
            printf("Como deseja Editar?\n\n1 - Excluir\n2 - Atualizar\n3 - Voltar\n\n");
            break;
    }
}

//Recebe algum comando de Edição e Encaminha para a Função Correspondente
void giveCommand(void * Tads[]) {
    showMenu(2);
    int choose = validadeCommand(1, 3);//Escolhe qual Estrutura irá editar

    switch (choose) {
        case 1://Caso deseja Deletar Dados
            showMenu(1);
            giveDelete(Tads, validadeCommand(1, 4));
            break;
        case 2://Caso deseja Atualizar Dados
            showMenu(1);
            giveUpdate(Tads, validadeCommand(1, 4));
            break;
    }
}

//Recebe a Escolha de Qual TAD irá deletar dados
void giveDelete(void * Tads[], int choose) {

    int matricula;

    printf("Digite a Matricula: ");
    scanf("%d", &matricula);

    switch (choose) {
        case 1://Caso escolha Deletar
            TimePass(0);
            Delete(Tads, matricula, 1);
            showTime(TimePass(1));
            break;
        case 2://Caso escolha Deletar da Arvore
            TimePass(0);
            //Delete(Tads, matricula, 0); //Escolhe Deletar da Arvore
            showTime(TimePass(1));
            break;
        case 3://Caso escolha Deletar de Ambas
            TimePass(0);
            Delete(Tads, matricula, 1);
            //Delete(Tads, matricula, 0); //Escolhe Deletar da Arvore
            showTime(TimePass(1));
            break;
    }
}

//Recebe a Escolha de Qual TAD irá atualizar dados
void giveUpdate (void * Tads[], int choose) {

    switch (choose) {
        case 1://Caso escolha Ataualizar da Lista
            break;
        case 2://Caso escolha Atualizar da Arvore
            break;
        case 3://Caso escolha Atualizar de Ambas
            break;
    }
}
#endif
