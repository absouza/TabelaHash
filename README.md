TabelaHash
==========
![release status](http://img.shields.io/badge/release-v.1.0-green.svg)
![build status](https://img.shields.io/teamcity/codebetter/bt428.svg)
![license](https://img.shields.io/hexpm/l/plug.svg)

Implementação da tabela hash na linguagem C, usando alocação dinamica, pela matéria Estrutura de dados e algoritmo I.

## Introdução


## Usando o programa de base

O primeiro parametro a ser lido é N que indica o tamanho da tabela hash

Logo após digita-se um char, que indica o que você deseja fazer:

i - insere

    O usuário digita 'i' numa linha e a string em outra para inserir a mesma na tabela hash
	
p - procura

    O usuário digita 'p' numa linha e a string em outra para procurar a mesma na tabela hash
	
r - retira

    O usuário digita 'r' numa linha e a string em outra para retirar a mesma na tabela hash
	
h - gera o hash de uma entrada

    O usuário digita 'h' numa linha e a string em outra para ver o hash correspondente na tabela hash
	
s - sai do programa

    O usuário digita 's' para sair do programa


## Usando as funções
```c
// Funções
Hash* criaTabela(int tam);
_Bool insere(char *str, Hash *table, int tam);
_Bool retira(char *str, Hash *table, int tam);
_Bool procura(char *str, Hash *table, int tam);
// Struct
{
  char* text;
  struct Hash *prox;
}
// Tipos do struct
*Hash
noHash
```

## Entradas de teste
```c
100
i
teste
i
teste2
p
teste2
r
teste
s
```
