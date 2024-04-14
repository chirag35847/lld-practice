#pragma once
#include "mutex"
#include "rider.hpp"

class RiderManager{
    RiderManager(){}
    static RiderManager* riderManager;
    static std::mutex mtx;
    std::unordered_map<std::string,Rider*>riders;
    static int riderCount;
public:
    static RiderManager* get();
    void addRider(std::string riderName, Rider* rider);
    Rider* getRider(std::string);
};