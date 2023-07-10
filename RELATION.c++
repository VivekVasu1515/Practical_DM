#include <iostream>
using namespace std;
const int size = 4; // Size of the set

class RELATION {
    bool rel[size][size]; // Boolean matrix to represent the binary relation
    public:
        // Constructor to initialize the relation matrix
        RELATION(bool arr[size][size]) {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    rel[i][j] = arr[i][j];
        }
        // Method to check if the relation is reflexive
        bool isReflexive() {
            for (int i = 0; i < size; i++)
                if (rel[i][i] == 0)
                    return false;
            return true;
        }
        // Method to check if the relation is symmetric
        bool isSymmetric() {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (rel[i][j] != rel[j][i])
                        return false;
            return true;
        }
        // Method to check if the relation is anti-symmetric
        bool isAntiSymmetric() {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (rel[i][j] && rel[j][i] && i != j)
                        return false;
            return true;
        }
        // Method to check if the relation is transitive
        bool isTransitive() {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int k = 0; k < size; k++)
                        if (rel[i][j] && rel[j][k] && !rel[i][k])
                            return false;
            return true;
        }
        // Method to check the type of the relation
        void checkRelation() {
            if (isReflexive() && isSymmetric() && isTransitive())
                cout << "The given relation is an Equivalence Relation";
            else if (isReflexive() && isAntiSymmetric() && isTransitive())
                cout << "The given relation is a Partial Order Relation";
            else
                cout << "The given relation is None";
        }
};

int main() {
    // Define a binary relation on a 4-element set
    bool arr[size][size] = {{1, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 1, 1},
                            {0, 0, 1, 1}};
    RELATION r(arr); // Create an instance of the RELATION class
    cout << r.isReflexive() << endl; // Check if the relation is reflexive
    cout << r.isSymmetric() << endl; // Check if the relation is symmetric
    cout << r.isTransitive() << endl; // Check if the relation is transitive
    cout << r.isAntiSymmetric() << endl; // Check if the relation is anti-symmetric
    r.checkRelation(); // Check the type of the relation
    return 0;
}
