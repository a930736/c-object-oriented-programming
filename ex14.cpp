//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//靜態資料成員實作（同一類別的物件此資料成員是共用的）
//static 資料型態 資料成員
// 特性：沒有this指標 2.必須在類別外初始化 只能設定一次
// 資料型態 類別名稱::靜態資料名稱 = 初值
//類別外引用靜態資料成員
//類別名稱::靜態資料名稱
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
    static long sumfires;
    static long sumsafes;
    void inputplayer();
    void showplayer();
};
long Baseball::sumfires = 0;
long Baseball::sumsafes = 0;

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
    sumfires += long(fires);
    sumsafes += long(safes);
    
}
float Baseball::countsafe()
{
    float counts;
    counts = float(fires)/float(safes);
    return counts;
    
}

float sumcountsafe()
{
    float sumcounts;
    sumcounts = float(Baseball::sumsafes)/float(Baseball::sumfires);
    return sumcounts;
}

void sumshowplayer()
{
    float sumfs;
    sumfs = sumcountsafe();
    cout<<" The total fire is :" << Baseball::sumfires <<endl;
    cout<<" The total safes is :"<< Baseball::sumsafes <<endl;
    cout<<"The total hit rate: "<< sumfs<<endl;
}

void clearsum()
{
    Baseball::sumfires = 0;
    Baseball::sumsafes = 0;
    cout <<"打擊初始值"<< Baseball::sumfires<<endl;
    cout <<"安打初始值"<< Baseball::sumsafes<<endl;
    
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
    sumshowplayer();
    clearsum();
    return 0;
}
