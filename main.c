#include "jeu.h"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #define ascii 0

#elif __APPLE__
    #define ascii 1

#elif __linux
    #define ascii 1

#elif __unix
    #define ascii 1

#else
    #define ascii 1
#endif
int main(void){
    short rolldice[8];
    short dicekeep[8];
    short pickomino[16];
    short domino=16;
    short numberplayer=0;
    short save=0;
    char namefile[15];
    Player player[8];
    initValue(pickomino,0,16,1);
    menu(ascii,pickomino);
    readSaveBinary(player,namefile,&save,pickomino,&domino,&numberplayer);
    if(save == 0){
        savePartybin(namefile);
        initValue(pickomino,0,16,1);
        numberplayer = fillStruct(player);
        saveTowerBin(player,namefile,pickomino,domino,numberplayer);
    }
    srand(time(NULL));
    initValue(rolldice,0,8,0);
    initValue(dicekeep,0,8,0);
    continuParty(player,namefile,numberplayer,pickomino,&domino,rolldice,dicekeep,ascii);
    remove(namefile);
    return 0;
}
