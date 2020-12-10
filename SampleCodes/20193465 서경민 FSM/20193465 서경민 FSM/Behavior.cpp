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
	cout << "���� ���� ����!" << endl;
}

void BattleState::Eat(character* c)
{
	cout << "������ ���� �� ����!" << endl;
}

void BattleState::Attack(character* c)
{
	cout << "�������� �̰��!!" << endl;

	setCharacterState(c, HungryState::GetInstance());
}

void BattleState::state(character* c)
{
	cout << "�޽��� ���� �� ����!" << endl;
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
	cout << "�ȱ�" << endl;
}

void MoveState::Eat(character* c)
{
	cout << "�Դ���" << endl;
}

void MoveState::Attack(character* c)
{
	cout << "�ú� �پ ����ߴ�!" << endl;

	setCharacterState(c, BattleState::GetInstance());
}

void MoveState::state(character* c)
{
	cout << "������!" << endl;

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
	cout << "�޽� ��, �ȴ���..." << endl;

	setCharacterState(c, MoveState::GetInstance());
}

void stateclass::Eat(character* c)
{
	cout << "�����鼭 �Դ���..." << endl;
}

void stateclass::Attack(character* c)
{
	cout << "�߻� ���� �߰�! �߻� ������ ���� �Ѵ�!!" << endl;

	setCharacterState(c, BattleState::GetInstance());
}

void stateclass::state(character* c)
{
	cout << "�� ���� �ʹ�..." << endl;
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
	cout << "�谡 ������..." << endl;
}

void HungryState::Eat(character* c)
{
	cout << "�Դ���..." << endl;

	setCharacterState(c, stateclass::GetInstance());
}

void HungryState::Attack(character* c)
{
	cout << "�谡 ���� ���Ϳ��� �׾���." << endl;

}

void HungryState::state(character* c)
{
	cout << "���� �� ã����..." << endl;
}
