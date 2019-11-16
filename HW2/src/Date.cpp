/**
 * @file Date.cpp
 * @author Shau-Shiun,Chu (b06501018@ntu.edu.tw)
 * @brief 
 * @version 0.1
 * @date 2019-09-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Date.h"
#include "string"
#include "vector"

Date::Date(int month, int day, int year)
{
    if (isValidDate(month, day, year))
    {
        dmonth = month;
        ddate = day;
        dyear = year;
    }
    else
    {
        cout << "error input of date" << endl;
        exit(0);
    }
}

Date::Date(const string &s)
{

    int month_Int, date_Int, year_Int;

    string split = "/";
    auto pos_start = 0;
    auto pos_end = 0;
    vector<string> dateList;
    while (((pos_end = s.find(split, pos_start)) != string::npos))
    {
        dateList.push_back(s.substr(pos_start, pos_end));
        pos_start = pos_end + 1;
    }
    dateList.push_back(s.substr(pos_start, s.length() - 1));

    if (dateList[0].empty() || dateList[1].empty() || dateList[2].empty())
    {
        cout << "empty date" << endl;
        exit(0);
    }

    vector<int> dateInt;
    for (string i : dateList)
    {
        dateInt.push_back(stoi(i));
    }
    month_Int = dateInt[0];
    date_Int = dateInt[1];
    year_Int = dateInt[2];

    if (!isValidDate(month_Int, date_Int, year_Int))
    {
        cout << "InvalidDate" << endl;
        exit(0);
    }

    dmonth = dateInt[0];
    ddate = dateInt[1];
    dyear = dateInt[2];
}

/**
 * @brief 
 *      
 *      finish 10/4/19
 *      test 10/4/19
 * 
 * @param year 
 * @return true 
 * @return false 
 */
bool Date::isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief 
 * 
 *      finish 10/4/19
 *      test   10/4/19
 * 
 * @param month 
 * @param year 
 * @return int 
 */
int Date::daysInMonth(int month, int year) //completed
{

    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if (month <= 7)
    {
        if (month % 2 == 0)
        {
            return 30;
        }
        else
        {
            return 31;
        }
    }
    else
    {
        if (month % 2 == 0)
        {
            return 31;
        }
        else
        {
            return 30;
        }
    }
}

/**
 * @brief 
 * 
 *      finish 10/4/19
 *      test   10/4/19
 * 
 * @param month 
 * @param day 
 * @param year 
 * @return true 
 * @return false 
 */
bool Date::isValidDate(int month, int day, int year) // completed
{
    if (year < 1 || month < 1 || month > 12 || day < 1 || daysInMonth(month, year) < day)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * @brief 
 * 
 *      finish 9/30/19
 *      test   9/30/19
 * 
 * @return string 
 */
string Date::toString() //completed
{
    return to_string(dmonth) + "/" + to_string(ddate) + "/" + to_string(dyear);
}

/**
 * @brief 
 * 
 *      finish 10/4/19
 *      test   10/4/19
 * 
 * @param d 
 * @return true 
 * @return false 
 */
bool Date::isBefore(const Date &d) //completed
{
    if (dyear > d.dyear)
    {
        return false;
    }
    else if (dyear == d.dyear)
    {
        if (dmonth > d.dmonth)
        {
            return false;
        }
        else if (dmonth == d.dmonth)
        {
            if (ddate >= d.ddate)
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 
 * 
 *      finish 10/4/19
 *      test   10/4/19
 * 
 * @param d 
 * @return true 
 * @return false 
 */
bool Date::isAfter(const Date &d) // completed
{
    if (!isBefore(d) && !isEqual(d))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 
 * 
 *      finish 9/30/19
 *      test   9/30/19
 *  
 * @param d 
 * @return true 
 * @return false 
 */
bool Date::isEqual(const Date &d) // completed
{
    if (ddate == d.ddate && dmonth == d.dmonth && dyear == d.dyear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 
 * 
 * @return int 
 */
int Date::dayInYear()
{
    int days = 0;
    for (int i = 1; i < dmonth; i++)
    {
        days += daysInMonth(i, dyear);
    }
    days += ddate;
    return days;
}

int Date::difference(const Date &d) // cannot use const
{
    int ans = 0;
    Date dc = d;
    if (isEqual(dc))
    {
        ans = 0;
    }
    else if (isBefore(dc))
    {
        //check year
        if (dyear < dc.dyear)
        {
            for (int i = dyear; i < dc.dyear; i += 1)
            {
                if (isLeapYear(i))
                {
                    ans += 366;
                }
                else
                {
                    ans += 365;
                }
            }
        }
        ans -= dayInYear();
        ans += dc.dayInYear();
        ans = 0 - ans;
    }
    else
    {
        if (dyear > dc.dyear)
        {
            for (int i = dc.dyear; i < dyear; i += 1)
            {
                if (isLeapYear(i))
                {
                    ans += 366;
                }
                else
                {
                    ans += 365;
                }
            }
        }
        ans -= dc.dayInYear();
        ans += dayInYear();
    }
    return ans;
}
