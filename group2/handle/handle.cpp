#include "core.h"
#include "handle.h"

bool compare_Core_handles(const Handle<Core> c1, const Handle<Core> c2) {
    return c1->name() < c2->name();
}
