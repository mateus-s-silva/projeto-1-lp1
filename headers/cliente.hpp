#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <map>

class Cliente {

    private:
    float total = 0;
    std::map<std::string, float> carrinho;


    public: 
    void escolherLanche(std::map<std::string, float>, std::map<std::string, float>);
    void verCarrinho();
    float valorCarrinho();   
    void excluirCarrinho();

};

#endif