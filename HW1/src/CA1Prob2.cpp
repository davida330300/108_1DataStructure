/**
 * @file CA1Prob2.cpp
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @ID b06501018
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 * @date 2019-09-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "iostream"
using namespace std;
int *showPrime(int);
int a[2];

/*
int main()
{
    int x;

    cin >> x;
    showPrime(x);
    cout << a[0] << "  " << a[1];
    system("pause");
    return 0;
}
*/

/**
 * @brief : show if the recent number is prime number
 * 
 * @param n : recent number
 * @return true : is prime
 * @return false : not prime
 */
bool isPrime(int n)
{
    bool flag = true;
    for (int i = 2; i * i <= n; i += 1)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
/**
 * @brief : if x is prime, a[0] = x, a[1] = 0
 *          if x is not prime, a[0] is the nearest and smaller prime number of x
 *                             a[2] is the nearesr and bigger prime number of x
 * 
 * @param x : the targert x
 * @return int* : an array "a"(global), len(a) = 2
 */
int *showPrime(int x)
{

    if (isPrime(x))
    {
        a[0] = x;

        a[1] = 0;
    }
    else
    {
        int i = x;
        while (!isPrime(i))
        {
            i -= 1;
        }
        a[0] = i;
        i = x;
        while (!isPrime(i))
        {
            i += 1;
        }
        a[1] = i;
    }
    return a;
}
