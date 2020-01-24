#include "DeliveryCompany.H"


DeliveryCompany::DeliveryCompany(int money) {
	money_ = money;
	DVList_ = new DeliveryVehicleList();
	deliveryNum_ = 0;

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
	char* key;
	do {
		if (DV->addParcel(parcel)) {
			return true;
		}
		DV = DVList_->iter();
		key = DV->getID();
	} while (strcmp(key, start) != 0);
	delete key;
	DVList_->reiter();
	delete parcel;
	return false;
}


bool DeliveryCompany::performDeliveryDay() {
	DeliveryVehicle* DV = DVList_->iter();
	if (DV == NULL) {
		return false;
	}
	char* start = DV->getID();
	char* key = NULL;
	int totalDeliveries = 0;
	int revenue = 0;
	int totalRevenue = 0;
	int delNum = 0;
	int* PdelNum = &delNum;
	cout << "Starting days deliveries:" << endl;

	do {
		delNum = 0;
		DV = DVList_->iter();
		revenue = DV->performDeliveryDay(PdelNum);
		totalDeliveries += delNum;
		totalRevenue += revenue;
		key = DV->getID();
	} while (strcmp(key, start) != 0);
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
	cout << "Company balance is now  " << money_<< endl;
}


void DeliveryCompany::displayNumberOfDeliveries() {
	cout << "Till now company has delivered " << deliveryNum_ << " parcels" << endl;
}


DeliveryCompany::~DeliveryCompany() {
	delete DVList_;
}

