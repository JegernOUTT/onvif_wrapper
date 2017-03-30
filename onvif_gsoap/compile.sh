#!/bin/bash

# Full onvif schema list
#
# http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl
# http://www.onvif.org/onvif/ver10/display.wsdl
# http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl
# http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl
# http://www.onvif.org/onvif/ver20/media/wsdl/media.wsdl
# http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl
# http://www.onvif.org/ver10/credential/wsdl/credential.wsdl
# http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl
# http://www.onvif.org/onvif/ver10/deviceio.wsdl
# http://www.onvif.org/onvif/ver10/receiver.wsdl
# http://www.onvif.org/onvif/ver10/recording.wsdl
# http://www.onvif.org/onvif/ver10/search.wsdl
# http://www.onvif.org/onvif/ver10/replay.wsdl
# http://www.onvif.org/onvif/ver20/analytics/wsdl/analytics.wsdl
# http://www.onvif.org/onvif/ver10/analyticsdevice.wsdl
# http://www.onvif.org/ver10/actionengine.wsdl
# http://www.onvif.org/ver10/pacs/accesscontrol.wsdl
# http://www.onvif.org/ver10/pacs/doorcontrol.wsdl
# http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl
# http://www.onvif.org/ver10/accessrules/wsdl/accessrules.wsdl
# http://www.onvif.org/ver10/schedule/wsdl/schedule.wsdl

mkdir onvifgen

wsdl2h -dPc++11 -t "3rdParty/goap-2.8/gsoap/typemap.dat" -o "onvifgen/onvif.h" http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl http://www.onvif.org/onvif/ver10/display.wsdl http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl http://www.onvif.org/ver10/credential/wsdl/credential.wsdl http://www.w3.org/2006/03/addressing/ws-addr.xsd 

echo Need to add import wsse.h into onvif.h
echo Press any key after adding it

soapcpp2 -j2Cxc++11 -d "onvifgen" -I"3rdparty/gsoap-2.8/gsoap/;3rdparty/gsoap-2.8/gsoap/import" "onvifgen/onvif.h"
