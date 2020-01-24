#include "DeliveryVehicleList.H"



listItem::listItem(DeliveryVehicle* item) {
	item_     = item;
	back_ = NULL;
	next_ = NULL;
	
}


void* listItem::item() {
	return item_;
}


listItem* listItem::next() {
	return next_;
}

void listItem::nextSet(listItem* next) {
	next_ = next;
}


listItem* listItem::back() {
	return back_;
}

void listItem::backSet(listItem* back) {
	back_ = back;
}


listItem::~listItem() {
	delete item_;
}




DeliveryVehicleList::DeliveryVehicleList() {
	list_ = NULL;
	curr_ = NULL;
}


void DeliveryVehicleList::addVehicle(DeliveryVehicle* newDV) {
	listItem* curr = list_;
	if (curr == NULL) {
		list_ = new listItem(newDV);
		curr_ = list_;
	}
	else {
		listItem* newitem = new listItem(newDV);
		curr->backSet(newitem);
		newitem->nextSet(curr);
	}
}


bool DeliveryVehicleList::isIn(char* id) {
	if (list_ == NULL) {
		return false;
	}
	listItem* curr = list_;
	if (curr != NULL) {
		if (strcmp(((DeliveryVehicle*)(list_->item()))->getID(), id) == 0) {
			return true;
		}
	}
	while (curr->next() != NULL) {
		if (strcmp(((DeliveryVehicle*)(curr->next()->item()))->getID(), id)==0){
			return true;
		}
	}
	return false;
}


DeliveryVehicle* DeliveryVehicleList::iter() {
	if (curr_ != NULL) {
		DeliveryVehicle* ret = (DeliveryVehicle*)curr_->item();
		curr_ = curr_->next();
		if (curr_ == NULL) {
			curr_ = list_;
		}
		return ret;
	}
	return NULL;
}

void DeliveryVehicleList::itereset() {
	curr_ = list_;
}


DeliveryVehicleList::~DeliveryVehicleList(){
	curr_ = NULL;
	listItem* tmp = list_;
	list_ = list_->next();
	while (tmp != NULL) {
		delete tmp;
		tmp = list_;
		if (list_ != NULL) {
			list_ = list_->next();
		}
	}
}


void DeliveryVehicleList::reiter() {
	curr_ = curr_->back();
}

