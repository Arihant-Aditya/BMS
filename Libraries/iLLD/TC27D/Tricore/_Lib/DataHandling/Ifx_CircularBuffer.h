/**
 * \file Ifx_CircularBuffer.h
 * \brief Circular buffer functions.
 *
 * \version iLLD_1_0_1_16_0_1
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_lib_datahandling_circularbuffer Circular buffer
 * This module implements circular buffer functions.
 * \ingroup IfxLld_lib_datahandling
 *
 */

#ifndef IFX_CIRCULARBUFFER_H
#define IFX_CIRCULARBUFFER_H 1

//---------------------------------------------------------------------------
#include "Cpu/Std/IfxCpu_Intrinsics.h"
//---------------------------------------------------------------------------

#ifndef IFX_CFG_CIRCULARBUFFER_C
#define IFX_CFG_CIRCULARBUFFER_C (1)
#endif

/** \addtogroup IfxLld_lib_datahandling_circularbuffer
 * \{
 */
/** \brief Return the circular buffer 16 bit value, and post-increment the circular buffer pointer
 *
 * \param buffer Specifies circular buffer.
 *
 * \return Return the next circular buffer value.
 */
uint16 Ifx_CircularBuffer_get16(Ifx_CircularBuffer *buffer);

/** \brief Return the circular buffer 32 bit value, and post-increment the circular buffer pointer
 *
 * \param buffer Specifies circular buffer.
 *
 * \return Return the next circular buffer value.
 */
uint32 Ifx_CircularBuffer_get32(Ifx_CircularBuffer *buffer);

/** \brief Copy count bytes from the circular buffer to the data array
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies destination pointer.
 * \param count Specifies number of bytes to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint8*)data) + count
 */
void *Ifx_CircularBuffer_read8(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count);

/** \brief Copy count 32 bit words from the circular buffer to the data array
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies destination pointer.
 * \param count Specifies number of 32 bit words to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint32*)data) + count
 */
void *Ifx_CircularBuffer_read32(Ifx_CircularBuffer *buffer, void *data, Ifx_SizeT count);

/** \brief Copy count bytes from the data array to the circular buffer
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies source pointer.
 * \param count Specifies number of bytes to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint8*)data) + count
 */
const void *Ifx_CircularBuffer_write8(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count);

/** \brief Copy count 32 bit words from the data array to the circular buffer
 *
 * \param buffer Specifies circular buffer.
 * \param data Specifies source pointer.
 * \param count Specifies number of 32 bit words to be copied. count MUST be >= 1.
 *
 * \return Returns the updated data pointer data = ((uint32*)data) + count
 */
const void *Ifx_CircularBuffer_write32(Ifx_CircularBuffer *buffer, const void *data, Ifx_SizeT count);

/** \} */
//---------------------------------------------------------------------------
#endif
