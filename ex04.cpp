//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//打擊率
#include <iostream>
#include <cstdlib>
using namespace std;

class Baseball{
private:
    char player[20];
    int fires;
    int safes;
    
    float  countsafe(){
        float counts;
        counts = float(safes)/float(fires) ;
        return counts;
        
    }
public:
    void inputplayer() {
        cout <<"player: " ;
        cin >> player;
        cout << "Fires: " ;
        cin >> fires;
        cout <<"Safes: ";
        cin >> safes;
    }
    void showplayer(){
        cout << "player: " <<player<< endl;
        cout << "countsafe: " << countsafe() <<endl;
     }
};

int main() {
    Baseball b;
    b.inputplayer();
    b.showplayer();
    
    return 0;
}
