#include <stdio.h>
#include <stdlib.h>

struct Maillon {
    int valeur;
    struct Maillon* suivant;
    struct Maillon* precedent;
};

// Insertion en tête
struct Maillon* insererTete(struct Maillon* tete, int val) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = val;

    if (tete == NULL) {
        m->suivant = m->precedent = m;
        return m;
    }
    struct Maillon* last = tete->precedent;
    m->suivant = tete;
    m->precedent = last;
    tete->precedent = m;
    last->suivant = m;
    return m; // nouvelle tête
}

// Insertion en queue
struct Maillon* insererQueue(struct Maillon* tete, int val) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = val;

    if (tete == NULL) {
        m->suivant = m->precedent = m;
        return m;
    }
    struct Maillon* last = tete->precedent;
    m->suivant = tete;
    m->precedent = last;
    last->suivant = m;
    tete->precedent = m;
    return tete; // la tête ne change pas
}

void afficher(struct Maillon* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    struct Maillon* temp = tete;
    do {
        printf("%d <-> ", temp->valeur);
        temp = temp->suivant;
    } while (temp != tete);
    printf("(retour)\n");
}

int main() {
    struct Maillon* tete = NULL;

    tete = insererQueue(tete, 1);
    tete = insererQueue(tete, 2);
    tete = insererTete(tete, 0);
    tete = insererQueue(tete, 3);

    afficher(tete);

    return 0;
}
