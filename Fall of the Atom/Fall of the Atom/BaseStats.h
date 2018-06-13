#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

class C_BaseStats
{
public:
	C_BaseStats();
	~C_BaseStats();

public:
	void setHealth();
	void setDefense();
	void setAttack();
	void setMoney();
	void setName();

	int getHealth();
	int getMoney();
	int getDefense();
	int getAttack();
	string getName();

protected:
	int m_health;
	int m_offense;
	int m_defense;
	int m_money;
	string m_name;
};

