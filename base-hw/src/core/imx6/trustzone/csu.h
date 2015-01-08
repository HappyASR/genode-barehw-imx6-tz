/*
 * \brief  Driver for the Central Security Unit
 * \author Stefan Kalkowski
 * \date   2012-11-06
 */

/*
 * Copyright (C) 2012 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _SRC__SERVER__VMM__INCLUDE__CSU_H_
#define _SRC__SERVER__VMM__INCLUDE__CSU_H_

/* Genode includes */
#include <util/mmio.h>
#include <util/register.h>

namespace Genode
{

	class Csu : Mmio
	{
		private:

			template <off_t OFF>
			struct Csl : public Register<OFF, 32>
			{
				enum {
					SECURE   = 0x33,
					UNSECURE = 0xff,
				};

				struct Slave_a : Register<OFF, 32>::template Bitfield<0, 8>  { };
				struct Slave_b : Register<OFF, 32>::template Bitfield<16, 8> { };
			};

			struct Master : public Register<0x218, 32>
			{
				enum {
					SECURE_UNLOCKED,
					UNSECURE_UNLOCKED,
					SECURE_LOCKED,
					UNSECURE_LOCKED
				};

				struct Esdhc3 : Bitfield<0,2>  { };
				struct Cortex : Bitfield<2,2>  { };
				struct Sdma   : Bitfield<4,2>  { };
				struct Gpu    : Bitfield<6,2>  { };
				struct Usb    : Bitfield<8,2>  { };
				struct Pata   : Bitfield<10,2> { };
				struct Mlb    : Bitfield<14,2> { };
				struct Rtic   : Bitfield<18,2> { };
				struct Esdhc4 : Bitfield<20,2> { };
				struct Fec    : Bitfield<22,2> { };
				struct Dap    : Bitfield<24,2> { };
				struct Esdhc1 : Bitfield<26,2> { };
				struct Esdhc2 : Bitfield<28,2> { };
			};

			struct Alarm_mask : public Register<0x230, 32> { };
			struct Irq_ctrl   : public Register<0x368, 32> { };

		public:

			typedef Csl<0x00> Csl00;
			typedef Csl<0x04> Csl01;
			typedef Csl<0x08> Csl02;
			typedef Csl<0x0c> Csl03;
			typedef Csl<0x10> Csl04;
			typedef Csl<0x14> Csl05;
			typedef Csl<0x18> Csl06;
			typedef Csl<0x1c> Csl07;
			typedef Csl<0x20> Csl08;
			typedef Csl<0x24> Csl09;
			typedef Csl<0x28> Csl10;
			typedef Csl<0x2c> Csl11;
			typedef Csl<0x30> Csl12;
			typedef Csl<0x34> Csl13;
			typedef Csl<0x38> Csl14;
			typedef Csl<0x3c> Csl15;
			typedef Csl<0x40> Csl16;
			typedef Csl<0x44> Csl17;
			typedef Csl<0x48> Csl18;
			typedef Csl<0x4c> Csl19;
			typedef Csl<0x50> Csl20;
			typedef Csl<0x54> Csl21;
			typedef Csl<0x58> Csl22;
			typedef Csl<0x5c> Csl23;
			typedef Csl<0x60> Csl24;
			typedef Csl<0x64> Csl25;
			typedef Csl<0x68> Csl26;
			typedef Csl<0x6c> Csl27;
			typedef Csl<0x70> Csl28;
			typedef Csl<0x74> Csl29;
			typedef Csl<0x78> Csl30;
			typedef Csl<0x7c> Csl31;
			typedef Csl<0x80> Csl32;
			typedef Csl<0x84> Csl33;
			typedef Csl<0x88> Csl34;
			typedef Csl<0x90> Csl35;
			typedef Csl<0x94> Csl36;
			typedef Csl<0x98> Csl37;
			typedef Csl<0x9C> Csl38;
			typedef Csl<0x200> Csl39;
			typedef Csl<0x204> Csl_HP0;
			typedef Csl<0x218> Csl_HP1;
			typedef Csl<0x358> Csl_HPCONTROL0;
			typedef Csl<0x35C> Csl_HPCONTROL1;

			Csu(addr_t const base) : Mmio(base)
			{
				/* PWM1 PWM2 PWM3 PWM4 PWM5 */
				write<Csl00::Slave_a>(Csl00::UNSECURE);

				/* CAN1 CAN2 */
				write<Csl00::Slave_b>(Csl00::UNSECURE);
				write<Csl01::Slave_a>(Csl00::UNSECURE);

				/* Timer (EPIT, GPT) TODO */
				write<Csl01::Slave_b>(Csl00::UNSECURE);

				/* GPIO1 GPIO2 */
				write<Csl02::Slave_a>(Csl00::UNSECURE);

				/* GPIO3 GPIO4 */
				write<Csl02::Slave_b>(Csl00::UNSECURE);

				/* GPIO5 GPIO6 */
				write<Csl03::Slave_a>(Csl00::UNSECURE);

				/* GPIO7 */
				write<Csl03::Slave_b>(Csl00::UNSECURE);

				/* KPP */
				write<Csl04::Slave_a>(Csl00::UNSECURE);

				/* WDOG1 */
				write<Csl04::Slave_b>(Csl00::UNSECURE);

				/* WDOG2 */
				write<Csl05::Slave_a>(Csl00::UNSECURE);

				/* CCM SNVS_HP SRC GPC */
				write<Csl05::Slave_b>(Csl00::UNSECURE);

				/* IP2ABP_ANATOP */
				write<Csl06::Slave_a>(Csl00::UNSECURE);

				/* IOMUX */
				write<Csl06::Slave_b>(Csl00::UNSECURE);

				/* DCIC1 DCIC2 */
				write<Csl07::Slave_a>(Csl00::UNSECURE);

				/* SDMA (port IPS_HOST) */
				write<Csl07::Slave_b>(Csl00::UNSECURE);

				/* USBOH3 (port PL301) USBOH3 (port USB) */
				write<Csl08::Slave_a>(Csl00::UNSECURE);

				/* ENET */
				write<Csl08::Slave_b>(Csl00::UNSECURE);

				/* MLB150 */
				write<Csl09::Slave_a>(Csl00::UNSECURE);

				/* USDHC1 */
				write<Csl09::Slave_b>(Csl00::UNSECURE);

				/* USDHC2 */
				write<Csl10::Slave_a>(Csl00::UNSECURE);

				/* USDHC3 */
				write<Csl10::Slave_b>(Csl00::UNSECURE);

				/* USDHC4 */
				write<Csl11::Slave_a>(Csl00::UNSECURE);

				/* I2C1 */
				write<Csl11::Slave_b>(Csl00::UNSECURE);

				/* I2C2 */
				write<Csl12::Slave_a>(Csl00::UNSECURE);

				/* I2C3 */
				write<Csl12::Slave_b>(Csl00::UNSECURE);

				/* ROMCP */
				write<Csl13::Slave_a>(Csl00::UNSECURE);

				/* VPU  MMDC_CORE (port IPS_P0)  MMDC_CORE (port IPS_P1) */
				write<Csl13::Slave_b>(Csl00::UNSECURE);

				/* WEIM */
				write<Csl14::Slave_a>(Csl00::UNSECURE);

				/* OCOTP_CTRL */
				write<Csl14::Slave_b>(Csl00::UNSECURE);

				/* PERFMON 1 2 3 */
				write<Csl15::Slave_b>(Csl00::UNSECURE);

				/* TZASC1 - TZASC2 */
				write<Csl16::Slave_a>(Csl16::UNSECURE);
				write<Csl16::Slave_b>(Csl16::UNSECURE);

				/* AUDMUX */
				write<Csl17::Slave_a>(Csl00::UNSECURE);

				/* CAAM */
				write<Csl17::Slave_b>(Csl00::UNSECURE);

				/* SPDIF */
				write<Csl18::Slave_a>(Csl00::UNSECURE);

				/* eCSPI1 */
				write<Csl18::Slave_b>(Csl00::UNSECURE);

				/* eCSPI2 */
				write<Csl19::Slave_a>(Csl00::UNSECURE);

				/* eCSPI3 */
				write<Csl19::Slave_b>(Csl00::UNSECURE);

				/* eCSPI4 */
				write<Csl20::Slave_a>(Csl00::UNSECURE);

				/* UART1 */
				write<Csl21::Slave_a>(Csl00::UNSECURE);

				/* ESAI1 */
				write<Csl21::Slave_b>(Csl00::UNSECURE);

				/* SSI1 */
				write<Csl22::Slave_a>(Csl00::UNSECURE);

				/* SSI2 */
				write<Csl22::Slave_b>(Csl00::UNSECURE);

				/* SSI3 */
				write<Csl23::Slave_a>(Csl00::UNSECURE);

				/* ASRC (VIA IPSYNC) */
				write<Csl23::Slave_b>(Csl00::UNSECURE);

				/* ROMCP */
				write<Csl24::Slave_b>(Csl00::UNSECURE);

				/* APBH_DMA */
				write<Csl27::Slave_a>(Csl00::UNSECURE);

				/* APBH_DMA */
				write<Csl27::Slave_b>(Csl00::UNSECURE);

				/* GPU3D */
				write<Csl28::Slave_a>(Csl00::UNSECURE);

				/* ARM CORE platform DAP platform controller */
				write<Csl29::Slave_b>(Csl00::UNSECURE);

				/* HSI */
				write<Csl30::Slave_a>(Csl00::UNSECURE);

				/* IPU1 */
				write<Csl30::Slave_a>(Csl00::UNSECURE);

				/* WEIM */
				write<Csl31::Slave_b>(Csl00::UNSECURE);

				/* PCIE */
				write<Csl32::Slave_a>(Csl00::UNSECURE);

				/* GPU2D */
				write<Csl32::Slave_b>(Csl00::UNSECURE);

				/* MIPI_CORE_CSI */
				write<Csl33::Slave_a>(Csl00::UNSECURE);

				/* MIPI_CORE_HSI */
				write<Csl33::Slave_b>(Csl00::UNSECURE);

				/* VDOA */
				write<Csl34::Slave_a>(Csl00::UNSECURE);

				/* UART */
				write<Csl34::Slave_b>(Csl00::UNSECURE); //UART2
				write<Csl35::Slave_a>(Csl00::UNSECURE); //UART3
				write<Csl35::Slave_b>(Csl00::UNSECURE); //UART4
				write<Csl36::Slave_a>(Csl00::UNSECURE); //UART5

				/* DTCP */
				write<Csl36::Slave_b>(Csl00::UNSECURE);
			}
	};

}

#endif /* _BASE_HW__SRC__SERVER__VMM__TSC_380_H_ */
