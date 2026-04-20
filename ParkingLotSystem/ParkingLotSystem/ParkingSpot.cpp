#include "ParkingSpot.h"

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

}