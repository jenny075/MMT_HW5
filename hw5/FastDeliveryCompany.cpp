#include "FastDeliveryCompany.H"

FastDeliveryCompany::FastDeliveryCompany(int money = 100) {
	int money_ = money;
	DeliveryVehicleList* DVList_ = DeliveryVehicleList();
	int deliveryNum_ = 0
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







