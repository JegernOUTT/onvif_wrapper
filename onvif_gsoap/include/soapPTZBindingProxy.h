/* soapPTZBindingProxy.h
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

#ifndef soapPTZBindingProxy_H
#define soapPTZBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC PTZBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        bool soap_own; ///< flag indicating that this context is owned by this proxy when context is shared
        /// Endpoint URL of service 'PTZBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvifgen/onvif.h, if any
        /// Construct a proxy with new managing context
        PTZBindingProxy();
        /// Copy constructor
        PTZBindingProxy(const PTZBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        PTZBindingProxy(struct soap*);
        /// Constructor taking an endpoint URL
        PTZBindingProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        PTZBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        PTZBindingProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        PTZBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~PTZBindingProxy();
        /// Initializer used by constructors
        virtual void PTZBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual PTZBindingProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        PTZBindingProxy& operator=(const PTZBindingProxy&);
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
        virtual int GetServiceCapabilities(_ns11__GetServiceCapabilities *ns11__GetServiceCapabilities, _ns11__GetServiceCapabilitiesResponse &ns11__GetServiceCapabilitiesResponse)
        { return this->GetServiceCapabilities(NULL, NULL, ns11__GetServiceCapabilities, ns11__GetServiceCapabilitiesResponse); }
        virtual int GetServiceCapabilities(const char *soap_endpoint, const char *soap_action, _ns11__GetServiceCapabilities *ns11__GetServiceCapabilities, _ns11__GetServiceCapabilitiesResponse &ns11__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetConfigurations' (returns SOAP_OK or error code)
        virtual int GetConfigurations(_ns11__GetConfigurations *ns11__GetConfigurations, _ns11__GetConfigurationsResponse &ns11__GetConfigurationsResponse)
        { return this->GetConfigurations(NULL, NULL, ns11__GetConfigurations, ns11__GetConfigurationsResponse); }
        virtual int GetConfigurations(const char *soap_endpoint, const char *soap_action, _ns11__GetConfigurations *ns11__GetConfigurations, _ns11__GetConfigurationsResponse &ns11__GetConfigurationsResponse);
        /// Web service operation 'GetPresets' (returns SOAP_OK or error code)
        virtual int GetPresets(_ns11__GetPresets *ns11__GetPresets, _ns11__GetPresetsResponse &ns11__GetPresetsResponse)
        { return this->GetPresets(NULL, NULL, ns11__GetPresets, ns11__GetPresetsResponse); }
        virtual int GetPresets(const char *soap_endpoint, const char *soap_action, _ns11__GetPresets *ns11__GetPresets, _ns11__GetPresetsResponse &ns11__GetPresetsResponse);
        /// Web service operation 'SetPreset' (returns SOAP_OK or error code)
        virtual int SetPreset(_ns11__SetPreset *ns11__SetPreset, _ns11__SetPresetResponse &ns11__SetPresetResponse)
        { return this->SetPreset(NULL, NULL, ns11__SetPreset, ns11__SetPresetResponse); }
        virtual int SetPreset(const char *soap_endpoint, const char *soap_action, _ns11__SetPreset *ns11__SetPreset, _ns11__SetPresetResponse &ns11__SetPresetResponse);
        /// Web service operation 'RemovePreset' (returns SOAP_OK or error code)
        virtual int RemovePreset(_ns11__RemovePreset *ns11__RemovePreset, _ns11__RemovePresetResponse &ns11__RemovePresetResponse)
        { return this->RemovePreset(NULL, NULL, ns11__RemovePreset, ns11__RemovePresetResponse); }
        virtual int RemovePreset(const char *soap_endpoint, const char *soap_action, _ns11__RemovePreset *ns11__RemovePreset, _ns11__RemovePresetResponse &ns11__RemovePresetResponse);
        /// Web service operation 'GotoPreset' (returns SOAP_OK or error code)
        virtual int GotoPreset(_ns11__GotoPreset *ns11__GotoPreset, _ns11__GotoPresetResponse &ns11__GotoPresetResponse)
        { return this->GotoPreset(NULL, NULL, ns11__GotoPreset, ns11__GotoPresetResponse); }
        virtual int GotoPreset(const char *soap_endpoint, const char *soap_action, _ns11__GotoPreset *ns11__GotoPreset, _ns11__GotoPresetResponse &ns11__GotoPresetResponse);
        /// Web service operation 'GetStatus' (returns SOAP_OK or error code)
        virtual int GetStatus(_ns11__GetStatus *ns11__GetStatus, _ns11__GetStatusResponse &ns11__GetStatusResponse)
        { return this->GetStatus(NULL, NULL, ns11__GetStatus, ns11__GetStatusResponse); }
        virtual int GetStatus(const char *soap_endpoint, const char *soap_action, _ns11__GetStatus *ns11__GetStatus, _ns11__GetStatusResponse &ns11__GetStatusResponse);
        /// Web service operation 'GetConfiguration' (returns SOAP_OK or error code)
        virtual int GetConfiguration(_ns11__GetConfiguration *ns11__GetConfiguration, _ns11__GetConfigurationResponse &ns11__GetConfigurationResponse)
        { return this->GetConfiguration(NULL, NULL, ns11__GetConfiguration, ns11__GetConfigurationResponse); }
        virtual int GetConfiguration(const char *soap_endpoint, const char *soap_action, _ns11__GetConfiguration *ns11__GetConfiguration, _ns11__GetConfigurationResponse &ns11__GetConfigurationResponse);
        /// Web service operation 'GetNodes' (returns SOAP_OK or error code)
        virtual int GetNodes(_ns11__GetNodes *ns11__GetNodes, _ns11__GetNodesResponse &ns11__GetNodesResponse)
        { return this->GetNodes(NULL, NULL, ns11__GetNodes, ns11__GetNodesResponse); }
        virtual int GetNodes(const char *soap_endpoint, const char *soap_action, _ns11__GetNodes *ns11__GetNodes, _ns11__GetNodesResponse &ns11__GetNodesResponse);
        /// Web service operation 'GetNode' (returns SOAP_OK or error code)
        virtual int GetNode(_ns11__GetNode *ns11__GetNode, _ns11__GetNodeResponse &ns11__GetNodeResponse)
        { return this->GetNode(NULL, NULL, ns11__GetNode, ns11__GetNodeResponse); }
        virtual int GetNode(const char *soap_endpoint, const char *soap_action, _ns11__GetNode *ns11__GetNode, _ns11__GetNodeResponse &ns11__GetNodeResponse);
        /// Web service operation 'SetConfiguration' (returns SOAP_OK or error code)
        virtual int SetConfiguration(_ns11__SetConfiguration *ns11__SetConfiguration, _ns11__SetConfigurationResponse &ns11__SetConfigurationResponse)
        { return this->SetConfiguration(NULL, NULL, ns11__SetConfiguration, ns11__SetConfigurationResponse); }
        virtual int SetConfiguration(const char *soap_endpoint, const char *soap_action, _ns11__SetConfiguration *ns11__SetConfiguration, _ns11__SetConfigurationResponse &ns11__SetConfigurationResponse);
        /// Web service operation 'GetConfigurationOptions' (returns SOAP_OK or error code)
        virtual int GetConfigurationOptions(_ns11__GetConfigurationOptions *ns11__GetConfigurationOptions, _ns11__GetConfigurationOptionsResponse &ns11__GetConfigurationOptionsResponse)
        { return this->GetConfigurationOptions(NULL, NULL, ns11__GetConfigurationOptions, ns11__GetConfigurationOptionsResponse); }
        virtual int GetConfigurationOptions(const char *soap_endpoint, const char *soap_action, _ns11__GetConfigurationOptions *ns11__GetConfigurationOptions, _ns11__GetConfigurationOptionsResponse &ns11__GetConfigurationOptionsResponse);
        /// Web service operation 'GotoHomePosition' (returns SOAP_OK or error code)
        virtual int GotoHomePosition(_ns11__GotoHomePosition *ns11__GotoHomePosition, _ns11__GotoHomePositionResponse &ns11__GotoHomePositionResponse)
        { return this->GotoHomePosition(NULL, NULL, ns11__GotoHomePosition, ns11__GotoHomePositionResponse); }
        virtual int GotoHomePosition(const char *soap_endpoint, const char *soap_action, _ns11__GotoHomePosition *ns11__GotoHomePosition, _ns11__GotoHomePositionResponse &ns11__GotoHomePositionResponse);
        /// Web service operation 'SetHomePosition' (returns SOAP_OK or error code)
        virtual int SetHomePosition(_ns11__SetHomePosition *ns11__SetHomePosition, _ns11__SetHomePositionResponse &ns11__SetHomePositionResponse)
        { return this->SetHomePosition(NULL, NULL, ns11__SetHomePosition, ns11__SetHomePositionResponse); }
        virtual int SetHomePosition(const char *soap_endpoint, const char *soap_action, _ns11__SetHomePosition *ns11__SetHomePosition, _ns11__SetHomePositionResponse &ns11__SetHomePositionResponse);
        /// Web service operation 'ContinuousMove' (returns SOAP_OK or error code)
        virtual int ContinuousMove(_ns11__ContinuousMove *ns11__ContinuousMove, _ns11__ContinuousMoveResponse &ns11__ContinuousMoveResponse)
        { return this->ContinuousMove(NULL, NULL, ns11__ContinuousMove, ns11__ContinuousMoveResponse); }
        virtual int ContinuousMove(const char *soap_endpoint, const char *soap_action, _ns11__ContinuousMove *ns11__ContinuousMove, _ns11__ContinuousMoveResponse &ns11__ContinuousMoveResponse);
        /// Web service operation 'RelativeMove' (returns SOAP_OK or error code)
        virtual int RelativeMove(_ns11__RelativeMove *ns11__RelativeMove, _ns11__RelativeMoveResponse &ns11__RelativeMoveResponse)
        { return this->RelativeMove(NULL, NULL, ns11__RelativeMove, ns11__RelativeMoveResponse); }
        virtual int RelativeMove(const char *soap_endpoint, const char *soap_action, _ns11__RelativeMove *ns11__RelativeMove, _ns11__RelativeMoveResponse &ns11__RelativeMoveResponse);
        /// Web service operation 'SendAuxiliaryCommand' (returns SOAP_OK or error code)
        virtual int SendAuxiliaryCommand(_ns11__SendAuxiliaryCommand *ns11__SendAuxiliaryCommand, _ns11__SendAuxiliaryCommandResponse &ns11__SendAuxiliaryCommandResponse)
        { return this->SendAuxiliaryCommand(NULL, NULL, ns11__SendAuxiliaryCommand, ns11__SendAuxiliaryCommandResponse); }
        virtual int SendAuxiliaryCommand(const char *soap_endpoint, const char *soap_action, _ns11__SendAuxiliaryCommand *ns11__SendAuxiliaryCommand, _ns11__SendAuxiliaryCommandResponse &ns11__SendAuxiliaryCommandResponse);
        /// Web service operation 'AbsoluteMove' (returns SOAP_OK or error code)
        virtual int AbsoluteMove(_ns11__AbsoluteMove *ns11__AbsoluteMove, _ns11__AbsoluteMoveResponse &ns11__AbsoluteMoveResponse)
        { return this->AbsoluteMove(NULL, NULL, ns11__AbsoluteMove, ns11__AbsoluteMoveResponse); }
        virtual int AbsoluteMove(const char *soap_endpoint, const char *soap_action, _ns11__AbsoluteMove *ns11__AbsoluteMove, _ns11__AbsoluteMoveResponse &ns11__AbsoluteMoveResponse);
        /// Web service operation 'Stop' (returns SOAP_OK or error code)
        virtual int Stop(_ns11__Stop *ns11__Stop, _ns11__StopResponse &ns11__StopResponse)
        { return this->Stop(NULL, NULL, ns11__Stop, ns11__StopResponse); }
        virtual int Stop(const char *soap_endpoint, const char *soap_action, _ns11__Stop *ns11__Stop, _ns11__StopResponse &ns11__StopResponse);
        /// Web service operation 'GetPresetTours' (returns SOAP_OK or error code)
        virtual int GetPresetTours(_ns11__GetPresetTours *ns11__GetPresetTours, _ns11__GetPresetToursResponse &ns11__GetPresetToursResponse)
        { return this->GetPresetTours(NULL, NULL, ns11__GetPresetTours, ns11__GetPresetToursResponse); }
        virtual int GetPresetTours(const char *soap_endpoint, const char *soap_action, _ns11__GetPresetTours *ns11__GetPresetTours, _ns11__GetPresetToursResponse &ns11__GetPresetToursResponse);
        /// Web service operation 'GetPresetTour' (returns SOAP_OK or error code)
        virtual int GetPresetTour(_ns11__GetPresetTour *ns11__GetPresetTour, _ns11__GetPresetTourResponse &ns11__GetPresetTourResponse)
        { return this->GetPresetTour(NULL, NULL, ns11__GetPresetTour, ns11__GetPresetTourResponse); }
        virtual int GetPresetTour(const char *soap_endpoint, const char *soap_action, _ns11__GetPresetTour *ns11__GetPresetTour, _ns11__GetPresetTourResponse &ns11__GetPresetTourResponse);
        /// Web service operation 'GetPresetTourOptions' (returns SOAP_OK or error code)
        virtual int GetPresetTourOptions(_ns11__GetPresetTourOptions *ns11__GetPresetTourOptions, _ns11__GetPresetTourOptionsResponse &ns11__GetPresetTourOptionsResponse)
        { return this->GetPresetTourOptions(NULL, NULL, ns11__GetPresetTourOptions, ns11__GetPresetTourOptionsResponse); }
        virtual int GetPresetTourOptions(const char *soap_endpoint, const char *soap_action, _ns11__GetPresetTourOptions *ns11__GetPresetTourOptions, _ns11__GetPresetTourOptionsResponse &ns11__GetPresetTourOptionsResponse);
        /// Web service operation 'CreatePresetTour' (returns SOAP_OK or error code)
        virtual int CreatePresetTour(_ns11__CreatePresetTour *ns11__CreatePresetTour, _ns11__CreatePresetTourResponse &ns11__CreatePresetTourResponse)
        { return this->CreatePresetTour(NULL, NULL, ns11__CreatePresetTour, ns11__CreatePresetTourResponse); }
        virtual int CreatePresetTour(const char *soap_endpoint, const char *soap_action, _ns11__CreatePresetTour *ns11__CreatePresetTour, _ns11__CreatePresetTourResponse &ns11__CreatePresetTourResponse);
        /// Web service operation 'ModifyPresetTour' (returns SOAP_OK or error code)
        virtual int ModifyPresetTour(_ns11__ModifyPresetTour *ns11__ModifyPresetTour, _ns11__ModifyPresetTourResponse &ns11__ModifyPresetTourResponse)
        { return this->ModifyPresetTour(NULL, NULL, ns11__ModifyPresetTour, ns11__ModifyPresetTourResponse); }
        virtual int ModifyPresetTour(const char *soap_endpoint, const char *soap_action, _ns11__ModifyPresetTour *ns11__ModifyPresetTour, _ns11__ModifyPresetTourResponse &ns11__ModifyPresetTourResponse);
        /// Web service operation 'OperatePresetTour' (returns SOAP_OK or error code)
        virtual int OperatePresetTour(_ns11__OperatePresetTour *ns11__OperatePresetTour, _ns11__OperatePresetTourResponse &ns11__OperatePresetTourResponse)
        { return this->OperatePresetTour(NULL, NULL, ns11__OperatePresetTour, ns11__OperatePresetTourResponse); }
        virtual int OperatePresetTour(const char *soap_endpoint, const char *soap_action, _ns11__OperatePresetTour *ns11__OperatePresetTour, _ns11__OperatePresetTourResponse &ns11__OperatePresetTourResponse);
        /// Web service operation 'RemovePresetTour' (returns SOAP_OK or error code)
        virtual int RemovePresetTour(_ns11__RemovePresetTour *ns11__RemovePresetTour, _ns11__RemovePresetTourResponse &ns11__RemovePresetTourResponse)
        { return this->RemovePresetTour(NULL, NULL, ns11__RemovePresetTour, ns11__RemovePresetTourResponse); }
        virtual int RemovePresetTour(const char *soap_endpoint, const char *soap_action, _ns11__RemovePresetTour *ns11__RemovePresetTour, _ns11__RemovePresetTourResponse &ns11__RemovePresetTourResponse);
        /// Web service operation 'GetCompatibleConfigurations' (returns SOAP_OK or error code)
        virtual int GetCompatibleConfigurations(_ns11__GetCompatibleConfigurations *ns11__GetCompatibleConfigurations, _ns11__GetCompatibleConfigurationsResponse &ns11__GetCompatibleConfigurationsResponse)
        { return this->GetCompatibleConfigurations(NULL, NULL, ns11__GetCompatibleConfigurations, ns11__GetCompatibleConfigurationsResponse); }
        virtual int GetCompatibleConfigurations(const char *soap_endpoint, const char *soap_action, _ns11__GetCompatibleConfigurations *ns11__GetCompatibleConfigurations, _ns11__GetCompatibleConfigurationsResponse &ns11__GetCompatibleConfigurationsResponse);
    };
#endif