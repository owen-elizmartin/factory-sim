#include "MachineManager.h"

MachineManager::MachineManager(): _nextId(0) {}

//template<typename T>
//int MachineManager::addMachine() {
//    int id = _nextId++;
//    _machines[id] = std::make_unique<T>();
//    return id;
//}

int MachineManager::getOutput(int machineId) const {
    return 0;
}
