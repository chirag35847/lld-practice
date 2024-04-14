#include "driverManager.hpp"
#include <mutex>

DriverManager* DriverManager::driverManager = nullptr;
std::mutex DriverManager::mtx;

DriverManager* DriverManager::get(){
    if(driverManager==nullptr){
        mtx.lock();
        if(driverManager==nullptr){
            driverManager = new DriverManager();
        }
        mtx.unlock();
    }
}

void DriverManager::addDriver(std::string driverName, Driver* driver){
    drivers[driverName] = driver;
}

std::unordered_map<std::string,Driver*> DriverManager::getDrivers(){
    return drivers;
}