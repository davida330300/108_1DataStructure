/**
 *  A class that stores a string and generates a hash code for it.
 *
 **/
 /**
   Briefly explain the function of this class.

   @author 			shau shiun chu
   @ID 				B06501018
   @Department 		Engineering Science and Ocean Engineering
   @Affiliation 	National Taiwan University

   version 1.0
 */
#include "String.h"
#include <typeinfo>

/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string& str) {
    this->str = str;
}

/**
 *  Construct a new String with the given variable.
 *  @param str is String.
 */
String::String(const String& str) {
    this->str = str.getvalue();
}

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const {
    return str;
}

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String& strg) {
    // Replace the following line with your solution.  Be sure to return false
    //   (rather than throwing a ClassCastException) if "strg" is not
    //   a String.
    if (typeid(strg) != typeid(String))
        return false;
    else if(this->getvalue() == strg.getvalue() )
        return true;
    else
        return false;
}

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() {
    // Replace the following line with your solution.
    int hashVal = 0;
    int stringlength = this->getvalue().size();
    for(int i = 0; i < stringlength; i++){
        hashVal = (31 * hashVal + int(this->getvalue().at(i))) % 1690877;// holme's law 
    }
//  hashVal = 127 * hashVal + int(this->getvalue().at(i));
    return hashVal;
}
