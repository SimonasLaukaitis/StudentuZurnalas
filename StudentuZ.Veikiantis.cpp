//
//                                  ****MOKINIU ZURNALAS v0.1****
//

#include "Libraries.h"
#include "Methods.h"

int main()
{
    logo();
    system("pause");
    system("cls");

    //srand funkcijos atskaitos taskas
    srand(time(NULL));
   

    start:


    //AR FAILAS TUSCIAS , AR NE
    ifstream read("kursiokai.txt");
    
    

    if (!read) {
        //cout << "Nepavyko atidaryti kursiokai.txt failo" << endl;
        
    } //return 0;

    bool isEmpty = read.peek() == EOF;

    //JEI TUSCIAS
    if (isEmpty) {

        std::cout << "\nFailas yra tuscias!\nIrasomi nauji duomenys\n" << endl;
        std::cout << "Vidurkis: 1\nMedianas: 2" << endl;
        cin >> MedianOrAvarage;

        wrongInput:
        std::cout << "NORMAL MODE: 1\nDEMO MODE: 2" << endl;
        int demoOrNormal;

        try{ // implementuoju exceptiona
            

            cin >> demoOrNormal;

            if (demoOrNormal>2 || demoOrNormal <1) {
                throw 1;
            }

            if (demoOrNormal == 1) {
                makeObj();

                //gradesCorection(); // IRASO NULIUS VIETOJE TUSCIU VIETU

                //objVector.clear();/// CIA GILI BUTI BLOGAI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                //nuskriaustukai.clear();
                //galvociai.clear();
            }

            else if (demoOrNormal == 2) {
                int temp;
                std::cout << "Kiek objektu kursim: ";
                cin >> objCount;
                std::cout << "Kiek pazimiu generuosim: ";
                cin >> temp;
                makeGeneratedObj(temp);
            }
            studentSortingInTwoCategories();

            studentWritingInTwoFilesFromVector();
            textDocumentIn();
            textDocumentOut();

            objVector.clear();
            nuskriaustukai.clear();
            galvociai.clear();

            //RUSIAVIMAS
           // textDpcumentInTwoFiles();
            goto start;
        }
        catch (int x) {
            cout << "*******************************************" << endl;
            cout << "IVEDETE NETEISINGA SKAICIU, SKAICIUS TURI BUTI NUO 1 ARBA 2!!!\N \nERROR NUMBER: " <<x<< endl;
            cout << "\n*******************************************" << endl;
            goto wrongInput;
        }
        
    }

    //JEI PILNAS
    if (!isEmpty) {
        int readOrClear = 0;
        std::cout << "\nFaile yra duomenu!\n";

        cout << "1. FAILU NUSKAITYMAS\n2. FAILU VALYMAS" << endl;
        cin >> readOrClear;
        if (readOrClear == 2) { 
            cleanAllFiles();
            cout << "VISI FAILAI ISVALYTI!" << endl;    
            system("CLS");
            cout << endl << endl;
            goto start;
        }

        else if (readOrClear == 1) {

            int choose=0;
            cout << " Skaitoma is failo\n" << endl;

            cout << "KAIP NORESITE ISVESTI\n1. *TESTAVIMAS* Per buferi kursiokai.txt\n2. Per buferi gudrociai.txt\n3. Per buferi nuskriaustukai.txt\n4. Paprastai kursiokai.txt\n5. Paprastai gudrociai.txt ir nuskriaustukai.txt" << endl;
            cin >> choose;
            if (choose == 1) {
                //NUSKAITYMAS PER BUFERI
                bufer_nusk("kursiokai.txt");

            

                goto start;
            }
            else if (choose == 2) {
                //NUSKAITYMAS PER BUFERI
                bufer_nusk("galvociai.txt");

                

                goto start;
            }
            else if (choose == 3) {
                //NUSKAITYMAS PER BUFERI
                bufer_nusk("nuskriaustukai.txt");

               

                goto start;
            }
            else if (choose == 4) { 
                textDocumentOut();
                printAllObjDetails();

               

                goto start;
            }
            else if (choose == 5) {
                textDpcumentOutTwoFiles(); 

                

                goto start;
            }
           // textDocumentOut();
        
       
       
        }

        

    }

    cout<<"\n"<<endl;
    //NUSKAITYMAS PER BUFERI
   // bufer_nusk("kursiokai.txt");

    //COUTINIMAS SURUSIUOTU
   // textDpcumentOutTwoFiles();

    //printAllObjDetails();
    cout <<"Pazymiu skaicius: "<< homeWorkCount << endl <<"Medianas ar vidurkis: "<< MedianOrAvarage << endl <<"Objektu skaicius: " <<objCount<<endl;
    

    return 0;
}

