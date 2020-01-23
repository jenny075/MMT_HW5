#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy
#include "Parcel.H"
#include <queue>
#define MAX_PARCELS 5 
using namespace std;
typedef enum quality{good = 3, ok = 4, bad = 5} Quality;
typedef enum vehicelType { general = 0, fast = 1, professional = 2 } VehicelType;//Yan: jenny, see clue at the bottom of page 4

class DeliveryVehicle{
public:
	//c'tor
	DeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~DeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	bool addParcel(Parcel* parcel);
	
	//performs all possible deliveries for one day
	//output example
	//Starting deliveries for vehicle riksha
	//Delivering parcel hot_air to position 3
	//Fuel consumed: 3 Revenue is: 4
	//Delivering parcel mice to position 2
	//Fuel consumed: 9 Revenue is: 4
	//Total travel distance is 12
	//Total revenue is -7
	//
	//if no parcels present:
	//No parcels to deliver for vehicle riksha
	virtual int performDeliveryDay(int* numberOfDeliveries);
	char* getID() const;
	Quality getQuality() const;
	int getCount() const;
	int getStopStation() const;
	void setStopstation(int stopping_at);

	VehicelType getType(); //Yan

protected:
	char* ID_;
	Quality quality_;
	queue<*Parcel> parcels_(MAX_PARCELS);
	int count_;
	int stopStation_;
	
	static VehicelType type_; //Yan

};

#endif /* DELIVERYVEHICLE_H_ */
