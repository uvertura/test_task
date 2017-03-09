#pragma once
#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H

/*
 Структкра описывающая 
 информацию о студенте 
*/
struct Student {
	/*ФИО*/
	char name[60];

	/*Город*/
	char city[60];

	/*Оценки*/
	int  marks[3];

	/*Средний бал*/
	float average = 0;

};

#endif // !STUDENT_STRUCT_H


