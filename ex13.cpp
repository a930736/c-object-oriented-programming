//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//宣告物件陣列
#include <iostream>
#include <cstdlib>
using namespace std;
class Baseball
{
private:
    char player[20];
    int fires;
    int safes;
    float countsafe();

public:
    void inputplayer();
    void showplayer();
};
void Baseball::inputplayer()
{
    cout <<"player: ";
    cin >> player;
    cout <<"fires: ";
    cin >> fires;
    cout <<"safes: ";
    cin >> safes;
    
}

void Baseball::showplayer()
{
    float fs;
    fs = countsafe();
    cout <<"player: "<<player <<endl;
    cout <<"fires: "<<fires<<endl;
    cout <<"safes: "<<safes<<endl;
    cout<<"rate: "<<fs<<endl;
    
}
float Baseball::countsafe()
{
    float counts;
    counts = float(fires)/float(safes);
    return counts;
    
}
int main()
{
    Baseball b[3];
    int i;
    cout <<"Enter datas: " <<endl;
    for (i=0; i< 3;i++)
    {
        b[i].inputplayer();
    }
    cout <<"Data lists: "<<endl;
    for (i=0;i <3;i++)
    {
        b[i].showplayer();
    }
    return 0;
}
