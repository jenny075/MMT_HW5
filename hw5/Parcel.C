#include "Parcel.H"
#include <iostream> // cout, endl
#include <string.h> // strlen, strcpy

Parcel::Parcel(const char* ID, int dest) {
	dest_ = dest;
	id_ = new char[strlen(ID) + 1];
	strcpy(id_, ID);
}

Parcel::~Parcel() {
	delete[] id_;
}

