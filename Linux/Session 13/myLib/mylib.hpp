#ifndef __MYLIB_H__
#define __MYLIB_H__

#include <vector>

class MyLib {
public:
    MyLib();
    void accumulateVector(const std::vector<int>& values);
    int getSum() const;

private:
    int sum;
};

#endif // __MYLIB_H__