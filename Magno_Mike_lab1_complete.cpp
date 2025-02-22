#include <iostream>
#include <string>
using namespace std;

const int maxElem = 30; 
int myArray[maxElem];   
int numElem = 0;        

string traverseArray() {
    if (numElem == 0) {
        return "The array is empty.\n";
    }
    string result = "Array elements: ";
    for (int i = 0; i < numElem; i++) {
        result += to_string(myArray[i]) + " ";
    }
    return result + "\n";
}

string insertAtTheEnd(int num) {
    if (numElem != maxElem) {
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

string insertAtTheBeginning(int num) {
    if (numElem != maxElem) {
        for (int i = numElem; i > 0; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

string insertAtTheGivenPosition(int num, int elementAfter) {
    if (numElem != maxElem) {
        int position = -1;
        for (int i = 0; i < numElem; i++) {
            if (myArray[i] == elementAfter) {
                position = i + 1;
                break;
            }
        }
        if (position == -1) {
            return "Specified element not found.\n";
        }
        for (int i = numElem; i > position; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[position] = num;
        numElem++;
        return "An element is successfully inserted at the specified location!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

int main() {
    myArray[0] = 0;
    myArray[1] = 1;
    myArray[2] = 2;
    myArray[3] = 3;
    myArray[4] = 4;
    numElem = 5;

    cout << traverseArray();
    cout << insertAtTheBeginning(3);
    cout << insertAtTheEnd(7);
    cout << insertAtTheEnd(9);
    cout << insertAtTheBeginning(20);
    cout << insertAtTheGivenPosition(37, 7);
    cout << insertAtTheBeginning(256);
    cout << insertAtTheGivenPosition(128, 9);
    cout << insertAtTheBeginning(19);

    cout << traversArray();


    void bubbleSort(){
        int i, j;
        bool swapped;
        for(int i =0; i < numElem - 1; i ++){
            swapped = false;
            for int (j = 0; j < numElem - i -1; j++ ) {
                if (myArrray[j] > myArray[j+1]){
                    swap(myArrray[j] , myArray[j+1]);
                    swaped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }

    }



    return 0;
}