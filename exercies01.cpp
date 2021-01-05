//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
class student {
private:
    string birth;
    string tel;
    struct grade{
        string subject[3];
        int score[3];
    } sgrade;
public:
    string name;
    char sex;
};
int main() {
    cout << "class student所占記憶體空間：" << sizeof(class student)<< endl;
    system("pause");
    return 0;
}
