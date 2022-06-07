#include "jeu.h"
void menu(short ascii,short *pickomino){
    char yesno[5];
    printf("Welcome to the pickomino game!!!\n");
    do {
    printf("Do you know the rules of this game (yes/no) ? ");
    scanf("%s",yesno);
    } while (strcmp(yesno,"yes") != 0 && strcmp(yesno,"no") != 0);
    if (strcmp(yesno,"no") == 0){
        printf("\nThe Pickominos have a value and a number of points. The Pickominos are as follows (the value of the Pickominos at the top and the number of points at the bottom) :\n");
        if(ascii == 0){
            drawDomino(pickomino);
        }
        else{
            drawDominoUnix(pickomino);
        }
        printf("The values are the total number of moves required to recover the Pickomino.\nEach player has a stack of Pickominoes in front of them.\nAt the beginning of the game, the players' stacks are empty and the Pickominoes are placed face up in the middle of the table.\nDuring the game, when a player picks up a Pickomino, they stack it on top of their stack of Pickominoes, so that only the last Pickomino picked up is visible.\n\n");
        printf("Dice : The dice are 6-sided dice, with sides from 1 to 5 and a special 'V' side (of value 5).\n\n");
        printf("For each turn, a player rolls as many times as he wishes and can set aside at least one of a different value than the ones already kept.\n\n");
        sleep(10);
        printf("First example:1st throw of the 8 dice:\n[1][5][V][1][4][2][V][V]\nThe player decides to keep the dice displaying the value V, so he puts these 3 dice aside and decides whether or not to re-roll the dice.\n2nd throw of the remaining 5 :\n[4] [5] [V] [4] [V]\nThe player cannot keep the dice displaying the value V because he already kept this value in the previous throw. He decides to keep the dice displaying the value 4, so he puts these 2 dice aside and decides whether or not he wishes to re-roll the dice.\n");
        printf("He chooses to re-roll the dice.\n3rd roll of the remaining 3 dice:\n [1] [5] [3]\nThe player decides to keep the dice showing the value 5, so he sets this one aside and decides whether or not to re-roll the dice. \nHe chooses to stop, so the player has kept 3 dice of value V (on the 1st roll), 2 dice of value 4 (on the 2nd roll) and one dice of value 5 (on the 3rd roll).\nHe therefore has a total value of 3*V+2*4+1*5=3*5+2*4+1*5=15+8+5=28\n\n");
        sleep(10);
        printf("2nd Example:\n1st roll of the 8 dice\n[2] [5] [V] [2] [4] [2] [5] [V]\nThe player decides to keep the dice with the V value, so he sets these 2 dice aside and decides whether or not to re-roll the dice.\nHe chooses to re-roll the dice.\n\n");
        printf("2nd throw of the remaining 6 dice:\n[3] [5] [V] [1] [V] [5]\nThe player cannot keep the dice with the value V because he already kept this value in the previous roll.\nHe decides to keep the dice with the value of 5, so he puts these 2 dice aside and decides whether or not he wants to re-roll the dice.\nHe chooses to re-roll the dice.\n\n3rd throw of the remaining 4 dice:\n[V] [5] [V] [V]\n");
        printf("The player may not keep the dice with the value V because he has already kept this value on the 1st throw. He cannot keep the dice with the value 5 either, because he has already kept this value in the 2nd throw.\nThis player's turn is therefore a failed turn.\n\n");
        sleep(10);
        printf("A trick is said to fail in the following 3 cases:\n1. the player cannot put in any odds (as in the 2nd example)\n2. the player has not placed any dice with the value V of the odds\nThe total value of the player's dice is less than the smallest value of the visible Pickominos.\n");
        printf("If the turn is missed, then the player must return a Pickomino. He returns the Pickomino at the top of his pile to the centre of the table.\nIn addition, he must return the highest value Pickomino from the centre of the table, unless it is the one he has just returned.\n\n");
        printf("In order to get a Pickomino back, there must be at least one with the value of V among the throws, as in Example 1:\nIf the Pickomino 28 is visible in the centre of the table, the player picks it up and places it on top of his pile\n2. if the Pickomino 28 is on top of another player's pile, the player picks it up and places it on top of his pile.\n");
        printf("Otherwise, if there is a Pickomino of lesser value than 28 in the centre of the table, the player picks up the Pickomino of greater value than 28 and places it on top of his pile.\nAlthough the player had a V among his cans, if he could not get any of the cans then his turn is over (so he must return a Pickomino and potentially turn over another one).\n\n");
        printf("When there are no more Pickominos face up in the centre of the table the game is over. The number of points of each player is counted as the sum of the points (bottom number) of the Pickominos in his pile. The winner is the player with the highest number of points.\n\n");
        do{
            sleep(15);
            printf("\nDid you finish reading (yes/no) ? ");
            scanf("%s",yesno);
        }while(strcmp(yesno,"yes")!=0);
    }
    printf("\n\n");
}


/* Affiche le numero et le nom du joueur associe a ce numero */
void printName(Player *player, short i){
    short j;
    for (j=0; j<i ; j++){
        printf("\nPlayer%d = %s",j+1,player[j].Name);
    }
}

/*Cette fonction affiche le tableau *t */
void printTab(short *t, short number){
    short i=0;
    for(i=0;i<number;i++){
        if (t[i] == 6){
            printf("V ");
        }
        else{
            printf("%d ",t[i]);
        }
    }
    printf("\n");
}

/* Fonction pour afficher une structure */
void printStruct(Player *player, short indexplayer, short number){
    short i;
    for(i=0;i<number;i++){
        printf("%d ",player[indexplayer].stack[i]);
    }
}


/* Dessine les caracteres ascii */
void drawAscii(char a, char b, char c, char d, char e, char f, short *pickomino, short i){
    short j;
    for(j=0;j<8;j++){
        if (pickomino[i*8+j]==0){
            printf("######\t");
        }
        else{
            printf("%c%c%c%c%c%c\t",a,b,c,d,e,f);
        }
    }
    printf("\n");
}


/* Fonction qui dessine les dominos en appelant la fonction DrawAscii() */
void drawDomino(short *pickomino){
    short i;
    short j;
    short values=21;
    short points=0;
    for (i=0;i<2;i++){
        drawAscii((char)218,(char)196,(char)196,(char)196,(char)196,(char)191,pickomino,i);
        for(j=0;j<8;j++){
            if (pickomino[i*8+j]==0){
                printf("######\t");
            }
            else{
                printf("%c %d %c\t",(char)179,values,(char)179);
            }
            values++;
        }
        printf("\n");
        drawAscii((char)195,(char)196,(char)196,(char)196,(char)196,(char)180,pickomino,i);
        for(j=0;j<8;j++){
            if (!(j%4)){
                points++;
            }
            if (pickomino[i*8+j]==0){
                printf("######\t");
            }
            else{
                printf("%c %d  %c\t",(char)179,points,(char)179);
            }
        }
        printf("\n");
        drawAscii((char)192,(char)196,(char)196,(char)196,(char)196,(char)217,pickomino,i);
        printf("\n");
    }
}

void drawAsciiUnix(short *pickomino, char *c, short i){
    short j;
    for(j=0;j<8;j++){
        if(pickomino[i*8+j]==0){
            printf("####\t");
        }
        else{
            printf("%s\t",c);
        }
    }
    printf("\n");
}


void drawDominoUnix(short *pickomino){
    short i;
    short j;
    short values=21;
    short points=0;
    for (i=0;i<2;i++){
        drawAsciiUnix(pickomino,"┌──┐",i);
        for(j=0;j<8;j++){
            if (pickomino[i*8+j]==0){
                printf("####\t");
            }
            else{
                printf("|%d|\t",values);
            }
            values++;
        }
        printf("\n");
        drawAsciiUnix(pickomino,"├──┤",i);
        for(j=0;j<8;j++){
            if (!(j%4)){
                points++;
            }
            if (pickomino[i*8+j]==0){
                printf("####\t");
            }
            else{
                printf("|%d |\t",points);
            }
        }
        printf("\n");
        drawAsciiUnix(pickomino,"└──┘",i);
    }
}


void buffer(FILE *c){
    char temp;
    while((temp=fgetc(c)) !='\n' && temp != EOF);
}


/* Fonction pour mettre des 0 dans toutes la structure */
void initStruct(Player *player, short indexplayer){
    short i;
    for(i=0;i<16;i++){
        player[indexplayer].stack[i] = 0;
    }
    player[indexplayer].point = 0;
}


/* Fonction demandant le nombre de joueur et leur nom */
short fillStruct(Player *player){
    short numberplayers=0;
    short numberhumans=0;
    short j;
    do{
        printf("How many players are you ? ");
        scanf("%hd",&numberplayers);
        buffer(stdin);
    }while(numberplayers < 2 || numberplayers > 7);
    do{
        printf("How many humans are you ? ");
        fscanf(stdin,"%hd",&numberhumans);
        buffer(stdin);
    }while(numberhumans>7 || numberhumans<0);
    if (numberhumans > numberplayers ) {
        while (numberhumans > numberplayers) {
                printf("Please select a number of possible humans : ");
                fscanf(stdin,"%hd",&numberhumans);
                buffer(stdin);
        }
    }
    for (j=0; j<numberhumans ; j++){
        printf("\nPlease enter your name Player%d ? ",j+1);
        fscanf(stdin,"%s",player[j].Name);
        buffer(stdin);
        initStruct(player,j);
        player[j].laststackelement = 0;
        player[j].ia=0;
    }
    for (j = numberhumans; j<numberplayers ; j++){
        printf("\nPlease enter the IA name : ");
        fscanf(stdin,"%s",player[j].Name);
        buffer(stdin);
        initStruct(player,j);
        player[j].laststackelement = 0;
        player[j].ia = 1;
    }
    printName(player,numberplayers);
    return numberplayers;
}


/* On met les valeurs dans le *t en commen�ant � la valeur commence*/
void initValue(short *t, short start, short number, short value){
    short i=0;
    for(i=start;i<start+number;i++){
        t[i] = value;
    }
}


/* Ici on lance les des et on met les valeurs correspondante dans le tableau *t */
void rollDice(short *t, short number){
    short j=0;
    short i=0;
    for(i=0;i<number;i++){
        j = (rand() % 6) + 1;
        t[i] = j;
    }
}


/* Compte nombre occurence de la valeur mise de cote */
short numberOccurence(short *t,short value, short end){
    short i;
    short number=0;
    for(i=0;i<end;i++){
        if(t[i] == value){
            number++;
        }
    }
    return number;
}

/*Verifie si la valeur 1 � 6 est inclue dans le tableau */
short checkValue(short *tab, short value, short end){
    short i;
    for(i=0;i<end;i++){
        if (value == tab[i]){
            return 0;
        }
    }
    return 1;
}

/* Verifie si il reste des possibilit�s de  valeur pour le joueur */
short checkPossibility(short *rolldice, short *dicekeep, short end, short numberdice){
    short i;
    short j;
    short state=0;
    short occurence=0;
    for(i=0;i<end;i++){
        for(j=0;j<numberdice;j++){
            if(rolldice[i]==dicekeep[j] && state==0){
                occurence++;
                state++;
            }
        }
        state = 0;
    }
    if (!(end == occurence)){
        return 0;
    }
    return 1;
}

short checkValueDice(short *dicekeep, short numberdice){
    short i;
    short j;
    short trouve=0;
    for(i=1;i<=6;i++){
        trouve=0;
        for(j=0;j<numberdice;j++){
            if(dicekeep[j]==i){
                trouve = 1;
            }
        }
        if(trouve == 0){
            return 1;
        }
    }
    return 0;
}


short checkStack(Player *player, short numberplayer, short indexplayer, short sumdice){
    short i;
    for (i=0;i<numberplayer;i++){
        if(player[i].stack[player[i].laststackelement-1] == sumdice && i != indexplayer){  /* Prend le dernier élément de la pile (et fait -1 car il affiche 0 sinon) et on compte pas le joueur en train de jouer */
            return i;
        }
    }
    return -1;
}

/* Verifie si il reste des pickominos disponibles */
short checkPickominoAvailable(short *pickomino, short number){
    short i;
    for(i = 0; i <= number - 21; i++){
        if (pickomino[i] == 1){
            return 1;
        }
    }
    return 0;
}


/* Regarde si le sommet de la pile d'un joueur est egal a la somme des des */
short checkLastElPlayer(Player *player, short sumdice, short indcurrentplayer, short numberofplayer){
    short i;
    for (i = 0; i < numberofplayer; i++){
        if (i != indcurrentplayer && player[i].stack[player[i].laststackelement - 1] == sumdice){
            return 1;
        }
    }
    return 0;
}

/* Verifie si la somme des d�s est bien entre 21 et 36 et par la suite il faudra qu'elle verifie si la valeur de la somme correspond � une valeur de pickomino dispo */
short checkSumDice(Player *player, short *pickomino, short numberplayer, short indcurrentplayer, short sumdice) {
    if (sumdice >=21 && sumdice <= 36 && (checkPickominoAvailable(pickomino, sumdice) || checkLastElPlayer(player, sumdice, indcurrentplayer, numberplayer))) {
        return 1;
    }
    else {
        return 0;
    }
}

short getNewSum(Player *player, short *pickomino, short numberplayer, short indcurrentPlayer, short sumdice){
    if (checkLastElPlayer(player, sumdice, indcurrentPlayer, numberplayer)){
        return sumdice;
    }
    else {
        short i;
        for (i = sumdice - 21; i >= 0 ; i--){
            if (pickomino[i] == 1){
                return i + 21;
            }
        }
    }
     return -1;
}


/* Replace un domino lors d'un tour perdu */
void replaceDomino(Player *player, short *pickomino, short indexPlayer){
    short valuetop;
    /* on change les proprietes du player */
    player[indexPlayer].laststackelement--;
    valuetop = player[indexPlayer].stack[player[indexPlayer].laststackelement];
    player[indexPlayer].stack[player[indexPlayer].laststackelement] = 0;

    /* on change le tableau pickomino */
    /* printf("1:%d",pickomino[valSommet - 21 - 1]); */
    pickomino[valuetop - 21] = 1;
    /* printf("2:%d",pickomino[valSommet - 21 - 1]); */

}


/* Lors d'un tour perdu cette fonction est appellee,
elle va appeller la fonctoin ReplaceDomino afin de mettre
le domino du sommet de la pile du joueur au centre de la table */
void lostDomino(Player *player, short *pickomino, short *domino, short indexplayer){
    short i=15;
    if (player[indexplayer].laststackelement > 0){
        replaceDomino(player,pickomino,indexplayer);
        *domino = *domino + 1;

    }
    while(pickomino[i]==0){
        i--;
    }
    pickomino[i]=0;
    *domino = *domino -1;
    printf("\nYour pile contains : ");
    printStruct(player,indexplayer,player[indexplayer].laststackelement);
    printf("\n\n%d Pickomino(s) remaining.\n",*domino);
    printf("\n");
}

/* Fonction pour prendre un pickominos */
short getDominos(Player *player, short *pickomino, short *domino, short sumdice, short numberplayer, short indexplayer){
    short i=sumdice;
    short j=0;
    if (pickomino[i-21] == 1){
        player[indexplayer].stack[player[indexplayer].laststackelement] = i;
        player[indexplayer].laststackelement ++;
    }
    else if((j = checkStack(player,numberplayer,indexplayer,sumdice)) >= 0){
        player[indexplayer].stack[player[indexplayer].laststackelement] = player[j].stack[player[j].laststackelement-1];
        player[j].stack[player[j].laststackelement-1] = 0;
        player[j].laststackelement--;
        player[indexplayer].laststackelement++;
        printf("\nYour pile contains : ");
        printStruct(player,indexplayer,player[indexplayer].laststackelement);
        printf("\n");
        return 0;
    }
    else{
        while(pickomino[i] == 0 && i>20){
            i--;
        }
        if (i==20){
            lostDomino(player,pickomino,domino,indexplayer);
            return 0;
        }
        player[indexplayer].stack[player[indexplayer].laststackelement] = i;
        player[indexplayer].laststackelement++;
    }
    *domino = *domino -1;
    pickomino[i-21] = 0;
    printf("\nYour pile contains : ");
    printStruct(player,indexplayer,player[indexplayer].laststackelement);
    printf("\n\n%d Pickomino(s) remaining.\n",*domino);
    return 0;
}

/* Laisse l'utilisateur choisir la valeur parmis tout les d�s propos�es (ne g�re pas les cas o� la valeur est d�j� dans le tableau tab (celui qui m�morise les lancers) et si la valeur n'est pas contenu dans le tableau ou les d�s ont �t� lanc�s (dans *t)*/
void choice(short *rolldice, short *dicekeep, short *numberdice, short *sumdice){
    char s[10];
    short count = 0; /* Compte le nombre d'apparition du caract�re*/
    short value=0; /* Permet de transformer le caract�re c en int */
    short i=0; /* Pour la boucle for */
    short keepvalue[1];
    etq : printf("Please, select a value : ");
    scanf("%s",s);
    value = (int)s[0];/* Ici c'est le nombre du caract�re ascii de c (exemple 1: c'est 49 dans la table ascii) */
    buffer(stdin);
    if (value == 86){
        value -=80; /* Convertit V � la valeur 6 */
    }
    else if(value>48 && value<54) {
        value -=48;
    }
    else{
        goto etq;
    }
    keepvalue[0] = value;
    if (checkPossibility(keepvalue,dicekeep,1,8) || checkValue(rolldice,value,*numberdice)){
        goto etq;
    }
    for(i=0;i<8;i++){
        if (rolldice[i] == value){
            count ++;
        }
    }
    if (value == 6){
        *sumdice = *sumdice + (count*value-count);
    }
    else {
        *sumdice = *sumdice + (count*value);
    }
    initValue(dicekeep,8-(*numberdice),count,value);
    *numberdice-=count;
}

/* Fonction permettant que le tour du joueur continu ou non */
void continuTower(Player *player, short *pickomino, short *domino,short *rolldice,short *dicekeep, short numberplayer, short indexplayer){
    char yesno[15];
    short numberdice=8;
    short sumdice = 0;
    short continu = 1;
    short flag=1;

    while(numberdice>=1 && continu && checkValueDice(dicekeep,8-numberdice)){
        rollDice(rolldice,numberdice);
        printf("Dice values : ");
        printTab(rolldice,numberdice);
        if (checkPossibility(rolldice,dicekeep,numberdice,8-numberdice)){
            printf("\nNo more possibilities");
            flag = 0;
            break;
        }

        choice(rolldice,dicekeep,&numberdice,&sumdice);
        if (sumdice >= 21) {
            do{
                printf("Do you want to continue (yes/no) ? ");
                fscanf(stdin,"%s", yesno);
                buffer(stdin);
            }while(strcmp(yesno,"yes")!=0 && strcmp(yesno,"no")!=0);
        }
        if (strcmp("no",yesno)==0){
            continu = 0;
        }

        if (!continu) {
            continue;
        }

        printf("Value of dice kept : ");
        printTab(dicekeep,8-numberdice);
        printf("\n");
        initValue(rolldice,0,8,0);
    }

    /* Faudrait mettre ce bloc dans une fonction � part pour cacher la complexit� */
    if (checkValue(dicekeep,6,8-numberdice)==0 && checkSumDice(player,pickomino,numberplayer,indexplayer,sumdice) && flag){
        printf("\nThe sum of your dice is %d\n",sumdice);
        printf("\nYou have successfully taken a pickomino");
        if (pickomino[sumdice-21] == 0){
            sumdice = getNewSum(player,pickomino,numberplayer,indexplayer,sumdice);
        }
        getDominos(player,pickomino,domino,sumdice,numberplayer,indexplayer); /* Pour prendre un pickomino */
    }
    else {
        printf("\nThe sum of your dice is %d\n",sumdice);
        printf("You didn't succeed in obtaining a pickomino...\n");
        lostDomino(player,pickomino,domino,indexplayer);
    }
    printf("\n");
}

/* Choix de l'ordi */
void choiceIA(short *rolldice,short *dicekeep,short *numberdice, short *sumdice,short *state){
    short i;
    short occurence = 0;
    short valuekeep = 0;
    short occurencekeep = 0;
    if ((*state) == 0){
        if(checkValue(rolldice,6,*numberdice) == 0){
            valuekeep = 6;
        }
    }
    if (valuekeep != 6){
        for(i=0;i<(*numberdice);i++){
            if(checkValue(dicekeep,rolldice[i],8-(*numberdice))== 1){
                occurence = numberOccurence(rolldice,rolldice[i],*numberdice);
            }
            if (valuekeep*occurencekeep < occurence*rolldice[i]){
                valuekeep = rolldice[i];
                occurencekeep = occurence;
            }
            occurence = 0;
        }
        printf("Please, select a value : %d\n",valuekeep);
        initValue(dicekeep,8-(*numberdice),occurencekeep,valuekeep);
        *sumdice += valuekeep*occurencekeep;
    }
    else{
        printf("Please, select a value : %c\n",'V');
        occurencekeep = numberOccurence(rolldice,6,*numberdice);
        initValue(dicekeep,8-(*numberdice),occurencekeep,valuekeep);
        *state=1;
        *sumdice += (valuekeep-1)*occurencekeep;
    }
    *numberdice -= occurencekeep;
}

/* Fonction permettant que le tour de l'IA continu ou non */
void continuTowerIA(Player *player, short *pickomino, short *domino, short *rolldice, short *dicekeep, short numberplayer, short indexplayer){
    short numberdice=8;
    short sumdice = 0;
    short continu = 1;
    short flag=1;
    short state=0;
    short i=0;

    while(numberdice>=1 && continu && checkValueDice(dicekeep,8-numberdice)){
        sleep(1);
        rollDice(rolldice,numberdice);
        printf("Dice value : ");
        printTab(rolldice,numberdice);
        if (checkPossibility(rolldice,dicekeep,numberdice,8-numberdice)){
            printf("\nNo more possibilities");
            flag = 0;
            break;
        }
        choiceIA(rolldice,dicekeep,&numberdice,&sumdice,&state);
        if (sumdice >= 21) {
            printf("Do you want to continue (yes/no) ? ");
            while(pickomino[i]==0){
                i++;
            }
            continu = ((i<sumdice) && (1<numberdice));
            if(continu == 1){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
            i = 0;
        }
        if (!(continu)) {
            continue;
        }

        printf("Value of dice kept : ");
        printTab(dicekeep,8-numberdice);
        printf("\n");
        initValue(rolldice,0,8,0);
    }

    /* Faudrait mettre ce bloc dans une fonction � part pour cacher la complexite */
    if (checkValue(dicekeep,6,8-numberdice)==0 && checkSumDice(player,pickomino,numberplayer,indexplayer,sumdice) && flag){
        printf("\nThe sum of your dice is %d\n",sumdice);
        printf("\nYou have successfully taken a pickomino");
        if (pickomino[sumdice-21] == 0){
            sumdice = getNewSum(player,pickomino,numberplayer,indexplayer,sumdice);
        }
        getDominos(player,pickomino,domino,sumdice,numberplayer,indexplayer);
    }
    else {
        printf("\nThe sum of your dice is %d\n",sumdice);
        printf("You didn't succeed in obtaining a pickomino...\n");
        lostDomino(player,pickomino,domino,indexplayer);
    }
    printf("\n");
}


/* Calcule le score de chaque joueur */
void score(Player *player, short numberplayer){
    short i;
    short j;
    /* ici i = 0 car la structure commence indice 0 */
    for(i = 0; i < numberplayer; i++){
        j = 0;
        while(j<player[i].laststackelement){
            if (player[i].stack[j] >= 21 && player[i].stack[j] <= 24) {
                player[i].point += 1;
            }
            else if (player[i].stack[j] >= 25 && player[i].stack[j] <= 28){
                player[i].point += 2;
            }
            else if (player[i].stack[j] >= 29 && player[i].stack[j] <= 32){
                player[i].point += 3;
            }
            else {
                player[i].point += 4;
            }
            j++;
        }
    }
}


/* Departage les joueurs en cas d'égalité en désignant gagnant le joueur possédant le domino de plus grande valeur */
short egality(Player *player, short numerowinner, short numplayeregality){
    short i;
    short j;
    short strongdomi;
    for (i = numerowinner ; i < numplayeregality ; i++) {
        if(player[i].point == player[numerowinner].point){
            j = 0;
            while(player[i].stack[j] != 0) {
                if (player[i].stack[j] > strongdomi) {
                    strongdomi = player[i].stack[j];
                    numerowinner = i;
                }
            j++;
            }
        }

    }
    return numerowinner;
}


/* cette fonction détermine le gagnant en comparant les points des joueurs */
void classement(Player *player, short numberplayer){
    short tab[8][2];
    short i;
    short j;
    short temp;
    short temp2;
    for(i=0;i<numberplayer;i++){
        tab[i][0] = player[i].point;
        tab[i][1] = i;
    }
    for(i=1;i<numberplayer;i++){
        temp = tab[i][0];
        temp2 = tab[i][1];
        j = i - 1;
        while(j>=0 && tab[j][0] < temp){
            tab[j+1][0]=tab[j][0];
            tab[j+1][1]=tab[j][1];
            j--;
        }
        tab[j+1][0] = temp;
        tab[j+1][1] = temp2;
    }
    printf("\n\nClassement:     NumeroJ  PTS\n");
    for(i=0;i<numberplayer;i++){
        if(tab[i][0]==tab[i+1][0]){
            j = egality(player,i,i+1);
            if(j != i){
                temp = tab[j][0];
                temp2 = tab[j][1];
                tab[j][0] = tab[i][0];
                tab[j][1] = tab[i][1];
                tab[i][0] = temp;
                tab[i][1] = temp2;
            }
        }
        printf("\t\tJoueur%d  %d\n",tab[i][1]+1,tab[i][0]);
    }
}

/* Creer un fichier de sauvegarde du tours en cours */
void saveTowerBin(Player *player, char *namefile, short *pickomino, short domino, short numberplayer){
    FILE *sauvegarde;
    sauvegarde = fopen(namefile,"wb");
    fwrite(&numberplayer, sizeof(short),1,sauvegarde);
    fwrite(&domino,sizeof(short),1,sauvegarde);
    fwrite(pickomino,sizeof(short),16,sauvegarde);
    fwrite(player,sizeof(Player),numberplayer,sauvegarde);
    fclose(sauvegarde);
}

/* Creer un fichier de sauvegarde de la partie en cours */
void savePartybin(char *namefile){
    FILE* sortie;
    printf("Enter a name to save the current game : ");
    scanf("%s",namefile);
    strcat(namefile,".bin");
    while((sortie = fopen(namefile,"wb"))== NULL){
        printf("Enter a name valid to save the current game : ");
        scanf("%s",namefile);
        strcat(namefile,".bin");
    }
    fclose(sortie);
}

/* Permet de reprendre la partie ou l'on s'etait arrete */
void readSaveBinary(Player *player, char *namefile, short *save, short *pickomino, short *domino, short *numberplayer){
    char yesno[5];
    FILE* charge;
    printf("Do you have a save file ? ");
    scanf("%s", yesno);
    while(strcmp(yesno,"yes") != 0 && strcmp(yesno,"no") != 0){
        printf("Please give a right answer : ");
        scanf("%s", yesno);
    }
    if(strcmp(yesno, "yes") == 0){
        printf("Do you want continue with the save ? ");
        scanf("%s", yesno);

        if(strcmp(yesno, "yes") == 0){
            printf("Name of the save file please : ");
            here : scanf("%s", namefile);
            strcat(namefile,".bin");
            charge = fopen(namefile, "rb");
            if(charge == NULL){
                printf("Enter a valid file name : ");
                goto here;
            }
            fread(numberplayer, sizeof(short), 1,charge);
            fread(domino, sizeof(short), 1, charge);
            fread(pickomino, sizeof(short), 16, charge);
            fread(player, sizeof(Player), *numberplayer, charge);
            *save = 1;
            fclose(charge);
        }
        else{
            charge=NULL;
        }
    }
    else{
        charge=NULL;
    }
}

/* Fonction permettant de passer au tour suivant,
    qui r�initialise le tableau de valeur du joueur
    et qui relance les d�s afin que le nouveau tour commence
*/
void continuParty(Player *player,char *namefile,short numberplayer,short *pickomino,short *domino,short *rolldice, short *dicekeep,short ascii){
    short indexplayer = 0;

    while(*domino) {
        printf("\n\nPlayer's tower %d (%s) :\n", indexplayer + 1,player[indexplayer].Name);
        printf("\nHere are the available pickominos :\n");
        if(ascii == 0){
            drawDomino(pickomino);
        }
        else{
            drawDominoUnix(pickomino);
        }
        initValue(dicekeep,0,8,0);
        if (player[indexplayer].ia == 0){
            continuTower(player,pickomino,domino,rolldice,dicekeep,numberplayer,indexplayer);
        }
        else{
            continuTowerIA(player,pickomino,domino,rolldice,dicekeep,numberplayer,indexplayer);
        }
        indexplayer++;
        if (indexplayer == numberplayer) {
            if ((*domino) > 1) {
                saveTowerBin(player,namefile,pickomino,*domino,numberplayer);
            }
            indexplayer = 0;
        }
    }
    score(player, numberplayer);
    classement(player, numberplayer);
}
