#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define n 3
int A[n][n] = { { -2, -4, 3 }, { -5, 6, -1 },{-4,5,5} };

int resultado[n+1][n+1];

int main()
{
    //inicializamos la primera fila y columa con 0
    for(int i=0;i<=n;i++)
        resultado[0][i] = 0;

    for(int i=0;i<=n;i++)
        resultado[i][0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            resultado[i][j] = A[i-1][j-1] + max(resultado[i][j-1], resultado[i-1][j]);
        }
    }

    cout << resultado[n][n];
    return 0;
}
