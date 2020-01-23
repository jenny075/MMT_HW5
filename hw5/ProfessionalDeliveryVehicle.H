#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy
#include <cmath>
#include "DeliveryVehicle.H"


class ProfessionalDeliveryVehicle : public DeliveryVehicle {
public:
	//c'tor
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~ProfessionalDeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
	bool addParcel(Parcel* parcel);

	int performDeliveryDay(int* numberOfDeliveries);
	
	


};

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
