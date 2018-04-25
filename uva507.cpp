#include <vector>
#include <iostream>
#include <math.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>
using namespace std;
//UVA 507
int* suma_max(int *A,int n){
	int e=0,d=-1;
	int suma=0;
	int i=1,f=0;
	int sumamax=0;
	while(f<n){
		f++;
		suma=suma+A[f];
		if(suma<0){
			suma=0;
			i=f+1;
		}else if(suma>sumamax){
			sumamax=suma;
			e=i;
			d=f;
		}
	}
	int *aux=new int[3];
	aux[0]=e;
	aux[1]=d;
	aux[2]=sumamax;
	return aux;
	delete aux;
}
int* suma_max3(int *A,int n){
	int e=0,d=-1;
	int suma=0;
	int sumamax=0;
	for(int i=1;i<=n;i++){
		for(int f=i;f<=n;f++){
			suma=0;
			for(int k=i;k<f;k++)
				suma=suma+A[k];
			if(suma>sumamax){
				sumamax=suma;
				e=i;
				d=f;
			}
		}

	}
	int *aux=new int[3];
	aux[0]=e;
	aux[1]=d;
	aux[2]=sumamax;
	return aux;
	delete aux;
}
int* suma_max2(int *A,int n){
	int e=0,d=-1;
	int suma=0;
	int sumamax=0;
	for(int i=1;i<=n;i++){//recorrido principal del array
			suma=0;
			for(int f=i;f<=n;f++){
				suma=suma+A[f];
			if(suma>sumamax){
				sumamax=suma;
				e=i;
				d=f;
			}
		}

	}
	int *aux=new int[3];
	aux[0]=e;
	aux[1]=d;
	aux[2]=sumamax;
	if(sumamax<=0)
		cout<<"Ruta no tiene paradas atractivas."<<endl;
	else return aux;
	delete aux;
}



int main(){
	cout<<"numero de problemas: ";
	int m;
	cin>>m;

	int n;

	int *A=new int[n];
	int *B=new int[3];
	int a;
	for(int j=1;j<=m;j++){
		cout<<"numero de paradas: ";
		cin>>n;
		for(int i=1;i<n;i++){
			cout<<i<<": ";
			cin>>a;
			A[i]=a;
			cout<<endl;
		}
		B=suma_max2(A,n);
		cout<<"e: "<<B[0]<<" d: "<<B[1]<<" sumamax: "<<B[2]<<endl;
	}

	return 0;


}
