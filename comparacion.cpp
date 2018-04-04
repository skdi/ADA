#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


int swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int getmenor(vector<int> v){
    for(int i=0;i<v.size();i++){
        if(v[i]>v[i+1])
            v[i]=0;
        else
            v[i+1]=0;

    }
    for(int j=0;j<v.size();j++){
    if(v[j]!=0)
        return v[0];
    }

}
void imprimir(vector<int> mv){
    for(int i=0;i<mv.size();i++){
        cout<<mv[i]<<"  ";
    }
    cout<<endl;
}


void insertionsort(vector<int> &v,int k){
    int a;
    for(int i=0;i<k;i++){
        a=i;
        while(a>0 && (v[a]<v[a-1])){
            swap(v[a],v[a-1]);
            a--;
            }
    }
}

void burbujita(vector<int> &v,int n){
    for(int i=2;i<n;i++){
       for(int j=0;i<n-i;j++){
        if(v[j]>v[j+1])
            swap(v[j],v[j+1]);
       }
    }
}


void llenar(vector <int> &v,int n){

    for(int i=0;i<n;i++){
        v.push_back(rand()%100);
    }
}

int main()
{

    vector <int> mv;
    llenar(mv,100);
    imprimir(mv);
    //insertionsort(mv,mv.size());
    burbujita(mv,mv.size());
    imprimir(mv);

}
