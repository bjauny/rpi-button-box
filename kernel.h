#pragma once

#include "serialLogger.h"

#include <circle/gpiomanager.h>
#include <circle/gpiopin.h>

#include <circle/sched/scheduler.h>
#include <circle/sched/synchronizationevent.h>

enum class EShutdownMode {
    ShutdownNone,
    ShutdownHalt,
    ShutdownReboot
};

class CKernel : public CSerialLogger {
    public:
        CKernel();
        virtual ~CKernel();

        bool Initialize();
        EShutdownMode Run();

        CGPIOPin& getButton() {return m_inputButton;}
        CSynchronizationEvent& getSynchro() {return m_synchro;}

    private:
        CGPIOManager m_gpioManager;
        CGPIOPin m_inputButton;

        CScheduler m_scheduler;
        CSynchronizationEvent m_synchro;
};
