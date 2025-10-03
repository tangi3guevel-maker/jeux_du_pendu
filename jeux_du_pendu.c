#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 100


int verifier_tentative(char c,char mot){
    int est_trouve=0; // renvoie 0 si c n'est pas dans mot sinon renvoi 1
    if(mot==c){
        est_trouve=1;
    }
    return est_trouve;
}

int maj_mot_devin(char mot_devine,char mot_mystere){
    mot_devine=mot_mystere;
    return mot_devine;
}

int afficher_mot_devine(char *mot){
    printf("le mot mystere est %s",mot);
}

int main(void){
    char mot[TAILLE_MAX_MOT]; // mot mystére du joueur 1
    int erreur; // monbre d'érreur
    int mot_touvee=0; // tanque mot mystére non trouvée = 0 sinon = 1 si trouvé
    printf("joueur 1 choisisser votre mot mystére : ");
    scanf("%s",mot);
    printf("joueur 1 choisisser votre nombre d'érreur : ");
    scanf("%d",&erreur);
    printf("Le mot mystére est %s avec %d érreur \n",mot,erreur);
    char mot_a_trouve[strlen(mot)]; // mot mystére pour joueur 2
    int j=0; // valeur de la boucle
    while(j<strlen(mot)){
        mot_a_trouve[j] = '_';
        j=j+1;
    }
    printf("%s et %s \n",mot_a_trouve,mot);
    while(mot_touvee==0){
        int i; // valeur de la boucle
        int k; // valeur de la boucle
        int m; // valeur de la boucle
        int lettre_vrai=0;
        int lettre_deja_utilise=0;
        char mot_erreu[TAILLE_MAX_MOT]; // lettre fausse déjà utilisé
        char essai; // letre chois par joueur 2 
        printf("Joueur 2 choisiser une letre : ");
        scanf(" %c", &essai);
        for(i=0;i<strlen(mot);i=i+1){
            if(verifier_tentative(essai,mot[i])==1){
                mot_a_trouve[i]=maj_mot_devin(mot_a_trouve[i],essai);
                lettre_vrai=lettre_vrai+1;
            }   
        }
        if(lettre_vrai==0){ // la lettre n'aparait pas dans le mot
            for(k=0;k<strlen(mot_erreu);k=k+1){
                if(mot_erreu[k]==essai){ // vérifit si le mot faut n'a pas déjà été noté
                lettre_deja_utilise=lettre_deja_utilise+1;
                }
            }
            if(lettre_deja_utilise==0){
                mot_erreu[strlen(mot_erreu)]=essai;
                erreur=erreur-1;
            }
        }
        lettre_vrai=0;
        lettre_deja_utilise=0;
        if(erreur==0){
            printf("perdu");
        }
        printf("mot %s acctuelement %s eurreu %s et eureur restant %d \n",mot,mot_a_trouve,mot_erreu,erreur);
        for(m=0;m<strlen(mot);m=m+1){
            if(mot_a_trouve[k]==mot[k]){
                printf("vrais \n");
            }
        }
    }
    printf("gagne");
}

// ligne 69 ne prend pas en compte le if
// ligne 74 dit toujours vrais 
