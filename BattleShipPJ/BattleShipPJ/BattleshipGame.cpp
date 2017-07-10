#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<list>
#include<string>
//#include<ctime>
using namespace std;


enum HitResult
{
	MISS,
	HIT,
	DESTROY
};

enum ShipType
{
	AIRCRAFT_CARRIER,
	BATTLE_SHIP,
	CRUISER,
	DESTROYER,
	SUBMARINE
};

//void InitDefaultShips(ShipType* myShips, int& size);
void Destroy(vector<ShipType>& myShips);
void PrintShip(ShipType shipType);

int main()
{
	HitResult hitResult;
	char inputCoordinate[3] = {0,};

	srand((unsigned int)time(NULL));
	
	vector<ShipType> myShips = { AIRCRAFT_CARRIER, BATTLE_SHIP, CRUISER, DESTROYER, DESTROYER, SUBMARINE, SUBMARINE };
	list<ShipType> myShipsList = { AIRCRAFT_CARRIER, BATTLE_SHIP, CRUISER, DESTROYER, DESTROYER, SUBMARINE, SUBMARINE };

	list<string> shiplist;
	shiplist.push_back("Aircraft");
	shiplist.push_back("Cruiser");
	shiplist.push_back("Battleship");
	shiplist.push_back("Destroyer");
	shiplist.push_back("Destroyer");
	shiplist.push_back("Submarine");
	shiplist.push_back("Submarine");

	while (!shiplist.empty())
	{
		cout << shiplist.size() << endl;
		
		
		int index = rand() % shiplist.size();
		list<string>::iterator it = shiplist.begin();
		list<string>::iterator itEnd = shiplist.end();
		int checkCount = 0;
		
		//mordern C++
		for (auto it = shiplist.begin(); it != shiplist.end(); ++it, ++checkCount )
		{
			if (checkCount == index)
			{
				cout << *it << endl;
				shiplist.erase(it);
				break;
			}
		}
		//88 C++
		/*for (; it != itEnd; ++it , ++checkCount)
		{
			if (checkCount == index)
			{
				cout << *it << endl;
				shiplist.erase(it);
				break;
			}
		}*/


	}






	while (myShipsList.size() != 0) {
		cin >> inputCoordinate;

		hitResult = DESTROY; //(HitResult)(rand() % 3);
		int num;

		switch (hitResult)
		{
		case MISS:
			printf("miss\n");

			break;

		case HIT:
			printf("Hit\n");
			break;

		case DESTROY:
			printf("Destroy: ");
			Destroy(myShips);
			break;

		default:
			printf("outofrange\n");
			break;
		}
	}
	
	return 0;
}

void Destroy(list<ShipType>& myShips) {
	int num = rand() % myShips.size();

	list<ShipType> ::iterator it;
	
	for (it = myShips.begin(); it!=myShips.end(); it++)
	{

	}
	

	//PrintShip(myShips[num]);
	
	cout << endl;
	
	//myShips.erase(myShips.begin() + num);

	for (int i = 0; i < myShips.size(); i++)
	{
		PrintShip(myShips[i]);
	}
	cout << endl;
}

void PrintShip(ShipType shipType) {
	switch (shipType)
	{
	case AIRCRAFT_CARRIER:
		cout << "AIRCRAFT_CARRIER ";
		break;
	case BATTLE_SHIP:
		cout << "BATTLE_SHIP ";
		break;
	case CRUISER:
		cout << "CRUISER ";
		break;
	case DESTROYER:
		cout << "DESTROYER ";
		break;
	case SUBMARINE:
		cout << "SUBMARINE ";
		break;
	default:
		cout << "PrintShip : WrongNumber(" << shipType << ")" << endl;
		break;
	}
}
