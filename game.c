#include "lib.h"

void PrepareDeck(){
	ClearListCard(&card_on_deck);
	CreateListCard(&card_on_deck);
	int i,j;
	for(i = 1; i <= 4; i++){
		for(j = 1; j <= 13; j++){
			infoCard newCard;
			newCard.number = j;
			newCard.type = i;
			AddCard(&card_on_deck,newCard);
		}
	}
}
