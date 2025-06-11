#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *saida;
    char nome[50], cpf[15], opcao;
    int idade, sexo, cont = 0;

    printf("=== SISTEMA DE TRIAGEM DE PACIENTES ===\n\n");

    printf("Digite seu CPF: ");
    scanf(" %14[^\n]", cpf);

    printf("Digite seu nome: ");
    getchar(); // limpa buffer
    scanf(" %49[^\n]", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    do {
        printf("Digite seu sexo: [1] Masculino [2] Feminino: ");
        scanf("%d", &sexo);
        if (sexo != 1 && sexo != 2) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (sexo != 1 && sexo != 2);

    // Criar arquivo com nome do paciente
    saida = fopen(nome, "w");
    fprintf(saida, "CPF: %s\n", cpf);
    fprintf(saida, "Nome: %s\n", nome);
    fprintf(saida, "Idade: %d\n", idade);
    fprintf(saida, "Sexo: %s\n", sexo == 1 ? "Masculino" : "Feminino");

    // Questionário
    struct Pergunta {
        char texto[150];
        int pontuacao;
    } perguntas[] = {
        {"Tem febre?", 5},
        {"Tem dor de cabeça?", 1},
        {"Tem secreção nasal ou espirros?", 1},
        {"Tem dor/irritação na garganta?", 1},
        {"Tem tosse seca?", 3},
        {"Tem dificuldade respiratória?", 10},
        {"Tem dores no corpo?", 1},
        {"Tem diarreia?", 1},
        {"Teve contato com caso confirmado de COVID-19 nos últimos 14 dias?", 10},
        {"Esteve em locais com grande aglomeração?", 3}
    };

    int total_perguntas = sizeof(perguntas) / sizeof(perguntas[0]);

    for (int i = 0; i < total_perguntas; i++) {
        do {
            printf("%s [S/N]: ", perguntas[i].texto);
            scanf(" %c", &opcao);
            if (opcao == 'S' || opcao == 's') {
                cont += perguntas[i].pontuacao;
                break;
            } else if (opcao == 'N' || opcao == 'n') {
                break;
            } else {
                printf("Opção inválida! Tente novamente.\n");
            }
        } while (1);
    }

    // Resultado
    printf("\n==== RESULTADO DA TRIAGEM ====\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Sexo: %s\n", sexo == 1 ? "Masculino" : "Feminino");
    printf("Pontuação final: %d pts\n", cont);

    fprintf(saida, "Pontuação final: %d pts\n", cont);

    if (cont <= 9) {
        printf("Classificação: Baixo Risco\n");
        fprintf(saida, "Classificação: Baixo Risco\n");
    } else if (cont <= 19) {
        printf("Classificação: Médio Risco\n");
        fprintf(saida, "Classificação: Médio Risco\n");
    } else {
        printf("Classificação: Alto Risco\n");
        fprintf(saida, "Classificação: Alto Risco\n");
    }

    fclose(saida);

    printf("\nRelatório salvo no arquivo \"%s\"\n", nome);
    return 0;
}
