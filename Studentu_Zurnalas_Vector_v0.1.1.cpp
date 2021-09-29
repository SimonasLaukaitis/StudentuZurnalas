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
int MedianOrFinalgrade; 

void generateGrades();

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
	Student(string name, string surname, double examGrade, int homeworkCount, int* pGrades) {
		this->name = name;
		this->surname = surname;
		this->homeworkCount = homeworkCount;
		this->examGrade = examGrade;

		for (int i = 0; i < homeworkCount; i++) {
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

	}

};




// Priskiriam statiniam kintamajam uz klases ribu reiksme
int Student::homeworkCount = 0; 

//KONSTANTA
const int objNumber = 2; 

//DINAMINEJ ATMINTY SUKURIU
Student* studentArray = new Student[objNumber];

//OBJEKTU KURIMO FUNKCIJA
void makeObj() { 
	
	for (int i = 0; i < objNumber; i++)
	{
		cout << (i + 1) << ". ***STUDENTAS***" << endl;
		studentArray[i].inputMethod();
	}
	
}

//generuoja pazymius(grazina vektoriu funkcijos pavidalu method()[i])
vector<int> generateGrades(int a) {
	vector<int> tempGrades;
	int x;

	//generuos random skaicius, kurie priklauso nuo sistemos laikrodzio
	srand(time(NULL)); 
	
	for (int i = 0; i < a; i++) {

		// generuoja atsitiktinius skaicius 0 - 10
		x = rand() % 11;
		tempGrades.push_back(x);
	}
	return tempGrades;
};

void printAllObjDetails() {
	for (int i = 0; i < 2; i++)
	{
		cout << (i + 1) << ". ";
		studentArray[i].printDetails(MedianOrFinalgrade);
	}
}

int main()
{
	/*cout << "\n****STUDENTU ZURNALAS V0.1****\n       SimonasLaukaitis©\n\n";
	cout << "Skaiciuosite:\n     1. Vidurki\n     2. Mediana" << endl;
	cin >> MedianOrFinalgrade;
	

	makeObj();

	system("CLS");

	cout << "   Vardas     Pavarde        Pazymiai" << endl;
	cout << "----------------------------------------------------------------------" << endl;

	printAllObjDetails();*/

	cout << "Sugeneruoti skaiciai" << endl;
	for(int i = 0; i < 10; i++) {
		cout <<i+1<<". "<< generateGrades(10)[i] << endl;
	}

	




	return 0;
};


