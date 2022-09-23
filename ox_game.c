#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//define function
void menu_main();
void menu_pvc();
void menu_pvp();
void menu_exit();

//render
void render_menu(){
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
}

void render_board(char ox[6][7]){
  printf("  A   B   C   D   E   F   G\n");
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			for(int k=0;k<7 && j==0;k++){
				if(k==0) printf("|");
				printf("---|");
				if(k==6) printf("\n");
			}
			if(j==0) printf("|");
			printf(" %c |",ox[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<7;i++){
		if(i==0) printf("|");
		printf("---|");
		if(i==6) printf("\n");
	}
	for(int i=0;i<29;i++){
		printf("=");
		if(i==28) printf("\n");
	}
}

void render_pvp_result(char ox[6][7],char pl[1000]){
  render_board(ox);
  printf("!!! The Winner is %s !!!\n\n",pl);
  printf("Select Menu\n");
	printf("[1] Restart\n");
	printf("[2] Menu\n");
	printf("Choose: ");
}

//game engine
int is_bingo(char ox[6][7]){
  //check col
	int isBingo = 0;
  for(int i=0;i<7 && !isBingo;i++){
    for(int j=5;j>=3;j--){
      if(ox[j][i]==ox[j-1][i] &&
          ox[j-1][i]==ox[j-2][i] &&
          ox[j-2][i]==ox[j-3][i] &&
          ox[j][i]!=' ' && ox[j-1][i]!= ' ' &&
          ox[j-2][i]!=' ' && ox[j-3][i] != ' ')
        isBingo = 1;
    }
  }	
  //check row
  for(int i=5;i>=0 && !isBingo;i--){
    for(int j=0;j<4;j++){
      if(ox[i][j]==ox[i][j+1] &&
          ox[i][j+1]==ox[i][j+2] &&
          ox[i][j+2]==ox[i][j+3] &&
          ox[i][j]!=' ' && ox[i][j+1]!= ' ' &&
          ox[i][j+2]!=' ' && ox[i][j+3] != ' ')
        isBingo = 1;
    }
  }
  //check left to right diagonal
  for(int i=5;i>=3 && !isBingo;i--){
    for(int j=0;j<4;j++){
      if(ox[i][j]==ox[i-1][j+1] &&
          ox[i-1][j+1]==ox[i-2][j+2] &&
          ox[i-2][j+2]==ox[i-3][j+3] &&
          ox[i][j]!=' ' && ox[i-1][j+1]!= ' ' &&
          ox[i-2][j+2]!=' ' && ox[i-3][j+3] != ' ')
        isBingo = 1;
    }
  }
  //check right to left diagonal
  for(int i=5;i>=3 && !isBingo;i--){
    for(int j=3;j<=6;j++){
      if(ox[i][j]==ox[i-1][j-1] &&
          ox[i-1][j-1]==ox[i-2][j-2] &&
          ox[i-2][j-2]==ox[i-3][j-3] &&
          ox[i][j]!=' ' && ox[i-1][j-1]!= ' ' &&
          ox[i-2][j-2]!=' ' && ox[i-3][j-3] != ' ')
        isBingo = 1;
    }
  }
 return isBingo;
}

int comp_select(char ox[6][7]){
	int free[7],len=0,drop;
	for(int i=0;i<7;i++){
		if(ox[0][i]==' '){
			free[len]=i;
			len++;
		}
	}
	drop = free[rand() % len];
  return drop;
}

//sub menu
void menu_pvp_result(char ox[6][7],char pl[1000]){
  system("clear");
  int select;
  render_pvp_result(ox,pl);
  scanf("%d",&select);
  if(select==1){
    menu_pvp();
  }
  else if(select==2){
    menu_main();
  }
}

void menu_pvc_result(char ox[6][7],char pl[1000]){
  system("clear");
  int select;
  render_pvp_result(ox,pl);
  scanf("%d",&select);
  if(select==1){
    menu_pvc();
  }
  else if(select==2){
    menu_main();
  }
}

//menu
void menu_main(){
  system("clear");
	int select;
	render_menu();
	scanf("%d",&select);
	if(select==1){
		menu_pvc();
	}
	else if(select==2){
		menu_pvp();
	}
	else if(select==3){
		menu_exit();
	}
}

void menu_pvc(){
	system("clear");
	char ox[6][7],select[100],sp,cp,plwin[1000];
	int round,bRound=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			ox[i][j] = ' ';
		}
	}
	render_board(ox);
	printf("Do you want to play first(Y/N)?\n");
	scanf("%s",select);
	if(select[0]=='Y'){
		round = 0;
		sp = 'X';
		cp = 'O';
	}
	else{
		round = 1;
		sp = 'O';
		cp = 'X';
	}
	while(1){
		bRound++;
		system("clear");
		char pick[1];
		int drop;
		render_board(ox);
		if(round==0){
			if(bRound==30 || bRound==32) printf("!!! BONUS TURN !!!\n");
			printf("Player, your turn!\n\n");
			printf("Where do you want to go(A-G)?\n");
			scanf("%s",pick);
			drop = pick[0]-'A';
			for(int i=5;i>=0;i--){
				if(ox[i][drop]==' '){
					ox[i][drop]=sp;
					break;
				}
			}
			if(is_bingo(ox)){
				strcpy(plwin,"Player");
				break;
			}
		}
		else if(round==1){
			drop = comp_select(ox);
			for(int i=5;i>=0;i--){
				if(ox[i][drop]==' '){
					ox[i][drop]=cp;
					break;
				}
			}
			if(is_bingo(ox)){
				strcpy(plwin,"Computer");
				break;
			}
		}
		round=!round;
    if(bRound==29 || bRound==31) round=!round;
		if(bRound==32) bRound=0;
	}
	menu_pvc_result(ox,plwin);
}

void menu_pvp(){
	system("clear");
	char ox[6][7];
	char p1[1000],p2[1000],plwin[1000];
	int round = 0,bRound = 0,rRound=0,rRow;
	int tempRow,tempCol;
	int reXo[11][2];
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			ox[i][j] = ' ';
		}
	}
	render_board(ox);
	printf("Player1: ");
	scanf("%s",p1);
	printf("Player2: ");
	scanf("%s",p2);
	while(1){
		bRound++;
		system("clear");
		char pick[1],oxb;
		int drop;
		render_board(ox);
		if(bRound==30 || bRound==32) printf("!!! BONUS TURN !!!\n");
		if(round==0) printf("%s, your turn!\n\n",p1);
		else printf("%s, your turn!\n\n",p2);
		printf("Where do you want to go(A-G)?\n");
		scanf("%s",pick);
		drop = pick[0]-'A';
		if(round==0) oxb='X';
		else oxb='O';
		for(int i=5;i>=0;i--){
			if(ox[i][drop]==' '){
				ox[i][drop]=oxb;
				rRow = i;
				break;
			}
		}
		if(rRound==10){
			// printf("<%d %d>",reXo[0][0],reXo[0][1]);
			ox[reXo[0][0]][reXo[0][1]] = ' ';
			for(int i=1;i<=11;i++){
				 tempRow=reXo[i][0];
				 tempCol=reXo[i][1];
				 reXo[i-1][0] = tempRow;
				 reXo[i-1][1] = tempCol;
			}
			rRound--;
		}
		else{
			reXo[rRound][0] = rRow;
			reXo[rRound][1] = drop;
		}
		for(int i=4;i>=0;i--){
			for(int j=0;j<7;j++){
				if(ox[i][j]!=' ' && ox[i+1][j]==' '){
					ox[i+1][j]=ox[i][j];
					ox[i][j]=' ';
				}
			}
		}
    if(is_bingo(ox)){
      if(round==0) strcpy(plwin,p1);
      else if(round==1) strcpy(plwin,p2);
      break;
    }
		round=!round;
		if(bRound==29 || bRound==31) round=!round;
		if(bRound==32) bRound=0;
		rRound++;
		if(rRound==11) rRound=0;
	}
  menu_pvp_result(ox,plwin);
}

void menu_exit(){
	system("clear");
	exit(0);
}

//core
void ox_game(){
	menu_main();
}

//main
int main(){
	srand(time(NULL));
	ox_game();
	return 0;
}
