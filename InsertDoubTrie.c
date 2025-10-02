#include <stdio.h>
#include <stdlib.h>

struct Maillon {
    int valeur;
    struct Maillon* suivant;
    struct Maillon* precedent;
};

struct Maillon* creerMaillon(int v) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = v;
    m->suivant = NULL;
    m->precedent = NULL;
    return m;
}

struct Maillon* inserer(struct Maillon* tete, int val) {
    struct Maillon* m = creerMaillon(val);

    if (tete == NULL || val < tete->valeur) {
        m->suivant = tete;
        if (tete != NULL) tete->precedent = m;
        return m;
    }

    struct Maillon* temp = tete;
    while (temp->suivant != NULL && temp->suivant->valeur < val) {
        temp = temp->suivant;
    }

    m->suivant = temp->suivant;
    if (temp->suivant != NULL) temp->suivant->precedent = m;
    temp->suivant = m;
    m->precedent = temp;

    return tete;
}

void afficher(struct Maillon* tete) {
    struct Maillon* temp = tete;
    while (temp != NULL) {
        printf("%d <-> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

int main() {
    struct Maillon* tete = NULL;

    tete = inserer(tete, 30);
    tete = inserer(tete, 10);
    tete = inserer(tete, 20);

    printf("Liste doublement chainee triee : ");
    afficher(tete);

    return 0;
}
