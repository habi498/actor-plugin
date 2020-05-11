#include "SQConsts.h"
#include <cstdio>


extern HSQAPI sq;

SQInteger RegisterSquirrelConst(HSQUIRRELVM v, const SQChar* cname, SQInteger cvalue) {
	sq->pushconsttable(v);
	sq->pushstring(v, cname, -1);
	sq->pushinteger(v, cvalue);
	sq->newslot(v, -3, SQFalse);
	sq->pop(v, 1);

	return 0;
}

void RegisterConsts(HSQUIRRELVM v) {
    // GeoIPCharset
	RegisterSquirrelConst(v, "GEOIP_CHARSET_ISO_8859_1",        0);
	RegisterSquirrelConst(v, "GEOIP_CHARSET_UTF8",              1);

    // GeoIPDBTypes
	RegisterSquirrelConst(v, "GEOIP_COUNTRY_EDITION",           1);
	RegisterSquirrelConst(v, "GEOIP_REGION_EDITION_REV0",       7);
	RegisterSquirrelConst(v, "GEOIP_CITY_EDITION_REV0",         6);
	RegisterSquirrelConst(v, "GEOIP_ORG_EDITION",               5);
	RegisterSquirrelConst(v, "GEOIP_ISP_EDITION",               4);
	RegisterSquirrelConst(v, "GEOIP_CITY_EDITION_REV1",         2);
	RegisterSquirrelConst(v, "GEOIP_REGION_EDITION_REV1",       3);
	RegisterSquirrelConst(v, "GEOIP_PROXY_EDITION",             8);
	RegisterSquirrelConst(v, "GEOIP_ASNUM_EDITION",             9);
	RegisterSquirrelConst(v, "GEOIP_NETSPEED_EDITION",          10);
	RegisterSquirrelConst(v, "GEOIP_DOMAIN_EDITION",            11);
    RegisterSquirrelConst(v, "GEOIP_COUNTRY_EDITION_V6",        12);
    RegisterSquirrelConst(v, "GEOIP_LOCATIONA_EDITION",         13);
    RegisterSquirrelConst(v, "GEOIP_ACCURACYRADIUS_EDITION",    14);
    RegisterSquirrelConst(v, "GEOIP_CITYCONFIDENCE_EDITION",    15);
    RegisterSquirrelConst(v, "GEOIP_CITYCONFIDENCEDIST_EDITION",16);
    RegisterSquirrelConst(v, "GEOIP_LARGE_COUNTRY_EDITION",     17);
    RegisterSquirrelConst(v, "GEOIP_LARGE_COUNTRY_EDITION_V6",  18);
    RegisterSquirrelConst(v, "GEOIP_CITYCONFIDENCEDIST_ISP_ORG_EDITION", 19);
    RegisterSquirrelConst(v, "GEOIP_CCM_COUNTRY_EDITION",       20);
    RegisterSquirrelConst(v, "GEOIP_ASNUM_EDITION_V6",          21);
    RegisterSquirrelConst(v, "GEOIP_ISP_EDITION_V6",            22);
    RegisterSquirrelConst(v, "GEOIP_ORG_EDITION_V6",            23);
    RegisterSquirrelConst(v, "GEOIP_DOMAIN_EDITION_V6",         24);
    RegisterSquirrelConst(v, "GEOIP_LOCATIONA_EDITION_V6",      25);
    RegisterSquirrelConst(v, "GEOIP_REGISTRAR_EDITION",         26);
    RegisterSquirrelConst(v, "GEOIP_REGISTRAR_EDITION_V6",      27);
    RegisterSquirrelConst(v, "GEOIP_USERTYPE_EDITION",          28);
    RegisterSquirrelConst(v, "GEOIP_USERTYPE_EDITION_V6",       29);
    RegisterSquirrelConst(v, "GEOIP_CITY_EDITION_REV1_V6",      30);
    RegisterSquirrelConst(v, "GEOIP_CITY_EDITION_REV0_V6",      31);
    RegisterSquirrelConst(v, "GEOIP_NETSPEED_EDITION_REV1",     32);
    RegisterSquirrelConst(v, "GEOIP_NETSPEED_EDITION_REV1_V6",  33);
}