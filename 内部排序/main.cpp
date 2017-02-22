#include <iostream>
using namespace std;
#include <fstream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define LS(a,b) ((a)<(b)) //define a<b
#define LL(a,b) ((a)>(b)) // define a>b
#define MAXSIZE 10000

typedef int KeyType;
typedef struct {
    KeyType key;
}RedType;
typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;

int compare=0;
int change=0;
int Create_Sq(SqList &L)
{
    int k;
    cout<<"������Ҫ������������ĸ���--��������ϵͳ���������Ҫ�������С��100��:";
    cin>>k;
    L.length=k;
    srand(time(NULL));
    for (int x=1; x<=k; x++)
    {
        L.r[x].key= rand() % k;//�����Ϊ0~k
    }
    return 1;
}
void Bubble_sort(SqList &L)//ð������
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i,j,l,k=L.length,m=0,n=0;
    for(i=1;i<=L.length-1;++i){
        for(j=1;j<=k-1;++j){
            ++m;
            if(LL(L.r[j].key,L.r[j+1].key)){
                l=L.r[j].key;
                L.r[j].key=L.r[j+1].key;
                L.r[j+1].key=l;
                ++n;
            }
        }
        --k;
    }
    cout<<endl<<"-----ð������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"ð������ıȽϴ���:";
    cout<<m<<endl;
    cout<<"ð������Ľ�������:";
    cout<<n<<endl;
    out<<endl<<"-----ð������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"ð������ıȽϴ���:";
    out<<m<<endl;
    out<<"ð������Ľ�������:";
    out<<n<<endl;
    out.close();
}

void InsertSort(SqList &L)//��������
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i,j,m=0,n=0;
    cout<<endl;
    for(i=2;i<=L.length;++i)
        if(LS(L.r[i].key,L.r[i-1].key))
        {
            ++m;
            ++n;
            L.r[0]=L.r[i];
            L.r[i]=L.r[i-1];
            for(j=i-2;LS(L.r[0].key,L.r[j].key);--j)
            {
                ++m;
                L.r[j+1]=L.r[j];
            }
            L.r[j+1]=L.r[0];
        }
    cout<<"-----ֱ�Ӳ�������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"ֱ�Ӳ�������ıȽϴ���:";
    cout<<m<<endl;
    cout<<"ֱ�Ӳ�������Ľ�������:";
    cout<<n<<endl;
    out<<"-----ֱ�Ӳ�������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"ֱ�Ӳ�������ıȽϴ���:";
    out<<m<<endl;
    out<<"ֱ�Ӳ�������Ľ�������:";
    out<<n<<endl;
    out.close();
}

void SelectSort(SqList &L) //��ѡ������
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int l,i,j,m=0,n=0;
    cout<<endl;
    for(i=1;i<L.length;++i){
        L.r[0]=L.r[i];
        j=i+1;
        l=i;
        for(;j<=L.length;++j){
            ++m;
            if(LL(L.r[0].key,L.r[j].key)){
                l=j;
                L.r[0]=L.r[j];
            }
        }
        if(l!=i){
            ++n;
            L.r[l]=L.r[i];
            L.r[i]=L.r[0];
        }
    }
    cout<<"-----��ѡ������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"��ѡ������ıȽϴ���:";
    cout<<m<<endl;
    cout<<"��ѡ������Ľ�������:";
    cout<<n<<endl;
    out<<"-----��ѡ������������-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"��ѡ������ıȽϴ���:";
    out<<m<<endl;
    out<<"��ѡ������Ľ�������:";
    out<<n<<endl;
    out.close();
}

int Partition(SqList &L,int low,int high){
    int pivotkey;
    L.r[0]=L.r[low];
    pivotkey=L.r[low].key;
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey){
            ++compare;
            --high;
        }
        ++change;
        L.r[low]=L.r[high];
        while(low<high&&L.r[low].key<=pivotkey){
            ++compare;
            ++low;
        }
        ++change;
        L.r[high]=L.r[low];
    }
    L.r[low]=L.r[0];
    return low;
}

void QSort(SqList &L,int low,int high)//�ݹ���ʽ�Ŀ��������㷨
{
    int pivotloc;
    if(low<high){
        pivotloc=Partition(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}

void QuickSort(SqList &L)
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int i;
    QSort(L,1,L.length);
    cout<<"-----��������������Ϊ-----"<<endl;
    for(i=1;i<=L.length;i++)
        cout<<" "<<L.r[i].key;
    cout<<endl;
    cout<<"��������ıȽϴ���:";
    cout<<compare<<endl;
    cout<<"��������Ľ�������:";
    cout<<change<<endl;
    out<<"-----��������������Ϊ-----"<<endl;
    for(i=1;i<=L.length;i++)
        out<<" "<<L.r[i].key;
    out<<endl;
    out<<"��������ıȽϴ���:";
    out<<compare<<endl;
    out<<"��������Ľ�������:";
    out<<change<<endl;
    out.close();
    compare=0;
    change=0;
}

void ShellInsert(SqList &L,int dk)//ϣ������
{
    int i;
    int j;
    for(i=dk+1;i<=L.length;++i)
        if(LS(L.r[i].key,L.r[i-dk].key)){
            ++compare;
            L.r[0]=L.r[i];
            for(j=i-dk;j>0&&LS(L.r[0].key,L.r[j].key);j-=dk){
                ++compare;
                ++change;
                L.r[j+dk]=L.r[j];
            }
            L.r[j+dk]=L.r[0];
        }
}
void ShellSort(SqList &L,int dlta[])//ϣ������
{
    ofstream out;
    out.open("sort.txt",ios::app);
    int k,j=L.length/2,t=0;
    while(j>=0){
        ++t;
        j-=2;
    }
    j=L.length/2;
    for(k=0;k<t;++k)//����ÿ�ε�����ֵ
    {
        if(j==0)
            j=1;//�������һ�����������
        dlta[k]=j;
        j-=2;
    }
    for(k=0;k<t;++k)
    ShellInsert(L,dlta[k]);
    cout<<"-----ϣ������������Ϊ-----"<<endl;
    for(k=1;k<=L.length;k++)
        cout<<" "<<L.r[k].key;
    cout<<endl;
    cout<<"ϣ������ıȽϴ���:";
    cout<<compare<<endl;
    cout<<"ϣ������Ľ�������:";
    cout<<change<<endl;
    out<<"-----ϣ������������Ϊ-----"<<endl;
    for(k=1;k<=L.length;k++)
        out<<" "<<L.r[k].key;
    out<<endl;
    out<<"ϣ������ıȽϴ���:";
    out<<compare<<endl;
    out<<"ϣ������Ľ�������:";
    out<<change<<endl;
    out.close();
    compare=0;
    change=0;
}

int main()
{
    char flag;
    do{
        int i;
        int dlta[MAXSIZE];
        int tem;
        SqList L,a,b,c,d;
        cout<<"-----------------------------------------���˵�-----------------------------------"<<endl;
        cout<<"-----------------------------------�ڲ������㷨�ıȽ�-----------------------------"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        for(tem=0;tem<6;tem++)
        {
            ofstream out;
            if(tem==0){
                out.open("sort.txt");
            }else{
                out.open("sort.txt",ios::app);
            }
            cout<<"��"<<tem+1<<"���������Ƚ�"<<endl;
            out<<"��"<<tem+1<<"���������Ƚ�"<<endl;
            Create_Sq(L);
            a=b=c=d=L;
            for(i=1;i<=L.length;i++)
            {
                cout<<" "<<L.r[i].key;
                out<<" "<<L.r[i].key;
                if(i%20==0) out<<endl;
            }
            out.close();
            Bubble_sort(L);
            InsertSort(a);
            SelectSort(b);
            QuickSort(c);
            ShellSort(d,dlta);
        }
        cout<<"�Ƿ�����ڶ��β���?";
        cin>>flag;
    }while(flag=='y'||flag=='Y');
    return 0;
}
