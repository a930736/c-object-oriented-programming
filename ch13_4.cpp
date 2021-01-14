//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class Reader
{
    private:
        char name[10]
    public:
        long index;
        Reader(char*A)
    {
        cout << "Reader's constructor is called!" << endl;
        set_name(A);
        index = 1;
    }
    
        char* get_name()
    {
        return name;
    }
};

void Reader::set_name(char* B)
{
    strcpy(name,B);
}

int main()
{
    char name[10];
    cout << "Please input your name ?";
    cin >> name;
    
    Reader A_reader(name);
    cout << "Your name is : ";
    cout << A_reader.get_name();

    cout<< "index " << A_reader.index <<<endl;
    return 0;
}
