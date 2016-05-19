#include "lib.h"

void botmove(){
	addressCard C = whichcardtake();
	if(C != NULL){
		doTake(Card(C));		
		doMeld(Card(C));
	}else{
		doDraw();
	}
	botmeld();
	infoCard off = whichcardoff();
	doOff(off);
}


addressCard whichcardtake(){
	int i = 1;
	int biggest = 0;
	addressCard T = First(card_on_off);
	addressCard B = NULL;
	while(T != NULL && i<=7){
		ClearListCard(&temp_card);
		addressCard C = First(Hand(player_who_play));
		while(C != NULL){
			AddCard(&temp_card,Card(C));
			C = Next(C);
		}
		if(trees(temp_card,Card(T))>2){
			addressCard O = First(card_on_off);
			while(O != NULL){
				AddCard(&temp_card,Card(O));
				if((SameCard(Card(O),Card(T))==1)){
					break;
				}
				O = Next(O);
			}	
		}
		if(B == NULL){
			B = T;
			biggest = trees(temp_card,Card(T));
		}else{
			if(biggest<trees(temp_card,Card(T))){
				B = T;
				biggest = trees(temp_card,Card(T));
			}
		}
		T = Next(T);
		i++;
	}
	if(biggest<3){
		B = NULL;
	}
	return B;
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
	addressCard O = First(Hand(player_who_play));
	addressCard R = O;
	int tree = trees(Hand(player_who_play),Card(O));
	int poin = point(Card(O));
	while(O != NULL){
		int t = trees(Hand(player_who_play),Card(O));
		int p = point(Card(O));
		if(t<tree){
			R = O;
			tree = t;
			poin = p;
		}else
		if(t==tree && p>poin){
			R = O;
			poin = p;	
		}
		O = Next(O);
	}
	return Card(R);
}
