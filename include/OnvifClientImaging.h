#pragma once

#include <vector>
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

    struct OnvifClientImagingImpl;

    class OnvifClientImaging
    {
		using InfoTuple = tuple<string, string, string>;

    public:
        OnvifClientImaging();
		OnvifClientImaging(OnvifClientImaging&) = delete;
		OnvifClientImaging& operator=(OnvifClientImaging&) = delete;
        ~OnvifClientImaging();

		tuple<Result, ImageSettings> GetImagingSettings(InfoTuple information,
		                                                string video_source_token);

        Result SetImagingSettings(InfoTuple information,
                                  string video_source_token,
                                  ImageSettings image_settings,
                                  bool force);

        tuple<Result, ImageOptions> GetOptions(InfoTuple information,
                                               string videoSourceToken);

        Result Move(InfoTuple information,
                    string video_source_token,
                    FocusMove focus_move);

        tuple<Result, FocusMoveOptionsRange> GetMoveOptions(InfoTuple information,
                                                       string video_source_token);

        Result Stop(InfoTuple information,
                    string video_source_token);

        tuple<Result, ImagingStatus> GetImagingStatus(InfoTuple information,
                                                      string video_source_token);

        tuple<Result, ImageCapabilities> GetServiceCapabilities(InfoTuple information);

    private:
	    unique_ptr<OnvifClientImagingImpl> impl_;
        void Authenticate(InfoTuple& information);
    };
}
