/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __NET_GENEVE_H
#define __NET_GENEVE_H  1

#include <net/udp_tunnel.h>

/* Geneve Header:
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |Ver|  Opt Len  |O|C|    Rsvd.  |          Protocol Type        |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |        Virtual Network Identifier (VNI)       |    Reserved   |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |                    Variable Length Options                    |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * Option Header:
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |          Option Class         |      Type     |R|R|R| Length  |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  |                      Variable Option Data                     |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

struct geneve_opt {
	__be16	opt_class;
	u8	type;
#ifdef __LITTLE_ENDIAN_BITFIELD
	u8	length;
	u8	r3;
	u8	r2;
	u8	r1;
#else
	u8	r1;
	u8	r2;
	u8	r3;
	u8	length;
#endif
	u8	opt_data[];
};

#define GENEVE_CRIT_OPT_TYPE (1 << 7)

struct genevehdr {
#ifdef __LITTLE_ENDIAN_BITFIELD
	u8 opt_len;
	u8 ver;
	u8 rsvd1;
	u8 critical;
	u8 oam;
#else
	u8 ver;
	u8 opt_len;
	u8 oam;
	u8 critical;
	u8 rsvd1;
#endif
	__be16 proto_type;
	u8 vni[3];
	u8 rsvd2;
	struct geneve_opt options[];
};

#ifdef CONFIG_INET
struct net_device *geneve_dev_create_fb(struct net *net, const char *name,
					u8 name_assign_type, u16 dst_port);
#endif /*ifdef CONFIG_INET */

#endif /*ifdef__NET_GENEVE_H */
