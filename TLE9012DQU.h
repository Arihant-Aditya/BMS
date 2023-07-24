/*
 * TLE9012DQU.h
 *
 *  Created on: 20-Jul-2023
 *      Author: Admin
 */

#ifndef TLE9012DQU_H_
#define TLE9012DQU_H_

# define END_OF_FRAME      5

# define PART_CONFIG           0x01
# define OL_OV_THR             0x02
# define OL_UV_THR             0x03
# define TEMP_CONF             0x04
# define INT_OT_WARN_CONF      0x05
# define RR_ERR_CNT            0x08
# define RR_CONFIG             0x09
# define FAULT_MASK            0x0A
# define GEN_DIAG              0x0B
# define CELL_UV               0x0C
# define CELL_OV               0x0D
# define EXT_TEMP_DIAG         0x0E
# define DIAG_OL               0x10
# define REG_CRC_ERR           0x11
# define CELL_UV_DAC_COMP      0x12
# define CELL_OV_DAC_COMP      0x13
# define OP_MODE               0x14
# define BAL_CURR_THR          0x15
# define BAL_SETTINGS          0x16
# define AVM_CONFIG            0x17
# define MEAS_CTRL             0x18
# define PCVM_i                0x19+i
# define SCVM_HIGH             0x25
# define SCVM_LOW              0x26
# define STRESS_PCVM           0x27
# define BVM                   0x28
# define EXT_TEMP_0            0x29
# define EXT_TEMP_1            0x2A
# define EXT_TEMP_2            0x2B
# define EXT_TEMP_3            0x2C
# define EXT_TEMP_4            0x2D
# define EXT_TEMP_R_DIAG       0x2F
# define INT_TEMP              0x30
# define MULTI_READ            0x31
# define MULTI_READ_CFG        0x32
# define BAL_DIAG_OC           0x33
# define BAL_DIAG_UC           0x34
# define INT_TEMP_2            0x35
# define CONFIG                0x36
# define GPIO                  0x37
# define GPIO_PWM              0x38
# define ICVID                 0x39
# define MAILBOX               0x3A
# define CUSTOMER_ID_0         0x3B
# define CUSTOMER_ID_1         0x3C
# define WDOG_CNT              0x3D
# define SCVM_CONFIG           0x3E
# define STRESS_AUX            0x3F
# define BAL_PWM               0x5B
# define BAL_CNT_0             0x5C
# define BAL_CNT_1             0x5D
# define BAL_CNT_2             0x5E
# define BAL_CNT_3             0x5F

extern unsigned char Send_TLE9012_Frame[6];
extern unsigned char CRC;
extern unsigned char Read_Back_First_IC[4];

unsigned char CalcCRC(unsigned char * buf, unsigned char len);
void CRCInit(void);
void Assign_PARAMETERS_To_TLE9012(unsigned char ID,unsigned char Address,unsigned short Data,unsigned char array[]);



#endif /* TLE9012DQU_H_ */
