#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];
int contador[TAM] = {0};
int tamanhos[TAM] = {0};

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao--;
	if(posicao < 0 || posicao > 9)
    	return POSICAO_INVALIDA;

	else if(vetorPrincipal[posicao] != NULL)
    	return JA_TEM_ESTRUTURA_AUXILIAR;

	else if(tamanho < 1)
    	return TAMANHO_INVALIDO;

	else{
		vetorPrincipal[posicao] = (int *)malloc(tamanho * sizeof(int));

        if(vetorPrincipal[posicao] == NULL)
            return SEM_ESPACO_DE_MEMORIA;

 		for(int i=0; i<tamanho; i++)
		    vetorPrincipal[posicao][i] = 0;

		tamanhos[posicao] = tamanho;

    	return SUCESSO;
	}
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else{
        if (vetorPrincipal[posicao] != NULL)
        {
            if(contador[posicao] < tamanhos[posicao]){
                vetorPrincipal[posicao][contador[posicao]] = valor;
                contador[posicao]++;
                return SUCESSO;
            }
            else
                return SEM_ESPACO;
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if(contador[posicao] == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
    else
        contador[posicao]--;
    
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if(contador[posicao] == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
        
    int achou = 0;
    for(int i=0; i<tamanhos[posicao]; i++){
        if(vetorPrincipal[posicao][i] == valor){
            if(i+1 == tamanhos[posicao])
                contador[posicao]--;
            else{
                for(int j=i; j < contador[posicao]; j++){
                    vetorPrincipal[posicao][j] = vetorPrincipal[posicao][j+1];
                }
                contador[posicao]--;
            }
            return SUCESSO;
        }
    }
    
    if(!achou)
        return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    posicao--;
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
    else
        return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
        
    for(int i=0; i<contador[posicao]; i++)
        vetorAux[i] = vetorPrincipal[posicao][i];
        
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
        
    for(int i=0; i<contador[posicao]; i++)
        vetorAux[i] = vetorPrincipal[posicao][i];
        
    int key, j;
    for(int i=0; i<contador[posicao]; i++){
        key = vetorAux[i];
        
        j = i-1;
        
        while (j >= 0 && vetorAux[j] > key) {
            vetorAux[j + 1] = vetorAux[j];
            j = j - 1;
        }
        vetorAux[j + 1] = key;
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int count = 0;
    
    for(int i=0; i<TAM; i++)
        count += contador[i];
    
    if(count == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int n = 0;
        for(int i=0; i<TAM; i++){
            if(vetorPrincipal[i] == NULL)
                continue;
            for(int j=0; j<contador[i]; j++)
                vetorAux[n++] = vetorPrincipal[i][j];
        }
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int count = 0;
    
    for(int i=0; i<TAM; i++)
        count += contador[i];
    
    if(count == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        int n = 0;
        for(int i=0; i<TAM; i++){
            if(vetorPrincipal[i] == NULL)
                continue;
            for(int j=0; j<contador[i]; j++)
                vetorAux[n++] = vetorPrincipal[i][j];
        }

        int key, j;
        for(int i=0; i<n; i++){
            key = vetorAux[i];
            
            j = i-1;
            
            while (j >= 0 && vetorAux[j] > key) {
                vetorAux[j + 1] = vetorAux[j];
                j = j - 1;
            }
            vetorAux[j + 1] = key;
        }
    }
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if((tamanhos[posicao] + novoTamanho) < 1)
        return NOVO_TAMANHO_INVALIDO;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else{
        novoTamanho += tamanhos[posicao];
        int *temp = (int *)realloc(vetorPrincipal[posicao], novoTamanho * sizeof(int));
        
        if(temp == NULL)
            return SEM_ESPACO_DE_MEMORIA;
        
        vetorPrincipal[posicao] = temp;

        if(novoTamanho < tamanhos[posicao])
            contador[posicao] = novoTamanho;
        
        tamanhos[posicao] = novoTamanho;

        return SUCESSO;
    }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;
    if(posicao < 0 || posicao > 9)
        return POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else if(contador[posicao] == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
    else
        return contador[posicao];
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (!inicio || !(*inicio))
        return;

    No *atual = *inicio;
    while (atual != NULL){
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabecote = (No *)malloc(sizeof(No));
    if (!cabecote)
        return NULL;

    cabecote->prox = NULL;
    No *atual = cabecote;
    int listaVazia = 1;

    for (int i = 0; i < TAM; i++){
        if (vetorPrincipal[i] != NULL && contador[i] > 0){
            listaVazia = 0;
            for (int j = 0; j < contador[i]; j++){
                No *novo = (No *)malloc(sizeof(No));
                if (!novo){
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }
                novo->conteudo = vetorPrincipal[i][j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
            }
        }
    }

    if (listaVazia){
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (!inicio || !inicio->prox)
        return;

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL){
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i=0; i<TAM; i++)
        vetorPrincipal[i] = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i=0; i < TAM; i++){
        if(vetorPrincipal[i] != NULL){
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}