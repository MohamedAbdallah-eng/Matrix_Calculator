#include <iostream>
#include <string>
#include <vector>


void input_array(double arr[][100],int row, int col);
void output_array(double arr[][100],int row, int col);
void add_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2);
void sub_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2);
void mult_arr(double arr1[][100], int row1, int col1, double arr2[][100], int row2, int col2);
double arr_deter(double arr[][100], int arr_size);
void divide_array(double arr1[][100],int row, int col ,double arr2[][100],int arr_size,double deter);
