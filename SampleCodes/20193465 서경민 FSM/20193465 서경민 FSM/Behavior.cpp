#include "characterState.h"
#include<iostream>
using namespace std;

BattleState* BattleState::instance;
MoveState* MoveState::instance;
HungryState* HungryState::instance;
stateclass* stateclass::instance;

BattleState* BattleState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BattleState();
	}

	return instance;
}

void BattleState::Move(character* c)
{
	cout << "피할 수가 없다!" << endl;
}

void BattleState::Eat(character* c)
{
	cout << "지금은 먹을 수 없다!" << endl;
}

void BattleState::Attack(character* c)
{
	cout << "전투에서 이겼다!!" << endl;

	setCharacterState(c, HungryState::GetInstance());
}

void BattleState::state(character* c)
{
	cout << "휴식을 취할 수 없다!" << endl;
}


MoveState* MoveState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MoveState();
	}

	return instance;
}

void MoveState::Move(character* c)
{
	cout << "걷기" << endl;
}

void MoveState::Eat(character* c)
{
	cout << "먹는중" << endl;
}

void MoveState::Attack(character* c)
{
	cout << "시비가 붙어서 대결했다!" << endl;

	setCharacterState(c, BattleState::GetInstance());
}

void MoveState::state(character* c)
{
	cout << "쉬는중!" << endl;

	setCharacterState(c, stateclass::GetInstance());
}


stateclass* stateclass::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new stateclass();
	}

	return instance;
}

void stateclass::Move(character* c)
{
	cout << "휴식 끝, 걷는중..." << endl;

	setCharacterState(c, MoveState::GetInstance());
}

void stateclass::Eat(character* c)
{
	cout << "걸으면서 먹는중..." << endl;
}

void stateclass::Attack(character* c)
{
	cout << "야생 동물 발견! 야생 동물을 공격 한다!!" << endl;

	setCharacterState(c, BattleState::GetInstance());
}

void stateclass::state(character* c)
{
	cout << "더 쉬고 싶다..." << endl;
}


HungryState* HungryState::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new HungryState();
	}

	return instance;
}

void HungryState::Move(character* c)
{
	cout << "배가 고프다..." << endl;
}

void HungryState::Eat(character* c)
{
	cout << "먹는중..." << endl;

	setCharacterState(c, stateclass::GetInstance());
}

void HungryState::Attack(character* c)
{
	cout << "배가 고파 몬스터에게 죽었다." << endl;

}

void HungryState::state(character* c)
{
	cout << "먹을 걸 찾는중..." << endl;
}
