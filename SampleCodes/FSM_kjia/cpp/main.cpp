//main 함수가 되는 부분
//클래스를 이용한 간단한 코드
#include <conio.h>
#include <iostream>
#include "student.h"
#include "studentstate.h"

using std::cout;
using std::endl;

int main()
{
	Student s;
	
	for (int i = 0; i < 30; ++i)
	{
		s.Update();
	}

	return 0;
}
