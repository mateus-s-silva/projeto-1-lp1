#include "../headers/gerente.hpp"
#include "../headers/cardapio.hpp"
#include "../headers/geral.hpp"
#include <iostream>
#include <fstream>
#include <map>

void adicionarSanduiche(std::map<std::string, float> &sanduiches){
    
    std::string sanduiche;
    std::fstream arquivo;
    float valor;

    arquivo.open("../lanches/sanduiches.txt", std::ios::app);

    arquivo << '\n';

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    std::cout << "Digite o nome do sanduiche que deseja adicionar: " << std::endl;
    
    std::cin.ignore();
    std::getline(std::cin, sanduiche);

    arquivo << sanduiche << '\n';
    
    std::cout << "Digite o valor do sanduiche que deseja adicionar: " << std::endl;
    std::cin >> valor;

    arquivo << valor;
 
    std::cout << "\nSanduiche adicionado com sucesso!" << std::endl;

    arquivo.close();
    sanduiches = carregarSanduiches();

}

void adicionarSuco(std::map<std::string, float> &sucos){
    std::string suco;
    std::fstream arquivo;
    float valor;

    arquivo.open("../lanches/sucos.txt", std::ios::app);

    arquivo << '\n';

    if(!arquivo.is_open()){
        std::cout << "Nao ta abrindo papai" << std::endl;
    }

    std::cout << "Digite o nome do sanduiche que deseja adicionar: " << std::endl;
    
    std::cin.ignore();
    std::getline(std::cin, suco);

    arquivo << suco << '\n';
    
    std::cout << "Digite o valor do sanduiche que deseja adicionar: " << std::endl;
    std::cin >> valor;

    arquivo << valor;
 
    std::cout << "\nSanduiche adicionado com sucesso!" << std::endl;

    arquivo.close();
    sucos = carregarSanduiches();
}

void alteraPrecoSanduiche(std::map<std::string, float> &sanduiches){

    std::string sanduiche;
    std::map<std::string, float>::iterator it;
    float valor;


    std::cout << "\nDigite o nome do sanduiche que deseja alterar o preco: " << std::endl;

    listarSanduiches(sanduiches);
    
    std::cin >> sanduiche;
    it = sanduiches.find(sanduiche);

    if(it != sanduiches.end()){

        std::cout << "\nDigite o novo valor do sanduiche: " << std::endl;
        std::cin >> valor;

        sanduiches[sanduiche] = valor;

        std::fstream arquivo("../lanches/sanduiches.txt", std::ios::out | std::ios::trunc);
        
        if(!arquivo.is_open()){
            std::cout << "Nao ta abrindo papai" << std::endl;
        }
        

        it = sanduiches.begin();

        while(it != sanduiches.end()){
            
            arquivo << it->first << '\n';
            arquivo << it->second;
            if (std::next(it) != sanduiches.end()) {
                arquivo << '\n';
            }
            it++;
        }
        arquivo.close();
        std::cout << "\nPreco alterado com sucesso" << std::endl;
    }
    else{
        throw std::runtime_error("Este sanduiche nao existe na lista.");
    }

}

void alteraPrecoSuco(std::map<std::string, float> &sucos){

    std::string suco;
    std::map<std::string, float>::iterator it;
    float valor;


    std::cout << "\nDigite o nome do suco que deseja alterar o preco: \n" << std::endl;

    listarSucos(sucos);
    
    std::cin >> suco;
    it = sucos.find(suco);

    if(it != sucos.end()){

        std::cout << "\nDigite o novo valor do sanduiche: " << std::endl;
        std::cin >> valor;

        sucos[suco] = valor;

        std::fstream arquivo("../lanches/sucos.txt", std::ios::out | std::ios::trunc);

        if(!arquivo.is_open()){
            std::cout << "Nao ta abrindo papai" << std::endl;
        }
        

        it = sucos.begin();

        while(it != sucos.end()){
            
            arquivo << it->first << '\n';
            arquivo << it->second;
            if (std::next(it) != sucos.end()) {
                arquivo << '\n';
            }
            it++;
        }
        arquivo.close();
        std::cout << "\nPreco alterado com sucesso" << std::endl;
    }
    else{
        throw std::runtime_error("Este suco nao existe na lista.");
    }
}

void excluiSanduiche(std::map<std::string, float> &sanduiches){

    std::string sanduiche;
    std::map<std::string, float>::iterator it;

    std::cout << "\nDigite o nome do sanduiche que deseja excluir: " << std::endl;

    listarSanduiches(sanduiches);
    
    std::cin >> sanduiche;
    it = sanduiches.find(sanduiche);

    if(it != sanduiches.end()){

        sanduiches.erase(sanduiche);

        std::fstream arquivo("../lanches/sanduiches.txt", std::ios::out | std::ios::trunc);

        if(!arquivo.is_open()){
            std::cout << "Nao ta abrindo papai" << std::endl;
        }
        

        it = sanduiches.begin();

        while(it != sanduiches.end()){
            
            arquivo << it->first << '\n';
            arquivo << it->second;
            if (std::next(it) != sanduiches.end()) {
                arquivo << '\n';
            }
            it++;
        }
        arquivo.close();
        std::cout << "\nItem excluido com sucesso." << std::endl;
    }
    else{
        throw std::runtime_error("Este sanduiche nao existe na lista.");
    }

}

void excluiSuco(std::map<std::string, float> &sucos){

    std::string suco;
    std::map<std::string, float>::iterator it;


    std::cout << "\nDigite o nome do sanduiche que deseja excluir: \n" << std::endl;

    listarSucos(sucos);
    
    std::cin >> suco;
    it = sucos.find(suco);

    if(it != sucos.end()){

        sucos.erase(it);

        std::fstream arquivo("../lanches/sucos.txt", std::ios::out | std::ios::trunc);
        
        if(!arquivo.is_open()){
            std::cout << "Nao ta abrindo papai" << std::endl;
        }
        

        it = sucos.begin();

        while(it != sucos.end()){
            
            arquivo << it->first << '\n';
            arquivo << it->second;
            if (std::next(it) != sucos.end()) {
                arquivo << '\n';
            }
            it++;
        }
        arquivo.close();
        std::cout << "\nItem excluido com sucesso." << std::endl;
    }
    else{
        throw std::runtime_error("Este sanduiche nao existe na lista.");
    }

}