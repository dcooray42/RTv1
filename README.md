# RTv1

Troisième projet de la branche graphique en parallèle de wolf3d de l'école 42. Créer un programme qui utilise la méthode du 
raytracing.

Pour ce projet, quelques notions de base sont demandés et obligatoires :
* Gérer 4 formes géométrique basiques (sphère, plan, cône, cylindre)
* Gérer les translations et rotations
* Gérer le positionnement et la direction de la caméra
* Gérer la lumière (1 spot lumineux minimum) et les effets qu'elle implique (luminosité et ombre)

Enfin, voici les bonus qui peuvent être implémenter dans le programme :
* Multi-spot
* Brillance (Phong)

## Pour commencer

Ces instructions vous aiderons a avoir une copie du projet et de pouvoir le faire marcher sur votre ordinateur.

### Prérequis

Ce que vous devez faire pour télécharger les fichiers sources afin de pouvoir les compiler par la suite

```
git clone https://github.com/konamifox/RTv1.git [nom du PATH/dossier]
```

### Installation

Se placer dans le dossier dans lequel vous avez fait la copie des fichiers sources du projet puis rentrer la commande suivante

```
make
```
Plusieurs fichiers .o auront fait leur apparitions dans le dossier que vous avez cloné ainsi que le binaire

```
rtv1
```
### Suppression

Pour supprimer les fichiers objets .o généré lors de la création du programme

```
make clean
```

Pour supprimer les fichiers objets .o et le programme

```
make fclean
```

Pour tout supprimer puis recompiler le programme

```
make re
```

## Faire des tests

Une fois que le programme a été crée, vous n'avez plus qu'à rentrer en ligne de commande le nom du programme + le fichier 
de description de scène.

### Utilisation du programme

Ligne de commande

```
./rtv1 [PATH/fichier de description de scène]
```

### Commandes

Utiliser la deuxième fenètre ouverte simultanément avec la fenètre de rendu de la scène pour intéragir avec cette dernière.

#### Exemple
![alt text](https://raw.githubusercontent.com/konamifox/photo/master/RTv1_1.jpeg?token=AT6ePGzIO0oJxvL3CMS76u6BBPgmAmITks5acek8wA%3D%3D)
![alt text](https://raw.githubusercontent.com/konamifox/photo/master/RTv1_2.jpeg?token=AT6ePP-MANreNtMJSJU2CjtGuAd68f0pks5acelBwA%3D%3D)
![alt text](https://raw.githubusercontent.com/konamifox/photo/master/RTv1_3.jpeg?token=AT6ePP5O0KiIMaqiaxz_hirFCRnecwvsks5acelLwA%3D%3D)
![alt text](https://raw.githubusercontent.com/konamifox/photo/master/RTv1_4.jpeg?token=AT6ePH_PF_xH2xLLEbL19faS6d5n-y7Hks5acelQwA%3D%3D)

## Compiler avec
* Minilibx - Librairie graphique

## Licence
* Minilibx - License BSD: Copyright Olivier Crouzet - 2014

## Auteur

* **Dimitri Cooray** - [Lien vers github](https://github.com/konamifox)
