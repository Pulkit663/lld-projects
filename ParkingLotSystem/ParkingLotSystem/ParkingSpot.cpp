#include "ParkingSpot.h"
#include <iostream>

ParkingSpot::ParkingSpot(int spotNumber, ParkingSpotType spotType)
	: spotNum(spotNumber), type(spotType), available(true), v(nullptr) { }

bool ParkingSpot::isAvailable() {
	return available;
}

bool ParkingSpot::canFitVehicle(Vehicle* v) {

	if (v == nullptr) return false;

	//nullptr → treated as false
	//valid pointer → treated as true
	// if(!v) return false;

	VehicleType t = v->getType();
	switch (t) {
	case VehicleType::BIKE: return true;
	case VehicleType::CAR: return type!= ParkingSpotType::BIKE;
	case VehicleType::TRUCK: return type == ParkingSpotType::TRUCK;
	}
	return false;
}

bool ParkingSpot::parkVehicle(Vehicle* vehicle) {

	if (!available || !canFitVehicle(vehicle)) return false;

	v = vehicle;
	available = false;
	return true;
}

void ParkingSpot::removeVehicle() {
	available = true;
	v = nullptr;
}

void ParkingSpot::displayInfo() {

	cout << "Spot Number : " + to_string(spotNum) + " which is a ";

	switch (type)
	{
	case ParkingSpotType::BIKE: cout << "BIKE SPOT"; break;
	case ParkingSpotType::TRUCK: cout << "TRUCK SPOT"; break;
	case ParkingSpotType::CAR: cout << "CAR SPOT"; break;
	}

	if (available)
		cout << " is not occupied ";
	else cout << " occupied ";

	if (v)
		v->displayInfo();
}