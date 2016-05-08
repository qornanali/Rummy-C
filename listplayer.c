#include "lib.h"

addressPlayer AllocPlayer (infoPlayer X){
	addressPlayer P = (addressPlayer) malloc (sizeof (ElmtListPlayer));
 	if (P != NULL) {
	 	Player(P) = X;
 		Next(P) = NULL;
 	}
	return (P);
}
addressPlayer SearchPlayer (ListPlayer L, infoPlayer X){
	addressPlayer P = First(L);
 	int found = 0;
 	while ((P != NULL) && (found == 0)){
 		if(strcmp(Name(P),X.name) == 0){
 			found = 1;
		}else{
			P = Next(P);
		}
 	}
 	return (P);
}
int AddPlayer (ListPlayer * L, infoPlayer X){
	addressPlayer P = AllocPlayer (X);
 	if (P != NULL){
		addressPlayer Last;
		if (First(*L) != NULL){
	 		Last = First(*L);
	 		while (Last->next != NULL){
			 	Last = Next(Last);
			}
	 		 Next(Last) = P;
	 	}else{
			First(*L) = P;
		}
	}
}
int SizeListPlayer(ListPlayer L){
	int Jml = 0;
 	addressPlayer P = First(L);
	while(P != NULL){
	 		Jml++;
	 		P = Next(P);
	}
 	return (Jml);
}
void ClearListPlayer (ListPlayer * L){
	addressPlayer PDel = First(*L);
 	while (PDel != NULL){
 		First(*L) = Next(First(*L));
 		DeAllocPlayer (PDel);
 		PDel = First(*L);
 	}
}
void CreateListPlayer (ListPlayer * L){
	First(*L) = NULL;
}
void DeAllocPlayer (addressPlayer P){
	if (P != NULL){
		free (P);
	}
}
void DeletePlayer(ListPlayer * L, infoPlayer X){
	addressPlayer PDel = First(*L);
	addressPlayer Prec;
	int found = 0;
	while(PDel != NULL && found == 0){
		if(strcmp(Name(PDel),X.name) == 0){
			found = 1;
		}else{
			Prec = PDel;
			PDel = Next(PDel);	
		}
	}
	if(found == 1){
		if (Prec == NULL && Next(PDel) == NULL){ 
			First(*L) = NULL; 
		}else 
		if (Prec == NULL){ 
			First(*L) = Next(PDel); 
		}else{ 
			Next(Prec) = Next(PDel); 
		}
 		Next(PDel) = NULL;
 		DeAllocPlayer(PDel);
	}
}
void ListPlayerInfo(ListPlayer L){
	addressPlayer P = First(L);
	while(P != NULL){
	 		printf("Player %s\nScore %d\n",Name(P),Score(P));
			if(isbot(Bot(P))==1){
				puts("is Bot");
			}
			if(SizeListCard(Hand(P))>0){
				puts("hand : ");
				ListCardInfo(Hand(P));	
			}
			if(SizeListCard(Meld(P))>0){
				puts("meld : ");
				ListCardInfo(Meld(P));	
			}
			printf("\n.\n");
	 		P = Next(P);
	}
 	printf("size player %d",SizeListPlayer(L));
}

