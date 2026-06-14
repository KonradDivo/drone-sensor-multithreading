# Drone Sensor Multithreading System

Ce projet C++ implémente un système d'acquisition de données embarqué pour drone basé sur une architecture multithreadée moderne (C++20). Il simule la réception simultanée de flux de données provenant de trois capteurs critiques (IMU, GPS, LiDAR) et assure la synchronisation de la mémoire pour éviter les accès concurrents.

## 🚀 Fonctionnalités Clés
*   **Programmation Concurrente Avancée :** Utilisation des `std::jthread` (C++20) pour une gestion sécurisée et automatisée du cycle de vie des threads.
*   **Thread-Safety :** Utilisation de verrous d'exclusion mutuelle (`std::mutex` et `std::lock_guard`) pour sanctuariser la section critique (télémétrie globale).
*   **Architecture Orientée Objet :** Découpage modulaire propre séparant la structure de données (`Telemetry.h`), la logique métier (`SensorManager`) et l'orchestration (`main.cpp`).
*   **Gestion des interruptions :** Utilisation de `std::stop_token` pour arrêter proprement les flux d'acquisition à la demande.

## 🛠️ Prérequis Techniques
*   **Compilateur :** GCC/MinGW (Support strict du standard **C++20** requis).
*   **IDE :** Code::Blocks 25.03.

## ⚙️ Configuration du compilateur (C++20)
Pour compiler ce projet dans Code::Blocks 25.03, vous devez activer explicitement le standard C++20 :
1. Allez dans le menu **Settings** -> **Compiler**.
2. Dans l'onglet **Compiler Settings**, recherchez **Compiler Flags**.
3. Cochez la case correspondant à `Have g++ follow the C++20 ISO C++ language standard [-std=c++20]`.
4. Cliquez sur **OK** et relancez la compilation générale (*Rebuild*).

## 🗂️ Structure du Projet
*   `Telemetry.h` : Contient l'état structurel du drone.
*   `SensorManager.h` / `.cpp` : Encapsule les algorithmes d'acquisition des capteurs de manière isolée.
*   `main.cpp` : Initialise le cycle de vie du drone et gère l'orchestration temporelle.
