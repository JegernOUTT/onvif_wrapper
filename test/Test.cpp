#include <chrono>
#include <thread>
#include <bandit/bandit.h>

#include "Onvif.hpp"
#include "Utility.hpp"

using namespace bandit;
using namespace snowhouse;

go_bandit([]()
{
    using namespace onvifwrapper;
    using namespace std::chrono;
    using namespace std::this_thread;;

    using std::tie;
    using std::to_string;

    // Global connection data
    string login = "root";
    string password = "root";
    string url = "http://192.168.0.94//onvif//device_service";

    OnvifCapabilities capabilities;
    vector<Profile> profiles;
    vector<VideoSourceConfiguration> configurations;
    vector<PTZConfiguration> ptz_configurations;
    PTZConfigurationOptions move_spaces;
    vector<Preset> presets;
    vector<PTZNode> ptz_nodes;

    describe("Ovif client device test", [&]
    {
        OnvifClientDevice device;
        auto information = make_tuple(login, password, url);
        
        it("Capabilities test", [&]
        {
            Result result;

            tie(result, capabilities) = device.GetCapabilities(information);

            AssertThat(result.is_error,             Is().EqualTo(false));
            AssertThat(capabilities.device.address, Is().Not().EqualTo(""));
            AssertThat(capabilities.media.address,  Is().Not().EqualTo(""));
            AssertThat(capabilities.ptz.address,    Is().Not().EqualTo(""));
        });

        it_skip("Reboot test", [&]
        {
            Result result;
            string message;

            tie(result, message) = device.SystemReboot(information);

            AssertThat(result.is_error, Is().EqualTo(false));
        });

        it("Device information test", [&]
        {
            Result result;
            DeviceInformation device_information;

            tie(result, device_information) = device.GetDeviceInformation(information);

            AssertThat(result.is_error,                Is().EqualTo(false));
            AssertThat(device_information.firmaware,   Is().Not().EqualTo(""));
            AssertThat(device_information.hardware,    Is().Not().EqualTo(""));
            AssertThat(device_information.manufacture, Is().Not().EqualTo(""));
            AssertThat(device_information.model,       Is().Not().EqualTo(""));
            AssertThat(device_information.serial,      Is().Not().EqualTo(""));
        });
    });

    describe("Onvif client media test", [&]
    {
        OnvifClientMedia media;
        auto information = make_tuple(login, password, capabilities.media.address);

        it("Get media profiles test", [&]
        {
            Result result;

            tie(result, profiles) = media.GetMediaProfiles(information);

            AssertThat(result.is_error, Is().EqualTo(false));
            AssertThat(profiles.size(), Is().Not().EqualTo(0));
            for (auto& profile : profiles)
            {
                AssertThat(profile.token, Is().Not().EqualTo(""));
                AssertThat(profile.name,  Is().Not().EqualTo(""));
                AssertThat(profile.video_source_configuration.bounds.height, Is().GreaterThan(0));
                AssertThat(profile.video_source_configuration.bounds.width,  Is().GreaterThan(0));
            }
        });

        it("Get media profile one by one test", [&]
        {
            for (auto& profile : profiles)
            {
                Result result;
                Profile incomig_profile;

                tie(result, incomig_profile) = media.GetMediaProfile(information, profile.token);

                AssertThat(result.is_error,         Is().EqualTo(false));
                AssertThat(incomig_profile.name,    Is().EqualTo(profile.name));
                AssertThat(incomig_profile.token,   Is().EqualTo(profile.token));
                AssertThat(incomig_profile.fixed,   Is().EqualTo(profile.fixed));
            }
        });

        it("Get video sources test", [&]
        {
            Result result;
            vector<VideoSource> video_sources;

            tie(result, video_sources) = media.GetVideoSources(information);

            AssertThat(result.is_error, Is().EqualTo(false));
            AssertThat(video_sources.size(), Is().Not().EqualTo(0));
            for (auto& source : video_sources)
            {
                AssertThat(source.resolution.width, Is().GreaterThan(0));
                AssertThat(source.resolution.height, Is().GreaterThan(0));
                AssertThat(source.frame_rate, Is().GreaterThan(0));
            }
        });

        it("Get video source configuration test", [&]
        {
            Result result;

            tie(result, configurations) = media.GetVideoSourceConfigurations(information);

            AssertThat(result.is_error,             Is().EqualTo(false));
            AssertThat(configurations.size(),       Is().GreaterThan(0));
            for (auto& config: configurations)
            {
                AssertThat(config.source_token,     Is().Not().EqualTo(""));
                AssertThat(config.bounds.height,    Is().GreaterThan(0));
                AssertThat(config.bounds.width,     Is().GreaterThan(0));
            }
        });

        it("Get video source configuration one by one test", [&]
        {
            for (auto& config : configurations)
            {
                Result result;
                VideoSourceConfiguration incomig_config;

                tie(result, incomig_config) = media.GetVideoSourceConfiguration(information, config.source_token);

                AssertThat(result.is_error,                 Is().EqualTo(false));
                AssertThat(incomig_config.source_token,     Is().EqualTo(incomig_config.source_token));
                AssertThat(incomig_config.bounds.width,     Is().EqualTo(incomig_config.bounds.width));
                AssertThat(incomig_config.bounds.height,    Is().EqualTo(incomig_config.bounds.height));
            }
        });

        it("Get video source configuration options test", [&]
        {
            Result result;
            VideoSourceConfigurationOptions config_options;

            for (auto& config : configurations)
            {
                for (auto& profile : profiles)
                {
                    tie(result, config_options) = media.GetVideoSourceConfigurationOptions(information, 
                                                                                           config.source_token,
                                                                                           profile.token);
                    AssertThat(result.is_error, Is().EqualTo(false));
                }
            }
        });

        it("Get stream uri test", [&]
        {
            Result result;
            MediaUri uri;

            for (auto& profile : profiles)
            {
                tie(result, uri) = media.GetStreamUri(information, 
                                                      StreamType::RTP_UNICAST, 
                                                      TransportProtocol::RTSP, 
                                                      profile.token);
                AssertThat(result.is_error, Is().EqualTo(false));
                AssertThat(uri.uri,         Is().Not().EqualTo(""));
            }
        });

        it("Get snapshot uri test", [&]
        {
            Result result;
            MediaUri uri;

            for (auto& profile : profiles)
            {
                if (profile.name != "TestMediaProfile" && profile.name != "Test")
                {
                    tie(result, uri) = media.GetSnapshotUri(information,
                                                            profile.token);
                    AssertThat(result.is_error, Is().EqualTo(false));
                    AssertThat(uri.uri, Is().Not().EqualTo(""));
                }
            }
        });

        it("Start multicast streaming test", [&]
        {
            Result result;

            for (auto& profile : profiles)
            {
                if (profile.name != "TestMediaProfile" && profile.name != "Test")
                {
                    result = media.StartMulticastStreaming(information,
                                                           profile.token);
                    AssertThat(result.is_error, Is().EqualTo(false));
                }
            }
        });

        it("Stop multicast streaming test", [&]
        {
            Result result;

            for (auto& profile : profiles)
            {
                if (profile.name != "TestMediaProfile" && profile.name != "Test")
                {
                    result = media.StopMulticastStreaming(information,
                                                          profile.token);
                    AssertThat(result.is_error, Is().EqualTo(false));
                }
            }
        });

        it_skip("Get service capabilities sources test", [&]
        {
            Result result;
            Capabilities cap;

            tie(result, cap) = media.GetServiceCapabilities(information);

            AssertThat(result.is_error,                 Is().EqualTo(false));
            AssertThat(cap.maximum_number_of_profiles,  Is().GreaterThan(0));
        });
    });

    describe("Onvif client ptz", [&]
    {
        OnvifClientPTZ ptz;
        auto information = make_tuple(login, password, capabilities.ptz.address);

        it("Get configurations test", [&]
        {
            Result result;

            tie(result, ptz_configurations) = ptz.GetConfigurations(information);

            AssertThat(result.is_error,             Is().EqualTo(false));
            AssertThat(ptz_configurations.size(),   Is().Not().EqualTo(0));
            for (auto& conf : ptz_configurations)
            {
                AssertThat(conf.node_token, Is().Not().EqualTo(""));
                AssertThat(conf.default_ptz_timeout, Is().Not().EqualTo(""));
                AssertThat(conf.default_absolute_pant_tilt_position_space, Is().Not().EqualTo(""));
                AssertThat(conf.default_absolute_zoom_position_space, Is().Not().EqualTo(""));
                AssertThat(conf.default_continuous_pan_tilt_velocity_space, Is().Not().EqualTo(""));
                AssertThat(conf.default_continuous_zoom_velocity_space, Is().Not().EqualTo(""));
                AssertThat(conf.default_relative_pan_tilt_translation_space, Is().Not().EqualTo(""));
                AssertThat(conf.default_relative_zoom_translation_space, Is().Not().EqualTo(""));
            }
        });

        it("Get configuration one by one test", [&]
        {
            Result result;
            PTZConfiguration inc_conf;

            tie(result, inc_conf) = ptz.GetConfiguration(information, "0");

            auto config = ptz_configurations.front();
            AssertThat(result.is_error, Is().EqualTo(false));
            AssertThat(config.node_token, Is().EqualTo(config.node_token));
            AssertThat(config.default_ptz_timeout, Is().EqualTo(config.default_ptz_timeout));
            AssertThat(config.default_absolute_pant_tilt_position_space,
                       Is().EqualTo(config.default_absolute_pant_tilt_position_space));
            AssertThat(config.default_absolute_zoom_position_space,
                       Is().EqualTo(config.default_absolute_zoom_position_space));
            AssertThat(config.default_continuous_pan_tilt_velocity_space,
                       Is().EqualTo(config.default_continuous_pan_tilt_velocity_space));
            AssertThat(config.default_continuous_zoom_velocity_space,
                       Is().EqualTo(config.default_continuous_zoom_velocity_space));
            AssertThat(config.default_relative_pan_tilt_translation_space,
                       Is().EqualTo(config.default_relative_pan_tilt_translation_space));
            AssertThat(config.default_relative_zoom_translation_space,
                       Is().EqualTo(config.default_relative_zoom_translation_space));
            AssertThat(config.default_ptz_timeout, Is().EqualTo(config.default_ptz_timeout));
        });

        it("Get configuration options test", [&]
        {
            Result result;

            tie(result, move_spaces) = ptz.GetConfigurationOptions(information, "0");

            AssertThat(result.is_error, Is().EqualTo(false));
        });

        it_skip("Relative move test", [&]
        {
            uint32_t error_count = 0u;
            for (auto i = 0; i < 10; ++i)
            {
                // translation { pantilt {x , y}, zoom {x} }
                PTZVector translation = {
                    {
                        GF(move_spaces.spaces.relative_pantilt_translation_space.front().x_range.first,
                        move_spaces.spaces.relative_pantilt_translation_space.front().x_range.second),
                        GF(move_spaces.spaces.relative_pantilt_translation_space.front().y_range.first,
                        move_spaces.spaces.relative_pantilt_translation_space.front().y_range.second)
                    },
                    {
                        GF(move_spaces.spaces.relative_zoom_translation_space.front().x_range.first,
                        move_spaces.spaces.relative_zoom_translation_space.front().x_range.second)
                    }
                };

                // speed { pantilt {x , y}, zoom {x} }
                PTZSpeed speed = {
                    {
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second),
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second)
                    },
                    {
                        GF(move_spaces.spaces.zoom_speed_space.front().x_range.first,
                        move_spaces.spaces.zoom_speed_space.front().x_range.second)
                    }
                };

                auto result = ptz.RelativeMove(information,
                                               translation,
                                               speed,
                                               profiles.front().token);

                if (result.is_error)
                    error_count++;

                sleep_for(5s);
            }
            AssertThat(error_count, Is().EqualTo(0));
        });

        it_skip("Continuous move test", [&]
        {
            uint32_t error_count = 0u;
            for (auto i = 0; i < 10; ++i)
            {
                // speed { pantilt {x , y}, zoom {x} }
                PTZSpeed speed =
                {
                    {
                        GF(move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.second),
                        GF(move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.second)
                    },
                    {
                        GF(move_spaces.spaces.continuous_zoom_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_zoom_velocity_space.front().x_range.second)
                    }
                };

                auto result = ptz.ContinuousMove(information,
                                                 speed,
                                                 "PT5S",
                                                 profiles.front().token);

                if (result.is_error)
                    error_count++;

                sleep_for(5s);
            }
            AssertThat(error_count, Is().EqualTo(0));
        });

        it_skip("Absolute move test", [&]
        {
            uint32_t error_count = 0u;
            for (auto i = 0; i < 10; ++i)
            {
                // position { pantilt {x , y}, zoom {x} }
                PTZVector position = {
                    {
                        GF(move_spaces.spaces.absolute_pan_tilt_position_space.front().x_range.first,
                        move_spaces.spaces.absolute_pan_tilt_position_space.front().x_range.second),
                        GF(move_spaces.spaces.absolute_pan_tilt_position_space.front().y_range.first,
                        move_spaces.spaces.absolute_pan_tilt_position_space.front().y_range.second)
                    },
                    {
                        GF(move_spaces.spaces.absolute_zoom_position_space.front().x_range.first,
                        move_spaces.spaces.absolute_zoom_position_space.front().x_range.second)
                    }
                };

                // speed { pantilt {x , y}, zoom {x} }
                PTZSpeed speed = {
                    {
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second),
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second)
                    },
                    {
                        GF(move_spaces.spaces.zoom_speed_space.front().x_range.first,
                        move_spaces.spaces.zoom_speed_space.front().x_range.second)
                    }
                };

                auto result = ptz.AbsoluteMove(information,
                                               speed,
                                               position,
                                               profiles.front().token);

                if (result.is_error)
                    error_count++;

                sleep_for(5s);
            }
            AssertThat(error_count, Is().EqualTo(0));
        });

        it_skip("Continuous move with stop test", [&]
        {
            uint32_t error_count = 0u;
            for (auto i = 0; i < 10; ++i)
            {
                // speed { pantilt {x , y}, zoom {x} }
                PTZSpeed speed = {
                    {
                        GF(move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.second),
                        GF(move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_pantilt_velocity_space.front().x_range.second)
                    },
                    {
                        GF(move_spaces.spaces.continuous_zoom_velocity_space.front().x_range.first,
                        move_spaces.spaces.continuous_zoom_velocity_space.front().x_range.second)
                    }
                };

                auto result = ptz.ContinuousMove(information,
                                                 speed,
                                                 "PT5S",
                                                 profiles.front().token);

                if (result.is_error)
                    error_count++;

                sleep_for(3s);

                result = ptz.Stop(information,
                                  true,
                                  true,
                                  profiles.front().token);
                AssertThat(result.is_error, Is().EqualTo(false));
            }
            AssertThat(error_count, Is().EqualTo(0));
        });

        it("Add presets test", [&]
        {
            for (auto i = 0; i < 16; ++i)
                presets.push_back( {"TestPreset" + to_string(i + 100), 
                                    "",
                                    {} });
            Result result;
            string preset_token;
            for (auto& preset: presets)
            {
                PTZVector translation = {
                    {
                        GF(move_spaces.spaces.relative_pantilt_translation_space.front().x_range.first,
                        move_spaces.spaces.relative_pantilt_translation_space.front().x_range.second),
                        GF(move_spaces.spaces.relative_pantilt_translation_space.front().y_range.first,
                        move_spaces.spaces.relative_pantilt_translation_space.front().y_range.second)
                    },
                    {
                        GF(move_spaces.spaces.relative_zoom_translation_space.front().x_range.first,
                        move_spaces.spaces.relative_zoom_translation_space.front().x_range.second)
                    }
                };

                PTZSpeed speed = {
                    {
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second),
                        GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                        move_spaces.spaces.pantilt_speed_space.front().x_range.second)
                    },
                    {
                        GF(move_spaces.spaces.zoom_speed_space.front().x_range.first,
                        move_spaces.spaces.zoom_speed_space.front().x_range.second)
                    }
                };
                result = ptz.RelativeMove(information,
                                          translation,
                                          speed,
                                          profiles.front().token);
                AssertThat(result.is_error, Is().EqualTo(false));

                tie(result, preset_token) = ptz.AddPreset(information,
                                                          profiles.front().token,
                                                          preset.name);
                AssertThat(result.is_error, Is().EqualTo(false));
                AssertThat(preset_token,    Is().Not().EqualTo(""));
                preset.token = preset_token;
            }
        });

        it("Goto presets test", [&]
        {
            for (auto& preset : presets)
            {
                auto result = ptz.GoToPreset(information,
                                             profiles.front().token,
                                             preset.token,
                                             { { 1.f , 1.f }, { 1.f } });

                AssertThat(result.is_error, Is().EqualTo(false));
            }
        });

        it("Change presets test", [&]
        {
            auto i = 0u;
            for (auto& preset : presets)
                preset.name = "ChangedTestPreset" + to_string(100 + i++);

            Result result;
            string preset_token;
            for (auto& preset : presets)
            {
                tie(result, preset_token) = ptz.ChangePreset(information,
                                                             profiles.front().token,
                                                             preset.token,
                                                             preset.name);
                AssertThat(result.is_error, Is().EqualTo(false));
                AssertThat(preset_token, Is().Not().EqualTo(""));
                preset.token = preset_token;
            }
        });

        it("Get all presets test", [&]
        {
            Result result;
            vector<Preset> inc_presets;

            tie(result, inc_presets) = ptz.GetPresets(information,
                                                      profiles.front().token);
            AssertThat(result.is_error,     Is().EqualTo(false));

            for (auto& preset : presets)
            {
                auto finded = std::find_if(inc_presets.begin(), 
                                           inc_presets.end(), 
                                           [&preset](auto& el) { return preset.token == el.token; });
                AssertThat(finded,          Is().Not().EqualTo(inc_presets.end()));
                AssertThat((*finded).token, Is().EqualTo(preset.token));
                AssertThat((*finded).name,  Is().EqualTo(preset.name));
            }
        });

        it("Remove all presets test", [&]
        {
            for (auto& preset : presets)
            {
                auto result = ptz.RemovePreset(information,
                                               profiles.front().token,
                                               preset.token);
                AssertThat(result.is_error, Is().EqualTo(false));
            }

            Result result;
            vector<Preset> inc_presets;

            tie(result, inc_presets) = ptz.GetPresets(information,
                                                      profiles.front().token);
            AssertThat(result.is_error, Is().EqualTo(false));

            for (auto& preset : presets)
            {
                auto finded = std::find_if(inc_presets.begin(),
                                           inc_presets.end(),
                                           [&preset](auto& el) { return preset.token == el.token; });
                AssertThat(finded,      Is().EqualTo(inc_presets.end()));
            }
        });

        it_skip("Set home test", [&]
        {
            PTZVector translation = {
                {
                    GF(move_spaces.spaces.relative_pantilt_translation_space.front().x_range.first,
                    move_spaces.spaces.relative_pantilt_translation_space.front().x_range.second),
                    GF(move_spaces.spaces.relative_pantilt_translation_space.front().y_range.first,
                    move_spaces.spaces.relative_pantilt_translation_space.front().y_range.second)
                },
                {
                    GF(move_spaces.spaces.relative_zoom_translation_space.front().x_range.first,
                    move_spaces.spaces.relative_zoom_translation_space.front().x_range.second)
                }
            };

            PTZSpeed speed = {
                {
                    GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                    move_spaces.spaces.pantilt_speed_space.front().x_range.second),
                    GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                    move_spaces.spaces.pantilt_speed_space.front().x_range.second)
                },
                {
                    GF(move_spaces.spaces.zoom_speed_space.front().x_range.first,
                    move_spaces.spaces.zoom_speed_space.front().x_range.second)
                }
            };
            auto result = ptz.RelativeMove(information,
                                           translation,
                                           speed,
                                           profiles.front().token);
            AssertThat(result.is_error, Is().EqualTo(false));

            result = ptz.SetHome(information,
                                 profiles.front().token);
            AssertThat(result.is_error, Is().EqualTo(false));
        });

        it("Goto home test", [&]
        {
            PTZVector translation = {
                {
                    GF(move_spaces.spaces.relative_pantilt_translation_space.front().x_range.first,
                    move_spaces.spaces.relative_pantilt_translation_space.front().x_range.second),
                    GF(move_spaces.spaces.relative_pantilt_translation_space.front().y_range.first,
                    move_spaces.spaces.relative_pantilt_translation_space.front().y_range.second)
                },
                {
                    GF(move_spaces.spaces.relative_zoom_translation_space.front().x_range.first,
                    move_spaces.spaces.relative_zoom_translation_space.front().x_range.second)
                }
            };

            PTZSpeed speed = {
                {
                    GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                    move_spaces.spaces.pantilt_speed_space.front().x_range.second),
                    GF(move_spaces.spaces.pantilt_speed_space.front().x_range.first,
                    move_spaces.spaces.pantilt_speed_space.front().x_range.second)
                },
                {
                    GF(move_spaces.spaces.zoom_speed_space.front().x_range.first,
                    move_spaces.spaces.zoom_speed_space.front().x_range.second)
                }
            };
            auto result = ptz.RelativeMove(information,
                                           translation,
                                           speed,
                                           profiles.front().token);
            AssertThat(result.is_error, Is().EqualTo(false));

            result = ptz.GoToHome(information,
                                  profiles.front().token,
                                  { { 1.f, 1.f }, { 1.f } });
            AssertThat(result.is_error, Is().EqualTo(false));
        });

        it("Get status test", [&]
        {
            Result result;
            PTZStatus status;

            tie(result, status) = ptz.GetStatus(information, 
                                                profiles.front().token);

            AssertThat(result.is_error, Is().EqualTo(false));
            // AssertThat(status.utc_time, Is().GreaterThan(0));
        });

        it_skip("Get service capabilities test", [&]
        {
            Result result;
            PTZCapabilitiesInformation capabilities;

            tie(result, capabilities) = ptz.GetServiceCapabilities(information);

            AssertThat(result.is_error, Is().EqualTo(false));
        });

        it("Get ptz nodes test", [&]
        {
            Result result;

            tie(result, ptz_nodes) = ptz.GetNodes(information);

            AssertThat(result.is_error, Is().EqualTo(false));
            AssertThat(ptz_nodes.size(), Is().GreaterThan(0));
            AssertThat(ptz_nodes.front().maximum_number_of_presets, Is().GreaterThan(10));
            // AssertThat(ptz_nodes.front().home_supported, Is().EqualTo(true));
        });

        it("Get ptz nodes test", [&]
        {
            Result result;
            PTZNode inc_node;

            for (auto& config: ptz_configurations)
            {
                tie(result, inc_node) = ptz.GetNode(information, config.node_token);

                AssertThat(result.is_error, Is().EqualTo(false));
                AssertThat(ptz_nodes.size(), Is().GreaterThan(0));
            }
        });
    });
});

using std::chrono::system_clock;
using std::chrono::seconds;

using std::chrono::duration_cast;
using std::cout;
using std::endl;

int main(int argc, char ** argv)
{
    auto start = system_clock::now();
    auto result = bandit::run(argc, argv);
    auto stop = system_clock::now();
    cout << "Time elapsed for all test: " 
         << duration_cast<seconds>(stop - start).count() << " seconds"
         << endl;
    return result;
}
