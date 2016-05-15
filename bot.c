#include "lib.h"

void botmove(){
	int sudahbuang = 0,sudahambil = 0;
	doDraw();
	doOff(Card(First(Hand(player_who_play))));
}
