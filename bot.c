#include "lib.h"

void botmove(){
	int sudahbuang = 0,sudahambil = 0;
	doDraw(&Hand(player_who_play));
	doOff(&Hand(player_who_play),Card(First(Hand(player_who_play))));
}
