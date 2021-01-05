//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//變數指標物件使用 new delete
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
    void setplayer(char *name, int fs, int ss);
    
    
};


void Baseball::setplayer(char*name, int fs, int ss)
{
    strcpy(player,name);
    fires = fs;
    safes = ss;
    
}

void Baseball::showplayer(){
    cout << "player: " << player<<endl;
    cout << "fires: " << fires <<endl;
    cout << "Safes: " << safes <<endl;
}

int main() {
    Baseball b;
    Baseball *b1 = new Baseball;
    b.setplayer("David", 232, 32);
    b1 ->setplayer("Tom", 400, 200);
    b.showplayer();
    b1->showplayer();
    delete b1;
    return 0;
}
