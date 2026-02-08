#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vial.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int NUM_VIALS = 5;

    Vial vials[NUM_VIALS];

    for (int i = 0; i < NUM_VIALS; i++) {
        vials[i].setLabel(i + 1);
    }

    char pool[16] = {
        'A','A','A','A',
        'B','B','B','B',
        'C','C','C','C',
        'D','D','D','D'
    };

    int index = 0;
    while (index < 16) {
        int vialIndex = rand() % 4;
        if (vials[vialIndex].add(pool[index])) {
            index++;
        }
    }

    bool done = false;

    while (!done) {
        cout << "\nCurrent Vials:\n";
        for (int i = 0; i < NUM_VIALS; i++) {
            vials[i].display();
        }

        int source, destination;
        cout << "\nEnter source vial (0 to quit): ";
        cin >> source;

        if (source == 0) {
            break;
        }

        cout << "Enter destination vial: ";
        cin >> destination;

        if (source < 1 || source > NUM_VIALS ||
            destination < 1 || destination > NUM_VIALS) {
            cout << "Invalid selection." << endl;
            continue;
        }

        vials[source - 1].transfer(vials[destination - 1]);

        done = true;
        for (int i = 0; i < NUM_VIALS; i++) {
            if (!vials[i].isComplete()) {
                done = false;
            }
        }
    }

    cout << "\nGame over.\n";
    return 0;
}
\
