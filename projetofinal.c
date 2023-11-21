#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int codigoCliente;
    char nomeCliente[50];
    int numeroAgencia;
    char numeroContaCorrente[20];
    float saldoAtual;
} ContaCorrente;

void cadastrarCliente(ContaCorrente clientes[], int *totalClientes);
void depositar(ContaCorrente clientes[], int totalClientes, int codigoCliente, float valorDeposito);
void sacar(ContaCorrente clientes[], int totalClientes, int codigoCliente, float valorSaque);
void consultarSaldo(ContaCorrente clientes[], int totalClientes, int codigoCliente);
void listarClientes(ContaCorrente clientes[], int totalClientes);
void realizarTransacao(ContaCorrente clientes[], int totalClientes);

int main()
{
    ContaCorrente clientes[100];
    int totalClientes = 0;
    int opcao;

    do
    {
        printf("\n1 - Cadastrar Cliente\n2 - Realizar Transacao\n3 - Listar Clientes\n4 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarCliente(clientes, &totalClientes);
            break;
        case 2:
            realizarTransacao(clientes, totalClientes);
            break;
        case 3:
            listarClientes(clientes, totalClientes);
            break;
        case 4:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}

void cadastrarCliente(ContaCorrente clientes[], int *totalClientes)
{
    ContaCorrente novoCliente;
    printf("\nDigite o codigo do cliente: ");
    scanf("%d", &novoCliente.codigoCliente);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novoCliente.nomeCliente);
    printf("Digite o numero da agencia: ");
    scanf("%d", &novoCliente.numeroAgencia);
    printf("Digite o numero da conta corrente: ");
    scanf("%19s", novoCliente.numeroContaCorrente);
    printf("Digite o saldo atual: ");
    scanf("%f", &novoCliente.saldoAtual);

    clientes[*totalClientes] = novoCliente;
    (*totalClientes)++;
}

void depositar(ContaCorrente clientes[], int totalClientes, int codigoCliente, float valorDeposito)
{
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigoCliente == codigoCliente)
        {
            clientes[i].saldoAtual += valorDeposito;
            printf("\nDeposito realizado com sucesso!\n");
            return;
        }
    }
    printf("\nCliente nao encontrado.\n");
}

void sacar(ContaCorrente clientes[], int totalClientes, int codigoCliente, float valorSaque)
{
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigoCliente == codigoCliente)
        {
            if (clientes[i].saldoAtual >= valorSaque)
            {
                clientes[i].saldoAtual -= valorSaque;
                printf("\nSaque realizado com sucesso!\n");
                return;
            }
            else
            {
                printf("\nSaldo insuficiente para realizar o saque.\n");
                return;
            }
        }
    }
    printf("\nCliente nao encontrado.\n");
}

void consultarSaldo(ContaCorrente clientes[], int totalClientes, int codigoCliente)
{
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigoCliente == codigoCliente)
        {
            printf("\nSaldo atual: %.2f\n", clientes[i].saldoAtual);
            return;
        }
    }
    printf("\nCliente nao encontrado.\n");
}

void listarClientes(ContaCorrente clientes[], int totalClientes)
{
    printf("\nListagem de Clientes:\n");
    for (int i = 0; i < totalClientes; i++)
    {
        printf("Cliente %d:\n", i + 1);
        printf("Codigo: %d\n", clientes[i].codigoCliente);
        printf("Nome: %s\n", clientes[i].nomeCliente);
        printf("Agencia: %d\n", clientes[i].numeroAgencia);
        printf("Conta Corrente: %s\n", clientes[i].numeroContaCorrente);
        printf("Saldo: %.2f\n", clientes[i].saldoAtual);
        printf("\n");
    }
}

void realizarTransacao(ContaCorrente clientes[], int totalClientes)
{
    int codigoCliente;
    int opcaoTransacao;
    float valorDeposito, valorSaque;

    printf("\nDigite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigoCliente == codigoCliente)
        {
            printf("\n1 - Depositar\n2 - Sacar\n3 - Consultar Saldo\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &opcaoTransacao);

            switch (opcaoTransacao)
            {
            case 1:
                printf("\nDigite o valor do deposito: ");
                scanf("%f", &valorDeposito);
                depositar(clientes, totalClientes, codigoCliente, valorDeposito);
                break;
            case 2:
                printf("\nDigite o valor do saque: ");
                scanf("%f", &valorSaque);
                sacar(clientes, totalClientes, codigoCliente, valorSaque);
                break;
            case 3:
                consultarSaldo(clientes, totalClientes, codigoCliente);
                break;
            default:
                printf("\nOpcao invalida.\n");
            }
            return;
        }
    }
    printf("\nCliente nao encontrado.\n");
}
