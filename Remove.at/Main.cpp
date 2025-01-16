#include <iostream>
#include "arraydinamico.hpp"

int main(){
  arraydinamico lista;

  int x, y; 
  for (int i=0; i<5; i++){
    std::cin >> x;
    lista.push_back(x);
  }


  std::cin >> y;
  std::cout << lista.count(y);
 

  //for (int unsigned i = 0; i<lista.size(); i++){
    //std::cout << lista.get_at(i) << " ";
  //}
  //std::cout << lista.size();
  //for (unsigned int i = 0; i < lista.size() ;i++){
    //std::cout << lista.get_at(i);
  //}
  //std::cout << lista.percent_occupied();
  }
//
