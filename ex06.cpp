//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//建構子實作
#include <iostream>
#include <cstdlib>
using namespace std;
class Baseball
{
private:
    char player[20];
    int fires;
    int safes;
    
public:
    void showplayer();
    Baseball();
    
};

Baseball::Baseball()
{
    strcpy(player, "Eric");
    fires = 68;
    safes = 20;
}

void Baseball::showplayer(){
    cout << "player: " << player<<endl;
    cout << "fires: " << fires <<endl;
    cout << "Safes: " << safes <<endl;
}

int main() {
    Baseball b;
    b.showplayer();
    return 0;
}
