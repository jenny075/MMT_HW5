#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_

class ProfessionalDeliveryVehicle{
public:
	//c'tor
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~ProfessionalDeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	bool addParcel(Parcel* parcel);
	
	


};

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
