#include <stdio.h>
#include <memory>
#include "Breaks.h"

DummyBreaks::DummyBreaks() {
}

DummyBreaks::~DummyBreaks() {
}

void DummyBreaks::Apply() {
    printf("%s: Applying breaks\n", __func__);
}

void DummyBreaks::Release() {
    printf("%s: Release breaks\n", __func__);
}

IBrakes::~IBrakes() {
    printf("%s\n", __func__);
}

IBrakes* IBrakes::GetInstance(BreakType type) {
    IBrakes* breaks = NULL;

    switch(type) {
    case DUMMY:
        breaks = new DummyBreaks();
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

void IBrakes::RunSample() {
    std::auto_ptr<IBrakes> breaks(IBrakes::GetInstance(IBrakes::DUMMY));
    breaks->Apply();
    breaks->Release();
}
