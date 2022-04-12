#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>
#include <vector>
#include <windows.h>


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
    task3f << "1000101010";
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

void task4(){
        int H=0;
        int W=0;

        cout << "Enter Height and Width" << endl;
        cin >> H >> W;

        int i=0;
        elochka2(H,W,i);

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

        int out[h];

        list<double> aver;

        for(int i = 0; i < h; ++i)
        {
            int n =0;
            for(int j = 0; j < w; ++j)
            {
                out[i] += arr[i][j];
            };

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

    list.HEAD = (Node*)malloc(sizeof(Node));
    list.HEAD->string = (char*)malloc(6);

    strcpy(list.HEAD->string, "HEAD");
    list.HEAD->size = strlen(list.HEAD->string);

    Node* node = list.HEAD;

    list.TAIL =node;
    strcpy(node->string, "TAIL");
    node->size = strlen(node->string);

    list.HEAD->prev = nullptr;
    list.TAIL->next = nullptr;


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

    list.HEAD = (Node*)malloc(sizeof(Node));
    list.HEAD->string = (char*)malloc(6);

    strcpy(list.HEAD->string, "HEAD");
    list.HEAD->size = strlen(list.HEAD->string);

    Node* node = list.HEAD;

    list.TAIL =node;
    strcpy(node->string, "TAIL");
    node->size = strlen(node->string);

    list.HEAD->prev = nullptr;
    list.TAIL->next = nullptr;

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
                cout << "ClassStud.h";
                break;

        }
    }

    return 0;
}
