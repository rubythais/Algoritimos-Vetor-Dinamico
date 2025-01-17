#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <iostream>
#include <stdexcept>
#include <cmath>

class array_list {
private:
    int* data;
    unsigned int size_;
    unsigned int capacity_;

    // Método para aumentar a capacidade do array
    void increase_capacity() {
        unsigned int new_capacity = capacity_ + 100; // Incremento padrão de 100
        int* new_data = new int[new_capacity];
        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    // Construtor
    array_list() : data(new int[100]), size_(0), capacity_(100) {}

    // Destrutor
    ~array_list() {
        delete[] data;
    }

    // Retorna a quantidade de elementos armazenados
    unsigned int size() const {
        return size_;
    }

    // Retorna a capacidade atual do array
    unsigned int capacity() const {
        return capacity_;
    }

    // Retorna o percentual de memória ocupada
    double percent_occupied() const {
        return static_cast<double>(size_) / capacity_;
    }

    // Insere elemento no índice especificado
    bool insert_at(unsigned int index, int value) {
        if (index > size_) return false;
        if (size_ == capacity_) increase_capacity();
        for (unsigned int i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
        return true;
    }

    // Remove elemento no índice especificado
    bool remove_at(unsigned int index) {
        if (index >= size_) return false;
        for (unsigned int i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
        return true;
    }

    // Retorna elemento no índice especificado
    int get_at(unsigned int index) const {
        if (index >= size_) return -1;
        return data[index];
    }

    // Remove todos os elementos
    void clear() {
        size_ = 0;
    }

    // Adiciona elemento no final
    void push_back(int value) {
        if (size_ == capacity_) increase_capacity();
        data[size_++] = value;
    }

    // Adiciona elemento no início
    void push_front(int value) {
        insert_at(0, value);
    }

    // Remove elemento do final
    bool pop_back() {
        if (size_ == 0) return false;
        --size_;
        return true;
    }

    // Remove elemento do início
    bool pop_front() {
        return remove_at(0);
    }

    // Retorna o elemento do final
    int back() const {
        if (size_ == 0) return -1;
        return data[size_ - 1];
    }

    // Retorna o elemento do início
    int front() const {
        if (size_ == 0) return -1;
        return data[0];
    }

    // Remove a primeira ocorrência de um valor
    bool remove(int value) {
        int index = find(value);
        if (index == -1) return false;
        return remove_at(index);
    }

    // Retorna o índice de um valor
    int find(int value) const {
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    // Retorna o número de ocorrências de um valor
    int count(int value) const {
        int count = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) ++count;
        }
        return count;
    }

    // Retorna a soma dos elementos
    int sum() const {
        int total = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            total += data[i];
        }
        return total;
    }
};

#endif // __ARRAY_LIST_IFRN__
 
  


  }
 };
#endif 
