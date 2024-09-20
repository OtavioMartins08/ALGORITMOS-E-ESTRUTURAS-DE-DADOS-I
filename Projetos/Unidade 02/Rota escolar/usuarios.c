#include "usuarios.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>

Usuario motoristas[MAX_USUARIOS];
Usuario alunos[MAX_USUARIOS];

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

void cadastrarUsuario(Usuario usuarios[], int *qtdUsuarios, const char *tipoUsuario)
{
    if (*qtdUsuarios >= MAX_USUARIOS)
    {
        printf("Limite de %s atingido!\n", tipoUsuario);
        return;
    }

    Usuario novoUsuario;
    printf("Digite o nome do %s: ", tipoUsuario);
    scanf(" %[^\n]s", novoUsuario.nome);
    printf("Digite o e-mail do %s: ", tipoUsuario);
    scanf("%s", novoUsuario.email);

    if (!emailValido(novoUsuario.email))
    {
        printf("E-mail invalido!\n");
        return;
    }

    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);

    usuarios[*qtdUsuarios] = novoUsuario;
    (*qtdUsuarios)++;
    printf("%s cadastrado com sucesso!\n", tipoUsuario);
}

void listarUsuarios(Usuario usuarios[], int qtdUsuarios, const char *tipoUsuario)
{
    printf("Lista de %s:\n", tipoUsuario);
    for (int i = 0; i < qtdUsuarios; i++)
    {
        printf("%d. %s (%s)\n", i + 1, usuarios[i].nome, usuarios[i].email);
    }
}

int loginUsuario(Usuario usuarios[], int qtdUsuarios, const char *tipoUsuario)
{
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
    printf("Digite o e-mail do %s: ", tipoUsuario);
    scanf("%s", email);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < qtdUsuarios; i++)
    {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0)
        {
            printf("Login bem-sucedido! Bem-vindo, %s!\n", usuarios[i].nome);
            return i;
        }
    }
    printf("Falha no login. Verifique suas credenciais.\n");
    return -1;
}

void editarUsuario(Usuario *usuario)
{
    printf("Digite o novo nome: ");
    scanf(" %[^\n]s", usuario->nome);
    printf("Digite o novo e-mail: ");
    scanf("%s", usuario->email);
    printf("Digite a nova senha: ");
    scanf("%s", usuario->senha);
    printf("Dados atualizados com sucesso!\n");
}

void excluirUsuario(Usuario usuarios[], int *qtdUsuarios, int indice)
{
    for (int i = indice; i < (*qtdUsuarios) - 1; i++)
    {
        usuarios[i] = usuarios[i + 1];
    }
    (*qtdUsuarios)--;
    printf("Usuario excluido com sucesso!\n");
}

void acoesMotorista(int indiceMotorista)
{
    int opcao;
    do
    {
        printf("\nAcoes para o motorista %s:\n", motoristas[indiceMotorista].nome);
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
            editarUsuario(&motoristas[indiceMotorista]);
            salvarMotoristas();
            break;
        case 2:
            excluirUsuario(motoristas, &qtdMotoristas, indiceMotorista);
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

void acoesAluno(int indiceAluno)
{
    int opcao;
    do
    {
        printf("\nAcoes para o aluno %s:\n", alunos[indiceAluno].nome);
        printf("1. Editar dados\n");
        printf("2. Excluir conta\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            editarUsuario(&alunos[indiceAluno]);
            salvarAlunos();
            break;
        case 2:
            excluirUsuario(alunos, &qtdAlunos, indiceAluno);
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
