#include "DeliveryCompany.H"

DeliveryCompany::DeliveryCompany(int money = 100) {
	int money_ = money;
	DeliveryVehicleList* DVList_ = new DeliveryVehicleList();
	int deliveryNum_ = 0;

}


bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	bool isIn = DVList_->isIn(vehicle->getID());
	if (isIn) {
		delete vehicle;
		return false;
	}
	DVList_->addVehicle(vehicle);
	return true;
}


bool DeliveryCompany::receiveParcel(Parcel* parcel) {
	//DVList_->itereset();
	DeliveryVehicle* DV = DVList_->iter();
	char* start = DV->getID();
	char* key = NULL;

	while (strcmp(key, start) != 0) {
		if (DV->addParcel(parcel)) {
			return true;
		}
		DV = DVList_->iter();
		key = DV->getID();
	}
	DVList_->reiter();
	delete parcel;
	return false;
}


bool DeliveryCompany::performDeliveryDay() {
	DeliveryVehicle* DV = DVList_->iter();
	char* start = DV->getID();
	char* key = NULL;
	int totalDeliveries = 0;
	int revenue;
	int totalRevenue;
	int* delNum;
	cout << "Starting days deliveries:" << endl;

	while (strcmp(key, start) != 0) {
		*delNum = 0;
		DV = DVList_->iter();
		revenue = DV->performDeliveryDay(delNum);
		totalDeliveries += *delNum;
		totalRevenue += revenue;
		key = DV->getID();
	}
	deliveryNum_ += totalDeliveries;
	cout << "Total revenue for company is " << totalRevenue << endl;
	money_ += totalRevenue;
	DVList_->reiter();
	if (totalDeliveries == 0) {
		return false;
	}
	return true;
}


void DeliveryCompany::displayFunds() {
	cout << "Company balance is now  " << money_;
}


void DeliveryCompany::displayNumberOfDeliveries() {
	cout << "Till now company has delivered " << deliveryNum_ << " parcels" << endl;
}


DeliveryCompany:~DeliveryCompany() {
	delete money_;
	delete DVList_;
	delete deliveryNum_;
}

