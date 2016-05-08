#include "lib.h"

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
}

void slp(int ms){
	Sleep(ms);
}

void cls(){
	system("cls");	
}

void drawshape(int x,int y,int v, int h, int type){
	gotoxy(x,y);
	int garis[6];
	if(type==1){
		garis[0] = duasikukiriatas;
		garis[1] = duasikukananatas;
		garis[2] = duasikukananbawah;
		garis[3] = duasikukiribawah;
		garis[4] = duahor;
		garis[5] = duaver;
	}else{
		garis[0] = sikukiriatas;
		garis[1] = sikukananatas;
		garis[2] = sikukananbawah;
		garis[3] = sikukiribawah;
		garis[4] = hor;
		garis[5] = ver;
	}
	printf("%c",garis[0]);
	int i;
	for(i=0;i<v;i++){
		x++;
		gotoxy(x,y);
		printf("%c",garis[4]);
	} 
	x++;
	printf("%c",garis[1]);
	for(i=0;i<h;i++){
		y++;
		gotoxy(x,y);
		printf("%c",garis[5]);
	} 
	y++;
	gotoxy(x,y);
	printf("%c",garis[2]);
	for(i=0;i<v;i++){
		x--;
		gotoxy(x,y);
		printf("%c",garis[4]);
	} 
	x--;
	gotoxy(x,y);
	printf("%c",garis[3]);
	for(i=0;i<h;i++){
		y--;
		gotoxy(x,y);
		printf("%c",garis[5]);
	}
}

void blankspace(int x, int y, int v, int h){
	gotoxy(x,y);
	int i,j;
	for(i=0;i<h;i++){
		for(j=0;j<v;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
}

void menu_main(int x, int y){
	cls();
	drawshape(x,y,23,9,1);
	gotoxy(x+2,y+2);
	printf("MainCar v2");
	gotoxy(x+2,y+4);
	printf("Mulai bermain");
	gotoxy(x+2,y+5);
	printf("Cara bermain");
	gotoxy(x+2,y+6);
	printf("Peringkat tertinggi");
	gotoxy(x+2,y+7);
	printf("Tentang Maincar");
	gotoxy(x+2,y+8);
	printf("Keluar");
	int pilihan = cursor(y+22,x+4,0,1,key_down,key_up,leftcursor,5);
	switch(pilihan){
		case 1 :
			newsession();
			break;
	}
}

int cursor(int x, int y, int xp, int yp, int key1, int key2, int chcursor, int option){
	int select = 1;
	int input;
	gotoxy(x,y);
	printf("%c",chcursor);
	do
	{
		input=getch();
		gotoxy(x,y);printf(" ");
		if(input==key1)
		{

			x+=xp;y+=yp;select++;
			if(select>option)
			{
				x=x-(xp * option);
				y=y-(yp * option);
				select=1;
			}

		}
		if(input==key2)
		{
			x-=xp;y-=yp;select--;
			if(select<1)
			{
				x=x+(xp * option);
				y=y+(yp * option);
				select=option;
			}
		}
		if(input==key_esc){
			select = option;
		}
		gotoxy(x,y);printf("%c",chcursor);
	}
	while(input!=key_enter && input!=key_esc);
	return select;
}

void input_dataplayer(int x, int y){
	cls();
	gotoxy(x,y);
	printf("Nama Pemain");
	drawshape(x,y+2,30,1,2);
	string * nama = (string) malloc(sizeof(char) * 60);
	gotoxy(x+1,y+3);
	scanf("%s",nama);
	CreateListPlayer(&ListPlayers);
	PreparePlayer(nama,'T');
	cls();
	gotoxy(x,y);
	drawshape(x,y+1,9,5,1);
	int i;
	for(i=0;i<3;i++){
		gotoxy(x+2,y+(i+3));
		printf("%d Bot",(i+1));
		if(i>0){
			printf("s");
		}	
	}
	int jml = cursor(y+8,x+3,0,1,key_down,key_up,leftcursor,3);
	if(jml>0){
		PreparePlayer("Bot1",'Y');
	}
	if(jml>1){
		PreparePlayer("Bot2",'Y');
	}
	if(jml>2){
		PreparePlayer("Bot3",'Y');
	}
}

void input_datasession(int x, int y){
	cls();
	gotoxy(x,y);
	printf("Maks Ronde");
	drawshape(x,y+2,5,1,2);
	gotoxy(x+1,y+3);
	scanf("%d",&maxround);
	cls();
	gotoxy(x,y);
	printf("Maks Skor");
	drawshape(x,y+2,5,1,2);
	gotoxy(x+1,y+3);
	scanf("%d",&maxscore);
}

void menu_game(){
	
}

//void showmycard(infoCard card, int x, int y){
//	int tmpx = x;
//	int tmpy = y;
//	int i,j;
//	for(i = 0; i < structcardrow; i++){
//		tmpy = y;
//		for( j = 0; j < structcardcol; j++){
//			gotoxy(tmpx,tmpy);
//			if(structmycard[i][j]=='X'){
//				if(i==structcardrow-2 && card.number!=10){
//					printf(" ");
//				}
//				switch(card.number){
//					case 1 :
//						printf("A");
//						break;
//					case 11 :
//						printf("J");
//						break;
//					case 12 :
//						printf("Q");
//						break;
//					case 13 :
//						printf("K");
//						break;
//					default :
//						printf("%d",card.number);	
//				}
//				if(i!=structcardrow-2){
//					printf(" ");
//				}
//				j++;
//				tmpy ++;
//			}else{
//				if(structmycard[i][j]=='C'){
//					printf("%c",deftypecard(card.type));
//				}
//				else
//				if(structmycard[i][j]!='/'){
//					printf("%c",structmycard[i][j]);
//				}
//				else{
//					printf(" ");
//				}
//			}
//			tmpy ++;
//		}
//		tmpx ++;
//	}
//}
