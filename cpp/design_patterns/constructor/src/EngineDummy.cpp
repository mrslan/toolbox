#include <stdio.h>
#include "EngineDummy.h"

EngineDummy::EngineDummy() {
}


EngineDummy::~EngineDummy() {
}

void EngineDummy::Start() {
    printf("%s: Starting Engine\n", __func__);
}

void EngineDummy::ShutDown() {
    printf("%s: Stopping Engine\n", __func__);
}
