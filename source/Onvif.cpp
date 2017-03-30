#include "Onvif.hpp"

namespace  onvifwrapper
{
	Onvif::Onvif(string user_name, string user_password, string onvif_url) : 
        is_connected_(false),
	    user_name_(user_name),
	    user_password_(user_password),
	    onvif_url_(onvif_url),
        onvif_device_information_(make_tuple(user_name_, user_password_, onvif_url_)),
        onvif_imaging_information_(make_tuple(user_name_, user_password_, onvif_url_)),
        onvif_media_information_(make_tuple(user_name_, user_password_, onvif_url_)),
        onvif_ptz_information_(make_tuple(user_name_, user_password_, onvif_url_))
    {
        InitAllInformation();
    }

	Onvif::~Onvif()
	{
	}

	OnvifClientDevice& Onvif::OnvifDevice()
	{
		return onvif_device_;
	}

	OnvifClientImaging& Onvif::OnvifImaging()
	{
		return onvif_imaging_;
	}

	OnvifClientMedia& Onvif::OnvifMedia()
	{
		return onvif_media_;
	}

	OnvifClientPTZ& Onvif::OnvifPtz()
	{
		return onvif_ptz_;
	}

    void Onvif::InitAllInformation()
    {
        InitCapabilities();
        InitProfiles();
        InitPtzConfigurations();
        InitPtzMoveSpaces();
        InitPtzNode();
        InitPtzPresets();
    }

    bool Onvif::IsConnected() const
    {
        return !capabilities_.first.is_error;
    }

    bool Onvif::IsPtz() const
    {
        return onvif_ptz_.IsPtz();
    }

    Result Onvif::InitCapabilities()
	{
        tie(capabilities_.first, capabilities_.second) = onvif_device_.GetCapabilities(onvif_device_information_);
        if (!capabilities_.first.is_error)
        {
            if (!capabilities_.second.device.address.empty())
            {
                onvif_device_available_ = true;
                get<2>(onvif_device_information_) = capabilities_.second.device.address;
            }
            if (!capabilities_.second.imaging.address.empty())
            {
                onvif_imaging_available_ = true;
                get<2>(onvif_imaging_information_) = capabilities_.second.device.address;
            }
            if (!capabilities_.second.media.address.empty())
            {
                onvif_media_available_ = true;
                get<2>(onvif_media_information_) = capabilities_.second.device.address;
            }
            if (!capabilities_.second.ptz.address.empty())
            {
                onvif_ptz_available_ = true;
                get<2>(onvif_ptz_information_) = capabilities_.second.device.address;
            }
        }

        return capabilities_.first;
	}

    Result Onvif::InitProfiles()
	{
        if (onvif_media_available_)
            tie(profiles_.first, profiles_.second) = onvif_media_.GetMediaProfiles(onvif_media_information_);
        return profiles_.first;
	}

    Result Onvif::InitPtzConfigurations()
	{
        if (onvif_ptz_available_)
        {
            vector<PTZConfiguration> configurations;
            tie(ptz_configuration_.first, configurations) = onvif_ptz_.GetConfigurations(onvif_ptz_information_);

            if (!ptz_configuration_.first.is_error && configurations.size() > 0)
                ptz_configuration_.second = configurations.front();
            else
                ptz_configuration_.first.is_error = true;
        }
        return ptz_configuration_.first;
	}
    Result Onvif::InitPtzMoveSpaces()
	{
        if (onvif_ptz_available_ && !ptz_configuration_.second.node_token.empty())
            tie(ptz_move_spaces_.first, ptz_move_spaces_.second) = onvif_ptz_.GetConfigurationOptions(onvif_ptz_information_,
                                                                                                      ptz_configuration_.second.node_token);
        return ptz_move_spaces_.first;
	}

    Result Onvif::InitPtzNode()
	{
        if (onvif_ptz_available_ && !ptz_configuration_.second.node_token.empty())
            tie(ptz_node_.first, ptz_node_.second) = onvif_ptz_.GetNode(onvif_ptz_information_,
                                                                        ptz_configuration_.second.node_token);
        return ptz_node_.first;
	}

    Result Onvif::InitPtzPresets()
	{
        if (onvif_ptz_available_ && !profiles_.second.size() > 0)
            tie(ptz_presets_.first, ptz_presets_.second) = onvif_ptz_.GetPresets(onvif_ptz_information_,
                                                                                 profiles_.second.front().token);
        return ptz_presets_.first;
	}

    bool Onvif::CapabilitiesRecieved() const
    {
        return !capabilities_.first.is_error;
    }

    bool Onvif::ProfilesRecieved() const
    {
        return !profiles_.first.is_error;
    }

    bool Onvif::PtzConfigurationsRecieved() const
    {
        return !ptz_configuration_.first.is_error;
    }

    bool Onvif::PtzMoveSpacesRecieved() const
    {
        return !ptz_move_spaces_.first.is_error;
    }

    bool Onvif::PtzNodeRecieved() const
    {
        return !ptz_node_.first.is_error;
    }

    bool Onvif::PtzPresetsRecieved() const
    {
        return !ptz_presets_.first.is_error;
    }

    const pair<Result, OnvifCapabilities>& Onvif::SavedCapabilities() const
	{
	    return capabilities_;
	}

    const pair<Result, vector<Profile>>& Onvif::SavedProfiles() const
	{
        return profiles_;
	}

    const pair<Result, PTZConfiguration>& Onvif::SavedPtzConfigurations() const
	{
        return ptz_configuration_;
	}

    const pair<Result, PTZConfigurationOptions>& Onvif::SavedPtzMoveSpaces() const
	{
	    return ptz_move_spaces_;
	}

    const pair<Result, PTZNode>& Onvif::SavedPtzNode() const
	{
        return ptz_node_;
	}

    const pair<Result, vector<Preset>>& Onvif::SavedPtzPresets() const
	{
	    return ptz_presets_;
	}

    tuple<Result, OnvifCapabilities> Onvif::GetCapabilities()
	{
        if (onvif_device_available_)
        {
            tie(capabilities_.first, capabilities_.second) = onvif_device_.GetCapabilities(onvif_device_information_);
            return make_tuple(capabilities_.first, capabilities_.second);
        }
        return make_tuple(Result{true, -1, "", "This action is not available for this device"}, OnvifCapabilities{});
	}

    tuple<Result, string> Onvif::SystemReboot()
	{
        if (onvif_device_available_)
            return onvif_device_.SystemReboot(onvif_device_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, "");
	}

    tuple<Result, DeviceInformation> Onvif::GetDeviceInformation()
	{
        if (onvif_device_available_)
            return onvif_device_.GetDeviceInformation(onvif_device_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, DeviceInformation{});
	}

    tuple<Result, Profile> Onvif::GetMediaProfile(string profile_token)
	{
        if (onvif_media_available_)
            return onvif_media_.GetMediaProfile(onvif_media_information_, profile_token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, Profile{});
	}

    tuple<Result, vector<Profile>> Onvif::GetMediaProfiles()
	{
        if (onvif_media_available_)
        {
            tie(profiles_.first, profiles_.second) = onvif_media_.GetMediaProfiles(onvif_media_information_);
            return make_tuple(profiles_.first, profiles_.second);
        }
	    return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<Profile>{});
	}

    tuple<Result, vector<VideoSource>> Onvif::GetVideoSources()
    {
        if (onvif_media_available_)
            return onvif_media_.GetVideoSources(onvif_device_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<VideoSource>{});
    }

    tuple<Result, VideoSourceConfiguration> Onvif::GetVideoSourceConfiguration(string configuration_token)
    {
        if (onvif_media_available_)
            return onvif_media_.GetVideoSourceConfiguration(onvif_device_information_, configuration_token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, VideoSourceConfiguration{});
    }

    tuple<Result, vector<VideoSourceConfiguration>> Onvif::GetVideoSourceConfigurations()
    {
        if (onvif_media_available_)
            return onvif_media_.GetVideoSourceConfigurations(onvif_device_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<VideoSourceConfiguration>{});
    }

    tuple<Result, VideoSourceConfigurationOptions> Onvif::GetVideoSourceConfigurationOptions(string configuration_token,
                                                                                             string profile_token)
    {
        if (onvif_media_available_)
            return onvif_media_.GetVideoSourceConfigurationOptions(onvif_device_information_, configuration_token, profile_token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, VideoSourceConfigurationOptions{});
    }

    tuple<Result, MediaUri> Onvif::GetStreamUri(StreamType stream_type,
                                                TransportProtocol transport_protocol)
    {
        if (onvif_media_available_)
            return onvif_media_.GetStreamUri(onvif_device_information_, stream_type, transport_protocol, profiles_.second.front().token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, MediaUri{});
    }

    tuple<Result, MediaUri> Onvif::GetSnapshotUri()
    {
        if (onvif_media_available_)
            return onvif_media_.GetSnapshotUri(onvif_device_information_, profiles_.second.front().token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, MediaUri{});
    }

    Result Onvif::StartMulticastStreaming()
    {
        if (onvif_media_available_)
            return onvif_media_.StartMulticastStreaming(onvif_device_information_, profiles_.second.front().token);
        return { true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::StopMulticastStreaming()
    {
        if (onvif_media_available_)
            return onvif_media_.StopMulticastStreaming(onvif_device_information_, profiles_.second.front().token);
        return { true, -1, "", "This action is not available for this device" };
    }

    tuple<Result, Capabilities> Onvif::GetServiceCapabilities()
    {
        if (onvif_media_available_)
            return onvif_media_.GetServiceCapabilities(onvif_device_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, Capabilities{});
    }

    tuple<Result, PTZConfiguration> Onvif::GetConfiguration(string ptz_configuration_token)
	{
        if (onvif_ptz_available_)
            return onvif_ptz_.GetConfiguration(onvif_ptz_information_, ptz_configuration_token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, PTZConfiguration{});
	}

    tuple<Result, vector<PTZConfiguration>> Onvif::GetConfigurations()
    {
        if (onvif_ptz_available_)
        {
            vector<PTZConfiguration> configurations;
            tie(ptz_configuration_.first, configurations) = onvif_ptz_.GetConfigurations(onvif_ptz_information_);

            if (!ptz_configuration_.first.is_error && configurations.size() > 0)
                ptz_configuration_.second = configurations.front();
            else
                ptz_configuration_.first.is_error = true;
            return make_tuple(ptz_configuration_.first, configurations);
        }
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<PTZConfiguration>{});
    }

    tuple<Result, PTZConfigurationOptions> Onvif::GetConfigurationOptions(string ptz_configuration_token)
    {
        if (onvif_ptz_available_)
        {
            tie(ptz_move_spaces_.first, ptz_move_spaces_.second) = onvif_ptz_.GetConfigurationOptions(onvif_device_information_, 
                                                                                                      ptz_configuration_token);
            return make_tuple(ptz_move_spaces_.first, ptz_move_spaces_.second);
        }
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, PTZConfigurationOptions{});
    }

    Result Onvif::RelativeMove(PTZVector translation,
                               PTZSpeed speed)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.RelativeMove(onvif_ptz_information_, translation, speed, profiles_.second.front().token);
        return Result{ true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::ContinuousMove(PTZSpeed speed,
                                 string timeout)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.ContinuousMove(onvif_ptz_information_, speed, timeout, profiles_.second.front().token);
        return { true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::AbsoluteMove(PTZSpeed speed,
                               PTZVector position)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.AbsoluteMove(onvif_ptz_information_, speed, position, profiles_.second.front().token);
        return Result{ true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::Stop(bool pan_tilt,
                       bool zoom)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.Stop(onvif_ptz_information_, pan_tilt, zoom, profiles_.second.front().token);
        return { true, -1, "", "This action is not available for this device" };
    }

    tuple<Result, vector<Preset>> Onvif::GetPresets()
    {
        if (onvif_ptz_available_)
        {
            tie(ptz_presets_.first, ptz_presets_.second) = onvif_ptz_.GetPresets(onvif_device_information_,
                                                                                 profiles_.second.front().token);
            return make_tuple(ptz_presets_.first, ptz_presets_.second);
        }
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<Preset>{});
    }

    Result Onvif::GoToPreset(string preset_token,
                             PTZSpeed speed)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.GoToPreset(onvif_ptz_information_, profiles_.second.front().token, preset_token, speed);
        return { true, -1, "", "This action is not available for this device" };
    }

    tuple<Result, string> Onvif::ChangePreset(string preset_token,
                                              string new_preset_name)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.ChangePreset(onvif_ptz_information_, profiles_.second.front().token, preset_token, new_preset_name);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, "");
    }

    tuple<Result, string> Onvif::AddPreset(string new_preset_name)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.AddPreset(onvif_ptz_information_, profiles_.second.front().token, new_preset_name);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, "");
    }

    Result Onvif::RemovePreset(string preset_token)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.RemovePreset(onvif_ptz_information_, profiles_.second.front().token, preset_token);
        return { true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::GoToHome(PTZSpeed speed)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.GoToHome(onvif_ptz_information_, profiles_.second.front().token, speed);
        return { true, -1, "", "This action is not available for this device" };
    }

    Result Onvif::SetHome()
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.SetHome(onvif_ptz_information_, profiles_.second.front().token);
        return { true, -1, "", "This action is not available for this device" };
    }

    tuple<Result, PTZStatus> Onvif::GetStatus()
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.GetStatus(onvif_ptz_information_, profiles_.second.front().token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, PTZStatus{});
    }

    tuple<Result, PTZCapabilitiesInformation> Onvif::GetPtzServiceCapabilities()
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.GetServiceCapabilities(onvif_ptz_information_);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, PTZCapabilitiesInformation{});
    }

    tuple<Result, PTZNode> Onvif::GetNode(string node_token)
    {
        if (onvif_ptz_available_)
            return onvif_ptz_.GetNode(onvif_ptz_information_, node_token);
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, PTZNode{});
    }

    tuple<Result, vector<PTZNode>> Onvif::GetNodes()
    {
        if (onvif_ptz_available_)
        {
            vector<PTZNode> nodes;
            tie(ptz_node_.first, nodes) = onvif_ptz_.GetNodes(onvif_ptz_information_);

            if (!ptz_node_.first.is_error && nodes.size() > 0)
                ptz_node_.second = nodes.front();
            else
                ptz_node_.first.is_error = true;
            return make_tuple(ptz_node_.first, nodes);
        }
        return make_tuple(Result{ true, -1, "", "This action is not available for this device" }, vector<PTZNode>{});
    }
}
