/**
 * @file CA1Prob3.cpp
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
bool isMultiple(long n, long m);

// int main()
// {
//     long  a = 184575863663, b = 8;

//     cout << isMultiple(a, b);

//     system("pause");
//     return 0;
// }

/**
 * @brief :¡@two positive long integers, x and y,
 *           if one is another number's divisor(one is another number's )
 * 
 * @param x : a long integer
 * @param y : a long integer
 * @return true 
 * @return false 
 */
bool isMultiple(long x, long y)
{
    if (x >= y) // find which one is smaller
    {
        int divisor = x / y;  // divisor is an integer
        if (x == divisor * y) // we mutiply the smaller number with divisor, if equal to the bigger, which means divisible
        {
            return true;
        }
    }
    else
    {
        int divisor = y / x;
        if (y == divisor * x)
        {
            return true;
        }
    }
    return false;
}

/*
(Save as ¡§CA1Prob3.cpp¡¨.)    
Write a function that takes two positive long integers, n and m, 
and returns true if and only if n is a multiple of m, that is, n=mi for some integer i. (20%)   

Please design the function using the following specification: 

bool isMultiple (long n, long m); 

*/
