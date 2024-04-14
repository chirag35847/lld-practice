#pragma once
#include "driverMatchingStrategy.hpp"
#include "tripmetadata.hpp"
#include "driverManager.hpp"
#include <iostream>

class LeastTimeDriverMatching : public DriverMatchingStrategy{
public:
    Driver* matchDriver(TripMetadata* tripMetadata){
        DriverManager* driverMgr = DriverManager::get();
        if((driverMgr->getDrivers()).size()==0){
            std::cout<<"No Drivers"<<std::endl;
            return nullptr;
        }

        Driver* driver = (driverMgr->getDrivers().begin())->second;
        tripMetadata->setDriverRating(driver->getRating());
        return driver;
    }
};