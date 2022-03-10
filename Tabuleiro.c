#include "Tabuleiro.h"

const int ERRO=-1;
const int TRUE=1;
const int FALSE=0;

/*
Função que aloca a memória necessária para o tabuleiro.
Valores menores ou iguais a 0 ou maiores que 10 retornam sem fazer a alocação.

Para esse projeto, estou supondo que o tabuleiro precisará ser definido apenas uma
vez. Por conta disso, uma variável estática será usada para prevenir futuras alocações.

*/
void SetTamanho(Tabuleiro *T, int n) {
    static int cont=0;
    if(n<=0||n>10||cont>0)
        return ;
    (*T).n=n;
    (*T).tab=malloc(n*sizeof(char *));
    int i;
    for(i=0; i<n; i++)
        (*T).tab[i]=malloc(n*sizeof(char));
    cont++;
}
/*
Libera a memória alocada para o tabuleiro.
*/
void LiberaTamanho(Tabuleiro *T) {
    for(int i=0; i<(*T).n; i++) {
        free((*T).tab[i]);
    }
    free((*T).tab);
}

/*
Testa os valores de entrada, caso sejam válidos, coloca o
elemento na posição ij. A função seguinte funciona de forma
análoga, mas retorna o valor
*/
void SetElemento(Tabuleiro *T, int i, int j, char c) {
    if(i<0||i>GetTamanho(*T))
        return ;
    if(j<0||j>GetTamanho(*T))
        return ;
    (*T).tab[i][j]=c;
}

char GetElemento(Tabuleiro T, int i, int j) {
    if(i<0||i>T.n)
        return ERRO;
    if(j<0||j>T.n)
        return ERRO;
    return T.tab[i][j];
}

/*
Retorna o tamanho do tabuleiro. Desta forma, conseguimos
obter seu tamanho sem acessar diretamente a variável, garantindo
menos modificações caso a forma de calcular o tamanho venha a mudar.
*/
int GetTamanho(Tabuleiro T) {
    return T.n;
}


void MarcaTodos(Tabuleiro *T, char c) {
    int i,j;
    for(i=0; i<(*T).n; i++) {
        for(j=0; j<(*T).n; j++) {
            (*T).tab[i][j]=c;
        }
    }
}

/*
As seguintes funções testam linhas e colunas. Elas foram
de certa forma sobrecarregadas.

A primeira sempre inicia com letra minúscula, pega o primeiro
elemento na linha, compara com o restante e só retorna verdadeiro
se todos forem iguais ao primeiro elemento.

A segunda inicia com letra maiúscula e percorre o vetor todo
comparando os elementos com um pré-definido.

Desta forma, reduzimoso tempo de execução da verificação do bingo
que não se importa com qual caractere se repete sem ferir a capacidade
do jogo da velha de verificar corretamente quem venceu.

Testes de consistência foram realizados para garantir a validade de l e col.
*/

int testaLinha(Tabuleiro T, int l) {
    if(l<0||l>T.n)
        return ERRO;
    char c=T.tab[l][0];
    for(int i=1; i<T.n; i++) {
        if(T.tab[l][i]!=c)
            return FALSE;
    }
    return TRUE;
}
int TestaLinha(Tabuleiro T, int l, char c) {
    if(l<0||l>T.n)
        return ERRO;
    for(int i=0; i<T.n; i++) {
        if(T.tab[l][i]!=c)
            return FALSE;
    }
    return TRUE;
}



int testaColuna(Tabuleiro T, int col) {
    if(col<0||col>T.n)
        return ERRO;
    char c=T.tab[0][col];
    for(int i=1; i<T.n; i++) {
        if(T.tab[i][col]!=c)
            return FALSE;
    }
    return TRUE;
}

int TestaColuna(Tabuleiro T, int col, char c) {
    if(col<0||col>T.n)
        return ERRO;

    for(int i=0; i<T.n; i++) {
        if(T.tab[i][col]!=c)
            return FALSE;
    }
    return TRUE;
}


/*
As funções testaDiagonal são similares à testa linha e testa
coluna, no ponto de que foram sobrecarregadas.

Para checar a diagonal principal(ED) comparamos elementos com
i e j iguais enquanto a diagonal inversa é obtida iniciando
pela linha 0, coluna n-1 e percorre até linha n-1,coluna 0.
*/


int testaDiagonalED(Tabuleiro T) {
    char c=T.tab[0][0];
    for(int i=1; i<T.n; i++) {
        if(T.tab[i][i]!=c)
            return FALSE;
    }
    return TRUE;
}


int TestaDiagonalED(Tabuleiro T, char c) {
    for(int i=0; i<T.n; i++) {
        if(T.tab[i][i]!=c)
            return FALSE;
    }
    return TRUE;
}

int testaDiagonalDE(Tabuleiro T) {
    char c =T.tab[0][T.n-1];
    for(int i=1, j=T.n-2; i<T.n&&j>=0; i++,j--) {
        if(T.tab[i][j]!=c)
            return FALSE;
    }
    return TRUE;
}

int TestaDiagonalDE(Tabuleiro T, char c) {
    for(int i=0, j=T.n-1; i<T.n&&j>=0; i++,j--) {
        if(T.tab[i][j]!=c)
            return FALSE;
    }
    return TRUE;
}



/*
Testar diferença é mais fácil que semelhança, porém mais trabalhoso.
É necessário pegar cada elemento e compará-lo com todos os restantes no vetor.
*/

int TestaDiferente(Tabuleiro T, int l) {
    char aux;

    if(l<0||l>T.n)
        return ERRO;

    for(int i=0; i<T.n-1; i++) {
        aux=T.tab[l][i];
        for(int j=i+1; j<T.n; j++) {
            if(T.tab[l][j]==aux)
                return FALSE;
        }
    }
    return TRUE;
}

void Imprime(Tabuleiro T) {
    for(int i=0; i<T.n; i++) {
        for(int j=0; j<T.n; j++) {
            printf("%c ",T.tab[i][j]);
        }
        printf("\n");
    }
}

/*Procura um determinado elemento na matriz e devolve sua ultima aparição. Se ele não existir, retorna o código de erro.
  Para converter a dimensão de dois caracteres em um inteiro, pega-se a linha e multiplica por 10 e soma com a coluna.
 */
int procuraElemento(Tabuleiro T,char c) {
    int end=ERRO;
    for(int i=0; i<T.n; i++) {
        for(int j=0; j<T.n; j++) {
            if(T.tab[i][j]==c)
                end=10*i+j;
        }
    }
    return end;
}



