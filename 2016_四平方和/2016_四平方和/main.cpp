//
//  main.cpp
//  2016_四平方和
//
//  Created by VachelChen on 2020/2/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void computing(int n){
    for(int i=0;i<=sqrt(n);i++)
    for(int j=i;j<=sqrt(n);j++)
        for(int k=j;k<=sqrt(n);k++)
            for(int m=k;m<=sqrt(n);m++){
                if(i*i+j*j+k*k+m*m == n){
                    cout<<i<<" "<<j<<" "<<k<<" "<<m<<endl;
                    return ;
                }
            }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    computing(n);
    return 0;
}
