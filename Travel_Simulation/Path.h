#ifndef PATH_H
#define PATH_H

#include <string>
#include "MyTime.h"

using std::string;

typedef  struct PATH {
    string start;
    string end;
    MyTime timeCost;
    int moneyCost;
} Path;

#endif // PATH_H
