#include <circle/gpiopin.h>
#include <circle/sched/task.h>

class CBlinkTask : public CTask {
    public:
        CBlinkTask(CSynchronizationEvent& p_synchro);
        virtual ~CBlinkTask();

        void Run() override;
    
    private:
        CGPIOPin m_outputLED;
        CSynchronizationEvent& m_synchro;
};