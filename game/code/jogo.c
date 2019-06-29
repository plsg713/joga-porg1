#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int i= 1;//posição da linha onde o personagem começa
int j= 0;// posição da coluna onde o personagem começa
int x=18;//posição da linha onde o inimigo começa 
int y=12;//posição da coluna onde o inimigo começa
int mapa[20][16];
char fase=1;
time_t seconds;
time_t actual;

 int mapa1[20][16] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1},
{1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1},
{1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1},
{1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1},
{1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1},
{1,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1},
{1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

 };
int mapa2[20][18] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
{1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1},
{1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
{1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
{1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1},
{1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1},
{1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1},
{1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1},
{1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1},
{1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1},
{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
{1,0,0,0,0,0,0,1,1,0,0,0,0,0,2,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
 };
 int mapa3[20][16] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
{1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
{1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
{1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
{1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
{1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
{1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,1},
{1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1},
{1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,2,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
 };



 void labirinto()
 {
   int linha,coluna;

    if(fase==1){
     for (linha=0;linha<20;linha++) {
       for (coluna=0;coluna<16;coluna++) {
            mapa[linha][coluna]=mapa1[linha][coluna];
            }
          }
        }
     if(fase==2){
       for (linha=0;linha<20;linha++) {
        for (coluna=0;coluna<16;coluna++) {
            mapa[linha][coluna]=mapa2[linha][coluna];
           }
         }
       }
       if (fase==3){
        for (linha=0;linha<20;linha++) {
         for (coluna=0;coluna<16;coluna++) {
            mapa[linha][coluna]=mapa3[linha][coluna];
            }
          }
       }
          for (linha=0;linha<20;linha++) {
            for (coluna=0;coluna<16;coluna++) {
              if ((linha == i) && (coluna == j)) {
                 printf("\033[1;35m");
                 printf("^");
                 printf("\033[0m");
                continue;
                }
                if ((linha == x) && (coluna == y)) { 
                 printf("\033[1;35m");
                 printf("▓");
                 printf("\033[0m");
                 continue;
                }
              if (mapa[linha][coluna] == 0) //"0" indica o caminho
                 printf(" ");
              if (mapa[linha][coluna] == 1)// "1" indica a parede
                 {printf("\033[1;31m");
                 printf("▓");
                printf("\033[0m");}
              if (mapa[linha][coluna] == 2)// "2" indica a saida
                 {printf("\033[1;32m");
                  printf("▓");
                  printf("\033[0m");}
                }
            printf("\n");
         }
    }
 int move_enemy(){
 char movimentoE= rand()%4;
    if(movimentoE==0){ 
            if(mapa[x-1][y]==0){
            mapa[x][y]=0;
            x=x-1;
            }else if ((mapa[x-1][y]==1)||(mapa[x-1][y]==2)){
            }
    }
    if(movimentoE==1){
            if(mapa[x+1][y]==0){ 
            mapa[x][y]=0;
            x=x+1;
            }else if ((mapa[x+1][y]==1)||(mapa[x+1][y]==2)){
            }
    }
   if(movimentoE==2){
    if(mapa[x][y-1]==0){
        mapa[x][y]=0;
        y=y-1;
    }else if ((mapa[x][y-1]==1)||(mapa[x][y-1]==2)){
  }
 }
 if(movimentoE==3){
    if(mapa[x][y+1]==0){
     mapa[x][y]=0;
        y=y+1;
        }else if (mapa[x][y+1]==1){}
         else if (mapa[x][y+1]==2){}
    }
     if(i == x && j == y){
     system("clear");
     char debug; i=1;j=0;x=1;y=2; 
     fase = 1; 
     while(debug != 'r'){
     scanf("%c",&debug); 
printf("                                   \n"); usleep (100000);
printf("         #######                   \n"); usleep (100000);
printf("        #       #                  \n"); usleep (100000);
printf("       #  R I P  #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("    #################              \n"); usleep (100000);
printf(" ###                 ###           \n"); usleep (100000);
printf(" ------VOCÊ PERDEU------           \n"); usleep (100000);
     if(debug == 'x')
       exit(0);} }
}


int move(char movimento)// função para os movimentos dos personagem.
{
       if (movimento == 'w') { 
          if (mapa[i-1][j]==0){
            system("\abeep");
            mapa[i][j]=0;
            i = i-1;

          }else if (mapa[i-1][j]==1){   
         }
            else if (mapa[i-1][j]==2){
          	return 1;
            }
           }
        if (movimento == 's')  {
          if (mapa[i+1][j]==0){
            system("\abeep");
            mapa[i][j]=0;
            i= i+1;
           }else if(mapa[i+1][j]==1){
           }else if(mapa[i+1][j]==2){
         	 return 1;
                }
              }
        if (movimento == 'd') {
          if(mapa[i][j+1]==0){
            system("\abeep");
            mapa[i][j]=0;
            j=j+1;
       }else if(mapa[i][j+1]==1){
       }else if (mapa[i][j+1]==2){
           return 1;
              }
            }
        if (movimento == 'a') {
         if(mapa[i][j-1]==0){
            system("\abeep");
            mapa[i][j]=0;
            j=j-1;
       }else if (mapa[i][j-1]==1){

        }else if(mapa[i][j-1]==2){
          system("clear");
          
               return 1;
        }
 }
    if(i == x && j == y){
    system("clear");
    char debug; 
    i=1;j=0;x=18;y=12; 
    fase = 1; 
    while(debug != 'r'){
    scanf("%c",&debug); 
    system("clear");
printf("                                   \n"); usleep (100000);
printf("         #######                   \n"); usleep (100000);
printf("        #       #                  \n"); usleep (100000);
printf("       #  R I P  #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("       #         #                 \n"); usleep (100000);
printf("    #################              \n"); usleep (100000);
printf(" ###                 ###           \n"); usleep (100000);
printf(" ------VOCÊ PERDEU------           \n"); usleep (100000);
    if(debug == 'x') 
    exit(0);}seconds = time(NULL); }
	return 0;

}

   int timer()
{
	actual = time(NULL);
	int now = (int)difftime(actual,seconds);
	return now;
}



void main()
{
    //menu
    int opcao,decisao;
    char movimento;
    system("clear");
    printf("                                                                                                                   \n"); 
printf("     ########## ##      ## #########                                                                               \n"); 
printf("         ##     ##      ## ##                                                                                      \n"); 
printf("         ##     ########## ########                                                                                \n"); 
printf("         ##     ##      ## ##                                                                                      \n");
printf("         ##     ##      ## #########                                                                               \n");

printf("                                                                                                                   \n"); 
printf("                 ########## ########## ########## ########## ########## ##########                                 \n"); 
printf("                 ##         ##         ##      ## ##      ## ##             ##                                     \n"); 
printf("                 ########## ##         ########## ########## ##########     ##                                     \n"); 
printf("                         ## ##         ##      ## ##                 ##     ##                                     \n"); 
printf("                 ########## ########## ##      ## ##         ##########     ##                                     \n");
printf("                                                                                                                   \n");

    printf("                             \n1 - JOGAR \n2 - INTRUCOES \n3 - SAIR\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        system("clear");
        seconds=time(NULL);
        while (1){
        system("clear");
        printf("\t   Time:%d\n", timer());
        move_enemy();
        printf("                                                                \n");
        labirinto();
        printf("\n Aperte (x) para sair do Jogo");
        scanf("%c", &movimento);
        if(movimento=='x') break;
         else if(move(movimento) == 1){
          fase+=1;
          i=1;
          j=0;	
   if(fase>3){
     system("clear");
     printf(" Parabéns, você terminou!!!");
     printf("tempo:%d segundos", timer());
        break;
	}
      }
    }
        break;
    case 2:
        system("clear");
        printf(" O jogo consiste em um labirinto de três fases. O objetivo do jogo é passar as três fases no menor tempo possível, \n");
         printf(" e sem tocar no inimigo que se move de forma pseudo aleatória.                                                     \n");
         printf("                                                                                                                   \n");      
         printf("                                  -------------------                                                              \n");       
         printf("                                 | Teclas de Controle|                                                             \n");
         printf("                                  -------------------                                                         \n");                   
         printf("                                                                                                                   \n");
         printf("                                           (W)                                                                     \n");
         printf("                                       (A)     (D)                                                                 \n");
         printf("                                           (S)                                                                     \n"); 
        
        return;
    case 3:
        system("clear");
        break;
   
    }
}








    
   



   
