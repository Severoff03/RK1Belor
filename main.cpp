#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void inputf(List& students) // задача 6
{
	cout << "Введите имя файла  " << endl;
	char name[64];
	
	cin.getline(name, 64);

	ofstream input(name, ios::binary);
	if (!input)
		cout << "Не удается открыть файл \"" << name << "\" для записи" << endl;
	else
	{
		student yacheika;
		ListNode* p = students.head;
		input.write((char*)&students.dlin, sizeof(students.dlin));
		for (int i = 1; i <= students.dlin; i++)
		{
			input.write((char*)&p->stud, sizeof(p->stud));
			p = p->next;
		}
		input.close();
        cout << "Файл записан" << endl;
	}


}


class Student{  /// Общая идея для задачи 8
private:
    string Name;
    int** classes;
    int numclas;
public:
    Student(){
        cin >> Name ;
        cin >> numclas;
        *classes = new int [numclas];

    }
    int addclass( int clas, int cl, int numofsub){
        if (clas > numclas )
        {
            return -1;
        }
        classes[numofsub][cl]=clas;
        return 1;
    }
    int addnewclass(){
        int** clas ;
        *clas = new int [numclas];

        for (int i; i< numclas; i++){
            clas[i]= new int [10];
        }

        for (int i=0; i < numclas;i++){
            for (int j=0;i<numclas;i++){
                clas[i][j]=classes[i][j];
            }

        }

        delete[] classes;
        *classes = new int [numclas+1];
        for (int i; i< numclas+1; i++){
            classes[i]= new int [10];
        }

        for (int i=0; i < numclas;i++){
            classes[i]= clas[i];
        }

        numclas++;
        return 1;
    }
    int midlclass()
    {
        int mid=0;
        for (int i=0; i < numclas;i++){
            mid += classes[num][i];
        }
        mid /= numclas;
        cout << "midl class -"<< mid << endl;
    }

    
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
void Binar2() // задача 2
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
void elochka(){ //задача 4
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
