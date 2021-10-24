#include "Methods.h"
#include "Libraries.h"

//konstruktorius be parametru
Student::Student() {};

Student::Student(string name, string surname, vector<int> pGrades, int examGrade) {
    this->name = name;
    this->surname = surname;
    for (int i = 0; i < pGrades.size(); i++) {
        grades[i] = pGrades[i];
    }
    this->examGrade = examGrade;
    this->finalGrade = finalGrade;

    pGrades.clear();
}

Student::Student(const Student& p) {
    name = p.name;
    surname = p.surname;
    examGrade = p.examGrade;
    finalGrade = p.finalGrade;


    for (int i = 0; i < p.grades.size(); i++) {
        grades.push_back(p.grades[i]); //Gal klaida , buvo grades[i] = p.grades[i]
        
    }
    
    
    
}

Student :: ~Student() {
    grades.clear();
    //objVector.clear();
    //cout << "DESTRUKTORIUS ISKVIESTAS" << endl;
}

void Student::setAll(string name, string surname, vector<int> pGrades, int examGrade) {
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
    else if (MedianOrAvarage == 2) {
        finalGrade = getMedian();
    }
}

bool Student :: operator<(const Student& r) const
{
    if (surname != r.surname) {
        return surname < r.surname;
    }

    return surname < r.surname;
}

string Student::getName() {
    return name;
}

string Student::getSurname() {
    return surname;
}

vector<int> Student::getGrades() {
    return grades;
}

int Student::getExamGrade() {
    return examGrade;
}

double Student::getFinalGrade() {
    return finalGrade;
}

double Student::getAvarageGrade() {
    double sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }

    return 0.4 * (sum / grades.size()) + 0.6 * examGrade;
}

double Student::getMedian() {
    double median;
    auto n = grades.size();

    median = grades[(n / 2)];

    median = (grades[n / 2] + grades[(n - 1) / 2]) / 2.0;

    return median;
}

void Student::setGrades(int a) {
    grades.push_back(a);
}

//pazymiu skaicius
void Student::gradesCount() {

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

void makeObj() {

    int input = 0;
    string tempName;
    string tempSurname;
    vector<int> tempGrades;
    int tempExamGrade = 0;
    double tempFinalGrade = 0; //Vidurkis arba Medianas

    cout << "Kiek objektu kursime: ";
    cin >> objCount;
    cout << endl;

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

        //Pridedam i vektoriu
        Student Mokinys;
        Mokinys.setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        objVector.push_back(Mokinys);

        tempGrades.clear();

        std::cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;

    }
    tempGrades.clear(); // ISVALOM TEMP GRADES VEKTORIU

    //Rikiuojam deque ir vector
    //sort(objVector.begin(), objVector.end());
    //Rikiuojam list
    objVector.sort();
}

void makeGeneratedObj(int grad) {

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    int input = 0;
    int x;
    string tempName;
    string tempSurname;
    vector<int> tempGrades;  //ISVALYTI!!!!!!!!!
	int tempExamGrade = 0;
    double tempFinalGrade = 0; //Vidurkis arba Medianas



    for (int i = 0; i < objCount; i++)
    {
        tempName = to_string(i+1) + ".Vardas";
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

        //Dedam i vektoriu
        Student Mokinys;
        Mokinys.setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        objVector.push_back(Mokinys);


        std::cout << (i + 1) << ". ***STUDENTO OBJEKTAS SUKURTAS***" << endl;


        tempGrades.clear(); // isvalom laikinaji grades
    }

    //Rikiuojam deque ir vector
   //sort(objVector.begin(), objVector.end());
   //Rikiuojam list
    objVector.sort();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> uztruko = end - start; // Skirtumas (s)
    std::cout << "Failo kurimas uztruko: " << uztruko.count() << " s\n";
}

void printAllObjDetails() {

    auto start = std::chrono::high_resolution_clock::now(); 
    auto st = start;

    for (Student a : objVector)
    {
        if (MedianOrAvarage == 1) {

            std::cout << left << setw(9) << a.getName() << " " << setw(15) << a.getSurname() << setw(5) << " Pazymiai: ";
            for (int j = 0; j < a.getGrades().size(); j++) {

                std::cout << setw(3) << a.getGrades()[j];

            }
            std::cout << setw(5) << "Egzaminas: " << setw(4) << a.getExamGrade() << setw(15) << " Galutinis (Vid): " << setprecision(2) << fixed << a.getFinalGrade() << setprecision(0) << endl;
        }

        else if (MedianOrAvarage == 2) {
            std::cout << left << setw(9) << a.getName() << " " << setw(15) << a.getSurname() << setw(5) << " Pazymiai: ";
            for (int j = 0; j < a.getGrades().size(); j++) {

                std::cout << setw(3) << a.getGrades()[j];

            }
            std::cout << setw(5) << "Egzaminas: " << setw(4) << a.getExamGrade() << setw(15) << " Galutinis (Med): " << setprecision(2) << fixed << a.getFinalGrade() << setprecision(0) << endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff; // Skirtumas (s)
    std::cout << "Failo nuskaitymas PAPRASTAI uztruko: " << diff.count() << " s\n";
}

void gradesCorection() {
    cout << "Pradejo veikti grades correction" << endl;
    for (Student a : objVector)
    {
        if (homeWorkCount < a.getGrades().size())
        {
            homeWorkCount = a.getGrades().size();
        }
        else
        {
            homeWorkCount = homeWorkCount;
        }
    }
    for (Student a : objVector)
    {
        for (int j = 0; j < homeWorkCount; j++) {
            if (j < a.getGrades().size()) {

            }
            else {

                a.setGrades(0);
            }
        }

    }
    cout << "baige veikti grades correction\nPazymiu skaicius: " <<homeWorkCount<< endl;
};

void textDocumentIn() {
    cout << "pradejo veikti textDocumentIn funkcija" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    //uzdeklaruojam
    ofstream out;

    //NUSTATYMU FAILAS
    out.open("SETTINGS.txt", std::ios_base::app);

    out << objCount << " " << homeWorkCount << " " << MedianOrAvarage;

    out.close();

    //DUOMENU FAILAS pridedam faila, arba perraso
    out.open("kursiokai.txt", std::ios_base::app);



    for (Student a:objVector) {

        out << left << setw(10) << a.getName() << " " << setw(10)<< a.getSurname() << "  ";
        for (int j = 0; j < homeWorkCount; j++) {
            out << left << setw(2) << a.getGrades()[j] << " "; /////////////////////////////////////////Pakeiciau
        }

        out << "  " << a.getExamGrade() << "  ";


        if (MedianOrAvarage == 1) {
            out << fixed << setprecision(2) <<a.getAvarageGrade();
        }
        else if (MedianOrAvarage == 2) {
            out << fixed << setprecision(2) << a.getMedian();
        }
        out << endl;
    }
    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Rasymas i faila  uztruko: " << diff.count() << " s\n";
}

void textDocumentOut() {
    cout << "pradejo veikti textDocumentOut funkcija" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

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

        //Idedam i vektoriu
        Student Mokinys;
        Mokinys.setAll(tempName, tempSurname, tempGrades, tempExamGrade);
        objVector.push_back(Mokinys);

        //Isvalom
        tempGrades.clear();

    }
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo \"kursiokai.txt\" nuskaitymas  uztruko : " << diff.count() << " s\n";
}

//RUSIUOJAM I GALVOCIUS IR NUSKRIAUSTUKUS !!!!! BLOGAI VEIKIA RANKA IVEDANT
void textDpcumentInTwoFiles(){

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    ofstream out;

    

    

    for (Student a: objVector) {

        if (a.getFinalGrade() >= 5) {

            out.open("galvociai.txt", std::ios_base::app);

            out << left << setw(10) << a.getName() << " " << setw(10) << a.getSurname() << "  ";
            for (int j = 0; j < homeWorkCount; j++) {
                out << left << setw(2) << a.getGrades()[j] << " "; /////////////////////////////////////////Pakeiciau
            }

            out << "  " << a.getExamGrade() << "  ";


            if (MedianOrAvarage == 1) {
                out << fixed << setprecision(2) << a.getAvarageGrade();
            }
            else if (MedianOrAvarage == 2) {
                out << fixed << setprecision(2) << a.getMedian();
            }
            out << endl;

            out.close();
        }
        
        else{
            out.open("nuskriaustukai.txt", std::ios_base::app);

            out << left << setw(10) << a.getName() << " " << setw(10) << a.getSurname() << "  ";
            for (int j = 0; j < homeWorkCount; j++) {
                out << left << setw(2) << a.getGrades()[j] << " "; /////////////////////////////////////////Pakeiciau
            }

            out << "  " << a.getExamGrade() << "  ";


            if (MedianOrAvarage == 1) {
                out << fixed << setprecision(2) << a.getAvarageGrade();
            }
            else if (MedianOrAvarage == 2) {
                out << fixed << setprecision(2) << a.getMedian();
            }
            out << endl;
            out.close();
        };
            
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Rusiavimas i dvi grupes ir irasymas uztruko: " << diff.count() << " s\n";
};

//IS TXT FAILO I RAM  !!!!!!!!!!SUTVARKYTI , NES PARODO VIENU PER DAUG
void textDpcumentOutTwoFiles() { 

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    

    string tempName;
    string tempSurname;
    vector<int> tempGrades;
    int tempExamGrade = 0;
    double tempFinalGrade = 0;
    int temp;



    ifstream in;

    in.open("SETTINGS.txt");
    in >> objCount >> homeWorkCount >> MedianOrAvarage;
    in.close();
    

    in.open("galvociai.txt");
    cout << "****************************GALVOCIAI****************************\n";
    while(!in.eof()) {
       

        in >> tempName >> tempSurname;
        for (int j = 0; j < homeWorkCount; j++) {
            in >> temp;
            tempGrades.push_back(temp);
        }
        in >> tempExamGrade >> tempFinalGrade;


        cout << "Galvocius ";
        cout << left << setw(10) << tempName << " " << setw(10) << tempSurname << "  ";
        for (int j = 0; j < homeWorkCount; j++) {
            cout << left << setw(2) << tempGrades[j] << " ";
        }

            tempGrades.clear();

            cout << "  " << tempExamGrade << "  ";


            if (MedianOrAvarage == 1) {
                cout << fixed << setprecision(2) << " (Vid) " << tempFinalGrade;
            }
            else if (MedianOrAvarage == 2) {
                cout << fixed << setprecision(2) << " (Med) " << tempFinalGrade;
            }
            cout << endl;

            
           
    }
    
    in.close();
   
    
    
   
    in.open("nuskriaustukai.txt");
    cout << "****************************NUSKRIAUSTUKAI****************************\n";
    while(!in.eof()) {
       
        in >> tempName >> tempSurname;
        for (int j = 0; j < homeWorkCount; j++) {
            in >> temp;
            tempGrades.push_back(temp);
        }
        in >> tempExamGrade >> tempFinalGrade;


        cout << "Nuskriaustukas ";
        cout << left << setw(10) << tempName << " " << setw(10) << tempSurname << "  ";

        for (int j = 0; j < homeWorkCount; j++) {
            cout << left << setw(2) << tempGrades[j] << " ";
        }

            tempGrades.clear();

            cout << "  " << tempExamGrade << "  ";


            if (MedianOrAvarage == 1) {
                cout << fixed << setprecision(2) << " (Vid) " << tempFinalGrade;
            }
            else if (MedianOrAvarage == 2) {
                cout << fixed << setprecision(2) << " (Med) " << tempFinalGrade;
            }
            cout << endl;
            
           
    }
    in.close();
  
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo Skaitymas uztruko: " << diff.count() << " s\n";
    
};

//ISVALO VISUS TXT FAILUS
void cleanAllFiles() {
    ofstream out;
    out.open("kursiokai.txt", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out.open("SETTINGS.txt", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out.open("galvociai.txt", std::ofstream::out | std::ofstream::trunc);
    out.close();

    out.open("nuskriaustukai.txt", std::ofstream::out | std::ofstream::trunc);
    out.close();

    cout << "\n***TXT FAILAI ISVALYTI!!!***\n";
};

//tik rusiavimas
void studentSortingInTwoCategories() {
    cout << "pradejo veikti studentSortingInTwoCategories funkcija" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    

    for (Student a:objVector) {
        if (a.finalGrade<5) {
            nuskriaustukai.push_back(a);
            //objVector.remove(a);
        }
        else {
            galvociai.push_back(a);

        }
	}



    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Rusiavimas ir dejimas i du vektorius uztruko: " << diff.count() << " s\n";
};

void studentWritingInTwoFilesFromVector() {

    cout << "pradejo veikti studentWritingInTwoFilesFromVector funkcija" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

        ofstream out;
        int i=0;
   
        //Galvociai
        out.open("galvociai.txt", std::ios_base::app);

        for(Student a : galvociai){
        out << left << setw(10) << a.getName() << " " << setw(10) << a.getSurname() << "  ";
        for (int j = 0; j < homeWorkCount; j++) {
            out << left << setw(2) << a.getGrades()[j] << " "; /////////////////////////////////////////Pakeiciau
        }

        out << "  " << a.getExamGrade() << "  ";


        if (MedianOrAvarage == 1) {
            out << fixed << setprecision(2) << a.getAvarageGrade();
        }
        else if (MedianOrAvarage == 2) {
            out << fixed << setprecision(2) << a.getMedian();
        }
       
        out << endl;

        i++;
        }


        out.close();


        i = 0;
        out.open("nuskriaustukai.txt", std::ios_base::app);

        for (Student a : nuskriaustukai) {
            out << left << setw(10) << a.getName() << " " << setw(10) << a.getSurname() << "  ";
            for (int j = 0; j < homeWorkCount; j++) {
                out << left << setw(2) << a.getGrades()[j] << " "; /////////////////////////////////////////Pakeiciau
            }

            out << "  " << a.getExamGrade() << "  ";


            if (MedianOrAvarage == 1) {
                out << fixed << setprecision(2) << a.getAvarageGrade();
            }
            else if (MedianOrAvarage == 2) {
                out << fixed << setprecision(2) << a.getMedian();
            }

            out << endl;

            i++;
        }


        out.close();

        //Nuskriaustukai


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Dvieju vektoriu rasymas i du skirtingus failus utruko:  " << diff.count() << " s\n";
};

void bufer_nusk(std::string read_vardas) {

    std::vector<std::string> splited;
    std::string eil;
    std::stringstream my_buffer;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream open_f(read_vardas);


    my_buffer << open_f.rdbuf();
    open_f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas i buferi uztruko: " << diff.count() << " s\n";



    start = std::chrono::high_resolution_clock::now();


    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            splited.push_back(eil);
        }
        else break;
    }


    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Buferio padalijimas i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();


    std::string outputas = "";
    for (std::string& a : splited) (a.compare(*splited.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;

    string tempName;
    string tempSurname;
    vector<int> tempGrades;
    int tempExamGrade = 0;
    double tempFinalGrade = 0;
    

    for (string a : splited) {
        cout << a << endl;
        //for (int i = 0; i < a.length(); i++) {
        //    for(int j = 0;!isspace(a[i]);j++){
        //        tempName += a[j];
        //    }

        //    for (int j = 0; !isspace(a[i]); j++) {
        //        tempSurname += a[j];
        //    }

        //    for (int j = 0; j<homeWorkCount; j++) {
        //        //pazymiai

        //    }

        //    tempExamGrade;
        //    tempExamGrade;
    }

    splited.clear();


    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Eiluciu vektoriaus konvertavimas i vienà eilutæ uztruko: " << diff.count() << " s\n";

    //start = std::chrono::high_resolution_clock::now();


    //std::ofstream out_f(write_vardas);
    //out_f << outputas;
    //out_f.close();
    //diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    //std::cout << "Failo áraðymas per vienà eilutæ uþtruko: " << diff.count() << " s\n";


    //diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    //std::cout << "Visas sugaiðtas laikas: " << diff.count() << " s\n\n";

    
}