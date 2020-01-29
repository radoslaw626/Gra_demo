#pragma once
#include <iostream>
using namespace std;
class Character
{
public:
	double hp = 0, coins = 0, attack = 0, exp = 0, lvl = 0;
	string name;
	virtual void showstats();
	virtual void showstats(char a);
	virtual void changestats(double a);
	virtual void changecoins(double a);
	virtual void lvlup(double a);
	virtual void changename(string a);
	virtual void changeexp(double a);
	virtual void Attack(Character&, Character&);
	virtual void Heal();
	~Character();
};
class Hero :public Character
{
public:
	Hero(string  Name = " ", double Hp = 10, double Coins = 15, double Attack = 1, double Exp = 0, double Lvl = 1)
	{
		name = Name;
		hp = Hp;
		coins = Coins;
		attack = Attack;
		exp = Exp;
		lvl = Lvl;
	}
	void Heal();
};

class Enemy :public Character
{
public:
	Enemy(string  Name = "Wolf", double Hp = 4, double Coins = 15, double Attack = 1, double Exp = 0, double Lvl = 1)
	{
		name = Name;
		hp = Hp;
		coins = Coins;
		attack = Attack;
		exp = Exp;
		lvl = Lvl;
	}
	void Heal();
};