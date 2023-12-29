#include "blinkTask.h"
#include "kernel.h"

#include <stdint.h>

LOGMODULE("CKernel");

void buttonHandler(void *pParam) {
    CKernel* kernel = static_cast<CKernel*>(pParam);
    assert(nullptr != kernel);
    LOGDBG("buttonHandler catched the interrupt");
    // Adding an explicit read for debounce purpose
    if (kernel->getButton().Read() > 0) {
        kernel->getSynchro().Set();
    }
}

CKernel::CKernel() : CSerialLogger(),
    m_gpioManager(CInterruptSystem::Get()),
    m_inputButton(23, GPIOModeInputPullDown, &m_gpioManager),
    m_scheduler(),
    m_synchro(false) {
}

CKernel::~CKernel() {
}

bool CKernel::Initialize() {
    bool initOK = false;
    LOGDBG("Initializing...");
    if (m_gpioManager.Initialize()) {
        m_inputButton.ConnectInterrupt(buttonHandler, this, true);
        m_inputButton.EnableInterrupt(GPIOInterruptOnRisingEdge);
        initOK = true;
    }
    LOGDBG("Initializing %s", initOK ? "OK" : "KO");
    return initOK;
}

EShutdownMode CKernel::Run() {
    CBlinkTask blinkTask{m_synchro}; // Ideally, pass here the LED info

    //blinkTask.Run();
    blinkTask.WaitForTermination();
    
    return EShutdownMode::ShutdownReboot;
}