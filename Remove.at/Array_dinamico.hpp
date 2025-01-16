#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
#include <stdexcept>  

class arraydinamico {
  private:
    int *lista;
    unsigned int size_, capacity_;
  void increase_capacity(){
      int *newarray = new int[capacity_+100];
      for (int unsigned i = 0; i<size_; i++){
        newarray[i] = lista[i];
      }
      delete [] lista;
      lista = newarray;
      capacity_= capacity_ + 100;
  }
  
public:
  arraydinamico(){ 
    size_ = 0;
    capacity_ = 100;
    this->lista = new int[capacity_];
    
      
  }
  ~arraydinamico(){
    delete [] lista;
  }

  unsigned int size(){
    return size_; 
  }

  unsigned int capacity(){
    return capacity_; 
  }

  double percent_occupied() {
    if (capacity_== 0){
      return 0.0; 
    }
    else {
      return (static_cast<double>(size_) / capacity_);  
        }
  }

  bool insert_at(int index, int value) {
    if (size_==capacity_){ 
      increase_capacity();
    }
    size_++; 
    for (int i=size_; i > index; i--){
      lista[i] = lista[i-1]; 
      }
      lista[index] = value; 
      return true; 
    }
    
  bool remove_at(int unsigned index){
    if (index >= size_){ 
      return false;
    }
    for (int unsigned i=index; i < size_; i++){
      lista[i] = lista[i+1]; 
    }
    size_--; 
    return true; 
  }

  void push_back(int value){
    if (this->size_ == this-> capacity_){
      increase_capacity(); 
    }
    this->lista[size_++] = value; 
  }

  void push_front(int unsigned value){
    if(size_==capacity_){ 
      increase_capacity();
    }
    size_++; 
    for (int unsigned i=0; i<size_-1; i++){
      lista[i + 1] = lista[i]; 
      
    }
    lista[0] = value;

  }

  int get_at(int unsigned index){
    if (index >= size_){ 
      return -1;
    }
    return lista[index]; 
   }

  bool pop_back(){
    if (size_==0){
      return false;
    }
    size_--; 
    return true;

    
  }
  
  bool pop_front(){
    remove_at(0); 
    return true;
  }

      
      
      
int back(){
  if (size_ == 0) {
    return -1;
  } 
  return lista[size_-1]; 
  }
    


  int front(){
  if (size_ == 0){
    return -1;
  }
  return lista[0]; 
  } 

  
bool remove(int value){
  int ind;
  for (int unsigned i=0; i <= size_-1; i++){
    if (value==lista[i]){ 
      ind = lista[i-1]; 
      remove_at(ind);
    }
  }
    return true;
  }  


  int find(int value) {
    for (unsigned int i = 0; i < size_; i++) {
      if (lista[i] == value) {
          return i; 
          break;
        }
    }
    return -1; 
  }

 




int count(int value) {
  int qtd = 0;
  for (int unsigned i=0; i<=size_; i++){
    if (value==lista[i]){ 
      qtd++; 
    }
  }
   return qtd;
  } 

  int sum() {
    int soma = 0;
    for (int unsigned i=0; i<size_; i++) {
      soma = soma + lista[i];  
    }
  return soma; 
  


  }
 };
#endif 
