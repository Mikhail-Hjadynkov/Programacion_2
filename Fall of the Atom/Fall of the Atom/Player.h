#pragma once
#include "BaseStats.h"

//Weapon Info Structure
//Weapon Input (Name, Ammo, Type, Key, Price, Cost, Supply, Id, Loss, MaxDamage, MinDamage, Obtained)
struct S_Weapon
{
	string m_name = "none", m_ammo = "none", m_type = "none", m_key = "none";
	unsigned int m_price, m_cost, m_supply = 0, m_id = 0, m_loss = 0, m_maxdmg = 0, m_mindmg = 0;
	bool m_obtained;
};

//Garment Info Structure
//Garment Input (Name, Key, Type, Ability, Price, Defense, Id, Obtained)
struct S_Garment
{
	string m_name = "none", m_key = "none", m_type = "none", m_ability = "none";
	unsigned int m_price=0, m_defense = 0, m_id = 0;
	bool m_obtained;
};

//Food Info Structure
//Food Input (Name, Key, Nutrition, Price, Id, Quantity)
struct S_Food
{
	string m_name = "none", m_key = "none";
	unsigned int m_nutrition = 0, m_price = 0, m_id = 0, m_quantity;
};

class C_Player : public C_BaseStats
{
public:
	//Constructors and Destructors
	C_Player();
	
	~C_Player();

public:
	//Main Setters
	void setHealth(int damage);
	void setInitialHealth(int health);
	void setMoney(int money);
	void setInitialMoney(int money);
	void setAvoidness(int avoidness);
	void setHeadDefense(int headDefense);
	void setBodyDefense(int bodyDefense);
	void setBonusDefense(int headDefense, int bodyDefense, float percentage);
	void setDefense(int headDefense, int bodyDefense, int bonusDefense);
	void setAttack(int attack);
	void setName();
	void setInitialName(string name);
	void setWeaponry();
	void setGarmentry();
	void setGroceries();
	void setXPosition(int X);
	void setYPosition(int Y);
	void setXPositionMovement(int X);
	void setYPositionMovement(int Y);
	void setBobbykey(int bobbykey);
	void setInitialBobbykey(int bobbykey);
	void setPowdrive(int powdrive);
	void setInitialPowdrive(int powdrive);
	void setVictory(bool state);
	void setCommand();
	void setHeadgear(string headgear);
	void setBodygear(string bodygear);
	void setObtainedWeapon(int index);
	void setObtainedGarment(int index);
	void setAmmoQuantity(int index, int addition);
	void setFoodQuantity(int index, int addition);

	//BattleTime Variables
	void setCurrentTurn();
	void setActionTrigger();
	void setWeaponId(int weaponId);
	bool setWeaponUsage();

	//Main Getters
	int getAvoidness();
	int getXPosition();
	int getYPosition();
	int getBobbykey();
	int getPowdrive();
	int getHeadDefense();
	int getBodyDefense();
	int getBonusDefense();
	string getHeadgear();
	string getBodygear();
	vector<S_Food> getFood();
	vector<S_Weapon> getWeapon();
	vector<S_Garment> getGarment();
	vector<string> getCommandline();
	bool getVictory();

	//Battletime Getters
	int getWeaponId();
	bool getCurrentTurn();
	bool getActionTrigger();

public:
	//Player Actions
	void getInventory();
	void getFeed(string food);
	void getEquipped(string gear);
	void getGoing(string direction);

private:
	//Private Variables
	string m_headgear;
	string m_bodygear;
	string m_command;
	int m_avoidness;
	int m_headDefense;
	int m_bodyDefense;
	int m_bonusDefense;
	int m_bobbykey;
	int m_powdrive;
	int m_positionX;
	int m_positionY;
	bool m_victory;
	
	//Private BattleTime Variables
	bool m_currentTurn;
	bool m_actionTrigger;
	int m_weaponId;

	//Private Vectors
	vector<S_Weapon> m_weaponry;
	vector<S_Garment> m_garmentry;
	vector<S_Food> m_groceries;
	vector<string> m_commandline;
};

