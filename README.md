# Implementação e Análise de Árvores Balanceadas
Um programa em C++ projetado para implementação e análise de três tipos de árvores binárias: Árvore Binária Simples (não balanceada), Árvore AVL e Árvore Rubro-Negra. O sistema permite que o usuário escolha, no momento da execução, qual tipo de árvore deseja criar e quais operações ele pode realizar sobre essa árvore. Sendo as operações possíveis: Inserção, Remoção, Busca e Impressão da Árvore.

## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição dos Arquivos](#2-descricao_dos_arquivos)


## Estrutura <a name="1-estrutura"></a>
```
Implementacao_e_Analise_de_Arvores_Balanceadas/
├── include_cpp/
│   ├── AVL_tree.hpp
│   ├── binary_nodo.hpp
│   ├── binary_tree.hpp
│   └── funcoes_uteis.hpp
├── src_cpp/
│   ├── AVL_tree.cpp
│   ├── binary_nodo.cpp
│   ├── binary_tree.cpp
│   ├── funcoes_uteis.cpp
│   └── main.cpp
├── Makefile
└── README.md
```


## Descrição dos Arquivos <a name="2-descricao_dos_arquivos"></a>
### a) binary_nodo.hpp & binary_nodo.cpp
Classe `binary_nodo` que corresponde à um nó capaz de armazenar ponteiros para outros dois nós.
- protected int `height`: Número inteiro que representa a altura que aquele nó está em relação à árvore em que está inserido.
- public int `key`: Número inteiro que representa a chave que identifica aquele nó em uma árvore.
- public std::string `data`: String que representa o conteúdo contido naquele nó.
- public std::shared_ptr\<binary_nodo\> `left_child`: Ponteiro inteligente de um `binary_nodo` que representa o nó à esquerda deste nó.
- public std::shared_ptr\<binary_nodo\> `right_child`: Ponteiro inteligente de um `binary_nodo` que representa o nó à direita deste nó.

#### ***\#public***:

#### -> binary_nodo(int key, std::string data)
Construtor para criar um objeto `binary_nodo`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica aquele nó em uma árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó.

#### -> virtual ~binary_nodo()
Destrutor para quando um objeto `binary_nodo` é destruído. Declarado como um destrutor padrão.

#### -> int getHeight() const
Método para acessar, sem permissão para modificar, o atributo `height` do nó. Retornando altura daquele nó em formato de número inteiro.

#### -> void updateHeight()
Método para atualizar o valor do atributo `height` do nó, levando em conta a altura de seus nós filhos — `left_child` e `right_child` —.

---

### b) binary_tree.hpp & binary_tree.cpp
Classe `binary_tree` que corresponde à implementação de uma árvore binária simples.
- protect std::shared_ptr\<binary_nodo\> `r`: Ponteiro inteligente de um `binary_nodo` que representa o nó raiz desta árvore.

#### ***\#public***:

#### -> binary_tree(int key, std::string data)
Construtor para criar um objeto `binary_tree`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo` no ponteiro de `r`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó raiz desta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó raiz.

#### -> virtual ~binary_tree()
Destrutor para quando um objeto `binary_tree` é destruído. Declarado como um destrutor padrão.

#### -> int maxKey() const
Método para acessar, sem permissão para modificar, o atributo `key` do nó de maior `key` da árvore. Retornando a chave daquele nó em formato de número inteiro.

#### -> int minKey() const
Método para acessar, sem permissão para modificar, o atributo `key` do nó de menor `key` da árvore. Retornando a chave daquele nó em formato de número inteiro.

#### -> void printTree()
Método para imprimir a estrutura da árvore com a posição de todos os seus nós pelo `key` tal como o nível em que cada um se encontra.

#### -> int getTreeHeight() const
Método para acessar, sem permissão para modificar, o atributo `height` do nó raiz da árvore. Retornando altura daquela árvore em formato de número inteiro.

#### -> virtual void insert(int key, std::string data)
Método para inserir um nó com atributos `key` e `data`. Ele chama o `insert(key, data, T)`, passando `r` como parâmetro `T`.

#### -> virtual bool remove(int key)
Método para remover o nó com atributo chave igual à `key`. Retornando uma booleana que indica se aquele nó foi (`true`) ou não (`false`) encontrado e removido. Ele chama o `remove(key, T)`, passando `r` como parâmetro `T`.

#### -> virtual std::string search(int key)
Método para buscar o nó com atributo chave igual à `key`. Retornando a `data` daquele nó em formato de número string ou `""` caso não encontre. Ele chama o `search(key, T)`, passando `r` como parâmetro `T`.

#### ***\#protected***:

#### -> virtual void insert(int key, std::string data, std::shared_ptr\<binary_nodo\> &T)
Método para inserir um nó com atributos `key` e `data`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó a ser inserido nesta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó a ser inserido nesta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para encontrar a posição adequada para colocar o nó que deseja-se inserir.

#### -> virtual bool remove(int key, std::shared_ptr\<binary_nodo\> &T)
Método para remover o nó com atributo chave igual à `key`. Retornando uma booleana que indica se aquele nó foi (`true`) ou não (`false`) encontrado e removido.
- int `key`: Número inteiro correspondente a chave de nó o qual deseja-se remover desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para buscar pelo `key` correspondente ao nó que deseja-se remover.

#### -> std::shared_ptr\<binary_nodo\> getSuccessor(std::shared_ptr\<binary_nodo\> &T)
Método para auxiliar `remove(key, T)`, percorrendo a árvore a partir do nó `T` e retornando o ponteiro do antecessor imediato do nó com o `key` de valor sucessor ao `key` daquele nó de dois filhos que será removido.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para encontrar o nó sucessor daquele que será removido.

#### -> virtual std::string search(int key, std::shared_ptr\<binary_nodo\> &T)
Método para buscar o nó com atributo chave igual à `key`. Retornando a `data` daquele nó em formato de número string ou `""` caso não encontre.
- int `key`: Número inteiro correspondente a chave de nó o qual deseja-se buscar nesta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para buscar pelo `key` correspondente ao nó que deseja-se encontrar.

#### -> void printTree(std::shared_ptr\<binary_nodo\> &T, int nodo_level, int nodo_index, std::vector\<std::vector\<float\>\> &tree_structure)
Método para auxiliar `printTree()`, percorrendo a árvore a partir da raiz e armazenando o `key` de todos os nós em `tree_structure` de forma padronizada.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para armazenar seu `key` em `tree_structure`.
- int `nodo_level`: Número inteiro que representa o nível daquele nó na árvore, é usado como índice das linhas do `tree_structure` onde armazenar o `key` de `T`.
-se definir como a chave que identifica o nó raiz desta árvore.
- int `nodo_index`: Número inteiro que representa a posição horizontal daquele nó na árvore, é usado como índice das colunas do `tree_structure` onde armazenar o `key` de `T`.
- std::vector\<std::vector\<float\>\> &`tree_structure`: Vetor de vetores (matriz) de números flutuantes que representa a estrutura desta árvore, é usado como parâmetro para impressão da estrutura da árvore em `printTree()` para armazenar as chaves dos nós em suas posições correspondentes.

#### -> void RR_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação simples à esquerda entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void LL_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação simples à direita entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void RL_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação dupla à esquerda entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void LR_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação dupla à direita entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

---

### c) AVL_tree.hpp & AVL_tree.cpp
Classe `AVL_tree`, derivada de `binary_tree`, que corresponde à implementação de uma árvore binária AVL.

#### ***\#public***:

#### -> AVL_tree(int key, std::string data)
Construtor para criar um objeto `AVL_tree`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo` no ponteiro de `r`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó raiz desta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó raiz.

#### ***\#protected***:

#### -> virtual void insert(int key, std::string data, std::shared_ptr\<binary_nodo\> &T) override
Método de inserção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores AVL.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó a ser inserido nesta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó a ser inserido nesta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para encontrar a posição adequada para colocar o nó que deseja-se inserir.

#### -> virtual bool remove(int key, std::shared_ptr\<binary_nodo\> &T) override
Método de remoção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores AVL. Retorna uma booleana que indica se a remoção foi bem-sucedida (`true`) ou não (`false`).
- int `key`: Número inteiro correspondente a chave de nó o qual deseja-se remover desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para buscar pelo `key` correspondente ao nó que deseja-se remover.

---

### d) funcoes_uteis.hpp & funcoes_uteis.cpp
Aquivos para declaração e implementação de outras funções úteis para o funcionamento do código. Não estão diretamente relacionadas com as funcionalidades das árvores binárias.

### + int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup)
Função para ler um número inteiro do terminal, bloqueando qualquer entrada que não seja um inteiro. Após validar que a entrada é um número inteiro, verifica-se se o valor pertence ao intervalo fechado \[`lim_inf`, `lim_sup`]. Se pertencer, a função retorna esse valor e é finalizada. Caso contrário, a `mensagem_erro` será exibida e um novo valor deverá ser inserido até que seja uma entrada válida. Se `lim_inf` e `lim_sup` forem iguais, o intervalo para conferência do valor principal será \[-∞, +∞]
- `mensagem_erro`: String correspondente à mensagem de erro que deve ser exposta caso um valor não inteiro seja recebido do dispositivo de entrada.
- `lim_inf`: Inteiro correspondente ao primeiro número de um intervalo fechado o qual o valor que deve pertencer.
- `lim_inf`: Inteiro correspondente ao último número de um intervalo fechado o qual o valor que deve pertencer.

---

### e) main.cpp
Onde fica localizado a função `main` que executa o programa. Em C++, é o ponto de entrada para a execução de um programa — ou seja, é onde a execução do código começa —. A interação com o usuário é realizada via terminal e o programa apresenta opções de tipo de árvores binárias que podem ser criadas os quais o usuário terá de escolher uma. Elas são:

| N° Árvore | Tipo de Árvore         |
|:----------|:-----------------------|
| 1         | Árvore Binária Simples |
| 2         | Árvore AVL             |
| 3         | Árvore Rubro-Negra     |

Após o usuário selecionar um tipo válido de árvore, ele apresenta um menu principal com as seguintes operações que podem ser realizadas: 

| N° Operação | Operação         | Descrição                                                                                                                                                     |
|:------------|:-----------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1           | Inserir Elemento | O sistema insere um nó na árvore. Nesta operação, se solicita o `key` que identifica esse nó e sua `data`.                                                    |
| 2           | Remover Elemento | O sistema solicita o `key` do nó que o usuário deseja remover. Caso o nó exista, ele será removido da árvore. Caso contrário, uma mensagem de erro é exibida. |
| 3           | Buscar Elemento  | O sistema solicita o `key` do nó que o usuário deseja encontrar. Caso o nó exista, será retornado sua `data`. Caso contrário, uma mensagem de erro é exibida. |
| 4           | Imprimir Árvore  | O sistema imprime a estrutura da árvore com a posição de todos os seus nós pelo `key` tal como o nível em que cada um se encontra.                            |
| 5           | Sair             | Encerra a execução do programa.                                                                                                                               |

Caso se dê entrada em um número de operação não reconhecido, o programa exibe uma mensagem de erro e regressa ao menu principal para a inserção de outro número até que ele seja considerado válido.
