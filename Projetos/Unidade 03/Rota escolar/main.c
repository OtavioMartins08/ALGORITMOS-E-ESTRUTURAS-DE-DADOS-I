#include "usuarios.h"
#include "rotas.h"
#include "arquivos.h"
#include "ordenacao_busca.h"

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

int main()
{
    extern Usuario *motoristas;
    extern Usuario *alunos;
    extern int qtdMotoristas, qtdAlunos;

    printf("Carregando motoristas do arquivo...\n");
    carregarUsuariosDoArquivo(&motoristas, &qtdMotoristas, ARQUIVO_MOTORISTAS);

    printf("Carregando alunos do arquivo...\n");
    carregarUsuariosDoArquivo(&alunos, &qtdAlunos, ARQUIVO_ALUNOS);

    printf("Carregando rotas do arquivo...\n");
    carregarRotasDoArquivo();

    ordenarUsuariosPorNome(&motoristas);
    ordenarUsuariosPorNome(&alunos);

    int opcao;
    do
    {
        limparTela();
        mostrarMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarUsuario(&motoristas, "motorista");
            ordenarUsuariosPorNome(&motoristas);
            break;
        case 2:
            cadastrarUsuario(&alunos, "aluno");
            ordenarUsuariosPorNome(&alunos);
            break;
        case 3:
        {
            Usuario *motoristaLogado = loginUsuario(motoristas, "motorista");
            if (motoristaLogado != NULL)
            {
                acoesMotorista(motoristaLogado);
            }
            break;
        }
        case 4:
        {
            Usuario *alunoLogado = loginUsuario(alunos, "aluno");
            if (alunoLogado != NULL)
            {
                acoesAluno(alunoLogado);
            }
            break;
        }
        case 5:
            listarUsuarios(motoristas, "motoristas");
            break;
        case 6:
            listarUsuarios(alunos, "alunos");
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
            printf("Pressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 8);

    salvarUsuariosNoArquivo(motoristas, ARQUIVO_MOTORISTAS);
    salvarUsuariosNoArquivo(alunos, ARQUIVO_ALUNOS);
    salvarRotasNoArquivo();

    return 0;
}
