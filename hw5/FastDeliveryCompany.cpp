#include "FastDeliveryCompany.H"

FastDeliveryCompany::FastDeliveryCompany(int money = 100): DeliveryCompany(money) {
}


bool FastDeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	if (vehicle->getType() == fast) {
		delete vehicle;
		return false;
	}
	bool isIn = DVList_->isIn(vehicle->getID());
	if (isIn) {
		delete vehicle;
		return false;
	}
	DVList_->addVehicle(vehicle);
	return true;
}

FastDeliveryCompany::~FastDeliveryCompany() {

}



