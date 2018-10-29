# League of Gems / LOG
The game is an Online Battle Arena. A single player will control a group of few characters, giving them intructions to defeat the enemies and get the gems.
## Description
In League of Gems, the player have to control his minions and use his skills to get the gem protected by the enemy. Both, player and AI, will have 10 different skills and a wave of minions. The AI will improve his minions' stats every level to make the game challenging. The player can move the camera to see any side of the map, but he can only see the enemies in skouted places.
Each level has a different pathfinding algorithm for the minions.
## Features
* Minions:
The player and the enemy have a wave of minions that will help you get the gem.
* Skills:
The player and the enemy have a list of skills use to help the minions reach the gem.
* Map/Level:
For each level there is a map with different path to be taken.
* Genetic Algorithm:
The genetic algorithm creates better waves of minions for every level completed.
* Pathfinding Algorithms:
Each level use a different pathfinding algorithm.
## User Stories
As a player, I want the minions to move to the position where I click to find the way to get the gem.
As a player, I want skills that give me the chance to support my minions while the fight to get the gem.
## Updates
## Diagrams
![league of gems-class diagram](https://user-images.githubusercontent.com/29305622/47621989-3062e480-dac5-11e8-9b07-466cf0201f69.png)
## Data Structures
* Node:
Data structure that saves an element into a greater data structure which will reference a starting node and the nodes will reference the next node.
* List:
The list is a linear collection of nodes.
* Matrix:
The matrix is a two dimensions data structure that save a list of lists.
## Algorithms
### Pathfinding:
* A* Search:
The A* Search algorithm takes a starting node from the graph and generate a tree with the paths it can take until the algorithm finds the target node, then the tree gives the path that reach the target.
* Prim:
This algorithm takes a starting position into a graph and the takes the edges with the lowest cost from there until it gets a minimal spanning tree.
* Dijkstra:
* Kruskal:
This algorithm takes the edges from the lowest cost to the highest and conect the nodes until there is a minimal spanning tree.
### Genetic Algorithm:
The genetic algorithm will create a starting wave of minions for the first level, and for the others it will take the previous level's wave and get the best minion for each class, then it will generate minions with similar stats.
## Bugs
## About
Instituto Tecnológico de Costa Rica
Área Académica Ingeniería en Computadores
CE-2103: Algoritmos y Estructuras de Datos II
Proyecto #2 - League of Gems
### Miembros:
* Víctor Castrillo Muñoz (2017110244)
* Gabriel Abarca Aguilar (2017110442)
* María Ávila Marin (2014089607)
* Roger Mora González (2017115791)
