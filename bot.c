#include "lib.h"

void botmove(){
	addressCard C = whichcardtake();
	if(C != NULL){
		addressCard CO = First(card_on_off);
		while(CO != NULL){
			if((SameCard(Card(CO),Card(C))==1)){
				MoveCard(&card_on_off,&Hand(player_who_play),Card(CO));
				break;
			}else{
				MoveCard(&card_on_off,&Hand(player_who_play),Card(CO));
			}
			CO = First(card_on_off);
		}		
		doMeld(Card(C));
		}else{
			doDraw();
		}
	botmeld();
	doOff(whichcardoff());
}

addressCard whichcardtake(){
	CreateListCard(&temp_card);
	addressCard R = NULL;
	return R;
}

void botmeld(){
	sortcard(&Hand(player_who_play),1);
	addressCard T = First(Hand(player_who_play));
	addressCard X = NULL;
	while(T != NULL){
		int t = trees(Hand(player_who_play),Card(T));
		int i = 1;
		if(t>2){
			while(i <= t){
				X = T;
				T = Next(T);
				doMeld(Card(X));
				i++;
			}
		}else{
			T = Next(T);
		}
	}
}

infoCard whichcardoff(){
	infoCard C = Card(First(Hand(player_who_play)));
	return C;
}
