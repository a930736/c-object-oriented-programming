//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//有引數及沒有引數的建構子實作 (overload)
#include <iostream>
#include <cstdlib>
using namespace std;
class Time
{
private:
    int hour;
    int min;
    int sec;
public:
    Time(){
        cout << "沒有引數的建構子"<<endl;
    }
    Time(int h, int m, int s)
    {
        cout <<"有引數的建構子"<<endl;
        hour = h;
        min = m;
        sec = s;
    }
    void setTime(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
    }
    int gethour(){
        return hour;
    }
    int getmin() {return min;}
    int getsec() { return sec;}
    
};
int main(){
    Time t1;
    Time t2(10,10,10);
    t1.setTime(12, 12, 12);
    t2.setTime(8, 10, 25);
    
    cout <<"t1 time is: " <<t1.gethour()<<","<<t1.getmin()<<","<<t1.getsec()<<endl;
    cout <<"t2 time is: " <<t2.gethour()<<","<<t2.getmin()<<","<<t2.getsec()<<endl;
    return 0;
    
}
