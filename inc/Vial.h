#ifndef VIAL_H
#define VIAL_H

class Vial {
private:
    char contents[4];
    int filled;
    int label;

public:
    Vial();
    Vial(char arr[], int size, int filledCount);
    Vial(char c1, char c2, char c3, char c4, int filledCount);

    bool add(char content);
    void display() const;
    bool isComplete() const;
    void setLabel(int label);
    bool transfer(Vial& destination);
};

#endif
