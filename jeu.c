#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init0(int *t,int nombre){
    int i=0;
    for(i=0;i<nombre;i++){
        t[i] = 0;
    }
}

void affiche(int *t,int nombre){
    int i=0;
    for(i=0;i<nombre;i++){
        if (t[i] == 6){
            printf("V ");
        }
        else{
            printf("%d ",t[i]);
        }        
    }
    printf("\n");
}

void initvalue(int *t,int nombre,int valeur){
    int i=0;
    for(i=0;i<nombre;i++){
        t[i] = valeur; 
    }
}

void lancerdes(int *t,int nombre){
    int j=0;
    int i=0;
    for(i=0;i<nombre;i++){
        j = (rand() % 6) + 1;
        t[i] = j;
    }
}

void choix(int *t,int *tab){
    char c;
    int temp=0;
    int compte = 0; /* Count value */
    int i=0;
    printf("Veuillez choisir une valeur : ");
    scanf("%c",&c);
    temp = (int)c;
    if (temp == 86){
        temp -=80;
    }
    else {
        temp -=48; /* string to int; Convertition table ascii*/
    }
    for(i=0;i<8;i++){
        if (t[i] == temp){
            compte ++;
        }
    }
    initvalue(tab,compte,temp);
}

void continuegame (int *t,int *tab){
    lancerdes(t,8);
    affiche(t,8);
    choix(t,tab);
    affiche(tab,8);
    lancerdes(t,8);
    affiche(t,8);
    choix(t,tab);    
}

int main(void){
    int des[8];
    int res[8];    
    srand(time(NULL));
    init0(des,8);
    init0(res,8);
    lancerdes(des,8);
    affiche(des,8);
    choix(des,res);
    affiche(res,8);
    printf("\n");
    lancerdes(des,8);
    affiche(res,8);
    return 0;
}