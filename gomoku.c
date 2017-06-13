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
int rating_board[BOARD_SIZE][BOARD_SIZE];
int selected_row, selected_col;


// -----------Prototype Decleration---------- //
void init(void);
void game(void);
char _show(int);
void show(void);
int judge(int, int, int);
int judge_row(int, int, int);
int judge_col(int, int, int);
int judge_right_slant(int, int, int);
int judge_left_slant(int, int, int);
void put(int, int);
void human_put(int);
void ai_put(int);
void reach(int, int, int);
int reach_point(int, int, int);
int reach_row(int, int, int);
int reach_col(int, int, int);
int reach_right_slant(int, int, int);
int reach_left_slant(int, int, int);

// ----------Structure---------- //
struct pos {
  int row;
  int col;
};


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
  show();
  while(True){
    put(Player1, o);
    if(judge(selected_row, selected_col, o)){
      printf("Player1の勝利\n");
      break;
    }
    show();
    put(Player2, x);
    if(judge(selected_row, selected_col, x)){
      printf("Player2の勝利\n");
      break;
    }
    show();
  }
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
  if(judge_row(row, col, ox)){
    return True;
  }
  if(judge_col(row, col, ox)){
    return True;
  }
  if(judge_right_slant(row, col, ox)){
    return True;
  }
  if(judge_left_slant(row, col, ox)){
    return True;
  }

  return False;
}

int judge_row(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 4) {
    return True;
  } else {
    return False;
  }

}



int judge_col(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row][col+i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row][col-i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 4) {
    return True;
  } else {
    return False;
  }
}

int judge_right_slant(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col+i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col-i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 4) {
    return True;
  } else {
    return False;
  }
}



int judge_left_slant(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col-i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col+i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 4) {
    return True;
  } else {
    return False;
  }
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
  printf("横列：");
  scanf("%d", &selected_row);
  printf("縦列：");
  scanf("%d", &selected_col);
  board[selected_row][selected_col] = ox;
}

void ai_put(int ox) {

}

void reach(int ox) {
  for(int row = 0; row < BOARD_SIZE; row++) {
    for(int col = 0; col < BOARD_SIZE; col++) {
      if(board[row][col] == 0) {
        if(reach_point(row, col, ox)) {
          rating_board[row][col] == 100;
        }
      }
    }
  }
}

int reach_point(int row, int col, int ox) {
  if(judge_row(row, col, ox)){
    return True;
  }
  if(judge_col(row, col, ox)){
    return True;
  }
  if(judge_right_slant(row, col, ox)){
    return True;
  }
  if(judge_left_slant(row, col, ox)){
    return True;
  }
  return False;
}

int reach_row(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 3) {
    return True;
  } else {
    return False;
  }

}



int reach_col(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row][col+i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row][col-i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 3) {
    return True;
  } else {
    return False;
  }
}

int reach_right_slant(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col+i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col-i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 3) {
    return True;
  } else {
    return False;
  }
}



int reach_left_slant(int row, int col, int ox) {
  int liner = 0;

  for(int i = 1; i < 5; i++){
    if(board[row][col] == board[row+i][col-i]) {
      liner++;
    } else {
      break;
    }
  }

  for(int i = 1; i < 5; i++) {
    if(board[row][col] == board[row-i][col+i]){
      liner++;
    } else {
      break;
    }
  }

  if(liner >= 3) {
    return True;
  } else {
    return False;
  }
}

