/**
 * @file CA1Prob4.cpp
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
#include "string"
using namespace std;
/**
 * @brief 
 * 
 */
class flower
{
private:
    string name;
    int petal;
    double price;

public:
    flower(string n, int pt, double pr);
    void setName(string n);
    void setPetal(int pt);
    void setPrice(double pr);
    string getName();
    int getPetal();
    double getPrice();
};
/**
 * @brief Construct a new flower::flower object
 * 
 * @param n :¡@string, the name of the flower
 * @param pt : integer, the number of the flower's petal
 * @param pr : integer, the number of the flower's price
 */
flower::flower(string n, int pt, double pr)
{
    setName(n);
    setPetal(pt);
    setPrice(pr);
}
/**
 * @brief : use setter to modify private member
 * 
 * @param n 
 */
void flower::setName(string n)
{
    name = n;
} /**
 * @brief : use setter to modify private member
 * 
 * @param pt 
 */
void flower::setPetal(int pt)
{
    petal = pt;
} /**
 * @brief : use setter to modify private member
 * 
 * @param pr 
 */
void flower::setPrice(double pr)
{
    price = pr;
}
/**
 * @brief : use getter to access private member
 * 
 * @return string 
 */
string flower::getName()
{
    return name;
}
/**
 * @brief : use getter to access private member
 * 
 * @return int 
 */
int flower::getPetal()
{
    return petal;
} /**
 * @brief : use getter to access private member
 * 
 * @return double 
 */
double flower::getPrice()
{
    return price;
}

int main()
{

    flower Flower("Kasumigaoka Utaha", 3, 25);
    cout << Flower.getName() << endl;
    cout << Flower.getPetal() << endl;
    cout << Flower.getPrice() << endl;

    Flower.setName("Sawamura Spencer Eriri");
    Flower.setPetal(16);
    Flower.setPrice(22);
    Flower.setPrice(999);
    cout << Flower.getName() << endl;
    cout << Flower.getPetal() << endl;
    cout << Flower.getPrice() << endl;

    system("pause");
    return 0;
}