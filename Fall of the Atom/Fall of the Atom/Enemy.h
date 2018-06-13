#pragma once
#include "BaseStats.h"
class C_Enemy : public C_BaseStats
{
public:
	//Constructor and Destructor
	C_Enemy();
	~C_Enemy();

public:
	//Main Setters
	void setInitialHealth(int health);
	void setHealth(int damage);
	void setMoney(int money);
	void setDefense(int defense);
	void setAttack(int attack);
	void setName(string name);
	void setFile(string file);

	//Main Getters
	string getName();
	string getFile();
	int getHealth();
	int getDefense();
	int getOffense();
	int getMoney();

	//Parameter Data Vectors (Secondary Getters)
	vector<string> getMainName();
	vector<string> getMainFile();
	vector<int> getMaxHealth();
	vector<int> getMinHealth();
	vector<int> getMaxDefense();
	vector<int> getMinDefense();
	vector<int> getMaxOffense();
	vector<int> getMinOffense();
	vector<int> getMaxMoney();
	vector<int> getMinMoney();

private:
	//Private Variables
	string m_file;
	int m_maxHealth;
	int m_minHealth;
	int m_maxDefense;
	int m_minDefense;
	int m_maxOffense;
	int m_minOffense;
	int m_maxMoney;
	int m_minMoney;

	//Private Vectors
	vector<string> m_nameVector{ "SOLDIER OF THE PRIPNIY PATROL" , "PRIBET SQUADRON PRIVATE" ,"SERGEANT OF THE KORSHKOV FORCES" ,"CADET OF THE KHAZNATANVIAN ARMY" ,"HJADYNIVITE FEDERAL COMMANDANT" ,"-GENERAL BASHTANYM KRISHINKOV-" ,"-CAPTAIN TALBASHYN ARMESY-" };
	vector<string> m_fileVector{ "soldier_a.gaf","soldier_b.gaf" ,"soldier_c.gaf" ,"soldier_d.gaf" ,"soldier_e.gaf" ,"general.gaf" ,"captain.gaf" };
	vector<int> m_maxHealthVector{150, 250, 400, 650, 1000, 2500, 5000};
	vector<int> m_minHealthVector{100, 150, 250, 400, 650, 2500, 5000};
	vector<int> m_maxDefenseVector{20, 35, 55, 85, 120, 200, 500};
	vector<int> m_minDefenseVector{10, 20, 35, 55, 85, 200, 500};
	vector<int> m_maxOffenseVector{25, 50, 80, 120, 175, 300, 750};
	vector<int> m_minOffenseVector{15, 25, 50, 80, 120, 350, 750};
	vector<int> m_maxMoneyVector{50, 100, 250, 500, 1000, 2500, 5000};
	vector<int> m_minMoneyVector{25, 50, 100, 250, 500, 2500, 5000};
};

