// Studentu_Zurnalas.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//                                  ****MOKINIU ZURNALAS v0.1****
//

#include <iostream>
#include<iomanip>

using namespace std;


class Student {  
public:
        
        string name;
        string surname;
        int homeworkCount = 0;
        double examGrade = 0;
        int* grades = new int[10]; //sukuriu array dinaminej atminty

        //konstruktorius su parametrais
        Student() {};
        Student(string name, string surname,  double examGrade, int homeworkCount, int* pGrades) {
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
           
        

        //metodai
        double getFinalGrade() { //galutinis vertinimas
            double sum = 0;
            for (int i = 0; i < homeworkCount; i++) {
                sum += grades[i];
            }

            return 0.4 * (sum / homeworkCount) + 0.6 * examGrade;
        }

        void getStudent() {
            cout << name << " " << surname << " ";
            for (int i = 0; i < homeworkCount; i++) {
                cout << " " << grades[i];
            }
            cout <<" "<< examGrade << " " << getFinalGrade() << endl;
        }

        void printDetails() {
            
            cout << name << " " << surname << " Pazymiai: ";
            for (int i = 0; i < homeworkCount; i++) {
                cout << grades[i] << " ";
            }
            cout << "Egzaminas: " << examGrade <<"Galutinis ivertinimas: "<< setprecision(2) << fixed <<getFinalGrade()<< endl;
        }

        void inputMethod() {
            
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> name >> surname;
            cout << "\nKiek namu darbu buvo uzduota: ";
            cin >> homeworkCount;
            cout << "\nSurasykite pazymius: " << endl;

            for (int i = 0; i < homeworkCount; i++) {
                cout << "Pazymys nr"<<i+1<<": ";
                cin >> grades[i];
            }

            cout << "\nIveskite egzamino pazymi: ";
            cin >> examGrade;
        }



        //destruktorius (dar paziureti)
        ~Student() {

           delete[] grades;
            // isvalom atminti(masyvas grades[])
            cout << "DESTRUKTORIUS ISKVIESTAS" << endl;

            //for (int i = 0; i < homeworkCount; i++) {
            //     delete[i] grades;
            //  }
            
             

            
            }
            
        
};

void makeObj() { //OBJEKTU KURIMO FUNKCIJA
    const int objNumber = 4; //KONSTANTA
    Student* studentArray = new Student[objNumber]; //DINAMINEJ ATMINTY SUKURIU

    

    for (int i = 0; i < objNumber; i++)
    {
        cout << (i + 1) << ". ***STUDENTAS***" << endl;
        studentArray[i].inputMethod();
    }
    system("CLS");
    cout << "Vardas  Pavarde  Pazymiai  1  2  3  4  Egzaminas Galutinis ivertinimas" << endl;
    cout << "----------------------------------------------------------------------" << endl;
   
    for (int i = 0; i < objNumber; i++)
    {
        cout << (i + 1) << ". ";
        studentArray[i].getStudent();
    }
}


int main()
{
    makeObj();
    
    
    


   
   
    return 0;
};


