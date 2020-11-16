//student 상태 구현
#include <iostream>
#include "state.h"
#include "studentstate.h"
#include "student.h"

using std::cout;
using std::endl;

TaskExecution* TaskExecution::Instance()
{
	static TaskExecution instance;
	return &instance;
}

void TaskExecution::Execute(Student* student)
{
	student->AddKnowledge(1);
	student->AddtaskExecution(1);
	student->IncreaseFatigue();
	cout << "과제중..." << endl;
	if (student->Overwork())
	{
		student->ChangeState(Rest::Instance());
	}
}

void TaskExecution::Exit(Student* student)
{
	cout << "과제 제출! 열심히 과제를 했다!" << endl;
	cout << "제출한 과제의 수 : " << student->taskExecutionValue() << endl;
}

Study* Study::Instance()
{
	static Study instance;
	return &instance;
}

void Study::Execute(Student* student)
{
	student->AddKnowledge(5);
	student->IncreaseFatigue();
	cout << "공부중..." << endl;
	if (student->Overwork())
	{
		student->ChangeState(Rest::Instance());
	}
}

void Study::Exit(Student* student)
{
	cout << "공부 끝! 열심히 했다!" << endl;
	cout << "현재까지의 지식 : " << student->KnowledgeValue() << endl;
}

Rest* Rest::Instance()
{
	static Rest instance;
	return &instance;
}

void Rest::Execute(Student* student)
{
	if (!student->Overwork())
	{
		cout << "충분히 휴식했다. 무엇을 할까?" << endl;
		if (student->taskExecutionValue() < 5)
			student->ChangeState(TaskExecution::Instance());
		else
			student->ChangeState(Study::Instance());
	}
	else
	{
		student->DecreaseFatigue();
		cout << "휴식중..." << endl;
	}
}
