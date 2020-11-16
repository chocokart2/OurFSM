//student 구현
#include <iostream>
#include "student.h"
#include "studentstate.h"

Student::Student() :s_state(Rest::Instance()), s_fatigue(0), s_knowledge(0), s_taskExecution(0) {}


void Student::ChangeState(State* s_newState)
{
	assert(s_state && s_newState);	//오류 검출 함수
	s_state->Exit(this);
	s_state = s_newState;
	s_state->Enter(this);
}

void Student::Update()
{
	if (s_state)
		s_state->Execute(this);
}
