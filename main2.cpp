#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

const int k=3;
void sum (int mas[k][k]);
void minimum(int matrix[k][k]);


int main()

{
     setlocale( LC_ALL,"Russian" );
        int arr[k][k];
        int i, j;

        for ( i = 0; i < k; i++ ){
                for ( j = 0; j < k; j++ ){
                        printf("arr[%d][%d] = ", i+1, j+1);
                        scanf("%d", &arr[i][j]);
                }
        }

        printf("\n-----------------------\n");
        for ( i = 0; i < k; i++ )
        for ( j = 0; j < k; j++ )
        printf( ( j < (k-1) ) ? "%d\t" : "%d\n", arr[i][j]);

        printf("\n ����� ��������� � ��� ��������, ������� �� �������� ������������� ���������:");
        sum(arr);
        printf("\n \n ������� ����� ���� ��������� ����������, ������������ �������� ��������� �������: ");
        minimum(arr);
        fflush(stdin);
        char c=getchar();
        return 0;
}

void sum(int mas[k][k])
{
        int i,j,a,sum,n;
        for (i=0;i<k;i++)
        {
                a=0;
                for (j=0;j<k;j++)
                if (mas[i][j]<0) a++;
                if (a==0)
                {
                        sum=0;
                        for (n=0;n<k;n++)
                        sum+=mas[n][i];
                        printf("\n ������� %d: %d",(i+1),sum);
                }
        }
}
/*
int sumDiagonal (int matrix[k][k], int currentDiagonal)
{
        int sum = 0;
        for(int i = 0, j = currentDiagonal; i < k; ++i)
        {
                sum += abs(matrix[j][i]);
                --j;
                if(j < 0)
                        j = k - 1;
        }
        return sum;
}
*/

int sumDiagonal (int matrix[k][k], int currentDiagonal)
{
        int sum = 0;

        for (int i=0;i<k;i++)
                for (int j=0;j<k;j++)
			if(i+j == currentDiagonal)
				sum += abs(matrix[i][j]);
        return sum;
}


void minimum(int matrix[k][k])
    /*��� ������� ��������� ����� �������� ����� ��� ������� ��������� ���������� ������������ ��������.
    ���� ������� �������� ����� �������� � ��������� � ���������� sumDiagonal, ��� �������� � �������� ����������
    ���� ������� � ����� ��������� ����� ������� ��� ����������.*/
{
        int min = sumDiagonal(matrix, 1);//
        for(int i = 2, cnt; i < k; ++i)
        {
                cnt = sumDiagonal(matrix, i);
                if(cnt < min)
                        min = cnt;
        }
        printf("%d\n",min);
}
