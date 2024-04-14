#include "tripManager.hpp"
#include "strategyManager.hpp"
#include "rider.hpp"
#include "location.hpp"

TripManager* TripManager::tripManager=nullptr;
std::mutex TripManager::mtx;

TripManager* TripManager::get(){
    if(tripManager==nullptr){
        mtx.lock();
        if(tripManager==nullptr){
            tripManager = new TripManager();
        }
        mtx.unlock();
    }
    return tripManager;
}

void TripManager::createTrip(Rider* rider, Location*startLoc, Location*endLoc){
    TripMetadata* tripMetadata = new TripMetadata(startLoc, endLoc, rider->getRiderRating());
    StrategyManager* strategyManager = StrategyManager::get();
    PricingStrategy* pricingStrategy = strategyManager->getPricingStrategy(tripMetadata);
    DriverMatchingStrategy* driverMatchingStrategy = strategyManager->getDriverMatchingStrategy(tripMetadata);
    Driver* driver = driverMatchingStrategy->matchDriver(tripMetadata);
    double price = pricingStrategy->calculatePrice(tripMetadata);

    Trip* createdTrip = new Trip(rider,driver,startLoc,endLoc,price,driverMatchingStrategy,pricingStrategy);
    int tripId = createdTrip->getTripId();
    trips[tripId] = createdTrip;
    tripMetaInfo[tripId] = tripMetadata;
}

std::unordered_map<int,Trip*> TripManager::getTrips(){
    return trips;
}