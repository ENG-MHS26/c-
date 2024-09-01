#include <iostream>

using namespace std;


void display(int i) {
    cout << "Value of int is: " << i << endl;
}

void display(float j) {
    cout << "Value of float is: " << j << endl;
}

void display(int i, float j) {
    cout << "Values entered: " << i << " & " << j << endl;
}
void display(float i, int j) {
    cout << "Values entered: " << i << " & " << j << endl;
}

int main() {
    display(5);      
    display (3.7f);   

    return 0;
}
