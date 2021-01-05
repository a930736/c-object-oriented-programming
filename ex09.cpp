//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//解構子實作 沒有回傳值 沒有參數 不可多在載 只能在public下 先建立的建構子後解除 後建立的建構子先解除
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
    ~Baseball(){
        cout <<"deconstructor: " << player <<endl;
    }
    
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
