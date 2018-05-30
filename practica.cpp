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

void generador(vector<double> &A,int n){
	for(int i=0;i++;i<n){
		srand(time(NULL));
		A.push_back(rand()%INT_MAX);
	}
		
}
double max(vector<double> A,int n,double E){
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


int main(){
	vector<double> A;
	double imax;
	for(int n=8;n<=20;n++){
		generador(A,pow(2,n));
		imax=max(A,n);

		A.clear();
	}
	
	return 0;
}
