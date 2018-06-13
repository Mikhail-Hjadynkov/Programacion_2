#pragma once
#include "enemy.h"
#include "player.h"
#include "quadrant.h"

enum TOKEN
{
	JEWEL = 1,
	LEAF,
	DOLL,
	CROWN,
	BALL,
};

enum LOADER
{
	NAME,
	POSITION_X,
	POSITION_Y,
	HEALTH,
	MONEY,
	BOBBYKEY,
	POWDRIVE,
	HEADGEAR,
	BODYGEAR,
	e_ATTANKASCHAKI,
	e_POSHKITCHI,
	e_VABRIKNILKI,
	e_BRIHTNIM,
	e_KOLDONODY,
	e_SHCHIRAMNIY,
	e_DAKINETSKAYA,
	e_TOGPALIYEV,
	e_RAYKUSTAYENI,
	e_LIDENKNIKH,
	e_BRIOSHK,
	AUTOMATIC_RIFLE,
	e_SHOTGUN,
	SUBMACHINE_GUN,
	e_BERHIRIYET,
	GRENADE_LAUNCHER,
	e_METATELNIYA,
	SONIC_REPEATER,
	SHOCKWAVE_EMITTER,
	LASER_PISTOL,
	e_DAGGER,
	e_TABANASHYN,
	e_SWORD,
	STABHAMMER,
	SAWEDSICKLE,
	ROUND,
	GAUGE,
	CALIBER,
	BEHNIT,
	GRENADE,
	SVAIKA,
	ARRAY,
	CORE,
	BATTERY,
	SOLDIER_HAT,
	POWER_HELMET,
	SHOCKTROOPER_FENDER,
	STEALTH_ARMET,
	GENERAL_CAP,
	SOLDIER_SUIT,
	POWER_ARMOR,
	ELECTRIFIED_EQUIPMENT,
	STEALTH_RIG,
	GENERAL_GARB,
	COMPUTER_UNLOCK,
	SERVER_UNLOCK,
	SYSTEM_UNLOCK,
	COMPUTER_BLOCK,
	SERVER_BLOCK,
	SYSTEM_BLOCK,
	DOOR_OPEN,
	GATE_OPEN,
	SAFE_OPEN,
	DOOR_BROKEN,
	GATE_BROKEN,
	SAFE_BROKEN,
	CORE_LIMIT,
};

enum WEAPONS
{
	RIFLE,
	SHOTGUN,
	SUBMACHINE,
	BERHIRIYET,
	LAUNCHER,
	METATELNIYA,
	REPEATER,
	EMITTER,
	PISTOL,
	DAGGER,
	TABANASHYN,
	SWORD,
	HAMMER,
	SICKLE,
};

enum GARMENT
{
	HAT,
	HELMET,
	FENDER,
	ARMET,
	CAP,
	SUIT,
	ARMOR,
	EQUIPMENT,
	RIG,
	GARB,
};

enum FOOD
{
	ATTANKASCHAKI,
	POSHKITCHI,
	VABRIKNILKI,
	BRIHTNIM,
	KOLDONODY,
	SHCHIRAMNIY,
	DAKINETSKAYA,
	TOGPALIYEV,
	RAYKUSTAYENI,
	LIDENKNIKH,
	BRIOSHK,
};

enum PRIZE_TYPE
{
	WEAPON,
	GARMENT,
	EVENT,
};

enum HACKABLES
{
	COMPUTER,
	SERVER,
	SYSTEM,
};

enum LOCKPICKABLES
{
	DOOR,
	GATE,
	SAFE,
};

enum ENEMIES
{
	SOLDIER,
	PRIVATE,
	SERGEANT,
	CADET,
	COMMANDANT,
	GENERAL,
	CAPTAIN,
};

//Lockpickable Info Structure
//Data Input (Name, Difficulty, Attempts, Keypins, Hits, Limit, Prize Number Id, Is Open, Is Broken)
struct S_Lockpickable
{
	string m_name = "none", m_difficulty = "none";
	unsigned int m_attempt = 0, m_keypin = 0, m_limit = 0, m_prize = 0, m_id = 0;
	bool m_open, m_broken;
};

//Hackables Info Structure
//Data Input (Name, Difficulty, Word, Password, Attempts, Possibilities, Limit, Prize Type, Id, Is Unlocked, Is Blocked)
struct S_Hackable
{
	string m_name = "none", m_difficulty = "none", m_word = "none", m_password = "none";
	unsigned int m_attempt = 0, m_possibilities = 0, m_limit = 0, m_type = 0, m_id = 0;
	bool m_unlocked, m_blocked;
};

//Map matrix
static int m_map[8][8]
{
	{ 0, 1, 2, 3, 4, 5, 6, 7},
	{ 8, 9,10,11,12,13,14,15},
	{16,17,18,19,20,21,22,23},
	{24,25,26,27,28,29,30,31},
	{32,33,34,35,36,37,38,39},
	{40,41,42,43,44,45,46,47},
	{48,49,50,51,52,53,54,55},
	{56,57,58,59,60,61,62,63},
};

class C_World
{
public:
	//Constructor and Destructor
	C_World();
	~C_World();

public:
	//Main Getters
	int getBattleValue();
	vector<string> getSaveFiles();

public:
	//Main Initializer
	void initializer();

public:
	//World Attributes
	void fileLoader(string file);
	void stop();
	void setSaveFiles();
	bool stob(string x);
	string btos(bool y);

public:
	//Gameplay Attributes
	void getLoader();
	void getSaver();
	void getHelp(string key);
	void getDescription(int quadrantValue);
	void getBattle(int index);
	void getConfrontation(string victim, int quadrantValue);
	void getEnemySelector(int maxSeed, int minSeed);
	void getSloty();
	void getBiryulki();
	void getStation(int quadrantValue);
	void getShop();
	void getShopPurchase(int index, int addition);
	void getStore();
	void getStorePurchase(int index, string type);
	void getRestaurant();
	void getRestaurantPurchase(int index, int addition);
	void getHackInitializer(string command, int quadrantValue);
	void getHacking(int index);
	void getLockpickInitializer(string command, int quadrantValue);
	void getLockpicking(int index);
	void getAttemptCounter(string function, int index);
	void getHackStates(string state, int index);
	void getLockpickStates(string state, int index);
	void getMap();

public:
	//Main Setters
	void setCore(string file);
	void setPlayer();
	void setEnemy(int key);
	void setQuadrant(int value);
	void setHackables();
	void setLockpickables();
	void setInitializer();
	void setExecuter();
	void setBattleValue(int value);

	//Main Getters
	C_Player getPlayer();
	C_Quadrant getQuadrant();
	C_Enemy getEnemy();
	vector<S_Lockpickable> getLockpickable();
	vector<S_Hackable> getHackable();
	vector<string> getCore();
	bool getInitializer();
	bool getExecuter();

private:
	//Private Variables
	int m_battleValue;

	//Initializer Variables
	bool m_initializer = false;
	bool m_executer = true;

	//Private Classes
	C_Player m_player;
	C_Enemy m_enemy;
	C_Quadrant m_quadrant;

	//Private Vectors
	vector<S_Lockpickable> m_lockpickable;
	vector<S_Hackable> m_hackable;
	vector<string> m_savefiles;
	vector<string> m_core;
};
