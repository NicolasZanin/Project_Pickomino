#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Cette fonction initie le tableau *t à 0*/
void init0(int *t,int nombre){
    int i=0;
    for(i=0;i<nombre;i++){
        t[i] = 0;
    }
}

/*Cette fonction affiche le tableau *t */
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

/* On met les valeurs dans le *t en commençant à la valeur commence*/
void initvalue(int *t,int nombre,int valeur,int commence){
    int i=0;
    for(i=commence;i<commence+nombre;i++){
        t[i] = valeur; 
    }
}

/* Ici on lance les des et on met les valeurs correspondante dans le tableau *t */
void lancerdes(int *t,int nombre){
    int j=0;
    int i=0;
    for(i=0;i<nombre;i++){
        j = (rand() % 6) + 1;
        t[i] = j;
    }
}

/* Laisse l'utilisateur choisir la valeur parmis tout les dés proposées (ne gère pas les cas où la valeur est déjà dans le tableau tab (celui qui mémorise les lancers) et si la valeur n'est pas contenu dans le tableau ou les dés ont été lancés (dans *t)*/
void choix(int *t,int *tab,int *des1){
    char s[20];
    int compte = 0; /* Compte le nombre d'apparition du caractère*/    
    int temp=0; /* Permet de transformer le caractère c en int */
    int i=0; /* Pour la boucle for */
    printf("Veuillez choisir une valeur : ");
    scanf("%s",s);
    temp = (int)s[0];/* Ici c'est le nombre du caractère ascii de c (exemple 1: c'est 49 dans la table ascii) */
    if (temp == 86){
        temp -=80; /* Convertit V à la valeur 6 */
    }
    else {
        temp -=48;
    }
    for(i=0;i<8;i++){ 
        if (t[i] == temp){
            compte ++;
        }
    }
    initvalue(tab,compte,temp,8-(*des1)); 
    *des1-=compte;
}

void continuegame (int *t,int *tab){
    int nombredes=8;
    while(nombredes>1){
        lancerdes(t,nombredes);
        affiche(t,nombredes);
        choix(t,tab,&nombredes);
        affiche(tab,8-nombredes);
        printf("\n");
        init0(t,8);
    }
}

int main(void){
    int des[8];
    int res[8];
    srand(time(NULL));
    init0(des,8);
    init0(res,8);
    continuegame(des,res);
    return 0;
}