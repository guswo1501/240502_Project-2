#include <iostream>
#include <string>

#define NAME 0
#define AGE 1
#define BIRTH 2

using namespace std;

int main()
{
	// 1. �� �� �Է��� ������ ����
	int num;

	cout << "�� �� �з��� �Է��Ͻðڽ��ϱ�?  ";
	cin >> num;

	// 2. �л� ����ŭ "�̸�, ����, ����" ������ �ѹ��� �Է¹ޱ� (�������� ������ ����)
	string** student_inputArr = new string * [num];			//2���� �迭 ���� (�ϴ� ���� ����)




	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "��° �л��� �����͸� �̸�, ����, ���� ������ �Է����ּ��� ";

		student_inputArr[i] = new string[3];				// �̸�,����,���� �� 3���� �����͸� �����״�, �� ��� 3���� ���� �����ϰڴٴ� ��

		for (int j = 0; j < 3; j++)
		{
			cin >> student_inputArr[i][j];
		}
	}


	// 4�� (���α׷� ����) ��ư ������ �������� ��� �ݺ��ǵ��� �ۼ�
	// ��ư �Է� ���� ���� ����

	int selectMode = 0;

	while (selectMode != 4)
	{
		cout << endl;
		cout << "1)�л� ���� ���  2)��� ���� ���  3)���� ���� ���� ���  4)���α׷� ���� �� ������ ��带 �������ּ���  ";
		cin >> selectMode;

		// 1~4���� �Է��� ���� ���� ���
		while ((selectMode != 1) && (selectMode != 2) && (selectMode != 3) && (selectMode != 4))
		{
			cout << "������ �� ���� �Է��Դϴ�. 1~4�� �߿��� �������ּ���!";
			cin >> selectMode;
		}

		// 3. �л� ���� ���
		if (selectMode == 1)
		{
			for (int i = 0; i < num; i++)
			{
				cout << endl;
				cout << student_inputArr[i][NAME] << " ���� " << student_inputArr[i][AGE] << " ���̰�, ������ " << student_inputArr[i][BIRTH] << "�Դϴ�." << endl;
			}

			selectMode = 0;		// �̰� �ѹ� �����ϰ� ���� selectMode �ʱ�ȭ
		}

		// 4. ��� ����
		// student_inputArr[i][1]�� �ִ� ���� ���� ���õ� ���̹Ƿ�, �̰� �̿�����.

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
			cout << "��� ���̴� " << avg_age << "�� �Դϴ�." << endl;
			cout << endl;

			selectMode = 0;		// �̰� �ѹ� �����ϰ� ���� selectMode �ʱ�ȭ
		}

		// 5. ���� ���� ���� ���
		// student_inputArr[i][2]�� �ִ� ���� ���ϰ� ���õ� ���̹Ƿ�, �̰� �̿�����.

		if (selectMode == 3)
		{
			int* birth_day = new int[num];
			int fast_birth = 0;

			for (int i = 0; i < num; i++)
			{
				birth_day[i] = stoi(student_inputArr[i][BIRTH]);		// birth_day��� �迭�� ���� �ű⿡ ������� ���� ���� ����

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
				cout << "���� ���� ���� : " << '0' << fast_birth << "," << endl;

				cout << endl;
			}

			else
			{
				cout << endl;
				cout << "���� ���� ������ " << fast_birth << "�Դϴ�." << endl;
				cout << endl;
			}

			delete[] birth_day;

			selectMode = 0;		// �̰� �ѹ� �����ϰ� ���� selectMode �ʱ�ȭ
		}

		

	}
	return 0;

	for (int i = 0; i < 3; i++)			// ���� �迭, �� ����
		delete[] student_inputArr[i];

	delete[] student_inputArr;			// ���� �迭, �� ����
}