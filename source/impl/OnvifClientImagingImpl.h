#pragma once

#include "soapImagingBindingProxy.h"

namespace onvifwrapper
{
    struct OnvifClientImagingImpl
    {
        ImagingBindingProxy device_proxy_;
    };
}
