# jogo-da-velha
Jogo da Velha desenvolvido na linguagem C para a displina Algoritmos e Estruturas de Dados II. Possui a implementação de uma inteligência artificial desenvolvida pelo algoritmo minimax.

## Introdução:

A utilização de TADs é amplamente difundida na linguagem C. Trata-se de um
recurso que permite a modularização do código e seu reaproveitamento. Sua
funcionalidade é análoga à das classes nas linguagens orientadas a objeto.
O trabalho em questão aplica isso através da simulação de um jogo da velha que envolve  interação do usuário e até mesmo a criação de uma inteligência artificial
rudimentar para interagir, além de manipulação de arquivos.


## Implementação:
O tipo de dados escolhido para o trabalho foi o vetor de duas dimensões
chamado tab. O usuário digitará um valor N que indicará a dimensão da matriz que será,
então, alocada dinamicamente na memória.

## Funções, variáveis e procedimentos:
O TAD possui três variáveis externas do tipo inteiro, chamadas ERRO, TRUE e
FALSE. Elas foram criadas para aumentar a legibilidade do código e permitir que ele se
torne mais facilmente portável a linguagens diferentes. Mesmo que a linguagem C já
ofereça recursos para retornar verdadeiro ou falso, ao usar variáveis específicas eu deixo
mais claro quando o valor inteiro de retorno tem algum significado ou quando ele
apenas sinaliza verdadeiro ou falso.

As variáveis recebem o modificador extern para permitir que elas, assim como
as funções, sejam inicializadas no .c e não no .h e seus valores escolhidos foram,
respectivamente, -1,1 e 0.

### As funções contidas no TAD são as seguintes:
_void SetTamanho(Tabuleiro *T, int n)_: recebe um tabuleiro por referência e define o
tamanho dele como sendo n. Se n for maior que 10, menor que 0 ou se outra chamada
da função já foi resolvida (o que implica que o vetor já foi alocado), a função retorna
sem fazer nada. Caso contrário, ele aloca dinamicamente a matriz e cada uma de suas
linhas.

_int GetTamanho(Tabuleiro T)_: Recebe um tabuleiro e retorna seu tamanho. Foi feita
para poupar o programador da tarefa de acessar a variável n dentro do tabuleiro, o que
também vai a favor do princípio dos TADs de que é responsabilidade do programador
do TAD criar métodos para obter as características da variável por ele criada.

_void LiberaTamanho(Tabuleiro *T)_: Recebe um tabuleiro por referência e libera a
memória alocada dinamicamente pela função setTamanho. Vale lembrar que, devido a
decisões tomadas na setTamanho, uma vez liberada a memória não poderá ser realocada
na mesma execução do programa, logo, esta função deve ser usada apenas quando se
tem certeza que o vetor não será mais acessado.

_void SetElemento(Tabuleiro *T, int i, int j, char c)_: Recebe um tabuleiro por referência
e posiciona o char c na posição tab[i][j]. Se i e j forem fora dos limites, retorna sem
fazer nada.

_void MarcaTodos(Tabuleiro *T, char c)_: Recebe um tabuleiro por referência e posiciona
o char c em todas as posições do tabuleiro.

_char GetElemento(Tabuleiro T, int i, int j)_: Recebe um tabuleiro e retorna o elemento na
posição tab[i][j]. Similar ao setElemento, esta também verifica se i e j são valores
válidos. Porém, devido ao tipo de retorno, desta vez é retornado um valor de erro
int TestaDiferente(Tabuleiro T, int i): Recebe uma linha i e compara todos os elementos
entre si. Se todos forem diferentes, retorna TRUE. Se houverem dois ou mais iguais,
retorna FALSE. Se i é um valor inválido, retorna ERRO.

_void Imprime(Tabuleiro T)_: Recebe um tabuleiro, itera sobre ele e imprime na tela seus
valores. Valores na mesma linha são separados por um espaço simples e as linhas são
separadas umas das outras por uma quebra de linha.

_int procuraElemento(Tabuleiro T,char c)_: Itera pela matriz à procura de um elemento
equivalente ao parâmetro c. Retorna a primeira aparição dele; caso ele não exista,
retorna erro. Para retornar corretamente o endereço do elemento, o valor correspondente
à linha é multiplicado por 10 e somado à coluna. Por exemplo, se o elemento está na
posição [2][2] o valor retornado é 22.

A pesquisa usada é a pesquisa sequencial. Os valores são comparados um a um
com o parâmetro e quando o sucesso acontece o valor é retornado.

_int TestaLinha(Tabuleiro T, int i, char c)_: Recebe um tabuleiro por valor junto com um
parâmetro para representar a linha e retorna TRUE se todos os valores da linha forem
iguais aos do char, FALSE caso contrário e ERROR caso i seja um valor inválido.

_int testaLinha(Tabuleiro T, int i)_: Recebe um tabuleiro por valor junto com um
parâmetro para representar a linha e retorna TRUE se todos os valores da linha forem
idênticos, FALSE caso contrário e ERROR caso i seja um valor inválido. Difere da
função anterior ao passo em que não se importa se os valores são iguais a um terceiro
parâmetro, apenas entre si.

_int TestaColuna(Tabuleiro T, int j, char c)_: Recebe um tabuleiro por valor junto com um
parâmetro para representar a coluna e retorna TRUE se todos os valores da coluna
forem iguais aos do char, FALSE caso contrário e ERROR caso i seja um valor
inválido.

_int testaColuna(Tabuleiro T, int j)_: Recebe um tabuleiro por valor junto com um
parâmetro para representar a coluna e retorna TRUE se todos os valores da coluna
forem idênticos, FALSE caso contrário e ERROR caso i seja um valor inválido. Difere
da função anterior ao passo em que não se importa se os valores são iguais a um terceiro
parâmetro, apenas entre si.

_int TestaDiagonalED(Tabuleiro T, char c)_: Recebe um tabuleiro por valor retorna TRUE
se todos os valores da diagonal Esquerda-Direita (identificáveis por terem o valor da
linha e da coluna iguais) forem iguais aos do char e FALSE caso contrário.

_int testaDiagonalED(Tabuleiro T)_: Recebe um tabuleiro por valor retorna TRUE se
todos os valores da diagonal Esquerda-Direita (identificáveis por terem o valor da linha
e da coluna iguais) forem iguais e FALSE caso contrário. Difere da função anterior ao
passo em que não se importa se os valores são iguais a um terceiro parâmetro, apenas
entre si.

_int TestaDiagonalDE(Tabuleiro T, char c)_: Recebe um tabuleiro por valor retorna TRUE
se todos os valores da diagonal Direita-Esquerda (identificáveis por terem o valor da
linha e da coluna, somados, igual ao tamanho do vetor menos um) forem iguais aos do
char e FALSE caso contrário.

_int testaDiagonalDE(Tabuleiro T)_: Recebe um tabuleiro por valor retorna TRUE se
todos os valores da diagonal Direita-Esquerda (identificáveis por terem o valor da linha
e da coluna, somados, igual ao tamanho do vetor menos um) forem iguais aos do char e
FALSE caso contrário. Difere da função anterior ao passo em que não se importa se os
valores são iguais a um terceiro parâmetro, apenas entre si.

## Programa Principal – Jogo da velha
Assim como o caça-níqueis, este programa pega os parâmetros a partir da linha
de comando e, fazendo uma análise, decide o que executa.

Se o parâmetro for inválido ou não existir, o jogo padrão é o humano x máquina.
Neste caso, a máquina joga usando o algoritmo recursivo minimax para que seja
virtualmente invencível.

Se o parâmetro for 1, o jogo é o padrão humano x humano. Se for 3, será lido de
um arquivo. Nota-se que, caso a leitura do arquivo termine em erro, seja porque o
arquivo foi inválido, seja porque o arquivo terminou antes que a partida terminasse, o
programa retorna e executa o humano x máquina.

Na hora do jogo em si, algumas decisões foram tomadas para verificar os dados.
Caso os dados sejam inválidos, ambos os valores são descartados o usuário terá novas
chances de inserir valores até que um válido seja devidamente inserido. Em todos os
casos, uma mensagem de erro própria é exibida. É importante mencionar isso porque na
hora de fazer a leitura por arquivo, basta um valor entre linha e coluna ser inválido para
que ambos sejam descartados. Também é importante mencionar que eles são verificados
juntos, ou seja, se seu primeiro parâmetro for inválido e o segundo válido, ele será
descartado mesmo assim.

Por último, é importante já começar a detalhar o funcionamento do minimax,
algoritmo usado para que a máquina jogue. Ele é um algoritmo que identifica a melhor
jogada através da análise recursiva de todas as combinações possíveis. É muito usado na
teoria de jogos para solucionar jogos determinísticos, especialmente aqueles com um
número relativamente pequeno de combinações possíveis, tais como dama e jogo da
velha. Em jogos estocásticos, como o de baralho, e determinísticos porém com ordem
de 10^10 combinações possíveis, tais como xadrez, ele também pode ser usado mas
precisa sofrer ajustes para prever uma jogada tanto quando a informação não é perfeita
quanto quando só é possível prever no máximo 15 jogadas à frente ao invés de quantas
forem necessárias.

### As funções contidas na main são as seguintes:
_void novoJogo(Tabuleiro *T)_: Recebe um tabuleiro, inicializa ele com “_” em todas as
posições e imprime na tela. É a função usada para começar um jogo e reiniciar caso o
anterior tenha sido concluído.

_int isVencedor(Tabuleiro T,char c)_: Verifica as condições de vitória (linha, coluna e
diagonais), retornando 1 caso exista um vencedor e 0 caso contrário.

_void setVencedor(char *c,Tabuleiro *T)_: Função auxiliar que imprime na tela quem
venceu e reinicia o jogo.

_int verificarVencedor(Tabuleiro *T)_: Usa as funções isVencedor, isVelha e
SetVencedor para ver se o jogo acabou e então, caso positivo, reinicia o jogo e retorna
TRUE. Caso contrário, retorna FALSE.

_int isVelha(Tabuleiro T)_: Verifica se todos os quadrados do tabuleiro estão ocupados
por caracteres diferentes de “_”. Se encontra um, retorna FALSE, caso contrário, retorna
TRUE. Importante salientar que, na hora de usar, esta função deve ser chamada depois
das verifica vencedor pois ela vai retornar verdadeiro caso alguém tenha vencido o jogo
no último movimento.

_int jogar(Tabuleiro *T,int lin, int col, char c)_: Função que permita que o jogador
humano jogue. Analisa se as linhas e colunas são válidas e retorna uma mensagem de
erro caso não sejam. Depois analisa se o lugar está vago (isto é, se o caractere na
posição é “_”) e emite uma mensagem de erro. Dado que os dados estejam certos,
posiciona o char c na posição indicada.

_void Jogar(Tabuleiro *T)_: Função usada para que a máquina jogue, ela é responsável
por invocar a função minimax e analisar seus resultados.

_double minimax(Tabuleiro *T,int player)_: Função que define a melhor jogada para a
máquina. É recursiva e sua condição de parada é o jogo chegar a um final, seja este
alguém vencer ou dar velha. Se ela venceu, retorna 1. Se o vencedor foi o oponente,
retorna -1. Se deu velha, retorna 0. Os valores foram multiplicados por um valor
arbitrariamente escolhido baseado na variável player para garantir que, dada duas
escolhas que culminam com um resultado, ele dará preferência para a que garante o
melhor resultado mais rápido ou o pior resultado mais lento.

Para identificar a melhor jogada, é criado um vetor análogo ao tabuleiro
chamado moves, que é então inicializado com um valor pré-definido. O tabuleiro
original é então percorrido, posição por posição, em busca dos espaços vagos,
identificados pelo char “_”. Então, para cada espaço vago, a função minimax se chama
recursivamente, passando como parâmetro o mesmo tabuleiro e um valor inteiro que é o
valor recebido +1. O resultado desta chamada é guardado numa posição análoga no
vetor tabuleiro.

Uma vez que o vetor moves tenha sido preenchido ele é percorrido e a partir
disso a melhor escolha é decidida. A ideia é que, sendo velha um jogo de soma zero
(para alguém vencer, outro tem necessariamente que perder), seu objetivo é maximizar
o seu resultado enquanto o objetivo do oponente é minimizar o resultado para você
(inclusive é disso que vem o nome minimax do algoritmo). Se for a vez do oponente
(identificado a partir do resto da divisão da variável de controle por 2), percorre o vetor
e retorna o resultado mais baixo. Se for a sua vez, percorre o vetor e retorna o resultado
mais alto.

De modo a garantir variedade nas partidas, no caso de várias casas terem igual
possibilidade, ele escolhe aleatoriamente entre elas. Desta forma, isso garante que a
máquina não fará sempre os mesmos movimentos, desde que sejam equivalentes.
Na hora de retornar, se foi uma chamada posterior, retorna o valor obtido para
aquela posição. Agora se foi a primeira chamada, ao invés disso retorna a posição em si
onde deve ser feita a jogada.

_void Um(Tabuleiro *T)_: Função referente ao modo de jogo humano x máquina, definida
como modo 1. Inicia um novo jogo e recebe o endereço da jogada do humano que, caso
seja inválido, poderá jogar novamente. A máquina depois joga usando a função Jogar
que invocará a minimax. Por último, se os jogadores desejarem, poderão jogar
novamente.

_void Dois(Tabuleiro *T)_: Análoga à um, mas ao invés de ser humano x máquina é
humano x humano. As verificações de dados são feitas duas vezes ao invés de apenas
uma o que implica num código com mais linhas mas que não necessariamente é mais
complexo. Assim como no anterior, diversos jogos poderão ser jogados.

_int Tres(Tabuleiro *T,char *file)_: Recebe um arquivo e lê os dados. Se em algum
momento for encontrado um erro, retorna e executa a função Um. Caso contrário, o
arquivo é lido sequencialmente até encontrar um caractere válido (no caso, os números
0, 1 e 2), ignorando todos os outros. O valor é então convertido para inteiro e salvo
numa variável. A partir disso, a execução prossegue como nas funções anteriores.
Organização do Código, Decisões de Implementação e Detalhes Técnicos
Ao fazer o código, como já mencionado, eu optei por usar constantes para
identificar casos em que o valor retornado significava verdadeiro, falso ou erro. Desta
forma, eu não teria dificuldades de diferenciar, ao corrigir o código, um valor de retorno
igual a zero e um valor de retorno igual a falso, que, na linguagem C, são equivalentes.
No caça-níqueis, apesar de os símbolos possíveis serem pré-definidos, o
programa é capaz de reconhecer e julgar os valores independente da simbologia
utilizada. Também optei por, em caso de erro encontrado na leitura de arquivo,
prosseguir com uma execução independente.
No jogo da velha, apesar de não ter sido requisitado, montei um algoritmo que
soluciona ele, o que implica em uma complexidade maior do algoritmo como um todo.

## Análise de Complexidade - TAD:
_void SetTamanho(Tabuleiro *T, int n)_:Executa algumas operações com O(1) para alocar
a matriz e depois itera pelas n linhas para aloca-las dinamicamente, logo, O(n).
int GetTamanho(Tabuleiro T): Retorna apenas um valor independente dos parâmetros,
logo, O(1).

_void LiberaTamanho(Tabuleiro *T)_: Similar à setTamanho, itera pelas n linhas
liberando a memória alocada e depois libera a memória da matriz em si, logo,
complexidade O(n).

_void SetElemento(Tabuleiro *T, int i, int j, char c)_: Executa apenas uma operação de
atribuição que independe dos parâmetros. Complexidade O(1).

_void MarcaTodos(Tabuleiro *T, char c)_: Itera pelas n linhas e n colunas da matriz para
marcar todos os valores. Complexidade O(n²).

_char GetElemento(Tabuleiro T, int i, int j)_: Executa apenas uma operação de retorno que
independe dos parâmetros. Complexidade O(1).

_int TestaDiferente(Tabuleiro T, int i)_: Pega uma linha de tamanho n e itera sobre ela
comparando seus elementos. Complexidade O(n).

_void Imprime(Tabuleiro T)_: Itera pelas n linhas e n colunas imprimindo seus valores.
Complexidade O(n²).

_int procuraElemento(Tabuleiro T,char c)_: Função interessante, itera sobre as linhas e
colunas até encontrar um valor específico e retorna ele. Na melhor das hipóteses o valor
está na primeira posição, o que resultaria numa complexidade O(1). Na pior ele está na
última, o que resultaria numa complexidade O(n²). Já que a notação O especifica um
limite, a complexidade desta função deve ser analisada usando o pior caso, o que resulta
em O(n²).

_int TestaLinha(Tabuleiro T, int i, char c), int TestaColuna(Tabuleiro T, int j, char c), int
testaLinha(Tabuleiro T, int i), int testaColuna(Tabuleiro T, int j)_: Todas essas funções
fazem essencialmente a mesma coisa: iteram sobre uma linha/coluna comparando os
valores entre si. Logo, todas elas possuem um comportamento O(n) no pior caso.

_int TestaDiagonalED(Tabuleiro T, char c), int TestaDiagonalDE(Tabuleiro T, char c),
int testaDiagonalED(Tabuleiro T),i nt testaDiagonalDE(Tabuleiro T)_: De forma análoga
aos anteriores, iteram sobre uma categoria do vetor. Neste caso, porém, trabalha-se com
duas dimensões ao invés de uma o que implica que uma discussão maior sobre o código
pode ser feita. Estas funções iteram simultaneamente sobre as linhas e as colunas; as
funções testaDiagonalED fazem uma iteração com apenas uma variável de controle
enquanto as TestaDiagonalDE fazem uma iteração com duas variáveis de controle. Em
ambos os casos, são feitas apenas O(n) comparações, o que implica em complexidade
final O(n).

## Análise de complexidade – Jogo da velha
_void novoJogo(Tabuleiro *T)_: É a soma da complexidade da função marcaTodos com a
Imprime. O(n²) + O(n²)= O(n²).

_int isVencedor(Tabuleiro T,char c)_: Soma das funções testaDiagonal, testaLinha e
testaColuna, todas O(n), por consequência, esta também é O(n).
void setVencedor(char *c,Tabuleiro *T): Executa função constante e a novoJogo que é
O(n²). Logo, esta também é O(n²).

_int verificarVencedor(Tabuleiro *T)_: Executa várias vezes a função isVencedor e
algumas operações constantes. 3*O(n) + C = O(n).

_int isVelha(Tabuleiro T)_: Itera sobre a matriz inteira atrás dos valores especificados.
Iterar pela matriz é fazer n vezes n comparações, logo, complexidade O(n²).

_int jogar(Tabuleiro *T,int lin, int col, char c)_: Faz verificações de dados de custo
constant e imprime uma vez, operação O(n²). Complexidade O(n²).

_double minimax(Tabuleiro *T,int player)_: Não irei demonstrar, mas a complexidade da
minimax é O(n²).

_void Jogar(Tabuleiro *T)_: Executa funções de custo constante, a minimax que é O(n²) e
a jogar que é O(n²). Complexidade O(n²).

_void Um(Tabuleiro *T)_: Executa, no máximo, n² jogadas. Cada jogada é composta de
uma invocação da função jogar, cuja complexidade é O(n²). No total, temos n²
execuções de algo que é O(n²), totalizando O(n^4).

_void Dois(Tabuleiro *T)_: Executa, no máximo, n² jogadas. Cada jogada é composta de
uma invocação da função jogar, cuja complexidade é O(n²). No total, temos n²
execuções de algo que é O(n²), totalizando O(n^4).

_int Tres(Tabuleiro *T,char *file)_: Análoga às anteriores, executa n² vezes a função jogar
na pior das hipóteses, o que implica O(n^4).

_int main(int argc, char *argv[])_: Não importa qual caminho seja tomado, no fim das
contas uma função O(n^4) será executada. Visto que o que importa é a maior
complexidade, temos uma main que é O(n^4).
