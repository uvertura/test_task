#pragma once
#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H

/*
 ��������� ����������� 
 ���������� � �������� 
*/
struct Student {
	/*���*/
	char name[60];

	/*�����*/
	char city[60];

	/*������*/
	int  marks[3];

	/*������� ���*/
	float average = 0;

};

#endif // !STUDENT_STRUCT_H


