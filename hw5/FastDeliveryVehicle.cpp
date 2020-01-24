#include "FastDeliveryVehicle.H"


//of the class - FastDeliveryVehicle
FastDeliveryVehicle::FastDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {
	type_ = fast;

}
// Adding parcel to member parcels_
// If successed return else  return false
bool  FastDeliveryVehicle::addParcel(Parcel* parcel) {
	return  DeliveryVehicle::addParcel(parcel);
}


// preform all the deliveries per one day.
// Retuening the total revenue and changing the value of the *numberOfDeliveries to the amount deliverd 
int FastDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries) {
	int tot = 0;
	int ind = 0;
	int revenue = 0;
	if (parcels_->empty()) {
		*numberOfDeliveries = 0;
		cout << "No parcels to deliver for vehicle " << getID() << endl;
		tot = 0;
		return tot;
	}
	//check if not empty first
	int way = 0;
	cout << "Starting deliveries for vehicle " << getID() << endl;
	if (parcels_->front()->getDest() >= getStopStation()) {
		way = parcels_->front()->getDest() - getStopStation();
	}
	else {
		way = (10 - getStopStation()) + parcels_->front()->getDest();
	}

	while (ind < 5 && tot + way <= 12) {
		tot = tot + way;
		cout << "Delivering parcel " << parcels_->front()->getID() << " to position " << parcels_->front()->getDest() << endl;
		setStopstation(parcels_->front()->getDest());
		ind++;
		cout << "Fuel consumed : " << way << " Revenue is : " << way*2 << endl;
		parcels_->pop();
		if (!parcels_->empty()) {
			if (parcels_->front()->getDest() >= getStopStation()) {
				way = parcels_->front()->getDest() - getStopStation();
			}
			else {
				way = (10 - getStopStation()) + parcels_->front()->getDest();
			}
		}
		else
			break;


	}
	*numberOfDeliveries = ind;
	cout << "Total travel distance is " << tot << endl;
	revenue =  tot - getQuality();
	cout << "Total revenue is " << revenue << endl;
	return revenue;
}
//D'tor
FastDeliveryVehicle::~FastDeliveryVehicle() {
	
}


