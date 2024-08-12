#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 100
#define MAX_ROTAS 100
#define MAX_NOME 50
#define MAX_EMAIL 80
#define MAX_SENHA 20
#define MAX_ROTA 100
#define MAX_HORARIO 10

#define ARQUIVO_MOTORISTAS "motoristas.txt"
#define ARQUIVO_ALUNOS "alunos.txt"
#define ARQUIVO_ROTAS "rotas.txt"

typedef struct
{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
} Usuario;

typedef struct
{
    char rota[MAX_ROTA];
    char horarioPartida[MAX_HORARIO];
    char horarioChegada[MAX_HORARIO];
} Rota;

Usuario motoristas[MAX_USUARIOS];
Usuario alunos[MAX_USUARIOS];
Rota rotas[MAX_ROTAS];

int qtdMotoristas = 0;
int qtdAlunos = 0;
int qtdRotas = 0;

void limparTela()
{
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
    }
}

void mensagemBoasVindas(const char *tipoUsuario)
{
    printf("Bem-vindo ao sistema de gerenciamento de onibus escolar (%s)\n", tipoUsuario);
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

int horarioValido(const char *horario)
{
    if (strlen(horario) != 5)
        return 0;

    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
        {
            if (horario[i] != ':')
                return 0;
        }
        else if (!isdigit(horario[i]))
        {
            return 0;
        }
    }

    int horas = (horario[0] - '0') * 10 + (horario[1] - '0');
    int minutos = (horario[3] - '0') * 10 + (horario[4] - '0');

    return (horas >= 0 && horas < 24 && minutos >= 0 && minutos < 60);
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

void salvarUsuariosNoArquivo(Usuario usuarios[], int qtdUsuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < qtdUsuarios; i++)
    {
        fprintf(arquivo, "%s\n%s\n%s\n", usuarios[i].nome, usuarios[i].email, usuarios[i].senha);
    }

    fclose(arquivo);
}

void carregarUsuariosDoArquivo(Usuario usuarios[], int *qtdUsuarios, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!\n", nomeArquivo);
        return;
    }

    *qtdUsuarios = 0;
    while (fscanf(arquivo, " %[^\n]\n%[^\n]\n%[^\n]\n", usuarios[*qtdUsuarios].nome, usuarios[*qtdUsuarios].email, usuarios[*qtdUsuarios].senha) == 3)
    {
        (*qtdUsuarios)++;
    }

    fclose(arquivo);
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

void adicionarRota()
{
    if (qtdRotas >= MAX_ROTAS)
    {
        printf("Limite de rotas atingido!\n");
        return;
    }

    printf("Digite a nova rota: ");
    scanf(" %[^\n]s", rotas[qtdRotas].rota);

    do
    {
        printf("Digite o horario de partida (hh:mm): ");
        scanf("%s", rotas[qtdRotas].horarioPartida);
        if (!horarioValido(rotas[qtdRotas].horarioPartida))
        {
            printf("Horario de partida invalido! Deve estar no formato hh:mm e conter apenas numeros.\n");
        }
    } while (!horarioValido(rotas[qtdRotas].horarioPartida));

    do
    {
        printf("Digite o horario de chegada (hh:mm): ");
        scanf("%s", rotas[qtdRotas].horarioChegada);
        if (!horarioValido(rotas[qtdRotas].horarioChegada))
        {
            printf("Horario de chegada invalido! Deve estar no formato hh:mm e conter apenas numeros.\n");
        }
    } while (!horarioValido(rotas[qtdRotas].horarioChegada));

    qtdRotas++;
    printf("Rota adicionada com sucesso!\n");
}

void listarRotas()
{
    printf("Lista de Rotas:\n");
    for (int i = 0; i < qtdRotas; i++)
    {
        printf("%d. %s; Partida: %s, Chegada: %s\n", i + 1, rotas[i].rota, rotas[i].horarioPartida, rotas[i].horarioChegada);
    }
}

void excluirRota()
{
    int indice;
    listarRotas();
    printf("Digite o numero da rota a ser excluida: ");
    scanf("%d", &indice);
    if (indice < 1 || indice > qtdRotas)
    {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = indice - 1; i < qtdRotas - 1; i++)
    {
        rotas[i] = rotas[i + 1];
    }
    qtdRotas--;
    printf("Rota excluida com sucesso!\n");
}

void salvarRotasNoArquivo()
{
    FILE *arquivo = fopen(ARQUIVO_ROTAS, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!\n", ARQUIVO_ROTAS);
        return;
    }

    for (int i = 0; i < qtdRotas; i++)
    {
        fprintf(arquivo, "%s;%s;%s\n", rotas[i].rota, rotas[i].horarioPartida, rotas[i].horarioChegada);
    }

    fclose(arquivo);
}

void carregarRotasDoArquivo()
{
    FILE *arquivo = fopen(ARQUIVO_ROTAS, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!\n", ARQUIVO_ROTAS);
        return;
    }

    qtdRotas = 0;
    while (fscanf(arquivo, " %[^;];%[^;];%s", rotas[qtdRotas].rota, rotas[qtdRotas].horarioPartida, rotas[qtdRotas].horarioChegada) != EOF)
    {
        qtdRotas++;
    }

    fclose(arquivo);
}

void mostrarMenuPrincipal()
{
    printf("Menu Principal:\n");
    printf("1. Registrar motorista\n");
    printf("2. Registrar aluno\n");
    printf("3. Login motorista\n");
    printf("4. Login aluno\n");
    printf("5. Listar motoristas\n");
    printf("6. Listar alunos\n");
    printf("7. Listar rotas\n");
    printf("8. Sair\n");
}

void mostrarMenuAluno(const char *nomeAluno)
{
    printf("Bem-vindo, %s!\n", nomeAluno);
    printf("Menu do Aluno:\n");
    printf("1. Listar rotas\n");
    printf("2. Editar conta\n");
    printf("3. Excluir conta\n");
    printf("4. Sair\n");
}

void mostrarMenuMotorista(const char *nomeMotorista)
{
    printf("Bem-vindo, %s!\n", nomeMotorista);
    printf("Menu do Motorista:\n");
    printf("1. Adicionar rota\n");
    printf("2. Listar rotas\n");
    printf("3. Excluir rota\n");
    printf("4. Editar conta\n");
    printf("5. Excluir conta\n");
    printf("6. Sair\n");
}

void acoesMotorista(int indiceMotorista)
{
    int opcao;
    do
    {
        limparTela();
        mostrarMenuMotorista(motoristas[indiceMotorista].nome);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarRota();
            break;
        case 2:
            listarRotas();
            break;
        case 3:
            excluirRota();
            break;
        case 4:
            editarUsuario(&motoristas[indiceMotorista]);
            break;
        case 5:
            excluirUsuario(motoristas, &qtdMotoristas, indiceMotorista);
            opcao = 6;
            break;
        case 6:
            break;
        default:
            printf("Opcao invalida!\n");
        }
        if (opcao != 6)
        {
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
        }
    } while (opcao != 6);
}

void acoesAluno(int indiceAluno)
{
    int opcao;
    do
    {
        limparTela();
        mostrarMenuAluno(alunos[indiceAluno].nome);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listarRotas();
            break;
        case 2:
            editarUsuario(&alunos[indiceAluno]);
            break;
        case 3:
            excluirUsuario(alunos, &qtdAlunos, indiceAluno);
            opcao = 4;
            break;
        case 4:
            break;
        default:
            printf("Opcao invalida!\n");
        }
        if (opcao != 4)
        {
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
        }
    } while (opcao != 4);
}

int main()
{
    carregarUsuariosDoArquivo(motoristas, &qtdMotoristas, ARQUIVO_MOTORISTAS);
    carregarUsuariosDoArquivo(alunos, &qtdAlunos, ARQUIVO_ALUNOS);
    carregarRotasDoArquivo();

    int opcao;
    do
    {
        limparTela();
        mostrarMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario(motoristas, &qtdMotoristas, "motorista");
            break;
        case 2:
            cadastrarUsuario(alunos, &qtdAlunos, "aluno");
            break;
        case 3:
        {
            int indiceMotorista = loginUsuario(motoristas, qtdMotoristas, "motorista");
            if (indiceMotorista != -1)
            {
                acoesMotorista(indiceMotorista);
            }
            break;
        }
        case 4:
        {
            int indiceAluno = loginUsuario(alunos, qtdAlunos, "aluno");
            if (indiceAluno != -1)
            {
                acoesAluno(indiceAluno);
            }
            break;
        }
        case 5:
            listarUsuarios(motoristas, qtdMotoristas, "motoristas");
            break;
        case 6:
            listarUsuarios(alunos, qtdAlunos, "alunos");
            break;
        case 7:
            listarRotas();
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
        if (opcao != 8)
        {
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
        }
    } while (opcao != 8);

    salvarUsuariosNoArquivo(motoristas, qtdMotoristas, ARQUIVO_MOTORISTAS);
    salvarUsuariosNoArquivo(alunos, qtdAlunos, ARQUIVO_ALUNOS);
    salvarRotasNoArquivo();

    return 0;
}