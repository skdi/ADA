#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
unsigned t1,t2,t3,t4;
using namespace std;
int swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void imprimir(vector<double> A,int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void insertSort(vector<double> &v,int ini,int fin)
{
    int j, temp,tam=v.size();
	for (int i=0;i<tam; i++)
    {
		j = i;
		while (j>0 && v[j]<v[j-1])
        {
            swap(v[j],v[j-1]);
            j--;
        }
    }
}
void merge(int l, int pi, int h,vector<double> &v)
{
    int temp[v.size()];
    for(int i=l;i<=h;i++)
        temp[i]=v[i];
    int izq=l,i=l,izq2=pi+1;//var de apoyo
    while(izq<=pi && izq2<=h){//copiando elementos menores
        if(temp[izq]<=temp[izq2]){
            v[i]=temp[izq];
            ++izq;
        }
        else{
            v[i]=temp[izq2];
            ++izq2;
        }
        ++i;
    }
    while(izq<=pi){
        v[i]=temp[izq];
        ++i;
        ++izq;
    }

}
void merge_sort(int izq, int der, vector<double> &p)
{
    int pivot;

    if (der>izq)
    {
        pivot = izq + ((der - izq)/2);
        merge_sort(izq, pivot, p);
        merge_sort(pivot+1, der, p);
        merge(izq, pivot, der, p);

    }
}
void MergeHibrido_insert(int izq,int der,vector<double> &p)
{
    int pivot;
    if(p.size()<=64)
        insertSort(p,izq,der);
    else
    {
       if (der>izq)
        {
            pivot = izq + ((der - izq)/2);
            merge_sort(izq, pivot, p);
            merge_sort(pivot+1, der, p);
            merge(izq, pivot, der, p);
        }
    }
}
void MergeHibrido_quick(int izq,int der,vector<double> &p)
{
    int pivot;
    if(p.size()<=64)
        sort(p.begin(),p.end());
    else
    {
       if (der>izq)
        {
            pivot = izq + ((der - izq)/2);
            merge_sort(izq, pivot, p);
            merge_sort(pivot+1, der, p);
            merge(izq, pivot, der, p);
        }
    }
}
void generator(int n)
{
    vector<double>A;
    vector<double>B;
    for(int i=0;i<n;i++)
        A.push_back(rand()%501);
    B=A;
    cout<<"Vector LLenado"<<endl;
    t1=clock();
    merge_sort(0,n-1,A);
    t2=clock();
    t3 = clock();
    MergeHibrido_quick(0,n-1,B);
    //MergeHibrido_insert(0,n-1,B);
    t4 = clock();
    double tM=(double(t2-t1)/CLOCKS_PER_SEC);
    double tS=(double(t4-t3)/CLOCKS_PER_SEC);
    cout<<"Merge: "<<tM<<endl;
    cout<<"Merge-Quick: "<<tS<<endl;


}
int main()
{
    for(double i=0;i<19;i++){
        cout<<"n="<<pow(2,i)<<endl;
        generator(pow(2,i));
    }
    //generator(500000);

    return 0;
}

