#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <time.h>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
ifstream archivo;

string abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cont=0;
int particion(vector<char> A,int p,int r){
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
void quicksort(vector<char> A,int p,int r){
	int q;
	if(p<r){
		q=particion(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
void insertSort(vector<char> v,int ini,int fin)
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
int orden(string contra){
	vector<char> temp;
	for(int i=0;i<contra.size();i++)
		temp.push_back(contra[i]);
	cont=0;
	quicksort(temp,0,temp.size()-1);
	return cont;

}
int get_menor(int temp[],int n){
	int pos=0;
	int min=500000;
	for(int i=0;i<n;i++){
		if(temp[i]>=0 && temp[i]<min){
			min=temp[i];
		}		
	}
	for(int i=0;i<n;i++){
		if(temp[i]==min)
			pos=i;
	}
	return pos;

}
void imprimir(vector<char> temp,int n){
	for(int i=0;i<=n;i++){
		cout<<temp[i];
	}
	cout<<endl;
}
/*string cast(vector<char> temp,int n){
	string aux;
	for(int i=0;i<=n;i++){
		aux[i]=vector[i]
	}

}*/
void contrasenha(int n,int m){
	string contra;
	int temp[n];
	vector<string> aux;
	int min;
	vector<string> aux2;

	for(int i=0;i<n;i++){//lectura
		cin>>contra;
		if(contra.size()<=m){//calculo del orden en el cual se imprimiran los strings
			temp[i]=orden(contra);
			aux.push_back(contra);//almacen de contrasenhas
		}
	}
	for(int i=0;i<n;i++){	//ya tenemos el orden,solo falta imprimirlos
		min=get_menor(temp,n);//ordenados
		vector<char> tempx;
		contra=aux[min];
		for(int i=0;i<contra.size();i++){//cast de string a vector<char>
			tempx.push_back(contra[i]);}
		quicksort(tempx,0,tempx.size()-1);//ordenamos vector char
		//cast(tempx,n);//damos la respuesta
		string zz(tempx.begin(),tempx.end());
		aux2.push_back(zz);
		temp[min]=-1;//marcamos la posicion 
	}
	for(int i=n-1;i>=0;i--){
		cout<<aux2[i]<<endl;
	}
}
int main(){
	int M;int n,m;
	cin>>M;
	if(M>0&&M<10){
		cout<<endl;
		for(int i=0;i<M;i++){
			cin>>m;;cin>>n;
			if(n>0&&n<=100&&m>0&&m<pow(10,6))
				contrasenha(n,m);
	}
	}
	

}
