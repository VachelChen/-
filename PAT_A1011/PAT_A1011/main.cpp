//
//  main.cpp
//  PAT_A1011
//
//  Created by VachelChen on 2020/5/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

double a[3][3];
char c[3];


int main(int argc, const char * argv[]) {
    c[0] = 'W';
    c[1] = 'T';
    c[2] = 'L';
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> a[i][j];
        }
    }
    
    double ans = 1;
    for (int i=0; i<3; i++) {
        int maxc = -1;
        double maxa = 0;
        for (int j=0; j<3; j++) {
            if(a[i][j] > maxa){
                maxc = j;
                maxa = a[i][j];
            }
        }
        cout<<c[maxc]<<" ";
        ans *= maxa;
    }
    printf("%.2f\n",(ans*0.65-1)*2);
    return 0;
}
