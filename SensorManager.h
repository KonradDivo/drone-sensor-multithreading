#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "Telemetry.h"
#include <mutex>
#include <thread> // Requis pour std::stop_token

class SensorManager {
private:
    DroneTelemetry m_telemetry; // Données privées (Encapsulation)
    std::mutex m_mutex;         // Verrou pour la synchronisation

public:
    SensorManager() = default;

    // Fonctions des capteurs qui s'exécuteront dans les jthreads
    void runIMU(std::stop_token stopToken);
    void runGPS(std::stop_token stopToken);
    void runLiDAR(std::stop_token stopToken);

    // Fonction thread-safe pour lire les données finales
    DroneTelemetry getTelemetry();
};

#endif

