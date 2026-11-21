/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022 MediaTek Inc.
 * Author: Owen Chen <owen.chen@mediatek.com>
 */

#ifndef __SOC_MEDIATEK_MT6789_PM_DOMAINS_H
#define __SOC_MEDIATEK_MT6789_PM_DOMAINS_H

#include "mtk-pm-domains.h"
#include <dt-bindings/power/mt6789-power.h>

#define MT6789_TOP_AXI_PROT_EN_MM_DISP		(BIT(10) | BIT(12))
#define MT6789_TOP_AXI_PROT_EN_DISP		(BIT(6) | BIT(23))

/*
 * MT6789 power domain support
 */
static enum scpsys_bus_prot_block scpsys_bus_prot_blocks_mt6789[] = {
	BUS_PROT_BLOCK_INFRA
};

static const struct scpsys_domain_data scpsys_domain_data_mt6789[] = {
	[MT6789_POWER_DOMAIN_MFG0] = {
		.name = "mfg0",
		.sta_mask = BIT(2),
		.ctl_offs = 0x308,
		.pwr_sta_offs = 0x16C,
		.pwr_sta2nd_offs = 0x170,
		.sram_pdn_bits = BIT(8),
		.sram_pdn_ack_bits = BIT(12),
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT6789_POWER_DOMAIN_MFG1] = {
		.name = "mfg1",
		.sta_mask = BIT(3),
		.ctl_offs = 0x30c,
		.pwr_sta_offs = 0x16C,
		.pwr_sta2nd_offs = 0x170,
		.sram_pdn_bits = BIT(8),
		.sram_pdn_ack_bits = BIT(12),
		.bp_cfg = {
			BUS_PROT_WR_IGN(INFRA,
					MT8192_TOP_AXI_PROT_EN_1_MFG1,
					MT8192_TOP_AXI_PROT_EN_1_SET,
					MT8192_TOP_AXI_PROT_EN_1_CLR,
					MT8192_TOP_AXI_PROT_EN_1_STA1),
			BUS_PROT_WR_IGN(INFRA,
					MT8192_TOP_AXI_PROT_EN_2_MFG1,
					MT8192_TOP_AXI_PROT_EN_2_SET,
					MT8192_TOP_AXI_PROT_EN_2_CLR,
					MT8192_TOP_AXI_PROT_EN_2_STA1),
			BUS_PROT_WR_IGN(INFRA,
					MT8192_TOP_AXI_PROT_EN_MFG1,
					MT8192_TOP_AXI_PROT_EN_SET,
					MT8192_TOP_AXI_PROT_EN_CLR,
					MT8192_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR_IGN(INFRA,
					MT8192_TOP_AXI_PROT_EN_2_MFG1_2ND,
					MT8192_TOP_AXI_PROT_EN_2_SET,
					MT8192_TOP_AXI_PROT_EN_2_CLR,
					MT8192_TOP_AXI_PROT_EN_2_STA1),
		},
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT6789_POWER_DOMAIN_MFG2] = {
		.name = "mfg2",
		.sta_mask = BIT(4),
		.ctl_offs = 0x310,
		.pwr_sta_offs = 0x16C,
		.pwr_sta2nd_offs = 0x170,
		.sram_pdn_bits = BIT(8),
		.sram_pdn_ack_bits = BIT(12),
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT6789_POWER_DOMAIN_MFG3] = {
		.name = "mfg3",
		.sta_mask = BIT(5),
		.ctl_offs = 0x314,
		.pwr_sta_offs = 0x16C,
		.pwr_sta2nd_offs = 0x170,
		.sram_pdn_bits = BIT(8),
		.sram_pdn_ack_bits = BIT(12),
		.caps = MTK_SCPD_KEEP_DEFAULT_OFF,
	},
	[MT6789_POWER_DOMAIN_DISP] = {
		.name = "disp",
		.sta_mask = BIT(21),
		.ctl_offs = 0x354,
		.pwr_sta_offs = 0x16C,
		.pwr_sta2nd_offs = 0x170,
		.sram_pdn_bits = BIT(8),
		.sram_pdn_ack_bits = BIT(12),
		.bp_cfg = {
			BUS_PROT_WR_IGN(INFRA,
					MT6789_TOP_AXI_PROT_EN_MM_DISP,
					MT8192_TOP_AXI_PROT_EN_MM_SET,
					MT8192_TOP_AXI_PROT_EN_MM_CLR,
					MT8192_TOP_AXI_PROT_EN_MM_STA1),
			BUS_PROT_WR_IGN(INFRA,
					MT6789_TOP_AXI_PROT_EN_DISP,
					MT8192_TOP_AXI_PROT_EN_SET,
					MT8192_TOP_AXI_PROT_EN_CLR,
					MT8192_TOP_AXI_PROT_EN_STA1),
		},
		.caps = MTK_SCPD_ALWAYS_ON,
	},
};

static const struct scpsys_soc_data mt6789_scpsys_data = {
	.domains_data = scpsys_domain_data_mt6789,
	.num_domains = ARRAY_SIZE(scpsys_domain_data_mt6789),
	.bus_prot_blocks = scpsys_bus_prot_blocks_mt6789,
	.num_bus_prot_blocks = ARRAY_SIZE(scpsys_bus_prot_blocks_mt6789),
};

#endif /* __SOC_MEDIATEK_MT6789_PM_DOMAINS_H */
