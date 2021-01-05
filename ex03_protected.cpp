//
//  main.cpp
//  exercise03
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
// protected 應用
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Cat{
private:
    int Size;
protected:
    int Sex;
public:
    void setsize(int size) {
        Size = size;
    }
};
class Lion(Cat){
public:
    void Setsex(int sex) {
        Sex = sex;
        
    }
};

int main(){
    Lion lion;
    lion.Setsex(0);
    lion.setsize(300);
    
}
