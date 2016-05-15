#include "lib.h"

addressCard AllocCard (infoCard X){
	addressCard P = (addressCard) malloc (sizeof (ElmtListCard));
 	if (P != NULL) {
	 	Card(P) = X;
 		Next(P) = NULL;
 	}
	return (P);
}
addressCard SearchCard (ListCard L, infoCard X){
	addressCard P = First(L);
 	int found = 0;
 	while ((P != NULL) && (found == 0)){
 		if(SameCard(Card(P),X)==1){
 			found = 1;
		}else{
			P = Next(P);
		}
 	}
 	return (P);
}
int AddCard (ListCard * L, infoCard X){
	addressCard P = AllocCard (X);
 	if (P != NULL){
		addressCard Last;
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
int SizeListCard(ListCard L){
	int Jml = 0;
 	addressCard P = First(L);
	while(P != NULL){
	 		Jml++;
	 		P = Next(P);
	}
 	return (Jml);
}
int SameCard(infoCard X, infoCard Y){
	int result = 0;
	if (Y.number == X.number && Y.type == X.type){
		result = 1;
	}
	return result;
}
void ClearListCard (ListCard * L){
	addressCard PDel = First(*L);
 	while (PDel != NULL){
 		First(*L) = Next(First(*L));
 		DeAllocCard (PDel);
 		PDel = First(*L);
 	}
}
void CreateListCard (ListCard * L){
	First(*L) = NULL;
}
void DeAllocCard (addressCard P){
	if (P != NULL){
		free (P);
	}
}
void DeleteCard(ListCard * L, infoCard X){
	addressCard PDel = First(*L);
	addressCard Prec = NULL;
	int found = 0;
	while(PDel != NULL && found == 0){
		if(SameCard(Card(PDel),X) == 1){
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
		printf("3");
			Next(Prec) = Next(PDel); 
		}
 		Next(PDel) = NULL;
 		DeAllocCard(PDel);
	}
}
void MoveCard(ListCard * L1, ListCard * L2, infoCard X){
	addressCard P = First((*L1));
	addressCard Prec = NULL;
 	int found = 0;
 	while ((P != NULL) && (found == 0)){
 		if(SameCard(Card(P),X)==1){
 			found = 1;
		}else{
			Prec = P;
			P = Next(P);
		}
 	}
 	if(found == 1){
		if (Prec == NULL && Next(P) == NULL){ 
			First((*L1)) = NULL; 
		}else 
		if (Prec == NULL){ 
			First((*L1)) = Next(P); 
		}else{ 
			Next(Prec) = Next(P); 
		}
	}
	Next(P) = First((*L2));
	First((*L2)) = P;
}
void ListCardInfo(ListCard L){
	addressCard P = First(L);
	while(P != NULL){
	 		printf("%d,%d\n",Number(P),Type(P));
	 		P = Next(P);
	}
 	printf("size card %d",SizeListCard(L));
}

void SwapCard(infoCard * X, infoCard * Y){
	infoCard temp;
	temp.number = X->number;
	temp.type = X->type;
	X->number = Y->number;
	X->type = Y->type;
	Y->number = temp.number;
	Y->type = temp.type;
}

addressCard TraceListCard(ListCard L, int index){
	addressCard P = First(L);
 	int i = 1;
 	while ((P != NULL) && i < index){
	 	P = Next(P);
		i++;	
 	}
 	return (P);
}

void sortcard(ListCard * L, int opt){
	addressCard C1,C2;
	C1 = First((*L));
	if(opt==1){
		while(C1 != NULL){
			C2 = First((*L));
			while(C2 != NULL){
				if(Number(C1)<Number(C2)){
					SwapCard(&Card(C1),&Card(C2));
				}
				C2 = Next(C2);
			}
			C1 = Next(C1);
		}
	}else{
		while(C1 != NULL){
			C2 = First((*L));
			while(C2 != NULL){
				if(Type(C1)<Type(C2)){
					SwapCard(&Card(C1),&Card(C2));
				}
				C2 = Next(C2);
			}
			C1 = Next(C1);
		}
		C1 = First((*L));
		while(C1 != NULL){
			C2 = First((*L));
			while(C2 != NULL){
				if(Type(C1)==Type(C2) && Number(C1)<Number(C2)){
					SwapCard(&Card(C1),&Card(C2));
				}
				C2 = Next(C2);
			}
			C1 = Next(C1);
		}
	}
}

int trees(ListCard L, infoCard C){
	sortcard(&L,1);
	int n = 0;
	addressCard P = SearchCard(L,C);
	while(P != NULL){
		if(Number(P)==C.number){
			n++;
			P = Next(P);
		}else{
			break;
		}
	}
	return n;
}
