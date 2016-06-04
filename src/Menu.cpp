/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void makelist();
void addtolist();
void checkitem();
void displaylist();
struct list
{
    int quant;
    string items;
    string place;
    string date;
};
int main()
{                //show to the user an interface to select an option
    int a;
    cout << "                        *WELCOME*" << endl;
    cout << "Please chose one of the option: " << endl;
    do
    {
        cout << "     (1) Create list" << endl;
        cout << "     (2) Add an item to a list." << endl;
        cout << "     (3) Verifie an item from a list" << endl;
        cout << "     (4) Verifie a listshop of a date" << endl;
        cout << "     (5) Exit" << endl;
        cin >> a;
        switch (a)   //case switches to know which opcion is selected
        {
        case 1:
            makelist();
            break;
        case 2:
            addtolist();
            break;
            /*case 3:
            checkitem();
            break;
            case 4:
            displaylist();
            break;*/
            case 5:
                cout << "...Closing...";
                return 0;
            default:
                cout << "..ERROR..introduce a number from 1 to 5";
                break;
        }
    } while (a != 5);   //if the case is not 5 its going to return an error message
    return 0;
}
void makelist()
{
    string FileName;
    cout << "Enter a name for the list: ";
    cin >> FileName;
    ofstream WriteToFile;
    WriteToFile.open(FileName);
    list L;
    int n;
    cout << "Enter a name for the items:" << endl;
    cin >> n;
    for (int i = 0; i <= n; i++) //cicle for the items
    {
        cout << "Enter items and quantity:" << endl;
        cin >> L.items >> L.quant;
        WriteToFile << L.items << L.quant;
    }
    cout << "Enter the name of the supermarket:" << endl;
    cin >> L.place;
    WriteToFile << L.place;
    cout << "Entrar date:" << endl;
    cin >> L.date;
    WriteToFile << L.date;
}
void addtolist()
{
    cout << "ur lists:" << endl;     // and display the saved lists for the user to choose
    ifstream readfromfile;
    if (readfromfile.is_open())
    {
        makelist();              //the user adding new item
    }
    else
        cout << "ERROR opening the document" << endl;
}
/*void checkitem()          // function for displaying list from file for the user to chech them which i don't know how to do it
{}
void displaylist()          // function displaying list from file which i also don't know how
{}*/
