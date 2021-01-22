//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多載運算子 擴充物件的運算子功能 overloading
// 類別轉換運算子
//
// 13.26


#include <iostream>
#include <cstring>
using namespace std;

class centimeter
{
private:
    float cm;
    static char unit[3];
    friend class meter;
public:
    centimeter(float cm) : cm(cm) {}
    void show_data()
    {
        cout << cm << unit <<endl;
    }
};

char centimeter::unit[3] = "cm";

class meter
{
private:
    float m ;
    static char unit[2];
public:
    meter(float m): m(m) {}
    meter(centimeter cm ): m(cm.cm/100){}// 型別轉換建構子
    operator centimeter()
    {
        return centimeter(m*100);
    }
    void show_data()
    {
        cout << m << unit <<endl;
    }
};
char meter::unit[2] = "m";

int main()
{
    meter my_meter(1.25);
    centimeter my_cm(0);
    my_cm = my_meter;
    my_cm.show_data();
    
    meter my_meter2(my_cm);
    my_meter2.show_data();
}
