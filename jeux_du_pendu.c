#include <stdio.h>
#include <string.h>

#define TAILLE_MAX_MOT 100


int verifier_tentative(int c,int mot){
    for(i=0;i<(strlen(mot)+1)){
        printf("%s",mot[i])
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
        scanf("%s",essai);
        if(verifier_tentative(essai,mot)==1){
            printf("oui");
        }
        else{
            printf("non")
        }
    }
    //Prochaine etape ?
    // Tant que joueur 2 n'a pas trouvé le mot 
        //joueur 2 fait une proposition
    
}
