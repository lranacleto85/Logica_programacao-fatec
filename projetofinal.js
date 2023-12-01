const readline = require('readline');

class Cliente {
    constructor() {
        this.codigo = 0;
        this.nome = '';
        this.numeroAgencia = 0;
        this.numeroConta = '';
        this.saldo = 0.0;
    }
}

function cadastrarCliente(clientes, totalClientes) {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question("Codigo do cliente: ", codigo => {
        clientes[totalClientes].codigo = parseInt(codigo);
        rl.question("Nome do cliente: ", nome => {
            clientes[totalClientes].nome = nome;
            rl.question("Numero da agencia: ", agencia => {
                clientes[totalClientes].numeroAgencia = parseInt(agencia);
                rl.question("Numero da conta corrente: ", conta => {
                    clientes[totalClientes].numeroConta = conta;
                    rl.question("Saldo atual: ", saldo => {
                        clientes[totalClientes].saldo = parseFloat(saldo);
                        totalClientes++;
                        rl.close();
                    });
                });
            });
        });
    });
}

function exibirClientes(clientes, totalClientes) {
    for (let i = 0; i < totalClientes; i++) {
        console.log(`\nCodigo do cliente: ${clientes[i].codigo}`);
        console.log(`Nome do cliente: ${clientes[i].nome}`);
        console.log(`Numero da agencia: ${clientes[i].numeroAgencia}`);
        console.log(`Numero da conta corrente: ${clientes[i].numeroConta}`);
        console.log(`Saldo atual: ${clientes[i].saldo.toFixed(2)}\n`);
    }
}

// Restante do código similar às funções em JavaScript...

let opcao = 0;
let totalClientes = 0;
const clientes = Array(100).fill(new Cliente());

// Implementação do menu em JavaScript
// Restante do código similar ao caso do C++...
