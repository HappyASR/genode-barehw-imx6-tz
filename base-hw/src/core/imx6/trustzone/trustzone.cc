/*
 * \brief  TrustZone specific functions for IMX6
 * \author Stefan Kalkowski
 * \date   2012-10-10
 */

/*
 * Copyright (C) 2012-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* core includes */
#include <trustzone.h>
#include <pic.h>
#include <cpu.h>
#include <csu.h>
#include <base/printf.h>

/* monitor exception vector address */
extern int _mon_kernel_entry;


void Kernel::trustzone_initialization(Pic *pic)
{
	PDBG("--- IMX6 trustzone INIT ---");

	/* set exception vector entry */
	Genode::Cpu::mon_exception_entry_at((Genode::addr_t)&_mon_kernel_entry);

	/* enable coprocessor access for TZ VMs */
	Genode::Cpu::allow_coprocessor_nonsecure();

	/* set unsecure IRQs versatile express*/
	//	pic->unsecure(34); //Timer 0/1
	//	pic->unsecure(35); //Timer 2/3
	//	pic->unsecure(36); //RTC
	//	pic->unsecure(40); //UART3
	//	pic->unsecure(41); //MCI0
	//	pic->unsecure(42); //MCI1
	//	pic->unsecure(43); //AACI
	//	pic->unsecure(44); //KMI0
	//	pic->unsecure(45); //KMI1
	//	pic->unsecure(47); //ETHERNET
	//	pic->unsecure(48); //USB

	/* set unsecure IRQs imx6*/
	//pic->unsecure(87); //GPT

	/* configure central security unit */
	Genode::Csu csu(Imx6::Board::CSU_MMIO_BASE);

}