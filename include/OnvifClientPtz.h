#pragma once

#include <vector>
#include <tuple>
#include <memory>
#include <algorithm>

#include "Utility.hpp"
#include "ErrorWrap.hpp"
#include "OnvifPod.hpp"

namespace onvifwrapper
{
    using std::tuple;
    using std::string;
    using std::unique_ptr;
    using std::vector;

    using std::get;
    using std::make_unique;
    using std::make_tuple;
    using std::for_each;

    struct OnvifClientPtzImpl;

    class OnvifClientPTZ
    {
        using InfoTuple = tuple<string, string, string>;

    public:
        OnvifClientPTZ();
        OnvifClientPTZ(OnvifClientPTZ&) = delete;
        OnvifClientPTZ& operator=(OnvifClientPTZ&) = delete;
        ~OnvifClientPTZ();

        bool IsPtz() const;
        tuple<Result, PTZConfiguration> GetConfiguration(InfoTuple information,
                                                         string ptz_configuration_token);
        tuple<Result, vector<PTZConfiguration>> GetConfigurations(InfoTuple information);
        tuple<Result, PTZConfigurationOptions> GetConfigurationOptions(InfoTuple information,
                                                                       string ptz_configuration_token);
        Result RelativeMove(InfoTuple information,
                            PTZVector translation,
                            PTZSpeed speed,
                            string profile_token);
        Result ContinuousMove(InfoTuple information,
                              PTZSpeed speed,
                              string timeout,
                              string profile_token);
        Result AbsoluteMove(InfoTuple information,
                            PTZSpeed speed,
                            PTZVector position,
                            string profile_token);
        Result Stop(InfoTuple information,
                    bool pan_tilt,
                    bool zoom,
                    string profile_token);

        tuple<Result, vector<Preset>> GetPresets(InfoTuple information,
                                                 string profile_token);
        Result GoToPreset(InfoTuple information,
                          string profile_token,
                          string preset_token,
                          PTZSpeed speed);
        tuple<Result, string> ChangePreset(InfoTuple information,
                                           string profile_token,
                                           string preset_token,
                                           string preset_name);
        tuple<Result, string> AddPreset(InfoTuple information,
                                        string profile_token,
                                        string preset_name);
	    Result RemovePreset(InfoTuple information,
                            string profile_token,
                            string preset_token);

        Result GoToHome(InfoTuple information,
                        string profile_token,
                        PTZSpeed speed);
        Result SetHome(InfoTuple information,
                       string profile_token);

        tuple<Result, PTZStatus> GetStatus(InfoTuple information,
                                           string profile_token);

        tuple<Result, PTZCapabilitiesInformation> GetServiceCapabilities(InfoTuple information);

        tuple<Result, PTZNode> GetNode(InfoTuple information,
                                       string node_token);
        tuple<Result, vector<PTZNode>> GetNodes(InfoTuple information);


    private:
        unique_ptr<OnvifClientPtzImpl> impl_;
        bool is_ptz_;

        void FillIsPtz(tuple<Result, vector<PTZConfiguration>> configurations);
        void Authenticate(InfoTuple& information);

        // Converters to POD
        template<typename SoapPTZConfiguration>
        static PTZConfiguration ConvertToPtzConfig(SoapPTZConfiguration* config);

        template<typename SoapSpace1DDescription>
        static Space1DDescriptionRange To1dDescription(SoapSpace1DDescription* description);

        template<typename SoapSpace2DDescription>
        static Space2DDescriptionRange To2dDescription(SoapSpace2DDescription* description);

        template<typename SoapPTZConfigurationOptions>
        static PTZConfigurationOptions ConvertToPtzConfigOptions(SoapPTZConfigurationOptions* config);

        template<typename SoapPreset>
        static Preset ConvertToPreset(SoapPreset* preset);

        template<typename SoapPTZNode>
        static PTZNode ConvertToPTZNode(SoapPTZNode* node);
    };

    template<typename SoapPTZConfiguration>
    PTZConfiguration OnvifClientPTZ::ConvertToPtzConfig(SoapPTZConfiguration* config)
    {
        return PTZConfiguration
        {
            S(config)->NodeToken,
            *S(S(config)->DefaultAbsolutePantTiltPositionSpace),
            *S(S(config)->DefaultAbsoluteZoomPositionSpace),
            *S(S(config)->DefaultRelativePanTiltTranslationSpace),
            *S(S(config)->DefaultRelativeZoomTranslationSpace),
            *S(S(config)->DefaultContinuousPanTiltVelocitySpace),
            *S(S(config)->DefaultContinuousZoomVelocitySpace),
            {
                {
                    S(S(S(config)->DefaultPTZSpeed)->PanTilt)->x,
                    S(S(S(config)->DefaultPTZSpeed)->PanTilt)->y,
                    *S(S(S(S(config)->DefaultPTZSpeed)->PanTilt)->space)
                },
                {
                    S(S(S(config)->DefaultPTZSpeed)->Zoom)->x,
                    *S(S(S(S(config)->DefaultPTZSpeed)->Zoom)->space)
                }
            },
            *S(S(config)->DefaultPTZTimeout),
            {
                S(S(S(config)->PanTiltLimits)->Range)->URI,
                {
                    S(S(S(S(config)->PanTiltLimits)->Range)->XRange)->Min,
                    S(S(S(S(config)->PanTiltLimits)->Range)->XRange)->Max
                },
                {
                    S(S(S(S(config)->PanTiltLimits)->Range)->YRange)->Min,
                    S(S(S(S(config)->PanTiltLimits)->Range)->YRange)->Max
                }
            },
            {
                S(S(S(config)->ZoomLimits)->Range)->URI,
                {
                    S(S(S(S(config)->ZoomLimits)->Range)->XRange)->Min,
                    S(S(S(S(config)->ZoomLimits)->Range)->XRange)->Max
                }
            }
        };
    }

    template<typename SoapSpace1DDescription>
    Space1DDescriptionRange OnvifClientPTZ::To1dDescription(SoapSpace1DDescription* description)
    {
        return Space1DDescriptionRange
        {
            S(description)->URI,
            {
                S(S(description)->XRange)->Min,
                S(S(description)->XRange)->Max
            }
        };
    }

    template<typename SoapSpace2DDescription>
    Space2DDescriptionRange OnvifClientPTZ::To2dDescription(SoapSpace2DDescription* description)
    {
        return Space2DDescriptionRange
        {
            S(description)->URI,
            {
                S(S(description)->XRange)->Min,
                S(S(description)->XRange)->Max
            },
            {
                S(S(description)->YRange)->Min,
                S(S(description)->YRange)->Max
            }
        };
    }

    template<typename SoapPTZConfigurationOptions>
    PTZConfigurationOptions OnvifClientPTZ::ConvertToPtzConfigOptions(SoapPTZConfigurationOptions* config)
    {
        vector<Space2DDescriptionRange> absolute_pan_tilt_position_space;
        vector<Space1DDescriptionRange> absolute_zoom_position_space;
        vector<Space2DDescriptionRange> relative_pan_tilt_translation_space;
        vector<Space1DDescriptionRange> relative_zoom_translation_space;
        vector<Space2DDescriptionRange> continuous_pan_tilt_velocity_space;
        vector<Space1DDescriptionRange> continuous_zoom_velocity_space;
        vector<Space1DDescriptionRange> pan_tilt_speed_space;
        vector<Space1DDescriptionRange> zoom_speed_space;

        for_each(S(S(config)->Spaces)->AbsolutePanTiltPositionSpace.begin(),
                 S(S(config)->Spaces)->AbsolutePanTiltPositionSpace.end(),
                 [&](auto ptr) { if (ptr) absolute_pan_tilt_position_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->AbsoluteZoomPositionSpace.begin(),
                 S(S(config)->Spaces)->AbsoluteZoomPositionSpace.end(),
                 [&](auto ptr) { if (ptr) absolute_zoom_position_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->RelativePanTiltTranslationSpace.begin(),
                 S(S(config)->Spaces)->RelativePanTiltTranslationSpace.end(),
                 [&](auto ptr) { if (ptr) relative_pan_tilt_translation_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->RelativeZoomTranslationSpace.begin(),
                 S(S(config)->Spaces)->RelativeZoomTranslationSpace.end(),
                 [&](auto ptr) { if (ptr) relative_zoom_translation_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->ContinuousPanTiltVelocitySpace.begin(),
                 S(S(config)->Spaces)->ContinuousPanTiltVelocitySpace.end(),
                 [&](auto ptr) { if (ptr) continuous_pan_tilt_velocity_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->ContinuousZoomVelocitySpace.begin(),
                 S(S(config)->Spaces)->ContinuousZoomVelocitySpace.end(),
                 [&](auto ptr) { if (ptr) continuous_zoom_velocity_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->PanTiltSpeedSpace.begin(),
                 S(S(config)->Spaces)->PanTiltSpeedSpace.end(),
                 [&](auto ptr) { if (ptr) pan_tilt_speed_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(config)->Spaces)->ZoomSpeedSpace.begin(),
                 S(S(config)->Spaces)->ZoomSpeedSpace.end(),
                 [&](auto ptr) { if (ptr) zoom_speed_space.emplace_back(To1dDescription(ptr)); });

                 
        return PTZConfigurationOptions
        {
            {
                absolute_pan_tilt_position_space,
                absolute_zoom_position_space,
                relative_pan_tilt_translation_space,
                relative_zoom_translation_space,
                continuous_pan_tilt_velocity_space,
                continuous_zoom_velocity_space,
                pan_tilt_speed_space,
                zoom_speed_space
            },
            {
                // S(S(config)->PTZTimeout)->Min,
                // S(S(config)->PTZTimeout)->Max
            }
        };
    }

    template<typename SoapPreset>
    Preset OnvifClientPTZ::ConvertToPreset(SoapPreset* preset)
    {
        return Preset
        {
            *S(S(preset)->Name),
            *S(S(preset)->token),
            {
                {
                    S(S(S(preset)->PTZPosition)->PanTilt)->x,
                    S(S(S(preset)->PTZPosition)->PanTilt)->y,
                    *S(S(S(S(preset)->PTZPosition)->PanTilt)->space),
                },
                {
                    S(S(S(preset)->PTZPosition)->Zoom)->x,
                    *S(S(S(S(preset)->PTZPosition)->PanTilt)->space),
                }
            }
        };
    }

    template<typename SoapPTZNode>
    PTZNode OnvifClientPTZ::ConvertToPTZNode(SoapPTZNode* node)
    {
        vector<Space2DDescriptionRange> absolute_pan_tilt_position_space;
        vector<Space1DDescriptionRange> absolute_zoom_position_space;
        vector<Space2DDescriptionRange> relative_pan_tilt_translation_space;
        vector<Space1DDescriptionRange> relative_zoom_translation_space;
        vector<Space2DDescriptionRange> continuous_pan_tilt_velocity_space;
        vector<Space1DDescriptionRange> continuous_zoom_velocity_space;
        vector<Space1DDescriptionRange> pan_tilt_speed_space;
        vector<Space1DDescriptionRange> zoom_speed_space;

        for_each(S(S(node)->SupportedPTZSpaces)->AbsolutePanTiltPositionSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->AbsolutePanTiltPositionSpace.end(),
                 [&](auto ptr) { if (ptr) absolute_pan_tilt_position_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->AbsoluteZoomPositionSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->AbsoluteZoomPositionSpace.end(),
                 [&](auto ptr) { if (ptr) absolute_zoom_position_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->RelativePanTiltTranslationSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->RelativePanTiltTranslationSpace.end(),
                 [&](auto ptr) { if (ptr) relative_pan_tilt_translation_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->RelativeZoomTranslationSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->RelativeZoomTranslationSpace.end(),
                 [&](auto ptr) { if (ptr) relative_zoom_translation_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->ContinuousPanTiltVelocitySpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->ContinuousPanTiltVelocitySpace.end(),
                 [&](auto ptr) { if (ptr) continuous_pan_tilt_velocity_space.emplace_back(To2dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->ContinuousZoomVelocitySpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->ContinuousZoomVelocitySpace.end(),
                 [&](auto ptr) { if (ptr) continuous_zoom_velocity_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->PanTiltSpeedSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->PanTiltSpeedSpace.end(),
                 [&](auto ptr) { if (ptr) pan_tilt_speed_space.emplace_back(To1dDescription(ptr)); });

        for_each(S(S(node)->SupportedPTZSpaces)->ZoomSpeedSpace.begin(),
                 S(S(node)->SupportedPTZSpaces)->ZoomSpeedSpace.end(),
                 [&](auto ptr) { if (ptr) zoom_speed_space.emplace_back(To1dDescription(ptr)); });

        return PTZNode
        {
            *S(S(node)->Name),
            {
                absolute_pan_tilt_position_space,
                absolute_zoom_position_space,
                relative_pan_tilt_translation_space,
                relative_zoom_translation_space,
                continuous_pan_tilt_velocity_space,
                continuous_zoom_velocity_space,
                pan_tilt_speed_space,
                zoom_speed_space
            },
            S(node)->MaximumNumberOfPresets,
            S(node)->HomeSupported,
            S(node)->AuxiliaryCommands,
            *S(S(node)->FixedHomePosition),
        };
    }
}
