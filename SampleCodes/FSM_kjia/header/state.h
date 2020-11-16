//상태에 관한 헤더
#pragma once
#include <iostream>
class Student;

class State
{
public:
	virtual void Enter(Student*) = 0;		//상태에 들어감
	virtual void Execute(Student*) = 0;		//상태에서의 행동
	virtual void Exit(Student*) = 0;		//상태에서 나감
};
