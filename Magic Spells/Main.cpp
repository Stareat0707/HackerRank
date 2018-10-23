#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Spell
{
public:
	Spell() :
		scrollName("")
	{
	}

	Spell(string name) :
		scrollName(name)
	{
	}

	virtual ~Spell()
	{
	}

	string revealScrollName()
	{
		return scrollName;
	}

private:
	string scrollName;
};

class Fireball :
	public Spell
{
public:
	Fireball(int power) :
		power(power)
	{
	}

	void revealFirepower()
	{
		cout << "Fireball: " << power << endl;
	}

private:
	int power;
};

class Frostbite :
	public Spell
{
public:
	Frostbite(int power) :
		power(power)
	{
	}

	void revealFrostpower()
	{
		cout << "Frostbite: " << power << endl;
	}

private:
	int power;
};

class Thunderstorm :
	public Spell
{
public:
	Thunderstorm(int power) :
		power(power)
	{
	}

	void revealThunderpower()
	{
		cout << "Thunderstorm: " << power << endl;
	}

private:
	int power;
};

class Waterbolt :
	public Spell
{
public:
	Waterbolt(int power) :
		power(power)
	{
	}

	void revealWaterpower()
	{
		cout << "Waterbolt: " << power << endl;
	}

private:
	int power;
};

class SpellJournal
{
public:
	static string journal;
	static string read()
	{
		return journal;
	}
};

string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
	if (dynamic_cast<Fireball*>(spell) != nullptr)
		dynamic_cast<Fireball*>(spell)->revealFirepower();
	else if (dynamic_cast<Frostbite*>(spell) != nullptr)
		dynamic_cast<Frostbite*>(spell)->revealFrostpower();
	else if (dynamic_cast<Waterbolt*>(spell) != nullptr)
		dynamic_cast<Waterbolt*>(spell)->revealWaterpower();
	else if (dynamic_cast<Thunderstorm*>(spell) != nullptr)
		dynamic_cast<Thunderstorm*>(spell)->revealThunderpower();
	else
	{
		string temp;
		int result = 0;
		int point = 0;
		string scrollName = spell->revealScrollName();
		for (int i = 0; i < SpellJournal::journal.size(); ++i)
		{
			for (int j = 0; j < scrollName.size(); ++j)
			{
				if (SpellJournal::journal[i] == scrollName[j])
				{
					temp += scrollName[j];
					scrollName.erase(j, 1);
					++result;
					point = j + 1;
					break;
				}
			}
		}
		cout << temp << endl;
		cout << result << endl;
	}
}

class Wizard
{
public:
	Spell* cast()
	{
		string s;
		cin >> s;

		int power;
		cin >> power;

		Spell *spell;
		if (s == "fire")
			spell = new Fireball(power);
		else if (s == "frost")
			spell = new Frostbite(power);
		else if (s == "water")
			spell = new Waterbolt(power);
		else if (s == "thunder")
			spell = new Thunderstorm(power);
		else
		{
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}

		return spell;
	}
};

int main()
{
	int t;
	cin >> t;
	Wizard Arawn;
	while (t--)
	{
		Spell* spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}