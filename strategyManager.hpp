#pragma once
#include "pricingStrategy.hpp"
#include "tripmetadata.hpp"
#include "driverMatchingStrategy.hpp"

class StrategyManager{
    StrategyManager(){}
    static StrategyManager* strategyManager;
    static std::mutex mtx;
public:
    static StrategyManager* get();
    PricingStrategy* getPricingStrategy(TripMetadata* tripMetadata);
    DriverMatchingStrategy* getDriverMatchingStrategy(TripMetadata* tripMetadata);
};