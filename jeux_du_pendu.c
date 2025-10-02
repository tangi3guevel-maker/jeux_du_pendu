#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 100


int verifier_tentative(int c,int *mot){
    int i;
    for(i=0;i<15;i=i+1){
        printf("%c",mot[i]);
    }
}

int main(void){
    int mot[TAILLE_MAX_MOT]; // mot mystére
    int erreur; // monbre d'érreur
    int mot_touvee=0; // tanque mot mystére non trouvée = 0 sinon = 1
    int essai; // letre chois par joueur 2
    printf("joueur 1 choisisser votre mot mystére : ");
    scanf("%s",mot);
    printf("joueur 1 choisisser votre nombre d'érreur : ");
    scanf("%d",&erreur);
    printf("Le mot mystére est %s avec %d érreur \n",mot,erreur);
    while(mot_touvee==0){
        printf("Joueur 2 choisiser une letre : ");
        scanf("%s \n",essai);
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
