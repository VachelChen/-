//
//  main.cpp
//  BJFU_249
//
//  Created by VachelChen on 2020/7/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;
#define Max 100
int Ack(int m,int n)
{
    int A[m+1][Max];
    for(int i=0;i<Max;i++)
        A[0][i]=i+1;
    for(int i=1;i<=m;i++)
    {
        A[i][0]=A[i-1][1];
        for(int j=1;j<Max;j++)
            A[i][j]=A[i-1][A[i][j-1]];
    }
    return A[m][n];
}

int main(int argc, const char * argv[]) {
    int m,n;
    while (cin >> m >> n) {
        if(!m && !n) break;
        cout<<Ack(m,n)<<endl;
    }
    return 0;
}
