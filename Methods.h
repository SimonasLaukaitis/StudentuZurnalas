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

__declspec(selectany) list<Student> objVector; //__declspec(selectany) kad nesidubliuotu su kitais failaiss

__declspec(selectany) list<Student> galvociai, nuskriaustukai;

// statinis kintamasis, kiek bus pazymiu
__declspec(selectany) int homeWorkCount; //__declspec(selectany) kad nesidubliuotu su kitais failais

__declspec(selectany) int MedianOrAvarage; //__declspec(selectany) kad nesidubliuotu su kitais failais //mediana rodysim, ar avg

__declspec(selectany) int objCount = 2; //__declspec(selectany) kad nesidubliuotu su kitais failais



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

//RUSIUOJAM I GALVOCIUS IR NUSKRIAUSTUKUS
void textDpcumentInTwoFiles();

//IS TXT FAILO I RAM
void textDpcumentOutTwoFiles();

//ISVALO VISUS TXT FAILUS
void cleanAllFiles();

void studentSortingInTwoCategories();

void studentWritingInTwoFilesFromVector();

//failo nuskaitymas miksuotai per buferi
void bufer_nusk(std::string read_vardas);
