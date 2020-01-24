#include "Parcel.H"
//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#pragma warning(disable:4996)


Parcel::Parcel(const char* ID, int dest) {
	dest_ = dest;
	id_ = new char[strlen(ID) + 1];
	strcpy(id_, ID);
}


char* Parcel::getID() const {
	return id_;
}

int Parcel::getDest() const {
	return dest_;
}

Parcel::~Parcel() {
	delete[] id_;
}

