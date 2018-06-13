#include "Enemy.h"

//Constructor and Destructor Definitions
C_Enemy::C_Enemy()
{

}

C_Enemy::~C_Enemy()
{
}

void C_Enemy::setInitialHealth(int health)
{
	m_health = health;
}

//Setter Definitions
void C_Enemy::setHealth(int damage)
{
	m_health -= damage;
}

void C_Enemy::setMoney(int money)
{
	m_money += money;
}

void C_Enemy::setDefense(int defense)
{
	m_defense = defense;
}

void C_Enemy::setAttack(int attack)
{
	m_offense = attack;
}

void C_Enemy::setName(string name)
{
	m_name = name;
}

void C_Enemy::setFile(string file)
{
	m_file = file;
}

//Main Getter Definitions
string C_Enemy::getName()
{
	return string(m_name);
}

string C_Enemy::getFile()
{
	return string(m_file);
}

int C_Enemy::getHealth()
{
	return m_health;
}

int C_Enemy::getDefense()
{
	return m_defense;
}

int C_Enemy::getOffense()
{
	return m_offense;
}

int C_Enemy::getMoney()
{
	return m_money;
}

//Secondary Getter Definitions
vector<string> C_Enemy::getMainName()
{
	return vector<string>(m_nameVector);
}

vector<string> C_Enemy::getMainFile()
{
	return vector<string>(m_fileVector);
}

vector<int> C_Enemy::getMaxHealth()
{
	return vector<int>(m_maxHealthVector);
}

vector<int> C_Enemy::getMinHealth()
{
	return vector<int>(m_minHealthVector);
}

vector<int> C_Enemy::getMaxDefense()
{
	return vector<int>(m_maxDefenseVector);
}

vector<int> C_Enemy::getMinDefense()
{
	return vector<int>(m_minDefenseVector);
}

vector<int> C_Enemy::getMaxOffense()
{
	return vector<int>(m_maxOffenseVector);
}

vector<int> C_Enemy::getMinOffense()
{
	return vector<int>(m_minOffenseVector);
}

vector<int> C_Enemy::getMaxMoney()
{
	return vector<int>(m_maxMoneyVector);
}

vector<int> C_Enemy::getMinMoney()
{
	return vector<int>(m_minMoneyVector);
}
