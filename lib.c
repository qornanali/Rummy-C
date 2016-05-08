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
