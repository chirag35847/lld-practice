#pragma once
#include "strategyManager.hpp"
#include "tripmetadata.hpp"
#include "defaultPricingStrategy.hpp"
#include "leastTimeBasedDriverMatching.hpp"

StrategyManager* StrategyManager::strategyManager=nullptr;
std::mutex StrategyManager::mtx;

StrategyManager* StrategyManager::get(){
    if(strategyManager==nullptr){
        mtx.lock();
        if(strategyManager==nullptr){
            strategyManager = new StrategyManager();
        }
        mtx.unlock();
    }
    return strategyManager;
}

PricingStrategy* StrategyManager::getPricingStrategy(TripMetadata* tripMetadata){
    return new DefaultPricingStrategy();
}

DriverMatchingStrategy* StrategyManager::getDriverMatchingStrategy(TripMetadata* tripmetadata){
    return new LeastTimeDriverMatching();
}