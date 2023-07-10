#include <iostream>
#include <cmath>
using namespace std;

class SET {
    int *set; // Dynamic array to store the elements of the set
    int size; // Current size of the set
    int capacity; // Maximum capacity of the set

public:
    // Constructor to initialize the set with a given capacity
    SET(int cap = 10) {
        capacity = cap;
        size = 0;
        set = new int[capacity];
    }

    // Destructor to free the memory allocated for the set
    ~SET() {
        delete[] set;
    }

    // Method to insert an element into the set
    void insert(int element) {
        if (size == capacity) {
            cout << "Set is full\n";
            return;
        }
        if (!ismember(element)) {
            set[size++] = element;
        }
    }

    // Method to check if an element belongs to the set
    bool ismember(int element) {
        for (int i = 0; i < size; i++) {
            if (set[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Method to find the powerset of the set
    void powerset() {
        int pow_set_size = pow(2, size);
        cout << "{ ";
        for (int counter = 0; counter < pow_set_size; counter++) {
            cout << "{";
            for (int j = 0; j < size; j++) {
                if (counter & (1 << j)) {
                    cout << set[j] << " ";
                }
            }
            cout << "} ";
        }
        cout << "}\n";
    }

    // Method to check if this set is a subset of another set
    bool subset(SET &s) {
        for (int i = 0; i < size; i++) {
            if (!s.ismember(set[i])) {
                return false;
            }
        }
        return true;
    }

    // Method to find the union of this set and another set
    SET set_union(SET &s) {
        SET result(size + s.size);
        for (int i = 0; i < size; i++) {
            result.insert(set[i]);
        }
        for (int i = 0; i < s.size; i++) {
            result.insert(s.set[i]);
        }
        return result;
    }

    // Method to find the intersection of this set and another set
    SET intersection(SET &s) {
      SET result(size);
      for (int i = 0; i < size; i++) {
          if (s.ismember(set[i])) {
              result.insert(set[i]);
          }
      }
      return result;
  }

    // Method to find the complement of this set with respect to a universal set
    SET complement(SET &universal) {
        SET result(universal.size);
        for (int i = 0; i < universal.size; i++) {
            if (!ismember(universal.set[i])) {
                result.insert(universal.set[i]);
            }
        }
        return result;
    }

    // Method to find the difference of this set and another set
    SET difference(SET &s) {
        SET result(size);
        for (int i = 0; i < size; i++) {
            if (!s.ismember(set[i])) {
                result.insert(set[i]);
            }
        }
        return result;
    }

   // Method to find the symmetric difference of this set and another set
   SET symmetric_difference(SET &s) {
     SET temp1 = set_union(s);
     SET temp2 = intersection(s);
     return temp1.difference(temp2);
   }

   // Method to find the Cartesian product of this set and another set
   void cartesian_product(SET &s) {
     cout << "{ ";
     for(int i=0;i<size;i++){
         for(int j=0;j<s.size;j++){
             cout<<"("<<set[i]<<","<<s.set[j]<<") ";
         }
     }
     cout<<"}\n";
   }

   // Method to print the elements of the set
   void print() {
     cout<<"{ ";
     for(int i=0;i<size;i++){
         cout<<set[i]<<" ";
     }
     cout<<"}\n";
   }
};

int main() {

  // Create two sets
  SET A, B;

  // Insert elements into the sets
  A.insert(1);
  A.insert(2);
  A.insert(3);
  A.insert(8);
  A.insert(4);
 

  B.insert(2);
  B.insert(3);
  B.insert(4);

  // Print the sets
  cout<<"Set A: ";
  A.print();

  cout<<"Set B: ";
  B.print();

  // Check if an element belongs to a set
  cout<<"Is 1 a member of Set A? "<<A.ismember(1)<<endl;

  // Find the powerset of a set
  cout<<"Powerset of Set A: ";
  A.powerset();

  // Check if one set is a subset of the other
  cout<<"Is Set B a subset of Set A? "<<A.subset(B)<<endl;

  // Find the union and intersection of two sets
  SET C = A.set_union(B);
  cout<<"Union of Set A and Set B: ";
  C.print();

  // Finds the intersection of two sets
  SET D = A.intersection(B);
  cout<<"Intersection of Set A and Set B: ";
  D.print();

  // Finds the symmetric difference of two sets
  SET E = A.symmetric_difference(B);
  cout <<"Symmetric Difference of Set A and Set B: ";
  E.print();


  // Finds the complement of a set
  SET F = A.complement(B);
  cout<< "Complement of Set A :";
  F.print();
}
