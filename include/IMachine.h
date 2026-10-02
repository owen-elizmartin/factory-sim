#pragma once

class IMachine {
    protected:
        explicit IMachine(int id): _id(id) {}

    private:
        int _id;

    public:

        virtual ~IMachine() = default;

        virtual void process() = 0;
        virtual int getOutput() const = 0; 
        int getId() const { return _id; }
};
