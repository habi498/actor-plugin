# GeoIP plugin for VC-MP 0.4 #

## Installation ##

1. [**GeoIP.dat**](/uploads/0b2160e5376920b508a0ab93018b5cf5/GeoIP.dat) must be placed into the server's root directory.
2. The plugin must be placed into the server's `plugins` directory. Choose your version:
    * Windows [**32 bit**](/uploads/973417076f89c23c348654e901eb7278/geoip04rel32.dll) or [**64 bit**](/uploads/abb36f78a2dad2a81a3878797c2860e6/geoip04rel64.dll)
    * Linux [**32 bit**](/uploads/054b8f889080f1388839940bfca81822/geoip04rel32.so) or [**64 bit**](/uploads/7e4a893cb1b2d12fc514698de1a696ab/geoip04rel64.so)
3. Add the plugin's name to plugins in server.cfg:
```
plugins geoip04rel64 squirrel04rel64
```

## Functions ##
`geoip_country_*` functions return `null` on failure or if the requested information is not found in the GeoIP database.

### Getting 2 letter country code: ###
* string `geoip_country_code_by_addr (string ip)`
* string `geoip_country_code_by_name (string host)`
* string `geoip_country_code_by_ipnum (integer longip)`

### Getting 3 letter country code: ###
* string `geoip_country_code3_by_addr (string ip)`
* string `geoip_country_code3_by_name (string host)`
* string `geoip_country_code3_by_ipnum (integer longip)`

### Getting country name: ###
* string `geoip_country_name_by_addr (string ip)`
* string `geoip_country_name_by_name (string host)`
* string `geoip_country_name_by_ipnum (integer longip)`

### Other functions: ###
* integer `geoip_num_countries ()`
* string `geoip_database_info ()`
* string `geoip_lib_version ()`
* integer `geoip_database_edition ()`
* integer `geoip_charset ()`
* boolean `geoip_set_charset (integer charset)` - charset can be `GEOIP_CHARSET_UTF8` or `GEOIP_CHARSET_ISO_8859_1`
* integer `geoip_addr_to_num (string ip)`
* string `geoip_num_to_addr (integer longip)`

## Constants ##

### Character sets - can be used for `geoip_charset()` and `geoip_set_charset()`: ###
```
GEOIP_CHARSET_ISO_8859_1
GEOIP_CHARSET_UTF8
```

### Database editions - can be used for `geoip_database_edition()`: ###
```
GEOIP_COUNTRY_EDITION
GEOIP_REGION_EDITION_REV0
GEOIP_CITY_EDITION_REV0
GEOIP_ORG_EDITION
GEOIP_ISP_EDITION
GEOIP_CITY_EDITION_REV1
GEOIP_REGION_EDITION_REV1
GEOIP_PROXY_EDITION
GEOIP_ASNUM_EDITION
GEOIP_NETSPEED_EDITION
GEOIP_DOMAIN_EDITION
GEOIP_COUNTRY_EDITION_V6
GEOIP_LOCATIONA_EDITION
GEOIP_ACCURACYRADIUS_EDITION
GEOIP_CITYCONFIDENCE_EDITION
GEOIP_CITYCONFIDENCEDIST_EDITION
GEOIP_LARGE_COUNTRY_EDITION
GEOIP_LARGE_COUNTRY_EDITION_V6
GEOIP_ASNUM_EDITION_V6
GEOIP_ISP_EDITION_V6
GEOIP_ORG_EDITION_V6
GEOIP_DOMAIN_EDITION_V6
GEOIP_LOCATIONA_EDITION_V6
GEOIP_REGISTRAR_EDITION
GEOIP_REGISTRAR_EDITION_V6
GEOIP_USERTYPE_EDITION
GEOIP_USERTYPE_EDITION_V6
GEOIP_CITY_EDITION_REV1_V6
GEOIP_CITY_EDITION_REV0_V6
GEOIP_NETSPEED_EDITION_REV1
GEOIP_NETSPEED_EDITION_REV1_V6
```

## Example ##

### Displaying a player's country's name and 2 letter country code on join: ###
```
function onPlayerJoin(player) {
    local country = geoip_country_name_by_addr(player.IP);
    if (country != null) // the plugin returned a meaningful result
        Message("* " + player.Name + " is connecting from " + country + ". [" + geoip_country_code_by_addr(player.IP) + "]");
}
```