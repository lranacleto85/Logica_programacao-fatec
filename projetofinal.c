// Projeto Final - Leonardo Ramos Anacleto

//********************************
//**ATIVIDADE –PROJETO BANCÁRIO**
//********************************

//Objetivo:Elaborar um algoritmo para possibilitargestão de informações bancárias. 
//Requisito básico para o  desenvolvimento  do  projeto:
//Utilizar  menu  para  o  usuário  navegar no  sistema,  sempre  possibilitando  acesso  ao  menuprincipal.
//O  menu  de  opções deverá permitir  o  usuário sacar,  depositar, efetuar  pix,  cadastrar  novo  cliente, transferir  dinheiro entre  contas e consultarsaldo.
//(A  consulta  deverá  apresentar informação  da  contade  um cliente específico ou de todas as contas cadastradas).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[100];
    int numeroAgencia;
    char numeroConta[100];
    float saldo;
} Cliente;

void cadastrarCliente(Cliente *clientes, int *totalClientes)
{
    printf("Codigo do cliente: ");
    scanf("%d", &clientes[*totalClientes].codigo);
    getchar();
    printf("Nome do cliente: ");
    fgets(clientes[*totalClientes].nome, 100, stdin);
    printf("Numero da agencia: ");
    scanf("%d", &clientes[*totalClientes].numeroAgencia);
    getchar();
    printf("Numero da conta corrente: ");
    fgets(clientes[*totalClientes].numeroConta, 100, stdin);
    printf("Saldo atual: ");
    scanf("%f", &clientes[*totalClientes].saldo);
    getchar();
    (*totalClientes)++;
}

void exibirClientes(Cliente *clientes, int totalClientes)
{
    for (int i = 0; i < totalClientes; i++)
    {
        printf("\nCodigo do cliente: %d", clientes[i].codigo);
        printf("\nNome do cliente: %s", clientes[i].nome);
        printf("\nNumero da agencia: %d", clientes[i].numeroAgencia);
        printf("\nNumero da conta corrente: %s", clientes[i].numeroConta);
        printf("\nSaldo atual: %.2f\n", clientes[i].saldo);
    }
}

void sacar(Cliente *clientes, int totalClientes, int codigoCliente, float valor)
{
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigo == codigoCliente)
        {
            if (clientes[i].saldo >= valor)
            {
                clientes[i].saldo -= valor;
                printf("Saque realizado com sucesso!\n");
            }
            else
            {
                printf("Saldo insuficiente para saque!\n");
            }
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void depositar(Cliente *clientes, int totalClientes, int codigoCliente, float valor)
{
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigo == codigoCliente)
        {
            clientes[i].saldo += valor;
            printf("Deposito realizado com sucesso!\n");
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void transferir(Cliente *clientes, int totalClientes, int codigoOrigem, int codigoDestino, float valor)
{
    int clienteOrigem = -1, clienteDestino = -1;
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigo == codigoOrigem)
        {
            clienteOrigem = i;
        }
        if (clientes[i].codigo == codigoDestino)
        {
            clienteDestino = i;
        }
    }

    if (clienteOrigem != -1 && clienteDestino != -1)
    {
        if (clientes[clienteOrigem].saldo >= valor)
        {
            clientes[clienteOrigem].saldo -= valor;
            clientes[clienteDestino].saldo += valor;
            printf("Transferencia realizada com sucesso!\n");
        }
        else
        {
            printf("Saldo insuficiente para transferencia!\n");
        }
    }
    else
    {
        printf("Cliente(s) nao encontrado(s)!\n");
    }
}

void pix(Cliente *clientes, int totalClientes, int codigoOrigem, char numeroContaDestino[100], float valor)
{
    int clienteOrigem = -1, clienteDestino = -1;
    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigo == codigoOrigem)
        {
            clienteOrigem = i;
        }
        if (strcmp(clientes[i].numeroConta, numeroContaDestino) == 0)
        {
            clienteDestino = i;
        }
    }

    if (clienteOrigem != -1 && clienteDestino != -1)
    {
        if (clientes[clienteOrigem].saldo >= valor)
        {
            clientes[clienteOrigem].saldo -= valor;
            clientes[clienteDestino].saldo += valor;
            printf("PIX realizado com sucesso!\n");
        }
        else
        {
            printf("Saldo insuficiente para PIX!\n");
        }
    }
    else
    {
        printf("Cliente(s) nao encontrado(s)!\n");
    }
}

void consultarSaldo(Cliente *clientes, int totalClientes, int codigoCliente)
{
    int opcaoConsulta;
    printf("\n1. Consultar saldo de um cliente específico");
    printf("\n2. Consultar saldo de todos os clientes");
    printf("\nOpcao: ");
    scanf("%d", &opcaoConsulta);
    getchar();

    switch (opcaoConsulta)
    {
    case 1:
        for (int i = 0; i < totalClientes; i++)
        {
            if (clientes[i].codigo == codigoCliente)
            {
                printf("Saldo atual do cliente %s: %.2f\n", clientes[i].nome, clientes[i].saldo);
                return;
            }
        }
        printf("Cliente nao encontrado!\n");
        break;
    case 2:
        printf("Saldo de todos os clientes:\n");
        for (int i = 0; i < totalClientes; i++)
        {
            printf("Codigo do cliente: %d | Nome: %s | Saldo: %.2f\n", clientes[i].codigo, clientes[i].nome, clientes[i].saldo);
        }
        break;
    default:
        printf("Opcao invalida!\n");
    }
}

int main()
{
    int opcao;
    int totalClientes = 0;
    Cliente clientes[100];

    do
    {
        printf("\nMenu:");
        printf("\n1. Cadastrar cliente");
        printf("\n2. Exibir clientes");
        printf("\n3. Sacar");
        printf("\n4. Depositar");
        printf("\n5. Transferir");
        printf("\n6. PIX");
        printf("\n7. Consultar saldo");
        printf("\n8. Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarCliente(clientes, &totalClientes);
            break;
        case 2:
            exibirClientes(clientes, totalClientes);
            break;
        case 3:
        {
            int codigoSaque;
            float valorSaque;
            printf("Digite o codigo do cliente: ");
            scanf("%d", &codigoSaque);
            printf("Digite o valor a sacar: ");
            scanf("%f", &valorSaque);
            sacar(clientes, totalClientes, codigoSaque, valorSaque);
        }
        break;
        case 4:
        {
            int codigoDeposito;
            float valorDeposito;
            printf("Digite o codigo do cliente: ");
            scanf("%d", &codigoDeposito);
            printf("Digite o valor a depositar: ");
            scanf("%f", &valorDeposito);
            depositar(clientes, totalClientes, codigoDeposito, valorDeposito);
        }
        break;
        case 5:
        {
            int codigoOrigem, codigoDestino;
            float valorTransferencia;
            printf("Digite o codigo do cliente de origem: ");
            scanf("%d", &codigoOrigem);
            printf("Digite o codigo do cliente de destino: ");
            scanf("%d", &codigoDestino);
            printf("Digite o valor a transferir: ");
            scanf("%f", &valorTransferencia);
            transferir(clientes, totalClientes, codigoOrigem, codigoDestino, valorTransferencia);
        }
        break;
        case 6:
        {
            int codigoOrigem;
            char numeroContaDestino[100];
            float valorPix;
            printf("Digite o codigo do cliente de origem: ");
            scanf("%d", &codigoOrigem);
            getchar();
            printf("Digite o numero da conta de destino: ");
            fgets(numeroContaDestino, 100, stdin);
            printf("Digite o valor do PIX: ");
            scanf("%f", &valorPix);
            pix(clientes, totalClientes, codigoOrigem, numeroContaDestino, valorPix);
        }
        break;
        case 7:
        {
            int codigoConsulta;
            printf("Digite o codigo do cliente para consultar saldo: ");
            scanf("%d", &codigoConsulta);
            consultarSaldo(clientes, totalClientes, codigoConsulta);
        }
        break;
        case 8:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
