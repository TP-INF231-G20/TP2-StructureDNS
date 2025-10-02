# TP2-StructureDNS
Exercice 1 : Supprimer toutes les occurrences dans une liste simplement chaînée
on parcourt la liste et on enlève tous les maillons qui contiennent la valeur cherchée.
Si la valeur est au début, on déplace la tête.
Si la valeur est ailleurs, on relie le maillon précédent avec le suivant, puis on libère la mémoire.
Exemple :
Liste : 1 -> 2 -> 3 -> 2 -> 4 -> NULL
Supprimer 2
Résultat : 1 -> 3 -> 4 -> NULL

Exercice 2 : Insertion dans une liste simplement chaînée triée
On insère un nouveau maillon à la bonne position pour garder l’ordre croissant.
Si la liste est vide ou si la valeur est plus petite que la première → insérer au début.
Sinon → avancer jusqu’à trouver l’endroit correct, puis insérer.
Exemple :
Liste : 5 -> 10 -> 20 -> NULL
Insérer 15
Résultat : 5 -> 10 -> 15 -> 20 -> NULL

Exercice 3 : Insertion dans une liste doublement chaînée triée
On cherche la bonne place.
On met à jour deux pointeurs : suivant et precedent.
Exemple :
Liste : 10 <-> 20 <-> 40
Insérer 30
Résultat : 10 <-> 20 <-> 30 <-> 40

Exercice 4 : Insertion tête et queue dans une liste simplement chaînée circulaire
Une liste circulaire : le dernier maillon pointe vers le premier.
Insertion en tête : on ajoute un maillon juste après le dernier, mais c’est le premier logique.
Insertion en queue : on ajoute un maillon après le dernier et on met à jour le pointeur last.
Exemple :
Liste : 0 -> 1 -> 2 -> (retour)
Après insertion en queue de 3 :
0 -> 1 -> 2 -> 3 -> (retour)

Exercice 5 : Insertion tête et queue dans une liste doublement chaînée circulaire
Pareil que l’exo 4 mais chaque maillon a deux liens (suivant et precedent).
En tête, on ajoute avant le premier.
En queue, on ajoute après le dernier.
Comme la liste est circulaire, le premier et le dernier sont reliés ensemble.
Liste : 0 <-> 1 <-> 2 <-> (retour)
Après insertion en queue de 3 :
0 <-> 1 <-> 2 <-> 3 <-> (retour)
