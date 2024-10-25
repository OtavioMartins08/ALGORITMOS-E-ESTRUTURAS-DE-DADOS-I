#include "usuarios.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Usuario *motoristas = NULL;
Usuario *alunos = NULL;
int qtdMotoristas = 0;
int qtdAlunos = 0;

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int emailValido(const char *email)
{
    int contArroba = 0;
    int comprimento = strlen(email);
    if (comprimento >= MAX_EMAIL)
        return 0;

    for (int i = 0; i < comprimento; i++)
    {
        if (email[i] == '@')
            contArroba++;
    }

    return contArroba == 1;
}

void cadastrarUsuario(Usuario **usuarios, const char *tipoUsuario)
{
    Usuario *novoUsuario = (Usuario *)malloc(sizeof(Usuario));
    if (!novoUsuario)
    {
        printf("Erro ao alocar memoria para novo %s!\n", tipoUsuario);
        return;
    }

    printf("Digite o nome do %s: ", tipoUsuario);
    scanf(" %[^\n]s", novoUsuario->nome);
    printf("Digite o e-mail do %s: ", tipoUsuario);
    scanf("%s", novoUsuario->email);

    if (!emailValido(novoUsuario->email))
    {
        printf("E-mail invalido!\n");
        free(novoUsuario);
        return;
    }

    printf("Digite a senha: ");
    scanf("%s", novoUsuario->senha);

    novoUsuario->prox = *usuarios;
    *usuarios = novoUsuario;

    printf("%s cadastrado com sucesso!\n", tipoUsuario);
}

void listarUsuarios(Usuario *usuarios, const char *tipoUsuario)
{
    Usuario *atual = usuarios;
    int indice = 1;
    printf("Lista de %s:\n", tipoUsuario);
    while (atual != NULL)
    {
        printf("%d. %s (%s)\n", indice++, atual->nome, atual->email);
        atual = atual->prox;
    }
}

Usuario *loginUsuario(Usuario *usuarios, const char *tipoUsuario)
{
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
    printf("Digite o e-mail do %s: ", tipoUsuario);
    scanf("%s", email);
    printf("Digite a senha: ");
    scanf("%s", senha);

    Usuario *atual = usuarios;
    while (atual != NULL)
    {
        if (strcmp(atual->email, email) == 0 && strcmp(atual->senha, senha) == 0)
        {
            printf("Login bem-sucedido! Bem-vindo, %s!\n", atual->nome);
            return atual;
        }
        atual = atual->prox;
    }
    printf("Falha no login. Verifique suas credenciais.\n");
    return NULL;
}

void editarUsuario(Usuario *usuario)
{
    printf("Digite o novo nome (atual: %s): ", usuario->nome);
    scanf(" %[^\n]s", usuario->nome);
    printf("Digite o novo e-mail (atual: %s): ", usuario->email);
    scanf("%s", usuario->email);
    printf("Digite a nova senha: ");
    scanf("%s", usuario->senha);
    printf("Dados atualizados com sucesso!\n");
}

void excluirUsuario(Usuario **usuarios, int indice)
{
    Usuario *atual = *usuarios;
    Usuario *anterior = NULL;
    int i = 0;

    while (atual != NULL && i < indice)
    {
        anterior = atual;
        atual = atual->prox;
        i++;
    }

    if (atual == NULL)
    {
        printf("Usuario não encontrado!\n");
        return;
    }

    if (anterior == NULL)
    {
        *usuarios = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Usuario excluido com sucesso!\n");
}

void acoesMotorista(Usuario *motorista)
{
    int opcao;
    do
    {
        printf("\nAcoes para o motorista %s:\n", motorista->nome);
        printf("1. Editar dados\n");
        printf("2. Excluir conta\n");
        printf("3. Adicionar rota\n");
        printf("4. Excluir rota\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            editarUsuario(motorista);
            salvarMotoristas();
            break;
        case 2:
            excluirUsuario(&motoristas, 0);
            salvarMotoristas();
            opcao = 5;
            break;
        case 3:
            adicionarRotaMotorista();
            break;
        case 4:
            excluirRotaMotorista();
            break;
        case 5:
            printf("Voltando ao menu principal...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
}

void acoesAluno(Usuario *aluno)
{
    int opcao;
    do
    {
        printf("\nAcoes para o aluno %s:\n", aluno->nome);
        printf("1. Editar dados\n");
        printf("2. Excluir conta\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            editarUsuario(aluno);
            salvarAlunos();
            break;
        case 2:
            excluirUsuario(&alunos, 0);
            salvarAlunos();
            opcao = 3;
            break;
        case 3:
            printf("Voltando ao menu principal...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
}
