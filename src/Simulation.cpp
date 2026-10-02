#include "Simulation.h"

Simulation::Simulation(): _status(Simulation::Status::Idle), _currentTime(0), _isDebugMode(false) {}

Simulation::Status Simulation::getStatus() const {
    return _status;
}

int Simulation::getCurrentTime() const {
    return _currentTime;
}

MachineManager& Simulation::getMachineManager() {
    return _machineManager;
}

int Simulation::getMachineOutput(int machineId) const {
    return _machineManager.getOutput(machineId);
}

void Simulation::setDebug(bool b) {
    _isDebugMode = b;
}

void Simulation::start() {
    _status = Simulation::Status::Running;
}

void Simulation::resume() {
    if (_status == Simulation::Status::Paused) {
        _status = Simulation::Status::Running;
    }
}
