#pragma once

#include "pricingStrategy.hpp"

class DefaultPricingStrategy : public PricingStrategy{
    public:
    double calculatePrice(TripMetadata* tripmetadata){
        return 100;
    }
};