#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;
//typedef vector<int> vect;
unsigned int t1,t2;
//int max = INT_MAX; 888888
int cont;
void imprime(vector<double> A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void generador(vector<double> &A,int n){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		A.push_back(rand()%INT_MAX);
	}

}
double max(vector<double> A,int n){
	int contador=0;
	double max=0;
	for(int i=0;i<n;i++){
		if(A[i]>max){
			max=A[i];
			contador++;
		}
	}
	return contador;
}

int main2(){
	vector<double> A;
	vector<double> E;
	double imax;
	double prom;
	int N;
	N=10;
	for(int n=8;n<=20;n++){
		imax=0;
		for(int j=0;j<N;j++){
			generador(A,pow(2,n));
			imax+=max(A,n);
			A.clear();
		}
		E.push_back(imax/N);

	}
	for(int i=0;i<E.size();i++){
		cout<<"i: "<<i<<"n: "<<pow(2,(i+8))<<"E[n]: "<<E[i]<<endl;
	}
	return 0;
}

int particion(vector<double> A,int p,int r){
	int pivot=A[r];
	int i=(p-1);
	for(int j=p;j<=r-1;j++){
		if(A[j]<=pivot){
			i++;
			swap(A[i],A[j]);
			cont++;
		}
	}
	swap(A[i+1],A[r]);cont++;
	return (i+1);
}
void quicksort(vector<double> &A,int p,int r){
	int q;
	if(p<r){
		q=particion(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(){
	vector<double> A;
	vector<double> E;
	double imax;
	double prom;
	//var para el promedio
	int N;
	N=10;
	//generando vectores de 2^n;8<n<20
	for(int n=8;n<=20;n++){
		imax=0;
		for(int j=0;j<N;j++){
			cont=0;
			generador(A,pow(2,n));
			quicksort(A,0,int(A.size())-1);
			imax+=cont;
			//cout<<cont<<endl;
			A.clear();
		}
		prom=imax/N;
		E.push_back(cont);
	}
	for(int i=0;i<E.size();i++){
		cout<<"i: "<<i<<" |n: "<<pow(2,(i+8))<<" |E[n]: "<<E[i]<<endl;
	}
	return 0;
}
