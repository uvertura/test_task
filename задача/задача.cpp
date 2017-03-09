// ������.cpp: ���������� ����� ����� ��� ����������� ����������.
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
#define RQ_CITY "������"
#define RQ_AVERAGE 5


using namespace std;

void printStudents(vector<Student> students, const char* title);
bool compare(Student const &a, Student const &b);

int main()
{
	setlocale(LC_ALL, "RUS");
		

	vector<Student> students;
	
#pragma region ������ ������ �� �����

	FILE* f_ptr = fopen(FILE_NAME, "r");

	if (NULL == f_ptr) {
		cerr << "�� ������� ������ ���� ��� ���������.\n" << ferror(f_ptr) << endl;
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

		//������� �������� ����
		st.average  = st.marks[0];
		st.average += st.marks[1];
		st.average += st.marks[2];
		st.average = round(st.average / 3);
		students.push_back(st);
	}
	fclose(f_ptr);

	size_t studentCount = students.size();
	if (0 == studentCount) {
		cout << "���� �� �������� ������ ��� ���������" << endl;
		getch();
		return 0;
	}

#pragma endregion

	
	//����� ������ �� ����������
	printStudents(students, "�� ����������");
	getch();

	//����������
	sort(students.begin(), students.end(), compare);

	//����� ������ ����� ����������
	printStudents(students, "����� ����������");
	getch();

	return 0;
}
  
void printStudents(const vector<Student> students, const char* title) {
	cout << "\t\t" << title << ":\n\n";

	for (vector<Student>::const_iterator it = students.cbegin(); it < students.cend(); ++it) {
		cout << "�������: " << it->name << endl
			<< "�����: " << it->city << endl
			<< "������: "
			<< it->marks[0] << ' '
			<< it->marks[1] << ' '
			<< it->marks[2] << endl
			<< "������� ����: " << it->average
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

