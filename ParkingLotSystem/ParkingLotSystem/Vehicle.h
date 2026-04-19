#pragma once

// pragma once is a preprocessor directive in C++ that tells the compiler to include a header file only once per compilation, 
// even if it’s referenced multiple times.

#include <string>
using namespace std;

enum class VehicleType {
	BIKE,
	CAR,
	TRUCK
};

class Vehicle
{
private:
	string vehicle_number;
	VehicleType type;

public:
	Vehicle(string vehicle_number, VehicleType type);

	VehicleType getType();
	string getVehicleNumber();
	void displayInfo();
	string vehicleTypeToString(VehicleType type);
};



