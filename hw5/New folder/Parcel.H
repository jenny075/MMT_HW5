#ifndef PARCEL_H_
#define PARCEL_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy

class Parcel{
public:
	//c'tor	
	Parcel(const char* ID, int dest);
	char* getID() const;
	int getDest() const;
	
	//d'tor
	~Parcel();

protected:
	char* id_;
	int dest_;
};

#endif /* PARCEL_H_ */
