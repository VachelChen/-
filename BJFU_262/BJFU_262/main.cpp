#include<iostream>
#include<cstring>
#include<string>
 
using namespace std;
 
struct Num
{
    char ch;
    int num;
}an[7000], temp;
 
void sort1(Num *bn)
{
    Num te;
    int i, j;
    for (j = 0; j<26; j++)
        for (i = 0; i < 25; i++)
        {
            if (bn[i].num < bn[i + 1].num)
            {
                te = bn[i];
                bn[i] = bn[i + 1];
                bn[i + 1] = te;
            }
        }
}
 
void sort2(Num *bn, int n)
{
    Num te;
    int i, j;
    for (j = 0; j<n; j++)
        for (i = 0; i < n-1; i++)
        {
            if (bn[i].ch > bn[i + 1].ch && bn[i + 1].num > 0)
            {
                te = bn[i];
                bn[i] = bn[i + 1];
                bn[i + 1] = te;
            }
        }
}
 
typedef struct
{
    int weight;
    int parent, lchild, rchild;
    char ch;
    char strc[60];
    int len;
    int num;
}HTNode, *HuffmanTree;
 
void Select(HuffmanTree &HT, int k, int &s1, int &s2)
{
    int i;
    HTNode h1, h2;
    int t1, t2;
    t1 = t2 = 0;
    h1.weight = 999999;
    for (i = 1; i <= k; i++)
    {
        if (HT[i].weight <= h1.weight &&HT[i].parent == 0)
        {
            h1 = HT[i];
            t1 = i;
        }
    }
    h2.weight = 999999;
    for (i = 1; i <= k; i++)
    {
        if (HT[i].weight <= h2.weight&&t1 != i&&HT[i].parent == 0)
        {
            h2 = HT[i];
            t2 = i;
        }
    }
 
    if (h1.weight == h2.weight && HT[t1].num > HT[t2].num)
    {
        int temp;
        temp = t1;
        t1 = t2;
        t2 = temp;
    }
 
    s1 = t1;
    s2 = t2;
    return;
}
 
void code(HuffmanTree &HT, int len, char str[], int n, char cc)
{
    int i;
    for (i = 0; i < len - 1; i++)
        HT[n].strc[i] = str[i];
    HT[n].strc[i] = cc;
    HT[n].strc[i + 1] = '\0';
    if (HT[n].lchild != 0)
        code(HT, len + 1, HT[n].strc, HT[n].lchild, '0');
    if (HT[n].rchild != 0)
        code(HT, len + 1, HT[n].strc, HT[n].rchild, '1');
}
 
void CreateHuffmanTree(HuffmanTree &HT, int n, char *str, int n1)
{
    int s1, s2;
    s1 = s2 = 0;
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];
 
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0; HT[i].len = 0; HT[i].num = i; HT[i].weight = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = an[i - 1].num;
        HT[i].ch = an[i - 1].ch;
    }
    for (int i = n + 1; i <= m; i++)
    {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    if (HT[m].lchild)
        code(HT, 1, "", HT[m].lchild, '0');
    if (HT[m].rchild)
        code(HT, 1, "", HT[m].rchild, '1');
    return;
}

int main()
{
    HuffmanTree h;
    int n, n1;
    char str[700], str2[700];
    while (cin >> str)
    {
        if (str[0] == '0'&&str[1] == '\0')
            break;
        n1 = 0;
        //其实map可以用一个2元的结构体取代
        for (int i = 0; i < 27; i++)
        {
            an[i].num = 0;
            an[i].ch = 'a' + i;
        }
        n = (int)strlen(str);
        for (int i = 0; i < n; i++)
        {
            an[str[i] - 'a'].num++;
            str2[i] = str[i];
            str2[i + 1] = '\0';
        }
        sort1(an);
        for (int i = 0; i < 26; i++)
        {
            if (an[i].num != 0)
                n1++;
        }
 
        sort2(an, n1);
 
        CreateHuffmanTree(h, n1, str, n1);
        if (n1 == 1)
        {
            h = new HTNode[3];
            h[1].weight = n; h[1].parent = h[1].lchild = h[1].rchild = 0;
            h[1].ch = str[0]; h[1].strc[0] = '0'; h[1].strc[1] = '\0';
        }
        int f = 0;
        for (int i = 0; i < 26; i++)
            if (an[i].num > 0)
            {
                f++;
                cout << an[i].ch << ":" << an[i].num ;
                if (f == n1)
                    cout << endl;
                else
                    cout << " ";
            }
 
 
 
        for (int i = 1; i <= 2 * n1 - 1; i++)
        {
            cout << i << " " << h[i].weight << " " << h[i].parent << " " << h[i].lchild << " " << h[i].rchild << endl;
        }
 
        for (int i = 1; i < n1; i++)
            cout << h[i].ch << ":" << h[i].strc << " ";
        cout << h[n1].ch << ":" << h[n1].strc;
        cout << endl;
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n1; j++)
                if (h[j].ch == str[i])
                    cout << h[j].strc;
        }
        cout << endl;
        cout << str << endl;
 
        for (int i = 1; i <= 2 * n1 - 1; i++)
        {
            h[i].parent = 0; h[i].lchild = 0; h[i].rchild = 0; h[i].len = 0; h[i].num = i;
        }
    }
 
    return 0;
}

