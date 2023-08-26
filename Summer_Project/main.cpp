#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;

int main()
{
int first = 1;
string enter;
string option;
string matrix_deter;
int row1,col1,row2,col2;
double arr1[100][100], arr2[100][100];
while(1){
        if (first == 1 || enter == "yes"){
        cout << "Please enter the dimensions of the first matrix (row,col): ";
        cin >> row1 >> col1;
        if (cin.fail()) {cout << "Error: invalid input"; break;}
        cout << "Please enter the dimensions of the second matrix (row,col): ";
        cin >> row2 >> col2;
        if (cin.fail()) {cout << "Error: invalid input"; break;}
        cout << "For the first matrix: \n";
        input_array(arr1,row1,col1);
        if (cin.fail()) {cout << "Error: invalid input"; break;}
        cout << "\nFor the second matrix: \n";
        input_array(arr2,row2,col2);
        if (cin.fail()) {cout << "Error: invalid input"; break;}
        first = 0;
    }
    cout << "\nPlease enter the option you need (add,sub,mult,div,det,exit): ";
    cin >> option;
    if (option == "add"){
        if (row1 == row2 && col1 == col2)
            add_arr(arr1,row1,col1,arr2,row2,col2);
        else cout << "\nError: Can't add different size matrices\n";
    }
    else if (option == "sub"){
        if (row1 == row2 && col1 == col2)
            sub_arr(arr1,row1,col1,arr2,row2,col2);
        else cout << "\nError: Can't subtract different size matrices\n";
    }
    else if (option == "mult"){
        if (col1 == row2)
            mult_arr(arr1,row1,col1,arr2,row2,col2);
        else cout << "\nError: Can't multiply matrices if the columns of the first doesn't equal the rows of the second\n";
    }
    else if (option == "div"){
        if (row2 == col2){
            if (col1 == row2){
                double deter = arr_deter(arr2,row2);
                if (deter == 0)
                    cout << "\nError: can't divide matrices if the second matrix has determinant = 0\n";
                else
                    divide_array(arr1,row1,col1,arr2,row2,deter);
            }
            else cout << "\nError: Can't divide matrices if the columns of the first doesn't equal the rows of the second\n";
        }
        else cout << "\nError: Can't divide matrices if the second matrix isn't a square matrix\n";
    }
    else if (option == "det"){
        cout << "choose which matrix to get the determinant for (matrix1,matrix2): ";
        cin >> matrix_deter;
        if (matrix_deter == "matrix1"){
            if (row1 == col1)
                cout << "The determinant of matrix1 = " << arr_deter(arr1, row1) << endl;
            else
                cout << "\nError: Can't get the determinant of non-squared matrix\n";
        }
        else if (matrix_deter == "matrix2"){
            if (row2 == col2)
                cout << "The determinant of matrix2 = " << arr_deter(arr2, row2) << endl;
            else
                cout << "\nError: Can't get the determinant of non-squared matrix\n";
        }
        else cout << "\nError: Invalid Matrix\n";
    }
    else if (option == "exit")
        break;
    else
        cout << "\nError: Invalid Option\n";
    cout << "\nPlease choose either to enter new matrices (type yes) or use the same matrices (type anything else): ";
    cin >> enter;
}
}
