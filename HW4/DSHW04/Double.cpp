/**
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 **/
 /**
   Briefly explain the function of this class.

   @author 			shau shiun chu
   @ID 				B06501018
   @Department 		Engineering Science and Ocean Engineering
   @Affiliation 	    National Taiwan University

   version 1.0
 */

#include "Double.h"
#include <math.h>
#include <typeinfo>


 /**
  *  Construct a new Double with the given variable.
  *  @param d the double variable by which the Double stores.
  */
Double::Double(const double& d) {
	this->d = d;
}

/**
 *  Construct a new Double with the given variable.
 *  @param d is the Double variable.
 */
Double::Double(const Double& d) {
	this->d = d.getvalue();
}

/**
 *  Get the value of the double variable.
 *  @return the stored value.
 */
double Double::getvalue() const {
	return d;
}

/**
 *  Returns true if "this" Double and "db" have identical values.
 *  @param db is the second Double.
 *  @return true if the double values are equal, false otherwise.
 */
bool Double::equals(const Double& db) { // need to be check again
	// Replace the following line with your solution.  Be sure to return false
	//   (rather than throwing a ClassCastException) if "db" is not
	//   a Double.
	if (typeid(db) != typeid(Double)){
		return false;
	}
	else{
		if (abs(this->getvalue() - db.getvalue()) < 0.000000001 )
			return true;
		else
			return false;
	}
}

/**
 *  Returns a hash code for this Double.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int Double::hashCode() {
	// Replace the following line with your solution.

	union {
		double d;
		long long int i;
	}u;

	u.d = d;
	u.i >> 3;
	u.i << 3;
	return int(u.i ^ (u.i >> 23));
}


ostream& operator<<(ostream &os, const Double &db)
{
	os << db.d;
	return os;
}
