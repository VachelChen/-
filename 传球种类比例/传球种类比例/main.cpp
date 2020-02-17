#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>

using namespace std;
//删除字符串中空格，制表符tab等无效字符
string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

float s2i(string str){
    stringstream ss;
    float x;
    ss << str;
    ss >> x;
    return x;
}

float deltax=0;
float deltay=0;
float ybix=0;
int forwardDirection=0;
int player[12][12];
int number=1;
int shoufa=1;
bool flag=false;
map <string,int>m;
map <string,float>x;
map <string,float>y;
map <string,int>num;
//map <string,int>shoot;

void output(){
    for(int i=1;i<=11;i++){
        for(int j=1;j<=11;j++){
            cout<<player[i][j]<<"\t";
        }
        cout<<endl;
    }
    

    cout<<"y/x:"<<(ybix)/(forwardDirection)<<endl;
    cout<<endl;
}


int main()
{
    ifstream fin("/Users/vachelchen/Desktop/2020_Problem_D_DATA/fullevents.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        //cout <<"原始字符串："<< line << endl; //整行输出
        if(number<6221){
            number++;
            continue;
        }
        number++;
        if(number>7828){
            break;
        }
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        string matchID = Trim(fields[0]); //清除掉向量fields中第1个元素的无效字符
        string teamID = Trim(fields[1]); //清除掉向量fields中第2个元素的无效字符
        string oID = Trim(fields[2]); //清除掉向量fields中第3个元素的无效字符
        string dID = Trim(fields[3]); //清除掉向量fields中第4个元素的无效字符
        string MP = Trim(fields[4]); //清除掉向量fields中第5个元素的无效字符
        string eventTime = Trim(fields[5]); //清除掉向量fields中第6个元素的无效字符
        string type = Trim(fields[6]); //清除掉向量fields中第7个元素的无效字符
        string subtype = Trim(fields[7]); //清除掉向量fields中第7个元素的无效字符
        string ox = Trim(fields[8]); //清除掉向量fields中第8个元素的无效字符
        string oy = Trim(fields[9]); //清除掉向量fields中第9个元素的无效字符
        string dx = Trim(fields[10]); //清除掉向量fields中第10个元素的无效字符
        string dy = Trim(fields[11]); //清除掉向量fields中第11个元素的无效字符
        
        if (matchID == "5"){
            
            if(type == "Substitution"){
                cout<<eventTime<<"   "<<teamID<<"发生一次换人"<<oID<<"->"<<dID<<endl;
            }
            
            if(type != "Shot" )  continue;
            
            cout<<eventTime<<"  "<<teamID<<"队员："<<oID<<"发起一次射门,位置在"<<ox<<" "<<oy<<endl;
        }
    }
        
    
    return EXIT_SUCCESS;
}

