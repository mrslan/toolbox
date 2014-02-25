#include <stdio.h>
#include <memory>
#include "Breaks.h"
#include "BreaksDummy.h"

Brakes* Brakes::GetInstance(BreakType type) {
    Brakes* breaks = NULL;

    switch(type) {
    case DUMMY:
        breaks = new BreaksDummy();
        break;

    default:
        printf("%s: Invalid type: %d\n", __func__, type);
        break;
    }

    if(breaks == NULL) {
        printf("Failed to create instance of type %d: break:%p\n",
                type,
                breaks);

        return NULL;
    }

    return breaks;
}
