//
//  main.cpp
//  PAT_B1022
//
//  Created by VachelChen on 2020/3/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long a,b,sum;
    int c;
    cin >> a >> b >> c;
    sum = a + b;
    int z[40];
    int num = 0;
    do{
        z[num++] = sum % c;
        sum = sum/c;
    }while(sum != 0);
    for (int i=num-1; i>=0; i--) {
        cout<<z[i];
    }
    return 0;
}
