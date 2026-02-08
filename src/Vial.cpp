#include "Vial.h"
#include <iostream>

using namespace std;

Vial::Vial() {
    for (int i = 0; i < 4; i++) {
        contents[i] = ' ';
    }
    filled = 0;
    label = 0;
}

Vial::Vial(char arr[], int size, int filledCount) {
    for (int i = 0; i < 4; i++) {
        if (i < size) {
            contents[i] = arr[i];
        }
        else {
            contents[i] = ' ';
        }
    }
    filled = filledCount;
    label = 0;
}

Vial::Vial(char c1, char c2, char c3, char c4, int filledCount) {
    contents[0] = c1;
    contents[1] = c2;
    contents[2] = c3;
    contents[3] = c4;
    filled = filledCount;
    label = 0;
}

bool Vial::add(char content) {
    if (filled >= 4) {
        return false;
    }
    contents[filled] = content;
    filled++;
    return true;
}

void Vial::setLabel(int lbl) {
    label = lbl;
}

void Vial::display() const {
    cout << "Vial " << label << ": [ ";
    for (int i = 0; i < 4; i++) {
        cout << contents[i] << " ";
    }
    cout << "]" << endl;
}

bool Vial::isComplete() const {
    if (filled == 0) {
        return true;
    }

    char first = contents[0];
    for (int i = 1; i < filled; i++) {
        if (contents[i] != first) {
            return false;
        }
    }
    return true;
}

bool Vial::transfer(Vial& destination) {
    if (filled == 0) {
        cout << "Source vial is empty." << endl;
        return false;
    }

    if (destination.filled == 4) {
        cout << "Destination vial is full." << endl;
        return false;
    }

    char movingChar = contents[filled - 1];

    if (destination.filled > 0) {
        char destTop = destination.contents[destination.filled - 1];
        if (destTop != movingChar) {
            cout << "Contents do not match." << endl;
            return false;
        }
    }

    bool movedSomething = false;

    while (filled > 0 &&
        contents[filled - 1] == movingChar &&
        destination.filled < 4) {

        destination.contents[destination.filled] = movingChar;
        destination.filled++;

        contents[filled - 1] = ' ';
        filled--;

        movedSomething = true;
    }

    return movedSomething;
}
