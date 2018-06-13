#include "Player.h"

//Constructor and Destructor Definitions

C_Player::C_Player()
{
	m_name = { "none" };
	m_defense = 0;
	m_offense = 0;
	m_avoidness = 0;
	m_health = 500;
	m_headgear = { "none" };
	m_bodygear = { "none" };
	m_money = 250;
	m_bobbykey = 3;
	m_powdrive = 3;
	m_positionX = 7;
	m_positionY = 7;
	m_currentTurn = true;
	m_actionTrigger = false;
	m_victory = false;
}

C_Player::~C_Player()
{
}

//Setter Definitions
void C_Player::setHealth(int damage)
{
	m_health += damage;
}

void C_Player::setInitialHealth(int health)
{
	m_health = health;
}

void C_Player::setMoney(int money)
{
	m_money += money;
}

void C_Player::setInitialMoney(int money)
{
	m_money = money;
}

void C_Player::setAvoidness(int avoidness)
{
	m_avoidness = avoidness;
}

void C_Player::setHeadDefense(int headDefense)
{
	m_headDefense = headDefense;
}

void C_Player::setBodyDefense(int bodyDefense)
{
	m_bodyDefense = bodyDefense;
}

void C_Player::setBonusDefense(int headDefense, int bodyDefense, float percentage)
{
	m_bonusDefense = (headDefense + headDefense)*percentage;
}

void C_Player::setDefense(int headDefense, int bodyDefense, int bonus)
{
	m_defense = headDefense + bodyDefense + bonus;
}

void C_Player::setAttack(int attack)
{
	m_offense = attack;
}

void C_Player::setXPosition(int X)
{
	m_positionX = X;
}

void C_Player::setYPosition(int Y)
{
	m_positionY = Y;
}

void C_Player::setXPositionMovement(int X)
{
	m_positionX += X;
}

void C_Player::setYPositionMovement(int Y)
{
	m_positionY += Y;
}

void C_Player::setBobbykey(int bobbykey)
{
	m_bobbykey += bobbykey;
}

void C_Player::setInitialBobbykey(int bobbykey)
{
	m_bobbykey = bobbykey;
}

void C_Player::setPowdrive(int powdrive)
{
	m_powdrive += powdrive;
}

void C_Player::setInitialPowdrive(int powdrive)
{
	m_powdrive = powdrive;
}

void C_Player::setVictory(bool state)
{
	m_victory = state;
}

void C_Player::setCommand()
{
	string command;
	getline(cin, command);
	m_commandline.clear();
	for (int i = 0; i < command.size(); i++)
	{
		command[i] = tolower(command[i]);
	}
	stringstream ss{ command };
	for (string s; ss >> s; )
	{
		m_commandline.push_back(s);
	}
	cout << endl;
}

void C_Player::setHeadgear(string headgear)
{
	m_headgear = headgear;
}

void C_Player::setBodygear(string bodygear)
{
	m_bodygear = bodygear;
}

void C_Player::setObtainedWeapon(int index)
{
	m_weaponry[index].m_obtained = true;
}

void C_Player::setObtainedGarment(int index)
{
	m_garmentry[index].m_obtained = true;
}

void C_Player::setAmmoQuantity(int index, int addition)
{
	m_weaponry[index].m_supply += addition;
}

void C_Player::setFoodQuantity(int index, int addition)
{
	m_groceries[index].m_quantity += addition;
}

void C_Player::setName()
{
	string name;
	getline(cin, name);
	m_name = name;
}

void C_Player::setInitialName(string name)
{
	m_name = name;
}

void C_Player::setWeaponry()
{
	//Weapon Input (Name, Ammo, Type, Key, Price, Cost, Supply, Id, Loss, MaxDamage, MinDamage, Obtained)
	S_Weapon weaponData;

	weaponData = { "Automatic [Rifle]", "5.56 mm round", "FW", "rifle",65,50, 0, m_weaponry.size(), 1, 40, 25, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "[Shotgun]", "12 gauge", "FW", "shotgun",80,75, 0, m_weaponry.size(), 3, 50, 30, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "[Submachine] Gun", "10 mm caliber", "FW", "submachine",0,100, 0, m_weaponry.size(), 5, 80, 15, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "[Berhiriyet]", "Behnit", "PW", "berhiriyet", 80,35,0, m_weaponry.size(), 2, 45, 35, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Grenade [Launcher]", "1 in Grenade", "PW", "launcher", 125,85,0, m_weaponry.size(), 3, 100, 25, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "[Metatelniya]", "Svaika", "PW", "metatelniya",0,115, 0, m_weaponry.size(), 1, 75, 70, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Sonic [Repeater]", "Elctmgnt. Array", "EW", "repeater",165,120, 0, m_weaponry.size(), 1, 130, 90, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Shockwave [Emitter]", "Uranium Core", "EW", "emitter",0,50, 0, m_weaponry.size(), 1, 200, 100, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Laser [Pistol]", "Lithium Battery", "EW", "pistol",240,150, 0, m_weaponry.size(), 1, 110, 75, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Guardian's [Dagger]", "-No Ammo-", "MW", "dagger",0,0, 1, m_weaponry.size(), 0, 10, 5, true };
	m_weaponry.push_back(weaponData);

	weaponData = { "[Tabanashyn]", "-No Ammo-", "MW", "tabanashyn",30,0, 1, m_weaponry.size(), 0, 25, 5, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Troop [Sword]", "-No Ammo-", "MW", "sword",65,0, 1, m_weaponry.size(), 0, 45, 20, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Stab[Hammer]", "-No Ammo-", "MW", "hammer",100,0, 1, m_weaponry.size(), 0, 50, 15, false };
	m_weaponry.push_back(weaponData);

	weaponData = { "Sawed[Sickle]", "-No Ammo-", "MW", "sickle",0,0, 1, m_weaponry.size(), 0, 75, 5, false };
	m_weaponry.push_back(weaponData);
}

void C_Player::setGarmentry()
{
	//Garment Input (Name, Key, Type, Ability, Price, Defense, Id, Obtained)
	S_Garment garmentData;

	garmentData = { "Soldier [Hat]", "hat", "HG", "+15% Defense Points",0, 15, m_garmentry.size(), true };
	m_garmentry.push_back(garmentData);

	garmentData = { "Power [Helmet]", "helmet", "HG", "+30% Defense Points",250, 25, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "Shocktrooper [Fender]", "helmet", "HG", "Damages when attacked",0, 20, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "Stealth [Armet]", "armet", "HG", "Lowers being ambushed",150, 20, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "General [Cap]", "cap", "HG", "Reveals enemy's stats",300, 40, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "Soldier [Suit]", "suit", "BG", "+15% Defense Points",0, 20, m_garmentry.size(), true };
	m_garmentry.push_back(garmentData);

	garmentData = { "Power [Armor]", "armor", "BG", "+30% Defense Points",350, 35, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "Electrified [Equipment]", "equipment", "BG", "Damages when attacked",0, 30, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "Stealth [Rig]", "rig", "BG", "Lowers being ambushed",250, 25, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);

	garmentData = { "General [Garb]", "garb", "BG", "Reveals enemy's stats",450, 45, m_garmentry.size(), false };
	m_garmentry.push_back(garmentData);
}

void C_Player::setGroceries()
{
	S_Food foodData;

	foodData = { "Attankaschaki","attankaschaki",50,10,m_groceries.size(),3 };
	m_groceries.push_back(foodData);

	foodData = { "Poshkitchi","poshkitchi",65,15,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Vabiknilki","vabriknilki",95,25,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Brihtnim","brihtnim",140,40,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Koldonody","koldonody",200,60,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Shchiramniy","shchiramniy",275,85,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Dakinetskaya","dakinetskaya",365,115,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Togpaliyev","togpaliyev",470,150,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Raykustayeni","raykustayeni",590,190,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Lidenknikh","lidenknikh",725,235,m_groceries.size(),0 };
	m_groceries.push_back(foodData);

	foodData = { "Brioshk","brioshk",875,285,m_groceries.size(),0 };
	m_groceries.push_back(foodData);
}

//BattleTime Function Definitions
void C_Player::setCurrentTurn()
{
	if (m_currentTurn == true)
	{
		m_currentTurn = false;
	}
	else
	{
		m_currentTurn = true;
	}
}

void C_Player::setActionTrigger()
{
	if (m_actionTrigger == true)
	{
		m_actionTrigger = false;
	}
	else
	{
		m_actionTrigger = true;
	}
}

void C_Player::setWeaponId(int weaponId)
{
	m_weaponId = weaponId;
}

bool C_Player::setWeaponUsage()
{
	bool found = false;
	int weaponId;

	for (int i = 0; i < m_weaponry.size(); i++)
	{
		if (getCommandline()[1] == m_weaponry[i].m_key)
		{
			found = true;
			setActionTrigger();
			setWeaponId(m_weaponry[i].m_id);
		}
	}

	return found;
}

int C_Player::getAvoidness()
{
	return m_avoidness;
}

//Getter Definitions
int C_Player::getXPosition()
{
	return m_positionX;
}

int C_Player::getYPosition()
{
	return m_positionY;
}

int C_Player::getBobbykey()
{
	return m_bobbykey;
}

int C_Player::getPowdrive()
{
	return m_powdrive;
}

int C_Player::getHeadDefense()
{
	return m_headDefense;
}

int C_Player::getBodyDefense()
{
	return m_bodyDefense;
}

int C_Player::getBonusDefense()
{
	return m_bonusDefense;
}

string C_Player::getHeadgear()
{
	return string(m_headgear);
}

string C_Player::getBodygear()
{
	return string(m_bodygear);
}

vector<S_Food> C_Player::getFood()
{
	return vector<S_Food>(m_groceries);
}

vector<S_Weapon> C_Player::getWeapon()
{
	return vector<S_Weapon>(m_weaponry);
}

vector<S_Garment> C_Player::getGarment()
{
	return vector<S_Garment>(m_garmentry);
}

vector<string> C_Player::getCommandline()
{
	return vector<string>(m_commandline);
}

bool C_Player::getVictory()
{
	return m_victory;
}

int C_Player::getWeaponId()
{
	return m_weaponId;
}

bool C_Player::getCurrentTurn()
{
	return m_currentTurn;
}

bool C_Player::getActionTrigger()
{
	return m_actionTrigger;
}

//Player Actions (All right)
void C_Player::getInventory()
{
	system("cls");
	cout << setw(20) << "<UTILITIES>" << endl;
	cout << "-------------------------------------" << endl;
	cout << setw(15) << "OBJECT" << setw(15) << "QUANTITY" << endl;
	cout << "-------------------------------------" << endl;
	cout << setw(15) << "Bobbykey" << setw(15) << m_bobbykey << endl;
	cout << setw(15) << "Powdrive" << setw(15) << m_powdrive << endl;
	cout << "-------------------------------------" << endl << endl;

	cout << setw(40) << "<WEAPONRY>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "WEAPON" << setw(15) << "AMMO" << setw(15) << "SUPPLY" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < m_weaponry.size(); i++)
	{
		switch (i)
		{
		case 0:
			cout << "(FIRE WEAPONS)" << endl;
			break;

		case 3:
			cout << endl << "(PROJECTILE WEAPONS)" << endl;
			break;

		case 6:
			cout << endl << "(ENERGY WEAPONS)" << endl;
			break;

		case 9:
			cout << endl << "(MELEE WEAPONS)" << endl;
			break;

		default:
			break;
		}

		if (m_weaponry[i].m_obtained == true)
		{
			cout << setw(25) << m_weaponry[i].m_name << setw(15) << m_weaponry[i].m_ammo << setw(15) << m_weaponry[i].m_supply << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << setw(40) << "<GARMENTRY>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "CLOTHING" << setw(15) << "DEFENSE" << setw(25) << "ABILITY" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < m_garmentry.size(); i++)
	{
		switch (i)
		{
		case 0:
			cout << "(HEADGEAR)" << endl;
			break;

		case 5:
			cout << endl << "(BODYGEAR)" << endl;
			break;

		default:
			break;
		}

		if (m_garmentry[i].m_obtained == true)
		{
			cout << setw(25) << m_garmentry[i].m_name << setw(15) << m_garmentry[i].m_defense << setw(25) << m_garmentry[i].m_ability << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << setw(40) << "<FOODSTUFF>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "MEAL" << setw(15) << "NUTRITION" << setw(15) << "PROVISIONS" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < m_groceries.size(); i++)
	{
		if (m_groceries[i].m_quantity > 0)
		{
			cout << setw(25) << m_groceries[i].m_name << setw(15) << m_groceries[i].m_nutrition << setw(15) << m_groceries[i].m_quantity << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;
}

void C_Player::getFeed(string food)
{
	bool found = false;
	int foodId;

	for (int i = 0; i < m_groceries.size(); i++)
	{
		if (food == m_groceries[i].m_key)
		{
			found = true;
			foodId = m_groceries[i].m_id;
		}
	}
	if (found == false)
	{
		cout << "<<You can't eat '" << food << "'. Hjadynivite food has strange names, but this doesn't exist at all..." << endl << endl;
	}
	else if (found == true && m_groceries[foodId].m_quantity<1)
	{
		cout << "You can't eat " << m_groceries[foodId].m_name << ". You don't have this meal!" << endl << endl;
	}
	else if (found == true && m_groceries[foodId].m_quantity>0)
	{
		cout << "You ate a big plate of " << m_groceries[foodId].m_name << endl;
		cout << "It was so yummy that you can feel how your health replenishes!" << endl << endl;
		setHealth(m_groceries[foodId].m_nutrition);
		setFoodQuantity(foodId, -1);
	}
}

void C_Player::getEquipped(string gear)
{
	bool found = false;
	int gearId;

	for (int i = 0; i < m_garmentry.size(); i++)
	{
		if (gear == m_garmentry[i].m_key)
		{
			found = true;
			gearId = m_garmentry[i].m_id;
		}
	}
	if (found == false)
	{
		cout << "You can't equip the '" << gear << "'. As it does not exist on your garmentry." << endl << endl;
	}
	else if (found == true && getHeadgear() == m_garmentry[gearId].m_name || getBodygear() == m_garmentry[gearId].m_name)
	{
		cout << "You already are equipped with the " << m_garmentry[gearId].m_name << endl << endl;
	}
	else if (found == true && getHeadgear() != m_garmentry[gearId].m_name && getBodygear() != m_garmentry[gearId].m_name)
	{
		cout << "You are now equipped with the " << m_garmentry[gearId].m_name << endl << endl;

		if (m_garmentry[gearId].m_type == "HG")
		{
			setHeadgear(m_garmentry[gearId].m_name);
			setHeadDefense(m_garmentry[gearId].m_defense);
		}
		else if (m_garmentry[gearId].m_type == "BG")
		{
			setBodygear(m_garmentry[gearId].m_name);
			setBodyDefense(m_garmentry[gearId].m_defense);
		}

		if (getHeadgear() == "Soldier [Hat]" && getBodygear() == "Soldier [Suit]")
		{
			cout << "You received a bonus +15% defense by using Soldier Set!" << endl;
			setBonusDefense(getHeadDefense(), getBodyDefense(), .15);
		}
		else if (getHeadgear() == "Power [Helmet]" && getBodygear() == "Power [Armor]")
		{
			cout << "You received a bonus +30% defense by using Power Set!" << endl;
			setBonusDefense(getHeadDefense(), getBodyDefense(), .30);
		}
		else if (getHeadgear() == "Shocktrooper [Fender]" && getBodygear() == "Electrified [Equipment]")
		{
			cout << "Now your enemies are damaged when they attack you!" << endl;
		}
		else if (getHeadgear() == "Stealth [Armet]" && getBodygear() == "Stealth [Rig]")
		{
			cout << "Now it is easier to avoid enemies' ambushes!" << endl;
			setAvoidness(10);
		}
		else if (getHeadgear() == "General [Cap]" && getBodygear() == "General [Garb]")
		{
			cout << "Your intuition has grown! You now can see enemy's stats." << endl;
		}
		else
		{
			setBonusDefense(getHeadDefense(), getBodyDefense(), 0);
		}

		setDefense(getHeadDefense(), getBodyDefense(), getBonusDefense());
	}
}

void C_Player::getGoing(string direction)
{
	if (direction == "north"&&m_positionY > 0)
	{
		setYPositionMovement(-1);
		cout << "You are on your way to the north." << endl;
	}
	else if (direction == "south"&&m_positionY < 7)
	{
		setYPositionMovement(1);
		cout << "You are on your way to the south." << endl;
	}
	else if (direction == "west"&&m_positionX > 0)
	{
		setXPositionMovement(-1);
		cout << "You are on your way to the west." << endl;
	}
	else if (direction == "east"&&m_positionX < 7)
	{
		setXPositionMovement(1);
		cout << "You are on your way to the east." << endl;
	}
	else
	{
		cout << "You can't go there anymore." << endl << endl;
	}
}