# SO LONG

## PARTIE OBLIGATOIRE

| Nom du programme              | so_long                                                                  |
| ----------------------------- | :----------------------------------------------------------------------: |         
| Fichiers de rendu             | Makefile, *.h, *.c, quelques cartes                                      |
| Makefile                      | NAME, all, clean, fclean, re                                             |
| Arguments                     | Une carte au format *.ber                                                |
| Fonctions externes autorisées | • open, close, read, write, printf, malloc, free, perror, strerror, exit |
|                               | • Toutes les fonctions de la MiniLibX                                    |

### Description 

Vous devez créer un jeu 2D basique dans lequel un dauphin s’échappe de la planète Terre après avoir mangé du poisson. 
Au lieu d’un dauphin, de poisson et de la Terre, vous pouvez utiliser le personnage, les items et le décor de votre choix.

Votre projet doit respecter les règles suivantes :

• Vous devez utiliser la MiniLibX. Soit la version disponible sur les machines de
l’école, soit en l’installant par les sources.

• La gestion de la fenêtre doit rester fluide (changer de fenêtre, la réduire, etc.).

• Bien que les exemples donnés montrent un thème dauphin, vous êtes libre de créer
l’univers que vous voulez.

• La carte sera construite en utilisant 3 éléments : les murs, les items à ramasser, et
l’espace vide.

• Le but du joueur est de ramasser tous les items présents sur la carte, puis de
s’échapper en empruntant le chemin le plus court possible.

• À chaque mouvement, le compte total de mouvement doit être affiché dans le shell.

• Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas, gauche,
droite.

• Vous devez utiliser une vue 2D (vue de haut ou de profil).

• Le jeu n’a pas à être en temps réel.

• Le joueur ne doit pas pouvoir se déplacer dans les murs.

• Votre programme doit afficher une image dans une fenêtre et respecter les règles
suivantes :

◦ Les touches W, A, S, et D doivent être utilisées afin de mouvoir le personnage
principal.
◦ Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme
proprement.
◦ Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le
programme proprement.
◦ L’usage des images de la MiniLibX est fortement recommandé.
• Votre programme doit prendre en paramètre un fichier de carte se terminant par
l’extension .ber.
◦ Votre carte peut être composée de ces 5 caractères :
0 pour un emplacement vide,
1 pour un mur,
C pour un item à ramasser (c pour collectible),
E pour une sortie,
P pour la position de départ du personnage.
◦ La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas,
le programme retourne une erreur.
◦ La carte doit contenir au moins une sortie, un item, et une position de départ.
◦ Vous n’avez pas à vérifier s’il existe un chemin valide (qu’il est possible d’emprunter) dans la carte.
◦ La carte doit être de forme rectangulaire.
◦ Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les
règles énoncées ci-dessus.
◦ Si une erreur de configuration est détectée, le programme doit quitter proprement et retourner "Error\n" suivi d’un message d’erreur explicite de votre
choix.

## PARTIE BONUS

Du moment que vous justifiez leur utilisation en évaluation, vous avez le droit d’utiliser des fonctions supplémentaires afin de faire la partie bonus. Soyez malins !

Liste de bonus :

• Le joueur peut perdre si son personnage est touché par une patrouille ennemie.
• Ajoutez des sprite animations.
• Le compte total de mouvement est directement affiché sur l’écran dans la fenêtre, plutôt que dans le shell.


## Etapes de mon programme

### PARSING DE LA MAP

map.ber est un argument de mon main
ouvrir map avec open
verifier que extension = .ber, que ca s'ouvre bien
-> map ouverte
utiliser gnl pour recupere ligne par ligne 
puis split "\n" pour avoir vraie map 2D
recuperer valeur largeur et hauteur de la map
parsing map : verifier qu'elle est correcte (coin = 1, regarde si rectangulaire avec strlen, check composition C P E 1 ou 0, puis compter ces lettres)


https://pub.phyks.me/sdz/sdz/ile-mapping.html

Lancer le programme : 

```./so_long ./maps/<name_of_the_map>.ber```