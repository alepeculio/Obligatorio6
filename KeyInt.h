#ifndef KEYINT_H
#define KEYINT_H

class KeyInt : public IKey {
private:
    int n;
public:
    KeyInt(int);

    bool equals(IKey*);
    int getKeyInt();

    ~KeyInt();


};


#endif /* KEYINT_H */

