//
//                                  ****MOKINIU ZURNALAS v0.1****
//

#include "Libraries.h"
#include "Methods.h"

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

    cout << homeWorkCount << " " << MedianOrAvarage << " " << objCount;

    return 0;
}

