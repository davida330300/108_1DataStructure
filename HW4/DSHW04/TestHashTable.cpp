/**
  Briefly explain the function of this class.

  @author 			shau shiun chu
  @ID 				B06501018
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  version 1.0
*/

#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.h"
#include "CheckerBoard.h"
#include "HashTableChained.cpp"
#include "Double.h"
#include "String.h"

template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards);

CheckerBoard* randomBoard();

int main() {
    /*

    // To test your hash function, add a method to your HashTableChained class
    // that counts the number of collisions--or better yet, also prints
    // a histograph of the number of entries in each bucket.  Call this method
    // from here.
    */


    HashTableChained<Double*, Integer*>* hash1 = new HashTableChained<Double*, Integer*>(100);


	//Test insert() and print()
	for (int i = 0; i < 100; i++) {
		Integer *value = new Integer(i);
		Double *key = new Double(i+4.17925);
		hash1->insert(key,value);
	}


	cout << "----Print the hashtable---"<< endl;
	hash1->print();
	
	cout << "\nThe following are hash1 test" << endl;
	cout << "\nSIZE TEST: The follow should print 100" << endl;
	cout << "Ans : There are " << hash1->size() << " entries in the table\n" << endl; //Test size()

	cout << "\nThe following are collision test, the smaller, the better" << endl;
	printf("Ans : collision counter : %d\n\n", hash1->collision_count());

	cout << "The following are remove test" << endl;
	cout << "The 7.17925 should be found" << endl;
	Double *f = new Double(7.17925); //Test find()
	if (hash1->find(f))
		cout << "Ans : The entry whose key is " << f->getvalue() << " can be found." << endl;
	else
		cout << "Ans : The entry whose key is " << f->getvalue() << " can't be found." << endl;

	cout << "\nRemove 7.17925" << endl;
	cout << "The 7.17925 should not be found" << endl;
	hash1->remove(f); //Test remove()
	if (hash1->find(f))
		cout << "Ans : The entry whose key is " << f->getvalue() << " still exists." << endl;
	else
		cout << "Ans : The entry whose key is " << f->getvalue() << " has been removed." << endl;

	delete f;

	cout << "\n The following should show not empty" << endl;
	if (hash1->isEmpty()) //Test isEmpty()
		cout << "Ans : Table is empty." << endl;
	else
		cout << "Ans : Table is not empty." << endl;
    cout << endl << endl;

	cout << "the below should show empty" << endl;
	hash1->makeEmpty(); //Test makeEmpty()
	hash1->print();
	if (hash1->isEmpty())
		cout << "Ans : Table is empty." << endl;
	else
		cout << "Ans : Table is not empty." << endl;

	delete hash1;


    HashTableChained<Double*, Integer*>* hash2 = new HashTableChained<Double*, Integer*>(100);
    for(int i = 0; i < 100; ++ i){
        Double* nd = new Double(3.14159 * static_cast<double>(i) + 2.914);
        Integer* ni = new Integer(i);
        hash2->insert(nd, ni);
    }
    hash2->print();
    printf("collision counter : %d\n", hash2->collision_count());
    hash2->makeEmpty();

	HashTableChained<String*, Integer*>* hash3 = new HashTableChained<String*, Integer*>(17);

	String* s1 = new String("Kyrie");
	Integer* i1 = new Integer(1);	
	hash3->insert(s1, i1);

	String* s2 = new String("Aisaka Taiga");
	Integer* i2 = new Integer(2);
	hash3->insert(s2, i2);

	String* s3 = new String("Kushieda Minori");
	Integer* i3 = new Integer(3);
	hash3->insert(s3, i3);

	String* s4 = new String("Kawashima Ami");
	Integer* i4 = new Integer(4);
	hash3->insert(s4, i4);

	String* s5 = new String("Misaka Mikoto");
	Integer* i5 = new Integer(5);
	hash3->insert(s5, i5);

	String* s6 = new String("Saten Ruiko");
	Integer* i6 = new Integer(6);
	hash3->insert(s6, i6);

	String* s7 = new String("Shirai Kuroko");
	Integer* i7 = new Integer(7);
	hash3->insert(s7, i7);

	String* s8 = new String("Uiharu Kazari");
	Integer* i8 = new Integer(8);
	hash3->insert(s8, i8);

	String* s9 = new String("Omae Kumiko");
	Integer* i9 = new Integer(9);
	hash3->insert(s9, i9);

	String* s10 = new String("Koaka Reina");
	Integer* i10 = new Integer(10);
	hash3->insert(s10, i10);

	String* s11 = new String("Nakagawa Natsuki");
	Integer* i11 = new Integer(11);
	hash3->insert(s11, i11);

	String* s12 = new String("Yoshikawa Yuko");
	Integer* i12 = new Integer(12);
	hash3->insert(s12, i12);

	String* s13 = new String("Kasaki Nozomi");
	Integer* i13 = new Integer(13);
	hash3->insert(s13, i13);

	String* s14 = new String("Yoroizuka Mizore");
	Integer* i14 = new Integer(14);
	hash3->insert(s14, i14);

	String* s15 = new String("Tanaka Asuka");
	Integer* i15 = new Integer(15);
	hash3->insert(s15, i15);

	hash3->print();
	printf("collision counter : %d\n", hash3->collision_count());

	String *f1 = new String("Misaka Mikoto");
	if (hash3->find(f1))
		cout << "Ans : The entry whose key is " << f1->getvalue() << " can be found." << endl;
	else
		cout << "Ans : The entry whose key is " << f1->getvalue() << " can't be found." << endl;
	delete f1;

	cout << hash3->size() << endl;
	cout << "\nThe following is remove operation" << endl;
	String *f2 = new String("Kushieda Minori");
	hash3->remove(f2);
	if (hash3->find(f2))
		cout << "Ans : The entry whose key is " << f2->getvalue() << " can be found." << endl;
	else
		cout << "Ans : The entry whose key is " << f2->getvalue() << " can't be found." << endl;
	delete f2;

	cout<< hash3->size()<<endl;

	hash3->makeEmpty();



    HashTableChained<CheckerBoard*, Integer*>* hash4 = new HashTableChained<CheckerBoard*, Integer*>(100);
    initTable(hash4, 100);

    cout << "There are " << hash4->size() << " entries in the table" << endl; //Test size()
    printf("collision counter : %d\n", hash4->collision_count());



	system("pause");
    return 0;
}


/**
 *  Generates a random 8 x 8 CheckerBoard.
 **/
CheckerBoard* randomBoard() {
    CheckerBoard* board = new CheckerBoard;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board->setElementAt(x, y, rand());
        }
    }
    return board;
}


/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(randomBoard(), new Integer(i));
    }
}
