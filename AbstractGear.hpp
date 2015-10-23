#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

class AbstractGear {
  public:
    AbstractGear(int*);
    virtual int map(int) = 0;
  protected:
    int* _config;
};

#endif
