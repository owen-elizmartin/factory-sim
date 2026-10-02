#pragma once
#include "MachineManager.h"

class Simulation {
    public:
        enum class Status {
            Idle,
            Paused,
            Running
        };
        
        Simulation();
        Status getStatus() const;
        int getCurrentTime() const;
        MachineManager& getMachineManager();
        int getMachineOutput(int machineId) const;
        
        void setDebug(bool b);
        
        void start();
        void resume();
    private:
        Status _status; 
        int _currentTime; // Single source of truth for simulation time;
        MachineManager _machineManager;
        bool _isDebugMode;
};
