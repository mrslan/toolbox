#include "Breaks.h"

class BreaksDummy: public Brakes
{
public:
    BreaksDummy();
    ~BreaksDummy();

    void Apply();
    void Release();
};
