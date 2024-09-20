/* MiniUPnP Project
 * http://miniupnp.free.fr/ or https://miniupnp.tuxfamily.org/
 * (c) 2006-2022 Thomas Bernard
 * generated by ./configure on 2024年 09月 20日 星期五 17:11:23 CST
 * Linux ltg 6.8.0-45-generic #45+tscfix SMP PREEMPT_DYNAMIC Wed Sep 18 21:50:02 CST 2024 x86_64 x86_64 x86_64 GNU/Linux
 * using no command line option */
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <inttypes.h>

#define MINIUPNPD_VERSION "2.3.3"
#define MINIUPNPD_DATE	"20240920"

#ifndef XSTR
#define XSTR(s) STR(s)
#define STR(s) #s
#endif /* XSTR */

/* UPnP version reported in XML descriptions
 * 1.0 / 1.1 / 2.0 depending on which UDA (UPnP Device Architecture) Version */
#define UPNP_VERSION_MAJOR	1
#define UPNP_VERSION_MINOR	1
#define UPNP_VERSION_MAJOR_STR	XSTR(UPNP_VERSION_MAJOR)
#define UPNP_VERSION_MINOR_STR	XSTR(UPNP_VERSION_MINOR)

#define USE_IFACEWATCHER 1
#define USE_NETFILTER 1
#define USE_NFTABLES  1
#define HAS_LIBCAP
/* Enable IGD2 "Port Triggering" as defined in Section 2.5.16
 * figure 2.2 in UPnP-gw-WANIPConnection-v2-Service.pdf */
#define ENABLE_PORT_TRIGGERING

#define DYNAMIC_OS_VERSION 1
#define OS_NAME		"Ubuntu"
#define OS_VERSION	"Ubuntu/%s"
#define OS_URL		"http://www.ubuntu.com/"

/* syslog facility to be used by miniupnpd */
#define LOG_MINIUPNPD		 LOG_DAEMON

/* Uncomment the following line to allow miniupnpd to be
 * controlled by miniupnpdctl */
/*#define USE_MINIUPNPDCTL*/

/* Comment the following line to disable NAT-PMP operations */
#define ENABLE_NATPMP

/* Comment the following line to disable PCP operations */
#define ENABLE_PCP

#ifdef ENABLE_PCP
/* Uncomment the following line to enable PCP PEER operation */
/*#define PCP_PEER*/
#ifdef PCP_PEER
/*#define PCP_FLOWP*/
#endif /*PCP_PEER*/
/*#define PCP_SADSCP*/
#endif /*ENABLE_PCP*/

/* Uncomment the following line to enable generation of
 * filter rules with pf */
/*#define PF_ENABLE_FILTER_RULES*/

/* Uncomment the following line to set dst address in rdr rules with pf.
 * It is disabled by default because of
 * https://github.com/miniupnp/miniupnp/issues/433 */
/*#define PF_SET_DST_ADDR*/

/* Uncomment the following line to enable caching of results of
 * the getifstats() function */
/*#define ENABLE_GETIFSTATS_CACHING*/
/* The cache duration is indicated in seconds */
#define GETIFSTATS_CACHING_DURATION 2

/* Uncomment the following line to enable multiple external ip support */
/* note : That is EXPERIMENTAL, do not use that unless you know perfectly what you are doing */
/* Dynamic external ip adresses are not supported when this option is enabled.
 * Also note that you would need to configure your .conf file accordingly. */
/*#define MULTIPLE_EXTERNAL_IP*/

/* Comment the following line to use home made daemonize() func instead
 * of BSD daemon() */
#define USE_DAEMON

/* Uncomment the following line to enable lease file support */
/*#define ENABLE_LEASEFILE*/
/* Uncomment the following line to store remaining time in lease file */
/*#define LEASEFILE_USE_REMAINING_TIME*/

/* Uncomment the following line to enable port in use check */
/*#define CHECK_PORTINUSE*/

/* Uncomment the following line to enable description regex filter */
/*#define ENABLE_REGEX*/

/* Define one or none of the two following macros in order to make some
 * clients happy. It will change the XML Root Description of the IGD.
 * Enabling the Layer3Forwarding Service seems to be the more compatible
 * option. */
/*#define HAS_DUMMY_SERVICE*/
#define ENABLE_L3F_SERVICE

/* define ADVERTISE_WANPPPCONN to allow buggy Control Point to use
 * WANPPPConnection instead of WANIPConnection. */
#define ADVERTISE_WANPPPCONN

/* Enable IP v6 support */
/*#define ENABLE_IPV6*/

/* Define V6SOCKETS_ARE_V6ONLY if AF_INET6 sockets are restricted
 * to IPv6 communications only. */
/*#define V6SOCKETS_ARE_V6ONLY*/

#define HAVE_IP_MREQN

/* Enable the support of IGD v2 specification.
 * This is not fully tested yet and can cause incompatibilities with some
 * control points, so enable with care. */
/*#define IGD_V2*/

#ifdef IGD_V2
/* Enable DeviceProtection service (IGDv2) */
#define ENABLE_DP_SERVICE
/*#define ENABLE_HTTPS*/
/*#define HTTPS_CERTFILE "/path/to/certificate.pem"*/
/*#define HTTPS_KEYFILE "/path/to/private.key"*/

/* Enable WANIPv6FirewallControl service (IGDv2). needs IPv6 */
#ifdef ENABLE_IPV6
#define ENABLE_6FC_SERVICE
#endif /* ENABLE_IPV6 */
#endif /* IGD_V2 */

/* UPnP Events support. Working well enough to be enabled by default.
 * It can be disabled to save a few bytes. */
#define ENABLE_EVENTS

/* include interface name in pf and ipf rules */
#define USE_IFNAME_IN_RULES

/* Experimental NFQUEUE support. */
/*#define ENABLE_NFQUEUE*/

/* Enable to make MiniUPnPd more strict about UPnP conformance
 * and the messages it receives from control points */
/*#define UPNP_STRICT*/

/* If SSDP_RESPOND_SAME_VERSION is defined, the M-SEARCH response
 * include the same device version as was contained in the search
 * request. It conforms to UPnP DA v1.1 */
#define SSDP_RESPOND_SAME_VERSION

/* Add the optional Date: header in all HTTP responses */
/*#define ENABLE_HTTP_DATE*/

/* Wait a little before answering M-SEARCH request */
/*#define DELAY_MSEARCH_RESPONSE*/

/* disable reading and parsing of config file (miniupnpd.conf) */
/*#define DISABLE_CONFIG_FILE*/

/* Uncomment the following line to configure all manufacturer infos through miniupnpd.conf */
/*#define ENABLE_MANUFACTURER_INFO_CONFIGURATION*/

#if defined(ENABLE_6FC_SERVICE) || (defined(ENABLE_PCP) && defined(ENABLE_IPV6))
#define ENABLE_UPNPPINHOLE
#endif

/* Uncomment the following line if your device does not have a proper clock
 * BOOTID.UPNP.ORG can be set with command line */
#define USE_TIME_AS_BOOTID

/* With the following macro defined, a random string is prepended to all URLs */
/*#define RANDOMIZE_URLS*/

/* maximum length of SSDP packets we are generating
 * (reception is done in a 1500byte buffer) */
#define SSDP_PACKET_MAX_LEN 1024

/* disable forking to the background and writing the pid file */
/*#define NO_BACKGROUND_NO_PIDFILE*/
/* Whether to use getifaddrs() to determine interface addresses */
/*#define USE_GETIFADDRS*/
#endif /* CONFIG_H_INCLUDED */
