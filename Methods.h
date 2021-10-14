#pragma once
#include "Libraries.h"

class Student {

public:
	string name;

	string surname;

	vector<int> grades;

	int examGrade;

	double finalGrade; //Vidurkis arba Medianas

	Student();

	Student(string, string, vector<int>, int);

	Student(const Student&);

	~Student();

	//VEIKIA KAIP KONSTRUKTORIUS
	void setAll(string, string, vector<int>, int);

	//OPERATORIAUS < OVERLOADINIMAS
	bool operator<(const Student&) const;

	string getName();

	string getSurname();

	vector<int> getGrades();

	int getExamGrade();

	double getFinalGrade();

	double getAvarageGrade();

	double getMedian();

	void setGrades(int);
	//DIDZIAUSIAS IVESTU PAZIMIU SKAICIUS
	void gradesCount();
};

__declspec(selectany) vector<Student> objVector; //__declspec(selectany) kad nesidubliuotu su kitais failaiss

// statinis kintamasis, kiek bus pazymiu
__declspec(selectany) int homeWorkCount; //__declspec(selectany) kad nesidubliuotu su kitais failais

__declspec(selectany) int MedianOrAvarage; //__declspec(selectany) kad nesidubliuotu su kitais failais //mediana rodysim, ar avg

__declspec(selectany) int objCount=1000; //__declspec(selectany) kad nesidubliuotu su kitais failais

//OBJEKTO KURIMAS IS INPUT
void makeObj();

//OBJEKTO KURIMAS GENERUOJANT
void makeGeneratedObj(int);

//ISVEDA VISUS OBJEKTUS (IS RAM)
void printAllObjDetails();

//PATAISO PAZYMIUS (VIETOJ TUSCIU VIETU IRASO NULIUS)
void gradesCorection();

//IRASO I TXT FAILA
void textDocumentIn();

//IS TXT FAILO I RAM
void textDocumentOut();


