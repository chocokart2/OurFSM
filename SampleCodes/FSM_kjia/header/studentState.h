//student 상태와 관련한 헤더
#pragma once
#include <iostream>
#include "state.h"

using std::cout;
using std::endl;

class Student;

class TaskExecution : public State
{
	TaskExecution() {};
	TaskExecution(const TaskExecution&);
	TaskExecution& operator=(const TaskExecution&);
public:
	static TaskExecution* Instance();
	void Enter(Student* student) {};
	void Execute(Student* student);
	void Exit(Student* student);
};

class Study : public State
{
	Study() {};
	Study(const Study&);
	Study& operator=(const Study&);
public:
	static Study* Instance();
	void Enter(Student* student) {};
	void Execute(Student* student);
	void Exit(Student* student);
};

class Rest : public State
{
	Rest() {};
	Rest(const Rest&);
	Rest& operator=(const Rest&);
public:
	static Rest* Instance();
	void Enter(Student* student) {};
	void Execute(Student* student);
	void Exit(Student* student) {};
};
