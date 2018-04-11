#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <time.h>
#include <stdlib.h>

using namespace std;

void merge(int, int, int, vector<double> &v);
void merge_sort(int izq, int der, vector<double> &p){
    int pivot;
    if (der>izq)
    {

        pivot = izq + ((der - izq)/2);

        merge_sort(izq, pivot, p);
        merge_sort(pivot+1, der, p);
        merge(izq, pivot, der, p);

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

void swap(double &a,double &b){
    double temp;
    temp=a;
    a=b;
    b=temp;
}
double getmenor(vector<double> v){
    for(double i=0;i<v.size();i++){
        if(v[i]>v[i+1])
            v[i]=0;
        else
            v[i+1]=0;

    }
    for(double j=0;j<v.size();j++){
    if(v[j]!=0)
        return v[0];
    }

}
void imprimir(vector<double> mv){
    for(double i=0;i<mv.size();i++){
        cout<<mv[i]<<"  ";
    }
    cout<<endl;
}


void llenar(vector <double> &v,double n){
    srand(time(NULL));  
  
    for(double i=0;i<n;i++){
        v.push_back(rand()%100);
    }
}
void llenar2(vector <double> &v){
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        cin>>a;
        v.push_back(a);
    }
}

int insertionsort(vector<double> &v,double k){
    int cont=0;
    if(k>v.size())//si k es mayor que el tamaño del vector ,sale
        cout<<"error"<<endl;
    for(double i=0;i<v.size();i++){//recorrido del vector v
        for(double j=i-1;j>=0;j--){//recorrido del vector v menos 1 posicion en direccion inversa
            if(v[j]<=v[j+1])//comparo el valor mayor
                break;
            swap(v[j],v[j+1]);//en caso de estar desordenado ,los cambio
            cont++;
        }
    }
    return cont;
}

int burbuja(vector<double> &v){
    int cont=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[i]){
                swap(v[j],v[i]);
                cont++;
            }
        }
    }
}
void llenar2(vector<double> &v,int size){
    int i=0;int a;
    while(i<size){
        cin>>a;
        v.push_back(a);
        i++;
    }
}

int main()
{
    double start_s=clock();

    vector <double> mv;
    llenar2(mv);
    //burbuja(mv);
    imprimir(mv);
    //cout<<"ILARI LARI EH ; OH OH OH                 OH "<<endl;
    //merge_sort(0,mv.size()-1,mv);
    cout<<"Optimal train swapping takes: "<<insertionsort(mv,mv.size())<<" swaps"<<endl;
    imprimir(mv);

    //double stop_s=clock();
    //cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<"ms"<< endl;




   cout<<getmenor(mv);
}
