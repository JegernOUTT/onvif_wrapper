#include "OnvifClientMedia.h"
#include "wsseapi.h"
#include "../source/impl/OnvifClientMediaImpl.h"

using namespace onvifwrapper;

OnvifClientMedia::OnvifClientMedia() :
    impl_(make_unique<OnvifClientMediaImpl>())
{
}

OnvifClientMedia::~OnvifClientMedia()
{
}

tuple<Result, Profile> OnvifClientMedia::GetMediaProfile(InfoTuple information, 
                                                         string profile_token)
{
    Authenticate(information);

    _ns9__GetProfile request;
    _ns9__GetProfileResponse response;
    request.ProfileToken = profile_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetProfile(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, Profile{});
    }

    return make_tuple(result, ConvertToProfile(response.Profile));
}
tuple<Result, vector<Profile>> OnvifClientMedia::GetMediaProfiles(InfoTuple information)
{
    Authenticate(information);

    _ns9__GetProfiles request;
    _ns9__GetProfilesResponse response;
    
    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetProfiles(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, vector<Profile>{});
    }

    vector<Profile> profiles;
    for_each(response.Profiles.begin(), 
             response.Profiles.end(), 
             [&profiles](auto el) { profiles.emplace_back(ConvertToProfile(el)); });
    return make_tuple(result, profiles);
}

tuple<Result, vector<VideoSource>> OnvifClientMedia::GetVideoSources(InfoTuple information)
{
    Authenticate(information);

    _ns9__GetVideoSources request;
    _ns9__GetVideoSourcesResponse response;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetVideoSources(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, vector<VideoSource>{});
    }

    vector<VideoSource> sources;
    for_each(response.VideoSources.begin(),
             response.VideoSources.end(),
             [&sources](auto el) { sources.emplace_back(ConvertToVideoSource(el)); });
    return make_tuple(result, sources);
}

tuple<Result, VideoSourceConfiguration> OnvifClientMedia::GetVideoSourceConfiguration(InfoTuple information,
                                                                                      string configuration_token)
{
    Authenticate(information);

    _ns9__GetVideoSourceConfiguration request;
    _ns9__GetVideoSourceConfigurationResponse response;
    request.ConfigurationToken = configuration_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetVideoSourceConfiguration(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, VideoSourceConfiguration{});
    }
    return make_tuple(result, ConvertToVideoSourceConfig(response.Configuration));
}

tuple<Result, vector<VideoSourceConfiguration>> OnvifClientMedia::GetVideoSourceConfigurations(InfoTuple information)
{
    Authenticate(information);

    _ns9__GetVideoSourceConfigurations request;
    _ns9__GetVideoSourceConfigurationsResponse response;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetVideoSourceConfigurations(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, vector<VideoSourceConfiguration>{});
    }

    vector<VideoSourceConfiguration> configs;
    for_each(response.Configurations.begin(),
             response.Configurations.end(),
             [&configs](auto el) { configs.emplace_back(ConvertToVideoSourceConfig(el)); });
    return make_tuple(result, configs);
}

tuple<Result, VideoSourceConfigurationOptions> OnvifClientMedia::GetVideoSourceConfigurationOptions(InfoTuple information,
                                                                                                    string configuration_token,
                                                                                                    string profile_token)
{
    Authenticate(information);

	_ns9__GetVideoSourceConfigurationOptions request;
    _ns9__GetVideoSourceConfigurationOptionsResponse response;
    request.ConfigurationToken = &configuration_token;
    request.ProfileToken = &profile_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetVideoSourceConfigurationOptions(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, VideoSourceConfigurationOptions{});
    }
    return make_tuple(result, ConvertToVideoConfigOptions(response.Options));
}

tuple<Result, MediaUri> OnvifClientMedia::GetStreamUri(InfoTuple information, 
                                                       StreamType stream_type,
                                                       TransportProtocol transport_protocol,
                                                       string profile_token)
{
    Authenticate(information);
    
    _ns9__GetStreamUri request;
    _ns9__GetStreamUriResponse response;
    ns2__StreamSetup stream_setup;
    ns2__Transport transport;
    transport.Protocol = static_cast<ns2__TransportProtocol>(transport_protocol);
    stream_setup.Stream = static_cast<ns2__StreamType>(stream_type);
    stream_setup.Transport = &transport;
    request.StreamSetup = &stream_setup;
    request.ProfileToken = profile_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetStreamUri(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, MediaUri {});
    }
    return make_tuple(result, MediaUri
                              {
                                  S(response.MediaUri)->Uri,
                                  S(response.MediaUri)->InvalidAfterConnect,
                                  S(response.MediaUri)->InvalidAfterReboot,
                                  S(response.MediaUri)->Timeout
                              });
}
tuple<Result, MediaUri> OnvifClientMedia::GetSnapshotUri(InfoTuple information,
                                                         string profile_token)
{
    Authenticate(information);

    _ns9__GetSnapshotUri request;
    _ns9__GetSnapshotUriResponse response;
    request.ProfileToken = profile_token;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetSnapshotUri(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, MediaUri{});
    }
    return make_tuple(result, MediaUri
    {
        S(response.MediaUri)->Uri,
        S(response.MediaUri)->InvalidAfterConnect,
        S(response.MediaUri)->InvalidAfterReboot,
        S(response.MediaUri)->Timeout
    });
}

Result OnvifClientMedia::StartMulticastStreaming(InfoTuple information, 
                                                 string profile_token)
{
    Authenticate(information);

    _ns9__StartMulticastStreaming request;
    _ns9__StartMulticastStreamingResponse response;
    request.ProfileToken = profile_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.StartMulticastStreaming(&request, response), impl_->device_proxy_.soap);
}
Result OnvifClientMedia::StopMulticastStreaming(InfoTuple information,
                                                string profile_token)
{
    Authenticate(information);

    _ns9__StopMulticastStreaming request;
    _ns9__StopMulticastStreamingResponse response;
    request.ProfileToken = profile_token;

    return ErrorWrap::Wrap(impl_->device_proxy_.StopMulticastStreaming(&request, response), impl_->device_proxy_.soap);
}

tuple<Result, Capabilities> OnvifClientMedia::GetServiceCapabilities(InfoTuple information)
{
    Authenticate(information);

	_ns9__GetServiceCapabilities request;
    _ns9__GetServiceCapabilitiesResponse response;

    auto result = ErrorWrap::Wrap(impl_->device_proxy_.GetServiceCapabilities(&request, response), impl_->device_proxy_.soap);
    if (result.is_error)
    {
        return make_tuple(result, Capabilities{});
    }
    return make_tuple(result, Capabilities
                              {
                                  *S(S(S(response.Capabilities)->ProfileCapabilities)->MaximumNumberOfProfiles),
                                  {
                                      *S(S(S(response.Capabilities)->StreamingCapabilities)->RTPMulticast),
                                      *S(S(S(response.Capabilities)->StreamingCapabilities)->RTP_USCORETCP),
                                      *S(S(S(response.Capabilities)->StreamingCapabilities)->RTP_USCORERTSP_USCORETCP),
                                      *S(S(S(response.Capabilities)->StreamingCapabilities)->NonAggregateControl),
                                      *S(S(S(response.Capabilities)->StreamingCapabilities)->NoRTSPStreaming)
                                  },
                                  *S(S(response.Capabilities)->SnapshotUri),
                                  *S(S(response.Capabilities)->Rotation),
                                  *S(S(response.Capabilities)->VideoSourceMode),
                                  *S(S(response.Capabilities)->OSD),
                                  *S(S(response.Capabilities)->EXICompression)
                              });
}

void OnvifClientMedia::Authenticate(InfoTuple& information)
{
    impl_->device_proxy_.soap_endpoint = get<2>(information).c_str();
    soap_wsse_add_Security(impl_->device_proxy_.soap);
    soap_wsse_add_UsernameTokenDigest(impl_->device_proxy_.soap, "Id", get<0>(information).c_str(), get<1>(information).c_str());

    impl_->device_proxy_.soap->recv_timeout = 5;
    impl_->device_proxy_.soap->send_timeout = 5;
    impl_->device_proxy_.soap->connect_timeout = 5;
}
