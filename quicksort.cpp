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
/**void QuickSort(vector<int> &arr,int ini,int fin)
{
    int i=ini,j=fin;
    int p=arr[(ini+fin)/2];
    while(i<=j)
    {
        while(arr[i]<p)i++;
        while(arr[j]>p)j--;
        if(i<=j)
        {
            swap(arr[i],arr[j]);
            i++;j--;
        }

    }
    if(ini<j)
        QuickSort(arr,ini,j);
    if(i<fin)
        QuickSort(arr,i,fin);

}*/
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
void MergeHibrido(int izq,int der,vector<double> &p)
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
void generator(int n)
{
    vector<double>A;
    vector<double>B;
    for(int i=0;i<n;i++)
        A.push_back(rand()%501);
    B=A;
    t3=clock();
    sort(B.begin(),B.end());
    t4=clock();
    t1 = clock();
    MergeHibrido(0,n-1,A);
    t2 = clock();
    double tM=(double(t2-t1)/CLOCKS_PER_SEC);
    double tS=(double(t4-t3)/CLOCKS_PER_SEC);
    cout<<tM<<endl;
    cout<<tS<<endl;
    ///imprimir(B,n);
}
int main()
{
    generator(500000);

    return 0;
}

