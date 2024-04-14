#pragma once
#include "constants.hpp"

class Rider{
    RIDER_RATING rating;
    std::string name;
public:
    Rider(std::string riderName){
        this->rating=RIDER_RATING::ONE;
        this->name=riderName;
    }

    RIDER_RATING getRiderRating(){
        return this->rating;
    }
};