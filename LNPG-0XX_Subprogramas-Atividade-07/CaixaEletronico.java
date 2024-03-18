//O programa original é um simulador de caixa eletrônico simples. Ele permite ao usuário fazer saques, depósitos e verificar o saldo da conta. O programa mantém o saldo em uma variável global e solicita ao usuário que insira sua operação desejada (saque, depósito ou consulta de saldo) e o valor, se aplicável. 

import java.util.Scanner;
public class CaixaEletronico {
    static double saldo = 1000.00;


public static void PrintarOpcaoInvalida(){
    System.out.println("Opção inválida.");


}


public static void saldo(){
    System.out.println("Seu saldo atual é: R$" + saldo);
}


public static void RealizarDeposito(double valor){
    saldo += valor;
    System.out.println("Depósito de R$" + valor + " realizado.");
}


public static void deposito(){
    Scanner scanner = new Scanner(System.in);
    double valor;
    System.out.println("Digite o valor do depósito:");
    valor = scanner.nextDouble();
    RealizarDeposito(valor);
}


public static void CondicionalSaque(double valor){
        if (valor > saldo) {
            System.out.println("Saldo insuficiente.");
        } else {
            saldo -= valor;
            System.out.println("Saque de R$" + valor + " realizado.");
        }
    }


public static void saque(){
        double valor;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite o valor do saque:");
        valor = scanner.nextDouble();
        CondicionalSaque(valor);


    }


public static int EscolherOpcao(){
        Scanner scanner = new Scanner(System.in);
    	int opcao;
    	double valor;
    	System.out.println("Bem-vindo ao Caixa Eletrônico");
    	System.out.println("Seu saldo atual é: R$" + saldo);
    	System.out.println("Escolha uma opção:");
    	System.out.println("1 - Saque");
    	System.out.println("2 - Depósito");
    	System.out.println("3 - Consultar Saldo");
    	opcao = scanner.nextInt();

        return opcao;
    }


public static void menu(){
    	int opcao;
    	opcao = EscolherOpcao();

    	if (opcao == 1) {
        	saque();
    	} else if (opcao == 2) {
        	deposito();
    	} else if (opcao == 3) {
        	saldo();
    	} else {
            PrintarOpcaoInvalida();
    	}

    	
    }


public static void main(String[] args) {
        menu();
    }
}


