#pragma once
#include"Vehicle.h"

enum class ParkingSpotType {
	BIKE, 
	CAR,
	TRUCK
};

class ParkingSpot
{
private:
	int spotNum;
	bool available;
	ParkingSpotType type;
	Vehicle* v;

public:
	ParkingSpot(int spotNum, ParkingSpotType type);

	bool isAvailable();

	void removeVehicle();
	bool parkVehicle(Vehicle* v);
	bool canFitVehicle(Vehicle* v);
	void displayInfo();
};

