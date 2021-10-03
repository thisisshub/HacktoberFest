#include <CkRest.h>
#include <CkJsonObject.h>

void ChilkatSample(void)
    {
    //  This example requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  The IP address used in this example is 104.40.211.35
    const char *ipAddress = "104.40.211.35";

    //  First we'll try the service at freegeoip.net.
    //  They have a limit of 10,000 queries per hour, and also
    //  provide free source code to run your own server.

    CkRest rest;

    //  Connect to freegeoip.net
    bool bTls = false;
    int port = 80;
    bool bAutoReconnect = true;
    bool success = rest.Connect("freegeoip.net",port,bTls,bAutoReconnect);
    if (success == false) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  Query the IP address to return JSON.
    const char *responseJson = rest.fullRequestNoBody("GET","/json/104.40.211.35");
    if (rest.get_LastMethodSuccess() != true) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  Just in case we are still connected..
    int maxWaitMs = 10;
    rest.Disconnect(maxWaitMs);

    CkJsonObject json;
    json.Load(responseJson);
    json.put_EmitCompact(false);

    std::cout << json.emit() << "\r\n";

    //  The JSON we get back looks like this:
    //  {
//   "ip": "104.40.211.35",
    //    "country_code": "US",
    //    "country_name": "United States",
    //    "region_code": "WA",
    //    "region_name": "Washington",
    //    "city": "Redmond",
    //    "zip_code": "98052",
    //    "time_zone": "America/Los_Angeles",
    //    "latitude": 47.6801,
    //    "longitude": -122.1206,
    //    "metro_code": 819
    //  }

    //  Examine a few bits of information:
    std::cout << "country name = " << json.stringOf("country_name") << "\r\n";
    std::cout << "country code = " << json.stringOf("country_code") << "\r\n";

    //  -----------------------------------------------------
    //  Now to use ip-api.com, which is mostly the same..

    success = rest.Connect("ip-api.com",port,bTls,bAutoReconnect);
    if (success == false) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  Query the IP address to return JSON.
    responseJson = rest.fullRequestNoBody("GET","/json/104.40.211.35");
    if (rest.get_LastMethodSuccess() != true) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  Just in case we are still connected..
    rest.Disconnect(maxWaitMs);

    json.Load(responseJson);
    json.put_EmitCompact(false);

    std::cout << json.emit() << "\r\n";

    //  The JSON we get back looks like this:
    //  This is very strange, because the two services don't agree.
    //  {
//   "as": "AS8075 Microsoft Corporation",
    //    "city": "Amsterdam",
    //    "country": "Netherlands",
    //    "countryCode": "NL",
    //    "isp": "Microsoft Corporation",
    //    "lat": 52.35,
    //    "lon": 4.9167,
    //    "org": "Microsoft Azure",
    //    "query": "104.40.211.35",
    //    "region": "NH",
    //    "regionName": "North Holland",
    //    "status": "success",
    //    "timezone": "Europe/Amsterdam",
    //    "zip": "1091"
    //  }

    //  Examine a few bits of information:
    std::cout << "country name = " << json.stringOf("country") << "\r\n";
    std::cout << "country code = " << json.stringOf("countryCode") << "\r\n";
    }
