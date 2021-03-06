/*
 * \brief  Board definitions for the i.MX6
 * \author Nikolay Golikov <nik@ksyslabs.org>
 * \date   2013-02-13
 */

/*
 * Copyright (C) 2012 Ksys Labs LLC
 * Copyright (C) 2012 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__PLATFORM__IMX6__DRIVERS__BOARD_BASE_H_
#define _INCLUDE__PLATFORM__IMX6__DRIVERS__BOARD_BASE_H_

namespace Genode
{
	/**
	 * i.MX6 motherboard
	 */
	struct Board_base
	{
		enum {
			MMIO_BASE          = 0x0,
			MMIO_SIZE          = 0x10000000,

//			RAM_BASE           = 0x10000000,
//			RAM_SIZE           = 0x40000000,

			RAM0_BASE          = 0x10000000,
			RAM0_SIZE          = 0x20000000,
			RAM1_BASE          = 0x20000000,
			RAM1_SIZE          = 0x20000000,

			UART_1_IRQ         = 58,
			UART_1_MMIO_BASE   = 0x02020000,
			UART_1_MMIO_SIZE   = 0x00004000,

			EPIT_1_IRQ         = 88,
			EPIT_1_MMIO_BASE   = 0x020d0000,
			EPIT_1_MMIO_SIZE   = 0x00004000,

			EPIT_2_IRQ         = 89,
			EPIT_2_MMIO_BASE   = 0x020d4000,
			EPIT_2_MMIO_SIZE   = 0x00004000,

			AIPS_1_MMIO_BASE   = 0x0207c000,
			AIPS_2_MMIO_BASE   = 0x0217c000,

			/* TrustZone Address Space Controller */
			TZASC_1_MMIO_BASE = 0x021D0000,
			TZASC_1_MMIO_SIZE = 0x00004000,

			TZASC_2_MMIO_BASE = 0x021D4000,
			TZASC_2_MMIO_SIZE = 0x00004000,

			/* clocks */
			PLL1_CLOCK = 800*1000*1000,

			/* CPU */
			CORTEX_A9_PRIVATE_MEM_BASE = 0x00a00000,
			CORTEX_A9_PRIVATE_MEM_SIZE = 0x00002000,
			CORTEX_A9_CLOCK            = PLL1_CLOCK,

			/* Central Security Unit */
			CSU_MMIO_BASE = 0x021C0000,
			CSU_MMIO_SIZE = 0x021C3FFF,

			SECURITY_EXTENSION = 1,
		};
	};
}

#endif /* _INCLUDE__PLATFORM__IMX6__DRIVERS__BOARD_BASE_H_ */

