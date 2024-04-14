#pragma once
#include<string>
#include "driver.hpp"

class DriverManager{
    DriverManager(){}
    static DriverManager* driverManager;
    static std::mutex mtx;
    std::unordered_map<std::string,Driver*>drivers;
public:
    static DriverManager* get();
    void addDriver(std::string driverName, Driver* driver);
    std::unordered_map<std::string,Driver*> getDrivers();
}; 