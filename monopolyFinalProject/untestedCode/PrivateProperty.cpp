#include "PrivateProperty.h"
#include <cstring>
using namespace std;
//CONSTRUCTORS

PrivateProperty::PrivateProperty() :Property() {
	houseCount = 0;
	hotelCount = 0;
	shopCount = 0;
	hasWifi = 0;
	hasGas = 0;
	hasElectricity = 0;
}
PrivateProperty::PrivateProperty(char* spaceType, int* playersOnSpace, int playersOnSpaceCount, char* propertyName, char* propertyGroup, int propertyID, int ownnerID, bool mortgaged, int purchasePrice, int rentPrice, int mortgagedPrice, int houseCount, int hotelCount, int shopCount, bool hasWifi, bool hasGas, bool hasElectricity)
{
	Property::setSpaceType(spaceType);
	Property::setPlayersOnSpace(playersOnSpace, playersOnSpaceCount);
	Property::setPlayersOnSpaceCount(playersOnSpaceCount);
	Property::setPropertyName(propertyName);
	Property::setPropertyGroup(propertyGroup);
	Property::setMortgaged(mortgaged);
	Property::setPropertyID(propertyID);
	Property::setOwnerID(ownnerID);
	Property::setPropertyID(propertyID);
	Property::setOwnerID(ownnerID);
	Property::setPurchasePrice(purchasePrice);
	Property::setRentPrice(rentPrice);
	Property::setMortgagePrice(mortgagedPrice);
	this->houseCount = houseCount;
	this->hotelCount = hotelCount;
	this->shopCount = shopCount;
	this->hasWifi = hasWifi;
	this->hasGas = hasGas;
	this->hasElectricity = hasElectricity;
}
PrivateProperty::PrivateProperty(PrivateProperty& PriPro) {

	this->houseCount = PriPro.getHouseCount();
	this->hotelCount = PriPro.getHotelCount();
	this->shopCount = PriPro.getShopCount();
	this->hasWifi = PriPro.getHasWifi();
	this->hasGas = PriPro.getHasGas();
	this->hasElectricity = PriPro.getHasElectricity();

	this->setSpaceType(PriPro.getSpaceType());
	this->setPlayersOnSpace(PriPro.getPlayersOnSpace(), PriPro.getPlayersOnSpaceCount());
	this->setPlayersOnSpaceCount(PriPro.getPlayersOnSpaceCount());
	this->setPropertyName(PriPro.getPropertyName());
	this->setPropertyGroup(PriPro.getPropertyGroup());
	this->setPropertyID(PriPro.getPropertyID());
	this->setOwnerID(PriPro.getOwnerID());
	this->setMortgaged(PriPro.getMortgaged());
	this->setPurchasePrice(PriPro.getPurchasePrice());
	this->setRentPrice(PriPro.getRentPrice());
	this->setMortgagePrice(PriPro.getMortgagePrice());
}
//SETTERS
void PrivateProperty::setHouseCount(int houseCount) {
	this->houseCount = houseCount;
}
void PrivateProperty::setHotelCount(int hotelCount) {
	this->hotelCount = hotelCount;
}
void PrivateProperty::setShopCount(int shopCount) {
	this->shopCount = shopCount;
}
void PrivateProperty::setHasWifi(bool hasWifi) {
	this->hasWifi = hasWifi;
}
void PrivateProperty::setHasGas(bool hasWifi) {
	this->hasGas = hasGas;
}
void PrivateProperty::setHasElectricity(bool) {
	this->hasElectricity = hasElectricity;
}
//GETTERS
int PrivateProperty::getHouseCount() {
	return houseCount;
}
int PrivateProperty::getHotelCount() {
	return hotelCount;
}
int PrivateProperty::getShopCount() {
	return shopCount;
}
bool PrivateProperty::getHasWifi() {
	return hasWifi;
}
bool PrivateProperty::getHasGas() {
	return hasGas;
}
bool PrivateProperty::getHasElectricity() {
	return hasElectricity;
}
//SPECIAL FUNCITONS
void PrivateProperty::addHouse() {
	houseCount++;
}
void PrivateProperty::addHotel() {
	hotelCount++;
}
void PrivateProperty::addShop() {
	shopCount++;
}
void PrivateProperty::addWifi() {
	hasWifi = true;
}
void PrivateProperty::addGas() {
	hasGas = true;
}
void PrivateProperty::addElectricity() {
	hasElectricity = true;
}
int PrivateProperty::calculateRent() {
	int newRentPrice = 0;
	newRentPrice = (((getRentPrice() * 0.3) * houseCount) + ((getRentPrice() * 0.8) * hotelCount) + ((getRentPrice() * 0.6) * shopCount) + getRentPrice());
	if (hasWifi == true) {
		newRentPrice = newRentPrice + ((getRentPrice() * 0.1));
	}
	if (hasGas == true) {
		newRentPrice = newRentPrice + ((getRentPrice() * 0.2));
	}
	if (hasElectricity == true) {
		newRentPrice = newRentPrice + ((getRentPrice() * 0.2));
	}
	return newRentPrice;
}
//DESTRUCTOR
PrivateProperty::~PrivateProperty() {
	houseCount = 0;
	hotelCount = 0;
	shopCount = 0;
	hasWifi = 0;
	hasGas = 0;
	hasElectricity = 0;
}