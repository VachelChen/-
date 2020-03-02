//
//  main.cpp
//  codeup_查找元素_统计同城学生人数
//
//  Created by VachelChen on 2020/3/2.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct student{
    string num;
    string name;
    string sex;
    int age;
};

int main(int argc, const char * argv[]) {
    int m;
    cin>>m;
    while(m--){
        int n,i,j;
        cin>>n;
        student stu[100];
        for(i=0;i<n;i++){
            cin>>stu[i].num>>stu[i].name>>stu[i].sex>>stu[i].age;
        }
        
        string number;
        cin>>number;
        
        for(j=0;j<n;j++){
            if(stu[j].num == number){
                    cout<<stu[j].num<<" "<<stu[j].name<<" "<<stu[j].sex<<" "<<stu[j].age<<endl;;
                    break;
                }
            }
        }
    return 0;
}
