#include "Parcel.H"

Parcel::Parcel(const char* ID, int dest) {
	dest_ = dest;
	id_ = new char[strlen(ID) + 1];
	strcpy(id_, ID);
}


char* Parcel::getID() const {
	return id_;
}

char* Parcel::getDest() const {
	return dest_;
}

Parcel::~Parcel() {
	delete[] id_;
}

