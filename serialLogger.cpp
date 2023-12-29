#include "serialLogger.h"

CSerialLogger::CSerialLogger()  :
    m_options(),
    m_deviceNameService(),
    m_interruptSystem(),
    m_serial(),
    m_timer(&m_interruptSystem),
    m_logger(m_options.GetLogLevel(), &m_timer, true) {
    assert(m_serial.Initialize(115200));
    CDevice *pTarget = m_deviceNameService.GetDevice(m_options.GetLogDevice(), false);
    assert(nullptr != pTarget);
    assert(m_logger.Initialize(pTarget));
    assert(m_interruptSystem.Initialize());
    assert(m_timer.Initialize());
}

CSerialLogger::~CSerialLogger() {

}