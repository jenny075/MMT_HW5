#include "DeliveryVehicleList.H"



listItem::listItem(void* item) {
	void* item_     = item;
	listItem* back_ = NULL;
	listItem* next_ = NULL;
	
}


listItem::item() {
	return item_;
}


listItem::next() {
	return next_;
}

listItem::nextSet(listItem* next) {
	return next_ = next;
}


listItem::back() {
	return back_;
}

listItem::backSet(listItem* back) {
	return back_ = back;
}


listItem::~listItem() {
	delete item_;
}




DeliveryVehicleList::DeliveryVehicleList() {
	void* list_     = NULL;
	listItem* curr_ = NULL;
}


DeliveryVehicleList::addVehicle(DeliveryVehicle* newDV) {
	listItem* curr = list_;
	if (curr == NULL) {
		listItem* list_ = listItem(newDV);
		curr_ = list_;
	}
	else {
		listItem* newitem = listItem(newDV);
		curr->backSet(newitem);
		newitem->nextSet(curr);
	}
}


DeliveryVehicleList::isIn(char* id) {
	itemList* curr = list_;
	if (curr != NULL) {
		if (strcmp(curr->item()->getID(), id) == 0) {
			return true;
		}
	}
	while (curr->next() != NULL) {
		if (strcmp(curr->next()->item()->getID(), id)==0){
			return true;
		}
	}
	return false;
}


DeliveryVehicleList::iter() {
	DeliveryVehicle* ret   = curr_->item();
	curr_ = curr_->next();
	if (curr_ == NULL) {
		curr_ = list_;
	}
	return ret
}

DeliveryVehicleList::itereset() {
	curr_ = list_;
}


DeliveryVehicleList::~DeliveryVehicleList() {
	curr_ = Null;
	listItem* tmp = list_;
	list_ = list_->next();
	while (tmp != NULL) {
		delete tmp;
		listItem* tmp = list_;
		list_ = list_->next();
	}
}


DeliveryVehicleList::reiter() {
	curr_ = curr_->back();
}


DeliveryVehicleList::Current() {
	return curr_;
}