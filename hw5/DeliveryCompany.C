#include "DeliveryCompany.H"

DeliveryCompany::DeliveryCompany(int money = 100) {
	int money_ = money;
	DeliveryVehicleList* DVList_ = DeliveryVehicleList();
	int deliveryNum_ = 0
}


bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle){
	bool isIn = DVList_->isIn(vehicle->getID());
	if (isIn) {
		delete vehicle;
		return false;
	}
	DVList_->addVehicle(vehicle);
	return true;
}


bool DeliveryCompany::receiveParcel(Parcel* parcel) {
	DVList_->itereset();
	DeliveryVehicle* DV = DVList_->iter();
	char* start = DV->getID();
	addParcel
	while 


}


bool performDeliveryDay() {

}


void displayFunds() {
	
}


void displayNumberOfDeliveries() {
	
}




