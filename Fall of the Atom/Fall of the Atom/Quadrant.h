#pragma once
#include <string>
#include <vector>

enum DIFFICULTY
{
	FREE,
	EASY,
	MEDM,
	HARD,
	MBSS,
	BOSS,
};

using namespace std;

class C_Quadrant
{
public:
	//Constructor and Destructor
	//Quadrant Input (Name, File, Colony, Difficulty, Value, XPosition, YPosition)
	C_Quadrant();
	~C_Quadrant();

public:
	//Main Setters
	void setName(string name);
	void setFile(string file);
	void setColony(string colony);
	void setMaxSeed(int mxSeed);
	void setMinSeed(int mnSeed);
	void setAmbushness(int probability);
	void setValue(int value);
	void setDifficulty(int level);

	//Main Getter
	string getName();
	string getColony();
	string getFile();
	int getMaxSeed();
	int getMinSeed();
	int getAmbushness();
	int getValue();

	//Parameter Data Vectors (Secondary Getters)
	vector<string> getMainName();
	vector<string> getMainColony();
	vector<string> getMainFile();
	vector<DIFFICULTY> getMainDifficulty();
	vector<int> getMainValue();

private:
	//Private Variables
	string m_name;
	string m_file;
	string m_colony;
	int m_maxseed;
	int m_minseed;
	int m_ambushness;
	int m_value;

	//Private Vectors
	vector<string> m_getNameVector{ "-ATANA METRO STATION-","2","3","4","-ARBTANIYA SUPPLY SHOP-","6","7","-CHURNIVNIY ATOMIC POWER CENTRAL-",
	"9","10","-GARVODNOSHT ARMOR & WEAPON STORE-","12","13","14","-HALL OF THE ATOM-","16",
	"-HJADYNIVITE ENERGY DEVELOPMENT COMPLEX-","18","19","20","-NADZHENIYE CENTRALNIY METRO STATION-","22","23","-TREASURY OF PRIBET-",
	"25","-PRIBET PALACE OF GOVERNMENT-","-ARBINTSKAYA FEDERAL BARRACKS-","28","29","30","31","32",
	"33","34","35","36","-MONUMENT TO THE KHAZNATANVIAN HEROES-","38","-PRIBET GARDEN RESTAURANT-","40",
	"-DARSHNAKOV METRO STATION-","42","-MUSEUM OF THE FALLEN-","44","45","46","47","48",
	"49","50","51","52","53","-TARNIBILSK METRO STATION-","55","56",
	"-TERNBELIY SLOTY CASINO-","58","59","-RAYUBINEV BIRYULKI PLAYHOUSE-","61","62","63","-GREAT PRIBET GATE-"};

	vector<string> m_getColonyVector{ "< Northwestern Garvodnosht Locality >","< Northern Garvodnosht Locality >","< Northeastern Garvodnosht Locality >","< Northwestern Arbtaniya Sector >","< Northeastern Arbtaniya Sector >","< Northwestern Churnivniyn Enclave >","< Northern Churnivniyn Enclave >","< Northeastern Churnivniyn Enclave >",
	"< Southwestern Garvodnosht Locality >","< Southern Garvodnosht Locality >","< Southeastern Garvodnosht Locality >","< Western Arbtaniya Sector >","< Eastern Arbtaniya Sector >","< Western Churnivniyn Enclave >","< Central Churnivniyn Enclave >","< Eastern Churnivniyn Enclave >",
	"< Northwestern Federatskaya District >","< Northern Federatskaya District >","< Northeastern Federatskaya District >","< Southwestern Arbtaniya Sector >","< Southeastern Arbtaniya Sector >","< Southwestern Churnivniyn Enclave >","< Southern Churnivniyn Enclave >","< Southeastern Churnivniyn Enclave >",
	"< Western Federatskaya District >","< Central Federatskaya District >","< Eastern Federatskaya District >","< Northwestern Centralniyn Quadrant >","< Northeastern Centralniyn Quadrant >","< Northwestern Pribet Garden Neighboorhood >","< Northern Pribet Garden Neighboorhood >","< Northeastern Pribet Garden Neighboorhood >",
	"< Southwestern Federatskaya District >","< Southern Federatskaya District >","< Southeastern Federatskaya District >","< Southwestern Centralniyn Quadrant >","< Southeastern Centralniyn Quadrant >","< Southwestern Pribet Garden Neighborhood >","< Southern Pribet Garden Neighborhood >","< Southeastern Pribet Garden Neighborhood >",
	"< Northwestern Ternbeliy Region >","< Northern Ternbeliy Region >","< Northeastern Ternbeliy Region >","< Northwestern Rayubinev Territory >","< Northeastern Rayubinev Territory >","< Northwestern Matkrubiyn Commune >","< Northern Matkrubiyn Commune >","< Northeastern Matkrubiyn Commune >",
	"< Western Ternbeliy Region >","< Central Ternbeliy Region >","< Eastern Ternbeliy Region >","< Western Rayubinev Territory >","< Eastern Rayubinev Territory >","< Western Matkrubiyn Commune >","< Central Matkrubiyn Commune >","< Eastern Matkrubiyn Commune >",
	"< Southwestern Ternbeliy Region >","< Southern Ternbeliy Region >","< Southeastern Ternbeliy Region >","< Southwestern Rayubinev Territory >","< Southeastern Rayubinev Territory >","< Southwestern Matkrubiyn Commune >","< Southern Matkrubiyn Commune >","< Southeastern Matkrubiyn Commune >"};
	
	vector<string> m_getFileVector{"station.gaf","2","3","4","shop.gaf","6","7","plant.gaf",
	"9","10","store.gaf","12","13","14","hall.gaf","16",
	"complex.gaf","18","19","20","station.gaf","22","23","treasury.gaf",
	"25","palace.gaf","barracks.gaf","28","29","30","31","32",
	"33","34","35","36","monument.gaf","38","restaurant.gaf","40",
	"station.gaf","42","museum.gaf","44","45","46","47","48",
	"49","50","51","52","53","station.gaf","55","56",
	"casino.gaf","58","59","place.gaf","61","62","63","entrance.gaf"};

	vector<DIFFICULTY> m_getDifficultyVector{FREE, EASY, FREE, MEDM, FREE, HARD, HARD, HARD,
										   MEDM, MEDM, MEDM, MEDM, HARD, HARD, BOSS, HARD,
										   HARD, HARD, HARD, HARD, FREE, HARD, HARD, HARD,
										   HARD, MBSS, HARD, HARD, MEDM, MEDM, MEDM, MEDM,
										   HARD, HARD, HARD, MEDM, MEDM, MEDM, FREE, EASY,
										   FREE, MEDM, MEDM, MEDM ,EASY ,EASY ,EASY ,EASY,
										   MEDM, MEDM, EASY, EASY, EASY, FREE, EASY, EASY,
										   FREE, EASY, EASY, FREE, EASY, EASY, EASY, FREE};

	vector<int> m_getValueVector{1, 2, 3, 4, 5, 6, 7, 8,
								9, 10, 11, 12, 13, 14, 15, 16, 
								17, 18, 19, 20, 21, 22, 23, 24,
								25, 26, 27, 28, 29, 30, 31, 32,
								33, 34, 35, 36, 37, 38, 39, 40,
								41, 42, 43, 44, 45, 46, 47, 48,
								49, 50, 51, 52, 53, 54, 55, 56,
								57, 58, 59, 60, 61, 62, 63, 64};
};

