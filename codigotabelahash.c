#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Macro ~ é substituição de palavras por isso não chega a ser uma função
#define HASH(t_string, t_table) (t_string % t_table)
// Ativa o DEBUG VISUAL
// Retire o comentario da linha abaixo para ativar o debug visual
// #define DEBUG 1
// HASH TABLE //
 
// HASH TYPE
typedef struct Hash{
    char* text;
    struct Hash *prox;
}*Hash, noHash;
 
Hash* criaTabela(int tam){
    int i;
    Hash *aux = (Hash*) calloc (sizeof(Hash) * tam, sizeof(Hash));
 
    for(i = 0; i < tam ; i++)
        aux[i] = NULL;
 
    return aux;
}
 
_Bool insere(char *str, Hash *table, int tam){
    int t_str = strlen(str);
    char *aux;
    noHash *t_aux, *novo;
 
#ifdef DEBUG
    printf("!!INSERE!!\n");
#endif
 
    if(!(aux = (char*) calloc(sizeof(char)*strlen(str),sizeof(char))))
        return false;
 
#ifdef DEBUG
    printf("!!MALLOC -AUX- OK!!\n");
#endif
 
    if(!(novo = (noHash*) malloc(sizeof(noHash))))
        return false;
 
#ifdef DEBUG
    printf("!!MALLOC -NOVO- OK!!\n");
#endif
 
    strcpy(aux, str);
    novo->text = aux;
    novo->prox = NULL;
    if(!table[HASH(t_str,tam)]){
        table[HASH(t_str,tam)] = novo;
#ifdef DEBUG
        printf("!!INSERT IF IS EMPTY OK!!\n");
#endif
        return true;
    }
 
    for(t_aux = table[HASH(t_str,tam)]; t_aux && (strcmp(t_aux->text,str) != 0); t_aux = t_aux->prox){
        if(t_aux->prox == NULL){
            t_aux->prox = novo;
            break;
        }
    }
 
#ifdef DEBUG
    printf("!!EVERYTHING FINE!!\n");
#endif
 
    return true;
}
 
_Bool retira(char *str, Hash *table, int tam){
    noHash *t_aux, *ant;
 
#ifdef DEBUG
    printf("!!RETIRA!!\n");
#endif
 
    if(!table[HASH(strlen(str),tam)]){
#ifdef DEBUG
        printf("!!NOT FOUND ITEN!!\n");
        printf("!!EVERYTHING FINE!!\n");
#endif
        return false;
    }
 
#ifdef DEBUG
        printf("!!SEARCHING THE LIST!!\n");
        printf("!!ENTERING LOOP!!\n");
#endif
 
    for(t_aux = table[HASH(strlen(str),tam)], ant = NULL; t_aux; ant = t_aux, t_aux = t_aux->prox){
        if(strcmp(str, t_aux->text) == 0){
            if(!t_aux->prox && !ant)
                table[HASH(strlen(str),tam)] = NULL;
            else if(t_aux->prox && !ant)
                table[HASH(strlen(str),tam)] = t_aux->prox;
            else
                ant->prox = t_aux->prox;
#ifdef DEBUG
            printf("!!FOUND ITEN!!\n");
            printf("!!EVERYTHING FINE!!\n");
#endif
            free(t_aux->text);
            free(t_aux);
            return true;
        }
    }
 
#ifdef DEBUG
    printf("!!NOT FOUND ITEN!!\n");
    printf("!!EVERYTHING FINE!!\n");
#endif
 
    return false;
}
 
_Bool procura(char *str, Hash *table, int tam){
    noHash *t_aux;
 
#ifdef DEBUG
    printf("!!PROCURA!!\n");
#endif
 
    for(t_aux = table[HASH(strlen(str),tam)]; t_aux; t_aux = t_aux->prox){
        if(strcmp(str, t_aux->text) == 0){
#ifdef DEBUG
            printf("!!FOUND ITEN!!\n");
            printf("!!EVERYTHING FINE!!\n");
#endif
            return true;
        }
    }
 
#ifdef DEBUG
    printf("!!NOT FOUND ITEN!!\n");
    printf("!!EVERYTHING FINE!!\n");
#endif
 
    return false;
}
 
int main(){
    int n;
    char opcao, str[100];
 
    printf("Digite o tamanho da sua Tabela Hash\n");
    scanf("%d" , &n);
 
    printf("DIGITE\n");
    printf("i para inserir\n");
    printf("p para procurar\n");
    printf("r para retirar\n");
    printf("h para gerar um hash de entrada\n");
    printf("s para sair do programa\n");
 
    Hash *table;
    table = criaTabela(n); // CRIA TABELA
 
    for(;;){
        scanf("%c", &opcao);
 
        if(opcao == 's')
            break;
 
        switch (opcao){
            case 'i':
                scanf("%s", str);
                scanf("%*c");
                printf("%s\n", insere(str, table, n) ? "sim" : "nao");
            break;
 
            case 'p':
                scanf("%s", str);
                scanf("%*c");
                printf("%s\n", procura(str, table, n) ? "sim" : "nao");
            break;
 
            case 'r':
                scanf("%s", str);
                scanf("%*c");
                printf("%s\n", retira(str, table, n) ? "sim" : "nao");
            break;
 
            case 'h':
                scanf("%s", str);
                scanf("%*c");
                printf("%d\n", HASH(strlen(str) , n));
            break;
        }
    }
 
    free(table);
 
    return EXIT_SUCCESS;
}
 
/*
int main(){
    // int i, j;
    // char aux[1000];
    Hash *table;
    table = criaTabela(100); // CRIA TABELA
    char *vaca = "Vaca", *vaca2 = "XANA";
    printf("insere = ? %s\n", insere(vaca, table, 100) ? "sim" : "nao"); // INSERE UMA STRING
    printf("insere = ? %s\n", insere(vaca2, table, 100) ? "sim" : "nao"); // INSERE UMA STRING
    printf("pocura = ? %s\n",  procura(vaca, table, 100) ? "sim" : "nao"); // PROCURA UMA STRING
    printf("retira = ? %s\n", retira(vaca, table, 100) ? "sim" : "nao"); // REMOVE UMA STRING
    printf("procura = ? %s\n",  procura(vaca, table, 100) ? "sim" : "nao"); // PROCURA UMA STRING
 
    free(table);
 
    return EXIT_SUCCESS;
}
*/
