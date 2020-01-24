#include "ProfessionalDeliveryCompany.H"


ProfessionalDeliveryCompany::ProfessionalDeliveryCompany(int money):DeliveryCompany(money){
}


bool ProfessionalDeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	if (vehicle->getType() == professional) {
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







