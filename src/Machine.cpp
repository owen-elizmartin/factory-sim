#include "Machine.h"

Machine::Status Machine::getStatus() const {
    return _status;
}

int Machine::getItemProduced() const {
    return _itemProduced;
}
