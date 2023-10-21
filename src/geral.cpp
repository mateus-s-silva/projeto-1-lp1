#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include "../headers/geral.hpp"


void listarSanduiches(std::map<std::string, float> sanduiches){

    std::map<std::string, float>::iterator it;

    std::cout << "\nSanduiches: " << std::endl;

    for(it = sanduiches.begin(); it != sanduiches.end(); it++){
        std::cout << "\n" << it->first << " - " << "Valor: " << it->second << std::endl;
    }

}

void listarSucos(std::map<std::string, float> sucos){

    std::map<std::string, float>::iterator it;

    std::cout << "\nSucos: " << std::endl;

    for(it = sucos.begin(); it != sucos.end(); it++){
        std::cout << "\n" << it->first << " - " << "Valor: " << it->second << std::endl;
    }

}