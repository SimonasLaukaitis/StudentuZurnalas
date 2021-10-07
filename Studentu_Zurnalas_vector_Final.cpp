// Studentu_Zurnalas.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//                                  ****MOKINIU ZURNALAS v0.1****
//

#include <iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;
// statinis kintamasis, kiek bus pazymiu
static int homeWorkCount; 
static int MedianOrAvarage = 2; //mediana rodysim, ar avg

class Student {
public:
    string name;
    string surname;
    vector<int> grades;
    int examGrade = 0;
    double finalGrade = 0; //Vidurkis arba Medianas

    //konstruktorius be parametru
    Student() {};

    //konstruktorius su parametrais
    Student(string name, string surname, vector<int> pGrades, int examGrade ) {
        this->name = name;
        this->surname = surname;
        for (int i = 0; i < pGrades.size(); i++) {
            grades[i] = pGrades[i];
        }
        this->examGrade = examGrade;
        this->finalGrade = finalGrade;

        pGrades.clear();
    }

    
    //kopijavimp konstruktorius
    Student(Student& p) {
        name = p.name;
        surname = p.surname;
        examGrade = p.examGrade;
        

        for (int i = 0; i < homeWorkCount; i++) {
            grades[i] = p.grades[i];
        }
    }

    //destruktorius
    ~Student() {
        grades.clear();
    }

    //konstruktoriaus atskira funkcija
    void setAll(string name, string surname, vector<int> pGrades, int examGrade) {
        this->name = name;
        this->surname = surname;
        
            grades = pGrades;

            //for (int i = 0; i < grades.size(); i++){ std::cout << grades[i] << " "; }
               
            pGrades.clear();

        
        this->examGrade = examGrade;

        //Skaiciuoja mediana arba avg
        if (MedianOrAvarage == 1) {
            finalGrade = getAvarageGrade();
        }
        else if(MedianOrAvarage == 2){
            finalGrade = getMedian();
        }
    }

    string getName() {
        return name;
    }

    string getSurname() {
        return surname;
    }

    vector<int> getGrades() {
        return grades;
    }

    int getExamGrade() {
        return examGrade;
    }

    double getFinalGrade() {
        return finalGrade;
    }

    //Vidurkio skaiciavimas
    double getAvarageGrade() {
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

    void setGrades(int a) {
        grades.push_back(a);
    }

    //pazymiu skaicius
    void gradesCount() {

        if (homeWorkCount < grades.size())
        {
            homeWorkCount = grades.size();
        }
        else
        {
            homeWorkCount = homeWorkCount;
        }
        //cout << "Objekte GradesCount: " << varGradesCount << endl;
    }
};



static int objCount = 100; //objektu skaicius

//DINAMINEJ ATMINTY SUKURIU
Student* studentArray = new Student[objCount];

//IVESTI OBJEKTUS
void makeObj() {

    int input = 0;
    string tempName;
    string tempSurname;
    vector<int> tempGrades;
    int tempExamGrade = 0;
    double tempFinalGrade = 0; //Vidurkis arba Medianas

    for (int i = 0; i < objCount; i++)
    {   
        

        std::cout << "Iveskite studento varda ir pavarde: ";
        cin >> tempName >> tempSurname;
        std::cout << "\nSurasykite pazymius( jei norite nutraukti, iveskite -1): " << endl;


        for (int i = 0; true; i++) {

            std::cout << "Pazymys nr" << i + 1 << ": ";
            cin >> input;
            if (input == -1) { break; }
            tempGrades.push_back(input); //REIKIA ISVALYTI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
           
        }

        std::cout << "\nIveskite egzamino pazymi: ";
        cin >> tempExamGrade;

        studentArray[i].setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        std::cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;

    }
    tempGrades.clear(); // ISVALOM TEMP GRADES VEKTORIU
}

//GENERUOTI OBJEKTUS
void makeGeneratedObj(int grad) {
    int input = 0;
    int x;
    string tempName;
    string tempSurname;
    vector<int> tempGrades;  //ISVALYTI!!!!!!!!!
    int tempExamGrade = 0;
    double tempFinalGrade = 0; //Vidurkis arba Medianas

    

    for (int i = 0; i < objCount; i++)
    {   
        tempName = "Vardas";
        tempSurname = "Pavarde";

        for (int j = 0; j < grad; j++) { // gaminam random pazymius;

                // generuoja atsitiktinius skaicius 0 - 10
                x = rand() % 11;
                tempGrades.push_back(x);
               // cout << tempGrades[j] << " " << endl;
            }

        tempExamGrade = rand() % 11;

        //nustatom kiek bus pazymiu
        homeWorkCount = grad;

        studentArray[i].setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        std::cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;
        

        tempGrades.clear(); // isvalom laikinaji grades
    }
}

//ISVESTI VISUS OBJEKTUS ( IS RAM )
void printAllObjDetails() {

    for (int i = 0; i < objCount; i++)
    {
        if (MedianOrAvarage == 1) {

            std::cout << left << setw(9) << studentArray[i].getName() << " " << setw(15) << studentArray[i].getSurname() << setw(5) << " Pazymiai: ";
            for (int j = 0; j < studentArray[i].getGrades().size(); j++) {
                
                std::cout << setw(3) << studentArray[i].getGrades()[j];
                
            }
            std::cout << setw(5) << "Egzaminas: " << setw(4) << studentArray[i].getExamGrade() << setw(15) << " Galutinis (Vid): " << setprecision(2) << fixed << studentArray[i].getFinalGrade() << setprecision(0) << endl;
        }

        else if (MedianOrAvarage == 2) {
            std::cout << left << setw(9) << studentArray[i].getName() << " " << setw(15) << studentArray[i].getSurname() << setw(5) << " Pazymiai: ";
            for (int j = 0; j < studentArray[i].getGrades().size(); j++) {

                std::cout << setw(3) << studentArray[i].getGrades()[j];

            }
            std::cout << setw(5) << "Egzaminas: " << setw(4) << studentArray[i].getExamGrade() << setw(15) << " Galutinis (Med): " << setprecision(2) << fixed << studentArray[i].getFinalGrade() << setprecision(0) << endl;
        }
    }
}

//JEI NERA PAZYMIO IRASO NULI
void gradesCorection() {
    for (int i = 0; i < objCount; i++) 
    {
        if (homeWorkCount < studentArray[i].getGrades().size())
        {
            homeWorkCount = studentArray[i].getGrades().size();
        }
        else
        {
            homeWorkCount = homeWorkCount;
        }
    }
    for (int i = 0; i < objCount; i++) 
    {
        for (int j = 0; j < homeWorkCount; j++){
            if (j < studentArray[i].getGrades().size()) {

            }
            else {
                
                studentArray[i].setGrades(0);
            }
         }

    }
};

//IRASOM I TXT
void textDocumentIn() {
    //uzdeklaruojam
    ofstream out;

    //NUSTATYMU FAILAS
    out.open("SETTINGS.txt", std::ios_base::app);

    out << objCount << " " << homeWorkCount << " " << MedianOrAvarage;

    out.close();

    //DUOMENU FAILAS pridedam faila, arba perraso
    out.open("kursiokai.txt", std::ios_base::app);

    

    for (int i = 0; i < objCount; i++) {

        out << studentArray[i].getName() << " " << studentArray[i].getSurname() << "  ";
        for (int j = 0; j < homeWorkCount; j++) {
            out << studentArray[i].getGrades()[j] << " ";
        }

        out << "  " << studentArray[i].getExamGrade() << "  ";

        
        if (MedianOrAvarage == 1) {
            out << studentArray[i].getAvarageGrade();
        }
        else if (MedianOrAvarage == 2) {
            out << fixed << setprecision(2) << studentArray[i].getMedian();
        }
        out << endl;
    }
    out.close();
}

//PAIMAM IS TXT
void textDocumentOut() {

    string tempName;
    string tempSurname;
    vector<int> tempGrades;
    int tempExamGrade = 0;
    double tempFinalGrade = 0;

    int tempObjCount = 0;
    int tempHomeWorkCount = 0;
    int tempMedianOrAvarage = 0;

    int temp = 0;

    //uzdeklaruojam
    ifstream in;

    //nuskaitom settings
    in.open("SETTINGS.txt");

    in >> objCount >> homeWorkCount >> MedianOrAvarage;

    //cout << "SETTINGS: " << objCount << " " << homeWorkCount << " " << MedianOrAvarage << endl;

    in.close();


    // pridedam faila, arba perrasom
    in.open("kursiokai.txt");

    for (int i = 0; i < objCount; i++) {

        in >> tempName >> tempSurname;

        for (int j = 0; j < homeWorkCount; j++) {
            in >> temp;
            tempGrades.push_back(temp);
        }
        in >> tempExamGrade >> tempFinalGrade;

        studentArray[i].setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        //Isvalom
        tempGrades.clear();
        
    }
    in.close();
    
}

int main()
{   //srand funkcijos atskaitos taskas
    srand(time(NULL));

    

    //AR FAILAS TUSCIAS , AR NE 
    ifstream read("kursiokai.txt");

    if (!read) return 0;

    bool isEmpty = read.peek() == EOF;

    //JEI TUSCIAS
    if (isEmpty) {
        std::cout << "Failas yra tuscias!\nIrasomi nauji duomenys\n" << endl;
        std::cout << "Vidurkis: 1\nMedianas: 2" << endl;
        cin >> MedianOrAvarage;
        std::cout << "NORMAL MODE: 1\nDEMO MODE: 2" << endl;
        int demoOrNormal;
        cin >> demoOrNormal;


        if (demoOrNormal == 1) {
            makeObj();
            gradesCorection(); // IRASO NULIUS VIETOJE TUSCIU VIETU
        }

        else if (demoOrNormal == 2) {
            int temp;
            std::cout << "Kiek pazimiu generuosim: ";
            cin >> temp;
            makeGeneratedObj(temp);
        }

        textDocumentIn();
    }

    //JEI PILNAS
    if (!isEmpty) {
        std::cout << "Faile yra duomenu!\nSkaitoma is failo\n" << endl;

        textDocumentOut();
    }

    
    
    printAllObjDetails();

    
    
    
    

    return 0;
}

