#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
class Lista_ligada {
private:
struct int_node {
        int value;
        int_node* next;
        int_node* prev; 
};
    int_node* head;
    int_node* tail;
    unsigned int size_;
public:
    Lista_ligada() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~Lista_ligada() {
        int_node *atual = this->head;
        int_node *i;
        while (atual != nullptr){
        i = atual;
        atual = atual->next;
        delete  i;
        }
    }
    unsigned int size() {
        return this->size_;
    }
    bool insert_at(unsigned int index, int value) {} 
    bool remove_at(unsigned int index) {} 
    int get_at(unsigned int index) { 
        int retorno;
        if (index >= size_) retorno =  -1;
        else {
        int_node *atual = this->head;
        for (int i = 0; i < index ;i++) atual = atual->next;    
        retorno =  atual->value; 
        }
        return retorno;
    } 

    void clear() { 
        int_node *atual = this->head;
        int_node *i;
        while (atual != nullptr){
        i = atual;
        atual = atual->next;
        delete  i;
        }
    } 
    void push_back(int value) { 
        int_node *novo_no = new int_node;
        novo_no->value = value;
        novo_no->next = nullptr;
        novo_no->prev = this->tail;
        if (this->head == nullptr) this->head = novo_no;
        else this->tail->next = novo_no;
        this->tail = novo_no;
        size_++;
    } 

    void push_front(int value) { 
        int_node *novo_no = new int_node;
        novo_no->value = value;
        novo_no->next = head;
        novo_no->prev = nullptr;
        if (this->head == nullptr) this->tail = novo_no;
        else this->head->prev = novo_no;
        this->head = novo_no;
        size_++;
    } 
    bool pop_back() { 
     int retorno = true;
        if (this->tail == nullptr) retorno = false;
        int_node *atual = this->tail;
        this->tail = this->tail->prev;
        atual = atual->prev;
        size_--;
        return retorno;
    } 
    bool pop_front() { 
       int retorno = true;
        if (this->tail == nullptr) retorno = false;
        int_node *atual = this->head;
        this->head = this->head->next;
        atual = atual->next;
        size_--;
        return retorno;
    } 
    int back(){ 
            if (this->head == nullptr) return -1;
            return this->head->value;
    } 
    int front(){ 
            if (this->tail == nullptr) return -1;
            return this->tail->value;
    } 
    bool remove(int value) {} 
    int find(int value) { 
        int encontrou = -1, pos = 0;
        int_node *atual =  this->tail;
        while (atual != nullptr){
            if (atual->value == value) {
                encontrou = pos;
                break;
            }
        atual = atual->next; 
        pos++;
        }
        return encontrou;
    } 
    int count(int value) { 
        int cont = 0;
        int_node *atual = this->head;
        while (atual != nullptr){
            if (atual->value == value) cont++;
        atual = atual->next;  
        }
        return cont;
    } 
    int sum() { 
        int soma = 0;
        int_node *atual = this->head;
        while(atual != nullptr){
            soma = soma + atual->value; 
            atual = atual->next; 
        }
        return soma ;
    } 
};
#endif // __LINKED_LIST_IFRN__
