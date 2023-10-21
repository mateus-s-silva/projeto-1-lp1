#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include "../headers/cardapio.hpp"


std::map<std::string, float> carregarSanduiches(){
    
    std::vector<std::string> linhas;
    std::string linha;
    std::map<std::string, float> cardapioSanduiches;
    
    std::fstream arquivo;
    arquivo.open("../lanches/sanduiches.txt");

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    while(std::getline(arquivo, linha)){
        linhas.push_back(linha);
    }

    for(size_t i = 0; i < linhas.size(); i += 2){
        cardapioSanduiches.insert(std::pair<std::string, float>(linhas[i], stof(linhas[i+1])));
    }

    return cardapioSanduiches;
}

std::map<std::string, float> carregarSucos(){
    
    std::vector<std::string> linhas;
    std::string linha;
    std::map<std::string, float> cardapioSucos;
    
    std::fstream arquivo;
    arquivo.open("../lanches/sucos.txt");

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo.");
    }

    while(std::getline(arquivo, linha)){
        linhas.push_back(linha);
    }

    for(size_t i = 0; i < linhas.size(); i += 2){
        cardapioSucos.insert(std::pair<std::string, float>(linhas[i], stof(linhas[i+1])));
    }

    return cardapioSucos;
}



