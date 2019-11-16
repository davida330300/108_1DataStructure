/**
 * @file CA1Prob5.cpp
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
class rectangle
{
private:
    double width;
    double length;
    double perimeter;
    double area;

public:
    rectangle(double wd, double lg);
    void setDimension(double wd, double lg);
    void setWidth(double wd);
    void setLength(double lg);
    double getWidth();
    double getLength();
    double getPerimeter();
    double getArea();
    bool isSquare();
};
/**
 * @brief Construct a new rectangle::rectangle object
 * 
 * @param wd : modify width
 * @param lg 
 */
rectangle::rectangle(double wd, double lg)
{
    width = wd;
    length = lg;
}
/**
 * @brief 
 * 
 * @param wd : modify width
 * @param lg : modify length
 */
void rectangle::setDimension(double wd, double lg)
{
    width = wd;
    length = lg;
}
/**
 * @brief : modify width
 * 
 * @param wd : modify width
 */
void rectangle::setWidth(double wd)
{
    width = wd;
}
/**
 * @brief : modify length
 * 
 * @param lg : modify length
 */
void rectangle::setLength(double lg)
{
    length = lg;
}
/**
 * @brief 
 * 
 * @return double 
 */
double rectangle::getWidth()
{
    return width;
}
/**
 * @brief : 
 * 
 * @return double 
 */
double rectangle::getLength()
{
    return length;
}
/**
 * @brief : the perimeter
 * 
 * @return double : the formula is simple
 */
double rectangle::getPerimeter()
{
    return 2 * width + 2 * length;
}
/**
 * @brief 
 * 
 * @return double : the multiply of width and length
 */
double rectangle::getArea()
{
    return width * length;
}
/**
 * @brief : check if width is equal to length
 * 
 * @return true : is equal
 * @return false : not equal
 */
bool rectangle::isSquare()
{
    if (width == length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    rectangle rec(5, 10);
    cout << rec.getArea() << endl;
    cout << rec.getLength() << endl;
    cout << rec.getPerimeter() << endl;
    cout << rec.isSquare() << endl;

    system("pause");
    return 0;
}
