#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
unsigned t1,t2,t3,t4;

void imprimir(vector<int> A,int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void generator(vector<int> &A,int n){
    int a;
    for(int i=0;i<n;i++){
    	cin>>a;
        A.push_back(a);
    }
    imprimir(A,n);
}

int particiona(vector<int> &A,int p,int r){
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r-1;j++){
		if(A[j]<=x){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

int funcion(vector<int> &A,int ini,int fin,int i){
	int piv;
	piv=particiona(A,ini,fin);
	//cout<<piv<<endl;
	if(i==piv)
		return A[piv];
	else if(i>piv){
		funcion(A,piv,fin,i);
	}else if(i<piv){
		funcion(A,0,piv,i);
	}
}


int main(){
	vector<int>A;
	//generator(A,12);
	A.push_back(15);
	A.push_back(10);
	A.push_back(12);
	A.push_back(4);
	A.push_back(6);
	A.push_back(13);
	A.push_back(1);
	A.push_back(5);
	A.push_back(2);
	A.push_back(9);
	A.push_back(10);
	A.push_back(7);
	A.push_back(8);
	//cout<<particiona(A,0,A.size()-1)<<endl;
	//imprimir(A,A.size()-1);
	cout<<funcion(A,0,A.size()-1,2);
	return 0;
}
