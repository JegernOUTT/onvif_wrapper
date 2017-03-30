#pragma once

#include "OnvifPod.hpp"
#include "Utility.hpp"

namespace onvifwrapper
{
	class ErrorWrap
	{
	public:
        template<typename Soap>
		static Result Wrap(int32_t error, Soap* s)
		{
            string full_error = "Timeout error";
            if (s && s->labbuf)
                full_error = s->labbuf;
			if (error == 0)
				return { false, error, FromSoapError(error), full_error  };
		    return { true, error, FromSoapError(error), full_error };
		}

	private :
		static string FromSoapError(int32_t status)
		{
			switch (status)
			{
			case -1: return "SOAP_EOF";
			case 0: return "SOAP_OK";
			case 1: return "SOAP_CLI_FAULT";
			case 2: return "SOAP_SVR_FAULT";
			case 3: return "SOAP_TAG_MISMATCH";
			case 4: return "SOAP_TYPE";
			case 5: return "SOAP_SYNTAX_ERROR";
			case 6: return "SOAP_NO_TAG";
			case 7: return "SOAP_IOB";
			case 8: return "SOAP_MUSTUNDERSTAND";
			case 9: return "SOAP_NAMESPACE";
			case 10: return "SOAP_USER_ERROR";
			case 11: return "SOAP_FATAL_ERROR";
			case 12: return "SOAP_FAULT";
			case 13: return "SOAP_NO_METHOD";
			case 14: return "SOAP_NO_DATA";
			case 15: return "SOAP_GET_METHOD";
			case 16: return "SOAP_PUT_METHOD";
			case 19: return "SOAP_HTTP_METHOD";
			case 20: return "SOAP_EOM";
			case 21: return "SOAP_MOE";
			case 22: return "SOAP_HDR";
			case 23: return "SOAP_NULL";
			case 24: return "SOAP_DUPLICATE_ID";
			case 25: return "SOAP_MISSING_ID";
			case 26: return "SOAP_HREF";
			case 27: return "SOAP_UDP_ERROR";
			case 28: return "SOAP_TCP_ERROR";
			case 29: return "SOAP_HTTP_ERROR";
			case 30: return "SOAP_SSL_ERROR";
			case 31: return "SOAP_ZLIB_ERROR";
			case 32: return "SOAP_DIME_ERROR";
			case 33: return "SOAP_DIME_HREF";
			case 34: return "SOAP_DIME_MISMATCH";
			case 35: return "SOAP_DIME_END";
			case 36: return "SOAP_MIME_ERROR";
			case 37: return "SOAP_MIME_HREF";
			case 38: return "SOAP_MIME_END";
			case 39: return "SOAP_PLUGIN_ERROR";
			case 40: return "SOAP_VERSIONMISMATCH";
			case 41: return "SOAP_DATAENCODINGUNKNOWN";
			case 42: return "SOAP_REQUIRED";
			case 43: return "SOAP_PROHIBITED";
			case 44: return "SOAP_OCCURS";
			case 45: return "SOAP_LENGTH";
			case 46: return "SOAP_PATTERN";
			case 47: return "SOAP_FD_EXCEEDED";
			case 48: return "SOAP_UTF_ERROR";
			case 49: return "SOAP_NTLM_ERROR";
			case 50: return "SOAP_LEVEL";
			default: return "Unknown error";
			}
		}
	};
}
