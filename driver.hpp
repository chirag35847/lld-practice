#pragma once
#include "constants.hpp"

class Driver{
    DRIVER_STATUS status;
    DRIVER_RATING rating;
    std::string name;
public:
    Driver(std::string driverName){
        this->status=DRIVER_STATUS::OFF_DUTY;
        this->rating=DRIVER_RATING::ONE;
        this->name=driverName;
    }

    void updateDriverStatus(DRIVER_STATUS current_status){
        this->status=current_status;
    }

    DRIVER_RATING getRating(){
        return this->rating;
    }

    std::string getDriverName(){
        return this->name;
    }
};