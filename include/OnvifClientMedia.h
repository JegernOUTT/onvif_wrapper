#pragma once

#include <vector>
#include <algorithm>
#include <tuple>
#include <memory>

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

    struct OnvifClientMediaImpl;

    class OnvifClientMedia
    {
        using InfoTuple = tuple<string, string, string>;

    public:
        OnvifClientMedia();
        OnvifClientMedia(OnvifClientMedia&) = delete;
        OnvifClientMedia& operator=(OnvifClientMedia&) = delete;
        ~OnvifClientMedia();

        tuple<Result, Profile> GetMediaProfile(InfoTuple information,
                                               string profile_token);
        tuple<Result, vector<Profile>> GetMediaProfiles(InfoTuple information);

        tuple<Result, vector<VideoSource>> GetVideoSources(InfoTuple information);

        tuple<Result, VideoSourceConfiguration> GetVideoSourceConfiguration(InfoTuple information,
                                                                            string configuration_token);
        tuple<Result, vector<VideoSourceConfiguration>> GetVideoSourceConfigurations(InfoTuple information);
        tuple<Result, VideoSourceConfigurationOptions> GetVideoSourceConfigurationOptions(InfoTuple information,
                                                                                          string configuration_token,
                                                                                          string profile_token);

        tuple<Result, MediaUri> GetStreamUri(InfoTuple information,
                                             StreamType stream_type,
                                             TransportProtocol transport_protocol,
                                             string profile_token);
        tuple<Result, MediaUri> GetSnapshotUri(InfoTuple information,
                                               string profile_token);
                           
        Result StartMulticastStreaming(InfoTuple information,
                                       string profile_token);
        Result StopMulticastStreaming(InfoTuple information,
                                      string profile_token);

        tuple<Result, Capabilities> GetServiceCapabilities(InfoTuple information);

    private:
	    unique_ptr<OnvifClientMediaImpl> impl_;
        void Authenticate(InfoTuple& information);

        // Converters to POD
        template<typename SoapProfile>
        static Profile ConvertToProfile(SoapProfile* profile);

        template<typename SoapVideoSource>
        static VideoSource ConvertToVideoSource(SoapVideoSource* source);

        template<typename SoapVideoSourceConfigOptions>
        static VideoSourceConfigurationOptions ConvertToVideoConfigOptions(SoapVideoSourceConfigOptions* options);

        template<typename SoapVideoSourceConfig>
        static VideoSourceConfiguration ConvertToVideoSourceConfig(SoapVideoSourceConfig* config);
    };

    template<typename SoapProfile>
    Profile OnvifClientMedia::ConvertToProfile(SoapProfile* profile)
    {
        return Profile
        {
            S(profile)->Name,
            S(profile)->token,
            *S(S(profile)->fixed),
            {
                S(S(profile)->VideoSourceConfiguration)->SourceToken,
                {
                    S(S(S(profile)->VideoSourceConfiguration)->Bounds)->x,
                    S(S(S(profile)->VideoSourceConfiguration)->Bounds)->y,
                    S(S(S(profile)->VideoSourceConfiguration)->Bounds)->width,
                    S(S(S(profile)->VideoSourceConfiguration)->Bounds)->height,
                }
            },
            {
                S(S(profile)->AudioSourceConfiguration)->SourceToken
            },
            {
                static_cast<VideoEncoding>(S(S(profile)->VideoEncoderConfiguration)->Encoding),
                {
                    S(S(S(profile)->VideoEncoderConfiguration)->Resolution)->Width,
                    S(S(S(profile)->VideoEncoderConfiguration)->Resolution)->Height
                },
                S(S(profile)->VideoEncoderConfiguration)->Quality,
                {
                    S(S(S(profile)->VideoEncoderConfiguration)->RateControl)->FrameRateLimit,
                    S(S(S(profile)->VideoEncoderConfiguration)->RateControl)->EncodingInterval,
                    S(S(S(profile)->VideoEncoderConfiguration)->RateControl)->BitrateLimit,
                },
                {
                    S(S(S(profile)->VideoEncoderConfiguration)->MPEG4)->GovLength,
                    static_cast<Mpeg4Profile>(S(S(S(profile)->VideoEncoderConfiguration)->MPEG4)->Mpeg4Profile)
                },
                {
                    S(S(S(profile)->VideoEncoderConfiguration)->H264)->GovLength,
                    static_cast<H264Profile>(S(S(S(profile)->VideoEncoderConfiguration)->H264)->H264Profile)
                },
                {
                    &S(S(S(S(S(profile)->VideoEncoderConfiguration)->Multicast)->Address)->IPv4Address)->front(),
                    S(S(S(profile)->VideoEncoderConfiguration)->Multicast)->Port,
                    S(S(S(profile)->VideoEncoderConfiguration)->Multicast)->TTL,
                    S(S(S(profile)->VideoEncoderConfiguration)->Multicast)->AutoStart,
                },
                S(S(profile)->VideoEncoderConfiguration)->SessionTimeout
            },
            {
                S(S(profile)->PTZConfiguration)->NodeToken,
                *S(S(S(profile)->PTZConfiguration)->DefaultAbsolutePantTiltPositionSpace),
                *S(S(S(profile)->PTZConfiguration)->DefaultAbsoluteZoomPositionSpace),
                *S(S(S(profile)->PTZConfiguration)->DefaultRelativePanTiltTranslationSpace),
                *S(S(S(profile)->PTZConfiguration)->DefaultRelativeZoomTranslationSpace),
                *S(S(S(profile)->PTZConfiguration)->DefaultContinuousPanTiltVelocitySpace),
                *S(S(S(profile)->PTZConfiguration)->DefaultContinuousZoomVelocitySpace),
                {
                    {
                        S(S(S(S(profile)->PTZConfiguration)->DefaultPTZSpeed)->PanTilt)->x,
                        S(S(S(S(profile)->PTZConfiguration)->DefaultPTZSpeed)->PanTilt)->y,
                        *S(S(S(S(S(profile)->PTZConfiguration)->DefaultPTZSpeed)->PanTilt)->space),
                    },
                    {
                        S(S(S(S(profile)->PTZConfiguration)->DefaultPTZSpeed)->Zoom)->x,
                        *S(S(S(S(S(profile)->PTZConfiguration)->DefaultPTZSpeed)->Zoom)->space),
                    }
                },
                *S(S(S(profile)->PTZConfiguration)->DefaultPTZTimeout),
                {
                    S(S(S(S(profile)->PTZConfiguration)->PanTiltLimits)->Range)->URI,
                    {
                        S(S(S(S(S(profile)->PTZConfiguration)->PanTiltLimits)->Range)->XRange)->Min,
                        S(S(S(S(S(profile)->PTZConfiguration)->PanTiltLimits)->Range)->XRange)->Max
                    },
                    {
                        S(S(S(S(S(profile)->PTZConfiguration)->PanTiltLimits)->Range)->YRange)->Min,
                        S(S(S(S(S(profile)->PTZConfiguration)->PanTiltLimits)->Range)->YRange)->Max
                    }
                },
                {
                    S(S(S(S(profile)->PTZConfiguration)->ZoomLimits)->Range)->URI,
                    {
                        S(S(S(S(S(profile)->PTZConfiguration)->ZoomLimits)->Range)->XRange)->Min,
                        S(S(S(S(S(profile)->PTZConfiguration)->ZoomLimits)->Range)->XRange)->Max
                    },
                }
            }
        };
    }

    template<typename SoapVideoSource>
    VideoSource OnvifClientMedia::ConvertToVideoSource(SoapVideoSource* source)
    {
        return VideoSource
        {
            S(source)->Framerate,
            {
                S(S(source)->Resolution)->Width,
                S(S(source)->Resolution)->Height
            },
            {
                {
                    S(S(S(source)->Imaging)->BacklightCompensation)->Level,
                    static_cast<OnMode>(S(S(S(source)->Imaging)->BacklightCompensation)->Mode)
                },
                *S(S(S(source)->Imaging)->Brightness),
                *S(S(S(source)->Imaging)->ColorSaturation),
                *S(S(S(source)->Imaging)->Sharpness),
                *S(S(S(source)->Imaging)->Contrast),
                {
                    static_cast<ExpMode>(S(S(S(source)->Imaging)->Exposure)->Mode),
                    S(S(S(source)->Imaging)->Exposure)->ExposureTime,
                    S(S(S(source)->Imaging)->Exposure)->Gain,
                    S(S(S(source)->Imaging)->Exposure)->Iris,
                    S(S(S(source)->Imaging)->Exposure)->MaxExposureTime,
                    S(S(S(source)->Imaging)->Exposure)->MinGain,
                    S(S(S(source)->Imaging)->Exposure)->MaxIris
                }
            }
        };
    }

    template<typename SoapVideoSourceConfigOptions>
    VideoSourceConfigurationOptions 
    OnvifClientMedia::ConvertToVideoConfigOptions(SoapVideoSourceConfigOptions* options)
    {
        return VideoSourceConfigurationOptions
        {
            {
                {
                    S(S(S(options)->BoundsRange)->XRange)->Min,
                    S(S(S(options)->BoundsRange)->XRange)->Max
                },
                {
                    S(S(S(options)->BoundsRange)->YRange)->Min,
                    S(S(S(options)->BoundsRange)->YRange)->Max
                },
                {
                    S(S(S(options)->BoundsRange)->WidthRange)->Min,
                    S(S(S(options)->BoundsRange)->WidthRange)->Max
                },
                {
                    S(S(S(options)->BoundsRange)->HeightRange)->Min,
                    S(S(S(options)->BoundsRange)->HeightRange)->Max
                }
            },
            S(options)->VideoSourceTokensAvailable
        };
    }

    template<typename SoapVideoSourceConfig>
    VideoSourceConfiguration OnvifClientMedia::ConvertToVideoSourceConfig(SoapVideoSourceConfig* config)
    {
        return VideoSourceConfiguration
        {
            S(config)->SourceToken,
            {
                S(S(config)->Bounds)->x,
                S(S(config)->Bounds)->y,
                S(S(config)->Bounds)->width,
                S(S(config)->Bounds)->height
            }
        };
    }
}
