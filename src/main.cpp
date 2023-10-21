#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "../headers/gerente.hpp"
#include "../headers/geral.hpp"
#include "../headers/cardapio.hpp"
#include "../headers/cliente.hpp"
#define SENHA "admin"

int main()
{
    int acesso;
    bool sistema = true;
    std::string senha;
    int option;


    std::map<std::string, float> opcoesSanduiches = carregarSanduiches();
    std::map<std::string, float> opcoesSucos = carregarSucos();

    Cliente cliente;

    while(sistema){
        std::cout << "Seja bem-vindo.\n\n Digite 0 para acessar perfil de cliente.\n\n Digite 1 para acessar perfil de gerente.\n" << std::endl;
        
        std::cin >> acesso;

        if (acesso == 0)
        {
            bool sairCliente = true;
            std::cout << "\nPerfil de cliente: " << std::endl;
            while (sairCliente){

                std::cout << "\nEscolha uma opcao: " << std::endl;

                std::cout 
                << "1 - Lista de sanduiches.\n"
                << "2 - Lista de sucos.\n"
                << "3 - Escolher um lanche.\n"
                << "4 - Valor do carrinho.\n"
                << "5 - Ver carrinho.\n"
                << "6 - Excluir item do carrinho.\n"
                << "0 - Sair.\n" 
                << std::endl;

                std::cin >> option;

                if(option == 1){
                    listarSanduiches(opcoesSanduiches);
                }
                else if(option == 2){
                    listarSucos(opcoesSucos);
                }
                else if(option == 3){
                    cliente.escolherLanche(opcoesSanduiches, opcoesSucos);
                }
                else if(option == 4){
                    std::cout << "\nValor total: " << cliente.valorCarrinho() << std::endl;
                }
                else if(option == 5){
                    cliente.verCarrinho();
                } 
                else if(option == 6){
                    cliente.excluirCarrinho();
                }
                else if(option == 0){
                    sairCliente = false;
                }
                else{
                    std::cout << "Opcao invalida." << std::endl;
                }
            }
        }

        else if(acesso == 1){
            
            std::cout << "\nDigite a senha para acessar perfil de gerente: ";
            std::cin >> senha;
            if (!senha.compare(SENHA))
            {
                std::cout << "Perfil de gerente" << std::endl;
                bool sairGerente = true;
                while(sairGerente){
                    std::cout << "\nEscolha uma opção: " << std::endl;

                    std::cout 
                    << "1 - Lista de sanduiches.\n"
                    << "2 - Lista de sucos.\n"
                    << "3 - Adicionar novo sanduiche.\n"
                    << "4 - Adicionar novo suco.\n"
                    << "5 - Alterar preco de um sanduiche.\n"
                    << "6 - Alterar preco de um suco.\n"
                    << "7 - Excluir um sanduiche.\n"
                    << "8 - Excluir um suco.\n"
                    << "0 - Sair.\n" 
                    << std::endl;

                    std::cin >> option;

                    if(option == 1){
                        listarSanduiches(opcoesSanduiches);
                    }
                    else if(option == 2){
                        listarSucos(opcoesSucos);
                    }
                    else if(option == 3){
                        adicionarSanduiche(opcoesSanduiches);
                    }
                    else if(option == 4){
                        adicionarSuco(opcoesSucos);
                    }
                    else if(option == 5){
                        alteraPrecoSanduiche(opcoesSanduiches);
                    } 
                    else if(option == 6){
                        alteraPrecoSuco(opcoesSucos);
                    }
                    else if(option == 7){
                        excluiSanduiche(opcoesSanduiches);
                    }
                    else if(option == 8){
                        excluiSuco(opcoesSucos);
                    }
                    else if(option == 0){
                        sairGerente = false;
                    }
                    else{
                        std::cout << "Opcao invalida." << std::endl;
                    }
                }
            }
            else{
                std::cout << "Senha incorreta." << std::endl;
            }

        }
        else sistema = false;
    }
    
    return 0;
}
