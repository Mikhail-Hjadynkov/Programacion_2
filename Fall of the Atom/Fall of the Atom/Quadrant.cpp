#include "Quadrant.h"

//Constructor and Destructor Definitions
C_Quadrant::C_Quadrant()
{
}

C_Quadrant::~C_Quadrant()
{
}

//Setter Definitions
void C_Quadrant::setName(string name)
{
	m_name = name;
}

void C_Quadrant::setFile(string file)
{
	m_file = file;
}

void C_Quadrant::setColony(string colony)
{
	m_colony = colony;
}

void C_Quadrant::setMaxSeed(int mxSeed)
{
	m_maxseed = mxSeed;
}

void C_Quadrant::setMinSeed(int mnSeed)
{
	m_minseed = mnSeed;
}

void C_Quadrant::setAmbushness(int probability)
{
	m_ambushness = probability;
}

void C_Quadrant::setValue(int value)
{
	m_value = value;
}

void C_Quadrant::setDifficulty(int level)
{
	switch (level)
	{
	case FREE:
		setMaxSeed(0);
		setMinSeed(0);
		setAmbushness(0);
		break;

	case EASY:
		setMaxSeed(120);
		setMinSeed(1);
		setAmbushness(25);
		break;

	case MEDM:
		setMaxSeed(140);
		setMinSeed(50);
		setAmbushness(50);
		break;

	case HARD:
		setMaxSeed(150);
		setMinSeed(90);
		setAmbushness(75);
		break;

	case MBSS:
		setMaxSeed(0);
		setMinSeed(0);
		setAmbushness(0);
		break;

	case BOSS:
		setMaxSeed(0);
		setMinSeed(0);
		setAmbushness(0);
		break;

	default:
		break;
	}
}

//Getter Definitions
string C_Quadrant::getName()
{
	return string(m_name);
}

string C_Quadrant::getColony()
{
	return string(m_colony);
}

string C_Quadrant::getFile()
{
	return string(m_file);
}

int C_Quadrant::getMaxSeed()
{
	return m_maxseed;
}

int C_Quadrant::getMinSeed()
{
	return m_minseed;
}

int C_Quadrant::getAmbushness()
{
	return m_ambushness;
}

int C_Quadrant::getValue()
{
	return m_value;
}

vector<string> C_Quadrant::getMainName()
{
	return vector<string>(m_getNameVector);
}

vector<string> C_Quadrant::getMainColony()
{
	return vector<string>(m_getColonyVector);
}

vector<string> C_Quadrant::getMainFile()
{
	return vector<string>(m_getFileVector);
}

vector<DIFFICULTY> C_Quadrant::getMainDifficulty()
{
	return vector<DIFFICULTY>(m_getDifficultyVector);
}

vector<int> C_Quadrant::getMainValue()
{
	return vector<int>(m_getValueVector);
}
