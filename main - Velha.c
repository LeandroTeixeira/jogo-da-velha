#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Tabuleiro.h"

//Funcao novoJogo, sinaliza que todas as posicoes est�o livres e imprime o tabuleiro
void novoJogo(Tabuleiro *T) {
    MarcaTodos(T, '_');
    Imprime(*T);
    printf("\n");
}

//Dado um tabuleiro e um caractere, verifica se aquele caractere venceu o jogo
int isVencedor(Tabuleiro T,char c) {
    return (TestaDiagonalDE(T, c) || TestaDiagonalED(T, c) || TestaColuna(T, 0, c)
            || TestaColuna(T, 1, c) || TestaColuna(T, 2, c) || TestaLinha(T, 0, c)
            || TestaLinha(T, 1, c) || TestaLinha(T, 2, c));
}

//Exibe a mensagem e come�a um novo jogo
void setVencedor(char *c,Tabuleiro *T) {
    printf("O vencedor foi: %s !\n", c);
    novoJogo(T);
}


int verificarVencedor(Tabuleiro *T) {
    if (isVencedor(*T,'X')) {
        setVencedor("X",T);
        return TRUE;
    } else if (isVencedor(*T,'O')) {
        setVencedor("O",T);
        return TRUE;
    } else if (isVelha()) {
        setVencedor("Ninguem, deu velha",T);
        return TRUE;
    }
    return FALSE;
}

/*
Ambas as fun��es verificam se o jogo da velha terminou empatado. Uma
faz uma an�lise a partir do tabuleiro enquanto a outra analisa a partir de um vetor.
*/
int isVelha(Tabuleiro T) {
    for (int i = 0; i < GetTamanho(T); i++) {
        for (int j = 0; j < GetTamanho(T); j++) {
            if (GetElemento(T,i,j) == '_') {
                return FALSE;
            }
        }
    }
    return TRUE;
}


//Analisa se a jogada � v�lida. Se for, coloca o char do jogador atual naquela posicao. Caso contr�rio, retorna mensagem de erro
int jogar(Tabuleiro *T,int lin, int col, char c) {
    if (col >= GetTamanho(*T) || lin >= GetTamanho(*T)) {
        printf("Jogada invalida! -- posicao fora do tabuleiro \n");
        Imprime(*T);
        printf("\n");
        return FALSE;
    }
    if(GetElemento(*T,lin, col) != '_') {
        printf("Jogada invalida! -- Elemento %c ja esta na posicao %d %d\n",GetElemento(*T,lin,col),lin,col);
        Imprime(*T);
        printf("\n");
        return FALSE;
    }

    else {
        SetElemento(T, lin, col, c);
        Imprime(*T);
        printf("\n");
        return TRUE;
    }
}


//Fun��es que fazem a m�quina jogar
void Jogar(Tabuleiro *T);
double minimax(Tabuleiro *T,int player);

void Um(Tabuleiro *T);
void Dois(Tabuleiro *T);
int Tres(Tabuleiro *T,char *file);

int main(int argc, char *argv[]) {
    Tabuleiro T;
    char *nome;
    int l,c;
    int modo=atoi(argv[1]);
    SetTamanho(&T,3);

    if(modo==3) {
        nome=argv[2];
        modo=Tres(&T,nome);
    }
    if(modo==2) {
        Dois(&T);
    }
    if(modo!=3&&modo!=2) {
        Um(&T);
    }



    /*  while(1) {
          do {
              scanf("%d",&l);
              scanf("%d",&c);
          } while(!jogar(&T,l, c,'X'));
          Jogar(&T);
      }
    */


}

void Um(Tabuleiro *T) {
    int check;//vari�vel para definir se o jogador quer jogar novamente
    int l,c;//linha e coluna, vari�veis de jogo
    printf("Modo escolhido: Humano x Maquina\n\n");
    novoJogo(T);
    do {
        do {
            do {
                printf("Digite onde deseja jogar: \n");
                scanf("%d",&l);
                scanf("%d",&c);
            } while(!jogar(T,l, c,'X'));

            if(verificarVencedor(T)==FALSE)//Se o primeiro player n�o venceu, d� chance para o segundo jogar
                Jogar(T);

        } while(verificarVencedor(T)==FALSE);
        printf("Deseja jogar novamente? 0 para sair, qualquer valor para continuar ");
        scanf("%d",&check);
    } while(check!=0);
}

void Dois(Tabuleiro *T) {
    int check;//vari�vel para definir se o jogador quer jogar novamente
    int l,c;//linha e coluna, vari�veis de jogo
    printf("Modo escolhido: Humano x Humano\n\n");
    novoJogo(T);
    do {
        do {
            do {
                printf("X, Digite onde deseja jogar: \n");
                scanf("%d",&l);
                scanf("%d",&c);
            } while(!jogar(T,l, c,'X'));
            //Se o primeiro player n�o venceu, d� chance para o segundo jogar
            if(verificarVencedor(T)==FALSE) {
                do {
                    printf("O, Digite onde deseja jogar: \n");
                    scanf("%d",&l);
                    scanf("%d",&c);
                } while(!jogar(T,l, c,'O'));
            }
        } while(verificarVencedor(T)==FALSE);
        printf("Deseja jogar novamente? 0 para sair, qualquer valor para continuar ");
        scanf("%d",&check);
    } while(check!=0);
}

int Tres(Tabuleiro *T,char *file) {
    int l,c;
    int ver;//int verificador que confere se o jogo j� acabou
    char aux;
    FILE *arq;
    arq=fopen(file,"r");
    if (arq==NULL)
        return ERRO;
    printf("Modo escolhido: Arquivo\n\n");
    novoJogo(T);


    /*
    Recebe as jogadas dos jogadores. Para cada valor, aplica um teste de consist�ncia e s� aceita valores de acordo ou indica��o
    de fim do arquivo, o que resulta em um retorno.

    */
    do {
        printf("X, Digite onde deseja jogar: \n");
        do {
            do {
                aux=fgetc(arq);
                if(feof(arq))
                    return ERRO;
            } while(aux!='0'&&aux!='1'&&aux!='2');
            l=aux-'0';
            do {
                aux=fgetc(arq);
                if(feof(arq))
                    return ERRO;
            } while(aux!='0'&&aux!='1'&&aux!='2');
            c=aux-'0';
            printf("%d %d\n",l,c);
        } while(!jogar(T,l, c,'X'));
        ver=verificarVencedor(T);

        //Se o primeiro player n�o venceu, d� chance para o segundo jogar. Desta forma, evita-se "empates" em que ambos vencem

       if(ver==FALSE) {
            do {
                printf("O, Digite onde deseja jogar: \n");
                do {
                    aux=fgetc(arq);
                    if(feof(arq))
                        return ERRO;
                } while(aux!='0'&&aux!='1'&&aux!='2');
                l=aux-'0';
                do {
                    aux=fgetc(arq);
                    if(feof(arq))
                        return ERRO;
                } while(aux!='0'&&aux!='1'&&aux!='2');
                c=aux-'0';
                printf("%d %d\n",l,c);
            } while(!jogar(T,l, c,'O'));
            ver=verificarVencedor(T);
        }
    } while(ver==FALSE);
    return 3;

}


void Jogar(Tabuleiro *T) {
    int jogada;
    jogada=minimax(T,0);
    printf("%d %d\n",jogada/10,jogada%10);
    jogar(T,jogada/10, jogada%10, 'O');
}


double minimax(Tabuleiro *T,int player) {
    srand(time(NULL));
    //Se o campo atual implica em fim de jogo, retorna um valor
    if(isVencedor(*T,'O'))
        return 10/(player+1)*1;
    if(isVencedor(*T,'X'))
        return 10/(player+1)*-1;
    if(isVelha(*T))
        return 0;
    //Vari�vel que guarda um valor que indica o qu�o bom � o movimento em uma dada posi��o. Posi��es ocupadas possuem valor fixo 10.
    double moves[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            moves[i][j]=10;
        }
    }
    /*
    Itera sobre cada posi��o na matriz para verificar se � um espa�o livre e a partir disso itera sobre cada espa�o livre.
    � neste ponto que a fun��o se chama recursivamente.
    Os valores s�o guardados no vetor moves.
    */
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(GetElemento(*T,i,j)=='_') {
                if(player%2==0)
                    SetElemento(T,i,j,'O');
                else
                    SetElemento(T,i,j,'X');
                double result=minimax(T,player+1);
                SetElemento(T,i,j,'_');
                moves[i][j]=result;
            }
        }
    }

    /*
    Se o jogador atual � a AI, pressup�e-se que ela tomar� a melhor decis�o dispon�vel.
    Se o jogador atual for o humano, pressup�e-se que ele tomar� a pior decis�o dif�cil (no ponto de vista da AI).
    */
    int ml;
    int mc;
    if(player%2==0) {
        int mv=-50;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                //Para garantir a diversidade de movimentos, se os valores forem iguais, ela tem 50% de chance de trocar
                if(moves[i][j]==mv&&moves[i][j]<10) {
                    if(rand()%3==0) {
                        ml=i;
                        mc=j;
                        mv=moves[ml][mc];
                    }
                }
                if(moves[i][j]>mv&&moves[i][j]<10) {
                    ml=i;
                    mc=j;
                    mv=moves[ml][mc];
                }
            }
        }
    } else {
        int mv=9999;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                //Para garantir a diversidade de movimentos, se os valores forem iguais, ela tem 50% de chance de trocar
                if(moves[i][j]==mv&&moves[i][j]<10) {
                    if(rand()%3==0) {
                        ml=i;
                        mc=j;
                        mv=moves[ml][mc];
                    }
                }
                if(moves[i][j]<mv) {
                    ml=i;
                    mc=j;
                    mv=moves[ml][mc];
                }
            }
        }
    }
    /*
    Se o jogador � zero, isso quer dizer que a vari�vel que queremos retornar � o endere�o da melhor jogada. Caso contr�rio, nos basta seu valor.
    */
    if(player==0)
        return ml*10+mc;
    else
        return moves[ml][mc];
}
