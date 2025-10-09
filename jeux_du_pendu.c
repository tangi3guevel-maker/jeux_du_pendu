#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAILLE_MAX_MOT 100

// Fonction pour afficher l'ASCII art en fonction du nombre d'erreurs
void afficher_pendu(int erreurs_actuelles, int erreurs_max) {
    // Calcul du taux d'erreur en pourcentage
    int taux_erreur = (erreurs_actuelles * 100) / erreurs_max;
    // Ajout de la barre supérieure (30%)
    if (taux_erreur >= 30) {
        printf("  _______\n"); // Barre supérieure (transversale)
    }
    // Ajout de la corde (40%)
    if (taux_erreur >= 40) {
        printf("  |/ |\n"); // Corde accrochée
    } else if (taux_erreur >= 30) {
        printf("  |/ \n"); // Barre sans corde
    }
    if (taux_erreur>=50){
        printf("  | (_)\n"); // Tête du pendu
    }
    else if(taux_erreur>=20){
        printf("  |\n"); // Pilier complet (à 20%)
    }
    // Ajout des bras (60%)
    if (taux_erreur >= 60) {
        printf("  | \\|/\n"); // Bras complets
    } else if (taux_erreur >= 20) {
        printf("  |\n"); // Pas de bras, mais espace sous le torse
    }
    // Ajout du torse (80%)
    if (taux_erreur >= 80) {
        printf("  |  |\n"); // Torse
    } else if (taux_erreur >= 20) {
        printf("  |\n"); // Pas de torse, mais espace sous la tête
    }
    // Ajout des jambes (100%)
    if (taux_erreur >= 100) {
        printf("  | / \\\n"); // Jambes complètes
    } else if (taux_erreur >= 10) {
        printf("  |\n"); // Pas de jambes, mais espace sous les bras
    }
    if (taux_erreur>=10){// Affichage de la base du pilier
        printf("__|__\n");
    }
}

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

void afficher_mot_devine(char *mot){
    int b; // valeur de la boucle
    printf("le mot mystere est : ");
    for(b=0;b<strlen(mot);b=b+1){
        printf("%c",mot[b]);
        printf("%c",' ');
    }
    printf("\n");
}

void afficher_progression(char *mot_actuel,char *lettre_deja_fausse,int ereur_restant){
    printf("Les lettre fausse deja utilise sont %s et il reste %d d'ereur \n",lettre_deja_fausse,ereur_restant);
    afficher_mot_devine(mot_actuel);
}

int main(void){
    char mot[TAILLE_MAX_MOT]; // mot mystére du joueur 1
    int erreur_max; // nombre maximal d'érreur
    int erreur=0; // nombre d'érreur
    int mot_touvee=0; // tanque mot mystére non trouvée = 0 sinon = 1 si trouvé
    int n; // valeur de la boucle
    int j=0; // valeur de la boucle
    printf("joueur 1 choisisser votre mot mystére : ");
    scanf("%s",mot);
    printf("joueur 1 choisisser votre nombre d'érreur : ");
    scanf("%d",&erreur_max);
    printf("Le mot mystére est %s avec %d érreur \n",mot,erreur_max);
    for(n=0;n<strlen(mot);n=n+1){
        mot[n]=tolower(mot[n]);
    }
    char mot_a_trouve[strlen(mot)*2]; // mot mystére pour joueur 2
    while(j<(strlen(mot))){
        mot_a_trouve[j] = '_';
        j=j+1;
    }
    int i; // valeur de la boucle
    int k; // valeur de la boucle
    int m; // valeur de la boucle
    int lettre_vrai=0;
    int lettre_deja_utilise=0;
    int lettre_trouvee=0;
    char mot_erreu[TAILLE_MAX_MOT]; // lettre fausse déjà utilisé
    char essai; // letre chois par joueur 2 
    while(mot_touvee==0){
        printf("Joueur 2 choisiser une letre : ");
        scanf(" %c", &essai);
        for(i=0;i<strlen(mot);i=i+1){
            if(verifier_tentative(essai,mot[i])==1){ // la lettre est dans le mot mystére
                mot_a_trouve[i]=maj_mot_devin(mot_a_trouve[i],essai);
                lettre_vrai=lettre_vrai+1; // +1 si la lettre est dans le mot mystére
            }   
        }
        if(lettre_vrai==0){ // la lettre n'aparait pas dans le mot
            for(k=0;k<strlen(mot_erreu);k=k+1){
                if(mot_erreu[k]==essai){ // la letre fausse à déjà été noté
                    lettre_deja_utilise=lettre_deja_utilise+1; // +1 si la lettre est dans la liste d'érreur
                }
            }
            if(lettre_deja_utilise==0){ // si la lettre na pas été noté
                mot_erreu[strlen(mot_erreu)]=essai; // rajoute la letre à la liste
                erreur=erreur+1; // fait perdre une vie
            }
        }

        lettre_vrai=0;
        lettre_deja_utilise=0;
        
        for(m=0;m<strlen(mot);m=m+1){
            if(mot_a_trouve[m]==mot[m]){ // vérifit si le mot est bien le mot à trouvée
                lettre_trouvee=lettre_trouvee+1;
            }
        }
        if(lettre_trouvee == strlen(mot)){ // le joueur 2 à trouvée le mot mystére 
            mot_touvee=1;
        }
        lettre_trouvee=0;

        afficher_progression(mot_a_trouve,mot_erreu,erreur_max-erreur);
        afficher_pendu(erreur,erreur_max);

        if(erreur==erreur_max){ // le joueur 2 n'a plus de vie
            printf("\nPERDU\n le mot été %s \n\n",mot);
            return 0;
        }
    }
    printf("\ngagné\n\n");
    return 0;
}
