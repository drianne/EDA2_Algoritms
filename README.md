<h1>BUSCA SEQUENCIAL INDEXADA</h4> <br>
<p align="center">    
    <img src="https://image.freepik.com/icones-gratis/simbolo-ferramenta-da-busca_318-32162.jpg" width=130 height=130>
</p>

## Contribuidores
| Nome	| Matrícula	|
|--|--|
| Adrianne Alves da Silva | 16/0047595 |
| Lucas Arthur Lermen | 16/0012961 |


## Apresentação

Este repositório apresenta um algoritmo de busca sequencial indexada, escrito em linguagem c, para fins didáticos na disciplina de Estrutura de dados 2. Consiste em uma atividade apresentada como avaliação parcial da disciplina de Estrutura de dados 2 do curso de Engenharia de software da Universidade de Brasília (UnB), Campus de Engenharias - Faculdade do Gama (FGA).

## Sobre algoritmo de busca

Algoritmos de busca, como o próprio nome diz, refere-se à estruturas lógicas independentes da linguagem que possibilitam a recuperação de um dado.

### 1.0 Busca Sequencial

É a forma mais simples de se realizar uma busca, sendo aplicável à tabela como vetor ou lista encadeada. De maneira simplista, a dinâmica da busca consiste em passar de registro em registro em busca da chave solicitada, sendo esse o critério de parada. Um exemplo :

```
for (i=0; i<n; i++)
  if (A[i]==x)
    return(i); /*Encontrou registro*/
return(-1); /*Não encontrou registro*/
```

![Busca Sequencial](https://sites.google.com/site/labworksharvin/_/rsrc/1373987242005/home/5-b/images%20%284%29.jpg)

É importante lembrar de evitar a explosão de índice do vetor.

### 1.1 Busca Sequencial Indexada

É uma forma de realização de busca sequencial, que utiliza uma tabela auxiliar para guardar os índices e um arquivo de dados ordenados. É importante dizer que cada elemento na tabela de índices possui uma chave, nomeada kindex e um indicador para o registro no arquivo correpondente. Dessa forma, a busca é feita a partir do ponto indicado na tabela, o que evita que a busca seja feita desde o começo.

Esse tipo de estrutura pode utilizar vetor ou lista encadeada, de maneira que o indicador de posição na tabela pode ser um ponteiro ou uma variável inteira. Sabe-se ainda que se o número de registros for muito grande, é possível utilizar uma tabela de índices secundária. Um exemplo observável encontra-se na imagem a seguir :

![Busca Sequencial Indexada](http://www.inf.ufsc.br/~aldo.vw/estruturas/gerarq15.gif)

É preciso salientar que a inserção de elementos pode ser feita no espaço vazio da estrutura, atualizando a tabela de índices ou no final da estrutura de maneira que é necessário reorganizar os registros e a tabela de índice.


### Algoritmo implementado

Com fins didáticos, o algoritmo implementado aqui corresponde à uma busca sequencial com tabela de registros criada automaticamente com números aleatórios em um vetor e uma única tabela de índices (suporta até 10000 elementos). Além disso, foi implementada uma função de remoção que marca a posição no vetor de registros com o número 999999999, reordena a tabela de registros e constroi novamente a tabela de índices.
