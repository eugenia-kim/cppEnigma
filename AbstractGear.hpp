#ifndef ABSTRACTGEAR_H
#define ABSTRACTGEAR_H

#include <vector>

class AbstractGear {
  public:
    AbstractGear(std::vector<int>);
    virtual int map(int) = 0;
  protected:
    std::vector<int> _config;
};

#endif
