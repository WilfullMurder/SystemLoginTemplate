// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool bLoggedIn()
{
    string Username, Password, UN, PW;

    cout << "Enter Username: \n";
    cin >> Username;
    cout << "Enter Password: \n";
    cin >> Password;

    ifstream read("data\\" + Username + ".txt");
    getline(read, UN);
    getline(read, PW);

    if (UN == Username && PW == Password)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

int main() 
{
    int Choice;

    cout << "Please register or login \n";
    cout << "1: Register \n";
    cout << "2: Login \n";
    cin >> Choice;

    if (Choice == 1)
    {
        string Username, Password;

        cout << "Please create a Username: \n";
        cin >> Username;
        cout << "Please create a password: \n";
        cin >> Password;


        ofstream file;
        file.open("data\\" + Username + ".txt");
        file << Username << endl << Password;
        file.close();

        main();
    }

    else if (Choice == 2)
    {
        bool bStatus = bLoggedIn();

        if (bStatus != true)
        {
            cout << "Login details are incorrect! \n";

            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Login successful! \n";
            system("PAUSE");
            return 1;
        }
    }

    else
    {
        cout << "Incorrect selection! \n";
        cout << "Please make a valid selection \n";
        main();
    }

}