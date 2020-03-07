//
//  main.cpp
//  PAT_B1036
//
//  Created by VachelChen on 2020/3/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    char c;
    cin >> n >> c;
    for(int i=0;i<round(n*1.0/2);i++){
        for (int j=0; j<n; j++) {
            if(i == 0 || i == round(n*1.0/2)-1 || j == 0 || j == n-1)
                cout<<c;
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
