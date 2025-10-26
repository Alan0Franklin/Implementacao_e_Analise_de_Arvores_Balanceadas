# Implementação e Análise de Árvores Balanceadas
Um programa em C++ projetado para implementação e análise de três tipos de árvores binárias: Árvore Binária Simples de Pesquisa (não balanceada), Árvore AVL e Árvore Rubro-Negra. O sistema permite que o usuário escolha, no momento da execução, qual tipo de árvore deseja criar e quais operações ele pode realizar sobre essa árvore. Sendo as operações possíveis: Inserção, Remoção, Busca e Impressão da Árvore.

## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição dos Arquivos](#2-descricao_dos_arquivos)
- [3. Como Compilar e Executar](#3-como_compilar_e_executar)
- [4. Formatos de Entrada e Saída Padrão](#4-formatos_de_entrada_e_saida_padrao)

## Estrutura <a name="1-estrutura"></a>
```
Implementacao_e_Analise_de_Arvores_Balanceadas/
├── Entradas_+_Saidas_Esperadas/
│   ├── AVL_entrada.txt
│   ├── AVL_saida.txt
│   ├── binary_entrada.txt
│   ├── binary_saida.txt
│   ├── red_black_entrada.txt
│   └── red_black_saida.txt
├── include_cpp/
│   ├── AVL_tree.hpp
│   ├── binary_nodo.hpp
│   ├── binary_tree.hpp
│   ├── color_nodo.hpp
│   ├── funcoes_uteis.hpp
│   └── red_black_tree.hpp
├── src_cpp/
│   ├── AVL_tree.cpp
│   ├── binary_nodo.cpp
│   ├── binary_tree.cpp
│   ├── color_nodo.cpp
│   ├── funcoes_uteis.cpp
│   ├── main.cpp
│   └── red_black_tree.cpp
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
Método para atualizar o valor do atributo `height` do nó, levando em conta a altura de seus nós filhos — `left_child` e `right_child`.

---

### b) color_nodo.hpp & color_nodo.cpp
Classe `color_nodo`, derivada de `binary_nodo`, que corresponde à um nó capaz de armazenar uma cor.
- public bool `color`: Número inteiro que representa a altura que aquele nó está em relação à árvore em que está inserido.
- public std::shared_ptr\<color_nodo\> `parent`: Ponteiro inteligente de um `color_nodo` que representa o nó à pai deste nó.

#### ***\#public***:

#### -> color_nodo(int key, std::string data)
Construtor para criar um objeto `color_nodo`, além de atribuir `key` e `data` aos atributos do objeto `color_nodo`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica aquele nó em uma árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó.

#### -> bool getColor()
Método para acessar o atributo `color` do nó. Retornando uma booleana que indica se aquele nó é rubro (`true`) ou negro (`false`).

#### -> void updateColor()
Método para atualizar o valor do atributo `color` do nó, levando seus nós parentes.

---

### c) binary_tree.hpp & binary_tree.cpp
Classe `binary_tree` que corresponde à implementação de uma árvore binária simples.
- protect std::shared_ptr\<binary_nodo\> `r`: Ponteiro inteligente de um `binary_nodo` que representa o nó raiz desta árvore.

#### ***\#public***:

#### -> binary_tree()
Construtor para criar um objeto `binary_tree`. Declarado como um construtor padrão.

#### -> binary_tree(int key, std::string data)
Construtor para criar um objeto `binary_tree`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo` no ponteiro de `r`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó raiz desta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó raiz.

#### -> virtual ~binary_tree()
Destrutor para quando um objeto `binary_tree` é destruído. Declarado como um destrutor padrão.

#### -> virtual void insert(int key, std::string data)
Método para inserir um nó com atributos `key` e `data`. Ele chama o `insert(key, data, T)`, passando `r` como parâmetro `T`.

#### -> virtual bool remove(int key)
Método para remover o nó com atributo chave igual à `key`. Retornando uma booleana que indica se aquele nó foi (`true`) ou não (`false`) encontrado e removido. Ele chama o `remove(key, T)`, passando `r` como parâmetro `T`.

#### -> virtual std::string search(int key)
Método para buscar o nó com atributo chave igual à `key`. Retornando a `data` daquele nó em formato de número string ou `""` caso não encontre. Ele chama o `search(key, T)`, passando `r` como parâmetro `T`.

#### -> virtual void printTree()
Método para imprimir a estrutura da árvore com a posição de todos os seus nós pelo `key` tal como o nível em que cada um se encontra.

#### -> float maxKey() const
Método para acessar, sem permissão para modificar, o atributo `key` do nó de maior `key` da árvore. Retornando a chave daquele nó em formato de número flutuante ou `0.5` caso a árvore esteja vazia.

#### -> float minKey() const
Método para acessar, sem permissão para modificar, o atributo `key` do nó de menor `key` da árvore. Retornando a chave daquele nó em formato de número flutuante ou `0.5` caso a árvore esteja vazia.

#### -> int getTreeHeight() const
Método para acessar, sem permissão para modificar, o atributo `height` do nó raiz da árvore. Retornando altura daquela árvore em formato de número inteiro ou `-1` caso a árvore esteja vazia.

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

#### -> void printTree(std::shared_ptr\<binary_nodo\> &T, int nodo_level, int nodo_index, std::vector\<std::vector\<std::shared_ptr\<binary_nodo\>\>\> &tree_structure)
Método para auxiliar `printTree()`, percorrendo a árvore a partir da raiz e armazenando o `key` de todos os nós em `tree_structure` de forma padronizada.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para armazenar seu `key` em `tree_structure`.
- int `nodo_level`: Número inteiro que representa o nível daquele nó na árvore, é usado como índice das linhas do `tree_structure` onde armazenar o `key` de `T`.
-se definir como a chave que identifica o nó raiz desta árvore.
- int `nodo_index`: Número inteiro que representa a posição horizontal daquele nó na árvore, é usado como índice das colunas do `tree_structure` onde armazenar o `key` de `T`.
- std::vector\<std::vector\<std::shared_ptr\<binary_nodo\>\>\> &`tree_structure`: Vetor de vetores (matriz) de números flutuantes que representa a estrutura desta árvore, é usado como parâmetro para impressão da estrutura da árvore em `printTree()` para armazenar as chaves dos nós em suas posições correspondentes.

#### -> void RR_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação simples à esquerda entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void LL_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação simples à direita entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void RL_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação dupla à direita-esquerda entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void LR_rotation(std::shared_ptr\<binary_nodo\> &T)
Método correspondente a uma rotação dupla à esquerda-direita entre nós desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa o nó o qual deseja-se realizar a rotação.

---

### d) AVL_tree.hpp & AVL_tree.cpp
Classe `AVL_tree`, derivada de `binary_tree`, que corresponde à implementação de uma árvore binária AVL.

#### ***\#public***:

#### -> AVL_tree(int key, std::string data)
Construtor para criar um objeto `AVL_tree`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo` no ponteiro de `r`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó raiz desta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó raiz.

#### ***\#protected***:

#### -> void insert(int key, std::string data, std::shared_ptr\<binary_nodo\> &T) override
Método de inserção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores AVL.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó a ser inserido nesta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó a ser inserido nesta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para encontrar a posição adequada para colocar o nó que deseja-se inserir.

#### -> bool remove(int key, std::shared_ptr\<binary_nodo\> &T) override
Método de remoção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores AVL. Retorna uma booleana que indica se a remoção foi bem-sucedida (`true`) ou não (`false`).
- int `key`: Número inteiro correspondente a chave de nó o qual deseja-se remover desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para buscar pelo `key` correspondente ao nó que deseja-se remover.

---

### e) red_black_tree.hpp & red_black_tree.cpp
Classe `red_black_tree`, derivada de `binary_tree`, que corresponde à implementação de uma árvore binária Rubro-Negra.

#### ***\#public***:

#### -> red_black_tree(int key, std::string data)
Construtor para criar um objeto `red_black_tree`, além de atribuir `key` e `data` aos atributos do objeto `binary_nodo` no ponteiro de `r`.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó raiz desta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó raiz.

#### -> void printTree() override
Método de sobrescrito de `binary_tree` para imprimir a estrutura da árvore com a cor de todos os seus nós. Com "R" representando nós Rubro e "B" representando nós Negros.

#### ***\#protected***:

#### -> void insert(int key, std::string data, std::shared_ptr\<binary_nodo\> &T) override
Método de inserção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores Rubro-Negra.
- int `key`: Número inteiro o qual deseja-se definir como a chave que identifica o nó a ser inserido nesta árvore.
- std::string `data`: String o qual deseja-se definir como conteúdo contido naquele nó a ser inserido nesta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para encontrar a posição adequada para colocar o nó que deseja-se inserir.

#### -> bool remove(int key, std::shared_ptr\<binary_nodo\> &T) override
Método de remoção sobrescrito de `binary_tree` com a implementação do sistema de balanceamento das árvores Rubro-Negra. Retorna uma booleana que indica se a remoção foi bem-sucedida (`true`) ou não (`false`).
- int `key`: Número inteiro correspondente a chave de nó o qual deseja-se remover desta árvore.
- std::shared_ptr\<binary_nodo\> `T`: Ponteiro inteligente de um `binary_nodo` que representa um dos nós que o método percorre na árvore para buscar pelo `key` correspondente ao nó que deseja-se remover.

#### -> void fixinsert(std::shared_ptr\<color_nodo\> &T)
Método auxiliar de inserção.
- std::shared_ptr\<color_nodo\> `T`: Ponteiro inteligente de um `color_nodo`.

#### -> void fixDelete(std::shared_ptr\<color_nodo\> &T)
Método auxiliar de remoção.
- std::shared_ptr\<color_nodo\> `T`: Ponteiro inteligente de um `color_nodo`.

#### -> void R_rotation(std::shared_ptr\<color_nodo\> &T)
Método correspondente a uma rotação simples à esquerda entre nós desta árvore.
- std::shared_ptr\<color_nodo\> `T`: Ponteiro inteligente de um `color_nodo` que representa o nó o qual deseja-se realizar a rotação.

#### -> void L_rotation(std::shared_ptr\<color_nodo\> &T)
Método correspondente a uma rotação simples à direita entre nós desta árvore.
- std::shared_ptr\<color_nodo\> `T`: Ponteiro inteligente de um `color_nodo` que representa o nó o qual deseja-se realizar a rotação.

---

### f) funcoes_uteis.hpp & funcoes_uteis.cpp
Aquivos para declaração e implementação de outras funções úteis para o funcionamento do código. Não estão diretamente relacionadas com as funcionalidades das árvores binárias.

### + int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup)
Função para ler um número inteiro do terminal, bloqueando qualquer entrada que não seja um inteiro. Após validar que a entrada é um número inteiro, verifica-se se o valor pertence ao intervalo fechado \[`lim_inf`, `lim_sup`]. Se pertencer, a função retorna esse valor e é finalizada. Caso contrário, a `mensagem_erro` será exibida e um novo valor deverá ser inserido até que seja uma entrada válida. Se `lim_inf` e `lim_sup` forem iguais, o intervalo para conferência do valor principal será \[-∞, +∞]
- `mensagem_erro`: String correspondente à mensagem de erro que deve ser exposta caso um valor não inteiro seja recebido do dispositivo de entrada.
- `lim_inf`: Inteiro correspondente ao primeiro número de um intervalo fechado o qual o valor que deve pertencer.
- `lim_inf`: Inteiro correspondente ao último número de um intervalo fechado o qual o valor que deve pertencer.

---

### g) main.cpp
Onde fica localizado a função `main` que executa o programa. Em C++, é o ponto de entrada para a execução de um programa — ou seja, é onde a execução do código começa. A interação com o usuário é realizada via terminal e o programa apresenta opções de tipo de árvores binárias que podem ser criadas os quais o usuário terá de escolher uma. Elas são:

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

Caso se dê entrada em um número de operação não reconhecido, o programa exibe uma mensagem de erro e regressa ao menu principal para a inserção de outro número até que ele seja considerado válido. A iteração do menu de operação se mantém até o usuário encerrar o programa.

## Como Compilar e Executar <a name="3-como_compilar_e_executar"></a>

Para compilar os arquivos, 
1. Compile o projeto com o `g++`, com ajuda do Makefile use o comando `make` em um terminal no diretório/pasta que o projeto estiver.
```bash
make
```
Este comando automatizará a compilação e gerará um executável chamado `Implementacao_e_Analise_de_Arvores_Balanceadas`.

2. Execute o programa em um terminal, o comando para realizar a execução vai depender do sistema operacional e do tipo de terminal. Alguns exemplos são:
*   **Windows (Command Prompt):** 
```bash
Implementacao_e_Analise_de_Arvores_Balanceadas.exe
```

*   **Linux/macOS (Terminal):** 
```bash
./Implementacao_e_Analise_de_Arvores_Balanceadas
```

3. Esse programa lê o conteúdo do `cout`, porém é possível redirecionar a entrada de um arquivo `entrada.txt` com o `<`, como se fosse digitado pelo terminal, e será impresso (`cin`) de forma redirecionada para um arquivo `saida.txt` com o `>`, como se fosse impresso no terminal. Para isso use o seguinte comando a depender do seu terminal:
*   **Windows (Command Prompt):** 
```bash
Implementacao_e_Analise_de_Arvores_Balanceadas.exe < entrada.txt > saida.txt
```

*   **Linux/macOS (Terminal):** 
```bash
./Implementacao_e_Analise_de_Arvores_Balanceadas < entrada.txt > saida.txt
```

4. Algumas outras funcionalidades do terminal que podem ser úteis incluem: O uso do `>>` no lugar de `>` faz o terminal gravar a saída no final do arquivo existente, sem apagar o conteúdo anterior; Se o arquivo de saída indicado não existir, ele será criado automaticamente. Se existir, será sobrescrito (ou acrescentado, com `>>`). A única exceção à isso é se o diretório onde deseja-se criar o arquivo não existir; Caso o arquivo em que deseja-se sofrer este redirecionamento de entrada e saída esteja em um diretório diferente daquele em que o terminal está aberto, é possível chamar o arquivo pelo seu caminho relativo ou absoluto. Abaixo está um exemplo de comando que executa o programa redirecionando a entrada a partir de um arquivo localizado neste repositório (usando seu caminho relativo) e gravando a saída no final de um arquivo `.txt` que ainda não existe no repositório:

*   **Windows (Command Prompt):** 
```bash
Implementacao_e_Analise_de_Arvores_Balanceadas.exe < Entradas_+_Saidas_Esperadas/AVL_entrada.txt >> saida.txt
```

*   **Linux/macOS (Terminal):** 
```bash
./Implementacao_e_Analise_de_Arvores_Balanceadas < Entradas_+_Saidas_Esperadas/AVL_entrada.txt >> saida.txt
```

**Observações:**
### Formato de Entrada Padrão
O programa lê **exatamente** neste formato:
```
[tipo da árvore que deseja ser criada]
[chave do nó raiz dessa árvore]
[conteúdo do nó raiz dessa árvore]
...
[número de operação == 1]
[chave do nó a ser inserido nessa árvore]
[conteúdo do nó a ser inserido nessa árvore]
...
[número de operação == 2/3]
[chave do nó a ser removido/buscado nessa árvore]
...
[número de operação == 4]
...
[número de operação == 5]
```

Exemplos concretos de entradas e saídas em `.txt` na subpasta `Entradas_+_Saidas_Esperadas`.

## Formatos de Entrada e Saída Padrão <a name="4-formatos_de_entrada_e_saida_padrao"></a>
### Exemplos concretos:
- Criação de uma árvores:
```
> Selecione o tipo de arvore deseja criar:
  | 1 - Arvore Binaria Simples
  | 2 - Arvore AVL
  | 3 - Arvore Rubro-Negra
  !:> 2
  !:> Determine a chave do seu no raiz, deve ser um inteiro: 10
  !:> Determine o conteudo que o no raiz deve conter em uma linha: Ana
  '-> Criação de Arvore AVL!
```

---

- Inserção de elementos em uma árvore:
```
> Selecione uma operacao para ser realizada na arvore: 
  | 1 - Inserir Elemento
  | 2 - Remover Elemento
  | 3 - Buscar Elemento
  | 4 - Imprimir Arvore
  | 5 - Sair
  !:> 1
  !:> Determine a chave do elemento que deseja inserir, deve ser um inteiro: 5
  !:> Determine o conteudo que o elemento que deseja inserir deve conter em uma linha: Bruno
  '-> Operacao de Insercao Concluida!
```

---

- Remoção de elementos de uma árvore:
```
> Selecione uma operacao para ser realizada na arvore: 
  | 1 - Inserir Elemento
  | 2 - Remover Elemento
  | 3 - Buscar Elemento
  | 4 - Imprimir Arvore
  | 5 - Sair
  !:> 2
  !:> Informe a chave do elemento que deseja remover, deve ser um inteiro: 15
  '-> Operacao de Remocao Concluida!
```

---

- Busca de elementos em uma árvore:
```
> Selecione uma operacao para ser realizada na arvore: 
  | 1 - Inserir Elemento
  | 2 - Remover Elemento
  | 3 - Buscar Elemento
  | 4 - Imprimir Arvore
  | 5 - Sair
  !:> 3
  !:> Informe a chave do elemento que deseja buscar, deve ser um inteiro: 18
  |-> Conteudo do elemento: Amanda
  '-> Operacao de Busca Concluida!
```

---

- Impressão da estrutura da árvore:
```
> Selecione uma operacao para ser realizada na arvore: 
  | 1 - Inserir Elemento
  | 2 - Remover Elemento
  | 3 - Buscar Elemento
  | 4 - Imprimir Arvore
  | 5 - Sair
  !:> 4
  |-> Estrutura da Arvore:
  |                                   (10)                                         Nivel 0
  |                  .----------------'  '----------------.
  |               (05)                                    (15)                     Nivel 1
  |        .------'  '------.                      .------'
  |     (03)                (07)                (12)                               Nivel 2
  |                       .-'  '-.
  |                    (06)      (09)                                              Nivel 3
  '
```

---

- Finalização da execução do programa:
```
> Selecione uma operacao para ser realizada na arvore: 
  | 1 - Inserir Elemento
  | 2 - Remover Elemento
  | 3 - Buscar Elemento
  | 4 - Imprimir Arvore
  | 5 - Sair
  !:> 5
  '-> Fim da Execucao do Programa.
```