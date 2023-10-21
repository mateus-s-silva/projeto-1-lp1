# Projeto 1 - Linguagem de programação 1
## Estrutura
### Headers
Na pasta ./headers estão todas as assinaturas de todas as funções e classes utilizadas. 

&nbsp;
Estão separadas por funcionalidade:
* cardapio.hpp: possui as assinaturas das funções responsáveis por carregar os cardapios inicialmente
* cliente.hpp: modelo da classe Cliente utilizada junto com todas as assinaturas de seus métodos
* geral.hpp: possui as assinaturas das funções de listagem
* gerente.hpp: possui as assinaturas das funções do gerente

## Lanches
Na pasta ./lanches possui os arquivos de texto a serem lidos

### Source 
Na pasta ./src encontramos todas as implementações de nossas funções declaradas no ./headers

## Como executar
Para compilar, navegue até a pasta ./src e execute o seguinte comando no terminal: 
~~~shell
g++ main.cpp geral.cpp cardapio.cpp cliente.cpp gerente.cpp -o exec -Iheade
rs -Wall -Wextra -pedantic 
~~~

Em seguide, execute o seguinte comando:
~~~shell
./exec
~~~ 

Se você tiver windows, provavelmente  terá que executar: 
~~~shell
exec.exe
~~~
ou 
~~~shell
./exec.exe
~~~

