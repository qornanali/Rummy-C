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
	cheaton = 0;
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
		n = 7;
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


void doMeld(ListCard * L1, ListCard * L2, infoCard C, int n){
	addressCard card = SearchCard(*L1,C);
	while((n--) && (card != NULL)){
		MoveCard(L1,L2,Card(card));
		card = Next(card);
	}
}

void doDraw(ListCard * L){
	MoveCard(&card_on_deck,L,Card(First(card_on_deck)));
}

void doOff(ListCard * L, infoCard C1){
	MoveCard(L,&card_on_off,C1);
}



