#include "blinkTask.h"

#include <circle/logger.h>
#include <circle/sched/scheduler.h>

LOGMODULE("CBlinkTask");

CBlinkTask::CBlinkTask(CSynchronizationEvent& p_synchro) :
    CTask(),
    m_outputLED(18, GPIOModeOutput),
    m_synchro(p_synchro) {
        LOGDBG("Task created");
}

CBlinkTask::~CBlinkTask() {}

void CBlinkTask::Run() {
    LOGDBG("Task running...");
    while(true) {
        m_synchro.Wait();

        for (unsigned i = 1; i <= 10; i++)
        {
            m_outputLED.Invert();
            CScheduler::Get()->MsSleep (200);

            m_outputLED.Invert();
            CScheduler::Get()->MsSleep (200);
        }

        m_synchro.Clear();
    }
}