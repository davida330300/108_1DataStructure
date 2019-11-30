/**
 *  A class that stores a variable of type int.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
using namespace std;

class Integer {
private:
  int i;

public:

  /**
   *  Construct a new Integer with the given variable.
   *  @param i the int variable by which the Integer stores.
   */
  Integer(const int& i) {
    this->i = i;
  }

  /**
   *  Construct a new Integer with i = 0;
   */
  Integer() {i = 0;}

  /**
   *  Get the value of the int variable.
   *  @return the stored value.
   */
  int getvalue() const {
    return i;
  }

  friend ostream& operator<<(ostream& os, const Integer in)
  {
      os << in.i;
      return os;
  }
};

#endif
