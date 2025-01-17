#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

#include <iostream>
#include <stdexcept>

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next;
        int_node* prev;

        int_node(int val, int_node* n = nullptr, int_node* p = nullptr)
            : value(val), next(n), prev(p) {}
    };

    int_node* head;
    int_node* tail;
    unsigned int size_;

public:
    linked_list() : head(nullptr), tail(nullptr), size_(0) {}

    ~linked_list() {
        clear();
    }

    unsigned int size() const {
        return size_;
    }

    unsigned int capacity() const {
        return size_; // capacidade é o número de elementos na lista
    }

    double percent_occupied() const {
        return size_ > 0 ? 1.0 : 0.0; // sempre 100% ocupado se houver elementos
    }

    void push_front(int value) {
        int_node* new_node = new int_node(value, head);
        if (head) {
            head->prev = new_node;
        } else {
            tail = new_node;
        }
        head = new_node;
        ++size_;
    }

    void push_back(int value) {
        int_node* new_node = new int_node(value, nullptr, tail);
        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        ++size_;
    }

    bool pop_front() {
        if (!head) return false;
        int_node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --size_;
        return true;
    }

    bool pop_back() {
        if (!tail) return false;
        int_node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        --size_;
        return true;
    }

    bool insert_at(unsigned int index, int value) {
        if (index > size_) return false;

        if (index == 0) {
            push_front(value);
            return true;
        }

        if (index == size_) {
            push_back(value);
            return true;
        }

        int_node* current = head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }

        int_node* new_node = new int_node(value, current, current->prev);
        current->prev->next = new_node;
        current->prev = new_node;
        ++size_;
        return true;
    }

    bool remove_at(unsigned int index) {
        if (index >= size_) return false;

        if (index == 0) {
            return pop_front();
        }

        if (index == size_ - 1) {
            return pop_back();
        }

        int_node* current = head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        --size_;
        return true;
    }

    int get_at(unsigned int index) const {
        if (index >= size_) return -1;

        int_node* current = head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    void clear() {
        while (pop_front()) {}
    }

    int back() const {
        if (!tail) return -1;
        return tail->value;
    }

    int front() const {
        if (!head) return -1;
        return head->value;
    }

    int find(int value) const {
        int_node* current = head;
        unsigned int index = 0;
        while (current) {
            if (current->value == value) return index;
            current = current->next;
            ++index;
        }
        return -1;
    }

    int count(int value) const {
        int_node* current = head;
        int count = 0;
        while (current) {
            if (current->value == value) ++count;
            current = current->next;
        }
        return count;
    }

    int sum() const {
        int_node* current = head;
        int total = 0;
        while (current) {
            total += current->value;
            current = current->next;
        }
        return total;
    }
};

#endif // __LINKED_LIST_IFRN__

