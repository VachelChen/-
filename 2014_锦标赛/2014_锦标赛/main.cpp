//
//  main.cpp
//  2014_锦标赛
//
//  Created by VachelChen on 2020/2/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

//重新决出k号位置，v为已输出值
void pk(int* a, int* b, int n, int k, int v)
{
    int k1 = k*2 + 1;
    int k2 = k1 + 1;
    
    if(k1>=n || k2>=n){
        b[k] = -1;
        return;
    }
    
    if(b[k1]==v)
        pk(a,b,n,k1,v);
    else
        pk(a,b,n,k2,v);
    
    //重新比较
    if(b[k1]<0){
        if(b[k2]>=0)
            b[k] = b[k2];
        else
            b[k] = -1;
        return;
    }
    
    if(b[k2]<0){
        if(b[k1]>=0)
            b[k] = b[k1];
        else
            b[k] = -1;
        return;
    }
    
    if() //填空
        b[k] = b[k1];
    else
        b[k] = b[k2];
}

//对a中数据，输出最大，次大元素位置和值
void f(int* a, int len)
{
    int n = 1;
    while(n<len) n *= 2;
    
    int* b = (int*)malloc(sizeof(int*) * (2*n-1));
    int i;
    for(i=0; i<n; i++){
        if(i<len)
            b[n-1+i] = i;
        else
            b[n-1+i] = -1;
    }
    
    //从最后一个向前处理
    for(i=2*n-1-1; i>0; i-=2){
        if(b[i]<0){
            if(b[i-1]>=0)
                b[(i-1)/2] = b[i-1];
            else
                b[(i-1)/2] = -1;
        }
        else{
            if(a[b[i]]>a[b[i-1]])
                b[(i-1)/2] = b[i];
            else
                b[(i-1)/2] = b[i-1];
        }
    }
    
    //输出树根
    printf("%d : %d\n", b[0], a[b[0]]);
    
    //值等于根元素的需要重新pk
    pk(a,b,2*n-1,0,b[0]);
    
    //再次输出树根
    printf("%d : %d\n", b[0], a[b[0]]);
    
    free(b);
}


int main()
{
    //int a[] = {54,55,18,16,122,17,30,9,58};
    int a[] = {60,55,18,16,122,17,30,9,58};
    f(a,9);
}
