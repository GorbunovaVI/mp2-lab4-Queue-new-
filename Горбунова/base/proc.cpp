#include "queue.h"
#include "JobStream.h"
#include <conio.h>
#include <iostream>  
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	double A;
	int VAL;
	int key = 10;
	int key_on = 0;
	double done_task = 0;  //количество выполненных задач
	double count_task = 0; //количество задач в очереди
	double stop_tact = 0;  //количество тактов простоя
	double all_tact = 0;   //количество тактов
	double no_task = 0;    //количество задач получивших отказ
	Queue N(MaxSize);
	int tact_have = 0;

	cout << endl << "Введите вероятность создания задачи(от 0 до 1): ";
	cin >> A;
	cout << endl << "Введите масимальное количество тактов: ";
	cin >> VAL;
	cout << endl << "Нажмите любую клавишу, чтобы остановить выполнение программы" << endl;
	while (!_kbhit())
	{
		if (!key) key_on = 1;
		all_tact++;
		JobStream JobStream(rand() % VAL + 1);
		double B = (double)(rand()) / RAND_MAX * 1;

		if (B > A)
		{
			if ((N.IsFull())) no_task++;
			else
			{
				N.put(JobStream.get_need());
			}
		}

		if (N.IsEmpty()) stop_tact++;
		else if (N.top() == tact_have)
		{
			done_task++;
			N.get();
			tact_have = 0;
			stop_tact++;
			if (key_on == 1) break;
		}
		else
		{
			tact_have++;
		}
		count_task = N.get_size();
	}

	cout << "количество выполненных задач: " << done_task << endl;
	cout << "количество задач в очереди: " << count_task << endl;
	cout << "количество тактов простоя: " << stop_tact << endl;
	cout << "общее количество тактов: " << all_tact << endl;
	cout << "количество задач, получивших отказ: " << no_task << endl;
	system("pause");
	return 0;
}