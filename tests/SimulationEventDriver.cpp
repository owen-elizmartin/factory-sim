#include <gtest/gtest.h>
#include "Simulation.h"

namespace
{
    class MachineA: public IMachine
    {
        public:
            explicit MachineA(int id): IMachine(id) {}

            void process() override
            {
            
            }
            
            int getOutput() const override
            {
                return 1;
            }
    };  
}


TEST(BehaviorSuite, ProcessNextEvent_OneScheduledEvent_AdvancesTimeAndProcessesEvent)
{
    // Arrange
        Simulation simulation;
        simulation.setDebug(true); // Simulation now stalls after every resolved event, user need to call simulation.continue() to resume simulation.
        
        MachineManager& machines = simulation.getMachineManager();
        
        int id = machines.addMachine<MachineA>();

    // Act
        simulation.start();
        
    // Assert
        EXPECT_EQ(simulation.getStatus(), Simulation::Status::Running);
        simulation.resume();

        EXPECT_EQ(simulation.getCurrentTime(), 10);
        EXPECT_EQ(simulation.getMachineOutput(id), 1);
}   

TEST(BehaviorSuite, ProcessNextEvent_MultipleEvents_ProcessesEarliestFirst)
{
//    // Arrange
//        Simulation simulation;
//        simulation.setDebug(true);
//
//        
//    // Act
//        simulation.start();
//    // Assert
}

TEST(BehaviorSuite, ProcessNextEvent_EventCreatesEvent_ProcessesNewEvent)
{

}

TEST(BehaviorSuite, ProcessNextEvent_TwoEventsAtSameTime_ProcessesBothAtSameSimulationTime)
{
    
}

TEST(BehaviorSuite, ProcessNextEvent_NoEvents_DoesNotAdvanceTime)
{

}
