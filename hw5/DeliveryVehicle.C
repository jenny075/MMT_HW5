#include "DeliveryVehicle.H"

DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality) {
	ID_ = new char[strlen(ID) + 1];
	strcpy(ID_, ID);
	quality_ = quality;
	count_ = 0;
	stopStation_ = 0;
	queue<*Parcel> parcels_(MAX_PARCELS);

}



