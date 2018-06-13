#include "World.h"

//Constructor and Destructor Definitions
C_World::C_World()
{
	setHackables();
	setLockpickables();
}

C_World::~C_World()
{
}

//Main Getters
int C_World::getBattleValue()
{
	return m_battleValue;
}

vector<string> C_World::getSaveFiles()
{
	return vector<string>(m_savefiles);
}

bool C_World::stob(string x)
{
	if (x == "false")
	{
		return false;
	}
	else if (x == "true")
	{
		return true;
	}
}

string C_World::btos(bool y)
{
	if (y == false)
	{
		return "false";
	}
	else if (y == true)
	{
		return "true";
	}
}

//Main Initializer Definition
void C_World::initializer()
{
	cout << "JOURNEY OF THE JUSTICE: Fall of the Atom (C) TCCPe 2018" << endl;
	fileLoader("intro.gaf");
	cout << "Input 'create' to create a new game." << endl;
	cout << "Input 'load' to load a saved game." << endl;
	
	do
	{
		cout << "Commandline>> ";
		m_player.setCommand();
		if (m_player.getCommandline().size() == 1)
		{
			if (m_player.getCommandline()[0] == "create")
			{
				setPlayer();
				cout << "Please write your name>> ";
				m_player.setName();
				cout << "All done, " << m_player.getName() << ". Your game has been created successfully!" << endl;
				cout << "ADVICE: Remember to save continuosly. It is frustrating to lose all your progress." << endl << endl;
				stop();

				cout << "Hello, " << m_player.getName() << "." << endl;
				fileLoader("story.gef");
				cout << endl << "Farewell and good luck, " << m_player.getName() << "." << endl;
				setInitializer();
				stop();

			}
			else if (m_player.getCommandline()[0] == "load")
			{
				setPlayer();
				getLoader();
				setInitializer();
			}
		}
	} while (getInitializer()==false);
	

	while (getExecuter() == true && m_player.getHealth() > 0 && m_player.getVictory() != true)
	{
		setQuadrant(m_map[m_player.getYPosition()][m_player.getXPosition()]);
		cout << m_quadrant.getColony() << endl;
		cout << m_quadrant.getName() << endl;
		fileLoader(m_quadrant.getFile());

		cout << endl << "---STATS---" << endl;
		cout << "Name: " << m_player.getName() << endl;
		cout << "Health: " << m_player.getHealth() << endl;
		cout << "Headgear: " << m_player.getHeadgear() << " equipped" << endl;
		cout << "Bodygear: " << m_player.getBodygear() << " equipped" << endl;
		cout << "Hjadynivite Rayubi: Rb$" << m_player.getMoney() << endl;

		cout << endl << "Input 'help' if you don't know what to do now." << endl;

		cout << endl << "Input a command>> ";
		m_player.setCommand();

		if (m_player.getCommandline().size() == 1)
		{
			if (m_player.getCommandline()[0] == "inventory")
			{
				m_player.getInventory();
			}
			else if (m_player.getCommandline()[0] == "analyze")
			{
				getDescription(m_quadrant.getValue());
			}
			else if (m_player.getCommandline()[0] == "help")
			{
				getHelp("main");
			}
			else if (m_player.getCommandline()[0] == "map")
			{
				getMap();
			}
			else if (m_player.getCommandline()[0] == "save")
			{
				getSaver();
			}
			else if (m_player.getCommandline()[0] == "exit")
			{
				cout << "Please specify that you wanna exit the game..." << endl;
				stop();
			}
		}
		else if (m_player.getCommandline().size() == 2)
		{
			if (m_player.getCommandline()[0] == "eat")
			{
				m_player.getFeed(m_player.getCommandline()[1]);
				stop();
			}
			else if (m_player.getCommandline()[0] == "equip")
			{
				m_player.getEquipped(m_player.getCommandline()[1]);
				stop();
			}
			else if (m_player.getCommandline()[0] == "play")
			{
				if (m_player.getCommandline()[1] == "sloty" && m_quadrant.getValue() == 57)
				{
					getSloty();
				}
				else if (m_player.getCommandline()[1] == "biryulki" && m_quadrant.getValue() == 60)
				{
					getBiryulki();
				}
				else
				{
					cout << "<<You cannot play any game here" << endl;
				}
			}
			else if (m_player.getCommandline()[0] == "enter")
			{
				if (m_player.getCommandline()[1] == "station")
				{
					getStation(m_quadrant.getValue());
				}
				else if (m_player.getCommandline()[1] == "shop" && m_quadrant.getValue() == 5)
				{
					getShop();
				}
				else if (m_player.getCommandline()[1] == "store" && m_quadrant.getValue() == 11)
				{
					getStore();
				}
				else
				{
					cout << "<<You cannot enter anywhere here" << endl;
				}
			}
			else if (m_player.getCommandline()[0] == "hack")
			{
				getHackInitializer(m_player.getCommandline()[1], m_quadrant.getValue());
			}
			else if (m_player.getCommandline()[0] == "lockpick")
			{
				getLockpickInitializer(m_player.getCommandline()[1], m_quadrant.getValue());
			}
			else if (m_player.getCommandline()[0] == "confront")
			{
				getConfrontation(m_player.getCommandline()[1], m_quadrant.getValue());
			}
			else if (m_player.getCommandline()[0] == "go")
			{
				m_player.getGoing(m_player.getCommandline()[1]);

				srand((int)time(0));
				setBattleValue((rand() % 100) + 1);
				if (getBattleValue()<=m_quadrant.getAmbushness() - m_player.getAvoidness())
				{
					cout << "-<EVENT>-" << endl;
					cout << "You have been ambushed by an enemy!" << endl << endl;
					stop();
					getEnemySelector(m_quadrant.getMinSeed(), m_quadrant.getMaxSeed());
				}
				else
				{
					stop();
				}
			}
			else if (m_player.getCommandline()[0] == "exit")
			{
				if (m_player.getCommandline()[1] == "game")
				{
					cout << "Ok. Goodbye, see you later, " << m_player.getName() << "!" << endl << endl;
					setExecuter();
					stop();
				}
			}
		}
	}
	if (m_player.getHealth() <= 0)
	{
		cout << "GAME OVER" << endl;
		stop();
	}
	if (m_player.getVictory() == true)
	{
		cout << "<CONGRATULATIONS>" << endl;
		cout << "You destroyed the Churnivniy Power Plant!" << endl << endl;
		fileLoader("end.gef");
		stop();
	}
}

//World Attribute Definitions
void C_World::fileLoader(string file)
{
	string printer;

	ifstream ifs{ file };
	while (getline(ifs, printer))
	{
		cout << printer << endl;
	}
}

void C_World::stop()
{
	system("pause");
	system("cls");
}

void C_World::setSaveFiles()
{
	string savefile;
	ifstream cmp{ "saves.gef" };
	while (getline(cmp, savefile))
	{
		m_savefiles.push_back(savefile);
	}
}

void C_World::getLoader()
{
	bool found = false;
	setSaveFiles();

	if (getSaveFiles().size() == 0)
	{
		cout << "There are no savefiles. You need to create a new game" << endl << endl;
	}
	else
	{
		cout << endl << "---LOAD---" << endl;
		do
		{
			cout << "Current save files:" << endl;
			fileLoader("saves.gef");
			cout << endl << "Input the file name>> ";
			m_player.setCommand();
			for (int z = 0; z < getSaveFiles().size(); z++)
			{
				if (getSaveFiles()[z] == m_player.getCommandline()[0])
				{
					found = true;
				}

				if (z == (getSaveFiles().size() - 1) && found == false)
				{
					cout << "File not found. Please input a valid savename." << endl;
				}
			}

		} while (found == false);
		setCore(m_player.getCommandline()[0]);
		for (int index = 0; index < CORE_LIMIT; index++)
		{
			if (index == 0)
			{
				m_player.setInitialName(getCore()[index]);
			}
			else if (index == 1)
			{
				m_player.setXPosition(stoi(getCore()[index]));
			}
			else if (index == 2)
			{
				m_player.setYPosition(stoi(getCore()[index]));
			}
			else if (index == 3)
			{
				m_player.setInitialHealth(stoi(getCore()[index]));
			}
			else if (index == 4)
			{
				m_player.setInitialMoney(stoi(getCore()[index]));
			}
			else if (index == 5)
			{
				m_player.setInitialBobbykey(stoi(getCore()[index]));
			}
			else if (index == 6)
			{
				m_player.setInitialPowdrive(stoi(getCore()[index]));
			}
			else if (index == 7)
			{
				m_player.setHeadgear(getCore()[index]);
			}
			else if (index == 8)
			{
				m_player.setBodygear(getCore()[index]);
			}
			else if (index == 9)
			{
				int foodIndex = 0;
				for (index; index < 20; index++)
				{
					m_player.setFoodQuantity(foodIndex, stoi(getCore()[index]));
					foodIndex++;
				}
				index = 19;
			}
			else if (index == 20)
			{
				int weaponIndex = 0;
				for (index; index < 34; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						m_player.setObtainedWeapon(weaponIndex);
					}
					weaponIndex++;
				}
				index = 33;
			}
			else if (index == 34)
			{
				int ammoIndex = 0;
				for (index; index < 43; index++)
				{
					m_player.setAmmoQuantity(ammoIndex, stoi(getCore()[index]));
					ammoIndex++;
				}
				index = 42;
			}
			else if (index == 43)
			{
				int garmentIndex = 0;
				for (index; index < 53; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						m_player.setObtainedGarment(garmentIndex);
					}
					garmentIndex++;
				}
				index = 52;
			}
			else if (index == 53)
			{
				int hackIndex = 0;
				for (index; index < 56; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						getHackStates("unlock", hackIndex);
					}
					hackIndex++;
				}
				index = 55;
			}
			else if (index == 56)
			{
				int hackIndex = 0;
				for (index; index < 59; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						getHackStates("block", hackIndex);
					}
					hackIndex++;
				}
				index = 58;
			}
			else if (index == 59)
			{
				int lockpickIndex = 0;
				for (index; index < 62; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						getLockpickStates("open", lockpickIndex);
					}
					lockpickIndex++;
				}
				index = 61;
			}
			else if (index == 62)
			{
				int lockpickIndex = 0;
				for (index; index < 65; index++)
				{
					if (stob(getCore()[index]) == true)
					{
						getLockpickStates("break", lockpickIndex);
					}
					lockpickIndex++;
				}
			}
		}
		cout << "Welcome again, " << m_player.getName() << ". Your game has been loaded successfully!" << endl;
		setInitializer();
		stop();
	}
}

void C_World::getSaver()
{
	int counter = 0;
	bool comparator = false;

	cout << endl << "---SAVE---" << endl;
	cout << "Be sure to name your savefile with a different name to those already created." << endl;
	do
	{
		cout << "Current save files:" << endl;
		if (m_savefiles.size() == 0)
		{
			cout << "None" << endl << endl;
		}
		else
		{
			fileLoader("saves.gef");
		}
		cout << endl << "We recommend you to save your files with extension (.gsf)" << endl;
		cout << endl << "Input the file name>> ";
		m_player.setCommand();
		
		for (int z = 0; z < m_savefiles.size(); z++)
		{
			if (m_savefiles[z] == m_player.getCommandline()[0])
			{
				comparator = true;
				cout << "Beware! There is a savefile with the same name." <<
					endl << "To avoid confusions, please input another filename." << endl << endl;
			}
			else
			{
				counter++;
			}
		}
		if (counter == m_savefiles.size())
		{
			comparator = false;
		}
		counter = 0;
	} while (comparator == true);
	ofstream app{ "saves.gef", std::ofstream::app };
	app << endl << m_player.getCommandline()[0];

	ofstream ofs{ m_player.getCommandline()[0] };
	ofs << m_player.getName() << endl;
	ofs << m_player.getXPosition() << endl;
	ofs << m_player.getYPosition() << endl;
	ofs << m_player.getHealth() << endl;
	ofs << m_player.getMoney() << endl;
	ofs << m_player.getBobbykey() << endl;
	ofs << m_player.getPowdrive() << endl;
	ofs << m_player.getHeadgear() << endl;
	ofs << m_player.getBodygear() << endl;
	for (int i = 0; i < m_player.getFood().size(); i++)
	{
		ofs << m_player.getFood()[i].m_quantity << endl;
	}
	for (int i = 0; i < m_player.getWeapon().size(); i++)
	{
		ofs << btos(m_player.getWeapon()[i].m_obtained) << endl;
	}
	for (int i = 0; i < m_player.getWeapon().size(); i++)
	{
		ofs << m_player.getWeapon()[i].m_supply << endl;
	}
	for (int i = 0; i < m_player.getGarment().size(); i++)
	{
		ofs << btos(m_player.getGarment()[i].m_obtained) << endl;
	}
	for (int i = 0; i < m_hackable.size(); i++)
	{
		ofs << btos(m_hackable[i].m_unlocked) << endl;
	}
	for (int i = 0; i < m_hackable.size(); i++)
	{
		ofs << btos(m_hackable[i].m_blocked) << endl;
	}
	for (int i = 0; i < m_lockpickable.size(); i++)
	{
		ofs << btos(m_lockpickable[i].m_open) << endl;
	}
	for (int i = 0; i < m_lockpickable.size(); i++)
	{
		ofs << btos(m_lockpickable[i].m_broken) << endl;
	}
	cout << "Saved successfully as " << m_player.getCommandline()[0] << "!" << endl << endl;
	stop();
	comparator = true;
}

//Gameplay Attribute Definitions
void C_World::getHelp(string key)
{
	system("cls");
	if (key == "lockpick")
	{
		cout << endl;
		cout << "LOCKPICKING INSTRUCTIONS" << endl;
		cout << "-Lockpicking requires bobbykeys to try to unlock" << endl;
		cout << "-All unlockables have a number of keypins to break" << endl;
		cout << "-To lockpick you need to input 'thrust' plus a direction" << endl;
		cout << "EXAMPLE:" << endl;
		cout << "(Command: thrust up)" << endl;
		cout << "This thrusts the lock upwards and registers the movement" << endl;
		cout << "-Finish all your movements and see how many movements you got right" << endl;
		cout << "-If you don't break the lock within the limit attempts, it will break" << endl;
		cout << " and you won't be able to try to unlock it again" << endl << endl;
		cout << "INFORMATION" << endl;
		cout << "There are a variety of keyholes types throughout Pribet. Some require more effort to lockpick." << endl;
		cout << "-(Difficulty) can range from easy to difficult depending on the door's protection" << endl;
		cout << "-(Limit) depends on the fact of how many times the keyhole can be lockpicked before wearing out" << endl;
		cout << "-(Keypins) can tell you how many movements you need to make if you wanna break the lock" << endl << endl;
	}
	else if (key == "hacking")
	{
		cout << endl;
		cout << "HACKING INSTRUCTIONS" << endl;
		cout << "-Hacking a system needs a powdrive to try to unlock" << endl;
		cout << "-The powdrive obtains all the letters of the password, you need to write the word." << endl;
		cout << "-To input a password you need to write 'type' plus the word" << endl;
		cout << "EXAMPLE:" << endl;
		cout << "(Command: type password)" << endl;
		cout << "This makes the system receive the input and check if it is the password" << endl;
		cout << "-Write the exact password and the system will be unlocked" << endl;
		cout << "-If you don't input the correct password within the limit attempts, it will be blocked" << endl;
		cout << " and you won't be able to try to unlock it again" << endl << endl;
		cout << "INFORMATION" << endl;
		cout << "Not all systems have the same level of protection. Some are more forgiving than others" << endl;
		cout << "-(Difficulty) can range from easy to difficult depending on the system's protection" << endl;
		cout << "-(Limit) depends on the system's ability to find threatening hardware, such as powdrives" << endl;
		cout << "-(Possibilities) can tell you a clue of how many words can be made with the password hint" << endl << endl;
	}
	else if (key == "main")
	{
		cout << "HELP" << endl;
		cout << "-This game is all command based, so be sure to check your spelling here." << endl;
		cout << "[1 COMMAND ACTIONS]." << endl;
		cout << "With this actions you don't need to input another word into the commandline." << endl;
		cout << "-INVENTORY		(Shows player's objects. And it can be pretty handy to know what you own)" << endl;
		cout << "-MAP			(Displays Pribet's region map. It helps you to see where you are)" << endl;
		cout << "-SAVE			(Saves current game. Beware! Creating does not save your game, you need save it)" << endl;
		cout << "-ANALYZE		(Makes you to admire the place, so a description can be available)" << endl;
		cout << "[2 COMMAND ACTIONS]." << endl;
		cout << "This actions need to be more specific to be executed, so they need to receive a certain command." << endl;
		cout << "<Always Available>" << endl;
		cout << "-GO...			(This basic command is used to move throughout. You can go in all cardinal points.)" << endl;
		cout << "-EQUIP...		(This command allows you to use your available armor for your defense)" << endl;
		cout << "-EAT...			(This command is for eating a meal that can replenish your health)" << endl;
		cout << "-EXIT GAME		(This may seem exagerated, but this can be a safe way to exit the game.)" << endl;
		cout << "<Available by Place>" << endl;
		cout << "-HACK...		(With this command you can try to hack certain electronic devices)" << endl;
		cout << "-ENTER...		(This command allows you to enter certain buildings. Mainly to shop, travel or play.)" << endl;
		cout << "-LOCKPICK...		(This command grants the opportunity to try to unlock some keyholes)" << endl;
		cout << "-CONFRONT...		(This command engages a battle. There may be certain persons whose ass you'd like to kick.)" << endl;
	}
	else if (key == "battle")
	{
		cout << "BATTLE" << endl;
		cout << "[1 COMMAND ACTIONS]" << endl;
		cout << "With this actions you don't need to input another word into the commandline." << endl;
		cout << "-INVENTORY		(Shows player's objects. And it can be pretty handy to know what you own)" << endl;
		cout << "[2 COMMAND ACTIONS]." << endl;
		cout << ">Remember to use only the word betweeen []" << endl;
		cout << "-USE...		(Makes use of the weapon only if you have enough ammo.)" << endl;
		cout << "-EQUIP...		(Equips the player with the specified armor. Be sure to own it)" << endl;
		cout << "-EAT...		(This command is for eating a meal that can replenish your health)" << endl;
		cout << "This actions need to be more specific to be executed, so they need to receive a certain command." << endl;
	}
}

void C_World::getDescription(int quadrantValue)
{
	system("cls");
	switch (quadrantValue)
	{
	case 1:
		cout << "-ATANA STATION-" << endl;
		cout << "The farthermost station of Pribet. It was constructed to reach certain" << endl;
		cout << "government complexes, and also to get easy access to all Pribet." << endl;
		cout << "Near the station is the commercial zone. Garvodnosht and Arbtaniya" << endl;
		cout << "are part of it, and there is easy to find an extensive amount of" << endl;
		cout << "weapons, armor and supplies." << endl;
		break;
	case 5:
		cout << "-ARBTANIYA SUPPLY SHOP-" << endl;
		cout << "One of the most recognized suppliers from all Pribet, what makes it" << endl;
		cout << "unique is the fact that their suplies are government-stocked. So it" << endl;
		cout << "is sure to find top-notch supplies and even some actually used by" << endl;
		cout << "the Pribet Guard itself. Without doubt the Arbtaniya Supply Shop is" << endl;
		cout << "a must for those who want to find a trustful and qualified supplier." << endl;
		break;
	case 8:
		cout << "-CHURNIVNIY ATOMIC POWER PLANT-" << endl;
		cout << "The newly constructed Churnivniy Atomic Power Plant, as the name implies," << endl;
		cout << "is the facility that the Hjadynivite and Khaznatanvian governments" << endl;
		cout << "constructed to implement atomic fision technology to create electricity." << endl;
		cout << "It is totally prohibited for any unrecognized strange to enter the facility." << endl;
		cout << "The system that constrols the whole is there and it may be breakable. " << endl;
		break;
	case 11:
		cout << "GARVODNOSHT WEAPON & ARMOR STORE" << endl;
		cout << "This store has an assortment of lots of weapons, some of them only seen" << endl;
		cout << "in Hjadynivia. The amazing thing about this store is that it is an" << endl;
		cout << "authorized retiler of army-grade armor and weapons. If you are the one" << endl;
		cout << "that wants to have the ultimate weapons and armor, this store is a must." << endl;
		cout << "The fatal flaw with this store is that it doesn't sell ammo at all." << endl;
		break;
	case 15:
		cout << "-HALL OF THE ATOM-" << endl;
		cout << "Constructed specially to conmemorate the Atomic Sciences, it is a goverment" << endl;
		cout << "building that hosts some of the most influent scientists and exchieftains" << endl;
		cout << "of the Hjadynivite Union. This place is surrounded by dangerous soldiers." << endl;
		cout << "Some say that the Captain of the Hjadynivite Union actually is living here" << endl;
		cout << "as part of the celebration of the 'Accomplishment of the Atom'." << endl;
		break;

	case 24:
		cout << "TREASURY OF PRIBET" << endl;
		cout << "Not only the treasury is the storage of gold and other valuable resources, but" << endl;
		cout << "also the home of antique relics and other invaluable treasures that are kept" << endl;
		cout << "inside. The treasury is certainly well army protected, but its flaw is that there" << endl;
		cout << "are no alarms or electronic sensors or locks to protect their goods. Maybe since" << endl;
		cout << "they love old and outdated things, their protection system consists only of a gate." << endl;
		break;

	case 17:
		cout << "-HJADYNIVITE ENERGY DEVERLOPMENT COMPLEX-" << endl;
		cout << "This building's main purpose is to enhance the atomic fision energy extraction." << endl;
		cout << "Although Hjadynivia has marked a milestone in energy production, their" << endl;
		cout << "process is very prone to a meltdown. Also, this facility finds the way to use" << endl;
		cout << "energy to make deadly weapons and armor. Some say that somewhere on the inside" << endl;
		cout << "there is an experimental armor that is protected by a government server." << endl;
		break;

	case 21:
		cout << "NADZHENIYE CENTRALNIY METRO STATION" << endl;
		cout << "Recognized as one of the most important metro stations of Pribet, it is mainly" << endl;
		cout << "used by government members. Some call this station as the 'Heart of Pribet'" << endl;
		cout << "thanks to its closeness to government buldings. That also means that it is the" << endl;
		cout << "hell for a Barithronite spy, as it is surrounded by army officials. But if" << endl;
		cout << "you are strong enough to overcome the soldiers, then no problem." << endl;
		break;
	case 26:
		cout << "PRIBET PALACE OF GOVERNMENT" << endl;
		cout << "Residence of the chieftains of Pribet, this is place is infested with government" << endl;
		cout << "people. The General, as the head of state, has reinforced the borders fearing" << endl;
		cout << "an invasion from any rebel group. Pribetite officials may seem happy and proud" << endl;
		cout << "on the outside, but in the inside they are living freightened by paranoia." << endl;
		cout << "Maybe their achievement won't save them from their wickedness." << endl;
		break;
	case 27:
		cout << "ARBINTSKAYA FEDERAL BARRACKS" << endl;
		cout << "The Leader of the Hjadynivite not only wants Pribet to be an energy powerhouse" << endl;
		cout << "but he also wants the city to be one of the most important military conentation" << endl;
		cout << "camps. The Federal Barracks is also the home of one of the most advanced" << endl;
		cout << "weapons developed in the I Intraplanetary War of 1850. It is property of one" << endl;
		cout << "of the officials, but he isn't always here. Someone may take a peek at the safa." << endl;
		break;
	case 37:
		cout << "MONUMENT TO THE HEROES" << endl;
		cout << "The Monument to the Heroes is a tall tower with an observatory at the top of it," << endl;
		cout << "where some says that there is memorabilia conmemorating the Hjadynivite soldiers" << endl;
		cout << "that died on the I Intraplanetary Battle. Supossedly there is the weapon used by" << endl;
		cout << "Captain Senasy to kill Federat Edenstern on the Battle of Lazlitniy. But even" << endl;
		cout << "the weapon is too tempting to be exhibited, and it is kept door locked." << endl;
	case 41:
		cout << "DARSHNAKOV METRO STATION" << endl;
		cout << "Darshnakov Station's importance to Pribet is humongous since it is very tied" << endl;
		cout << "with Pribetite culture. Darshnakov Station provides the main gate to Ternbeliy" << endl;
		cout << "Region, and thus, one of the most beloved administative divisions of Pribet." << endl;
		cout << "Also known as 'Happiness Station', it is used by a lot of Churnivniy Power Plant" << endl;
		cout << "worker's families on weekends. Ternbeliy is the destination of Pribetite Families." << endl;
		break;
	case 43:
		cout << "MUSEUM OF THE FALLEN" << endl;
		cout << "This museum can be seen by foreigners like an hostile way to show Hjadynivia's" << endl;
		cout << "victories throughout history, since this museum is specifically purposed to show" << endl;
		cout << "the defeat of the enemies of Hjadynivia. And as well, it can be the treasure mine" << endl;
		cout << "of a scavenger that looks for imported weapons, but robbing the weapons isn't" << endl;
		cout << "as easy as said since the exhibits are locked under computer protection." << endl;
	case 39:
		cout << "PRIBET GARDEN RESTAURANT" << endl;
		cout << "The Pribet Garden Restaurant is, without doubt, the best restaurant in Khaznatanvia." << endl;
		cout << "Famous because of its traditional Hjadynivite meals, from Attankaschaki to Brioshk," << endl;
		cout << "its menu is widely recognized Naanda-wide and the best part is that they actually" << endl;
		cout << "serve the food in Void (TM) containers that keep the food warm even if you eat" << endl;
		cout << "it months later. Although the food has strange names, the flavor is nostalgic." << endl;
		break;
	case 54:
		cout << "TARNIBILSK METRO STATION" << endl;
		cout << "Tarnibilsk Mestro Station was built to transport visitors and locals easily from" << endl;
		cout << "near the Gate of Pribet to their destinations. It is also filled with Pribet," << endl;
		cout << "Khaznatanvia and Hjadynivia cultural references to welcome visitors and to" << endl;
		cout << "make locals feel proud of their homelands. This is also a great addition to the" << endl;
		cout << "city, showing Naanda that Hjadynivites have a big warm heart." << endl;
		break;
	case 57:
		cout << "TERNBELIY SLOTY CASINO" << endl;
		cout << "The Ternbeliy Sloty casino is the main tourist attraction for those who want" << endl;
		cout << "to win big. The casino was constructed on an ancient abandoned castle, and" << endl;
		cout << "now it is a classy place to win *waste* money. One of the most remarkable" << endl;
		cout << "things is that here is the only place in all Naanda where you can play Sloty," << endl;
		cout << "the Hjadynivite version of slots, also known asn the 'All or nothing' slots." << endl;
		break;
	case 60:
		cout << "RAYUBINEV BIRYULKI PLAYHOUSE" << endl;
		cout << "The Biryulki Playhouse is the place where townfolks from all around the city" << endl;
		cout << "gather to play a nice game of Biryulki. This game is practically a millionaire" << endl;
		cout << "maker since you have a 20% opportunity to win and the longer the game, the" << endl;
		cout << "prize is juicier! This playhouse is a demonstration of Khaznatanvian culture," << endl;
		cout << "this game has been played by generation and generations." << endl;
		break;
	case 64:
		cout << "-THE GREAT PRIBET GATE-" << endl;
		cout << "The great pribet gate is the main and only entrance to the city, since all the" << endl;
		cout << "city is surrounded by Pribet River. The gate was erected not much long ago," << endl;
		cout << "the city is not even a year old. Its main purpose according to informative" << endl;
		cout << "brochures is to 'Open Hjadynivia's arms to Naanda'. Pribet is privileged thanks " << endl;
		cout << "to their templated climate. So far it looks like the city everyone wants to live in." << endl;
		break;
	default:
		break;
	}
}

void C_World::getBattle(int index)
{
	setEnemy(index);
	while (m_enemy.getHealth() > 0 && m_player.getHealth() > 0)
	{
		cout << m_quadrant.getColony() << endl;
		cout << m_enemy.getName() << endl << endl;
		if (m_player.getHeadgear() == "General [Cap]"&&m_player.getBodygear() == "General [Garb]")
		{
			cout << setw(46) << "<ENEMY STATS>" << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << setw(20) << "Health: " << m_enemy.getHealth() << setw(20) << "Defense: " << m_enemy.getDefense() << setw(20) << "Offense: " << m_enemy.getAttack() << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		fileLoader(m_enemy.getFile());
	
		cout << setw(46) << "<PLAYER STATS>" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << setw(20) << "Health: " << m_player.getHealth() << setw(20) << "Defense: " << m_player.getDefense() << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
	
		if (m_player.getCurrentTurn() == true && m_player.getActionTrigger() == false)
		{
	
			cout << "Input a command>> ";
			m_player.setCommand();
	
			if (m_player.getCommandline().size() == 1)
			{
				if (m_player.getCommandline()[0] == "run")
				{
					cout << m_enemy.getName() << ":" << endl;
					cout << "YOU CANNOT RUN, DAMN BARITHRONITE SPY! BWAHAHAHA" << endl;
					stop();
				}
				else if (m_player.getCommandline()[0] == "help")
				{
					getHelp("battle");
				}
				else if (m_player.getCommandline()[0] == "inventory")
				{
					m_player.getInventory();
				}
				else
				{
					cout << "Invalid action. Be sure to write a valid command<<" << endl;
					stop();
				}
			}
			else if (m_player.getCommandline().size() == 2)
			{
				if (m_player.getCommandline()[0] == "use")
				{
					if (m_player.setWeaponUsage() == true && m_player.getWeapon()[m_player.getWeaponId()].m_supply >= m_player.getWeapon()[m_player.getWeaponId()].m_loss)
					{
						cout << setw(46) << "---<EVENT>---" << endl;
						cout << "You used the " << m_player.getWeapon()[m_player.getWeaponId()].m_name << " against the " << m_enemy.getName() << "!" << endl;
						m_player.setAttack(((rand() % m_player.getWeapon()[m_player.getWeaponId()].m_maxdmg) + m_player.getWeapon()[m_player.getWeaponId()].m_mindmg) - (m_enemy.getDefense() / 10));
						m_player.setAmmoQuantity(m_player.getWeaponId(), m_player.getWeapon()[m_player.getWeaponId()].m_loss*-1);
						m_enemy.setHealth(m_player.getAttack());

						if (m_player.getAttack() > 0)
						{
							cout << "The " << m_enemy.getName() << " has lost " << m_player.getAttack() << " health points!" << endl;
						}
						else
						{
							cout << "The " << m_enemy.getName() << " wasn't affected by your attack!" << endl;
						}
					}
					else if (m_player.setWeaponUsage() == true && m_player.getWeapon()[m_player.getWeaponId()].m_supply < m_player.getWeapon()[m_player.getWeaponId()].m_loss)
					{
						cout << "You don't have enough ammo to use the " << m_player.getWeapon()[m_player.getWeaponId()].m_name << "!" << endl;
					}
					else if (m_player.setWeaponUsage() == false)
					{
						cout << "You can't use that in battle! Beware on input your actions.<<" << endl;
					}
					m_player.setCurrentTurn();
					stop();
				}
				else if (m_player.getCommandline()[0] == "equip")
				{
					m_player.getEquipped(m_player.getCommandline()[1]);
					stop();
				}
				else if (m_player.getCommandline()[0] == "eat")
				{
					m_player.getFeed(m_player.getCommandline()[1]);
					stop();
				}
			}
		}
		else
		{
			cout << setw(46) << "---<EVENT>---" << endl;
			cout << "The " << m_enemy.getName() << " is bound to attack!" << endl;
			cout << "WHAM!" << endl;
			m_enemy.setAttack(m_enemy.getAttack() - ((m_player.getDefense() * (rand() % (m_player.getDefense() + 1)) / 20)));
			if (m_enemy.getAttack() > 0)
			{
				cout << "You lost " << m_enemy.getAttack() << " health points!" << endl;
				m_player.setHealth(-m_enemy.getAttack());
			}
			else
			{
				cout << "You weren't affected by his attack!" << endl;
			}

			if (m_player.getHeadgear() == "Shocktrooper [Fender]"&&m_player.getBodygear() == "Electrified [Equipment]")
			{
				cout << endl << "The " << m_enemy.getName() << " received an electric shock when attacked you!" << endl;
				m_enemy.setHealth(m_enemy.getAttack() / 20);
			}
			m_player.setCurrentTurn();
			m_player.setActionTrigger();
			stop();
		}
	}
	if (m_enemy.getHealth() <= 0)
	{
		cout << setw(44) << "~~~<VICTORY>~~~" << endl;
		cout << "Congratulations, you killed the " << m_enemy.getName() << " !" << endl << endl;
		cout << "You receive: Rb$" << m_enemy.getMoney() << endl;
		m_player.setMoney(m_enemy.getMoney());
		stop();
	}
	else
	{
		cout << setw(44) << "...<DEFEAT>..." << endl;
		cout << "Damn... You were defeated by the " << m_enemy.getName() << "..." << endl << endl;
		stop();
	}
}

void C_World::getConfrontation(string victim, int quadrantValue)
{
	if (victim == "general"&&quadrantValue == 26)
	{
		getBattle(GENERAL);
	}
	else if (victim == "captain"&&quadrantValue == 15)
	{
		getBattle(CAPTAIN);
	}
	else
	{
		cout << ">>You can't confront anyone here" << endl;
	}
}

void C_World::getEnemySelector(int minSeed, int maxSeed)
{
	int selector;
	srand((int)time(0));
	selector = ((rand() % maxSeed) + minSeed);
	cout << selector << " " << minSeed << " " << maxSeed << " " << endl;
	if (selector <= 50)
	{
		getBattle(SOLDIER);
	}
	else if (selector > 50 && selector <= 90)
	{
		getBattle(PRIVATE);
	}
	else if (selector > 90 && selector <= 120)
	{
		getBattle(SERGEANT);
	}
	else if (selector > 120 && selector <= 140)
	{
		getBattle(CADET);
	}
	else if (selector > 140 && selector <= 150)
	{
		getBattle(COMMANDANT);
	}
	else
	{
		getBattle(SERGEANT);
	}
}

void C_World::getSloty()
{
	vector<char> slot{ '?','?','?' };
	int bet, randomizer;

	system("cls");
	cout << "	      ---SLOTY---" << endl;
	cout << "***Get the same icons and you'll win!***" << endl;
	cout << " ++Just input your bet and get lucky!++ " << endl << endl;
	cout << ">> FINANCES" << endl;
	cout << "Balance: Rb$" << m_player.getMoney() << endl;
	cout << "Bet: Rb$";
	cin >> bet;
	if (bet > m_player.getMoney())
	{
		cout << endl << "STOP! You cannot bet that quantity! You don't own that much money." << endl << endl;
	}
	else if (bet == 0)
	{
		cout << endl << "WAIT! You cannot bet nothing! You gotta input a real bet." << endl << endl;
	}
	else
	{
		srand((int)time(0));
		for (int c = 0; c < slot.size(); c++)
		{
			randomizer = (rand() % 150) + 1;
			if (randomizer <= 50)
			{
				slot[c] = '%';
			}
			else if (randomizer > 50 && randomizer <= 90)
			{
				slot[c] = '&';
			}
			else if (randomizer > 90 && randomizer <= 120)
			{
				slot[c] = '@';
			}
			else if (randomizer > 120 && randomizer <= 140)
			{
				slot[c] = '#';
			}
			else if (randomizer > 140 && randomizer <= 150)
			{
				slot[c] = '$';
			}
		}

		cout << endl;
		fileLoader("slot_a.gaf");
		cout << "       | [" << slot[0] << "] [" << slot[1] << "] [" << slot[2] << "] |(  )" << endl;
		fileLoader("slot_b.gaf");
		cout << endl;
		if (slot[0] == slot[1] && slot[1] == slot[2])
		{
			switch (slot[0])
			{
			case '%':
				bet *= 2;
				break;
			case '#':
				bet *= 25;
				break;
			case '@':
				bet *= 10;
				break;
			case '&':
				bet *= 5;
				break;
			case '$':
				bet *= 50;
				break;
			}
			m_player.setMoney(bet);
			cout << "CONGRATULATIONS!" << endl;
			cout << "You win Rb$" << bet << "!" << endl << endl;
			cout << ">> FINANCES" << endl;
			cout << "Balance: Rb$" << m_player.getMoney() << endl;

		}
		else
		{
			m_player.setMoney(-bet);
			cout << "What a pity..." << endl;
			cout << "You lose Rb$" << bet << "..." << endl << endl;
			cout << ">> FINANCES" << endl;
			cout << "Balance: Rb$" << m_player.getMoney() << endl << endl;
		}
	
		stop();
	}
}

void C_World::getBiryulki()
{
	int bet, randomizer, turn = 0;
	bool win = false;
	
	vector<int>count{ 0,0,0,0,0 };
	vector<string>names{ "jewel","leaf","doll","crown","ball" };
	string option = "void", token;
	system("cls");
	cout << "	     ---BIRYULKI---" << endl;
	cout << "***Be the first in getting all your tokens and win!***" << endl;
	cout << "      ++The longer the game, the more you earn!++ " << endl << endl;
	cout << ">> FINANCES" << endl;
	cout << "Balance: Rb$" << m_player.getMoney() << endl;
	cout << "Bet: Rb$";
	cin >> bet;

	if (bet > m_player.getMoney())
	{
		cout << endl << "STOP! You cannot bet that quantity! You don't own that much money." << endl << endl;
	}
	else if (bet == 0)
	{
		cout << endl << "WAIT! You cannot bet nothing! You gotta input a real bet" << endl << endl;
	}
	else
	{
		fileLoader("tokens.gaf");
		while (token != "jewel"&&token != "leaf"&&token != "crown"&&token != "ball"&&token != "doll")
		{
			cout << "Choose a token: ";
			cin >> token;
			fileLoader(token);
			if (token == "jewel" || token == "leaf" || token == "crown" || token == "ball" || token == "doll")
			{
				cout << "Ok! Your token will be the " << token << endl;
			}
			else
			{
				cout << "That's an invalid token name... Be sure to write the token name." << endl << endl;
			}
		}
		srand((int)time(0));
		while (count[0] != 5 && count[1] != 5 && count[2] != 5 && count[3] != 5 && count[4] != 5)
		{
			turn++;
			randomizer = (rand() % 5) + 1;
			switch (randomizer)
			{

			case JEWEL:
				fileLoader("jewel.gaf");
				cout << "The token number " << turn << " is a Jewel!" << endl << endl;
				count[0]++;
				break;
			case LEAF:
				fileLoader("leaf.gaf");
				cout << "The token number " << turn << " is a Leaf!" << endl << endl;
				count[1]++;
				break;
			case DOLL:
				fileLoader("doll.gaf");
				cout << "The token number " << turn << " is a Doll!" << endl << endl;
				count[2]++;
				break;
			case CROWN:
				fileLoader("crown.gaf");
				cout << "The token number " << turn << " is a Crown!" << endl << endl;
				count[3]++;
				break;
			case BALL:
				fileLoader("ball.gaf");
				cout << "The token number " << turn << " is a Ball!" << endl << endl;
				count[4]++;
				break;
			}
			cout << "TURN'S RESULTS" << endl;
			cout << "The jewel has " << count[0] << " tokens!" << endl;
			cout << "The leaf has " << count[1] << " tokens!" << endl;
			cout << "The doll has " << count[2] << " tokens!" << endl;
			cout << "The crown has " << count[3] << " tokens!" << endl;
			cout << "The ball has " << count[4] << " tokens!" << endl << endl;

			stop();
		}
		for (int p = 0; p < count.size(); p++)
		{
			if (count[p] == 5 && names[p] == token)
			{
				win = true;
			}
		}
		if (win == true)
		{
			bet *= turn;
			m_player.setMoney(bet);
			cout << "CONGRATULATIONS!" << endl;
			cout << "Your bet will be multiplied by " << turn << "!" << endl;
			cout << "You win Rb$" << bet << "!" << endl << endl;
			cout << ">> FINANCES" << endl;
			cout << "Balance: Rb$" << m_player.getMoney() << endl;
			stop();
		}
		else
		{
			m_player.setMoney(-bet);
			cout << "What a pity..." << endl;
			cout << "You lose Rb$" << bet << "..." << endl << endl;
			cout << ">> FINANCES" << endl;
			cout << "Balance: Rb$" << m_player.getMoney() << endl << endl;
			stop();
		}

	}
}

void C_World::getStation(int quadrantValue)
{
	if (quadrantValue==1 || quadrantValue == 21 || quadrantValue == 41 || quadrantValue == 54)
	{
		switch (quadrantValue)
		{
		case 1:
			cout << "[ATANA STATION]" << endl << endl;
			break;
		case 21:
			cout << endl << "[NADZHENIYE CENTRALNIY STATION]" << endl << endl;
			break;
		case 41:
			cout << endl << "[DARSHNAKOV STATION]" << endl << endl;
			break;
		case 54:
			cout << endl << "[TARNIBILSK STATION]" << endl << endl;
			break;
		default:
			cout << "There are no metro stations in this quadrant>>" << endl;
			break;
			stop();
		}

		cout << "Destinations:" << endl;

		if (quadrantValue != 1)
		{
			cout << ">>Atana Station" << endl;
		}
		if (quadrantValue != 21)
		{
			cout << ">>Nadzheniye Station" << endl;
		}
		if (quadrantValue != 41)
		{
			cout << ">>Darshnakov Station" << endl;
		}
		if (quadrantValue != 54)
		{
			cout << ">>Tarnibilsk Station" << endl;
		}

		cout << endl << "Destination station name>> ";
		m_player.setCommand();

		if (m_player.getCommandline()[0] == "nadzheniye" && quadrantValue != 21)
		{
			cout << "You are now traveling to Nadzheniye station" << endl;
			m_player.setXPosition(4);
			m_player.setYPosition(2);
		}
		else if (m_player.getCommandline()[0] == "darshnakov" && quadrantValue != 41)
		{
			cout << "You are now traveling to Darshnakov station" << endl;
			m_player.setXPosition(0);
			m_player.setYPosition(5);
		}
		else if (m_player.getCommandline()[0] == "tarnibilsk" && quadrantValue != 54)
		{
			cout << "You are now traveling to Tarnibilsk station" << endl;
			m_player.setXPosition(5);
			m_player.setYPosition(6);
		}
		else if (m_player.getCommandline()[0] == "atana" && quadrantValue != 1)
		{
			cout << "You are now traveling to Atana station" << endl;
			m_player.setXPosition(0);
			m_player.setYPosition(0);
		}
		else
		{
			cout << "You can't go to that station. Be sure just to input the name of the destination station." << endl;
		}
	}
	else
	{
		cout << "There are no stations in this quadrant." << endl;
	}
	stop();
}

void C_World::getShop()
{
	cout << endl << "-ARBTANIYA SUPPLY SHOP-" << endl;
	cout << "OBJECT			PRICE		DESCRIPTION" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "(x1)Bobbykey		Rb$30		Famous between burglars, it is used to unlock keyholes." << endl;
	cout << "(x1)Powdrive		Rb$30		As the name implies, it has the power to extract password digits." << endl << endl;

	cout << "AMMO			PRICE		DESCRIPTION" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "(x10) 5.56 mm [round]	Rb$50		This ammo is specifically used for its reliability" << endl;
	cout << "(x15) 12 [gauge]	Rb$75		This shell contains a lot of cadmium pellets on its inside" << endl;
	cout << "(x30) 10 mm [caliber]	Rb$100		The most sold and used ammo in all Pribet!" << endl;
	cout << "(x10) [Behnit]		Rb$35		This ancient arrow is special by its accuracy" << endl;
	cout << "(x12) 1 in [Grenade]	Rb$85		This little 1 inch grenades explode when collide" << endl;
	cout << "(x5) [Svaika]		Rb$115		Svaikas do a lot of damage if reachs its victim" << endl;
	cout << "(x3) Elctmgnt.[Array]	Rb$120		This is the ammo of experimental atomic army grade weaponry" << endl;
	cout << "(x1) Uranium [Core]	Rb$50		Smuggling this ammo is a reason to be in the Gobrinski" << endl;
	cout << "(x5) Lithium [Battery]	Rb$150		Hjadynivite officials and spies use this top-notch ammo" << endl << endl;

	cout << "Input a command>> ";
	m_player.setCommand();

	if (m_player.getCommandline().size() == 1)
	{
		if (m_player.getCommandline()[0] == "exit")
		{
			cout << "The ARBTANIYA SUPPLY SHOP thanks your preference! We hope to see you again soon." << endl;
		}
	}
	else if (m_player.getCommandline().size() == 2)
	{
		if (m_player.getCommandline()[0] == "buy")
		{
			if (m_player.getCommandline()[1] == "bobbykey" && (m_player.getMoney() - 30) >= 0)
			{
				cout << "You bought some " << m_player.getCommandline()[1] << "s. They will be added to your inventory." << endl;
				m_player.setBobbykey(1);
				m_player.setMoney(-30);
				stop();
			}
			else if (m_player.getCommandline()[1] == "powdrive" && (m_player.getMoney() - 30) >= 0)
			{
				cout << "You bought some " << m_player.getCommandline()[1] << "s. They will be added to your inventory." << endl;
				m_player.setPowdrive(1);
				m_player.setMoney(-30);
				stop();
			}
			else if (m_player.getCommandline()[1] == "round")
			{
				getShopPurchase(RIFLE, 10);
			}
			else if (m_player.getCommandline()[1] == "gauge")
			{
				getShopPurchase(SHOTGUN, 15);
			}
			else if (m_player.getCommandline()[1] == "caliber")
			{
				getShopPurchase(SUBMACHINE, 30);
			}
			else if (m_player.getCommandline()[1] == "behnit")
			{
				getShopPurchase(BERHIRIYET, 10);
			}
			else if (m_player.getCommandline()[1] == "grenade")
			{
				getShopPurchase(LAUNCHER, 12);
			}
			else if (m_player.getCommandline()[1] == "svaika")
			{
				getShopPurchase(METATELNIYA, 5);
			}
			else if (m_player.getCommandline()[1] == "array")
			{
				getShopPurchase(REPEATER, 3);
			}
			else if (m_player.getCommandline()[1] == "core")
			{
				getShopPurchase(EMITTER, 1);
			}
			else if (m_player.getCommandline()[1] == "battery")
			{
				getShopPurchase(PISTOL, 5);
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

void C_World::getShopPurchase(int index, int addition)
{
	if ((m_player.getMoney() - m_player.getWeapon()[index].m_cost) >= 0)
	{
		cout << "You bought a pack of " << m_player.getWeapon()[index].m_ammo << ". They will be added to your inventory." << endl;
		m_player.setAmmoQuantity(index, addition);
		m_player.setMoney(m_player.getWeapon()[index].m_cost*-1);
		stop();
	}
	else
	{
		cout << "<<You can't buy that!" << endl;
		cout << "(!) Please be sure that you have enough money or that the supply actually exists." << endl;
		stop();
	}
}

void C_World::getStore()
{
	cout << "-GARVODNOSHT ARMOR & WEAPON STORE-" << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "WEAPON				PRICE		DESCRIPTION" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (m_player.getWeapon()[RIFLE].m_obtained == false)
	{
		cout << "Automatic [Rifle]		Rb$65		This weapon actually was developed by a Hjadynivite " << endl;
	}
	if (m_player.getWeapon()[SHOTGUN].m_obtained == false)
	{
		cout << "[Shotgun]			Rb$80		This weapon is deadly when used near the the victim " << endl;
	}
	if (m_player.getWeapon()[BERHIRIYET].m_obtained == false)
	{
		cout << "[Berhiriyet]			Rb$80		This is an ancient bow-like weapon. Very used long ago. " << endl;
	}
	if (m_player.getWeapon()[LAUNCHER].m_obtained == false)
	{
		cout << "Grenade [Launcher]		Rb$125		This machine-gun-like weapon launches mid-ranged grenades. " << endl;
	}
	if (m_player.getWeapon()[REPEATER].m_obtained == false)
	{
		cout << "Sonic [Repeater]		Rb$165		When the weapon is triggered, it creates a destructive sonic wave. " << endl;
	}
	if (m_player.getWeapon()[PISTOL].m_obtained == false)
	{
		cout << "Laser [Pistol]			Rb$240		Shoots an accurate hot laser beam. It is very piercing. " << endl;
	}
	if (m_player.getWeapon()[TABANASHYN].m_obtained == false)
	{
		cout << "[Tabanasyn]			Rb$30		Ancient sharp knife used by the Tuvaknish tribe. " << endl;
	}
	if (m_player.getWeapon()[SWORD].m_obtained == false)
	{
		cout << "Trooper [Sword]			Rb$65		One-handed sword used by Hjadynivites in the I Great War. " << endl;
	}
	if (m_player.getWeapon()[HAMMER].m_obtained == false)
	{
		cout << "Stab[Hammer]			Rb$100		Modified Hjadynivite hammer with a spike used to stab. " << endl;
	}

	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "GEAR				PRICE		DESCRIPTION" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (m_player.getGarment()[HELMET].m_obtained == false)
	{
		cout << "Power [Helmet]			Rb$250		Heavy metal helmet used by Hjadynivites 30 years ago. " << endl;
	}
	if (m_player.getGarment()[ARMET].m_obtained == false)
	{
		cout << "Stealth [Armet]			Rb$150		Armet used by spies. It makes almost no sound at all." << endl;
	}
	if (m_player.getGarment()[CAP].m_obtained == false)
	{
		cout << "General [Cap]			Rb$300		Cap used by Hjadynivite generals. Somehow enhances intuition." << endl;
	}
	if (m_player.getGarment()[ARMOR].m_obtained == false)
	{
		cout << "Power [Armor]			Rb$350		Heavy metal armor used by Hjadynivites 30 years ago. " << endl;
	}
	if (m_player.getGarment()[RIG].m_obtained == false)
	{
		cout << "Stealth [Rig]			Rb$250		Rig used by spies. It makes almost no sound at all." << endl;
	}
	if (m_player.getGarment()[GARB].m_obtained == false)
	{
		cout << "General [Garb]			Rb$450		Garb used by Hjadynivite generals. Somehow enhances intuition." << endl;
	}

	cout << endl << "Input a command>> ";
	m_player.setCommand();
	
	if (m_player.getCommandline().size() == 1)
	{
		if (m_player.getCommandline()[0] == "exit")
		{
			cout << "The GARVODNOSHT ARMOR & WEAPON STORE thanks your preference! We hope to see you again soon." << endl;
		}
	}
	else if (m_player.getCommandline().size() == 2)
	{
		if (m_player.getCommandline()[0] == "buy")
		{
			if (m_player.getCommandline()[1] == "rifle")
			{
				getStorePurchase(RIFLE, m_player.getWeapon()[RIFLE].m_type);
			}
			else if (m_player.getCommandline()[1] == "shotgun")
			{
				getStorePurchase(SHOTGUN, m_player.getWeapon()[SHOTGUN].m_type);
			}
			else if (m_player.getCommandline()[1] == "berhiriyet")
			{
				getStorePurchase(BERHIRIYET, m_player.getWeapon()[BERHIRIYET].m_type);
			}
			else if (m_player.getCommandline()[1] == "launcher")
			{
				getStorePurchase(LAUNCHER, m_player.getWeapon()[LAUNCHER].m_type);
			}
			else if (m_player.getCommandline()[1] == "repeater")
			{
				getStorePurchase(REPEATER, m_player.getWeapon()[REPEATER].m_type);
			}
			else if (m_player.getCommandline()[1] == "pistol")
			{
				getStorePurchase(PISTOL, m_player.getWeapon()[PISTOL].m_type);
			}
			else if (m_player.getCommandline()[1] == "helmet")
			{
				getStorePurchase(HELMET, m_player.getGarment()[HELMET].m_type);
			}
			else if (m_player.getCommandline()[1] == "armet")
			{
				getStorePurchase(ARMET, m_player.getGarment()[ARMET].m_type);
			}
			else if (m_player.getCommandline()[1] == "cap")
			{
				getStorePurchase(CAP, m_player.getGarment()[CAP].m_type);
			}
			else if (m_player.getCommandline()[1] == "armor")
			{
				getStorePurchase(ARMOR, m_player.getGarment()[ARMOR].m_type);
			}
			else if (m_player.getCommandline()[1] == "rig")
			{
				getStorePurchase(RIG, m_player.getGarment()[RIG].m_type);
			}
			else if (m_player.getCommandline()[1] == "garb")
			{
				getStorePurchase(GARB, m_player.getGarment()[GARB].m_type);
			}
			else
			{
				cout << "You can't buy " << m_player.getCommandline()[1] << endl;
				cout << "(!) Please be sure that the object actually exists." << endl;
				stop();
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

void C_World::getStorePurchase(int index, string type)
{
	try
	{
		if (type == "FW" || type == "PW" || type == "EW" || type == "MW")
		{
			if ((m_player.getMoney() - m_player.getWeapon()[index].m_price) >= 0 && m_player.getWeapon()[index].m_obtained == false)
			{
				cout << "You bought the " << m_player.getWeapon()[index].m_name << ". Now you can use it in the battlefield!." << endl;
				m_player.setObtainedWeapon(index);
				m_player.setMoney(m_player.getWeapon()[index].m_price*-1);
				stop();
			}
			else
			{
				throw("<<You can't buy that weapon");
			}
		}
		else if (type == "HG" || type == "BG")
		{
			if ((m_player.getMoney() - m_player.getGarment()[index].m_price) >= 0 && m_player.getGarment()[index].m_obtained == false)
			{
				cout << "You bought the " << m_player.getGarment()[index].m_name << ". Now you can use it in the battlefield!." << endl;
				m_player.setObtainedGarment(index);
				m_player.setMoney(m_player.getGarment()[index].m_price*-1);
				stop();
			}
			else
			{
				throw("<<You can't buy that garment");
			}
		}
	}
	catch (const char* advise)
	{
		cout << advise << endl;
		cout << "(!) Please be sure that you have enough money or you may even own what you asked for." << endl;
		stop();
	}
}

void C_World::getRestaurant()
{
	cout << endl << "-PRIBET GARDEN RESTAURANT-" << endl;
	cout << "MEAL			PRICE		DESCRIPTION" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "Attankaschaki		Rb$10		Tuna & mayo with rice" << endl;
	cout << "Poshkitchi		Rb$15		Boiled wheat with minced meat and rice" << endl;
	cout << "Vabriknilki		Rb$25		Potato balls filled with chicken, herbs and cheese" << endl;
	cout << "Brihtnim		Rb$40		Meat dumplings with mushroom cream sauce" << endl;
	cout << "Koldonody		Rb$60		Egg noodle soup with cheese and bacon" << endl;
	cout << "Shchiramniy		Rb$85		Bean stew with tomato sauce and pork cutlets" << endl;
	cout << "Dakinetskaya		Rb$115		Fish sticks with cheese garlic bread and tartar sauce" << endl;
	cout << "Togpaliyev		Rb$150		Chicken, cheese, bacon, and dressing pastry pies" << endl;
	cout << "Raykustayeni		Rb$190		Cream with minced meat bits & herbs with fluff biscuits" << endl;
	cout << "Lidenknikh		Rb$235		Bacon-wrapped prawns with cheese and roasted veggies" << endl;
	//		Brioshk				Rb$285	SECRET MENU ITEM

	cout << endl << "Input a command>> ";
	m_player.setCommand();

	if (m_player.getCommandline().size() == 1)
	{
		if (m_player.getCommandline()[0] == "exit")
		{
			cout << "The PRIBET GARDEN RESTAURANT thanks your preference! We hope to see you again soon." << endl;
		}
	}
	else if (m_player.getCommandline().size() == 2)
	{
		if (m_player.getCommandline()[0] == "buy")
		{
			if (m_player.getCommandline()[1] == "attankaschaki")
			{
				getRestaurantPurchase(ATTANKASCHAKI, 1);
			}
			else if (m_player.getCommandline()[1] == "poshkitchi")
			{
				getRestaurantPurchase(POSHKITCHI, 1);
			}
			else if (m_player.getCommandline()[1] == "vabriknilki")
			{
				getRestaurantPurchase(VABRIKNILKI, 1);
			}
			else if (m_player.getCommandline()[1] == "brihtnim")
			{
				getRestaurantPurchase(BRIHTNIM, 1);
			}
			else if (m_player.getCommandline()[1] == "koldonody")
			{
				getRestaurantPurchase(KOLDONODY, 1);
			}
			else if (m_player.getCommandline()[1] == "shchiramniy")
			{
				getRestaurantPurchase(SHCHIRAMNIY, 1);
			}
			else if (m_player.getCommandline()[1] == "dakinetskaya")
			{
				getRestaurantPurchase(DAKINETSKAYA, 1);
			}
			else if (m_player.getCommandline()[1] == "togpaliyev")
			{
				getRestaurantPurchase(TOGPALIYEV, 1);
			}
			else if (m_player.getCommandline()[1] == "raykustayeni")
			{
				getRestaurantPurchase(RAYKUSTAYENI, 1);
			}
			else if (m_player.getCommandline()[1] == "lidenknikh")
			{
				getRestaurantPurchase(LIDENKNIKH, 1);
			}
			else if (m_player.getCommandline()[1] == "brioshk")
			{
				getRestaurantPurchase(BRIOSHK, 1);
			}
			else
			{
				cout << "You can't buy " << m_player.getCommandline()[1] << endl;
				cout << "(!) Please be sure that the meal actually exists." << endl;
				stop();
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

void C_World::getRestaurantPurchase(int index, int addition)
{
	if ((m_player.getMoney() - m_player.getFood()[index].m_price) >= 0)
	{
		cout << "You bought a plate of " << m_player.getFood()[index].m_name << ". It will be added to your inventory." << endl;
		m_player.setFoodQuantity(index, addition);
		m_player.setMoney(m_player.getFood()[index].m_price*-1);
		stop();
	}
	else
	{
		cout << "<<You can't buy that."<< endl;
		cout << "(!) Please be sure that you have enough money." << endl;
		stop();
	}
}

void C_World::getHackInitializer(string command, int quadrantValue)
{
	if (command == "computer" && quadrantValue == 43)
	{
		getHacking(COMPUTER);
	}
	else if (command == "server" && quadrantValue == 17)
	{
		getHacking(SERVER);
	}
	else if (command == "system" && quadrantValue == 8)
	{
		getHacking(SYSTEM);
	}
}

void C_World::getHacking(int index)
{
	//Data Input (Name, Filename, Difficulty, Word, Password, Attempts, Possibilities, Limit, Prize Type, Id, Is Unlocked, Is Blocked)

	system("cls");
	cout << "//"<<getHackable()[index].m_name<<" HACKING" << endl;
	if (getHackable()[index].m_unlocked == false && getHackable()[index].m_blocked == false)
	{
		if (index == SYSTEM)
		{
			fileLoader("screen_l.gaf");
			cout << "This is the government's Churniv Power Plant System. It may be pretty difficult to surpass." << endl << endl;
		}
		else if (index == COMPUTER)
		{
			fileLoader("computer_l.gaf");
			cout << "This is a pretty common computer. It may be kinda easy to hack." << endl << endl;
		}
		else if (index == SERVER)
		{
			fileLoader("computer_l.gaf");
			cout << "This is a server. It may be somewhat complex to hack." << endl << endl;
		}

		cout << "<DATA>" << endl;
		cout << "Difficulty: " << getHackable()[index].m_difficulty << endl;
		cout << "Possibilities: " << getHackable()[index].m_possibilities << endl;
		cout << "Limit: " << getHackable()[index].m_limit << endl << endl;
		cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

		if (index == SYSTEM)
		{
			fileLoader("system_a.gaf");
			cout << "  | |(Password hint: " << getHackable()[index].m_word << ")     | |" << endl;
			fileLoader("system_b.gaf");
		}
		else
		{
			fileLoader("monitor_a.gaf");
			cout << "     |   |(Password hint: " << getHackable()[index].m_word << ")             |   |" << endl;
			fileLoader("monitor_b.gaf");
		}
	}
	else if (getHackable()[index].m_unlocked == true)
	{
		if (index == SYSTEM)
		{
			fileLoader("screen_u.gaf");
			cout << "This system has been hacked already!" << endl;
			stop();
		}
		else if (index == COMPUTER)
		{
			fileLoader("computer_u.gaf");
			cout << "This computer has been hacked already!" << endl;
			stop();
		}
		else if (index == SERVER)
		{
			fileLoader("computer_u.gaf");
			cout << "This computer has been hacked already!" << endl;
			stop();
		}
		
	}
	else if (getHackable()[index].m_blocked == true)
	{
		if (index == SYSTEM)
		{
			fileLoader("screen_b.gaf");
			cout << "This system has detected an access violation. It will be impossible to hack again" << endl;
			stop();
		}
		else if (index == SERVER)
		{
			fileLoader("computer_b.gaf");
			cout << "This server has detected an access violation. It will be impossible to hack again" << endl;
			stop();
		}
		else if (index == COMPUTER)
		{
			fileLoader("computer_b.gaf");
			cout << "This computer has detected an access violation. It will be impossible to hack again" << endl;
			stop();
		}
	}

	while (getHackable()[index].m_unlocked == false && getHackable()[index].m_blocked == false && m_player.getPowdrive()>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << m_player.getPowdrive() << endl;
		cout << "Attempts: " << getHackable()[index].m_attempt << endl << endl;

		//Command input
		cout << "Input a command>> ";
		m_player.setCommand();

		if (m_player.getCommandline().size() == 1)
		{
			if (m_player.getCommandline()[0] == "help")
			{
				getHelp("hacking");
			}
			else
			{
				cout << "<<Wrong or incomplete command. Be sure to enter the correct command or input 'help'" << endl << endl;
			}
		}
		else if (m_player.getCommandline().size() == 2)
		{
			if (m_player.getCommandline()[0] == "type")
			{
				getAttemptCounter("hack", index);
				m_player.setPowdrive(-1);
				if (m_player.getCommandline()[1] == getHackable()[index].m_password)
				{
					switch (getHackable()[index].m_type)
					{
					case WEAPON:
						fileLoader("monitor_d.gaf");
						cout << "You avoided the Monument to the Heroes' secret treasure chamber!" << endl;
						cout << "You stole the " << m_player.getWeapon()[SUBMACHINE].m_name << " from one exhibit. Now you can use it in the battlefield!." << endl;
						m_player.setObtainedWeapon(SUBMACHINE);
						stop();
						break;

					case GARMENT:
						fileLoader("monitor_d.gaf");
						cout << "You shut down the complex's data servers and alarm system!" << endl;
						cout << "You stole the found the Shocktrooper Set from one secret room! Now you can use it in the battlefield!" << endl;
						m_player.setObtainedGarment(FENDER);
						m_player.setObtainedGarment(EQUIPMENT);
						stop();
						break;

					case EVENT:
						fileLoader("system_d.gaf");
						cout << "You deactivated the Churnivniy Power Plant!" << endl;
						cout << "Hjadynivia's Power Plant will autodestruct!" << endl;
						m_player.setVictory(true);
						stop();
						break;

					default:
						break;
					}
					getHackStates("unlock", index);
				}
				else
				{
					if (index == SYSTEM)
					{
						fileLoader("system_a.gaf");
						cout << "  | |(Password hint: " << getHackable()[index].m_word << ")     | |" << endl;
						fileLoader("system_c.gaf");
						for (int c = 0; c < getHackable()[index].m_password.size(); c++)
						{
							if (getHackable()[index].m_password[c] == m_player.getCommandline()[1][c])
							{
								cout << "System reports that there is a similarity at index number " << c << endl;
							}
						}
					}
					else if (index == SERVER)
					{
						fileLoader("monitor_a.gaf");
						cout << "     |   |(Password hint: " << getHackable()[index].m_word << ")             |   |" << endl;
						fileLoader("monitor_c.gaf");
						for (int c = 0; c < getHackable()[index].m_password.size(); c++)
						{
							if (getHackable()[index].m_password[c] == m_player.getCommandline()[1][c])
							{
								cout << "Server reports that there is a similarity at index number " << c++ << endl;
							}
						}
					}
					else if (index == COMPUTER)
					{
						fileLoader("monitor_a.gaf");
						cout << "     |   |(Password hint: " << getHackable()[index].m_word << ")             |   |" << endl;
						fileLoader("monitor_c.gaf");
						for (int c = 0; c < getHackable()[index].m_password.size(); c++)
						{
							if (getHackable()[index].m_password[c] == m_player.getCommandline()[1][c])
							{
								cout << "Computer reports that there is a similarity at index number " << c++ << endl;
							}
						}
					}
				}
			}
			else
			{
				cout << "Hey! You entered an invalid input. Be sure to get it right" << endl;
			}
		}
		else
		{
			cout << "<< Command Overload!" << endl;
		}

		if (getHackable()[index].m_attempt == getHackable()[index].m_limit)
		{
			cout << endl << "You didn't guess the password. The computer is blocked, it can't be accessed again." << endl << endl;
			getHackStates("block", index);
			stop();
		}
		if (m_player.getPowdrive() == 0 && getHackable()[index].m_unlocked != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the computer again." << endl << endl;
			stop();
		}
	}
}

void C_World::getLockpickInitializer(string command, int quadrantValue)
{
	if (command == "door"&&quadrantValue == 37)
	{
		getLockpicking(DOOR);
	}
	else if (command == "gate"&&quadrantValue == 24)
	{
		getLockpicking(GATE);
	}
	else if (command == "safe"&&quadrantValue == 27)
	{
		getLockpicking(SAFE);
	}
}

//Data Input (Name, Difficulty, Attempts, Keypins, Hits, Limit, Prize Number, Id, Is Open, Is Broken)
void C_World::getLockpicking(int index)
{
	int  randomizer, hits=0;
	vector<string> keylock; //"int" prefix stands for "internal"

	system("cls");
	cout << "//" << getLockpickable()[index].m_name << " LOCKPICKING" << endl << endl;
	if (getLockpickable()[index].m_open == false && (getLockpickable()[index].m_broken == false))
	{
		fileLoader("door_c.gaf");
		if (index == DOOR)
		{
			cout << "This is a pretty common door" << endl << endl;
		}
		else if (index == GATE)
		{
			cout << "This is a ye olde gate, it can't be that easy to unlock" << endl << endl;
		}
		else if (index == SAFE)
		{
			cout << "This is a pretty common safe, it can be a pain to open" << endl << endl;
		}
		
		cout << "<DATA>" << endl;
		cout << "Difficulty: " << getLockpickable()[index].m_difficulty << endl;
		cout << "Keypins: " << getLockpickable()[index].m_keypin << endl;
		cout << "Limit: " << getLockpickable()[index].m_limit << endl << endl;
		cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

		//Logic
		for (int k = 0; k < getLockpickable()[index].m_keypin; k++)
		{
			randomizer = rand() % 4 + 1;
			switch (randomizer)
			{
			case 1:
				keylock.push_back("up");
				break;
			case 2:
				keylock.push_back("down");
				break;
			case 3:
				keylock.push_back("right");
				break;
			case 4:
				keylock.push_back("left");
				break;
			}
		}
	}
	else if (getLockpickable()[index].m_open == true)
	{
		fileLoader("door_o.gaf");
		if (index == DOOR)
		{
			cout << "This door has been lockpicked successfully!" << endl;
		}
		else if (index == GATE)
		{
			cout << "This gate has been lockpicked successfully!" << endl;
		}
		else if (index == SAFE)
		{
			cout << "This safe has been lockpicked successfully!" << endl;
		}
		stop();
	}
	else if (getLockpickable()[index].m_broken == true)
	{
		fileLoader("door_b.gaf");
		if (index == DOOR)
		{
			cout << "This door's keyhole is broken. It will be impossible to try to unlock it." << endl;
		}
		else if (index == GATE)
		{
			cout << "This gate's keyhole is broken. It will be impossible to try to unlock it." << endl;
		}
		else if (index == SAFE)
		{
			cout << "This safe's keyhole is broken. It will be impossible to try to unlock it." << endl;
		}
		stop();
	}

	while (getLockpickable()[index].m_open == false && getLockpickable()[index].m_broken == false && m_player.getBobbykey() > 0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << m_player.getBobbykey() << endl;
		cout << "Attempts: " << getLockpickable()[index].m_attempt << endl << endl;
		m_player.setBobbykey(-1);

		//Command input
		for (int t = 0; t < getLockpickable()[index].m_keypin; t++)
		{
			getAttemptCounter("lockpick", index);
			cout << "Input a command>> ";
			m_player.setCommand();

			if (m_player.getCommandline().size() == 1)
			{
				if (m_player.getCommandline()[0] == "help")
				{
					getHelp("lockpick");
				}
			}
			else if (m_player.getCommandline().size() == 2)
			{
				if (m_player.getCommandline()[0] == "thrust")
				{
					if (m_player.getCommandline()[1] == keylock[t])
					{
						hits += 1;
						cout << "You got over keypin number " << t << "!" << endl;
					}
					else
					{
						cout << endl << "You didn't overpass this keypin. Try thrusting in other direction next time." << endl;
					}
				}
				else
				{
					cout << "Hey! You entered an invalid direction. You can thrust upwards, downwards, left and right." << endl;
					t--;
				}
			}
			else
			{
				cout << "<< Incorrect Command!" << endl;
				t--;
			}
		}
	}

		if (hits < getLockpickable()[index].m_keypin)
		{
			cout << endl << "You have surpassed " << hits << " keypins out of " << getLockpickable()[index].m_keypin << endl;
		}
		if (hits == getLockpickable()[index].m_keypin)
		{
			if (index == DOOR)
			{
				cout << endl << "You surpassed all keypins and unlocked the door!" << endl << endl;
				cout << "You opened the Museum of the Fallen's storage back door." << endl;
				cout << "You unwapped a package and took the " << m_player.getWeapon()[METATELNIYA].m_name << " from the box. Now you can use it in the battlefield!." << endl;
				m_player.setObtainedWeapon(METATELNIYA);
			}
			else if (index == GATE)
			{
				cout << endl << "You surpassed all keypins and unlocked the gate!" << endl << endl;
				cout << "You unlocked the Pribetite Treasury gate and found Khaznatanvia's national treasure!" << endl;
				cout << "You now own the " << m_player.getWeapon()[SICKLE].m_name << ". You can use it in the battlefield!." << endl;
				m_player.setObtainedWeapon(SICKLE);
			}
			else if (index == SAFE)
			{
				cout << endl << "You surpassed all keypins and unlocked the gate!" << endl << endl;
				cout << "You opened the Arbintskaya Federal Barracks safe." << endl;
				cout << "You unveiled and took the " << m_player.getWeapon()[EMITTER].m_name << ". Now you can use it in the battlefield!." << endl;
				m_player.setObtainedWeapon(EMITTER);
			}
			getLockpickStates("open", index);
			stop();

		}
		if (getLockpickable()[index].m_attempt == getLockpickable()[index].m_limit)
		{
			if (index == DOOR)
			{
				cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the door is locked forever." << endl << endl;
			}
			else if (index == GATE)
			{
				cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the gate is locked forever." << endl << endl;
			}
			else if (index == SAFE)
			{
				cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the safe is locked forever." << endl << endl;
			}
			getLockpickStates("break", index);
			stop();
		}
		if (m_player.getBobbykey() == 0 && getLockpickable()[index].m_open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the door again." << endl << endl;
			stop();
		}
		hits = 0;
}

void C_World::getAttemptCounter(string function, int index)
{
	if (function == "hack")
	{
		m_hackable[index].m_attempt++;
	}
	else if (function == "lockpick")
	{
		m_lockpickable[index].m_attempt++;
	}
}

void C_World::getHackStates(string state, int index)
{
	if (state == "unlock")
	{
		m_hackable[index].m_unlocked = true;
	}
	else if (state == "block")
	{
		m_hackable[index].m_blocked = true;
	}
}

void C_World::getLockpickStates(string state, int index)
{
	if (state == "open")
	{
		m_lockpickable[index].m_open = true;
	}
	else if (state == "break")
	{
		m_lockpickable[index].m_broken = true;
	}
}

void C_World::getMap()
{
	system("cls");
	cout << "-<MAP OF PRIBET>-" << endl << endl;
	fileLoader("map.gaf");
	cout << endl;
}

void C_World::setCore(string file)
{
	string retriever;
	int index = 0;
	ifstream *ifs = new ifstream{ file };
	while (getline(*ifs, retriever))
	{
		m_core.push_back(retriever);
	}
	delete (ifs);
}

//Setter Definitions
void C_World::setPlayer()
{
	m_player.setGarmentry();
	m_player.setWeaponry();
	m_player.setGroceries();
}

void C_World::setEnemy(int key)
{
	m_enemy.setName(m_enemy.getMainName()[key]);
	m_enemy.setFile(m_enemy.getMainFile()[key]);
	m_enemy.setInitialHealth((rand() % m_enemy.getMaxHealth()[key]) + m_enemy.getMinHealth()[key]);
	m_enemy.setDefense((rand() % m_enemy.getMaxDefense()[key]) + m_enemy.getMinDefense()[key]);
	m_enemy.setAttack((rand() % m_enemy.getMaxOffense()[key]) + m_enemy.getMinOffense()[key]);
	m_enemy.setMoney((rand() % m_enemy.getMaxMoney()[key]) + m_enemy.getMinMoney()[key]);
}

void C_World::setQuadrant(int value)
{
	m_quadrant.setName(m_quadrant.getMainName()[value]);
	m_quadrant.setColony(m_quadrant.getMainColony()[value]);
	m_quadrant.setFile(m_quadrant.getMainFile()[value]);
	m_quadrant.setDifficulty(m_quadrant.getMainDifficulty()[value]);
	m_quadrant.setValue(m_quadrant.getMainValue()[value]);
}

//Data Input (Name, Difficulty, Attempts, Keypins, Limit, Prize Number, Id, Is Open, Is Broken)
void C_World::setLockpickables()
{
	S_Lockpickable lockpickableData;

	lockpickableData = {"Museum of the Fallen's Storage Door", "Easy", 0, 4, 12, METATELNIYA, m_lockpickable.size(), false, false};
	m_lockpickable.push_back(lockpickableData);

	lockpickableData = { "Pribetite Treasury Gate", "Average", 0, 5, 10, SICKLE, m_lockpickable.size(), false, false };
	m_lockpickable.push_back(lockpickableData);

	lockpickableData = { "Arbintskaya Federal Barracks Safebox", "Hard", 0, 6, 8, EMITTER, m_lockpickable.size(), false, false };
	m_lockpickable.push_back(lockpickableData);
}

//Data Input (Name, Difficulty, Word, Password, Attempts, Possibilities, Limit, Prize Type, Id, Is Unlocked, Is Blocked)
void C_World::setHackables()
{
	S_Hackable hackableData;
	int randomizer;
	vector<string> wordset;
	srand((int)time(0));

	wordset = { "parses","passer","spares","sparse","spears" };
	randomizer = rand() % 5 + 1;
	hackableData = { "Monument to the Heroes' Computer", "Easy", "aeprss", wordset[randomizer], 0, 5, 6, WEAPON, m_hackable.size(), false, false};
	m_hackable.push_back(hackableData);

	wordset = { "dearths","hardest","hatreds","threads","trashed" };
	randomizer = rand() % 5 + 1;
	hackableData = { "Hjadynivite Energy Development Complex's Server", "Average", "aedhrst", wordset[randomizer], 0, 5, 5, GARMENT, m_hackable.size(), false, false };
	m_hackable.push_back(hackableData);

	wordset = { "restrain","retrains","strainer","terrains","trainers" };
	randomizer = rand() % 5 + 1;
	hackableData = { "Churniv Power Plant's System", "Hard", "aeinrrst", wordset[randomizer], 0, 5, 4, EVENT, m_hackable.size(), false, false };
	m_hackable.push_back(hackableData);
}

void C_World::setInitializer()
{
	m_initializer = true;
}

void C_World::setExecuter()
{
	m_executer = false;
}

void C_World::setBattleValue(int value)
{
	m_battleValue = value;
}

C_Player C_World::getPlayer()
{
	return C_Player(m_player);
}

C_Quadrant C_World::getQuadrant()
{
	return C_Quadrant (m_quadrant);
}

C_Enemy C_World::getEnemy()
{
	return C_Enemy (m_enemy);
}

//Getter Definitions

vector<S_Lockpickable> C_World::getLockpickable()
{
	return vector<S_Lockpickable>(m_lockpickable);
}

vector<S_Hackable> C_World::getHackable()
{
	return vector<S_Hackable>(m_hackable);
}

vector<string> C_World::getCore()
{
	return vector<string>(m_core);
}

bool C_World::getInitializer()
{
	return m_initializer;
}

bool C_World::getExecuter()
{
	return m_executer;
}