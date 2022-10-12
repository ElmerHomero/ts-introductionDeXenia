#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*********************************************************************************

void CapturaMatriz(float A[10][20], int ren, int col);
void ImprimeMatriz(float A[10][20], int ren, int col);
void GaussJordan(float A[10][20], int ren, int col);

//*********************************************************************************

int main()
{
	int n, ren, col;
	float A[10][20], aux, p;
	printf("\n\tNo. de ecuaciones: ");
	scanf("%d",&n);
	CapturaMatriz(A, n, n+1);
	ImprimeMatriz(A, n, n+1);
	GaussJordan(A, n, n+1);
	ImprimeMatriz(A, n, n+1);
	printf("\n\tSolucion del problema: \n");
	for(ren=0;ren<n;ren++)
	{
		printf("\n x%d = %1.4f ",ren+1, A[ren][n]);
	}
	system("pause");
	return 0;
}

//*********************************************************************************

//*****Funcion que captura una matriz

//*********************************************************************************
void CapturaMatriz(float A[10][20], int ren, int col)
{
	int i, j;
	for(i=0;i<ren;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\n\tA[%d][%d]: ",i+1,j+1);
			scanf("%f",&A[i][j]);
		}
	}
}

//*********************************************************************************

//*****Funcion que imprime una matriz

//*********************************************************************************
void ImprimeMatriz(float A[10][20], int ren, int col)
{
	int i, j;
	system("cls");
	printf("\n\tMatriz: \n");
	for(i=0;i<ren;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j==col-1)
			{
				printf("| %.2f  ",A[i][j]);
			}
			else
			{
				printf("%.2f  ",A[i][j]);
			}
			
		}
		printf("\n");
	}
	system("pause");
}

//*********************************************************************************

//*****Funcion que realiza el metodo de Gauss Jordan a una matriz

//*********************************************************************************
void GaussJordan(float A[10][20], int ren, int col)
{
	float P, aux;
	int i, j, k;
	for(i=0;i<ren;i++)
	{
		P=A[i][i];
		for(j=0;j<col;j++)
		{
			A[i][j]=A[i][j]/P;
		}
		for(j=0;j<ren;j++)
		{
			if(A[j][i]!=1 && A[j][i]!=0)
			{
				aux=A[j][i];
				for(k=i;k<col;k++)
				{
					A[j][k]=A[j][k]-(aux*A[i][k]);
				}
			}
		}
	}
}
