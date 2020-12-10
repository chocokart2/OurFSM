#pragma once
#include"character.h"

class characterState
{
public:
	virtual void Move(character* c) = 0;
	virtual void Eat(character* c) = 0;
	virtual void Attack(character* c) = 0;
	virtual void state(character* c) = 0;
protected:
	void setCharacterState(character* c, characterState* s)
	{
		c->setState(s);
	}
};

class MoveState :public characterState
{
	static MoveState* instance;
public:
	static MoveState* GetInstance();

	virtual void Move(character* c);
	virtual void Eat(character* c);
	virtual void Attack(character* c);
	virtual void state(character* c);
};

class stateclass :public characterState
{
	static stateclass* instance;
public:
	static stateclass* GetInstance();

	virtual void Move(character* c);
	virtual void Eat(character* c);
	virtual void Attack(character* c);
	virtual void state(character* c);
};

class BattleState :public characterState
{
	static BattleState* instance;
public:
	static BattleState* GetInstance();

	virtual void Move(character* c);
	virtual void Eat(character* c);
	virtual void Attack(character* c);
	virtual void state(character* c);
};

class HungryState :public characterState
{
	static HungryState* instance;
public:
	static HungryState* GetInstance();

	virtual void Move(character* c);
	virtual void Eat(character* c);
	virtual void Attack(character* c);
	virtual void state(character* c);
};
