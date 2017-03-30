#include "OnvifClientImaging.h"
#include "wsseapi.h"
#include "../source/impl/OnvifClientImagingImpl.h"

using namespace onvifwrapper;

OnvifClientImaging::OnvifClientImaging() :
    impl_(make_unique<OnvifClientImagingImpl>())
{
}

OnvifClientImaging::~OnvifClientImaging()
{
}

tuple<Result, ImageSettings> OnvifClientImaging::GetImagingSettings(InfoTuple information,
                                                                    string video_source_token)
{
	Authenticate(information);

	_ns8__GetImagingSettings request;
	_ns8__GetImagingSettingsResponse response;
	request.VideoSourceToken = video_source_token;

	auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetImagingSettings(&request, response), impl_->device_proxy_.soap);
	if (result.is_error)
	{
        return make_tuple(result, ImageSettings{});
	}
	return make_tuple(result, 
					  ImageSettings
                      {
                          {
                              S(S(S(response.ImagingSettings)->BacklightCompensation)->Level),
                              static_cast<OnMode>(S(S(response.ImagingSettings)->BacklightCompensation)->Mode)
                          },
                          S(S(response.ImagingSettings)->Brightness),
                          S(S(response.ImagingSettings)->ColorSaturation),
                          S(S(response.ImagingSettings)->Sharpness),
                          S(S(response.ImagingSettings)->Contrast),
                          {
                              
                              static_cast<ExpMode>(S(S(response.ImagingSettings)->Exposure)->Mode),
                              S(S(S(response.ImagingSettings)->Exposure)->ExposureTime),
                              S(S(S(response.ImagingSettings)->Exposure)->Gain),
                              S(S(S(response.ImagingSettings)->Exposure)->Iris),
                              S(S(S(response.ImagingSettings)->Exposure)->MaxExposureTime),
                              S(S(S(response.ImagingSettings)->Exposure)->MinGain),
                              S(S(S(response.ImagingSettings)->Exposure)->MaxIris)
                          }
                      });
}

Result OnvifClientImaging::SetImagingSettings(InfoTuple information,
                                              string video_source_token,
                                              ImageSettings image_settings,
                                              bool force)
{
    Authenticate(information);

    _ns8__SetImagingSettings request;
    _ns8__SetImagingSettingsResponse response;
    request.VideoSourceToken = video_source_token;
    request.ImagingSettings->BacklightCompensation->Mode =
        static_cast<ns2__BacklightCompensationMode>(image_settings.back_light_compensation.mode);
    request.ImagingSettings->BacklightCompensation->Level = &image_settings.back_light_compensation.level;
    request.ImagingSettings->Brightness = &image_settings.brightness;
    request.ImagingSettings->ColorSaturation = &image_settings.color_saturation;
    request.ImagingSettings->Sharpness = &image_settings.sharpness;
    request.ImagingSettings->Contrast = &image_settings.contrast;
    request.ImagingSettings->Exposure->Mode = static_cast<ns2__ExposureMode>(image_settings.exposure.mode);
    request.ImagingSettings->Exposure->ExposureTime = &image_settings.exposure.exposure_time;
    request.ImagingSettings->Exposure->Gain = &image_settings.exposure.gain;
    request.ImagingSettings->Exposure->Iris = &image_settings.exposure.iris;
    request.ImagingSettings->Exposure->MaxExposureTime = &image_settings.exposure.max_exposure_time;
    request.ImagingSettings->Exposure->MinGain = &image_settings.exposure.min_gain;
    request.ImagingSettings->Exposure->MaxIris = &image_settings.exposure.max_iris;
    request.ForcePersistence = &force;

    return ErrorWrap::Wrap(impl_->device_proxy_.SetImagingSettings(&request, response), impl_->device_proxy_.soap);

}

tuple<Result, ImageOptions> OnvifClientImaging::GetOptions(InfoTuple information,
                                                           string video_source_token)
{
    Authenticate(information);

    _ns8__GetOptions request;
    _ns8__GetOptionsResponse response;
    request.VideoSourceToken = video_source_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetOptions(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, ImageOptions{});
    }

    return make_tuple(result, 
                      ImageOptions
                      {
                          {
                              { 
                                  S(S(S(response.ImagingOptions)->BacklightCompensation)->Level)->Min,
                                  S(S(S(response.ImagingOptions)->BacklightCompensation)->Level)->Max
                              },
                              {
                                  static_cast<OnMode>(S(S(response.ImagingOptions)->BacklightCompensation)->Mode.front()),
                                  static_cast<OnMode>(S(S(response.ImagingOptions)->BacklightCompensation)->Mode.back())
                              }
                          },
                          {
                              S(S(response.ImagingOptions)->Brightness)->Min,
                              S(S(response.ImagingOptions)->Brightness)->Max
                          },
                          {
                              S(S(response.ImagingOptions)->ColorSaturation)->Min,
                              S(S(response.ImagingOptions)->ColorSaturation)->Max
                          },
                          {
                              S(S(response.ImagingOptions)->Sharpness)->Min,
                              S(S(response.ImagingOptions)->Sharpness)->Max
                          },
                          {
                              S(S(response.ImagingOptions)->Contrast)->Min,
                              S(S(response.ImagingOptions)->Contrast)->Max
                          },
                          {
                              {
                                  static_cast<ExpMode>(S(S(response.ImagingOptions)->Exposure)->Mode.front()),
                                  static_cast<ExpMode>(S(S(response.ImagingOptions)->Exposure)->Mode.back()),
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->ExposureTime)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->ExposureTime)->Max
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->Gain)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->Gain)->Max
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->Iris)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->Iris)->Max
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->MaxExposureTime)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->MaxExposureTime)->Max
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->MinGain)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->MinGain)->Max
                              },
                              {
                                  S(S(S(response.ImagingOptions)->Exposure)->MaxIris)->Min,
                                  S(S(S(response.ImagingOptions)->Exposure)->MaxIris)->Max
                              },
                          }
                      });
}

Result OnvifClientImaging::Move(InfoTuple information,
                                       string video_source_token,
                                       FocusMove focus_move)
{
    Authenticate(information);

    _ns8__Move request;
    _ns8__MoveResponse response;
    request.Focus->Absolute->Position = focus_move.absolute_move.position;
    request.Focus->Absolute->Speed = &focus_move.absolute_move.speed;
    request.Focus->Relative->Distance = focus_move.relative_move.distance;
    request.Focus->Relative->Speed = &focus_move.relative_move.speed;
    request.Focus->Continuous->Speed = focus_move.continuous_move.speed;
    request.VideoSourceToken = video_source_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.Move(&request, response), impl_->device_proxy_.soap);
}

tuple<Result, FocusMoveOptionsRange> OnvifClientImaging::GetMoveOptions(InfoTuple information,
                                                                   string video_source_token)
{
    Authenticate(information);

    _ns8__GetMoveOptions request;
    _ns8__GetMoveOptionsResponse response;
    request.VideoSourceToken = video_source_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetMoveOptions(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, FocusMoveOptionsRange{});
    }
    return make_tuple(result, 
                      FocusMoveOptionsRange
                      {
                          {
                              {
                                  S(S(S(response.MoveOptions)->Absolute)->Position)->Min,
                                  S(S(S(response.MoveOptions)->Absolute)->Position)->Max
                              },
                              {
                                  S(S(S(response.MoveOptions)->Absolute)->Speed)->Min,
                                  S(S(S(response.MoveOptions)->Absolute)->Speed)->Max
                              }
                          },
                          {
                              {
                                  S(S(S(response.MoveOptions)->Relative)->Distance)->Min,
                                  S(S(S(response.MoveOptions)->Relative)->Distance)->Max
                              },
                              {
                                  S(S(S(response.MoveOptions)->Relative)->Speed)->Min,
                                  S(S(S(response.MoveOptions)->Relative)->Speed)->Max
                              }
                          },
                          {
                              {
                                  S(S(S(response.MoveOptions)->Continuous)->Speed)->Min,
                                  S(S(S(response.MoveOptions)->Continuous)->Speed)->Max
                              }
                          }
                      });
}

Result OnvifClientImaging::Stop(InfoTuple information,
                                       string video_source_token)
{
    Authenticate(information);

    _ns8__Stop request;
    _ns8__StopResponse response;
    request.VideoSourceToken = video_source_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.Stop(&request, response), impl_->device_proxy_.soap);
}

tuple<Result, ImagingStatus> OnvifClientImaging::GetImagingStatus(InfoTuple information,
                                                                  string video_source_token)
{
    Authenticate(information);

    _ns8__GetStatus request;
    _ns8__GetStatusResponse response;
    request.VideoSourceToken = video_source_token;
	auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetStatus(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, ImagingStatus{});
    }
    return make_tuple(result, 
                      ImagingStatus
                      {
                          S(S(response.Status)->FocusStatus20)->Position,
                          static_cast<MoveStatus>(S(S(response.Status)->FocusStatus20)->MoveStatus),
                          *S(S(S(response.Status)->FocusStatus20)->Error),
                      });
}

tuple<Result, ImageCapabilities> OnvifClientImaging::GetServiceCapabilities(InfoTuple information)
{
    Authenticate(information);

	_ns8__GetServiceCapabilities request;
    _ns8__GetServiceCapabilitiesResponse response;
	
    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetServiceCapabilities(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, ImageCapabilities{});
    }
    return make_tuple(result, ImageCapabilities{ S(S(response.Capabilities)->ImageStabilization), 
                                                 S(S(response.Capabilities)->Presets) });
}

void OnvifClientImaging::Authenticate(InfoTuple& information)
{
    impl_->device_proxy_.soap_endpoint = get<2>(information).c_str();
    soap_wsse_add_Security(impl_->device_proxy_.soap);
    soap_wsse_add_UsernameTokenDigest(impl_->device_proxy_.soap, "Id", get<0>(information).c_str(), get<1>(information).c_str());

    impl_->device_proxy_.soap->recv_timeout = 5;
    impl_->device_proxy_.soap->send_timeout = 5;
    impl_->device_proxy_.soap->connect_timeout = 5;
}
