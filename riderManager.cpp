#include "riderManager.hpp"

RiderManager* RiderManager::riderManager = nullptr;
std::mutex RiderManager::mtx;

RiderManager* RiderManager::get(){
    if(riderManager==nullptr){
        mtx.lock();
        if(riderManager==nullptr){
            riderManager = new RiderManager();
        }
        mtx.unlock();
    }
    return riderManager;
}

void RiderManager::addRider(std::string riderName, Rider* rider){
    riders[riderName] = rider;
}

Rider* RiderManager::getRider(std::string riderName){
    return riders[riderName];
}