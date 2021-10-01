// Studentu_Zurnalas.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//                                  ****MOKINIU ZURNALAS v0.1****
//

#include <iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

static int varGradesCount;

//Mediano arba Vidurkio skaiciavimui
int MedianOrFinalgrade = 0; 

int generateExamGrade();

vector<int> generateGrades(int);



class Student {
public:

	string name;
	string surname;
	static int homeworkCount; // statinis kintamasis
	double examGrade = 0;
	vector<int> grades;



	//konstruktorius be parametru
	Student() {};
	//konstruktorius su parametrais
	Student(string name, string surname, double examGrade, int homeworkCount, vector<int> pGrades) {
		this->name = name;
		this->surname = surname;
		this->homeworkCount = homeworkCount;
		this->examGrade = examGrade;

		for (int i = 0; i < pGrades.size(); i++) {
			grades[i] = pGrades[i];
		}

	}

	//kopijavimo konstruktorius
	Student(Student& p) {
		name = p.name;
		surname = p.surname;
		homeworkCount = p.homeworkCount;
		examGrade = p.examGrade;

		for (int i = 0; i < homeworkCount; i++) {
			grades[i] = p.grades[i];
		}
	}



	
	//vidurkis
	double getFinalGrade() { 
		double sum = 0;
		for (int i = 0; i < grades.size(); i++) {
			sum += grades[i];
		}

		return 0.4 * (sum / grades.size()) + 0.6 * examGrade;
	}

	//medianas
	double getMedian() {
	    double median;
		auto n = grades.size();
	    
	    sort(grades.begin(), grades.end());
			
	    median = grades[(grades.size() / 2)];
	   
		median = (grades[n / 2] + grades[(n - 1) / 2]) / 2.0;
	    
	    return median;
	}

	//vieno studento duomenys (senas)
	void getStudent() {
		cout << name << " " << surname << " Pazymiai: ";
		for (int i = 0; i < grades.size(); i++) {
			cout << " " << grades[i];
		}
		cout << " Egzaminas " << examGrade << " Vidurkis " << getFinalGrade() <<" Medianas: "<<getMedian() << endl;
	}

	//studento duomenys 1 vidurkis, 2 medianas
	void printDetails(int x) {

		if (x == 1) {

			cout << left << setw(9) << name << " " << setw(15) << surname << setw(5) << " Pazymiai: ";
			for (int i = 0; i < varGradesCount; i++) {

				if (i < grades.size()) {
					cout << setw(3) << grades[i];
				}
				else {
					cout << setw(3) << 0;
					grades.push_back(0);
				}
			}
			cout << setw(5) << "Egzaminas: " << setw(4) << examGrade << setw(15) << " Galutinis ivertinimas: " << setprecision(2) << fixed << getFinalGrade() << setprecision(0) << endl;
		}

		else if (x == 2) {
			cout << left << setw(9) << name << " " << setw(15) << surname << setw(5) << " Pazymiai: ";

			for (int i = 0; i < varGradesCount; i++) {
				if (i < grades.size()) {
					cout << setw(3) << grades[i];
				}

				else {
					cout << setw(3) << 0;
					grades.push_back(0);
				}
			}
			cout << setw(5) << "Egzaminas: " << setw(4) << examGrade << setw(15) << " Medianas: " << setprecision(2) << fixed << getMedian() << setprecision(0) << endl;
		}
	}

	//ivedimas
	void inputMethod() {
		int input = 0;

		cout << "Iveskite studento varda ir pavarde: ";
		cin >> name >> surname;
		cout << "\nSurasykite pazymius( jei norite nutraukti, iveskite -1): " << endl;


		for (int i = 0; true; i++) {

			cout << "Pazymys nr" << i + 1 << ": ";
			cin >> input;
			if (input == -1) { break; }
			grades.push_back(input);
			gradesCount();

		}

		cout << "\nIveskite egzamino pazymi: ";
		cin >> examGrade;
	}

	//Generuotas pazymiu ir egzamino ivedimas
	void inputGeneratedMethod() {
		int temp;
		
		name = "Vardas";
		surname = "Pavarde";
		for (int i = 0; i < generateGrades(4).size(); i++) {
			temp = generateGrades(4)[i];
			grades.push_back(temp);
		}
					
		examGrade = generateExamGrade();
		gradesCount();
	}

	//destruktorius (dar paziureti)
	~Student() {

		// delete[] grades;
		 // isvalom atminti(masyvas grades[])
		cout << "DESTRUKTORIUS ISKVIESTAS" << endl;

		//for (int i = 0; i < homeworkCount; i++) {
		//     delete[i] grades;
		//  }




	}

	//pazymiu skaicius
	void gradesCount() {

		if (varGradesCount < grades.size()) {
			varGradesCount = grades.size();
		}
		else { varGradesCount = grades.size(); }

	}

};




// Priskiriam statiniam kintamajam uz klases ribu reiksme
int Student::homeworkCount = 0; 

//KONSTANTA
const int objNumber = 2; 

//DINAMINEJ ATMINTY SUKURIU
Student* studentArray = new Student[objNumber];



//generuoja pazymius(grazina vektoriu funkcijos pavidalu method()[i])
vector<int> generateGrades(int a) {
	vector<int> tempGrades;
	int x;

	for (int i = 0; i < a; i++) {

		// generuoja atsitiktinius skaicius 0 - 10
		x = rand() % 11;
		tempGrades.push_back(x);
	}
	return tempGrades;
};
//Generuoja egzamino pazimi
int generateExamGrade() {
	int temp;
	
	temp = rand() % 11;
	return temp;
	
}

//OBJEKTU KURIMO FUNKCIJA
void makeObj() {

	for (int i = 0; i < objNumber; i++)
	{
		cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;
		studentArray[i].inputMethod();
	}

}

//Generuotu objektu kurimo funkcija
void makeGeneratedObj() {
	for (int i = 0; i < objNumber; i++)
	{
		cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;
		studentArray[i].inputGeneratedMethod();
	}
}

void printAllObjDetails() {
	for (int i = 0; i < objNumber; i++)
	{
		cout << (i + 1) << ". ";
		studentArray[i].printDetails(MedianOrFinalgrade);
	}
}

int main()
{	//srand funkcijos atskaitos taskas
	srand(time(NULL));

	int choose;

	cout << "\n****STUDENTU ZURNALAS V0.1****\n       SimonasLaukaitis©\n\n";

	cout << " DEMO  MODE 1.\nNORMAL MODE 2." << endl;
	cin >> choose;

	cout << "Skaiciuosite:\n     1. Vidurki\n     2. Mediana" << endl;
	cin >> MedianOrFinalgrade;
	
	if (choose == 1) {
		makeGeneratedObj();
	}
	else if (choose == 2) {
		makeObj();
	}
	
	

	system("CLS");

	cout << "   Vardas     Pavarde        Pazymiai" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	printAllObjDetails();

	return 0;
};


