#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>
#include <cstring>
#include <vector>


using namespace std;

void makef1(){
    ofstream task1f;
    task1f.open("t1.txt",ios::out);
    task1f << "Something in english";
    task1f.close();
}
void task1(){

    FILE*task1f;

    task1f = fopen("t1.txt", "r");

    int num[256];

    int size=0;

    for(int i = 0; i < 256; ++i)
    {
        num[i] = 0;
    }

    char chek = 0;

    while(fscanf(task1f, "%c", &chek) != EOF)
    {
        num[(int)chek]++;
    }

    fclose(task1f);

    ofstream task1w;
    task1w.open ("t2.txt",ios::out);

    for(int i = 0; i < 256; ++i)
    {
       task1w<< (char)i << "\t" << num[i]<< "\n";
    }
    task1w.close();

}

void task2(){

    ofstream task2f;
    int num;
    int bit[11];
    task2f.open ("t2.txt",ios::out);

    cout << "Enter number"<<endl;
    cin >> num ;

    int x = 1024 , n;

    for (int i = 0; i < 11; i++)
    {
        n = num & x;
        if (n != 0)
            bit[i]=1;
        else
            bit[i]=0;

        x >>= 1;
    }
    for (int i=0;i<11;i++)
    task2f<< bit[i];

    task2f.close();

}
void make3f(){
    ofstream task3f;
    task3f.open("t3.txt",ios::out);
    task3f << "100010101";
    task3f.close();
}

const char hexn[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void task3(){
    FILE*task3;
    task3 = fopen("t3.txt", "r");
    char c = 0;
    int num_length = 0;

    char chars[64];

    for(int i = 0; i < 63; ++i)
    {
        chars[i] = 0;
    }

    string result;

    while(fscanf(task3 , "%c", &c) != EOF)
    {
        chars[num_length] = c;
        num_length++;
    }

    for(int i = 0,temp = 0; i < num_length; i += 4){

        for(int j = 0; j < 4; ++j){

            temp |= (((chars[i + j] == 0x30) ? 0 : 1) << j);
        }

        result += hexn[temp];
    }

    cout << "0x"<<result<< endl;

}



void task4(){
            int H=0;
        int W=0;

        cout << "Enter Width and Height" << endl;
        cin >> H >> W;
       for (int i=0; i < H; i++) {
           for (int j = 0; j < W + 1; j++) {
               if (j >= i + 1 || j >= W - i)
                   cout << " ";
               else
                   cout << "*";
           }
           cout << endl;
       }

       }

}


void task5(){
    {
        int h;
        int w;
        cout << "Enter height and width"<< endl;
        cin >> h >> w;
        cout << "Enter matrix"<< endl;
        int** arr= new int*[h];
        for (int i =0; i <h; i++){
            arr[i] = new int [w];
            for (int j=0; j<w; j++){
                cin >> arr[i][j];
            }

        }

        float out[h];

        list<double> aver;

        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                out[i] += arr[i][j];
            }

            out[i] /= w;
        }
        delete[] arr;
        for (int i=0;i<h;i++)
        cout << out[i]<< endl;


    }
}

struct Node
{
    Node* prev;
    Node* next;
    char* string;
    int size;
};

struct linklist
{
    Node* HEAD;
    Node* TAIL;
};

void task6(){
    linklist list;

    FILE*task6f;
    task6f = fopen("t6.txt", "w");

    Node* new_node = list.TAIL;

    int num_of_elements = 0;

    do
    {
        num_of_elements++;
        new_node = new_node->prev;
    }
    while(new_node->prev != nullptr);

    new_node = list.TAIL;

    while(new_node != nullptr)
    {
        fprintf(task6f, "%d\t\"%s\"\t%d\n", num_of_elements, new_node->string, new_node->size);
        num_of_elements--;
        new_node = new_node->prev;
    }
}

void task7(){
    linklist list;

    Node* element = (Node*)malloc(sizeof(Node));

    element->next = nullptr;
    element->prev = nullptr;
    element->string = (char*)malloc(strlen("element"));
    strcpy(element->string, "element");

    int index;

    cout << "Enter element"<<endl;
    cin >> index;

    Node* cur_node = list.HEAD;
    int cur_index = 0;

    while(cur_index < index && cur_node != nullptr)
    {
        cur_node = cur_node->next;
        cur_index++;
    }

    element->next = cur_node->next;
    element->prev = cur_node;

    cur_node->next->prev = element;
    cur_node->next = element;

}
struct Student {
    char* name;
    int age;
    char* ID;
};

struct Mark {
    char subj[100];
    int id_subj;
    vector<int> marks_list;
    float averMark;

    Mark(const char* _subj)
    {
        memset(subj, 0 ,100);
        memcpy(subj, _subj, strlen(_subj));

    }
    Mark(const char* _subj, int _idSubj)
    {
        memset(subj, 0 ,100);
        memcpy(subj, _subj, strlen(_subj));
        id_subj = _idSubj;
    }
    ~Mark() {

    }

};

class Student1 {
private :
    Student* info;
    list<Mark*> listSubjMark;
    list<Mark*>::iterator lookForSub(const char* subjName);

public :

    Student1(const char* new_name, const int new_age, const char* new_numTicket) {
        info = new Student();
        info->name = (char*)new_name;
        info->age = new_age;
        info->ID = (char*) new_numTicket;


    }
    ~Student1()
    {
        delete info;
    }


    void addSubject(const char* subjName, int idSubj = 0) {

        for (list<Mark*>::iterator it = listSubjMark.begin(); it != listSubjMark.end(); ++it)
        {
            if (strcmp((*it)->subj, subjName) == 0)
            {
                (*it)->id_subj = idSubj;
                return;
            }
        }
        listSubjMark.push_back(new Mark(subjName, idSubj));

    }

    int addMarkToSubj(const char* subjName, int mark){
        auto subjMarkIt = lookForSub(subjName);
        if ((*subjMarkIt) != nullptr)
        {
            (*subjMarkIt)->marks_list.push_back(mark);
            float av_mark = 0;
            for(const auto& mark: (*subjMarkIt)->marks_list)
            {
                av_mark += mark;
            }
            av_mark /= (*subjMarkIt)->marks_list.size();
            (*subjMarkIt)->averMark = av_mark;
            return av_mark;
        }

    }



};







int main() {
    int Num=1;

    while (Num != 0) {
        cout << "Enter function number" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> Num;
        switch (Num) {
            case 1:
                makef1();
                task1();
                cout << "Done" << endl;
                break;
            case 2:
                task2();
                cout << "Done" << endl;
                break;
            case 3:
                make3f();
                task3();
                cout << "Done" << endl;
                break;
            case 4:
                task4();
                cout << "Done" << endl;
                break;
            case 5:
                task5();
                cout << "Done" << endl;
                break;
            case 6:
                cout << "Prototype"<< endl;
                break;
            case 7:
                cout << "Prototype"<< endl;
                break;
            case 8:
                cout << "Look in class";
                break;

        }
    }

    return 0;
}
