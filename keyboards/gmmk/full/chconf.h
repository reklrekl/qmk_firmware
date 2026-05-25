// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once



#define CH_CFG_NO_IDLE_THREAD TRUE

//override for crash on USB Timeout
#pragma weak chThdEnqueueTimeoutS


#include_next <chconf.h>
