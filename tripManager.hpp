#pragma once
#include "mutex"
#include "riderManager.hpp"
#include "driverManager.hpp"
#include "trip.hpp"

class TripManager{
    static TripManager* tripManager;
    static std::mutex mtx;
    TripManager(){
        riderManager = RiderManager::get();
        driverManager = DriverManager::get();
    }
    RiderManager* riderManager;
    DriverManager* driverManager;
    std::unordered_map<int,TripMetadata*> tripMetaInfo;
    std::unordered_map<int,Trip*> trips;
public:
    static TripManager* get();
    void createTrip(Rider* rider, Location* start, Location*end);
    std::unordered_map<int,Trip*> getTrips();
};