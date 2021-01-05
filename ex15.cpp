//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//靜態常數資料成員實作（同一類別的物件此資料成員是共用的）
//const static 資料型態 資料成員
//靜態資料分兩種 static  及 const static

#include <iostream>
#include <cstdlib>
using namespace std;
class Circle
{
private:
    const static double PI;
    static int count;
    int radius;
public:
    Circle(int r)
{
    radius = r;
    count++;
}
    double Area() {
        return PI * radius * radius;
    }
    int getcounter()
    {
        return count;
    }
};

const double Circle::PI = 3.141592;
int Circle::count = 0;

int main()
{
    Circle c1(3);
    cout <<" Area is : "<< c1.Area()<<endl;
    Circle c2(5);
    cout <<" Area is : "<< c2.Area()<<endl;
    cout <<"由c1取出："<<c1.getcounter()<<endl;
    cout <<"由c2取出："<<c2.getcounter()<<endl;
    return 0;
}
