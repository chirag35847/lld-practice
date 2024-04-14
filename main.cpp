#include "tripManager.hpp"

int main() {

	std::cout<<"xeexexex\n";
	//---------------Creating Riders and Drivers--------------------------------
	Rider* keertiRider = new Rider("Keerti");
	std::cout<<"Created1\n";
	Rider* gauravRider = new Rider("Gaurav");
	RiderManager* riderMgr = RiderManager::get();
	riderMgr->addRider("keerti", keertiRider);
	riderMgr->addRider("gaurav", gauravRider);

	Driver* yogitaDriver = new Driver("Yogita");
	Driver* riddhiDriver = new Driver("Riddhi");
	DriverManager* driverMgr = DriverManager::get();
	driverMgr->addDriver("yogita", yogitaDriver);
	driverMgr->addDriver("riddhi", riddhiDriver);

	//These details in turn will be stored in database
	//-------------------------------------------------------------------------

	TripManager* tripMgr = TripManager::get();


	std::cout << std::endl << "Creating Trip for Keerti from location (10,10) to (30,30)" << std::endl;
	tripMgr->createTrip(keertiRider, new Location(10, 10), new Location(30, 30));

	std::cout << std::endl << "Creating Trip for Gaurav from location (200,200) to (500,500)" << std::endl;
	tripMgr->createTrip(gauravRider, new Location(200, 200), new Location(500, 500));


	//-------------------Display all the trips created--------------------------
	std::unordered_map<int, Trip*> tripsMap = tripMgr->getTrips();
	for (auto mapVal : tripsMap) {
		(mapVal.second)->displayTripDetails();
	}

	return 0;
}