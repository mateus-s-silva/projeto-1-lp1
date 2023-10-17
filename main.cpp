#include <iostream>
#include <fstream>
#include <vector>
#include "./cliente/cliente.hpp"
#define SENHA "admin"

int main(int argc, char const *argv[])
{
    bool acesso;
    int sair = 0;
    std::string senha;
    int option;

    std::cout << "Seja bem-vindo.\n\n Digite 0 para acessar perfil de cliente.\n\n Digite 1 para acessar perfil de gerente.\n" << std::endl;
    
    std::cin >> acesso;

    if (!acesso)
    {
        std::cout << "\nPerfil de cliente: " << std::endl;
        while (true){

            std::cout << "\nEscolha uma opcao: " << std::endl;

            std::cout << "1 - Lista de sanduiches.\n"
            << "2 - Lista de sucos.\n"
            << "3 - Escolher um lanche.\n"
            << "4 - Valor do carrinho.\n"
            << "5 - Ver carrinho.\n"
            << "6 - Excluir item do carrinho.\n"
            << "0 - Sair.\n" << std::endl;

            std::cin >> option;

            if(option == 1){
                listarSanduiches();
            }
            else if(option == 2){
                //listarSucos();
            }
            else if(option == 3){
                //escolherLanche();
            }
            else if(option == 4){
                //valorCarrinho();
            }
            else if(option == 5){
                //verCarrinho();
            } 
            else if(option == 6){
                //excluirCarrinho();
            }
            else if(option == 0){
                sair = 1;
            }
            else{
                std::cout << "Opcao invalida." << std::endl;
            }

        }
    }

    else{
        
        std::cout << "Digite a senha para acessar perfil de gerente: ";
        std::cin >> senha;
        if (!senha.compare(SENHA))
        {
            std::cout << "Perfil de gerente" << std::endl;
            while(true){
                std::cout << "Escolha uma opção: " << std::endl;
            }
        }
        else{
            std::cout << "Senha incorreta." << std::endl;
        }

    }
    
    return 0;
}
