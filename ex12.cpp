//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//使用this 指標來回傳物件
#include <iostream>
#include <cstdlib>
using namespace std;
class Cubic
{
    int a;
public:
    Cubic(int n){
        a =n*n*n;
    }
    Cubic cub_sum(Cubic b){
        this->a = this->a +b.a;
        return *this;
    }
    int show_data(){
        cout <<this->a << endl;
        return 0;
    }
};
int main()
{
    int n1, n2;
    cout<<"Enter the first number: ";
    cin >> n1;
    cout<<"Enter the second number: ";
    cin >> n2;
    Cubic first(n1);
    Cubic second(n2);
    Cubic third(0);
    third.show_data();
    third = first.cub_sum(second);
    third.show_data();
    return 0;
}
