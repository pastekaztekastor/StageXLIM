# Simulation de foule avec CUDA

Ce *README* servira davantage de feuille de route/journal de bord qu'un README classique. Les quelques documents pouvant être utiles seront tout de même répertoriés ici.

## Table des matières

- [Simulation de foule avec CUDA](#simulation-de-foule-avec-cuda)
  - [Table des matières](#table-des-matières)
  - [Fichier Utiles](#fichier-utiles)
  - [Introduction du sujet](#introduction-du-sujet)
  - [Structure du programme](#structure-du-programme)
    - [Rendu](#rendu)
    - [Utilisation de CUDA](#utilisation-de-cuda)
    - [Makefile](#makefile)
    - [Pour aller plus loin](#pour-aller-plus-loin)
  - [Installation](#installation)
  - [Utilisation](#utilisation)
  - [Liste des tâches à effectuer](#liste-des-tâches-à-effectuer)
    - [Organisation](#organisation)
    - [Programmation](#programmation)

## Fichier Utiles

- [Pointage](markdown/pointage.md)
- [Journal de bord](markdown/journal_de_bord.md)
- [Programme CPU](markdown/onlyCPU.md)

## Introduction du sujet

Lors de la réunion de début de stage (01-06-2023), le projet de stage et de simulation a été présenté de la manière suivante :

L'objectif est de simuler une foule en 2D en utilisant des modèles physiques existants. Cependant, il est nécessaire de paralléliser autant que possible la simulation en utilisant CUDA dans un premier temps.

- Étude de modèles de foule -> Théorie mathématique
  - Congestion du trafic routier
  - Simulations principalement réalisées avec ***MatLab***, ce qui limite l'optimisation des calculs et n'autorise aucune parallélisation.
  - La taille de la population influence la qualité des résultats. Plus elle est importante, plus les résultats sont intéressants.
- Simulation uniquement en 2D
- Plusieurs façons de procéder avec de nombreux modèles mathématiques

> Il existe des simulations basées sur des particules pour cela, mais nous n'utiliserons pas ces modèles.

- Nous optons pour un fonctionnement basé sur une grille (avec des "roomels" - éléments de la pièce - d'une dimension de 1, mais cela n'a pas d'importance).
  - Chaque roomel ne peut contenir qu'une seule personne et elles ne peuvent pas se comprimer.
  - Dans un premier temps, nous avons une distribution aléatoire d'individus dans la pièce.
  - Les individus ont pour objectif de sortir de la pièce et **ils se déplacent tous à la même vitesse**.

Lors du déplacement, il peut y avoir des situations problématiques, si une personne est déjà présente sur la case, ou si on rencontre un mure. Il faut donc prévoire ces cas. 

- Ne rien faire.
- Prendre une case voisine au hasard.
- Prendre la case voisine la plus proche.

> Même si, dans la vraie vie, nous avons tendance à privilégier les personnes les plus proches de la sortie.

Pour le mélange, nous pouvons mélanger un tableau d'indices pointant vers les individus.

## Structure du programme

Dans le programme il y a 3 étapes 

```mermaid
---
title : Structure du programme
---
flowchart TB;
  subgraph principal 
    direction LR
    a[Initialisation] --> b[Simulation] --> c[Retour]
    b -->sB
    c -->sC
    a -->sA
  end
  subgraph sA [Paramètres]
    sa1[Variables de Simulation]
    sa3[Constante de Simulation]
    sa2[Variables de support]
    sa4[Choix du model]

  end
  subgraph sB [Pour chaque frame]
    direction TB
    sb1[Shuffle des individue] -->sb2
    sb2[Applicaiton du model] --> |Pour chaque individu| sb2

  end
  subgraph sC [Retour]
    sc1[Temps de caclul]
    sc2[Congestion]
    sc3[Annimation]
  end
 ```

 Pour ce qui est du choix du model nous avons plusieur paramètre qui pe

### Rendu

Le rendu final n'est pas une priorité. Nous pourrions générer des fichiers binaires qui seront lus par un programme **Processing** pour produire des images ou des vidéos. Le programme doit être modifiable à l'aide de fichiers de configuration au format JSON. Nous devons également pouvoir récupérer des données de sortie (tableau de fichiers binaires).

### Utilisation de CUDA

Parallélisation des calculs pour chaque individu à l'aide de CUDA.

### Makefile

Je dois me renseigner sur le fonctionnement des fichiers Makefile.
Je ne pense pas qu'un Makefile soit utile pour le moment. Dans le pire des cas un ficher `bach` sera amplement suffisant.

### Pour aller plus loin

Nous avons un objectif de rendu.

## Installation

Dans un premier temps, j'ai commencé par créer un programme qui implémente ce que nous avons décrit, mais uniquement en utilisant le CPU. La documentation détaillée de ce programme est disponible dans le fichier [onlyCPU.md](markdown/onlyCPU.md).

Cepandant dans un premier temps vous pouvez essayer le programme `onlyCPU` sur votre propre machine. Elle doit néanmoins être équipé d'un terminal et de bach.

## Utilisation

> À faire

## Liste des tâches à effectuer

### Organisation

- [x] Réalisation du fichier README.md
- [x] Explication du projet
- [ ] Refaire le fichier  [`gitignore`](.gitignore) de manière approp
- [ ] Pas néssécaire de faire un choix de la position des individus.
- [ ] Créer un fichier Makefile.

### Programmation

- [x] Modéliser le problème
- [x] Version CPU
- [ ] Documentation de la CPU
- [ ] Benchmark de la CPU
- [ ] Version GPU
- [ ] Documentation de la GPU
- [ ] Benchmark de la GPU
