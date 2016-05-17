#include "lib.h"

void PrepareCard(){
	CreateListCard(&card_on_deck);
	CreateListCard(&card_on_off);
	CreateListCard(&temp_card);
	int i,j;
	for(i = 1; i <= 4; i++){
		for(j = 1; j <= 13; j++){
			infoCard newCard;
			newCard.number = j;
			newCard.type = i;
			AddCard(&card_on_deck,newCard);
		}
	}
	shuffledeck();
	givecardtoplayers();
}

void PrepareInfoPlayer(infoPlayer * X){
	CreateListCard(&(X->card_on_hand));
	CreateListCard(&(X->card_on_meld));
	X->score = 0;
}

void PreparePlayer(string * name, char bot){
	infoPlayer info;
	info.name = name;
	info.bot = bot;
	printf("%s",info.name);
	PrepareInfoPlayer(&info);
	printf("%d ",info.score);
	printf("%d",SizeListCard(info.card_on_hand));
	AddPlayer(&ListPlayers,info);
}

void newsession(){
	endsession = 0;
	roundcount = 0;
	cheaton = 1;
	input_dataplayer(3,3);
	input_datasession(3,3);
	newround(First(ListPlayers));
	console();
}

void newround(addressPlayer firstplayer){
	player_who_play = firstplayer;
	if(roundcount!=0){
		addressPlayer P = First(ListPlayers);
		while(P != NULL){
			PrepareInfoPlayer(&Player(P));
			P = Next(P);
		}
	}
	PrepareCard();
	endround = 0;
	roundcount++;
}

void shuffledeck(){
	int a,b,c;
	addressCard card1,card2;
	c = random(1,100);
	while(c--){
		a = random(1,52);
		b = random(1,52);
		card1 = TraceListCard(card_on_deck,a);
		card2 = TraceListCard(card_on_deck,b);		
		SwapCard(&Card(card1),&Card(card2));
	}
}

void givecardtoplayers(){
	int n;
	if(SizeListPlayer(ListPlayers)==2){
		n = 10;
	}else{
		n = 6;
	}
	while(n--){
		addressPlayer P = First(ListPlayers);
		while(P != NULL){
			MoveCard(&card_on_deck,&Hand(P),Card(First(card_on_deck)));
			P = Next(P);
		}
	}
}

void console(){
	cls();
	printf("Max Round %d\nMax Score %d\n.\nCheat %d\n.\nRound #%d\n%s turn\n.\n"
	,maxround,maxscore,cheaton,roundcount,Name(player_who_play));
	ListPlayerInfo(ListPlayers);
	printf("\n.\n");
	if(SizeListCard(card_on_deck)>0){
		puts("deck : ");
		ListCardInfo(card_on_deck);	
	}
	puts(".");
	if(SizeListCard(card_on_off)>0){
		puts("off : ");
		ListCardInfo(card_on_off);	
	}
	puts(".");
	if(SizeListCard(temp_card)>0){
		puts("temp : ");
		ListCardInfo(temp_card);	
	}
}

void play(){
	while(endsession==0){
		int i = 1;	
		while(endround==0){
			if(Bot(player_who_play) == 'Y'){
				botmove();
			}else{
				playermenu(50,10);
				//sortcard(&Hand(player_who_play),1);
			}
		
			getch();
			menu_game(0,0);
			if(SizeListCard(card_on_deck)==0 || SizeListCard(Hand(player_who_play))==0){
				endround = 1;
			}else{
				player_who_play = Next(player_who_play);
				i++;
				if(player_who_play == NULL){
					player_who_play = First(ListPlayers);
					i = 1;
				}
			}
		}
		addressPlayer P = First(ListPlayers);
		addressPlayer biggerscore = P;
		while(P != NULL){
			if(calcscore(Player(biggerscore))<calcscore(Player(P))){
				biggerscore = P;
			}
			Score(P) += calcscore(Player(P));
			P = Next(P);
		}
		if(roundcount>maxround ||  Score(player_who_play)>=maxscore){
			endsession = 1;
		}else{
			newround(biggerscore);	
		}
	}
	
}


void doMeld(infoCard C){
	sortcard(&Hand(player_who_play),1);
	addressCard P = First(Hand(player_who_play));
	while(P != NULL){
		addressCard Px = P;
		P = Next(P);
		if((Number(Px)==C.number)){
			MoveCard(&Hand(player_who_play),&Meld(player_who_play),Card(Px));
		}
	}
}

void doDraw(){
	MoveCard(&card_on_deck,&Hand(player_who_play),Card(First(card_on_deck)));
}

void doOff(infoCard C1){
	MoveCard(&Hand(player_who_play),&card_on_off,C1);
}

void doTake(infoCard C){
	addressCard CO = First(card_on_off);
	while(CO != NULL){
		MoveCard(&card_on_off,&Hand(player_who_play),Card(CO));
		if((SameCard(Card(CO),C)==1)){
			break;
		}
		CO = First(card_on_off);
	}
}

