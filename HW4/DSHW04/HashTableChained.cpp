/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

/**
  Briefly explain the function of this class.

  @author 			shau shiun chu
  @ID 				B06501018
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  HashTableChained.cpp
  version 1.0
*/

#include "HashTableChained.h"
#include <iostream>
#include <typeinfo>
using namespace std;

//check if the input number is a prime
template<typename K, typename V>
bool HashTableChained<K, V>::is_Prime(int n)
{
    bool prime = true;
    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int customizeSize)
{
    // Your solution here.
    int modifySize = customizeSize;
    while(!is_Prime(modifySize))
    {
        modifySize += 1;
    }
    tablesize = modifySize;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained()
{
    // Your solution here.
    tablesize = 101;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code)
{
    // Replace the following line with your solution.
    int val = 0;
    val = int(abs((code * 37 + 101) % tablesize));
    return val;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size()
{
    // Replace the following line with your solution.
    return entrysize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty()
{
    // Replace the following line with your solution.
    if(entrysize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value)
{
    // Replace the following line with your solution.
    K insertKey = key;
    Entry<K,V> insertEntry(key,value);
    table[compFunction(insertKey->hashCode())].insertFront(insertEntry);

    entrysize ++;
    return;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key)   //?
{
    K findKey = key;

    DList<Entry<K,V>> *bucket = &table[compFunction(findKey->hashCode())];


    //"current" points to the first entry of the bucket.
    DListNode<Entry<K,V>> *current = bucket->front();

    if (typeid(findKey) != typeid(bucket->getItem(current).getkey())){
        return false;
    }

    for(int i = 0; i < bucket->length(); i++){
		//bool Double::equals(const Double& db)
        if(bucket->getItem(current).getkey()->equals(*findKey)){
            return true;
        }
        else{
            current = bucket->next(current);
        }
    }
    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key)   //?
{
    K removeKey = key;
    DList<Entry<K,V>> *bucket = &table[compFunction(removeKey->hashCode())];

    DListNode<Entry<K,V>> *current = bucket->front();

    if (typeid(removeKey) != typeid(bucket->getItem(current).getkey())){
        return;
    }

    for(int i = 0; i < bucket->length(); i++)
    {
        if(bucket->getItem(current).getkey()->equals(*removeKey)){
            bucket->remove(current);
            entrysize--;
            return;
        }
        else{
            current = bucket->next(current);
        }
    }
    return;
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty(){
    // Your solution here.
    delete [] table;
    table = new DList<Entry<K,V>>[tablesize];
    entrysize = 0;
}


// print all entries from the dictionary.

template<typename K, typename V>
void HashTableChained<K, V>::print()
{
    for(int i = 0; i < tablesize; i++){
        DList<Entry<K,V>> *bucket = &table[i];
        cout << "hashtable[" << i << "] : ";
		if (bucket->length() == 0){
			cout << "empty = = " << endl;
			continue;
		}
		DListNode<Entry<K,V>> *current = bucket->front();
		for (int j = 0; j < bucket->length(); j++){
			cout << "(" << bucket->getItem(current).getkey()->getvalue() << "," << bucket->getItem(current).getvalue()->getvalue() << ") ";
			current = bucket->next(current);
		}
		cout << endl;
    }
}


//  count collisions...

template<typename K, typename V>
int HashTableChained<K, V>::collision_count(){
    int counter = 0;
    for (int i = 0; i < tablesize; i++){
        if (table[i].isEmpty())
            continue;
        else
            counter += table[i].length()-1;
    }
    return counter;
}
