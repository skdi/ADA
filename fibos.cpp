#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdint>
#include <cmath>
#include <math.h>
//Ejer2
#define MAXTEST 10000
#define MAXFIB 100
#define m 2
using namespace std;

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

int main(){
	//fibo_ejer3();
	fibo_MX(5);
	//cout<<fiboi_ejer8();
	return 0;
}



/*
int[][] operator* (const int[m][m] &matrix_2)
  {
      int A[m][m];
      T total=0;

      for(int i = 0; i < m; i++) {
          for(int j = 0; j < m; j++) {
              for(int k = 0; k < m; k++) {
                  total += (matrix_2[i][k] * matrix_2[k][j]);
              }
              A.m_matrix[i][j] = total;

              // Limpiar el total sumado arriba
              total = 0;
          }
      }
      return A;
  }
int[][] fibo(int n){

    int A[m][m];
    if(n==1)
    {
      A[0][0]=1;
      A[0][1]=1;
      A[1][0]=1;
      A[1][1]=0;
      return A;
    }
    else
    {
      if(n%2==0)
        A=fibo_Mx(n/2)*fibo_Mx(0.5*n);
      else 
      	A=fibo_Mx(n/2)*fibo_Mx((n+1)*0.5);
      print_matrix(A);
    }

}*/
