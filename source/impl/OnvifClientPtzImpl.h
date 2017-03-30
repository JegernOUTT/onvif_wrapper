#pragma once

#include "soapPTZBindingProxy.h"

namespace onvifwrapper
{
    struct OnvifClientPtzImpl
    {
        PTZBindingProxy device_proxy_;
    };
}
