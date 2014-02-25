#include <memory>
#include "Breaks.h"

void Brakes::RunSample() {
    std::auto_ptr<Brakes> breaks(Brakes::GetInstance(Brakes::DUMMY));
    breaks->Apply();
    breaks->Release();
}
