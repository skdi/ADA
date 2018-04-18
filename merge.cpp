#include <iostream>
#define sizee 4
using namespace std;

void CopyArray(int *A,int *B){
	for(int i=0;i<sizee;i++){
		B[i]=A[i];
	}
}
void TopDownSplitMerge(int *B,int inicio,int fin,int *A);
void TopdownMerge(int *A,int inicio,int mid,int fin,int *B);

void TopDownMergeSort(int *A,int *B,int n){
	CopyArray(A,B);//copia de A en B
	TopDownSplitMerge(B,0,n,A);//ordenar datos de B hacia A
}
void TopDownSplitMerge(int *B,int inicio,int fin,int *A){
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

void TopdownMerge(int *A,int inicio,int mid,int fin,int *B){
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


void imprimir(int *A){
	for(int i=0;i<sizee;i++)
		cout<<A[i]<<endl;
}
void BottomUpMerge(int *A,int left,int right,int fin,int *B);
void BottomUpMergeSort(int *A,int *B,int n){
	for(int w=1;w<n;w=2*w){
		for(int i=0;i<n;i=i+2*w){
			BottomUpMerge(A,i,min(i+w,n),min(i+2*w,n),B);
		}
		CopyArray(B,A);
	}
}
void BottomUpMerge(int *A,int left,int right,int fin,int *B){
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


int main(){
	int *A=new int[sizee];
	int *B=new int[sizee];

	int a;
	cout<<"ingresa algo pe"<<endl;
	for(int i=0;i<sizee;i++){
		cin>>a;
		A[i]=a;
		cout<<":::"<<endl;
	}
	
	//TopDownMergeSort(A,B,sizee);
	BottomUpMergeSort(A,B,sizee);
	imprimir(A);



	return 0;
}
