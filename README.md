
# my_radar

Deuxième projet graphique, C uniquement avec la librairie CSFML


## Le projet:

Créer un simulateur de trafic aérien en 2D à partir d'une map passée en paramètre :

Pour cette première version de simulateur, il est demandé de considérer deux types d'entités:
- les avions 
- les tours de controle

#### Les règles de base:
 - Les avions volent d'un endroit donné à un autre
 - Les avions apparaissent sur la simulation quand ils décollent
 - Les avions disparaissent quand ils atterrissent ou lorsqu'il rencontre un autre avion
 - Les avions se déplace en ligne droite acec une vitesse constante
 - Les tours de contrôle empêchent les collisionsentre avions dans leur périmètre d'action
 - Les tours de contrôle ne bougent pas
 - Les tours de contrôle apparaissent au lancement de la simulation

 ### Le but 
 Amener à la réflexion sur les quadtrees



## Installation

```bash
Downloads> git clone git@github.com:Nerzouille/my_radar.git
...
Downloads/my_radar> make
...
```
    
## Usage/Examples

```bash
my_radar> ./my_radar -h
    Introducing the my_radar project, an air traffic simulation.
    Pass file containing aircraft and control tower data as parameter to observe the magic.
    You can press the "S" key to show or hide the sprites.
    The same goes for hitboxes by pressing "L".

    You can press "q" at any moment to quit the simulation

my_radar> ./my_radar map.txt
    <lancement du projet>
```


## Result

|**Test**|**Result**|
|--|--|
|Preliminary|2 / 2|
|Clocks|1 / 1|
|Window size|1 / 1|
|Window framerate|1 / 1|
|Usage|1 / 1|
|Modularity|2 / 5|
|Parameter|4 / 5|
|Display hitboxes|2 / 2|
|Display shapes|2 / 5|
|Collision|2 / 3|
|Entities management|11 / 11|
|Sprites|2 / 2|
|Land on/Take off|2 / 2|
|Delayed takeoffs|2 / 2|
|Aircraft's appearance|3 / 3|
|Rotation|2 / 3|
|Speed|2 / 2|
|Displayed area|2 / 2|
|Area's shapes|1 / 1|
|Collision|2 / 2|
|Sprites|2 / 2|
|Area size|2 / 2|
|Lifetime|1 / 1|
|Changing script|1 / 1|
|Other bonus|0|
|**__Total__**|53 / 60|
|Coding Style|1 / 1|

## Authors

- SMOTER Noa ([LinkedIn](https://www.linkedin.com/in/noa-smoter/) / [Portfolio](https://noasmoter.vercel.app/))

