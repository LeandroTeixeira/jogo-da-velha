/*
O .h é um tanto objetivo e dispensa poucos comentários, mas é importante já salientar
que as operações SetTamanho, SetElemento e MarcaTodos foram definidas como inteiras
(e não voids, como originalmente previsto) para facilitar um tratamento de erros
que não culmine necessariamente em término repentino do programa. Elas retornarão um valor
para indicar erro abrupto.

Para fins práticos, ao invés de usar um valor arbitrário para apontar erros, optei por
incluir uma nova variável constante no .c com o valor definido. Desta forma, caso o valor
se mostre inapropriado, a correção pode ser transmitida de forma mais rápida e eficiente
ao resto do programa.

Seguindo a mesma linha e para evitar potenciais erros dado que agora temos um valor inteiro
com um significado diferente de verdadeiro ou falso, verdadeiro e falso foram definidas como
variáveis constantes. Isso não só corrige os problemas que poderiam decorrer de um valor inteiro
ter um terceiro significado como também aumenta a portabilidade desse algoritmo para linguagens
em que verdadeiro e falso são termos suportados.

GetTamanho foi adicionada para acessar o tamanho da matriz sem acessar a variável.
*/

typedef struct {
    char** tab;
    int n;
} Tabuleiro;
extern const int ERRO;
extern const int TRUE;
extern const int FALSE;

void SetTamanho(Tabuleiro *T, int n);

int GetTamanho(Tabuleiro T);

void LiberaTamanho(Tabuleiro *T);

void SetElemento(Tabuleiro *T, int i, int j, char c);

void MarcaTodos(Tabuleiro *T, char c);

char GetElemento(Tabuleiro T, int i, int j);

int TestaDiferente(Tabuleiro T, int i);

void Imprime(Tabuleiro T);


/*
Função procuraElemento adicionada. Ela busca um elemento específico e retorna
sua última aparição, ERRO caso ele não seja encontrado.
*/
int procuraElemento(Tabuleiro T,char c);

/*
Funções testalinha, testacoluna e testadiagonal foram "sobrecarregadas".
A versão que começa com letra minúscula irá apenas verificar se todas as
variáveis num determinado contexto são iguais. A que começa com letra
maiúscula recebe um parâmetro adicional, um caractere, e retornará
verdadeiro apenas se todos os valores forem iguais àquele caractere.
*/



int TestaLinha(Tabuleiro T, int i, char c);

int TestaColuna(Tabuleiro T, int j, char c);

int TestaDiagonalED(Tabuleiro T, char c);

int TestaDiagonalDE(Tabuleiro T, char c);

int testaLinha(Tabuleiro T, int i);

int testaColuna(Tabuleiro T, int j);

int testaDiagonalED(Tabuleiro T);

int testaDiagonalDE(Tabuleiro T);




