#include "EncodersDriver.h"

EncodersDriver::EncodersDriver() : m_menuEncoder(),
                                   m_valueEncoder(m_menuEncoder.getCcList())
{
}
