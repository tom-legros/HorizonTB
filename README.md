# HorizonTB 

**HorizonTB** est une barre de tâches alternative et modulaire (Windows, Linux, macOS) conçue avec une panoplie de widgets personnalisables. 
Chaque composant (météo, horloge) est un widget autonome et indépendant.

## Fonctionnalités

- **Widget Horloge** : Affichage de l'heure et de la date.
- **Widget Météo** : Affichage de la météo avec une petite icône.

## Stack technique

- **Langage** : C++17
- **Framework** : Qt 6

## Architecture du projet

```text
HorizonTB/
├── mainwindow.cpp / .h     # Fenêtre principale (conteneur de la barre)
├── widgethorloge.cpp / .h  # Widget autonome d'affichage de l'heure
├── widgetmeteo.cpp / .h    # Widget d'affichage météo
├── CMakeLists.txt          # Fichier de configuration CMake
└── README.md
```

## Récupérer le projet

1. Cloner le dépôt :
   ```cmd
   git clone https://github.com/tom-legros/HorizonTB.git
   ```

---
*Développé avec passion par **Tom Legros** en C++ avec Qt 6.*