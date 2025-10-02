#include <stdio.h>
#include <stdlib.h>

struct Maillon {
    int valeur;
    struct Maillon* suivant;
};

struct Maillon* creerMaillon(int v) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = v;
    m->suivant = NULL;
    return m;
}

// Insérer dans une liste triée croissante
struct Maillon* inserer(struct Maillon* tete, int val) {
    struct Maillon* m = creerMaillon(val);

    // Si la liste est vide ou val doit aller au début
    if (tete == NULL || val < tete->valeur) {
        m->suivant = tete;
        return m;
    }

    struct Maillon* temp = tete;
    while (temp->suivant != NULL && temp->suivant->valeur < val) {
        temp = temp->suivant;
    }
    m->suivant = temp->suivant;
    temp->suivant = m;

    return tete;
}

void afficher(struct Maillon* tete) {
    struct Maillon* temp = tete;
    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

int main() {
    struct Maillon* tete = NULL;

    tete = inserer(tete, 10);
    tete = inserer(tete, 5);
    tete = inserer(tete, 20);
    tete = inserer(tete, 15);

    printf("Liste triee : ");
    afficher(tete);

    return 0;
}
