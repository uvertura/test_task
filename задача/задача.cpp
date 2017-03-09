// задача.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#pragma warning(disable: 4996)
#include <conio.h>
#include <vector>
#include <algorithm>

#include "STUDENT_STRUCT.h"

#define FILE_NAME "1.txt"
#define RQ_CITY "Москва"
#define RQ_AVERAGE 5


using namespace std;

void printStudents(vector<Student> students, const char* title);
bool compare(Student const &a, Student const &b);

int main()
{
	setlocale(LC_ALL, "RUS");
		

	vector<Student> students;
	
#pragma region Чтение данных из файла

	FILE* f_ptr = fopen(FILE_NAME, "r");

	if (NULL == f_ptr) {
		cerr << "Не удалось отрыть файл для обработки.\n" << ferror(f_ptr) << endl;
		return -1;
	}

	while(!feof(f_ptr))
	{
		Student st;
		if (0 >= fscanf(f_ptr, "%s\n%s\n%d\n%d\n%d\n",
			&st.name, &st.city,
			&st.marks[0], &st.marks[1], &st.marks[2])) {
			break;
		}

		//Подсчет среднего бала
		st.average  = st.marks[0];
		st.average += st.marks[1];
		st.average += st.marks[2];
		st.average = round(st.average / 3);
		students.push_back(st);
	}
	fclose(f_ptr);

	size_t studentCount = students.size();
	if (0 == studentCount) {
		cout << "Файл не содержит данных для обработки" << endl;
		getch();
		return 0;
	}

#pragma endregion

	
	//Вывод данных до сортировки
	printStudents(students, "До сортировки");
	getch();

	//Сортировка
	sort(students.begin(), students.end(), compare);

	//Вывод данных после сортировки
	printStudents(students, "После сортировки");
	getch();

	return 0;
}
  
void printStudents(const vector<Student> students, const char* title) {
	cout << "\t\t" << title << ":\n\n";

	for (vector<Student>::const_iterator it = students.cbegin(); it < students.cend(); ++it) {
		cout << "Фамилия: " << it->name << endl
			<< "Город: " << it->city << endl
			<< "Оценки: "
			<< it->marks[0] << ' '
			<< it->marks[1] << ' '
			<< it->marks[2] << endl
			<< "Средний балл: " << it->average
			<< endl << endl;
	}
}

bool compare(Student const &a, Student const &b) {
	int weight = strcmp(a.name, b.name);
	if (RQ_AVERAGE <= a.average && 0 == strcmp(RQ_CITY, a.city))
		weight -= 1000;

	if (RQ_AVERAGE <= b.average && 0 == strcmp(RQ_CITY, b.city))
		weight += 1000;

	return 0 > weight;
}

