#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;

void input_array(double arr[][100],int row, int col){
    for (int i =0; i < row;i++){
        for (int j =0; j < col; j++){
            cout << "Please enter the " << i << "," << j << " value of the matrix: ";
            cin >> arr[i][j];
        }
    }
}
void output_array(double arr[][100],int row, int col){
    for (int i =0; i < row; i++){
        for (int j=0; j<col; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void add_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2){
    cout << "matrix1 + matrix2 = \n";
    for (int i =0; i < row1; i++){
        for (int j = 0; j < col1; j++)
            cout << arr1[i][j] + arr2[i][j] << " ";
        cout << endl;
    }
}
void sub_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2){
    cout << "matrix1 - matrix2 = \n";
    for (int i =0; i < row1; i++){
        for (int j = 0; j < col1; j++)
            cout << arr1[i][j] - arr2[i][j] << " ";
        cout << endl;
    }
}
void mult_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2){
    double arr3[100][100];
    for (int i = 0; i<row1;i++){
        for (int j = 0; j<col2;j++){
            arr3[i][j]=0;
            for (int k = 0; k < row2;k++){
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    output_array(arr3,row1,col2);
}
double arr_deter(double arr[][100], int arr_size){
    double deter = 0, element;
    int sub_i = 0,sub_j =0;
    double arr_temp[100][100];
    if (arr_size == 1)
        deter = arr[0][0];
    else if (arr_size == 2)
        deter = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    else{
        for (int i = 0; i < arr_size; i++){
                element = arr[0][i];
                for (int j =1; j < arr_size; j++){
                    for (int k = 0; k < arr_size; k++){
                        if (k == i)
                            continue;
                        arr_temp[sub_i][sub_j] = arr[j][k];
                        sub_j++;
                    }
                    sub_i++;
                    sub_j=0;
                }
                if (i%2==0)
                    deter += arr_deter(arr_temp,arr_size-1)*element;
                else
                    deter -= arr_deter(arr_temp,arr_size-1)*element;
                sub_i=0;
        }
    }
    return deter;
}

void divide_array(double arr1[][100],int row, int col ,double arr2[][100],int arr_size,double deter){
    double cofactor[100][100], arr_temp[100][100];  // First part, to calculate the cofactor of the matrix
    int sub_i = 0, sub_j =0;
    for (int i = 0; i < arr_size;i++){
        for (int j =0; j < arr_size;j++){
            for (int k =0; k < arr_size;k++){
                if (k == i) continue;
                for (int m = 0; m < arr_size;m++){
                    if (m == j) continue;
                    arr_temp[sub_i][sub_j] = arr2[k][m];
                    sub_j++;
                }
                sub_i++;
                sub_j = 0;
            }
            if ((i+j)%2==0)
            cofactor[i][j] = arr_deter(arr_temp,arr_size-1);
            else
            cofactor[i][j] = arr_deter(arr_temp,arr_size-1) * -1;
            sub_i = 0;
        }
    }
    double transpose[100][100];         // second part to calculate the transpose of the matrix
    for (int i =0; i<arr_size;i++){
        for (int j =0;j<arr_size;j++){
            transpose[i][j]=cofactor[j][i];
        }
    }
    for (int i =0; i <arr_size;i++){         // third part to calculate the inverse of the matrix
        for (int j =0; j<arr_size;j++){
            transpose[i][j]= transpose[i][j]/deter;
        }
    }
    mult_arr(arr1, row, col, transpose, arr_size, arr_size); //multiplying the first matrix with the inverse of the second matrix
}

