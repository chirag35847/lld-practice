#pragma once
#include "tripmetadata.hpp"
#include "driver.hpp"

class DriverMatchingStrategy{
    public:
    virtual Driver* matchDriver(TripMetadata* tripMetadata)=0;
};