#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdint>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;
typedef int c_matrix;
typedef vector< vector<c_matrix> > matrix;
//Ejer2
#define MAXTEST 10000
#define MAXFIB 100
#define m 2

#define uint64_t unsigned long long int
uint64_t fibo_ejer1(uint64_t n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else return fibo_ejer1(n-1)+fibo_ejer1(n-2);
}
void fibo_ejer3(){
	srand(time(NULL));
	for(uint64_t i=0;i<MAXTEST;i++){
		cout<<fibo_ejer1(rand()%MAXFIB)<<" ";
	}
	cout<<endl;

}
uint64_t fiboi_ejer4(uint64_t n){
	uint64_t fibo[n];
	fibo[0]=0;
	fibo[1]=1;
	for(uint64_t i=2;i<=n;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	return fibo[n];
}

uint64_t fiboi_ejer6(uint64_t n,uint64_t c){
    uint64_t f1=0;
    uint64_t f2=1;
    uint64_t acum=0;
    if(n==1)
      return 1;
    if(n==0)
      return 0;
    for(uint64_t i=2;i<=n;i++)
    {
      acum=((f1%c)+(f2%c))%c;
      f1=f2;
      f2=acum;
    }
    return acum;
 }

uint64_t fiboi_ejer7(uint64_t n){
	uint64_t fant=0;
	uint64_t fact=1;
	uint64_t i=1;
	uint64_t faprox;
	while(i<n){
		faprox=fant+fact;
		fant=fact;
		fact=faprox;
		i++;
	}
	return fact;

}
uint64_t fiboi_ejer8(){
	fiboi_ejer6(1000000,pow(2,20));
}
void print_matrix(int A[m][m]){

    cout<<endl;
      for (int i = 0; i < m; i++) {
          for (int j = 0; j < m; j++) {
              cout << A[i][j] << " ";
          }
          cout << endl;
      }
      cout<<endl;
  }

int fibo_MX(int n){
	int A[m][m];
      A[0][0]=fiboi_ejer6(n,pow(2,20));
      A[0][1]=fiboi_ejer6(n-1,pow(2,20));
      A[1][0]=fiboi_ejer6(n-1,pow(2,20));
      A[1][1]=fiboi_ejer6(n-2,pow(2,20));
      print_matrix(A);
      return A[0][0];
}

void CreateMatrix(matrix *&Arr,int  n,int c){
  Arr = new matrix(n);
  for(int i = 0; i < n; ++i)
    (*Arr)[i].resize(c);
}
matrix *ProductMatrix(matrix *A, matrix *B, int n){
  matrix * R;
  CreateMatrix(R,n,n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int k = 0; k < n; ++k)
        (*R)[i][j] += (*A)[i][k] * ((*B)[k][j]);
  return R;
}


matrix* fibo_m(int n){
  
    matrix *A;
    CreateMatrix(A,m,m);
    matrix *temp; matrix *temp2;

    
    if(n==1)
    {
      (*A)[0][0]=1;
      (*A)[0][1]=1;
      (*A)[1][0]=1;
      (*A)[1][1]=0;
      return A;
    }
    else
    {
      if(n%2==0){
        A=ProductMatrix(fibo_m(n/2),fibo_m(n/2),m);
      }
      else 
        A=ProductMatrix(fibo_m(n/2),fibo_m((n+1)/2),m);
      return A;
    }

}



int main(){
  for(int i=1;i<=10;i++){
    cout<<(*fibo_m(i))[0][0]<<endl;
  }

	//fibo_MX(5);
	//cout<<fiboi_ejer8();
	return 0;
}




