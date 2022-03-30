#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    int H=0;
    int W=0;

    cout << "Enter Height and Width" << endl;
    cin >> H >> W;


    for(int i =1; i < H+1 ;i++){
        for (int j=0; j < W+1; j++){
            if (j >= i+1 || j <= W-i)
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;

    }

    return 0;
}

