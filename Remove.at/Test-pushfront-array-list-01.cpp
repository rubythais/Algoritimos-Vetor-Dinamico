#include <iostream>
#include <chrono>
#include "arraydinamico.hpp"

int main() {
    arraydinamico l1; // Cria uma instância da classe arraydinamico
    int n; // Declara uma variável para armazenar o número de elementos
    std::cin >> n; // Lê o número de elementos que serão inseridos

    auto beg = std::chrono::high_resolution_clock::now(); // Marca o tempo de início

    // Insere n elementos no início do vetor
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x; // Lê o valor do próximo elemento
        l1.push_front(x); // Insere o elemento no início do vetor
    }

    auto end = std::chrono::high_resolution_clock::now(); // Marca o tempo de fim
    auto elapsed = end - beg; // Calcula o tempo decorrido

    // Verifica se o número de elementos no vetor é igual a n
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n"; // Se o tamanho não for igual a n, imprime uma mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }

    // Imprime o tempo decorrido para as inserções
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;

    return 0; // Encerra o programa com sucesso
}
