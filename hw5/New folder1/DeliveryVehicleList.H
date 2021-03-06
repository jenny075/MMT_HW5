#ifndef DELIVERYVEHICLELIST_H_
#define DELIVERYVEHICLELIST_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy

#include "DeliveryVehicle.H"

class listItem {
protected:
	listItem* back_;
	listItem* next_;
	DeliveryVehicle* item_;

public:

	//c'tor
	listItem(DeliveryVehicle* item);

	DeliveryVehicle* item();

	listItem* next();
	listItem* back();
	void nextSet(listItem* next);
	void backSet(listItem* back);

	//d'tor
	~listItem();
};

class DeliveryVehicleList {
protected:
	listItem* list_;
	listItem* curr_;

public:

	//c'tor
	DeliveryVehicleList();

	//d'tor
	~DeliveryVehicleList();

	//adds parcel to vehicle returns false if add failed
	void addVehicle(DeliveryVehicle* newDV);

	// check if there's a vehicle with the same id in the list
	bool isIn(char* id);

	// iterate over the items in the list
	DeliveryVehicle* iter();

	//
	void reiter();

	// resets the iterator to the 1st item in the list.
	void itereset();
};
#endif /* FASTDELIVERYVEHICLE_H_ */