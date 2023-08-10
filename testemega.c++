#include <iostream> // DANIELE RAMOS E TAYNA MARIOH
#include <vector>
#include <random>
#include <algorithm>
#include <set>

// Função para realizar o sorteio de números aleatórios
std::vector<int> realizarSorteio(int quantidade) { // Quantidade de números para o sorteio
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 60); // Distribuição de números

    std::set<int> numerosSorteados; // Números que foram sorteados
    while (numerosSorteados.size() < quantidade) {
        int numero = dis(gen);
        numerosSorteados.insert(numero);
    }
    return std::vector<int>(numerosSorteados.begin(), numerosSorteados.end());
}

// Função para obter os números escolhidos pelo jogador
std::vector<int> obterNumerosEscolhidos() { 
    std::vector<int> numerosEscolhidos;
    for (int i = 0; i < 6; ++i) { 
        int numero;
        do {
            std::cout << "Escolha o " << i + 1 << "º número (1-60): ";
            std::cin >> numero;
        } while (numero < 1 || numero > 60 || std::find(numerosEscolhidos.begin(), numerosEscolhidos.end(), numero) != numerosEscolhidos.end());

        numerosEscolhidos.push_back(numero);
    }
    return numerosEscolhidos;
}

// Função para comparar os números escolhidos com os sorteados
int compararNumeros(const std::vector<int>& escolhidos, const std::vector<int>& sorteados) {
    int acertos = 0;
    for (int num : escolhidos) {
        if (std::find(sorteados.begin(), sorteados.end(), num) != sorteados.end()) {
            acertos++;
        }
    }
    return acertos;
}

void imprimirNumeros(const std::vector<int>& numeros) { // Imprimir números da Mega
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Bem-vindo ao Mega Senai!" << std::endl; // Inicialização da Mega Sena

    while (true) {
        std::vector<int> numerosEscolhidos = obterNumerosEscolhidos(); // Números escolhidos pelo jogador
        std::vector<int> numerosSorteados = realizarSorteio(6); // Números que serão sorteados

        int acertos = compararNumeros(numerosEscolhidos, numerosSorteados);

        if (acertos == 6) {
            std::cout << "Parabéns! Você acertou todos os números." << std::endl; 
            break;
        } else {
            std::cout << "Números sorteados: ";
            imprimirNumeros(numerosSorteados);
            std::cout << "Você acertou " << acertos << " números. Tente novamente." << std::endl; // Total de acertos pelo jogador
        }

        char escolha;
        std::cout << "Deseja jogar novamente? (S/N): "; // Escolha do jogador para tentar novamente
        std::cin >> escolha;
        if (escolha != 'S' && escolha != 's') {
            std::cout << "Obrigado por jogar o jogo Mega Senai!" << std::endl; 
            break;
        }
    }

    return 0;
}