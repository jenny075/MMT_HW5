#include "ProfessionalDeliveryVehicle.H"

//C'tor of the calss ProfessionalDeliveryVehicle
ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {
	type_ = professional;

}

//Adds parcel to member parcels_
//If successed return true else false
bool ProfessionalDeliveryVehicle::addParcel(Parcel* parcel) {
	if (parcels_->empty()) {
		return  DeliveryVehicle::addParcel(parcel);
	}
	else {
		int way = (parcel->getDest())-(parcels_->back()->getDest());
		if (way <= PACKAGE_RATE && way > 0) {
			return  DeliveryVehicle::addParcel(parcel);
		}
		return false;
	}
}


int  ProfessionalDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries) {
	int tot = 0;
	int ind = 0;
	int revenue = 0;
	if (parcels_->empty()) {
		*numberOfDeliveries = 0;
		cout << "No parcels to deliver for vehicle " << getID() << endl;
		cout << "Revenue per distance : no distance" << endl;
		cout << "Revenue per parcel: no parcels" << endl;
		tot = 0;
		return tot;
	}
	//check if not empty first
	int way = 0;
	cout << "Starting deliveries for vehicle " << getID() << endl;

	way = parcels_->front()->getDest() - getStopStation();

	while (ind < 5 && tot + way <= 12) {
		tot = tot + way;
		cout << "Delivering parcel " << parcels_->front()->getID() << " to position " << parcels_->front()->getDest() << endl;
		setStopstation(parcels_->front()->getDest());
		ind++;
		cout << "Fuel consumed : " << way << " Revenue is : " << PACKAGE_RATE << endl;
		parcels_->pop();
		if (!parcels_->empty()) {
			way = parcels_->front()->getDest() - getStopStation();
		}
		else
			break;


	}
	*numberOfDeliveries = ind;
	cout << "Total travel distance is " << tot << endl;
	revenue = ind * PACKAGE_RATE - tot - getQuality();
	cout << "Total revenue is " << revenue << endl;
	int ave_parcel = revenue / ind;
	int ave_way = revenue / tot;
	cout<<"Revenue per distance: " << ave_way <<endl;
	cout<<"Revenue per parcel: " << ave_parcel <<endl;
	return revenue;
}

ProfessionalDeliveryVehicle::~ProfessionalDeliveryVehicle() {

}
