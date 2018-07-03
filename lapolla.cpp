
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define n 4
int A[n][n] = { { -2, -4, 3 ,-6}, { -5, 6, -1 ,-2 },{-4 ,5 ,5 ,5},{6, -1, -6, 3} };

int resultado[n+1][n+1];
void imprimir(int A[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"("<<i<<";"<<j<<"): "<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
void imprimir(int A[n+1][n+1]){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			cout<<"("<<i<<";"<<j<<"): "<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

int trozo_maximo(int A[n][n]){
	    //inicializamos la primera fila y columa con 0
	int a,b,c;
    for(int i=0;i<=n;i++)
        resultado[0][i] = 0;

    for(int i=0;i<=n;i++)
        resultado[i][0] = 0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {	
            resultado[i][j] = A[i-1][j-1] + resultado[i][j-1]+resultado[i-1][j]-resultado[i-1][j-1];//max(resultado[i][j-1], resultado[i-1][j]);
        }
    }
    imprimir(resultado);
    return resultado[n][n];
}
int main()
{
	cout<<"MATRIZ NORMAL"<<endl;
	
    imprimir(A);
    cout<<endl;
        cout <<"EL TROZO MAXIMO ES :"<<trozo_maximo(A)<<endl;
    return 0;
}


/*#include <iostream>
#include <vector>
int n,m;
using namespace std;
typedef vector<vector<int>> matriz;
matriz llenarmatrix(matriz A,int n,int m){
	int s;
	cout<<"llenado de la Matriz"<<endl;
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s;
			temp.push_back(s);			
		}
		A.push_back(temp);
		

	}

}
int suma(matriz A,int i,int j,int n,int m){
	int suma=0;
	int a,b;
	for(a=i;a<n;a++){
		for(b=j;b<m;b++){
			suma+=A[a][b];
		}
	}
	return suma;
}
int maxmatrix(matriz A,int n,int m){
	int i,j,f,g;
	int max;
	i=0;j=0;
	max=A[i][j];
	int temp;
	for(i=0;i<f;i++){
		for(j=0;j<g;j++){
			for(f=n-i;f>0;f--){
				for(g=m-j;g>0;g--){
					temp=suma(A,i,j,f,g);
					cout<<temp<<endl;
					if(max<temp){
						max=temp;
						cout<<max<<endl;
					}
				}
			}
		}
	}
	return max;


}

int main(){
	cout<<"ingresa n y m:"<<endl;
	cin>>n;cin>>m;
	matriz A;
	int max;
	A={{-2,-4,3},{-5,6,-1},{-4,5,5}};
	max=maxmatrix(A,n,m);
	cout<<"trozo maximo es: "<<max<<endl;
	
	return 0;
}*/
