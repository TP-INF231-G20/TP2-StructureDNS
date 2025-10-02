#include <stdio.h>
#include <stdlib.h>

// Définition d'un maillon
struct Maillon {
    int valeur;
    struct Maillon* suivant;
};

// Création d'un maillon
struct Maillon* creerMaillon(int v) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = v;
    m->suivant = NULL;
    return m;
}

// Afficher la liste
void afficher(struct Maillon* tete) {
    struct Maillon* temp = tete;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// Supprimer toutes les occurrences d'une valeur
struct Maillon* supprimer(struct Maillon* tete, int val) {
    // Supprimer au début
    while (tete != NULL && tete->valeur == val) {
        struct Maillon* temp = tete;
        tete = tete->suivant;
        free(temp);
    }
    // Supprimer dans le reste
    struct Maillon* courant = tete;
    while (courant != NULL && courant->suivant != NULL) {
        if (courant->suivant->valeur == val) {
            struct Maillon* temp = courant->suivant;
            courant->suivant = temp->suivant;
            free(temp);
        } else {
            courant = courant->suivant;
        }
    }
    return tete;
}

int main() {

    struct Maillon* tete = creerMaillon(1);
    tete->suivant = creerMaillon(2);
    tete->suivant->suivant = creerMaillon(3);
    tete->suivant->suivant->suivant = creerMaillon(2);
    tete->suivant->suivant->suivant->suivant = creerMaillon(4);

    printf("Liste avant suppression : ");
    afficher(tete);

    tete = supprimer(tete, 2); 

    printf("Liste apres suppression : ");
    afficher(tete);

    return 0;
}
