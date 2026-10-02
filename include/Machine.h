#pragma once

class Machine {
    public:
        enum class Status {
            Idle,
            Running
        };
        
        Status getStatus() const;
        int getItemProduced() const;

    private:
        Machine::Status _status;
        int _itemProduced;
        int _completionTime;
};
