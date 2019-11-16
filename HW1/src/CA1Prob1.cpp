/**
 * @file CA1Prob1.cpp
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @ID b06501018
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 * @date 2019-09-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "algorithm"
#include "array"
#include "iostream"
using namespace std;

/**
 * @brief : input two array, "a" & "b", return the inner product of a & b
 *          a & b should have same lenght, if not, we should choose the shorter as the common length¡@dot operation
 * @param a : an array
 * @param b : an array
 * @param n : the smaller length between a & b, also the length of the dot operation
 * @return int : inner product should be int
 */
int dotProduct(int a[], int b[], int n)
{
    int i = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}

int main()
{
    cout << "haha" << endl;
    int a[] = {-1, 0, 2, 15, 7, 6, -4, 8, 21, -10};
    int b[] = {5, 9, -18, 16, 0, 1, -4, 18, -2, 12};
    int n_of_a = sizeof(a) / sizeof(int);
    int n_of_b = sizeof(b) / sizeof(int);
    int n = min(n_of_a, n_of_b);
    cout << dotProduct(a, b, n);
    system("pause");
    return 0;
}
