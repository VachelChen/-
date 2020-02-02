//
//  main.cpp
//  2019_数列求值
//
//  Created by VachelChen on 2020/2/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//

//给定数列1, 1, 1, 3, 5, 9, 17, …，从第4 项开始，每项都是前3 项的和。求
//第20190324 项的最后4 位数字。

#include <iostream>
using namespace std;

long long a[20190325];


int main(int argc, const char * argv[]) {
    // insert code here...
    a[1]=1;
    a[2]=1;
    a[3]=1;
    for(long long i=4;i<=20190325;i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10000;
    }
    cout<<a[20190324]<<endl;
    return 0;
}
