//
//  main.cpp
//  快排
//
//  Created by VachelChen on 2020/3/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

int Partition(int a[],int left,int right){
    int temp = a[left];
    //必需先从右开始看不能搞反
    while(left<right){  //在while内部也要检测left<right
        while(a[right]>temp && left<right){right--;}
        a[left] = a[right];
        while(a[left]<temp && left<right){left++;}
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

void quickSort(int a[],int left,int right){
    if(left<right){
        int pos = Partition(a,left,right);
        quickSort(a,left,pos-1);
        quickSort(a,pos+1,right);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int a[100];
    for(int i=0;i<n;i++)
        cin >> a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout << a[i];
    return 0;
}
