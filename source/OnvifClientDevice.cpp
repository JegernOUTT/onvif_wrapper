#include "OnvifClientDevice.h"
#include "wsseapi.h"
#include "../source/impl/OnvifClientDeviceImpl.h"

namespace onvifwrapper
{
	OnvifClientDevice::OnvifClientDevice() :
		impl_(std::make_unique<OnvifClietnDeviceImpl>())
	{
	}

	OnvifClientDevice::~OnvifClientDevice()
	{
		impl_->device_proxy_.soap_close_socket();
	}

	tuple<Result, OnvifCapabilities> OnvifClientDevice::GetCapabilities(InfoTuple information)
	{
		Authenticate(information);

		_ns1__GetCapabilities request;
		_ns1__GetCapabilitiesResponse response;
		request.Category.emplace_back(ns2__CapabilityCategory::All);
		
		auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetCapabilities(&request, response), impl_->device_proxy_.soap);
        if (result.is_error)
        {
            return make_tuple(result, OnvifCapabilities{});
        }
        return make_tuple(result, OnvifCapabilities
                                  {
                                      {
                                          S(S(response.Capabilities)->Analytics)->XAddr,
                                          S(S(response.Capabilities)->Analytics)->RuleSupport,
                                          S(S(response.Capabilities)->Analytics)->AnalyticsModuleSupport
                                      },
                                      {
                                          S(S(response.Capabilities)->Device)->XAddr,
                                          {
                                              *S(S(S(S(response.Capabilities)->Device)->Network)->IPFilter),
                                              *S(S(S(S(response.Capabilities)->Device)->Network)->ZeroConfiguration),
                                              *S(S(S(S(response.Capabilities)->Device)->Network)->IPVersion6),
                                              *S(S(S(S(response.Capabilities)->Device)->Network)->DynDNS)
                                          },
                                          {
                                              S(S(S(response.Capabilities)->Device)->System)->DiscoveryResolve,
                                              S(S(S(response.Capabilities)->Device)->System)->DiscoveryBye,
                                              S(S(S(response.Capabilities)->Device)->System)->RemoteDiscovery,
                                              S(S(S(response.Capabilities)->Device)->System)->SystemBackup,
                                              S(S(S(response.Capabilities)->Device)->System)->SystemLogging,
                                              S(S(S(response.Capabilities)->Device)->System)->FirmwareUpgrade,
                                          },
                                          {
                                              *S(S(S(S(response.Capabilities)->Device)->IO)->InputConnectors),
                                              *S(S(S(S(response.Capabilities)->Device)->IO)->RelayOutputs)
                                          },
                                          {
                                              S(S(S(response.Capabilities)->Device)->Security)->TLS1_x002e1,
                                              S(S(S(response.Capabilities)->Device)->Security)->TLS1_x002e2,
                                              S(S(S(response.Capabilities)->Device)->Security)->OnboardKeyGeneration,
                                              S(S(S(response.Capabilities)->Device)->Security)->AccessPolicyConfig,
                                              S(S(S(response.Capabilities)->Device)->Security)->X_x002e509Token,
                                              S(S(S(response.Capabilities)->Device)->Security)->SAMLToken,
                                              S(S(S(response.Capabilities)->Device)->Security)->KerberosToken,
                                              S(S(S(response.Capabilities)->Device)->Security)->RELToken
                                          }
                                      },
                                      {
                                          S(S(response.Capabilities)->Events)->XAddr,
                                          S(S(response.Capabilities)->Events)->WSSubscriptionPolicySupport,
                                          S(S(response.Capabilities)->Events)->WSPullPointSupport,
                                          S(S(response.Capabilities)->Events)->WSPausableSubscriptionManagerInterfaceSupport
                                      },
                                      {
                                          S(S(response.Capabilities)->Imaging)->XAddr
                                      },
                                      {
                                          S(S(response.Capabilities)->Media)->XAddr,
                                          {
                                              *S(S(S(S(response.Capabilities)->Media)->StreamingCapabilities)->RTPMulticast),
                                              *S(S(S(S(response.Capabilities)->Media)->StreamingCapabilities)->RTP_USCORETCP),
                                              *S(S(S(S(response.Capabilities)->Media)->StreamingCapabilities)->RTP_USCORERTSP_USCORETCP)
                                          }
                                      },
                                      {
                                          S(S(response.Capabilities)->PTZ)->XAddr
                                      }
                                  });
	}

    tuple<Result, string> OnvifClientDevice::SystemReboot(InfoTuple information)
	{
		Authenticate(information);

		_ns1__SystemReboot request;
		_ns1__SystemRebootResponse response;

		auto result = ErrorWrap::Wrap(impl_->device_proxy_.SystemReboot(&request, response), impl_->device_proxy_.soap);
        if (result.is_error)
        {
            return make_tuple(result, "");
        }
		return make_tuple(result, response.Message);
	}

    tuple<Result, DeviceInformation> OnvifClientDevice::GetDeviceInformation(InfoTuple information)
	{
		Authenticate(information);

		_ns1__GetDeviceInformation request;
		_ns1__GetDeviceInformationResponse response;

		auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetDeviceInformation(&request, response), impl_->device_proxy_.soap);
        if (result.is_error)
        {
            return make_tuple(result, DeviceInformation{});
        }
		return make_tuple(result,
						  DeviceInformation { response.FirmwareVersion,
											  response.HardwareId, 
											  response.Manufacturer, 
											  response.Model, 
											  response.SerialNumber });
	}

    void OnvifClientDevice::Authenticate(InfoTuple& information)
	{
		impl_->device_proxy_.soap_endpoint = get<2>(information).c_str();
		soap_wsse_add_Security(impl_->device_proxy_.soap);
		soap_wsse_add_UsernameTokenDigest(impl_->device_proxy_.soap, "Id", get<0>(information).c_str(), get<1>(information).c_str());

		impl_->device_proxy_.soap->recv_timeout = 5;
		impl_->device_proxy_.soap->send_timeout = 5;
		impl_->device_proxy_.soap->connect_timeout = 5;
	}
}
