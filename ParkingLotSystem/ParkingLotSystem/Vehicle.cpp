#include "Vehicle.h"
#include<iostream>

Vehicle::Vehicle(string vehicle_number_, VehicleType type_) 
	: vehicle_number(vehicle_number_), type(type_) { }

VehicleType Vehicle::getType() {
	return type;
}

string Vehicle::getVehicleNumber() {
	return vehicle_number;
}

string Vehicle::vehicleTypeToString(VehicleType type) {
	switch (type) {
		case VehicleType::TRUCK : return "TRUCK";
		case VehicleType::BIKE: return "BIKE";
		case VehicleType::CAR: return "CAR";
	}
}

void Vehicle::displayInfo() {
	cout << "Vehicle Info : Type -> " + vehicleTypeToString(type) + ", Vehicle Number -> " + vehicle_number;
}