#pragma once

#include <vector>
#include <tuple>
#include <memory>

#include "ErrorWrap.hpp"
#include "Utility.hpp"

namespace onvifwrapper
{
    using std::string;
    using std::vector;
    using std::tuple;
    using std::unique_ptr;

    using std::make_unique;
    using std::make_tuple;
    using std::get;

    struct OnvifClietnDeviceImpl;

	class OnvifClientDevice final
    {
		using InfoTuple = tuple<string, string, string>;

    public:
		OnvifClientDevice();
		OnvifClientDevice(OnvifClientDevice&) = delete;
		OnvifClientDevice& operator=(OnvifClientDevice&) = delete;
        ~OnvifClientDevice();

		tuple<Result, OnvifCapabilities> GetCapabilities(InfoTuple information);
		tuple<Result, string> SystemReboot(InfoTuple information);
		tuple<Result, DeviceInformation> GetDeviceInformation(InfoTuple information);

    private:
		unique_ptr<OnvifClietnDeviceImpl> impl_;

		void Authenticate(InfoTuple& information);
    };
}
