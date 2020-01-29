#include "Klasy_funkcje.h"
#include "Windows.h"
#include <iostream>
#include <string>
using namespace std;
Character::~Character() {}
void Character::showstats()
{
	cout << "\t\t\t\t" << name << " Stats: " << endl;
	cout << "Lvl:        " << lvl << endl;
	cout << "Hp:         " << hp << endl;
	cout << "Attack:     " << attack << endl;
	cout << "Experiance: " << exp << endl;
	cout << "Money:      " << coins << " Coins" << endl;
}
void Character::changename(string a)
{
	name = a;
}
void Character::changestats(double a)
{
	hp *= a;
	coins *= a;
	attack *= a;
	lvl = a;
}
void Character::Heal() {
}
void Hero::Heal() {
	hp = 10 * lvl;
}
void Enemy::Heal() {
	hp = 5 * lvl;
}
void Character::changeexp(double a) {
	exp = a;
}
void Character::changecoins(double a) {
	coins = a;
}
void Character::lvlup(double a)
{
	changestats(a);
}
void Character::showstats(char b)
{
	char a = b;
	cout << "\t\t\t\t" << name << " Stats: " << endl;
	switch (a) {
	case 'l':cout << "Lvl:        " << lvl << endl; break;
	case 'h':cout << "Hp:         " << hp << endl; break;
	case 'a':cout << "Attack:     " << attack << endl; break;
	case 'e':cout << "Experiance: " << exp << endl; break;
	case 'c':cout << "Money:      " << coins << " Coins" << endl; break;
	}
}
void Character::Attack(Character& dealer, Character& victim)
{
	cout << "Character " << victim.name << " received damage: \t " << dealer.attack << " (hp:" << victim.hp-dealer.attack << ')' << endl;
	victim.hp -= dealer.attack;
	if (victim.hp <= 0) {
		cout << "Character " << victim.name << " died." << endl;
		cout << "Character " << dealer.name << " got " << victim.lvl << " experiance." << endl;
		cout << "Character " << dealer.name << " got " << victim.coins << " coins." << endl;
		dealer.exp += victim.lvl;
		dealer.coins += victim.coins;
		victim.coins = 0;
	}
	if (dealer.exp >= 5 * dealer.lvl) {
		dealer.exp = dealer.exp - (dealer.lvl * 5);
		dealer.lvlup(dealer.lvl + 1);
		cout << "Character " << dealer.name << " leveled up to lvl: (" << dealer.lvl << ')' << endl;
	}
	if (victim.hp > 0)
	{
		Sleep(500);
		Attack(victim, dealer);
	}
}
