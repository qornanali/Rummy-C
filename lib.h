#ifndef lib_H
#define lib_H

/*Library*/
#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

/*Konstanta*/
#define key_up 72
#define key_down 80
#define key_left 75
#define key_right 77
#define key_enter 13
#define key_esc 27
#define structcardcol 9
#define structcardrow 7
#define sikukananbawah 217
#define sikukiriatas 218
#define sikukananatas 191
#define sikukiribawah 192
#define duasikukananatas 187
#define duasikukananbawah 188
#define duasikukiriatas 201
#define duasikukiribawah 200
#define duahor 205
#define duaver 186
#define ver 179
#define hor 196
#define playery 34
#define playerx 35
#define bot1y 12
#define bot1x 3
#define bot2y 1
#define bot2x 35
#define bot3y 12
#define bot3x 100
#define leftcursor 17
#define upcursor 30
#define delay_fast 500
#define delay_slow 1000

/*Processor*/
#define First(L) (L).First
#define Next(P) (P)->next
#define NextCard(P) (P)->next
#define Number(P) (P)->info.number
#define Type(P) (P)->info.type
#define Card(P) (P)->info
#define Player(P) (P)->info
#define Name(P) (P)->info.name
#define Score(P) (P)->info.score
#define Hand(P) (P)->info.card_on_hand
#define Meld(P) (P)->info.card_on_meld
#define NextPlayer(P) (P)->next

/*ADT*/
typedef char * string;

/*listcard.c*/
typedef struct{
	int type;
	int number;
} infoCard;
typedef struct tElmtListCard *addressCard;
typedef struct tElmtListCard {
    infoCard info;
    addressCard  next;
    } ElmtListCard;
typedef struct {
     addressCard First;
} ListCard;

addressCard AllocCard (infoCard X);
addressCard SearchCard (ListCard L, infoCard X);
int AddCard (ListCard * L, infoCard X);
int SizeListCard(ListCard L);
int SameCard(infoCard X, infoCard Y);
void ClearListCard (ListCard * L);
void CreateListCard (ListCard * L);
void DeAllocCard (addressCard P);
void DeleteCard(ListCard * L, infoCard X);
void MoveCard(ListCard * L1, ListCard * L2, infoCard X);
void ListCardInfo(ListCard L);
void SwapCard(infoCard * X, infoCard * Y);

/*listplayer.c*/
typedef struct{
	string * name;
	int score;
	ListCard card_on_hand;
	ListCard card_on_meld;
} infoPlayer;
typedef struct tElmtListPlayer *addressPlayer;
typedef struct tElmtListPlayer {
    infoPlayer info;
    addressPlayer  next;
    } ElmtListPlayer;
typedef struct {
     addressPlayer First;
} ListPlayer;
addressPlayer AllocPlayer (infoPlayer X);
addressPlayer SearchPlayer (ListPlayer L, infoPlayer X);
int AddPlayer (ListPlayer * L, infoPlayer X);
int SizeListPlayer(ListPlayer L);
void ClearListPlayer (ListPlayer * L);
void CreateListPlayer (ListPlayer * L);
void DeAllocPlayer (addressPlayer P);
void DeletePlayer(ListPlayer * L, infoPlayer X);
void ListPlayerInfo(ListPlayer L);

/*lib.c*/
void slp(int ms);

/*game.c*/
void PrepareDeck();

/*ui.c*/
void gotoxy(int x, int y);
void cls();

/*bot.c*/


/*Global Variable*/
ListCard card_on_deck;
ListCard card_on_off;
addressPlayer player_who_play;
int session,round,maxsession,maxscore,cheaton,winnersession;

#endif
