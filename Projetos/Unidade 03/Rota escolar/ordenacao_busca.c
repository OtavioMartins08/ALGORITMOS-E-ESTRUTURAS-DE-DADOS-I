#include "ordenacao_busca.h"
#include <string.h>
#include <stdlib.h>

Usuario* dividir(Usuario* head)
{
    Usuario* slow = head;
    Usuario* fast = head->prox;

    while (fast && fast->prox)
    {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    Usuario* meio = slow->prox;
    slow->prox = NULL;

    return meio;
}

Usuario* merge(Usuario* left, Usuario* right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (strcmp(left->nome, right->nome) <= 0)
    {
        left->prox = merge(left->prox, right);
        return left;
    }
    else
    {
        right->prox = merge(left, right->prox);
        return right;
    }
}

Usuario* mergeSort(Usuario* head)
{
    if (!head || !head->prox)
        return head;

    Usuario* meio = dividir(head);
    Usuario* left = mergeSort(head);
    Usuario* right = mergeSort(meio);

    return merge(left, right);
}

void ordenarUsuariosPorNome(Usuario** usuarios)
{
    *usuarios = mergeSort(*usuarios);
}

Usuario* buscarUsuarioPorNome(Usuario* usuarios, const char* nome)
{
    Usuario* atual = usuarios;

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}
