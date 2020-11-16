//student의 헤더
#pragma once
#include <iostream>
#include <cassert>		//assert() 함수 이용을 위한 포함 student.cpp에서 이용

using std::cout;
using std::endl;

const int maxTired = 5;

class State;

class Student
{
	State* s_state;
	int s_taskExecution;
	int s_fatigue;
	int s_knowledge;
public:
	Student();

	void ChangeState(State* s_newState);

	void Update();

	int Study() { return s_knowledge; }
	void setStudy(int s_k) { s_knowledge = s_k; }

	void AddKnowledge(const int val) { s_knowledge += val; }
	int KnowledgeValue()const { return s_knowledge; }

	void AddtaskExecution(const int val) { s_taskExecution += val; }
	int taskExecutionValue()const { return s_taskExecution; }

	void DecreaseFatigue() { s_fatigue -= 1; }
	void IncreaseFatigue() { s_fatigue += 1; }
	bool Overwork()const
	{
		if (s_fatigue > maxTired) { return true; }
		return false;
	}
};
