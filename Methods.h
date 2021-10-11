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

static vector<Student> objVector;

// statinis kintamasis, kiek bus pazymiu
static int homeWorkCount; //static kad nesidubliuotu su kitais failais

static int MedianOrAvarage; //static kad nesidubliuotu su kitais failais //mediana rodysim, ar avg

static int objCount; //objektu skaicius static kad nesidubliuotu su kitais failais

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


 