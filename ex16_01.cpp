//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多型
//1.多載 overloading 函數名稱相同 但是參數不同
//2.覆寫 overriding  發生在繼承 物件不同但函數名稱相同 衍生會覆寫
//3.動態連結 Dynamic Binding  發生在繼承 物件不同但函數名稱相同 呼叫基礎函數時 作用卻發生在衍生類別 利用指標
// 16.1

#include <iostream>
#include <cstring>
using namespace std;

class object
{
protected:
    char color[10];
    char type[10];
public:
    object(char * _type, char * _color)
    {
        strcpy(type, _type);
        strcpy(color, _color);
        
    }
    
};

class shoe : public object
{
private:
    friend class person;
public:
    shoe(char * type, char * color ): object(type, color){}
};

class clothes: public object
{
private:
    friend class person;
public:
    clothes(char* type, char * color):object(type, color){}
    
};

class pants : public object
{
private:
    friend class person;
public:
    pants(char* style , char * color) : object(style, color) {}
    
};

class person
{
protected:
    char last_name[5];
    char first_name[15];
    clothes * my_clothes;
    shoe * my_shoes;
    pants * my_pants;
    
public:
    person(const char* l_name, const char * f_name)
    {
        strcpy(last_name, l_name);
        strcpy(first_name, f_name);
    }
    void wear( shoe & a_shoe)
    {
        cout << "The wear(shoe & a_shoe) is called. " <<endl;
        my_shoes = & a_shoe;
    }
    void wear( pants & a_pants)
    {
        cout << "The wear(pants & a_pants) is called. " <<endl;
        my_pants= & a_pants;
    }
    void wear( clothes & a_clothes)
    {
        cout << "The wear(clothes & a_clothes) is called. " <<endl;
        my_clothes = & a_clothes;
    }
    
    void show_data()
    {
        cout << "My name is : " << last_name << " " << first_name <<endl;
        cout << "I wear a " <<my_clothes->color << " " << my_clothes->type <<endl;
        cout << ", a " << my_pants->color << " " << my_pants->type << endl;
        cout << "  and " << my_shoes->color << " " << my_shoes->type << endl;
        
    }
};


int main()
{
    person John("Josh", "Wang");
    clothes a_clothes("T shirt" , " white");
    pants a_pants("short", " green");
    shoe a_shoes("gym shoes" ," black");
    John.wear(a_clothes);
    John.wear(a_pants);
    John.wear(a_shoes);
    
    John.show_data();
    return 0 ;
    
}

