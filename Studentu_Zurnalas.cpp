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
        static int homeworkCount; // statinis kintamasis
        double examGrade = 0;
        int* grades = new int[10]; //sukuriu array dinaminej atminty

        //konstruktorius be parametru
        Student() {};
        //konstruktorius su parametrais
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
            
            cout << left << setw(9) <<  name <<  " " << setw(15) << surname  << setw(5)<<" Pazymiai: ";
            for (int i = 0; i < homeworkCount; i++) {
                cout << setw(3)<< grades[i] ;
            }
            cout  <<setw(5) << "Egzaminas: "<<setw(4) << examGrade << setw(15)<<" Galutinis ivertinimas: "<< setprecision(2) << fixed <<getFinalGrade()<< setprecision(0)<< endl;
            
        }

        void inputMethod() {
            
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> name >> surname;
            /*cout << "\nKiek namu darbu buvo uzduota: ";
            cin >> homeworkCount;*/
            cout << "\nSurasykite pazymius: " << endl;

            for (int i = 0; i < homeworkCount; i++) {
                cout << "Pazymys nr"<<i+1<<": ";
                cin >> grades[i];
            }

            cout << "\nIveskite egzamino pazymi: ";
            cin >> examGrade;
        }
        
        static void setHomeworCount() {
            cout << "Irasykite kiek bus namu darbu (pazymiu skaicius): ";
            cin >> homeworkCount;
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
int Student::homeworkCount = 0; // Priskiriam statiniam kintamajam uz klases ribu reiksme

void makeObj() { //OBJEKTU KURIMO FUNKCIJA
    const int objNumber = 3; //KONSTANTA
    Student* studentArray = new Student[objNumber]; //DINAMINEJ ATMINTY SUKURIU

    

    for (int i = 0; i < objNumber; i++)
    {
        cout << (i + 1) << ". ***STUDENTAS***" << endl;
        studentArray[i].inputMethod();
    }
    system("CLS");
    cout << "   Vardas     Pavarde        Pazymiai" << endl;
    cout << "----------------------------------------------------------------------" << endl;
   
    for (int i = 0; i < objNumber; i++)
    {
        cout << (i + 1) << ". ";
        studentArray[i].printDetails();
    }
}


int main()
{   
    Student::setHomeworCount();
    makeObj();
    /*int array1[] = { 10,9,8,9 };
    int array2[] = { 9,9,8,9 };
    Student pirmas("Simonas", "Laukaitis", 10, 4, array1);
    Student antras("Domas", "Laukaitovskis", 9,4, array2);

    cout << "    Vardas    Pavarde         Pazymiai  1  2  3  4  Egzaminas       Galutinis ivertinimas" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "100 " ; pirmas.printDetails();
    cout << "    " ; antras.printDetails();
    */
    

   
   
    return 0;
};


