/*
 * TLE9012DQU.c
 *
 *  Created on: 20-Jul-2023
 *      Author: Admin
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "TLE9012DQU.h"

unsigned char Send_TLE9012_Frame[6];
unsigned char Read_Back_First_IC[4]={0x1E,0x01,0x36,0xA8};

unsigned char CRC;
unsigned char crcTable[256];

unsigned char CalcCRC(unsigned char * buf, unsigned char len) {
        const unsigned char * ptr = buf;
        unsigned char _crc = 0xFF;

        while(len--) _crc = crcTable[_crc ^ *ptr++];

        return ~_crc;
}

void CRCInit(void) {
    unsigned char _crc;
        for (int i = 0; i < 0x100; i++) {
                _crc = (unsigned char)i;

                for (unsigned char bit = 0; bit < 8; bit++) _crc = (_crc & 0x80) ? ((_crc << 1) ^ 0x1D) : (_crc << 1);

                crcTable[i] = _crc;
        }
}

void Assign_PARAMETERS_To_TLE9012(unsigned char ID,unsigned char Address,unsigned short Data,unsigned char array[])
{
    unsigned char index=0;
    unsigned char Data_bytes[2];
    Data_bytes[0] = Data & 0xFF;
    Data_bytes[1] = (Data>>8) & 0xFF;

    array[index] = 0x1E;
    index++;
    array[index] = ID;
    index++;
    array[index] = Address;
    index++;
    array[index] = Data_bytes[1];
    index++;
    array[index] = Data_bytes[0];
}

