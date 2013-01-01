/* 
 * File:   main.c
 * Author: PC
 *
 * Created on 21 de Dezembro de 2012, 23:57
 */


#include <stdio.h>
#include <stdlib.h>
#define TAM 50
#define SIZE 20
#define CAP_MAX 5


/*
 * 
 */


// Estruturas e enumeracoes subjacentes a aluno e instrutor

typedef struct cod_postal {
    unsigned short int nr_local, nr_rua;
} cod_postal;

typedef struct morada {
    char rua[TAM];
    unsigned short int numero;
    cod_postal cod_postal;
    char localidade[SIZE];
} morada;

typedef struct telefone {
    unsigned short int ind_regional, numero1, numero2;
} telefone;

typedef enum dia {
    UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, ONZE,
    DOZE, TREZE, CATORZE, QUINZE, DEZASSEIS, DEZASSETE, DEZOITO, DEZANOVE, VINTE,
    VINTE_E_UM, VINTE_E_DOIS, VINTE_E_TRES, VINTE_E_QUATRO, VINTE_E_CINCO,
    VINTE_E_SEIS, VINTE_E_SETE, VINTE_E_OITO, VINTE_E_NOVE, TRINTA, TRINTA_E_UM
} dia;

typedef enum mes {
    JANEIRO, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO,
    SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
} mes;

typedef struct data {
    dia dia;
    mes mes;
    unsigned short int ano;
} data;

typedef enum categoria {
    A, B, C, D
} categoria;

typedef enum rev_carta {
    Sim, Nao
} rev_carta;


// Estrutura para os dados do Aluno

typedef struct aluno {
    unsigned long int ni;
    char nome[TAM];
    morada morada;
    telefone telefone;
    data data;
    categoria categoria;
    rev_carta rev_carta;
} aluno;


// Estrutura para os dados do Instrutor

typedef struct instrutor {
    unsigned short int nr_licenca;
    char nome[TAM];
    morada morada;
    telefone telefone;
    data data;
    categoria categoria;
    unsigned short salario;
} instrutor;

void clear_input() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Funcao para inserir alunos
void inserir_aluno(aluno alunos[], int nr_aluno) {
    puts("Inserir numero de identificacao: ");
    scanf("%lu", &alunos[nr_aluno].ni);
    clear_input();
    puts("Escrever nome completo: ");
    fflush(stdin);
    fgets(alunos[nr_aluno].nome, TAM, stdin);
    puts("Escrever o nome da rua onde habita: ");
    fflush(stdin);
    fgets(alunos[nr_aluno].morada.rua, TAM, stdin);
    puts("Inserir numera da porta: ");
    scanf("%hu", &alunos[nr_aluno].morada.numero);
    puts("Inserir codigo postal: ");
    scanf("%hu - %hu", &alunos[nr_aluno].morada.cod_postal.nr_local, &alunos[nr_aluno].morada.cod_postal.nr_rua);
    puts("Escrever a localidade onde habita: ");
    fflush(stdin);
    fgets(alunos[nr_aluno].morada.localidade, SIZE, stdin);
    puts("Inserir numero de telefone: ");
    scanf("%hu - %hu - %hu", &alunos[nr_aluno].telefone.ind_regional, &alunos[nr_aluno].telefone.numero1, &alunos[nr_aluno].telefone.numero2);
    puts("Inserir data de nascimento (dia-mes-ano): ");
    int dia = (intptr_t)&alunos[nr_aluno].data.dia;
    int mes = (intptr_t)&alunos[nr_aluno].data.mes;
    int ano = (intptr_t)&alunos[nr_aluno].data.ano;
    scanf("%d - %d - %d", &dia, &mes, &ano);
    puts("Introduzir a categoria de conducao na qual se esta a inscrever (A, B, C ou D): ");
    int categoria = (intptr_t)&alunos[nr_aluno].categoria;
    scanf("%d", &categoria);
    puts("Introduzir revalidacao de carta (sim ou nao): ");
    int rev_carta = (intptr_t)&alunos[nr_aluno].rev_carta;
    scanf("%d", &rev_carta);
}

void alterar_aluno(aluno alunos[], int nr_aluno) {


}

void listar_aluno() {

}


// menu principal

int menu() {

    int opcao;

    do {
        printf("* Agenda eletronica *\n\n");
        printf("-- Bem vindo ao programa de agenciamento --\n \n \n ");
        printf("            ---------------------//---------------------\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n \n \n");
        printf("                        |-----------------------------|\n");
        printf("                        |1-Gerir dados do Aluno       |\n");
        printf("                        |2-Gerir dados do Instrutor   |\n");
        printf("                        |3-Gerir marcacoes das aulas  |\n");
        printf("                        |4-Sair                     |\n");
        printf("                        |-----------------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao > 4 || opcao < 1);

    return opcao;
}


// submenu "Gerir dados do Aluno"

int menu_aluno() {

    int opcao;

    do {
        printf("\t\t\t* Gerir dados do Aluno *\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n\n\n");
        printf("                        |------------------|\n");
        printf("                        |1-Adicionar dados |\n");
        printf("                        |2-Alterar dados   |\n");
        printf("                        |3-Listar dados    |\n");
        printf("                        |4-Remover dados   |\n");
        printf("                        |5-Voltar          |\n");
        printf("                        |------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao > 5 || opcao < 1);

    return opcao;
}


// submenu "Gerir dados do Instrutor"

int menu_Instrutor() {

    int opcao;

    do {
        printf("\t\t\t* Gerir dados do Instrutor *\n\n");
        printf("Por Favor, escolha uma das seguintes opcoes digitanto o numero correspondente \n\n\n");
        printf("                        |------------------|\n");
        printf("                        |1-Adicionar dados |\n");
        printf("                        |2-Alterar dados   |\n");
        printf("                        |3-Listar dados    |\n");
        printf("                        |4-Remover dados   |\n");
        printf("                        |5-Voltar          |\n");
        printf("                        |------------------|\n\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao > 5 || opcao < 1);

    return opcao;
}

int main(void) {

    aluno alunos[CAP_MAX];
    int opcao, opcao_aluno, i, nr_aluno;


    do {
        system("clear");
        opcao = menu();
        switch (opcao) {
            case 1:
                do {
                    system("clear");
                    opcao_aluno = menu_aluno();
                    switch (opcao_aluno) {
                        case 1:
                            puts("Seleccionada opcao 1 - Adicionar dados");
                            for (i = 0; i < CAP_MAX; i++) {
                                inserir_aluno(alunos, nr_aluno);
                            }

                            system("clear");
                            break;
                        case 2:

                            break;
                        case 3:
                            puts("Selecionada opcao 3 - Listar dados");
                            puts("Alunos inscritos:");
                            for (i = 0; i < CAP_MAX; i++) {
                                printf("%d - %s", i, alunos[i].nome);
                            }

                            break;
                        case 4:

                            break;
                        case 0:
                            printf("Seleccionada opcao 0 - Voltar\n");
                            break;
                    }
                } while (opcao_aluno != 5);
            case 2:
                break;
            case 3:
                break;

        }
    } while (opcao_aluno != 4);


    return 0;
}

