#include <stdio.h>
#include <stdlib.h>

struct Maillon {
    int valeur;
    struct Maillon* suivant;
};

// Insertion en tête
struct Maillon* insererTete(struct Maillon* last, int val) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = val;

    if (last == NULL) {
        m->suivant = m;
        return m;
    }
    m->suivant = last->suivant;
    last->suivant = m;
    return last;
}

// Insertion en queue
struct Maillon* insererQueue(struct Maillon* last, int val) {
    struct Maillon* m = (struct Maillon*)malloc(sizeof(struct Maillon));
    m->valeur = val;

    if (last == NULL) {
        m->suivant = m;
        return m;
    }
    m->suivant = last->suivant;
    last->suivant = m;
    return m; // nouveau last
}

void afficher(struct Maillon* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }
    struct Maillon* temp = last->suivant;
    do {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    } while (temp != last->suivant);
    printf("(retour)\n");
}

int main() {
    struct Maillon* last = NULL;

    last = insererQueue(last, 1);
    last = insererQueue(last, 2);
    last = insererTete(last, 0);
    last = insererQueue(last, 3);

    afficher(last);

    return 0;
}
