# Projet - Performance et Parallélisme (OpenMP en C)

Ce projet contient plusieurs implémentations parallèles avec OpenMP et séquentielles de :

- Calcul de la fractale de Mandelbrot
- Calcul de PI

Les programmes sont compilés avec `gcc` en utilisant `-fopenmp` pour OpenMP, y compris pour les versions séquentielles même si ils ne l'utilise pas.

---

## Compilation

Depuis la racine du projet :

```
make
```

Pour nettoyer :

```
make clean
```

---

## Choix du nombre de threads

OpenMP utilise une variable d’environnement pour déterminer le nombre de threads :

```
export OMP_NUM_THREADS=8
```

Exemple d’exécution :

```
export OMP_NUM_THREADS=16
./mandel_omp_schedule
```

---

## Choix du scheduler

Tous les fichiers dont le nom se termine par `_schedule` utilisent la variable d’environnement :

```
OMP_SCHEDULE
```

Elle permet de choisir dynamiquement le scheduling, exemples :

```
export OMP_SCHEDULE="static,1"
./mandel_omp_schedule
```

```
export OMP_SCHEDULE="dynamic,1"
./mandel_omp_schedule
```

```
export OMP_SCHEDULE="static,1000"
./pi_omp_schedule
```

---

## Rapports d'analyse des performances

Le dossier `rapport/` contient les documents d’analyse des performances :

- `CompteRenduMandelbrot.*` : Version Markdown ou PDF du rapport sur Mandelbrot
- `CompteRenduPi.pdf` : Version Markdown ou PDF du rapport sur le calcul de PI
- `donnees.ods` : ensemble des mesures de performances relevées manuellement (temps d’exécution et speedup)  