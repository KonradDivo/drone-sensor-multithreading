#include "SensorManager.h"
#include <iostream>
#include <chrono>

void SensorManager::runIMU(std::stop_token stopToken) {
    while (!stopToken.stop_requested()) { // Boucle infinie propre tant qu'on ne demande pas l'arrêt
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> lock(m_mutex);
        m_telemetry.imu_pitch += 0.5;
        std::cout << "[CAPTEUR IMU] Pitch mis a jour : " << m_telemetry.imu_pitch << std::endl;
    }
}

void SensorManager::runGPS(std::stop_token stopToken) {
    while (!stopToken.stop_requested()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        std::lock_guard<std::mutex> lock(m_mutex);
        m_telemetry.latitude += 0.0001;
        m_telemetry.longitude += 0.0001;
        std::cout << "[CAPTEUR GPS] Position mise a jour : " << m_telemetry.latitude << ", " << m_telemetry.longitude << std::endl;
    }
}

void SensorManager::runLiDAR(std::stop_token stopToken) {
    while (!stopToken.stop_requested()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        std::lock_guard<std::mutex> lock(m_mutex);
        m_telemetry.altitude += 1.2;
        std::cout << "[CAPTEUR LiDAR] Altitude mise a jour : " << m_telemetry.altitude << "m" << std::endl;
    }
}

DroneTelemetry SensorManager::getTelemetry() {
    std::lock_guard<std::mutex> lock(m_mutex); // Lecture sécurisée
    return m_telemetry;
}

