#pragma once
#include "tripmetadata.hpp"

class PricingStrategy{
    public:
    virtual double calculatePrice(TripMetadata* tripMetadata)=0;
};