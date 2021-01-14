//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 運用mutable修飾詞定義常變動的資料
// 13.12
//mutable定義的資料成員 在常數物件及常數函數裡 仍可以被修改

#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char * string;
    int len;
    mutable int index;
public:
    String(char* string_);
    char get_current_char() const;
    int get_cursor() const;
    void show_string();
};

String::String(char* string_) : len(strlen(string_)), index(1)
{
    string = new char[len];
    strcpy(string, string_);
}
char String::get_current_char() const
{
    int index_now = index;
    index++;
    
    if(index > len)
    {index = 1; }
    return *(string + index_now - 1);
}

int String::get_cursor() const
{
    return index;
}

int main()
{
    String A_String("My God");
    const String B_String("My Lord");
    
    for(int i = 1; i <=5; i++)
    {
        cout << "A_String[" << A_String.get_cursor()<< "]=" << A_String.get_current_char() << endl;
    }
    cout << endl;
    
    
    for(int i=1; i<=5; i++)
    {
     cout << "B_String[" << B_String.get_cursor()<< "]=" << B_String.get_current_char() << endl;
    }
    // B式常數物件 但是get.current_char() 及 get_cursor() 皆為常數函數 所以可以呼叫 而使index可以被改掉
    return 0;
}
