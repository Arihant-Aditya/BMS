/**
 * \file IfxFce.c
 * \brief FCE  basic functionality
 *
 * \version iLLD_1_0_1_16_0_1
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxFce.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

Ifx_FCE_STS IfxFce_getCrc16InterruptStatus(Ifx_FCE *fce)
{
    Ifx_FCE_STS interruptStatus;
    interruptStatus.U = fce->IN2.STS.U;
    return interruptStatus;
}


Ifx_FCE_STS IfxFce_getCrc32InterruptStatus(Ifx_FCE *fce, IfxFce_Crc32Kernel crc32Kernel)
{
    Ifx_FCE_STS interruptStatus;

    if (crc32Kernel == IfxFce_Crc32Kernel_0)
    {
        interruptStatus.U = fce->IN0.STS.U;
    }
    else
    {
        interruptStatus.U = fce->IN1.STS.U;
    }

    return interruptStatus;
}


Ifx_FCE_STS IfxFce_getCrc8InterruptStatus(Ifx_FCE *fce)
{
    Ifx_FCE_STS interruptStatus;
    interruptStatus.U = fce->IN3.STS.U;
    return interruptStatus;
}


uint32 IfxFce_reflectCrc32(uint32 crcStartValue, uint8 crcLength)
{
    uint32 ReversedData = 0x0U;
    uint8  inputDataCounter;

    for (inputDataCounter = 0; inputDataCounter < crcLength; ++inputDataCounter)
    {
        if (crcStartValue & 0x01)
        {
            ReversedData |= (uint32)((uint32)1 << ((crcLength - 1) - inputDataCounter));
        }

        crcStartValue = (uint32)((uint32)crcStartValue >> (uint32)1);
    }

    return ReversedData;
}


void IfxFce_resetModule(Ifx_FCE *fce)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(password);
    fce->KRST1.B.RST = 1;  /* Only if both Kernel reset bits are set a reset is executed */
    fce->KRST0.B.RST = 1;
    IfxScuWdt_setCpuEndinit(password);

    while (0 == fce->KRST0.B.RSTSTAT)  /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(password);
    fce->KRSTCLR.B.CLR = 1;     /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(password);
}
