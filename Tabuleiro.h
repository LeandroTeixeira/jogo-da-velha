/*
O .h � um tanto objetivo e dispensa poucos coment�rios, mas � importante j� salientar
que as opera��es SetTamanho, SetElemento e MarcaTodos foram definidas como inteiras
(e n�o voids, como originalmente previsto) para facilitar um tratamento de erros
que n�o culmine necessariamente em t�rmino repentino do programa. Elas retornar�o um valor
para indicar erro abrupto.

Para fins pr�ticos, ao inv�s de usar um valor arbitr�rio para apontar erros, optei por
incluir uma nova vari�vel constante no .c com o valor definido. Desta forma, caso o valor
se mostre inapropriado, a corre��o pode ser transmitida de forma mais r�pida e eficiente
ao resto do programa.

Seguindo a mesma linha e para evitar potenciais erros dado que agora temos um valor inteiro
com um significado diferente de verdadeiro ou falso, verdadeiro e falso foram definidas como
vari�veis constantes. Isso n�o s� corrige os problemas que poderiam decorrer de um valor inteiro
ter um terceiro significado como tamb�m aumenta a portabilidade desse algoritmo para linguagens
em que verdadeiro e falso s�o termos suportados.

GetTamanho foi adicionada para acessar o tamanho da matriz sem acessar a vari�vel.
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
Fun��o procuraElemento adicionada. Ela busca um elemento espec�fico e retorna
sua �ltima apari��o, ERRO caso ele n�o seja encontrado.
*/
int procuraElemento(Tabuleiro T,char c);

/*
Fun��es testalinha, testacoluna e testadiagonal foram "sobrecarregadas".
A vers�o que come�a com letra min�scula ir� apenas verificar se todas as
vari�veis num determinado contexto s�o iguais. A que come�a com letra
mai�scula recebe um par�metro adicional, um caractere, e retornar�
verdadeiro apenas se todos os valores forem iguais �quele caractere.
*/



int TestaLinha(Tabuleiro T, int i, char c);

int TestaColuna(Tabuleiro T, int j, char c);

int TestaDiagonalED(Tabuleiro T, char c);

int TestaDiagonalDE(Tabuleiro T, char c);

int testaLinha(Tabuleiro T, int i);

int testaColuna(Tabuleiro T, int j);

int testaDiagonalED(Tabuleiro T);

int testaDiagonalDE(Tabuleiro T);




