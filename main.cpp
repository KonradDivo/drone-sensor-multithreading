#include "SensorManager.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "=== DÉMARRAGE DU SYSTÈME EMBARQUÉ DU DRONE (C++20) ===" << std::endl;

    SensorManager manager;

    // Utilisation des jthreads : l'appel à la fonction se fait via un pointeur de fonction membre
    // Le std::stop_token est injecté automatiquement par le jthread
   /* std::jthread threadIMU(&SensorManager::runIMU, &manager);
    std::jthread threadGPS(&SensorManager::runGPS, &manager);
    std::jthread threadLiDAR(&SensorManager::runLiDAR, &manager);*/
    // Utilisation de fonctions lambdas pour lancer les threads proprement en C++20
    std::jthread threadIMU([&manager](std::stop_token st) { manager.runIMU(st); });
    std::jthread threadGPS([&manager](std::stop_token st) { manager.runGPS(st); });
    std::jthread threadLiDAR([&manager](std::stop_token st) { manager.runLiDAR(st); });


    // On laisse tourner la simulation pendant 2 secondes
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\n=== DEMANDE D'ARRET DES CAPTEURS (DESCENTE DU DRONE) ===" << std::endl;
    // Pas besoin d'appeler de join() !
    // Les jthreads vont détruire proprement les boucles en sortant du main.

    DroneTelemetry finalData = manager.getTelemetry();
    std::cout << "\nRapport final du drone - Altitude: " << finalData.altitude
              << "m, Pitch: " << finalData.imu_pitch << std::endl;

    return 0;
}

