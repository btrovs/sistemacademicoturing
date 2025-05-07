#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Necessário para isdigit

// Validação de email
bool validarEmail(const char *email) {
    const char *arroba = strchr(email, '@');
    if (arroba == NULL) {
        return false;
    }

    const char *ponto = strchr(arroba, '.');
    if (ponto == NULL) {
        return false;
    }

    return true;
}

// Validação do formato do CPF: xxx.xxx.xxx-xx
bool validarCPFFormatado(const char *cpf) {
    if (strlen(cpf) != 14) {
        return false;
    }

    if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-') {
        return false;
    }

    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7 || i == 11) continue;
        if (!isdigit(cpf[i])) return false;
    }

    return true;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    char nome[200], senha[20], estado[50], cidade[50];
    char email[200];
    char cpf[20]; // espaço suficiente para "000.000.000-00\0"
    int rg, cep;
    int dia, mes, ano;
    int opcao;

    printf("---- SISTEMA ACADÊMICO FACULDADE ALAN TURING - BEM-VINDO(A) ----\n");

    printf("1 - Inserir/Editar Nome\n");
    printf("2 - Inserir/Editar Data de Nascimento\n");
    printf("3 - Inserir/Editar CPF\n");
    printf("4 - Inserir/Editar RG\n");
    printf("5 - Inserir/Editar Email\n");
    printf("6 - Inserir/Editar Senha\n");
    printf("7 - Inserir/Editar Estado\n");
    printf("8 - Inserir/Editar Cidade\n");
    printf("9 - Inserir/Editar CEP\n");

    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // limpa o '\n' deixado pelo scanf

    switch(opcao) {
        case 1:
            printf("Insira ou Edite seu Nome: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            break;

        case 2:
            printf("Insira sua Data de Nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &dia, &mes, &ano);
            break;

        case 3:
            printf("Insira ou Edite seu CPF (com pontos e traço, ex: 123.456.789-00): ");
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            if (validarCPFFormatado(cpf)) {
                printf("CPF com formato válido!\n");
            } else {
                printf("Formato de CPF inválido. Use xxx.xxx.xxx-xx\n");
            }
            break;

        case 4:
            printf("Insira ou Edite seu RG: ");
            scanf("%d", &rg);
            break;

        case 5:
            printf("Insira ou Edite seu Email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';

            if (validarEmail(email)) {
                printf("Email válido!\n");
            } else {
                printf("Email inválido.\n");
            }
            break;

        case 6:
            printf("Insira ou Edite sua Senha: ");
            fgets(senha, sizeof(senha), stdin);
            senha[strcspn(senha, "\n")] = '\0';
            break;

        case 7:
            printf("Insira ou Edite seu Estado: ");
            fgets(estado, sizeof(estado), stdin);
            estado[strcspn(estado, "\n")] = '\0';
            break;

        case 8:
            printf("Insira ou Edite sua Cidade: ");
            fgets(cidade, sizeof(cidade), stdin);
            cidade[strcspn(cidade, "\n")] = '\0';
            break;

        case 9:
            printf("Insira ou Edite seu CEP: ");
            scanf("%d", &cep);
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
