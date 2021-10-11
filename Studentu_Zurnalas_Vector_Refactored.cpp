//
//                                  ****MOKINIU ZURNALAS v0.1****
//

//#include "Libraries.h"
#include "Methods.h"


//
//class Student {
//
//
//
//   
//
//    //konstruktorius be parametru
//    Student();
//
//
//    //konstruktorius su parametrais
//    Student(string name, string surname, vector<int> pGrades, int examGrade);
//
//
//    //kopijavimp konstruktorius
//    Student(const Student& p);
//
//    //destruktorius
//    ~Student();
//
//    //konstruktoriaus atskira funkcija
//    void setAll(string name, string surname, vector<int> pGrades, int examGrade);
//
//
//    //overloadinu < operatoriu
//    bool operator<(const Student& r) const;
//
//    string getName();
//
//    string getSurname();
//
//    vector<int> getGrades();
//
//    int getExamGrade(); 
//
//    double getFinalGrade();
//
//    //Vidurkio skaiciavimas
//    double getAvarageGrade();
//
//    //medianas
//    double getMedian();
//
//    void setGrades(int a);
//
//    //pazymiu skaicius
//    void gradesCount();
//};










//IVESTI OBJEKTUS v
//void makeObj();
//
////GENERUOTI OBJEKTUS v
//void makeGeneratedObj(int grad);
//
////ISVESTI VISUS OBJEKTUS ( IS RAM ) v
//void printAllObjDetails();
//
////JEI NERA PAZYMIO IRASO NULI v
//void gradesCorection();
//
////IRASOM I TXT v
//void textDocumentIn();
//
////PAIMAM IS TXT v
//void textDocumentOut();


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

