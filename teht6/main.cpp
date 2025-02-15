#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    //muuttujat ja iteraattorit nimihakua varten;
    string etsittavanimi;
    vector<Student>::iterator it = studentList.begin();

    //luodaan opiskelijat näin viikkotehtävän alustuksessa ohjatulla tavalla.

    studentList.push_back(Student("Keijo",17));
    studentList.push_back(Student("Kalevi",67));
    studentList.push_back(Student("Ari",34));
    studentList.push_back(Student("Sean",25));
    studentList.push_back(Student("Marjatta",68)); //opiskelija vuodesta '75

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            //teoriassa jotain tähän suuntaan, mutta skipataan

            //string name;
            //int age;
            cout<<"Student name:?"<<endl;
            //cin>>name;
            cout<<"Student age:?"<<endl;
            //cin>>age
            //studentList.push_back(Student(name,age));


            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.

            for(auto& i: studentList)
            {
                i.printStudentInfo();
            }

            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b){return a.getName()<b.getName();});

            for(auto &s: studentList)
            {
                s.printStudentInfo();
            }

            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b){return a.getAge()<b.getAge();});

            for(auto &s: studentList)
            {
                s.printStudentInfo();
            }

            break;
        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.


            cout<<"Give the name of the student you want to find: "<<endl;
            cin>>etsittavanimi;

            it=find_if(studentList.begin(), studentList.end(), [etsittavanimi](const Student & s)-> bool{return s.getName() == etsittavanimi;});

            if(it != studentList.end())
            {
                cout<<"Student found: "<<endl;
                it->printStudentInfo();
            }
            else
            {
                cout<<"Student not found"<<endl;
            }

            break;
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }

    }while(selection < 5);
return 0;
}
