#pragma once
#include <memory>
#include <unordered_map>
#include "IMachine.h"

class MachineManager {
    public:
        MachineManager();

        template<typename T>
        int addMachine() {
            int id = _nextId++;
            _machines[id] = std::make_unique<T>(id);
            return id;
        }

        int getOutput(int machineId) const;
         
    private:
        std::unordered_map<int, std::unique_ptr<IMachine>> _machines;
        int _nextId;
};
