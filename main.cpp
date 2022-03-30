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
void Binar2()
{
ofstream Datatest;
Datatest.open ("data.txt",ios::out);
string Binar;

int Num;
cout << "Enter the number" << endl;
cin >> Num;

BinarCod(Num,Datatest);


Datatest.close();
}
void elochka2(int H, int W, int i)
{
    for (int j=0; j < W+1; j++){
        if (j >= i+1 || j >= W-i)
            cout << " ";
        else
            cout << "*";
    }
    cout << endl;
    i++;
    if (i < H+1)
        elochka2(H,W,i);
}
void elochka(){
    int H=0;
    int W=0;

    cout << "Enter Height and Width" << endl;
    cin >> H >> W;

    int i=0;
    elochka2(H,W,i);
}


int main() {

    elochka();

    return 0;
}
