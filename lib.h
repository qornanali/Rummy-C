/*
----------------------------------------------------------------------
File           : lib.h
Deskripsi      : Header file project maincar
Dibuat oleh    : 	-Ali Qornan Jaisyurrahman		151511007
			-Muhammad Hamzhya Salsatinnov Hairy	151511017
			-Riyan Gandarma  			151511028
Tanggal dibuat : 09 Mei 2016
----------------------------------------------------------------------
*/

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
#define Bot(P) (P)->info.bot
#define NextPlayer(P) (P)->next

/*ADT*/
typedef char * string;

/*listcard.c*/
typedef struct{
	int type; //jenis kartu
	int number; //nomor kartu
} infoCard; //komposit info kartu
typedef struct tElmtListCard *addressCard;
typedef struct tElmtListCard {
    infoCard info; 
    addressCard  next; //alamat elmt selanjutnya
    } ElmtListCard; //komposit kartu
typedef struct {
     addressCard First;
} ListCard; //komposit list kartu


/*created : Ali*/
addressCard AllocCard (infoCard X); //mengalokasikan memori utk elmt baru
addressCard SearchCard (ListCard L, infoCard X); //mencari kartu 
addressCard TraceListCard(ListCard L, int index); //mendapatkand data kartu di index ke berapa
int AddCard (ListCard * L, infoCard X); //menambah elmt kartu baru
int SizeListCard(ListCard L); //menghitung jml elmn di list kartu
int SameCard(infoCard X, infoCard Y); //mengecek apakah 2 kartu itu sama atau tidak
void ClearListCard (ListCard * L); //menghapus seluruh isi kartu
void CreateListCard (ListCard * L); //membuat list kartu
void DeAllocCard (addressCard P); //mengdealokasikan memori
void DeleteCard(ListCard * L, infoCard X); //menghapus kartu
void MoveCard(ListCard * L1, ListCard * L2, infoCard X); //memindahkan kartu dari ke list yang lain
void ListCardInfo(ListCard L); //menampilkan info list kartu
void SwapCard(infoCard * X, infoCard * Y); //menukar isi kartu
void sortcard(ListCard * L, int opt); //mengurutkan kartu
int trees(ListCard L, infoCard C); //mengecek jumlah trees dalam list

/*listplayer.c*/
typedef struct{
	string * name; //nama pemain
	int score; //jumlah skor
	char bot; //apakah bot atau bukan
	ListCard card_on_hand; //list kartu di tangan
	ListCard card_on_meld; //list kartu yang sudah jadi
} infoPlayer; //komposit info pemain
typedef struct tElmtListPlayer *addressPlayer;
typedef struct tElmtListPlayer {
    infoPlayer info;
    addressPlayer  next; //alamat elmt selanjutnya
    } ElmtListPlayer; //komposit pemain
typedef struct {
     addressPlayer First;
} ListPlayer; //komposit list pemain

/*created : Ali*/
addressPlayer AllocPlayer (infoPlayer X); //mengalokasikan memori untuk elmt baru pemain
addressPlayer SearchPlayer (ListPlayer L, infoPlayer X); //mencari data pemain di suatu list
int AddPlayer (ListPlayer * L, infoPlayer X); //menambah elmt baru pemain 
int SizeListPlayer(ListPlayer L); //menghitung jumlah pemain dalam list
void ClearListPlayer (ListPlayer * L); //menghapus semua data pemain
void CreateListPlayer (ListPlayer * L); //membuat list pemain
void DeAllocPlayer (addressPlayer P); //mengdealokasikan memori
void DeletePlayer(ListPlayer * L, infoPlayer X); //menghapus elmt pemain
void ListPlayerInfo(ListPlayer L); //menampilkan info list pemain

/*lib.c*/
/*created : Ali*/
int random(int a, int b); //mendapat acakan nilai
char deftypecard(int type); //menampilkan karakter kartu
int calcscore(infoPlayer P); //mengkalkulasikan skor
int point(infoCard C); //mendapatkan data poin dari kartu

/*game.c*/
/*created : Ali*/
void PrepareCard(); //mempersiapkan kartu untuk game
void PreparePlayer(string * name, char bot); //mempersiapkan pemain untuk game
void PrepareInfoPlayer(infoPlayer * X); //mempersiapkan data pemain untuk game
void newround(addressPlayer firstplayer); //membuat ronde baru
void doMeld(infoCard C); //melakukan proses menyimpan kartu
void doDraw(); //mencangkul kartu
void doTake(infoCard C); //mengambil kartu dari buangan
void doOff(infoCard C1); //membuang kartu
void newsession(); //membuat sesi baru
void console(); //menampilkan seluruh data permainan
void shuffledeck(); //mengocok deck
void givecardtoplayers(); //membagi2 kartu dari deck ke pemain
void play(); //memulai permainan
int checkmeld(ListCard L); //mengecek apakah kartu bisa disimpan atau tidak


/*ui.c*/
/*created : Hamzah*/
void setcolor(unsigned color); 
void everyone();
void present();
void tunggu();
void maincar();
/*created : Ali*/
void slp(int ms); //membuat jeda pada console
void gotoxy(int x, int y); //memindahkan kursor
void cls(); //clearscreen
void drawshape(int x, int y, int v, int h, int type); //menampilkan kotak
void drawsomechar(int x, int y, int v, int h, char c); //menampilkan suatu karakter
void menu_main(int x, int y); //menampilkan menu utama
int cursor(int x, int y, int xp, int yp, int key1, int key2, int chcursor, int option); //menampilan kursor
void input_dataplayer(int x, int y); //menampilkan menu untuk memasukkan data pemain
void input_datasession(int x, int y); //menampikan menu untuk membuat sesi baru
void menu_game(int x, int y); //menampilkan menu permainan
void showhand(int show, addressCard first, int x, int y, int xp, int yp); //menampilkan visualisasi kartu di tangan
void showcard(infoCard card, int x, int y); //menampilkan visualisasi kartu
void showblankcard(int x, int y); //menampilkan visualisasi kartu terbalik
void showdeck(int x, int y); //menampilkan visualisasi deck
void showoff(int x, int y); //menampilkan visualisasi buangan
void showmeld(int x, int y); //menampilkan visualisasi simpanan
void playermenu(int x, int y); //menampilkan menu pemain
void loadgame(); //memuat ui permainan

/*bot.c*/
/*created : Ali*/
void botmove(); //algoritma pergerakan bot
infoCard whichcardoff(); //memilih kartu mana yang dibuang
addressCard whichcardtake(); //memilih kartu mana yang diambil

/*Global Variable*/
ListCard card_on_deck,card_on_off,temp_card; 
ListPlayer ListPlayers;
addressPlayer player_who_play,winner;
int roundcount,maxround,maxscore,cheaton,endround,endsession;


#endif
