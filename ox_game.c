#include <stdio.h>
#include <stdlib.h>

void print_board(){
  printf("  A   B   C   D   E   F   G\n");
  for(int i=0;i<13;i++){
    for(int j=0;j<7;j++){
      if(i%2==0 && j==0){
        printf("|---|");
      }
      else if(i%2==0 && j!=0){
        printf("---|");
        
      }
      else if(i%2==1 && j==0){
        printf("| %c |",' ');
      }
      else if(i%2==1 && j!=0){
        printf(" %c |",' ');
      }
      if(j==6){
        printf("\n");
      }
    }
  }
  printf("\n");
}

void play_pp(){
  system("clear");
  char go;
  print_board();
  printf("Where do you want to go(A-G)?\n>>");
  scanf("%c",&go);
}

int menu(){
  int choice;
  printf(" ,-----.,--.   ,--.     ,----.\n");
  printf("'  .-.  '\\  `.'  /     '  .-./    ,--,--.,--,--,--. ,---.\n");
  printf("|  | |  | .'    \\      |  | .---.' ,-.  ||        || .-. :\n");
  printf("'  '-'  '/  .'.  \\     '  '--'  |\\ '-'  ||  |  |  |\\   --.\n");
  printf(" `-----''--'   '--'     `------'  `--`--'`--`--`--' `----' \n");
  printf("===========================================================\n");
  printf("Select Menu\n");
  printf("[1] Player vs Computer\n");
  printf("[2] Player vs Player\n");
  printf("[3] Exit\n");
  printf("Choose: ");
  scanf("%d",&choice);
  if(choice==1){
    system("clear");
    choice = 2;
  }
  else if(choice==2){
    system("clear");
    choice = 3;
  }
  else if(choice==3){
    system("clear");
    exit(0);
  }
  return choice;
}

int menu_pp(){
  char name1[1000],name2[1000];
  print_board();
  printf("Player 1: ");
  scanf("%s",name1);
  printf("Player 2: ");
  scanf("%s",name2);
  while(1){
    play_pp();
  }
  return 0;
}

int menu_pc(){
  return 0;
}

void ox_game(){
  system("clear");
  int choice = 1;
  while(1){
    if(choice==1){
      choice = menu();
    }
    else if(choice==2){
      choice = menu_pc();
    }
    else if(choice==3){
      choice = menu_pp();
    }
  } 
}

int main(){
  system("clear");
  ox_game();
  return 0;
}
                                                