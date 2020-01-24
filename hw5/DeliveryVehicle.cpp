#include "DeliveryVehicle.H"
using namespace std;

//c'tor of the class - DeliveryVehicle 
DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality) {
	ID_ = new char[strlen(ID) + 1];
	strcpy(ID_, ID);
	quality_ = quality;
	count_ = 0;
	stopStation_ = 0;
	parcels_ = new queue <Parcel*>() ;
	type_ = general;

}

//returns the ID_ member
char* DeliveryVehicle::getID() const {
	return ID_;
}

//returns the quality_ member
Quality DeliveryVehicle::getQuality() const {
	return quality_;
}


//returns the count_ member
int DeliveryVehicle::getCount() const {
	return count_;
}

//returns the stopStation_ member
int DeliveryVehicle::getStopStation() const {
	return stopStation_;
}

//chanching the value of the memeber stopStation_ to stopping_at
void DeliveryVehicle::setStopstation(int stopping_at)  {
	stopStation_= stopping_at;
}

// Adding parcel to member parcels_
// If successed return else  return false
bool DeliveryVehicle::addParcel(Parcel* parcel) {
	int i = 0;
	if (getCount() >= MAX_PARCELS)
		return false;
	else {
		Parcel* temp_p;
		for (i = 0; i < (int)parcels_->size(); i++) {
			temp_p = parcels_->front();

			if (parcel == temp_p) {
				return false;
			}
			parcels_->pop();
			parcels_->push(temp_p);
		}
		parcels_->push(parcel);
		count_++;
		return true;
	}
		


}
// preform all the deliveries per one day.
// Retuening the total revenue and changing the value of the *numberOfDeliveries to the amount deliverd 
int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries) {
	int tot=0;
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
		cout << "Delivering parcel " << parcels_->front()->getID() << " to position "<< parcels_->front()->getDest() << endl;
		setStopstation(parcels_->front()->getDest());
		ind++;
		cout << "Fuel consumed : " << way << " Revenue is : " << PACKAGE_RATE << endl;
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
	revenue = ind * PACKAGE_RATE - tot - getQuality();
	cout << "Total revenue is " << revenue << endl;
	return revenue;
}

//returns the type_ member
VehicelType DeliveryVehicle::getType()  { //Yan
	return type_;
}


//D'tor of the class DeliveryVehicle
DeliveryVehicle::~DeliveryVehicle() {
	delete[] ID_;
	while (!parcels_->empty()) {
		parcels_->pop();

	}

}