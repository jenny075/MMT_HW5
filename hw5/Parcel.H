#ifndef PARCEL_H_
#define PARCEL_H_

class Parcel{
public:
	//c'tor	
	Parcel(const char* ID, int dest);
	
	//d'tor
	~Parcel();
protected:
	char* id_;
	int dest_;
};

#endif /* PARCEL_H_ */
