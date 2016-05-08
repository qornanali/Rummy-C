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

void drawsomechar(int x, int y, int v, int h, char c){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<h;j++){
			gotoxy(x+j,y+i);
			printf("%c",c);
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
			menu_game(0,0);
			play();
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

void menu_game(int x, int y){
	cls();
	drawshape(x+3,y+4,100,35,1);
	addressPlayer P = First(ListPlayers);
	int n = SizeListPlayer(ListPlayers);
	showhand(1,First(Hand(P)),x+32,y+36,5,0);
	if(n > 1){
		P = Next(P);
		showhand(cheaton,First(Hand(P)),x,y+9,0,3);
	}
	if(n > 2){
		P = Next(P);
		showhand(cheaton,First(Hand(P)),x+32,y,5,0);
	}
	if(n > 3){
		P = Next(P);
		showhand(cheaton,First(Hand(P)),x+100,y+9,0,3);
	}
	showdeck(x+20,y+10);
	showoff(x+20,y+22);
}


void showhand(int show, addressCard first, int x, int y, int xp, int yp){
	int x1,y1;
	x1 = x;
	y1 = y;
	addressCard card = first;
	while(card != NULL){
		gotoxy(x1,y1);
		if(show==1){
			showcard(Card(card),x1,y1);
		}else{
			showblankcard(x1,y1);
		}
		x1 += xp;
		y1 += yp;
		card = Next(card);
	}
}

void showblankcard(int x, int y){
	drawsomechar(x+1,y+1,7,7,'/');
	drawshape(x,y,7,7,2);
}

void showcard(infoCard card, int x, int y){
	drawsomechar(x+1,y+1,7,7,' ');
	drawshape(x,y,7,7,2);
	gotoxy(x+4,y+4);	
	printf("%c",deftypecard(card.type));
	gotoxy(x+1,y+1);
	switch(card.number){
		case 1 :
			printf("A");
			break;
		case 11 :
			printf("J");
			break;
		case 12 :
			printf("Q");
			break;
		case 13 :
			printf("K");
			break;
		default :
			printf("%d",card.number);
			break;	
	}
	if(card.number==10){
		gotoxy(x+6,y+7);
	}else{
		gotoxy(x+7,y+7);
	}
	switch(card.number){
		case 1 :
			printf("A");
			break;
		case 11 :
			printf("J");
			break;
		case 12 :
			printf("Q");
			break;
		case 13 :
			printf("K");
			break;
		default :
			printf("%d",card.number);
			break;	
	}
}

void showdeck(int x, int y){
	int n = SizeListCard(card_on_deck);
	if(n>0){
		gotoxy(x,y);
		printf("Cangkulan %d",n);
		showblankcard(x,y+1);
	}
}

void showoff(int x, int y){
	int n = SizeListCard(card_on_off);
	gotoxy(x,y);
	printf("Buangan %d",n);
	addressCard first = First(card_on_off);
	if(n>7){
		n -= 7;
		first = TraceListCard(card_on_off,n);
	}
	showhand(1,first,x,y+1,5,0);
}

