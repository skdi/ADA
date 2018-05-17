#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;
#define n 3
#define m 4
	int A[n];
	int B[m];
	int C[m][n+m+1];
void imprimir(int A[m][m+n+1]){
	for(int i=0;i<m;i++){
		for(int j=0;j<n+m+1;j++){	
			cout<<A[i][j];
		}
		cout<<endl;
	}

}

int* multi_matriz1(int A[n],int B[m],int C[m][m+n+1]){

	int temp=0;
	int l=m+n;
	int k=0;
	int *r= new int(m+n+1);
	for(int i=m-1;i>=0;i--){//B
		l=m+n-k;
		temp=0;
		for(int j=n-1;j>=0;j--){//A
			C[k][l]=(A[j]*B[i])%10+temp;
			if(j==0){
				C[k][l-1]=temp=(int)(A[j]*B[i])/10;
			}
			temp=(int)(A[j]*B[i])/10;
			if(l>0)
				l--;
		}
		k++;
	}
	for(int i=m+n;i<=0;i--)
	{
		temp=0;
		for(int j=0;j>m;j++)
		{
			temp=temp+C[j][i];
		}
		r[i]=temp;
	}
	return r;
}



int main(){

	int *r;
	cout<<"llenando A:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<"llenando B:";
	for(int i=0;i<m;i++){
		cin>>B[i];
	}
	r=multi_matriz1(A,B,C);
	imprimir(C);
	cout<<endl<<"---------------"<<endl;
	for(int i=0;i<m+n+1;i++){
		cout<<"i:"<<i<<" -> "<<r[i]<<endl;
	}

}
