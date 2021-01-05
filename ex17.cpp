//
//  main.cpp
//  ex04
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//
//巢狀類別
//Ａ類別包含Ｂ類別，Ａ稱為外圍類別，Ｂ稱為巢狀類別，且Ｂ的有效作用範圍在Ａ內
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Bookshelf
{
private:
    static int Max_book;
    int count;
    char * name;
    class Book
    {
    private:
        char *title;
        int price;
    public:
        Book(char* t,int p)
        {
            title = new char[strlen(t)+1];
            strcpy(title,t);
            price = p;
        }
        
        char * getTitle()
        {
            return title;
        }
        int getPrice(){
            return price;
        }
    };
    Book *book[8];
public:
    Bookshelf(char* n)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        count = 0;
        
    }
    void Insertbook(char*t, int p)
    {
    if(count == Max_book)
    {
        cout <<"The bookself is full"<<endl;
    }
        book[count++] = new Book(t,p);
    }
    
    void ListAllbooks()
    {
        cout <<"["<<name<<"]"<<endl;
        for (int i = 0;i < count;i++)
        {
            cout <<book[i]->getTitle()<<"定價是："<<book[i]->getPrice()<<endl;
        }
    }
};

int Bookshelf::Max_book = 8;
int main()
{
    Bookshelf A("圖書館Ａ號書架");
    A.Insertbook("python3", 100);
    A.Insertbook("C++", 1000);
    A.Insertbook("C#", 740);
    A.Insertbook("C", 950);
    A.Insertbook("Java", 850);
    A.Insertbook("Javascript", 580);
    A.Insertbook("MySQL", 1200);
    A.Insertbook("Flash", 150);
    A.ListAllbooks();
}
