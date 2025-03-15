#include<iostream>

int main(){
    std::string nome;
    std::string tensore;
    std::cout << "DIMMMI IL TUO NOME ";
    std::getline(std::cin, nome);


    std::cout << "COSA CAZZO è UN TENSORE? ";
    std::getline(std::cin, tensore);
    
    std::cout << "mi chiamo " << nome << " e secondo me un tensore è " << tensore <<std :: endl;
    return 0;
}

