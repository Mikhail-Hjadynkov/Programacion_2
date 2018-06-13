#include "BaseStats.h"

C_BaseStats::C_BaseStats()
{
}

C_BaseStats::~C_BaseStats()
{
}

void C_BaseStats::setHealth()
{
}

void C_BaseStats::setDefense()
{
}

void C_BaseStats::setAttack()
{
}

void C_BaseStats::setMoney()
{
}

void C_BaseStats::setName()
{
}

int C_BaseStats::getHealth()
{
	return m_health;
}

int C_BaseStats::getMoney()
{
	return m_money;
}

int C_BaseStats::getDefense()
{
	return m_defense;
}

int C_BaseStats::getAttack()
{
	return m_offense;
}

string C_BaseStats::getName()
{
	return string(m_name);
}
