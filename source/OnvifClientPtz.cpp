#include "OnvifClientPtz.h"
#include "wsseapi.h"
#include "../source/impl/OnvifClientPtzImpl.h"

using namespace onvifwrapper;

OnvifClientPTZ::OnvifClientPTZ() :
    is_ptz_(false),
    impl_(make_unique<OnvifClientPtzImpl>())
{
}

OnvifClientPTZ::~OnvifClientPTZ()
{
}

bool OnvifClientPTZ::IsPtz() const
{
    return is_ptz_;
}

void OnvifClientPTZ::FillIsPtz(tuple<Result, vector<PTZConfiguration>> configurations)
{
    is_ptz_ = !(get<0>(configurations).is_error || get<1>(configurations).size() == 0);
}

tuple<Result, PTZConfiguration> OnvifClientPTZ::GetConfiguration(InfoTuple information,
                                                                 string ptz_configuration_token)
{
    Authenticate(information);

    _ns11__GetConfiguration	request;
    _ns11__GetConfigurationResponse response;
    request.PTZConfigurationToken = ptz_configuration_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetConfiguration(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        FillIsPtz(make_tuple(result, vector<PTZConfiguration>{}));
        return make_tuple(result, PTZConfiguration{});
    }
    
    FillIsPtz(make_tuple(result, vector<PTZConfiguration>{ ConvertToPtzConfig(response.PTZConfiguration) }));
    return make_tuple(result, ConvertToPtzConfig(response.PTZConfiguration));
}
tuple<Result, vector<PTZConfiguration>> OnvifClientPTZ::GetConfigurations(InfoTuple information)
{
    Authenticate(information);

    _ns11__GetConfigurations request;
    _ns11__GetConfigurationsResponse response;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetConfigurations(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        FillIsPtz(make_tuple(result, vector<PTZConfiguration>{}));
        return make_tuple(result, vector<PTZConfiguration>{});
    }

    vector<PTZConfiguration> configs;
    for_each(response.PTZConfiguration.begin(),
             response.PTZConfiguration.end(),
             [&configs](auto el) { configs.emplace_back(ConvertToPtzConfig(el)); });
    FillIsPtz(make_tuple(result, configs));
    return make_tuple(result, configs);
}
tuple<Result, PTZConfigurationOptions> OnvifClientPTZ::GetConfigurationOptions(InfoTuple information,
                                                                               string ptz_configuration_token)
{
    Authenticate(information);

    _ns11__GetConfigurationOptions request;
    _ns11__GetConfigurationOptionsResponse response;
    request.ConfigurationToken = ptz_configuration_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetConfigurationOptions(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, PTZConfigurationOptions{});
    }

    return make_tuple(result, ConvertToPtzConfigOptions(response.PTZConfigurationOptions));
}

Result OnvifClientPTZ::RelativeMove(InfoTuple information,
                                    PTZVector translation,
                                    PTZSpeed speed,
                                    string profile_token)
{
    Authenticate(information);

    _ns11__RelativeMove request;
    _ns11__RelativeMoveResponse response;

    ns2__Vector2D translation_vector2D;
    translation_vector2D.x = translation.pan_tilt.x;
    translation_vector2D.y = translation.pan_tilt.y;
    translation_vector2D.space = &translation.pan_tilt.space;
    ns2__Vector1D translation_vector1D;
    translation_vector1D.x = translation.zoom.x;
    translation_vector1D.space = &translation.zoom.space;
    ns2__PTZVector translation_vector;
    translation_vector.PanTilt = &translation_vector2D;
    translation_vector.Zoom = &translation_vector1D;

    ns2__Vector2D speed_vector2D;
    speed_vector2D.x = speed.pan_tilt.x;
    speed_vector2D.y = speed.pan_tilt.y;
    speed_vector2D.space = &speed.pan_tilt.space;
    ns2__Vector1D speed_vector1D;
    speed_vector1D.x = speed.zoom.x;
    speed_vector1D.space = &speed.zoom.space;
    ns2__PTZSpeed speed_vector;
    speed_vector.PanTilt = &speed_vector2D;
    speed_vector.Zoom = &speed_vector1D;

    request.ProfileToken = profile_token;
    request.Translation = &translation_vector;
    request.Speed = &speed_vector;

    return ErrorWrap::Wrap(impl_->device_proxy_.RelativeMove(&request, response), impl_->device_proxy_.soap);
}
Result OnvifClientPTZ::ContinuousMove(InfoTuple information, 
                                      PTZSpeed speed,
                                      string timeout,
                                      string profile_token)
{
    Authenticate(information);

    _ns11__ContinuousMove request;
    _ns11__ContinuousMoveResponse response;

    ns2__Vector2D speed_vector2D;
    speed_vector2D.x = speed.pan_tilt.x;
    speed_vector2D.y = speed.pan_tilt.y;
    speed_vector2D.space = &speed.pan_tilt.space;
    ns2__Vector1D speed_vector1D;
    speed_vector1D.x = speed.zoom.x;
    speed_vector1D.space = &speed.zoom.space;
    ns2__PTZSpeed speed_vector;
    speed_vector.PanTilt = &speed_vector2D;
    speed_vector.Zoom = &speed_vector1D;

    request.ProfileToken = profile_token;
    request.Velocity = &speed_vector;
    request.Timeout = &timeout;

    return ErrorWrap::Wrap(impl_->device_proxy_.ContinuousMove(&request, response), impl_->device_proxy_.soap);
}
Result OnvifClientPTZ::AbsoluteMove(InfoTuple information,
                                    PTZSpeed speed,
                                    PTZVector position,
                                    string profile_token)
{
    Authenticate(information);

    _ns11__AbsoluteMove request;
    _ns11__AbsoluteMoveResponse response;

    ns2__Vector2D position_vector2D;
    position_vector2D.x = position.pan_tilt.x;
    position_vector2D.y = position.pan_tilt.y;
    position_vector2D.space = &position.pan_tilt.space;
    ns2__Vector1D position_vector1D;
    position_vector1D.x = position.zoom.x;
    position_vector1D.space = &position.zoom.space;
    ns2__PTZVector position_vector;
    position_vector.PanTilt = &position_vector2D;
    position_vector.Zoom = &position_vector1D;

    ns2__Vector2D speed_vector2D;
    speed_vector2D.x = speed.pan_tilt.x;
    speed_vector2D.y = speed.pan_tilt.y;
    speed_vector2D.space = &speed.pan_tilt.space;
    ns2__Vector1D speed_vector1D;
    speed_vector1D.x = speed.zoom.x;
    speed_vector1D.space = &speed.zoom.space;
    ns2__PTZSpeed speed_vector;
    speed_vector.PanTilt = &speed_vector2D;
    speed_vector.Zoom = &speed_vector1D;

    request.ProfileToken = profile_token;
    request.Position = &position_vector;
    request.Speed = &speed_vector;
    
    return ErrorWrap::Wrap(impl_->device_proxy_.AbsoluteMove(&request, response), impl_->device_proxy_.soap);
}
Result OnvifClientPTZ::Stop(InfoTuple information,
                            bool pan_tilt,
                            bool zoom,
                            string profile_token)
{
    Authenticate(information);

	_ns11__Stop request;
    _ns11__StopResponse response;

    request.PanTilt = &pan_tilt;
    request.Zoom = &zoom;
    request.ProfileToken = profile_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.Stop(&request, response), impl_->device_proxy_.soap);
}

tuple<Result, vector<Preset>> OnvifClientPTZ::GetPresets(InfoTuple information,
                                                         string profile_token)
{
    Authenticate(information);

    _ns11__GetPresets request;
    _ns11__GetPresetsResponse response;
    request.ProfileToken = profile_token; 

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetPresets(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, vector<Preset>{});
    }

    vector<Preset> presets;
    for_each(response.Preset.begin(),
             response.Preset.end(),
             [&presets](auto el) { presets.emplace_back(ConvertToPreset(el)); });
    return make_tuple(result, presets);
}
Result OnvifClientPTZ::GoToPreset(InfoTuple information, 
                                  string profile_token,
                                  string preset_token,
                                  PTZSpeed speed)
{
    Authenticate(information);

    _ns11__GotoPreset request;
    _ns11__GotoPresetResponse response;

    ns2__Vector2D speed_vector2D;
    speed_vector2D.x = speed.pan_tilt.x;
    speed_vector2D.y = speed.pan_tilt.y;
    speed_vector2D.space = &speed.pan_tilt.space;
    ns2__Vector1D speed_vector1D;
    speed_vector1D.x = speed.zoom.x;
    speed_vector1D.space = &speed.zoom.space;
    ns2__PTZSpeed speed_vector;
    speed_vector.PanTilt = &speed_vector2D;
    speed_vector.Zoom = &speed_vector1D;

    request.ProfileToken = profile_token;
    request.PresetToken = preset_token;
    request.Speed = &speed_vector;

    return ErrorWrap::Wrap(impl_->device_proxy_.GotoPreset(&request, response), impl_->device_proxy_.soap);
}
tuple<Result, string> OnvifClientPTZ::ChangePreset(InfoTuple information,
                                                   string profile_token,
                                                   string preset_token,
                                                   string preset_name)
{
    Authenticate(information);

    _ns11__SetPreset request;
    _ns11__SetPresetResponse response;
    request.ProfileToken = profile_token;
    request.PresetToken = &preset_token;
    request.PresetName = &preset_name;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.SetPreset(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, "");
    }
    return make_tuple(result, response.PresetToken);
}

tuple<Result, string> OnvifClientPTZ::AddPreset(InfoTuple information,
                                                string profile_token,
                                                string preset_name)
{
    Authenticate(information);

    _ns11__SetPreset request;
    _ns11__SetPresetResponse response;
    request.ProfileToken = profile_token;
    request.PresetName = &preset_name;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.SetPreset(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, "");
    }
    return make_tuple(result, response.PresetToken);
}

Result OnvifClientPTZ::RemovePreset(InfoTuple information,
                                    string profile_token,
                                    string preset_token)
{
    Authenticate(information);

    _ns11__RemovePreset request;
    _ns11__RemovePresetResponse response;
    request.PresetToken = preset_token;
    request.ProfileToken = profile_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.RemovePreset(&request, response), impl_->device_proxy_.soap);
}

Result OnvifClientPTZ::GoToHome(InfoTuple information,
                                string profile_token, 
                                PTZSpeed speed)
{
    Authenticate(information);

    _ns11__GotoHomePosition request;
    _ns11__GotoHomePositionResponse response;

    ns2__Vector2D speed_vector2D;
    speed_vector2D.x = speed.pan_tilt.x;
    speed_vector2D.y = speed.pan_tilt.y;
    speed_vector2D.space = &speed.pan_tilt.space;
    ns2__Vector1D speed_vector1D;
    speed_vector1D.x = speed.zoom.x;
    speed_vector1D.space = &speed.zoom.space;
    ns2__PTZSpeed speed_vector;
    speed_vector.PanTilt = &speed_vector2D;
    speed_vector.Zoom = &speed_vector1D;

    request.ProfileToken = profile_token;
    request.Speed = &speed_vector;

    return ErrorWrap::Wrap(impl_->device_proxy_.GotoHomePosition(&request, response), impl_->device_proxy_.soap);
}
Result OnvifClientPTZ::SetHome(InfoTuple information,
                               string profile_token)
{
    Authenticate(information);

    _ns11__SetHomePosition request;
    _ns11__SetHomePositionResponse response;
    request.ProfileToken = profile_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.SetHomePosition(&request, response), impl_->device_proxy_.soap);
}

tuple<Result, PTZStatus> OnvifClientPTZ::GetStatus(InfoTuple information,
                                                   string profile_token)
{
    Authenticate(information);

    _ns11__GetStatus request;
    _ns11__GetStatusResponse response;
    request.ProfileToken = profile_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetStatus(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, PTZStatus{});
    }

    return make_tuple(result, PTZStatus
                              {
                                  {
                                      {
                                          S(S(S(response.PTZStatus)->Position)->PanTilt)->x,
                                          S(S(S(response.PTZStatus)->Position)->PanTilt)->y,
                                          *S(S(S(S(response.PTZStatus)->Position)->PanTilt)->space)
                                      },
                                      {
                                          S(S(S(response.PTZStatus)->Position)->Zoom)->x,
                                          *S(S(S(S(response.PTZStatus)->Position)->Zoom)->space)
                                      }
                                  },
                                  {
                                      static_cast<MoveStatus>(*S(S(S(response.PTZStatus)->MoveStatus)->PanTilt)),
                                      static_cast<MoveStatus>(*S(S(S(response.PTZStatus)->MoveStatus)->Zoom))
                                  },
                                  *S(S(response.PTZStatus)->Error),
                                   static_cast<uint64_t>(S(response.PTZStatus)->UtcTime)
                              });
}

tuple<Result, PTZCapabilitiesInformation> OnvifClientPTZ::GetServiceCapabilities(InfoTuple information)
{
    Authenticate(information);

	_ns11__GetServiceCapabilities request;
    _ns11__GetServiceCapabilitiesResponse response;
	
    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetServiceCapabilities(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, PTZCapabilitiesInformation{});
    }

    return make_tuple(result, PTZCapabilitiesInformation
                              {
                                  *S(S(response.Capabilities)->EFlip),
                                  *S(S(response.Capabilities)->Reverse),
                                  *S(S(response.Capabilities)->GetCompatibleConfigurations),
                                  *S(S(response.Capabilities)->MoveStatus),
                                  *S(S(response.Capabilities)->StatusPosition)
                              });
}


tuple<Result, PTZNode> OnvifClientPTZ::GetNode(InfoTuple information,
                                               string node_token)
{
    Authenticate(information);

	_ns11__GetNode request;
    _ns11__GetNodeResponse response;
    request.NodeToken = node_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetNode(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, PTZNode{});
    }

    return make_tuple(result, ConvertToPTZNode(response.PTZNode));
}

tuple<Result, vector<PTZNode>> OnvifClientPTZ::GetNodes(InfoTuple information)
{
    Authenticate(information);

	_ns11__GetNodes request;
    _ns11__GetNodesResponse response;


    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetNodes(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, vector<PTZNode>{});
    }

    vector<PTZNode> nodes;
    for_each(response.PTZNode.begin(),
             response.PTZNode.end(),
             [&nodes](auto el) { nodes.emplace_back(ConvertToPTZNode(el)); });
    return make_tuple(result, nodes);
}

void OnvifClientPTZ::Authenticate(InfoTuple& information)
{
    impl_->device_proxy_.soap_endpoint = get<2>(information).c_str();
    soap_wsse_add_Security(impl_->device_proxy_.soap);
    soap_wsse_add_UsernameTokenDigest(impl_->device_proxy_.soap, "Id", get<0>(information).c_str(), get<1>(information).c_str());

    impl_->device_proxy_.soap->recv_timeout = 5;
    impl_->device_proxy_.soap->send_timeout = 5;
    impl_->device_proxy_.soap->connect_timeout = 5;
}
