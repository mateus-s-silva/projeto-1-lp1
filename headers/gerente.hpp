#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <map>
#include <string>

void adicionarSuco(std::map<std::string, float>&);
void adicionarSanduiche(std::map<std::string, float>&);
void alteraPrecoSanduiche(std::map<std::string, float>&);
void alteraPrecoSuco(std::map<std::string, float>&);
void excluiSanduiche(std::map<std::string, float>&);
void excluiSuco(std::map<std::string, float>&);

#endif