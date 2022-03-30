#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void BinarCod(int Num, ofstream& Datatest)
{
    if (Num > 0){

        if (Num%2==0)
        {
            Num /=2;
            BinarCod(Num,Datatest);
            Datatest << 0;
        }
        else
        {
            Num /=2;
            BinarCod(Num,Datatest);
            Datatest << 1;
        }
    }

}

int main() {


    ofstream Datatest;
    Datatest.open ("data.txt",ios::out);
    string Binar;

    int Num;
    cout << "Enter the number" << endl;
    cin >> Num;

    BinarCod(Num,Datatest);






    Datatest.close();

    return 0;
}
