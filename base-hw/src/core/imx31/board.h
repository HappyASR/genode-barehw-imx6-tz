/*
 * \brief  Board driver for core
 * \author Martin Stein
 * \date   2012-11-01
 */

#ifndef _BOARD__IMX31_H_
#define _BOARD__IMX31_H_

/* Genode includes */
#include <drivers/board_base.h>

namespace Genode
{
	/**
	 * AHB-lite 2v6 to IP bus interface
	 */
	class Aips : public Mmio
	{
		/**
		 * Configuration of the masters
		 */
		struct Mpr { enum { ALL_UNBUFFERED_AND_FULLY_TRUSTED = 0x77777777 }; };
		struct Mpr1 : Register<0x0, 32>, Mpr { };
		struct Mpr2 : Register<0x4, 32>, Mpr { };

		/**
		 * Configuration of the platform peripherals
		 */
		struct Pacr { enum { ALL_UNBUFFERED_AND_FULLY_UNPROTECTED = 0 }; };
		struct Pacr1 : Register<0x20, 32>, Pacr { };
		struct Pacr2 : Register<0x24, 32>, Pacr { };
		struct Pacr3 : Register<0x28, 32>, Pacr { };
		struct Pacr4 : Register<0x2c, 32>, Pacr { };

		/**
		 * Configuration of the off-platform peripherals
		 */
		struct Opacr1 : Register<0x40, 32>, Pacr { };
		struct Opacr2 : Register<0x44, 32>, Pacr { };
		struct Opacr3 : Register<0x48, 32>, Pacr { };
		struct Opacr4 : Register<0x4c, 32>, Pacr { };
		struct Opacr5 : Register<0x50, 32>, Pacr { };

		public:

			/**
			 * Constructor
			 */
			Aips(addr_t const base) : Mmio(base) { }

			/**
			 * Configure this module appropriately for the first kernel run
			 */
			void prepare_kernel()
			{
				/* avoid AIPS intervention at any memory access */
				write<Mpr1>(Mpr::ALL_UNBUFFERED_AND_FULLY_TRUSTED);
				write<Mpr2>(Mpr::ALL_UNBUFFERED_AND_FULLY_TRUSTED);
				write<Pacr1>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Pacr2>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Pacr3>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Pacr4>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Opacr1>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Opacr2>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Opacr3>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Opacr4>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
				write<Opacr5>(Pacr::ALL_UNBUFFERED_AND_FULLY_UNPROTECTED);
			}
	};

	/**
	 * Board driver for core
	 */
	struct Board : Board_base
	{
		/**
		 * Static AIPS 1 instance
		 */
		static Aips * aips_1() { static Aips a(AIPS_1_MMIO_BASE); return &a; }

		/**
		 * Static AIPS 2 instance
		 */
		static Aips * aips_2() { static Aips a(AIPS_2_MMIO_BASE); return &a; }

		/**
		 * Configure this module appropriately for the first kernel run
		 */
		static void prepare_kernel()
		{
			aips_1()->prepare_kernel();
			aips_2()->prepare_kernel();
		}
	};
}

#endif /* _BOARD__IMX31_H_ */
