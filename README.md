#Algoritimos
# Projeto: Implementação de Estruturas Dinâmicas
- Aluna: Tâmara Thais
- Curso: Análise e Desenvolvimento de Sistemas
- Professor: Jorgiano Vidal
## Descrição

Neste repositório contém implementações de estruturas de dados dinâmicas em C++, especificamente de um vetor dinâmico e uma lista duplamente ligada. Essas estruturas são fundamentais para a manipulação eficiente de dados, permitindo operações como inserção, remoção e acesso a elementos de forma dinâmica.

## Implementações

- **Vetor Dinâmico (`array_list.hpp`)**:
  - Implementa um array que pode ser redimensionado dinamicamente conforme a necessidade.
  - Métodos principais:
    - `push_back()`: Adiciona um elemento ao final do vetor.
    - `pop_back()`: Remove o último elemento do vetor.
    - `insert()`: Insere um elemento em uma posição específica.
    - `erase()`: Remove um elemento de uma posição específica.
    - `operator[]`: Acesso a elementos por índice.
    - `size()`: Retorna o número de elementos no vetor.
    - `capacity()`: Retorna a capacidade atual do vetor.
    - `clear()`: Remove todos os elementos do vetor.

- **Lista Duplamente Ligada (`linked_list.hpp`)**:
  - Implementa uma lista onde cada nó possui ponteiros para o próximo e o anterior, permitindo navegação bidirecional.
  - Métodos principais:
    - `push_front()`: Adiciona um elemento no início da lista.
    - `push_back()`: Adiciona um elemento no final da lista.
    - `pop_front()`: Remove o primeiro elemento da lista.
    - `pop_back()`: Remove o último elemento da lista.
    - `insert()`: Insere um elemento em uma posição específica.
    - `erase()`: Remove um elemento de uma posição específica.
    - `size()`: Retorna o número de elementos na lista.
    - `clear()`: Remove todos os elementos da lista.

## Requisitos

- **Linguagem**: C++
- **Compilador**: GCC ou qualquer outro compatível com C++17.

## Como Compilar e Executar os Testes

1. **Clone o repositório**:

   ```bash
   git clone https://github.com/rubythais/arraydinamico_Algoritimos.git
   cd arraydinamico_Algoritimos
