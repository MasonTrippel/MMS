
#include "mms.h"
#include <string>
#include <vector>




int MMS::inventorySize() {
	int i = static_cast<int>(adoptables.size());
	
	return i;
}


int MMS::inventorySizeByShots(bool has_shots) const {
	int numOfAnimals = 0;
	if (has_shots) {
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::hasShot()) {
				numOfAnimals++;
			}

		}
	}
	else {
		for (int i = 0; i < adoptables.size(); i++) {
			if (!adoptables[i]->Adoptable::hasShot()) {
				numOfAnimals++;
			}

		}
	}

	return numOfAnimals;
}

int MMS::inventorySizeByType(AdoptableType type) const {
	int numOfAnimals = 0;
	
	
	if (type == DOG) {
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::getType() == DOG) {
				numOfAnimals++;
			}

		}
	}
	else if(type == CAT) {
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::getType() == CAT) {
				numOfAnimals++;
			}

		}
	}
	else if (type == TURTLE) {
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::getType() == TURTLE) {
				numOfAnimals++;
			}

		}
	}
	else {
		numOfAnimals = static_cast<int>(adoptables.size());
	
	}

	return numOfAnimals;
}

int MMS::inventorySizeByRestrictions(bool has_restrictions) const {
	int numOfAnimals = 0;
	if (has_restrictions) {
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::getType() == TURTLE) {
				numOfAnimals++;
			}

		}
		return numOfAnimals;
	}
	else{
		for (int i = 0; i < adoptables.size(); i++) {
			if (adoptables[i]->Adoptable::getType() != TURTLE) {
				numOfAnimals++;
			}

		}
		return numOfAnimals;
	}



}


std::vector<std::string> MMS::animalsInInventory() const {
	std::vector<std::string> names;
	for (int i = 0; i < adoptables.size(); i++) {
		names.push_back(adoptables[i]->Adoptable::getFirstName() + " " + adoptables[i]->Adoptable::getLastName());	
	}
	return names;
}


