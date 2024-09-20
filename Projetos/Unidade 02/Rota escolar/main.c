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
    carregarUsuariosDoArquivo(motoristas, &qtdMotoristas, ARQUIVO_MOTORISTAS);
    carregarUsuariosDoArquivo(alunos, &qtdAlunos, ARQUIVO_ALUNOS);
    carregarRotasDoArquivo();

    ordenarUsuariosPorNome(motoristas, qtdMotoristas);
    ordenarUsuariosPorNome(alunos, qtdAlunos);

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
            ordenarUsuariosPorNome(motoristas, qtdMotoristas);
            break;
        case 2:
            cadastrarUsuario(alunos, &qtdAlunos, "aluno");
            ordenarUsuariosPorNome(alunos, qtdAlunos);
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
