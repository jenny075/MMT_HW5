#ifndef PARCEL_H_
#define PARCEL_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
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
