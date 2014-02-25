#include <stdio.h>
#include "BreaksDummy.h"

BreaksDummy::BreaksDummy() {
}

BreaksDummy::~BreaksDummy() {
}

void BreaksDummy::Apply() {
    printf("%s: Applying breaks\n", __func__);
}

void BreaksDummy::Release() {
    printf("%s: Release breaks\n", __func__);
}

Brakes::~Brakes() {
    printf("%s\n", __func__);
}
