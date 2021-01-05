//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//多載建構子實作 (overload)
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
    Baseball(char *name, int fs, int ss);
    
};

Baseball::Baseball()
{
    strcpy(player, "Eric");
    fires = 68;
    safes = 20;
}
Baseball::Baseball(char*name, int fs, int ss)
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
    Baseball a("David",115,20);
    b.showplayer();
    a.showplayer();
    return 0;
}
