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
class Student
{
private:
    int ID;
    float Score_E, Score_M, Score_T;
public:
    Student(int id,float E, float M) {
        ID = id;
        Score_E = E;
        Score_M = M;
        Score_T = E + M;
        cout <<"Student ID: "<< ID<<endl;
        cout<<"Total score is :" << Score_T<<endl;
        cout <<"address of this pointer: " << this <<endl;
    }
};

int main()
{
    Student A(103012, 90, 100);
    cout <<"stu 物件位址： "<< &A <<endl;
    return 0;
}
