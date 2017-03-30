/* soapImagingBindingProxy.h
   Generated by gSOAP 2.8.40 for onvifgen/onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapImagingBindingProxy_H
#define soapImagingBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC ImagingBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'ImagingBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvifgen/onvif.h, if any
        /// Construct a proxy with new managing context
        ImagingBindingProxy();
        /// Copy constructor
        ImagingBindingProxy(const ImagingBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        ImagingBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        ImagingBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        ImagingBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        ImagingBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        ImagingBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~ImagingBindingProxy();
        /// Initializer used by constructors
        virtual void ImagingBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual ImagingBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        ImagingBindingProxy& operator=(const ImagingBindingProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Add SOAP Header to message
        virtual void soap_header(struct _wsse__Security *wsse__Security);
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault string (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail as string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Web service operation 'GetServiceCapabilities' (returns SOAP_OK or error code)
        virtual int GetServiceCapabilities(_ns8__GetServiceCapabilities *ns8__GetServiceCapabilities, _ns8__GetServiceCapabilitiesResponse &ns8__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, ns8__GetServiceCapabilities, ns8__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _ns8__GetServiceCapabilities *ns8__GetServiceCapabilities, _ns8__GetServiceCapabilitiesResponse &ns8__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetImagingSettings' (returns SOAP_OK or error code)
        virtual int GetImagingSettings(_ns8__GetImagingSettings *ns8__GetImagingSettings, _ns8__GetImagingSettingsResponse &ns8__GetImagingSettingsResponse)
        { return this->GetImagingSettings(NULL, NULL, ns8__GetImagingSettings, ns8__GetImagingSettingsResponse); }
        virtual int GetImagingSettings(const char *soap_endpoint, const char *soap_action, _ns8__GetImagingSettings *ns8__GetImagingSettings, _ns8__GetImagingSettingsResponse &ns8__GetImagingSettingsResponse);
        /// Web service operation 'SetImagingSettings' (returns SOAP_OK or error code)
        virtual int SetImagingSettings(_ns8__SetImagingSettings *ns8__SetImagingSettings, _ns8__SetImagingSettingsResponse &ns8__SetImagingSettingsResponse)
        { return this->SetImagingSettings(NULL, NULL, ns8__SetImagingSettings, ns8__SetImagingSettingsResponse); }
        virtual int SetImagingSettings(const char *soap_endpoint, const char *soap_action, _ns8__SetImagingSettings *ns8__SetImagingSettings, _ns8__SetImagingSettingsResponse &ns8__SetImagingSettingsResponse);
        /// Web service operation 'GetOptions' (returns SOAP_OK or error code)
        virtual int GetOptions(_ns8__GetOptions *ns8__GetOptions, _ns8__GetOptionsResponse &ns8__GetOptionsResponse)
        { return this->GetOptions(NULL, NULL, ns8__GetOptions, ns8__GetOptionsResponse); }
        virtual int GetOptions(const char *soap_endpoint, const char *soap_action, _ns8__GetOptions *ns8__GetOptions, _ns8__GetOptionsResponse &ns8__GetOptionsResponse);
        /// Web service operation 'Move' (returns SOAP_OK or error code)
        virtual int Move(_ns8__Move *ns8__Move, _ns8__MoveResponse &ns8__MoveResponse)
        { return this->Move(NULL, NULL, ns8__Move, ns8__MoveResponse); }
        virtual int Move(const char *soap_endpoint, const char *soap_action, _ns8__Move *ns8__Move, _ns8__MoveResponse &ns8__MoveResponse);
        /// Web service operation 'Stop' (returns SOAP_OK or error code)
        virtual int Stop(_ns8__Stop *ns8__Stop, _ns8__StopResponse &ns8__StopResponse)
        { return this->Stop(NULL, NULL, ns8__Stop, ns8__StopResponse); }
        virtual int Stop(const char *soap_endpoint, const char *soap_action, _ns8__Stop *ns8__Stop, _ns8__StopResponse &ns8__StopResponse);
        /// Web service operation 'GetStatus' (returns SOAP_OK or error code)
        virtual int GetStatus(_ns8__GetStatus *ns8__GetStatus, _ns8__GetStatusResponse &ns8__GetStatusResponse)
        { return this->GetStatus(NULL, NULL, ns8__GetStatus, ns8__GetStatusResponse); }
        virtual int GetStatus(const char *soap_endpoint, const char *soap_action, _ns8__GetStatus *ns8__GetStatus, _ns8__GetStatusResponse &ns8__GetStatusResponse);
        /// Web service operation 'GetMoveOptions' (returns SOAP_OK or error code)
        virtual int GetMoveOptions(_ns8__GetMoveOptions *ns8__GetMoveOptions, _ns8__GetMoveOptionsResponse &ns8__GetMoveOptionsResponse)
        { return this->GetMoveOptions(NULL, NULL, ns8__GetMoveOptions, ns8__GetMoveOptionsResponse); }
        virtual int GetMoveOptions(const char *soap_endpoint, const char *soap_action, _ns8__GetMoveOptions *ns8__GetMoveOptions, _ns8__GetMoveOptionsResponse &ns8__GetMoveOptionsResponse);
        /// Web service operation 'GetPresets' (returns SOAP_OK or error code)
        virtual int GetPresets(_ns8__GetPresets *ns8__GetPresets, _ns8__GetPresetsResponse &ns8__GetPresetsResponse)
        { return this->GetPresets(NULL, NULL, ns8__GetPresets, ns8__GetPresetsResponse); }
        virtual int GetPresets(const char *soap_endpoint, const char *soap_action, _ns8__GetPresets *ns8__GetPresets, _ns8__GetPresetsResponse &ns8__GetPresetsResponse);
        /// Web service operation 'GetCurrentPreset' (returns SOAP_OK or error code)
        virtual int GetCurrentPreset(_ns8__GetCurrentPreset *ns8__GetCurrentPreset, _ns8__GetCurrentPresetResponse &ns8__GetCurrentPresetResponse)
        { return this->GetCurrentPreset(NULL, NULL, ns8__GetCurrentPreset, ns8__GetCurrentPresetResponse); }
        virtual int GetCurrentPreset(const char *soap_endpoint, const char *soap_action, _ns8__GetCurrentPreset *ns8__GetCurrentPreset, _ns8__GetCurrentPresetResponse &ns8__GetCurrentPresetResponse);
        /// Web service operation 'SetCurrentPreset' (returns SOAP_OK or error code)
        virtual int SetCurrentPreset(_ns8__SetCurrentPreset *ns8__SetCurrentPreset, _ns8__SetCurrentPresetResponse &ns8__SetCurrentPresetResponse)
        { return this->SetCurrentPreset(NULL, NULL, ns8__SetCurrentPreset, ns8__SetCurrentPresetResponse); }
        virtual int SetCurrentPreset(const char *soap_endpoint, const char *soap_action, _ns8__SetCurrentPreset *ns8__SetCurrentPreset, _ns8__SetCurrentPresetResponse &ns8__SetCurrentPresetResponse);
    };
#endif