#include "../headers/cliente.hpp"
#include "../headers/geral.hpp"
#include <iterator>

void Cliente::escolherLanche(std::map<std::string, float> sanduiches, std::map<std::string, float> sucos){

    std::string escolha;
    int opcao;
    bool check = true;
    

    while (check){
        std::cout << "\nDigite 1 para escolher um sanduiche ou 2 para escolher um suco." 
        << "\nDigite 0 para sair."
        << std::endl;
        std::cin >> opcao;

        if(opcao == 1){

            std::map<std::string, float>::iterator it;

            listarSanduiches(sanduiches);
            std::cout << "\nDigite o nome do sanduiche que deseja adicionar no carrinho: " << std::endl;
            
            std::cin >> escolha;

            it = sanduiches.find(escolha);

            if(it != sanduiches.end()){
                this->carrinho[it->first] = it->second;
                std::cout << "\nItem adicionado com sucesso." << std::endl;
            }
            else{
                throw std::runtime_error("Elemento não foi encontrado no cardapio");
            }
        }
        else if(opcao == 2){
            
            std::map<std::string, float>::iterator it;

            listarSucos(sucos);
            std::cout << "\nDigite o nome do suco que deseja adicionar no carrinho: " << std::endl;

            std::cin >> escolha;

            it = sucos.find(escolha);

            if(it != sucos.end()){
                this->carrinho[(*it).first] = (*it).second;
                std::cout << "\nItem adicionado com sucesso." << std::endl;
            }
            else{
                throw std::runtime_error("Elemento não foi encontrado no cardapio");
            }
        }
        else if(opcao == 0) check = false;
    }
    
}

void Cliente::verCarrinho(){
    std::map<std::string, float>::iterator it;

    std::cout << "\nMeu carrinho: " << std::endl;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); it++){
        std::cout << it->first << std::endl;
    }
}

float Cliente::valorCarrinho(){
    
    this->total = 0;

    for(auto it: this->carrinho){
        this->total += it.second;
    }

    return this->total;
}

void Cliente::excluirCarrinho(){

    std::string itemParaExcluir;
    
    std::cout << "Digite o nome do item que deseja excluir do carrinho: " << std::endl;
    for(auto it: this->carrinho){
        std::cout << it.first << std::endl;
    }

    std::cin >> itemParaExcluir;
    
    std::map<std::string, float>::iterator it = this->carrinho.find(itemParaExcluir);

    if (it != this->carrinho.end())
    {
        this->carrinho.erase(itemParaExcluir);
        std::cout << "\nItem excluido com sucesso!" << std::endl;
    }
    else{
        throw std::runtime_error("\nItem nao esta disponivel no carrinho.");
    }

}