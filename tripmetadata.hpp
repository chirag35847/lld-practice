#pragma once
#include "rider.hpp"
#include "rider.hpp"
#include "location.hpp"

class TripMetadata{
    Location* startLoc;
    Location* destDoc;
    DRIVER_RATING driver_rating;
    RIDER_RATING rider_rating;
public:
    TripMetadata(Location* start, Location* dest,RIDER_RATING rider_rating){
        this->startLoc=start;
        this->destDoc=dest;
        this->rider_rating=rider_rating;
    }

    void setDriverRating(DRIVER_RATING driver_rating){
        this->driver_rating = driver_rating;
    }
};