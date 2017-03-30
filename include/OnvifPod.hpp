#pragma once

#include <string>
#include <utility>
#include <vector>

namespace onvifwrapper
{
	using std::string;
    using std::pair;
    using std::vector;

    using FRange = pair<float, float>;
    using IRange = pair<int, int>;
    using DurationRange = pair<int64_t, int64_t>;

    enum class OnMode { OFF = 0, ON = 1 };
    enum class ExpMode { AUTO = 0, MANUAL = 1 };
    enum class MoveStatus { IDLE = 0, MOVING = 1, UNKNOWN = 2 };
    enum class VideoEncoding { JPEG = 0, MPEG4 = 1, H264 = 2 };
    enum class Mpeg4Profile { SP = 0, ASP = 1 };
    enum class H264Profile { BASELINE = 0, MAIN = 1, EXTENDED = 2, HIGH = 3 };
    enum class StreamType { RTP_UNICAST = 0, RTP_MULTICAST = 1 };
    enum class TransportProtocol { UDP = 0, TCP = 1, RTSP = 2, HTTP = 3 };


    struct AnalyticsCapabilities
    {
        string address;
        bool rule_support;
        bool analytics_module_support;
    };

    struct NetworkCapabilities
    {
        bool ip_filter;
        bool zero_configuration;
        bool ip_version6;
        bool dyn_dns;
    };

    struct SystemCapabilities
    {
        bool discovery_resolve;
        bool discovery_bye;
        bool remote_discovery;
        bool system_backup;
        bool system_logging;
        bool firmware_upgrade;
    };

    struct IOCapabilities
    {
        int input_connectors;
        int relay_outputs;
    };

    struct SecurityCapabilities
    {
        bool tls1_x002_e1;
        bool tls1_x002_e2;
        bool onboard_key_generation;
        bool access_policy_config;
        bool x_x002_e509_token;
        bool saml_token;
        bool kerberos_token;
        bool rel_token;
    };

    struct EventCapabilities
    {
        string address;
        bool ws_subscription_policy_support;
        bool ws_pull_point_support;
        bool ws_pausable_subscription_manager_interface_support;
    };

    struct ImagingCapabilities
    {
        string address;
    };

    struct RealTimeStreamingCapabilities
    {
        bool rtp_multicast;
        bool rtp_uscoretcp;
        bool rtp_uscorertsp_uscoretcp;
    };

    struct PTZCapabilities
    {
        string address;
    };

    struct DeviceCapabilities
    {
        string address;
        NetworkCapabilities network;
        SystemCapabilities system;
        IOCapabilities io;
        SecurityCapabilities security;
    };

    struct MediaCapabilities
    {
        string address;
        RealTimeStreamingCapabilities streaming_capabilities;
    };

	struct OnvifCapabilities
	{
        AnalyticsCapabilities analytics;
        DeviceCapabilities device;
        EventCapabilities events;
        ImagingCapabilities imaging;
        MediaCapabilities media;
        PTZCapabilities ptz;
	};

	struct Result
	{
		bool is_error;
		int error_code;
		string soap_error;
		string full_error;
	};

	struct DeviceInformation
	{
		string firmaware;
		string hardware;
		string manufacture;
		string model;
		string serial;
	};

    struct BackLightCompensation
    {
        float level;
        OnMode mode;
    };

    struct Exposure
    {
        ExpMode mode;
        float exposure_time;
        float gain;
        float iris;
        float max_exposure_time;
        float min_gain;
        float max_iris;
    };

	struct ImageSettings
	{
		BackLightCompensation back_light_compensation;
		float brightness;
		float color_saturation;
		float sharpness;
		float contrast;
		Exposure exposure;
	};

    struct BackLightCompensationRange
    {
        FRange level_range;
        pair<OnMode, OnMode> mode_range;
    };

    struct ExposureRange
    {
        pair<ExpMode, ExpMode> mode_range;
        FRange exposure_time_range;
        FRange gain_range;
        FRange iris_range;
        FRange max_exposure_time_range;
        FRange min_gain_range;
        FRange max_iris_range;
    };

    struct ImageOptions
    {
        BackLightCompensationRange back_light_compensation_range;
        FRange brightness;
        FRange color_saturation;
        FRange sharpness;
        FRange contrast;
        ExposureRange exposure;
    };

    struct AbsoluteFocus
    {
        float position;
        float speed;
    };

    struct RelativeFocus
    {
        float distance;
        float speed;
    };

    struct ContinuousFocus
    {
        float speed;
    };

    struct FocusMove
    {
        AbsoluteFocus absolute_move;
        RelativeFocus relative_move;
        ContinuousFocus continuous_move;
    };

    struct AbsoluteFocusRange
    {
        FRange position;
        FRange speed;
    };

    struct RelativeFocusRange
    {
        FRange distance;
        FRange speed;
    };

    struct ContinuousFocusRange
    {
        FRange speed;
    };

    struct FocusMoveOptionsRange
    {
        AbsoluteFocusRange absolute_move_range;
        RelativeFocusRange relative_move_range;
        ContinuousFocusRange continuous_move_range;
    };

    struct FocusStatus
    {
        float position;
        MoveStatus move_status;
        string error;
    };

    struct ImagingStatus
    {
        FocusStatus focus_status;
    };

    struct ImageCapabilities
    {
        bool image_stabilization;
        bool presets;
    };

    struct IntRectangle
    {
        int x;
        int y;
        int width;
        int height;
    };

    struct IntRectangleRange
    {
        IRange x_range;
        IRange y_range;
        IRange width_range;
        IRange height_range;
    };

    struct Vector2D
    {
        float x;
        float y;
        string space;
    };

    struct Vector1D
    {
        float x;
        string space;
    };

    struct PTZSpeed
    {
        Vector2D pan_tilt;
        Vector1D zoom;
    };

    struct PTZVector
    {
        Vector2D pan_tilt;
        Vector1D zoom;
    };

    struct PanTiltLimits
    {
        string uri;
        FRange x_range;
        FRange y_range;
    };

    struct ZoomLimits
    {
        string uri;
        FRange x_range;
    };

    struct PTZConfiguration
    {
        string node_token;
        string default_absolute_pant_tilt_position_space;
        string default_absolute_zoom_position_space;
        string default_relative_pan_tilt_translation_space;
        string default_relative_zoom_translation_space;
        string default_continuous_pan_tilt_velocity_space;
        string default_continuous_zoom_velocity_space;
        PTZSpeed default_ptz_speed;
        string default_ptz_timeout;
        PanTiltLimits pan_tilt_limits;
        ZoomLimits zoom_limits;
    };

    struct VideoSourceConfiguration
    {
        string source_token;
        IntRectangle bounds;
    };

    struct AudioSourceConfiguration
    {
        string source_token;
    };

    struct VideoResolution
    {
        int width;
        int height;
    };

    struct VideoRateControl
    {
        int framerate_limit;
        int encoding_interval;
        int bitrate_limit;
    };

    struct Mpeg4Configuration
    {
        int gov_length;
        Mpeg4Profile mpeg4_profile;
    };

    struct H264Configuration
    {
        int gov_length;
        H264Profile mpeg4_profile;
    };

    struct MulticastConfiguration
    {
        string ipv4_address;
        int port;
        int ttl;
        bool auto_start;
    };

    struct VideoEncoderConfiguration
    {
        VideoEncoding video_encoding;
        VideoResolution video_resolution;
        float quality;
        VideoRateControl video_rate_control;
        Mpeg4Configuration mpeg4_configuration;
        H264Configuration h264_configuration;
        MulticastConfiguration multicast_configuration;
        string session_timeout;
    };

    struct Profile
    {
        string name;
        string token;
        bool fixed;
        VideoSourceConfiguration video_source_configuration;
        AudioSourceConfiguration audio_source_configuration;
        VideoEncoderConfiguration video_encoder_configuration;
        PTZConfiguration ptz_configuration;
    };

    struct VideoSource
    {
        float frame_rate;
        VideoResolution resolution;
        ImageSettings imaging;
    };

    struct VideoSourceConfigurationOptions
    {
        IntRectangleRange bounds_range;
        vector<string> video_source_tokens_available;
    };

    struct MediaUri
    {
        string uri;
        bool invalid_after_connect;
        bool invalid_after_reboot;
        string timeout;
    };

    struct StreamingCapabilities
    {
        bool rtp_multicast;
        bool rtp_uscoretcp;
        bool rtp_uscorertsp_uscoretcp;
        bool non_aggregate_control;
        bool no_rtsp_streaming;
    };

    struct Capabilities
    {
        int maximum_number_of_profiles;
        StreamingCapabilities streaming_capabilities;
        bool snapshot_uri;
        bool rotation;
        bool video_source_mode;
        bool osd;
        bool exi_compression;
    };

    struct Space2DDescriptionRange
    {
        string uri;
        FRange x_range;
        FRange y_range;
    };

    struct Space1DDescriptionRange
    {
        string uri;
        FRange x_range;
    };

    struct PTZSpaces
    {

        vector<Space2DDescriptionRange> absolute_pan_tilt_position_space;
        vector<Space1DDescriptionRange> absolute_zoom_position_space;
        vector<Space2DDescriptionRange> relative_pantilt_translation_space;
        vector<Space1DDescriptionRange> relative_zoom_translation_space;
        vector<Space2DDescriptionRange> continuous_pantilt_velocity_space;
        vector<Space1DDescriptionRange> continuous_zoom_velocity_space;
        vector<Space1DDescriptionRange> pantilt_speed_space;
        vector<Space1DDescriptionRange> zoom_speed_space;
    };

    struct PTZConfigurationOptions
    {
        PTZSpaces spaces;
        DurationRange ptz_timeout;
    };

    struct Preset
    {
        string name;
        string token;
        PTZVector ptz_position;
    };
    
    struct PTZMoveStatus
    {
        MoveStatus pan_tilt;
        MoveStatus zoom;
    };

    struct PTZStatus
    {
        PTZVector position;
        PTZMoveStatus move_status;
        string error;
        uint64_t utc_time;
    };

    struct PTZCapabilitiesInformation
    {
        bool e_flip;
        bool reverse;
        bool get_compatible_configurations;
        bool move_status;
        bool status_position;
    };

    struct PTZNode
    {
        string name;
        PTZSpaces supported_ptz_spaces;
        int maximum_number_of_presets;
        bool home_supported;
        vector<string> auxiliary_commands;
        bool fixed_home_position;
    };
}
