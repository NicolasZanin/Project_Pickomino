#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct{
   char Name[30];
   short indexplayer;
   short stack[16];
   short point;
   short laststackelement;
   short ia;
}Player;

/*Visuel*/
void menu(short ascii,short *pickomino);
void printName(Player *player, short i);
void printTab(short *t, short number);
void printStruct(Player *player, short indexplayer, short number);
void drawAscii(char a, char b, char c, char d, char e, char f, short *pickomino, short i);
void drawDomino(short *pickomino);
void drawAsciiUnix(short *pickomino, char *c, short i);
void drawDominoUnix(short *pickomino);

/*Initialisation*/
void buffer(FILE *c);
void initStruct(Player *player, short indexplayer);
short fillStruct(Player *player);
void initValue(short *t, short start, short number, short value);
void rollDice(short *t, short number);

/*Verif*/
short numberOccurence(short *t,short value, short end);
short checkValue(short *tab, short value, short end);
short checkPossibility(short *rolldice, short *dicekeep, short end, short numberdice);
short checkValueDice(short *dicekeep, short numberdice);
short checkStack(Player *player, short numberplayer, short indexplayer, short sumdice);
short checkPickominoAvailable(short *pickomino, short number);
short checkLastElPlayer(Player *player, short sumdice, short indcurrentplayer, short numberofplayer);
short checkSumDice(Player *player, short *pickomino, short numberplayer, short indcurrentplayer, short sumdice);

/*Prendre ou rendre pickomino*/
short getNewSum(Player *player, short *pickomino, short numberplayer, short indcurrentPlayer, short sumdice);
void replaceDomino(Player *player, short *pickomino, short indexPlayer);
void lostDomino(Player *player, short *pickomino, short *domino, short indexplayer);
short getDominos(Player *player, short *pickomino, short *domino, short sumdice, short numberplayer, short indexplayer);

/*Choix humain/Ordi */
void choice(short *rolldice, short *dicekeep, short *numberdice, short *sumdice);
void continuTower(Player *player, short *pickomino, short *domino,short *rolldice,short *dicekeep, short numberplayer, short indexplayer);
void choiceIA(short *rolldice,short *dicekeep,short *numberdice, short *sumdice,short *state);
void continuTowerIA(Player *player, short *pickomino, short *domino, short *rolldice, short *dicekeep, short numberplayer, short indexplayer);

/*Departager Joueur*/
void score(Player *player, short numberplayer);
short egality(Player *player, short numerowinner, short numplayeregality);
void classement(Player *player, short numberplayer);

/*Sauvegarde*/
void saveTowerBin(Player *player, char *namefile, short *pickomino, short domino, short numberplayer);
void savePartybin(char *namefile);
void readSaveBinary(Player *player, char *namefile, short *save, short *pickomino, short *domino, short *numberplayer);

/*Fin Partie*/
void continuParty(Player *player,char *namefile,short numberplayer,short *pickomino,short *domino,short *rolldice, short *dicekeep,short ascii);
