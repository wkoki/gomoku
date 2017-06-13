#include <stdio.h>


// ----------Define---------- //
#define False 0
#define True 1
#define o 1
#define x 2
#define Human 0
#define AI 1
#define Random 2

// ----------Setting---------- //
#define BOARD_SIZE 10
#define Player1 Human
#define Player2 Human

// ----------Global Variables---------- //
int board[BOARD_SIZE][BOARD_SIZE];



// -----------Prototype Decleration---------- //
void game(void);
void init(void);
char _show(int);
void show(void);
void put(int, int);
void human_put(int);
int judge(void);


// ----------Main---------- //
int main(int argc, char *argv[]){
  init();
  game();
}



// ----------Functions---------- //
void init(void) {
  for(int i = 0; i < BOARD_SIZE; i++) {
    for(int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

void game(void) {
  printf("ゲームスタート\n");
  do{
    show();
    put(Player1, o);
    show();
    put(Player2, x);
  }while(judge());
}

char _show(int ox){
  switch(ox){
  case 0: return ' ';
  case 1: return 'o';
  case 2: return 'x';
  default: return 'E';
  }
}


void show(void) {
  for(int i = 0; i < BOARD_SIZE; i++) {

    for(int j = 0; j < BOARD_SIZE; j++) {
      printf("+-");
    }printf("+\n");

    for(int j = 0; j < BOARD_SIZE; j++) {
      printf("|%c", _show(board[j][i]));
    }printf("|\n");

  }

  for(int j = 0; j < BOARD_SIZE; j++) {
    printf("+-");
  }printf("+\n");
}


int judge(int row, int col, int ox) {
  int liner = 0;

}

void put(int player, int ox) {

  switch(player){
  case Human:
    human_put(ox);
    break;

  default:
    break;
  }
}

void human_put(int ox) {
  int row, col;
  printf("横列：");
  scanf("%d", &row);
  printf("縦列：");
  scanf("%d", &col);
  board[row][col] = ox;
}


