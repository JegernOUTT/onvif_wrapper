/* soapDisplayBindingProxy.cpp
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

#include "soapDisplayBindingProxy.h"

DisplayBindingProxy::DisplayBindingProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	DisplayBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

DisplayBindingProxy::DisplayBindingProxy(const DisplayBindingProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

DisplayBindingProxy::DisplayBindingProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	DisplayBindingProxy_init(_soap->imode, _soap->omode);
}

DisplayBindingProxy::DisplayBindingProxy(const char *endpoint)
{	this->soap = soap_new();
	this->soap_own = true;
	DisplayBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = endpoint;
}

DisplayBindingProxy::DisplayBindingProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	DisplayBindingProxy_init(iomode, iomode);
}

DisplayBindingProxy::DisplayBindingProxy(const char *endpoint, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	DisplayBindingProxy_init(iomode, iomode);
	soap_endpoint = endpoint;
}

DisplayBindingProxy::DisplayBindingProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	DisplayBindingProxy_init(imode, omode);
}

DisplayBindingProxy::~DisplayBindingProxy()
{	if (this->soap_own)
		soap_free(this->soap);
}

void DisplayBindingProxy::DisplayBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
        {"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"c14n", "http://www.w3.org/2001/10/xml-exc-c14n#", NULL, NULL},
        {"ds", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL},
        {"saml1", "urn:oasis:names:tc:SAML:1.0:assertion", NULL, NULL},
        {"saml2", "urn:oasis:names:tc:SAML:2.0:assertion", NULL, NULL},
        {"wsu", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd", NULL, NULL},
        {"xenc", "http://www.w3.org/2001/04/xmlenc#", NULL, NULL},
        {"wsc", "http://docs.oasis-open.org/ws-sx/ws-secureconversation/200512", NULL, NULL},
        {"wsse", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd", "http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd", NULL},
        {"ns13", "http://www.onvif.org/ver10/pacs", NULL, NULL},
        {"ns14", "http://www.w3.org/2005/08/addressing", NULL, NULL},
        {"xmime", "http://www.w3.org/2005/05/xmlmime", NULL, NULL},
        {"ns4", "http://www.w3.org/2004/08/xop/include", NULL, NULL},
        {"ns2", "http://www.onvif.org/ver10/schema", NULL, NULL},
        {"ns3", "http://docs.oasis-open.org/wsn/b-2", NULL, NULL},
        {"ns5", "http://docs.oasis-open.org/wsrf/bf-2", NULL, NULL},
        {"ns6", "http://docs.oasis-open.org/wsn/t-1", NULL, NULL},
        {"ns1", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL},
        {"ns10", "http://www.onvif.org/ver20/media/wsdl", NULL, NULL},
        {"ns11", "http://www.onvif.org/ver20/ptz/wsdl", NULL, NULL},
        {"ns12", "http://www.onvif.org/ver10/credential/wsdl", NULL, NULL},
        {"ns7", "http://www.onvif.org/ver10/display/wsdl", NULL, NULL},
        {"ns8", "http://www.onvif.org/ver20/imaging/wsdl", NULL, NULL},
        {"ns9", "http://www.onvif.org/ver10/media/wsdl", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

#ifndef WITH_PURE_VIRTUAL
DisplayBindingProxy *DisplayBindingProxy::copy()
{	DisplayBindingProxy *dup = SOAP_NEW_COPY(DisplayBindingProxy);
	if (dup)
		soap_copy_context(dup->soap, this->soap);
	return dup;
}
#endif

DisplayBindingProxy& DisplayBindingProxy::operator=(const DisplayBindingProxy& rhs)
{	if (this->soap_own)
		soap_free(this->soap);
	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
	return *this;
}

void DisplayBindingProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void DisplayBindingProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	DisplayBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void DisplayBindingProxy::soap_noheader()
{	this->soap->header = NULL;
}

void DisplayBindingProxy::soap_header(struct _wsse__Security *wsse__Security)
{	::soap_header(this->soap);
	this->soap->header->wsse__Security = wsse__Security;
}

::SOAP_ENV__Header *DisplayBindingProxy::soap_header()
{	return this->soap->header;
}

::SOAP_ENV__Fault *DisplayBindingProxy::soap_fault()
{	return this->soap->fault;
}

const char *DisplayBindingProxy::soap_fault_string()
{	return *soap_faultstring(this->soap);
}

const char *DisplayBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this->soap);
}

int DisplayBindingProxy::soap_close_socket()
{	return soap_closesock(this->soap);
}

int DisplayBindingProxy::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

void DisplayBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void DisplayBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *DisplayBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int DisplayBindingProxy::GetServiceCapabilities(const char *endpoint, const char *soap_action, _ns7__GetServiceCapabilities *ns7__GetServiceCapabilities, _ns7__GetServiceCapabilitiesResponse &ns7__GetServiceCapabilitiesResponse)
{	struct soap *soap = this->soap;
	struct __ns7__GetServiceCapabilities soap_tmp___ns7__GetServiceCapabilities;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/GetServiceCapabilities";
	soap_tmp___ns7__GetServiceCapabilities.ns7__GetServiceCapabilities = ns7__GetServiceCapabilities;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__GetServiceCapabilities(soap, &soap_tmp___ns7__GetServiceCapabilities);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__GetServiceCapabilities(soap, &soap_tmp___ns7__GetServiceCapabilities, "-ns7:GetServiceCapabilities", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__GetServiceCapabilities(soap, &soap_tmp___ns7__GetServiceCapabilities, "-ns7:GetServiceCapabilities", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__GetServiceCapabilitiesResponse*>(&ns7__GetServiceCapabilitiesResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__GetServiceCapabilitiesResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__GetServiceCapabilitiesResponse.soap_get(soap, "ns7:GetServiceCapabilitiesResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::GetLayout(const char *endpoint, const char *soap_action, _ns7__GetLayout *ns7__GetLayout, _ns7__GetLayoutResponse &ns7__GetLayoutResponse)
{	struct soap *soap = this->soap;
	struct __ns7__GetLayout soap_tmp___ns7__GetLayout;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/GetLayout";
	soap_tmp___ns7__GetLayout.ns7__GetLayout = ns7__GetLayout;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__GetLayout(soap, &soap_tmp___ns7__GetLayout);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__GetLayout(soap, &soap_tmp___ns7__GetLayout, "-ns7:GetLayout", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__GetLayout(soap, &soap_tmp___ns7__GetLayout, "-ns7:GetLayout", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__GetLayoutResponse*>(&ns7__GetLayoutResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__GetLayoutResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__GetLayoutResponse.soap_get(soap, "ns7:GetLayoutResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::SetLayout(const char *endpoint, const char *soap_action, _ns7__SetLayout *ns7__SetLayout, _ns7__SetLayoutResponse &ns7__SetLayoutResponse)
{	struct soap *soap = this->soap;
	struct __ns7__SetLayout soap_tmp___ns7__SetLayout;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/SetLayout";
	soap_tmp___ns7__SetLayout.ns7__SetLayout = ns7__SetLayout;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__SetLayout(soap, &soap_tmp___ns7__SetLayout);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__SetLayout(soap, &soap_tmp___ns7__SetLayout, "-ns7:SetLayout", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__SetLayout(soap, &soap_tmp___ns7__SetLayout, "-ns7:SetLayout", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__SetLayoutResponse*>(&ns7__SetLayoutResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__SetLayoutResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__SetLayoutResponse.soap_get(soap, "ns7:SetLayoutResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::GetDisplayOptions(const char *endpoint, const char *soap_action, _ns7__GetDisplayOptions *ns7__GetDisplayOptions, _ns7__GetDisplayOptionsResponse &ns7__GetDisplayOptionsResponse)
{	struct soap *soap = this->soap;
	struct __ns7__GetDisplayOptions soap_tmp___ns7__GetDisplayOptions;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/GetDisplayOptions";
	soap_tmp___ns7__GetDisplayOptions.ns7__GetDisplayOptions = ns7__GetDisplayOptions;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__GetDisplayOptions(soap, &soap_tmp___ns7__GetDisplayOptions);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__GetDisplayOptions(soap, &soap_tmp___ns7__GetDisplayOptions, "-ns7:GetDisplayOptions", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__GetDisplayOptions(soap, &soap_tmp___ns7__GetDisplayOptions, "-ns7:GetDisplayOptions", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__GetDisplayOptionsResponse*>(&ns7__GetDisplayOptionsResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__GetDisplayOptionsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__GetDisplayOptionsResponse.soap_get(soap, "ns7:GetDisplayOptionsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::GetPaneConfigurations(const char *endpoint, const char *soap_action, _ns7__GetPaneConfigurations *ns7__GetPaneConfigurations, _ns7__GetPaneConfigurationsResponse &ns7__GetPaneConfigurationsResponse)
{	struct soap *soap = this->soap;
	struct __ns7__GetPaneConfigurations soap_tmp___ns7__GetPaneConfigurations;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/GetPaneConfigurations";
	soap_tmp___ns7__GetPaneConfigurations.ns7__GetPaneConfigurations = ns7__GetPaneConfigurations;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__GetPaneConfigurations(soap, &soap_tmp___ns7__GetPaneConfigurations);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__GetPaneConfigurations(soap, &soap_tmp___ns7__GetPaneConfigurations, "-ns7:GetPaneConfigurations", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__GetPaneConfigurations(soap, &soap_tmp___ns7__GetPaneConfigurations, "-ns7:GetPaneConfigurations", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__GetPaneConfigurationsResponse*>(&ns7__GetPaneConfigurationsResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__GetPaneConfigurationsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__GetPaneConfigurationsResponse.soap_get(soap, "ns7:GetPaneConfigurationsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::GetPaneConfiguration(const char *endpoint, const char *soap_action, _ns7__GetPaneConfiguration *ns7__GetPaneConfiguration, _ns7__GetPaneConfigurationResponse &ns7__GetPaneConfigurationResponse)
{	struct soap *soap = this->soap;
	struct __ns7__GetPaneConfiguration soap_tmp___ns7__GetPaneConfiguration;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/GetPaneConfiguration";
	soap_tmp___ns7__GetPaneConfiguration.ns7__GetPaneConfiguration = ns7__GetPaneConfiguration;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__GetPaneConfiguration(soap, &soap_tmp___ns7__GetPaneConfiguration);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__GetPaneConfiguration(soap, &soap_tmp___ns7__GetPaneConfiguration, "-ns7:GetPaneConfiguration", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__GetPaneConfiguration(soap, &soap_tmp___ns7__GetPaneConfiguration, "-ns7:GetPaneConfiguration", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__GetPaneConfigurationResponse*>(&ns7__GetPaneConfigurationResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__GetPaneConfigurationResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__GetPaneConfigurationResponse.soap_get(soap, "ns7:GetPaneConfigurationResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::SetPaneConfigurations(const char *endpoint, const char *soap_action, _ns7__SetPaneConfigurations *ns7__SetPaneConfigurations, _ns7__SetPaneConfigurationsResponse &ns7__SetPaneConfigurationsResponse)
{	struct soap *soap = this->soap;
	struct __ns7__SetPaneConfigurations soap_tmp___ns7__SetPaneConfigurations;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/SetPaneConfigurations";
	soap_tmp___ns7__SetPaneConfigurations.ns7__SetPaneConfigurations = ns7__SetPaneConfigurations;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__SetPaneConfigurations(soap, &soap_tmp___ns7__SetPaneConfigurations);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__SetPaneConfigurations(soap, &soap_tmp___ns7__SetPaneConfigurations, "-ns7:SetPaneConfigurations", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__SetPaneConfigurations(soap, &soap_tmp___ns7__SetPaneConfigurations, "-ns7:SetPaneConfigurations", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__SetPaneConfigurationsResponse*>(&ns7__SetPaneConfigurationsResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__SetPaneConfigurationsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__SetPaneConfigurationsResponse.soap_get(soap, "ns7:SetPaneConfigurationsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::SetPaneConfiguration(const char *endpoint, const char *soap_action, _ns7__SetPaneConfiguration *ns7__SetPaneConfiguration, _ns7__SetPaneConfigurationResponse &ns7__SetPaneConfigurationResponse)
{	struct soap *soap = this->soap;
	struct __ns7__SetPaneConfiguration soap_tmp___ns7__SetPaneConfiguration;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/SetPaneConfiguration";
	soap_tmp___ns7__SetPaneConfiguration.ns7__SetPaneConfiguration = ns7__SetPaneConfiguration;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__SetPaneConfiguration(soap, &soap_tmp___ns7__SetPaneConfiguration);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__SetPaneConfiguration(soap, &soap_tmp___ns7__SetPaneConfiguration, "-ns7:SetPaneConfiguration", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__SetPaneConfiguration(soap, &soap_tmp___ns7__SetPaneConfiguration, "-ns7:SetPaneConfiguration", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__SetPaneConfigurationResponse*>(&ns7__SetPaneConfigurationResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__SetPaneConfigurationResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__SetPaneConfigurationResponse.soap_get(soap, "ns7:SetPaneConfigurationResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::CreatePaneConfiguration(const char *endpoint, const char *soap_action, _ns7__CreatePaneConfiguration *ns7__CreatePaneConfiguration, _ns7__CreatePaneConfigurationResponse &ns7__CreatePaneConfigurationResponse)
{	struct soap *soap = this->soap;
	struct __ns7__CreatePaneConfiguration soap_tmp___ns7__CreatePaneConfiguration;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/CreatePaneConfiguration";
	soap_tmp___ns7__CreatePaneConfiguration.ns7__CreatePaneConfiguration = ns7__CreatePaneConfiguration;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__CreatePaneConfiguration(soap, &soap_tmp___ns7__CreatePaneConfiguration);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__CreatePaneConfiguration(soap, &soap_tmp___ns7__CreatePaneConfiguration, "-ns7:CreatePaneConfiguration", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__CreatePaneConfiguration(soap, &soap_tmp___ns7__CreatePaneConfiguration, "-ns7:CreatePaneConfiguration", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__CreatePaneConfigurationResponse*>(&ns7__CreatePaneConfigurationResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__CreatePaneConfigurationResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__CreatePaneConfigurationResponse.soap_get(soap, "ns7:CreatePaneConfigurationResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DisplayBindingProxy::DeletePaneConfiguration(const char *endpoint, const char *soap_action, _ns7__DeletePaneConfiguration *ns7__DeletePaneConfiguration, _ns7__DeletePaneConfigurationResponse &ns7__DeletePaneConfigurationResponse)
{	struct soap *soap = this->soap;
	struct __ns7__DeletePaneConfiguration soap_tmp___ns7__DeletePaneConfiguration;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/display/wsdl/DeletePaneConfiguration";
	soap_tmp___ns7__DeletePaneConfiguration.ns7__DeletePaneConfiguration = ns7__DeletePaneConfiguration;
	soap_begin(soap);
	soap_set_version(soap, 2); /* SOAP1.2 */
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize___ns7__DeletePaneConfiguration(soap, &soap_tmp___ns7__DeletePaneConfiguration);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns7__DeletePaneConfiguration(soap, &soap_tmp___ns7__DeletePaneConfiguration, "-ns7:DeletePaneConfiguration", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns7__DeletePaneConfiguration(soap, &soap_tmp___ns7__DeletePaneConfiguration, "-ns7:DeletePaneConfiguration", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_ns7__DeletePaneConfigurationResponse*>(&ns7__DeletePaneConfigurationResponse)) // NULL ref?
		return soap_closesock(soap);
	ns7__DeletePaneConfigurationResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns7__DeletePaneConfigurationResponse.soap_get(soap, "ns7:DeletePaneConfigurationResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */