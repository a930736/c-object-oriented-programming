//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//類別與結構實作
#include <iostream>
#include <cstdlib>
using namespace std;
struct Data
{
    char name[10];
    int height;
};

class Date
{
private:
    int year;
    int month;
    int day;
public:
    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
        
    }
    int getYear(){
        return year;
    }
    int getMonth(){
        return month;
    }
    int getDay(){
        return day;
    }
};

class Person
{
private:
    Date birthday;
    Data data;
public:
    void setAllData(Date d1, Data d2) {
        birthday.setDate(d1.getYear(), d1.getMonth(), d1.getDay());
        strcpy(data.name,d2.name);
        data.height = d2.height;
    }
    void printAllData(){
        cout<<"Name: " <<data.name<<endl;
        cout<<"Height: "<<data.height <<endl;
        cout<<"Birthday: "<<birthday.getYear()<<","<<birthday.getMonth()<<","<<birthday.getDay()<<endl;
    }
};

int main(){
    Date d1;
    d1.setDate(1999, 3, 6);
    Data d2;
    d2.height = 175;
    strcpy(d2.name,"Eric");
    Person p;
    p.setAllData(d1,d2);
    p.printAllData();
    return 0;
    
}
