#pragma once

#include <circle/devicenameservice.h>
#include <circle/koptions.h>
#include <circle/interrupt.h>
#include <circle/logger.h>
#include <circle/serial.h>
#include <circle/timer.h>

class CSerialLogger {
    public:
        CSerialLogger();
        virtual ~CSerialLogger();

    private:
        CKernelOptions m_options;
        CDeviceNameService m_deviceNameService;
        CInterruptSystem m_interruptSystem;
        CSerialDevice m_serial;
        CTimer m_timer;
        CLogger m_logger;
};