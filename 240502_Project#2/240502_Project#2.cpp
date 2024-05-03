#include <iostream>
#include <string>

#define NAME 0
#define AGE 1
#define BIRTH 2

using namespace std;

int main()
{
	// 1. 몇 명 입력할 것인지 묻기
	int num;

	cout << "몇 명 분량을 입력하시겠습니까?  ";
	cin >> num;

	// 2. 학생 수만큼 "이름, 나이, 생일" 순서로 한번에 입력받기 (공백으로 데이터 구분)
	string** student_inputArr = new string * [num];			//2차원 배열 선언 (일단 행을 생성)




	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번째 학생의 데이터를 이름, 나이, 생일 순서로 입력해주세요 ";

		student_inputArr[i] = new string[3];				// 이름,나이,생일 총 3개의 데이터를 받을테니, 한 행당 3개의 열을 생성하겠다는 뜻

		for (int j = 0; j < 3; j++)
		{
			cin >> student_inputArr[i][j];
		}
	}


	// 4번 (프로그램 종료) 버튼 누르기 전까지는 계속 반복되도록 작성
	// 버튼 입력 받을 변수 선언

	int selectMode = 0;

	while (selectMode != 4)
	{
		cout << endl;
		cout << "1)학생 정보 출력  2)평균 나이 계산  3)가장 빠른 생일 출력  4)프로그램 종료 중 실행할 모드를 선택해주세요  ";
		cin >> selectMode;

		// 1~4번의 입력을 받지 못할 경우
		while ((selectMode != 1) && (selectMode != 2) && (selectMode != 3) && (selectMode != 4))
		{
			cout << "실행할 수 없는 입력입니다. 1~4번 중에서 선택해주세요!";
			cin >> selectMode;
		}

		// 3. 학생 정보 출력
		if (selectMode == 1)
		{
			for (int i = 0; i < num; i++)
			{
				cout << endl;
				cout << student_inputArr[i][NAME] << " 님은 " << student_inputArr[i][AGE] << " 세이고, 생일은 " << student_inputArr[i][BIRTH] << "입니다." << endl;
			}

			selectMode = 0;		// 이걸 한번 실행하고 나면 selectMode 초기화
		}

		// 4. 평균 나이
		// student_inputArr[i][1]에 있는 값이 나이 관련된 값이므로, 이걸 이용하자.

		if (selectMode == 2)
		{
			float sum_age = 0;
			float avg_age = 0;

			for (int i = 0; i < num; i++)
			{
				sum_age += stoi(student_inputArr[i][AGE]);
			}

			avg_age = sum_age / num;

			cout << endl;
			cout << "평균 나이는 " << avg_age << "세 입니다." << endl;
			cout << endl;

			selectMode = 0;		// 이걸 한번 실행하고 나면 selectMode 초기화
		}

		// 5. 가장 빠른 생일 출력
		// student_inputArr[i][2]에 있는 값이 생일과 관련된 값이므로, 이걸 이용하자.

		if (selectMode == 3)
		{
			int* birth_day = new int[num];
			int fast_birth = 0;

			for (int i = 0; i < num; i++)
			{
				birth_day[i] = stoi(student_inputArr[i][BIRTH]);		// birth_day라는 배열을 만들어서 거기에 사람들의 생일 정보 저장

			}

			for (int i = 0; i < num; i++)
			{
				if (birth_day[i] <= birth_day[num - 1])
				{
					fast_birth = birth_day[i];
				}

				if (birth_day[i] > birth_day[num - 1])
				{
					fast_birth = birth_day[num - 1];
				}

				else break;
			}

			if (fast_birth < 1000)
			{
				cout << endl;
				cout << "가장 빠른 생일 : " << '0' << fast_birth << "," << endl;

				cout << endl;
			}

			else
			{
				cout << endl;
				cout << "가장 빠른 생일은 " << fast_birth << "입니다." << endl;
				cout << endl;
			}

			delete[] birth_day;

			selectMode = 0;		// 이걸 한번 실행하고 나면 selectMode 초기화
		}

		

	}
	return 0;

	for (int i = 0; i < 3; i++)			// 동적 배열, 열 해제
		delete[] student_inputArr[i];

	delete[] student_inputArr;			// 동적 배열, 행 해제
}