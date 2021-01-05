//
//  main.cpp/Users/peter/Desktop/test/c-object-oriented-programming/ex02postoffice.cpp
//  exercise-postoffice
//
//  Created by  Peter on 2021/1/5.
//  Copyright © 2021  Peter. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
/* 郵局提款 */
class postoffice{
private:
    int savings;
public:
    string name;
    static int totsavings;
    int initial() {
        savings = 0;
        return savings;
    }
    int save(){
        cout << "Hello" << name << "\n";
        cout << "請輸入提款金額（負代表提款）:";
        int money;
        cin >> money;
        savings += money;
        return money;
    }
    /*計算郵局總存款餘額 */
    static void operate(int money){
        totsavings += money;
    }
    /*查詢個人餘額*/
    int look(){
        return savings;
    }
};
int postoffice::totsavings = 0;

int main(){
    class postoffice people[2];
    int choose;
    int customer;
    people[0].initial();
    people[1].initial();
    people[0].name = "David";
    people[1].name = "Mary";
    int deposit;
    
    while(1) {
        cout << " 1.存款作業 2.查詢存款  3.查詢郵局總存款  0.結束 :";
        cin >> choose;
        if(choose == 0){
            break;
        }
        switch (choose) {
            case 1:
                cout <<"存提款作業\n";
                cout <<"輸入存戶編號：0 or 1" ;
                cin >> customer;
                if (customer == 0 || customer == 1){
                    deposit = people[customer].save();
                    people[customer].operate(deposit);
                }
                else
                    cout << "Error !\n";
                break;
            case 2 :
                cout <<"查詢存款作業\n";
                cout <<"輸入存戶編號：0 or 1" ;
                cin >> customer;
                if (customer == 0 || customer == 1){
                    cout << people[customer].name <<"存款餘額為："
                    << people[customer].look() << endl;
                }
                else
                    cout << "Error !\n";
                break;
                
            case 3:
                cout << "郵局總存款為" << postoffice::totsavings << endl;
                break;
            default:
                cout << "Error !\n" ;
                break;
        }
    }
    return 0;
}
