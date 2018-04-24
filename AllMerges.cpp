#include <vector>
#include <iostream>
#include <math.h>
#include <ctime>
#define sizee 50000

using namespace std;
//TOP TO DOWN MERGE
void CopyArray(double *A,double *B){
    for(int i=0;i<sizee;i++){
        B[i]=A[i];
    }
}
void TopDownSplitMerge(double *B,int inicio,int fin,double *A);
void TopdownMerge(double *A, int inicio, int mid, int fin, double *B);

void TopDownMergeSort(double *A,double *B,double n){
    CopyArray(A,B);//copia de A en B
    TopDownSplitMerge(B,0,n,A);//ordenar datos de B hacia A
}
void TopDownSplitMerge(double *B, int inicio, int fin, double *A){
    if(fin-inicio<2)//si el int *era el tamano 1
        return;
    //calculando el pivot
    int mid=(inicio-fin)/2;
    //llamado recursivo para ordenar
    TopDownSplitMerge(A,inicio,mid,B);//ordenamiento de la primera mitad
    TopDownSplitMerge(A,mid+1,fin,B);//ordenamiento de la segunda mitad
    //
    TopdownMerge(B,inicio,mid,fin,A);
}

void TopdownMerge(double *A,int inicio,int mid,int fin,double *B){
    int i=inicio,j=mid;
    //mientras hallan elementos en la
    for(int k=inicio;k<fin;k++){
        if(i<mid && (j>=fin ||A[i]<=A[j])){
            B[k]=A[i];
            i++;
        }else{
            B[k]=A[j];
            j++;
        }
    }
}
//MERGE DIAPOSITIVA

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
void merge(int p, int pi, int r,vector<double> &v)
{
    int B[v.size()];//es un vector auxiliar
    for(int i=p;i<=r;i++)
        B[i]=v[i];
    int izq=p,i=p,izq2=pi+1;//var de apoyo
    while(izq<=pi){
        v[i]=B[izq];
        ++i;
        ++izq;
    }
    while(izq<=pi && izq2<=r){//copiando elementos menores
        if(B[izq]<=B[izq2]){
            v[i]=B[izq];
            ++izq;
        }
        else{
            v[i]=B[izq2];
            ++izq2;
        }
        ++i;
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
void imprimir(double *A){
    for(int i=0;i<sizee;i++)
        cout<<A[i]<<"   ";
    cout<<endl;
}
void imprimir(vector<double> mv){
    for(double i=0;i<mv.size();i++){
        cout<<mv[i]<<"  ";
    }
    cout<<endl;
}


void llenar(vector <double> &v,double n){

    for(double i=0;i<n;i++){
        v.push_back(rand()%100);
    }
}
void CopyArray(vector<double>B,double *A){
    for(int i=0;i<sizee;i++){
        A[i]=B[i];
    }
}


// MERGE BOTTOM-UP
void BottomUpMerge(double *A, int left, int right, int fin, double *B);
void BottomUpMergeSort(double *A,double *B,int n){
    for(int w=1;w<n;w=2*w){
        for(int i=0;i<n;i=i+2*w){
            BottomUpMerge(A,i,min(i+w,n),min(i+2*w,n),B);
        }
        CopyArray(B,A);
    }
}
void BottomUpMerge(double *A,int left,int right,int fin,double *B){
    int i=left,j=right;
    for(int k=left;k<fin;k++){
        if(i<right &&(j>=fin || A[i]<=A[j])){
            B[k]=A[i];
            i++;
        }else{
            B[k]=A[j];
            j++;
        }
    }
}
// INSERTION SORT
void insertionsort(vector<double> &v,double k){
    if(k>v.size())//si k es mayor que el tamaño del vector ,sale
        cout<<"error"<<endl;
    for(double i=0;i<v.size();i++){//recorrido del vector v
        for(double j=i-1;j>=0;j--){//recorrido del vector v menos 1 posicion en direccion inversa
            if(v[j]<=v[j+1])//comparo el valor mayor
                break;
            swap(v[j],v[j+1]);//en caso de estar desordenado ,los cambio
        }
    }
}




int main()
{
    double start_s=clock();
    double *A=new double[sizee];
    double *B=new double[sizee];
    vector <double> mv;
    llenar(mv,sizee);
    CopyArray(mv,A);
    //imprimir(mv);
    //cout<<"ILARI LARI EH ; OH OH OH                 OH "<<endl;
    //merge_sort(0,mv.size()-1,mv);
    //insertionsort(mv,mv.size());
    //imprimir(mv);
    BottomUpMergeSort(A,B,sizee);
    //imprimir(A);

    double stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)<< endl;




   cout<<getmenor(mv);
}
