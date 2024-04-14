#pragma once
#include "driver.hpp"
#include "rider.hpp"
#include "location.hpp"
#include "pricingStrategy.hpp"
#include "driverMatchingStrategy.hpp"
#include<iostream>

class Trip{
    Rider* rider;
    Driver* driver;
    Location* startLoc;
    Location* destLoc;
    double price;
    int tripId;
    PricingStrategy* pricingStrategy;
    DriverMatchingStrategy* driverMatchingStrategy;
    TRIP_STATUS status;
public:
    Trip(Rider* rider, Driver* driver, Location* startLoc, Location* destLoc, double price, DriverMatchingStrategy* driverMatchingStg, PricingStrategy* pricingStg){
        this->status = TRIP_STATUS::ON_THE_WAY;
        this->rider = rider;
        this->driver = driver;
        this->destLoc = destLoc;
        this->startLoc = startLoc;
        this->price = price;
        this->pricingStrategy = pricingStg;
        this->driverMatchingStrategy = driverMatchingStg;
        this->tripId = nextTripId;
        nextTripId++;
    }
    
    int getTripId(){
        return this->tripId;
    }

    void displayTripDetails(){
        std::cout<<"Printing details for : "<<tripId<<std::endl;
    }
};