#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 100


int verifier_tentative(char c,char *mot){
    int i; // valeur de la boucle
    int est_trouve=0; // renvoie 0 si c n'est pas dans mot sinon renvoi 1
    for(i=0;i<strlen(mot);i=i+1){
        if(mot[i]==c){
            est_trouve=1;
        }
    }
    return est_trouve;
}

int maj_mot_devin(char mot_devine,char *mot_mystere){
    
}

int main(void){
    char mot[TAILLE_MAX_MOT]; // mot mystére
    int erreur; // monbre d'érreur
    int mot_touvee=0; // tanque mot mystére non trouvée = 0 sinon = 1
    printf("joueur 1 choisisser votre mot mystére : ");
    scanf("%s",mot);
    printf("joueur 1 choisisser votre nombre d'érreur : ");
    scanf("%d",&erreur);
    printf("Le mot mystére est %s avec %d érreur \n",mot,erreur);
    while(1){
        char essai; // letre chois par joueur 2 
        printf("Joueur 2 choisiser une letre : ");
        scanf(" %c", &essai);
        if(verifier_tentative(essai,mot)==1){
            printf("oui \n");
        }
        else{
            printf("non \n");
        }
    }
    //Prochaine etape ?
    // Tant que joueur 2 n'a pas trouvé le mot 
        //joueur 2 fait une proposition
    
}
