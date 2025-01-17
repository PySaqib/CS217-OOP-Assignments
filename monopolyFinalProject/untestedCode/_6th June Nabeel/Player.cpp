#include "Player.h"
//UPDATED ACCORDING TO NEW DATA MEMBERS
Player::Player()
{
	name = nullptr;
	playerid = 0;
	cash = 0;
	propertylist = nullptr;
	propertylistsize = 0;
	isInJail = false;
	hasJailRescueCard = 0;
	isbankrupt = false;
	playerPosition = 0;

}
Player::Player(const char* Name, int Playerid)
{
	int i = 0, f = 0, j = 0;
	for (int k = 0; Name[k] != '\0'; k++)
	{
		f++;
	}
	name = new char[f + 1];
	for (j = 0; j < f; j++)
	{
		name[j] = Name[j];

	}
	name[j] = '\0';
	playerid = Playerid;
	cash = 5000;
	propertylist = nullptr;
	propertylistsize = 0;
	isInJail = false;
	hasJailRescueCard = 0;
	isbankrupt = false;
	playerPosition = 0;

}

Player::Player(const Player& p)
{
	int i = 0, f = 0, j = 0;
	for (int k = 0; p.name[k] != '\0'; k++)
	{
		f++;
	}
	name = new char[f + 1];
	for (j = 0; j < f; j++)
	{
		name[j] = p.name[j];

	}
	name[j] = '\0';
	playerid = p.playerid;
	cash = p.cash;
	propertylist = p.propertylist;
	propertylistsize = p.propertylistsize;
	isInJail = p.isInJail;
	hasJailRescueCard = p.hasJailRescueCard;
	isbankrupt = p.isbankrupt;
	playerPosition = p.playerPosition;
}

void Player::addCash(int amount)
{
	cash += amount;
}
void Player::deductCash(int amount)
{

	cash -= amount;

}
void Player::addProperty(Property* id)
{
	int i = 0;
	Property** newpropertylist = new Property * [propertylistsize + 1];
	for (int i = 0; i < propertylistsize + 1; i++) {
		newpropertylist[i] = new Property;
	}

	for (i = 0; i < propertylistsize; i++)
	{
		newpropertylist[i] = propertylist[i];

	}
	newpropertylist[i] = id;
	propertylistsize++;
	propertylist = newpropertylist;
}
void Player::removeProperty(Property* id)
{
	int i = 0, j;
	Property** newpropertylist = new Property * [propertylistsize - 1];
	for (int i = 0; i < propertylistsize - 1; i++) {
		newpropertylist[i] = new Property;
	}
	for (i = 0, j = 0; i < propertylistsize; i++)
	{
		if (propertylist[i]->getPropertyID() != id->getPropertyID())
		{
			newpropertylist[j] = propertylist[i];
			j++;
		}
	}
	propertylistsize--;
	propertylist = newpropertylist;
}

int Player::getCash()
{
	return cash;
}

int Player::getPropertyListSize()
{
	return propertylistsize;
}

int Player::getPlayerID()
{
	return playerid;
}

char* Player::getName()
{
	return name;
}

bool Player::getIsBankrupt()
{
	return isbankrupt;
}

int Player::getHasJailRescueCard()
{
	return hasJailRescueCard;
}


bool Player::getIsInJail()
{
	return isInJail;
}
void Player::setCash(int amount)
{
	cash = amount;
}
void Player::setPropertyListSize(int size)
{
	propertylistsize = size;
}

void Player::setPropertyList(Property** amount,int size)
{

	propertylist = new Property * [size];
	for (int i = 0; i < size; i++) {
		propertylist[i] = new Property;
	}
	for (int i = 0; i < size; i++) {
		propertylist[i] = amount[i];
	}
	propertylistsize = size;

}

void Player::setPlayerID(int id)
{
	playerid = id;
}

void Player::setName(char* Name)
{
	int i = 0, f = 0, j = 0;
	for (int k = 0; Name[k] != '\0'; k++)
	{
		f++;
	}
	name = new char[f + 1];
	for (j = 0; j < f; j++)
	{
		name[j] = Name[j];

	}
	name[j] = '\0';
}
void Player::setIsInJail(bool a)
{
	isInJail = a;
}
void Player::setIsBankrupt(bool a)
{
	isbankrupt = a;
}

void Player::setHasJailRescueCard(int a)
{
	hasJailRescueCard = a;
}

Property** Player::getPropertyList()
{
	return propertylist;
}

int Player::getPlayerPosition() {
	return playerPosition;
}
void Player::setPlayerPosition(int x) {
	playerPosition = x;
}


// Review

//  NEW FUNC(2):
void Player::atJail(Player& a) {

	// If players wants to pay fine ... 
	std::cout << "Do you want to pay fine?" << std::endl;
	char b[5];
	cin.getline(b, 20);
	if (strcmp(b, "yes") || (strcmp(b, "Yes"))) {
		a.deductCash(400);
	}
	if (strcmp(b, "no") || (strcmp(b, "No"))) {
		// JAIL RESCUE CARD WALLA ROOLA : 
		if (a.getHasJailRescueCard() > 0) {
			a.setPlayerPosition(11);
			a.hasJailRescueCard--;
		}
		a.inJailCount = 0;
		if (a.inJailCount < 2) {
			/*
			 Dice walla jo kaam krna ha Kar loo ....
			*/
			a.inJailCount++;
		}
	}

}

int Player::SoldPropertyPrice(int id) {
	bool found = false;
	int price = 0;
	for (int i = 0; i < propertylistsize && found == false; i++) {
		if (propertylist[i]->getPropertyID() == id) {
			found = true;
			price = propertylist[i]->getPurchasePrice();
		}
	}
	return price;
}
void Player::PropertyMortgaged(int id) {
	for (int i = 0; i < propertylistsize; i++) {
		if (propertylist[i]->getPropertyID() == id) {
			propertylist[i]->setMortgaged(true);
		}
	}
}
int Player::ReturnUpgradedPrice(int id) {
	for (int i = 0; i < propertylistsize; i++) {
		if (propertylist[i]->getPropertyID() == id) {
			return propertylist[i]->upgradedPrice();
		}
	}
}
bool Player::searchProperty(int id) {
	bool found = false;

	for (int i = 0; i < propertylistsize && found == false; i++) {
		if (propertylist[i]->getPropertyID() == id) {
			found = true;
		}
	}
	return found;
}

void Player::setIsInJailCount(int i) {
	inJailCount = i;
}
int Player::getIsInJailCount() {
	return inJailCount;
}