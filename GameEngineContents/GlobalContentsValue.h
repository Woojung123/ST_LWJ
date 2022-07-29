#pragma once
//#include "Player.h"
//#include "Monster.h"

enum class OBJECTORDER
{
	Player,
	Monster,
	BackGround,
	Camera,
	Bullet,
	Effect,
	UI = 1000,
};


typedef struct UnitInfo
{
	int m_Hp;
	int m_MaxHp;
	int Gold;
	int Dammage;


}UINFO;


// Ό³Έν :
class GlobalContentsValue
{
public:
	class Enums 
	{
	};

	class Actors 
	{
	public:
		//static Monster* TestMonster;

	private:
		Actors() {		}
		~Actors() {		}
	};

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

