#include <iostream>
#include <string>
#include <vector>

struct Cliente {
    int codigo;
    std::string nome;
    int numeroAgencia;
    std::string numeroConta;
    float saldo;
};

void cadastrarCliente(std::vector<Cliente> &clientes, int &totalClientes) {
    Cliente novoCliente;
    std::cout << "Codigo do cliente: ";
    std::cin >> novoCliente.codigo;
    std::cin.ignore();
    std::cout << "Nome do cliente: ";
    std::getline(std::cin, novoCliente.nome);
    std::cout << "Numero da agencia: ";
    std::cin >> novoCliente.numeroAgencia;
    std::cin.ignore();
    std::cout << "Numero da conta corrente: ";
    std::getline(std::cin, novoCliente.numeroConta);
    std::cout << "Saldo atual: ";
    std::cin >> novoCliente.saldo;
    std::cin.ignore();

    clientes.push_back(novoCliente);
    totalClientes++;
}

void exibirClientes(const std::vector<Cliente> &clientes, int totalClientes) {
    for (int i = 0; i < totalClientes; i++) {
        std::cout << "\nCodigo do cliente: " << clientes[i].codigo << std::endl;
        std::cout << "Nome do cliente: " << clientes[i].nome << std::endl;
        std::cout << "Numero da agencia: " << clientes[i].numeroAgencia << std::endl;
        std::cout << "Numero da conta corrente: " << clientes[i].numeroConta << std::endl;
        std::cout << "Saldo atual: " << clientes[i].saldo << std::endl;
    }
}

// Restante do código similar às funções em C++...

int main() {
    int opcao = 0;
    int totalClientes = 0;
    std::vector<Cliente> clientes;

    // Implementação do menu em C++
    // Restante do código similar ao caso do C...
}
