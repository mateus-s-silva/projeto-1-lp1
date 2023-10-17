#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include "../classes/lanches/lanche.hpp"
#include "cliente.hpp"

std::vector<Lanche> carrinho;
std::vector<std::string> sanduiches;
std::vector<std::string> sucos;


void listarSanduiches(){
    
    std::vector<std::string> linhas;
    std::string linha;
    int k = 0;

    std::fstream arquivo;
    arquivo.open("../lanches/sucos.txt");

    if (!arquivo.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo." << std::endl;
        return;
    }

    while(std::getline(arquivo, linha)){
        linhas.push_back(linha);
    }

    arquivo.close();

    for (size_t i = 0; i < linhas.size(); i++)
    {
        std::cout << "Sanduiches: \n" 
                  << i+1 << ": " << linhas[i + k++] << " - Valor: " << stof(linhas[i + 1]) << std::endl;
    }

}
