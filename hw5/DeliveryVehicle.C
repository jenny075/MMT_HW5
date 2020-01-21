#include "DeliveryVehicle.H"

DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality) {
	ID_ = new char[strlen(ID) + 1];
	strcpy(ID_, ID);
	quality_ = quality;
	count_ = 0;
	stopStation_ = 0;
	queue<*Parcel> parcels_(MAX_PARCELS);

}
char* DeliveryVehicle::getID() const {
	return ID_;
}

Quality DeliveryVehicle::getQuality() const {
	return quality_;
}

int DeliveryVehicle::getCount() const {
	return count_;
}

int DeliveryVehicle::getStopStation() const {
	return stopStation_;
}

int DeliveryVehicle::setStopStation(int stopping_at)  {
	stopStation_= stopping_at;
}

bool DeliveryVehicle::addParcel(Parcel* parcel) {
	int i = 0;
	if (this.getCount() >= MAX_PARCELS)
		return false;
	else {
		for (i = 0; i < MAX_PARCELS; i++) {
			if (parcel == parcels_[i]) {
				parcel->~Parcel();
				return false;
			}
		}
		this.parcels_.push_back(parcel);
		this.count_++;
		return true
	}
		


}



