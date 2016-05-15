#include "lib.h"

int random(int a, int b){
	int c = ((rand() % b) + a);
	return c;
}

int isbot(char a){
	int result = 0;
	if(a == 'Y'){
		result = 1;
	}
	return result;
}

char deftypecard(int type){
	return type+2;
}

int calcscore(infoPlayer P){
	int poin = 0;
	addressCard C = First((P.card_on_meld));
	while(C != NULL){
		poin += point(Card(C));
		C = Next(C);
	}
	C = First((P.card_on_hand));
	while(C != NULL){
		poin -= point(Card(C));
		C = Next(C);
	}
	return poin;
}

int point(infoCard C){
	int poin = 0;
	switch(C.number){
		case 1 : 
			poin = 15;
			break;
		case 11 :
			poin = 10;
			break;
		case 12 :
			poin = 10;
			break;
		case 13 :
			poin = 10;
			break;
		default :
			poin = 5;
			break;
	}
	return poin;
}
