//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//物件的關係建立  關聯 has a  用指標   在物件裡的物件 不需要先存在
// 聚合 包含   用指標或參考 被聚合物間必須已經先存在
// 組合 裡面的物件與本身的物件生命週期相同 同時消失 用物件宣告 要同時初始化
// 15.1

#include <iostream>
#include <cstring>
using namespace std;

class Tire
{
private:
    char size[10];
public:
    Tire(char* i_size)
    {
        strcpy(size, i_size);
    }
    void show_data()
    {
        cout << " size : " << size <<endl;
    }
};

class Car
{
private:
    Tire ** Tires;
    int Tire_num;
    char brand[20];
    
public:
    Car(char* _brand, Tire ** tire_ , int num)
    {
        strcpy(brand, _brand);
        Tires = tire_;
        Tire_num = num;
    }
    
    void show_data()
    {
        cout << "Output Car Object data......" <<endl;
        cout << "\tbrand : " << brand <<endl;
        
        for(int i = 0; i < Tire_num; i++)
        {
            (*(Tires+i))->show_data();
        }
    }
};


class Eye
{
private:
    char color[10];
public:
    Eye(char* i_color)
    {
        cout << "Initialize Eye Object...." <<endl;
        strcpy(color, i_color);
    }
    void show_data()
    {
        cout << "\t eye color : " << color <<endl;
        
    }
};

class Person
{
private:
    char name[10];
    char sex;
    Eye myEye;
    Car * myCar; // 建立關聯關係 

public:
    Person(char * _name, char _sex, char * _color ): myEye(_color) // 宣告Person物件時 Eye物件同時建立 建立組合關係
    {
        cout << "Initialize Person Object......" <<endl;
        strcpy(name, _name);
        sex = _sex;
    }
    void setCar(Car * aCar)
    {
        myCar = aCar;
        
    }
    
    void show_data()
    {
        cout << endl;
        cout << "Output Person Object data......." <<endl;
        cout << "Name : " << name <<endl;
        cout << "Sex : " << sex <<endl;
        myEye.show_data();
        cout << endl;
        myCar->show_data();
        
    }
};

int main()
{
    char name[20] = "Eric" ;
    char eyecolor[20] = "Yellow" ;
    Person john(name, 'M', eyecolor);
    Tire * anyTire[4];
    anyTire[0] = new Tire("235/100/50");
    anyTire[1] = new Tire("235/100/50");
    anyTire[2] = new Tire("235/100/50");
    anyTire[3] = new Tire("235/100/50");
    
    char brand[10] = "BMW";
    Car aCar(brand,  anyTire, sizeof(anyTire)/sizeof(anyTire[0])); //將輪胎物件傳入建構子 建立  聚合關係
    john.setCar( & aCar);
    john.show_data();
    
    return 0;
    
    
}
