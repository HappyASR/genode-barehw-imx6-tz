/*
 * \brief  Interrupt controller for kernel
 * \author Martin Stein
 * \date   2012-04-23
 */

/*
 * Copyright (C) 2012-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _IMX6__TRUSTZONE__PIC_H_
#define _IMX6__TRUSTZONE__PIC_H_

/* core includes */
#include <pic/cortex_a9.h>
#include <cpu/cortex_a9.h>
#include <pic/imx6_trustzone.h>

namespace Kernel
{
	/**
	 * Interrupt controller for kernel
	 */
	class Pic : public Imx6_trustzone::Pic { };
}

//bool Arm_gic::Pic::_use_security_ext() { return 0; }


#endif /* _IMX6__TRUSTZONE__PIC_H_ */

