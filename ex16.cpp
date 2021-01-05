//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//靜態成員函數
//static 傳回值 函數名稱（參數）
//屬於類別層次，與物件無關
//＊＊靜態函數 絕對不可以存取 非靜態成員 **
//也不可宣告為 const
//可由外部直接使用

#include <iostream>
#include <cstdlib>
using namespace std;
class Circle
{
private:
    const static double PI;
   
    int radius;
public:
    static int counter;
    Circle(int r)
{
    radius = r;
    counter++;
}
    double Area() {
        return PI * radius * radius;
    }
    static int getcounter()
    {
        return counter;
    }
};

const double Circle::PI = 3.141592;
int Circle::counter = 0;

int main()
{
    Circle::counter = 5;
    cout << Circle::getcounter()<<endl;
    return 0;
}
