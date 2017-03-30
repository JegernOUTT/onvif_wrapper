#pragma once

#include <string>
#include <memory>

#include "OnvifClientDevice.h"
#include "OnvifClientImaging.h"
#include "OnvifClientMedia.h"
#include "OnvifClientPtz.h"
#include "ErrorWrap.hpp"

namespace onvifwrapper
{
	using std::string;
    using std::get;
    using std::tie;

	using login = string;
	using password = string;
	using url = string;

	class Onvif
	{
	public:
		explicit Onvif(login user_name, password user_password, url onvif_url);
        Onvif(Onvif&) = delete;
        Onvif& operator=(Onvif&) = delete;
		~Onvif();

		OnvifClientDevice& OnvifDevice();
		OnvifClientImaging& OnvifImaging();
		OnvifClientMedia& OnvifMedia();
		OnvifClientPTZ& OnvifPtz();

		void InitAllInformation();
	    bool IsConnected() const;
	    bool IsPtz() const;

        Result InitCapabilities();
        Result InitProfiles();
        Result InitPtzConfigurations();
        Result InitPtzMoveSpaces();
        Result InitPtzNode();
        Result InitPtzPresets();

        bool CapabilitiesRecieved() const;
        bool ProfilesRecieved() const;
        bool PtzConfigurationsRecieved() const;
        bool PtzMoveSpacesRecieved() const;
        bool PtzNodeRecieved() const;
        bool PtzPresetsRecieved() const;

        const pair<Result, OnvifCapabilities>& SavedCapabilities() const;
        const pair<Result, vector<Profile>>& SavedProfiles() const;
        const pair<Result, PTZConfiguration>&  SavedPtzConfigurations() const;
        const pair<Result, PTZConfigurationOptions>& SavedPtzMoveSpaces() const;
        const pair<Result, PTZNode>& SavedPtzNode() const;
        const pair<Result, vector<Preset>>& SavedPtzPresets() const;

	public:
        // Onvif device methods
        tuple<Result, OnvifCapabilities> GetCapabilities();
        tuple<Result, string> SystemReboot();
        tuple<Result, DeviceInformation> GetDeviceInformation();

        // Onvif media methods
        tuple<Result, Profile> GetMediaProfile(string profile_token);
        tuple<Result, vector<Profile>> GetMediaProfiles();
        tuple<Result, vector<VideoSource>> GetVideoSources();
        tuple<Result, VideoSourceConfiguration> GetVideoSourceConfiguration(string configuration_token);
        tuple<Result, vector<VideoSourceConfiguration>> GetVideoSourceConfigurations();
        tuple<Result, VideoSourceConfigurationOptions> GetVideoSourceConfigurationOptions(string configuration_token,
                                                                                          string profile_token);
        tuple<Result, MediaUri> GetStreamUri(StreamType stream_type,
                                             TransportProtocol transport_protocol);
        tuple<Result, MediaUri> GetSnapshotUri();
        Result StartMulticastStreaming();
        Result StopMulticastStreaming();
        tuple<Result, Capabilities> GetServiceCapabilities();

        // Onvif ptz methods
        tuple<Result, PTZConfiguration> GetConfiguration(string ptz_configuration_token);
        tuple<Result, vector<PTZConfiguration>> GetConfigurations();
        tuple<Result, PTZConfigurationOptions> GetConfigurationOptions(string ptz_configuration_token);
        Result RelativeMove(PTZVector translation,
                            PTZSpeed speed);
        Result ContinuousMove(PTZSpeed speed,
                              string timeout);
        Result AbsoluteMove(PTZSpeed speed,
                            PTZVector position);
        Result Stop(bool pan_tilt,
                    bool zoom);
        tuple<Result, vector<Preset>> GetPresets();
        Result GoToPreset(string preset_token,
                          PTZSpeed speed);
        tuple<Result, string> ChangePreset(string preset_token,
                                           string new_preset_name);
        tuple<Result, string> AddPreset(string new_preset_name);
        Result RemovePreset(string preset_token);
        Result GoToHome(PTZSpeed speed);
        Result SetHome();
        tuple<Result, PTZStatus> GetStatus();
        tuple<Result, PTZCapabilitiesInformation> GetPtzServiceCapabilities();
        tuple<Result, PTZNode> GetNode(string node_token);
        tuple<Result, vector<PTZNode>> GetNodes();

	private:
        bool is_connected_;

		string user_name_;
		string user_password_;
		string onvif_url_;

        tuple<string, string, string> onvif_device_information_;
        bool onvif_device_available_;
		OnvifClientDevice onvif_device_;

        tuple<string, string, string> onvif_imaging_information_;
        bool onvif_imaging_available_;
		OnvifClientImaging onvif_imaging_;

        tuple<string, string, string> onvif_media_information_;
        bool onvif_media_available_;
		OnvifClientMedia onvif_media_;
		
        tuple<string, string, string> onvif_ptz_information_;
        bool onvif_ptz_available_;
	    OnvifClientPTZ onvif_ptz_;

	private:
        pair<Result, OnvifCapabilities> capabilities_;
        pair<Result, vector<Profile>> profiles_;
        pair<Result, PTZConfiguration> ptz_configuration_;
        pair<Result, PTZConfigurationOptions> ptz_move_spaces_;
        pair<Result, PTZNode> ptz_node_;
        pair<Result, vector<Preset>> ptz_presets_;
	};
}
