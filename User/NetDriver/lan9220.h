#ifndef __LAN9220_H__
#define __LAN9220_H__

#include "stm32f10x.h"

/*-------------------------- LAN9220 IRQ define ----------------------------*/
#define LAN9220_IRQ_PIN               (uint16_t)GPIO_Pin_6
#define LAN9220_IRQ_PORT               GPIOD
/*------------------------- LAN9220 PME define -----------------------------*/
#define LAN9220_PME_PIN               (uint16_t)GPIO_Pin_0
#define LAN9220_PME_PORT               GPIOE
/*----------------------- LAN9220 RESET define -----------------------------*/
#define LAN9220_RESET_PIN             (uint16_t)GPIO_Pin_3
#define LAN9220_RESET_PORT             GPIOD
/*----------------------- LAN9220 AMDIX_EN define --------------------------*/
#define LAN9220_AMDIX_EN_PIN          (uint16_t)GPIO_Pin_1
#define LAN9220_AMDIX_EN_PORT          GPIOE

//------------------------------------------------------------------------------
// LAN9220 Defines 
/*
 ****************************************************************************
 ****************************************************************************
 *	TX/RX FIFO Port Register (Direct Address)
 *	Offset (from Base Address)
 *	and bit definitions
 ****************************************************************************
 ****************************************************************************
 */
 /*-------------------------------------------------------------------------*/
#define RX_DATA_FIFO_PORT	               (0x00)
#define TX_DATA_FIFO_PORT	               (0x20)

#define TX_CMD_A_INT_ON_COMP_		         (0x80000000)
#define TX_CMD_A_INT_BUF_END_ALGN_	     (0x03000000)
#define TX_CMD_A_INT_4_BYTE_ALGN_	       (0x00000000)
#define TX_CMD_A_INT_16_BYTE_ALGN_	     (0x01000000)
#define TX_CMD_A_INT_32_BYTE_ALGN_	     (0x02000000)
#define TX_CMD_A_INT_DATA_OFFSET_	       (0x001F0000)
#define TX_CMD_A_INT_FIRST_SEG_ 	       (0x00002000)
#define TX_CMD_A_INT_LAST_SEG_		       (0x00001000)
#define TX_CMD_A_BUF_SIZE_			         (0x000007FF)

#define TX_CMD_B_PKT_TAG_			           (0xFFFF0000)
#define TX_CMD_B_ADD_CRC_DISABLE_	       (0x00002000)
#define TX_CMD_B_DISABLE_PADDING_	       (0x00001000)
#define TX_CMD_B_PKT_BYTE_LENGTH_	       (0x000007FF)

#define RX_STATUS_FIFO_PORT              (0x00000040)
#define RX_STS_ES			                   (0x00008000)
#define RX_STS_LENGTH_ERR	               (0x00001000)
#define RX_STS_MULTICAST	               (0x00000400)
#define RX_STS_FRAME_TYPE	               (0x00000020)
#define RX_FIFO_PEEK		                 (0x00000044)

#define TX_STS_ES			                   (0x00008000)

#define TX_STATUS_FIFO_PORT              (0x00000048)
#define TX_FIFO_PEEK		                 (0x0000004C)
/*-------------------------------------------------------------------------*/
/*
 ****************************************************************************
 ****************************************************************************
 *	Slave Interface Module Control and Status Register (Direct Address)
 *	Offset (from Base Address)
 *	and bit definitions
 ****************************************************************************
 ****************************************************************************
 */
 /*-------------------------------------------------------------------------*/
#define ID_REV				                  (0x50)

#define ID_REV_CHIP_ID_ 	              (0xFFFF0000)	// RO	default 0x011X
#define ID_REV_REV_ID_		              (0x0000FFFF)	// RO
/*-------------------------------------------------------------------------*/
#define INT_CFG 			                  (0x54)

#define INT_CFG_INT_DEAS_	              (0xFF000000)	// R/W
#define INT_CFG_IRQ_INT_	              (0x00001000)	// RO
#define INT_CFG_IRQ_EN_ 	              (0x00000100)	// R/W
#define INT_CFG_IRQ_POL_	              (0x00000010)	// R/W Not Affected by SW Reset
#define INT_CFG_IRQ_TYPE_	              (0x00000001)	// R/W Not Affected by SW Reset
#define INT_CFG_IRQ_RESERVED_          	(0x00FFCEEE)	//Reserved bits mask
/*-------------------------------------------------------------------------*/
#define INT_STS 			                  (0x58)

#define INT_STS_SW_INT_ 	              (0x80000000)	// R/WC
#define INT_STS_TXSTOP_INT_             (0x02000000)	// R/WC
#define INT_STS_RXSTOP_INT_             (0x01000000)	// R/WC
#define INT_STS_RXDFH_INT_	            (0x00800000)	// R/WC
#define INT_STS_RXDF_INT_	              (0x00400000)	// R/WC
#define INT_STS_TX_IOC_ 	              (0x00200000)	// R/WC
#define INT_STS_RXD_INT_	              (0x00100000)	// R/WC
#define INT_STS_GPT_INT_	              (0x00080000)	// R/WC
#define INT_STS_PHY_INT_	              (0x00040000)	// RO PHY中断
#define INT_STS_PME_INT_              	(0x00020000)	// R/WC
#define INT_STS_TXSO_		                (0x00010000)	// R/WC
#define INT_STS_RWT_		                (0x00008000)	// R/WC
#define INT_STS_RXE_		                (0x00004000)	// R/WC
#define INT_STS_TXE_	                	(0x00002000)	// R/WC
#define INT_STS_ERX_		                (0x00001000)	// R/WC
#define INT_STS_TDFU_		                (0x00000800)	// R/WC
#define INT_STS_TDFO_		                (0x00000400)	// R/WC
#define INT_STS_TDFA_		                (0x00000200)	// R/WC
#define INT_STS_TSFF_		                (0x00000100)	// R/WC
#define INT_STS_TSFL_		                (0x00000080)	// R/WC
#define INT_STS_RDFO_		                (0x00000040)	// R/WC
#define INT_STS_RDFL_		                (0x00000020)	// R/WC
#define INT_STS_RSFF_		                (0x00000010)	// R/WC
#define INT_STS_RSFL_		                (0x00000008)	// R/WC
#define INT_STS_GPIO2_INT_	            (0x00000004)	// R/WC
#define INT_STS_GPIO1_INT_	            (0x00000002)	// R/WC
#define INT_STS_GPIO0_INT_	            (0x00000001)	// R/WC
/*-------------------------------------------------------------------------*/
#define INT_EN				                  (0x5C)

#define INT_EN_SW_INT_EN_		            (0x80000000)	// R/W
#define INT_EN_TXSTOP_INT_EN_	          (0x02000000)	// R/W
#define INT_EN_RXSTOP_INT_EN_	          (0x01000000)	// R/W
#define INT_EN_RXDFH_INT_EN_          	(0x00800000)	// R/W
#define INT_EN_RXDF_INT_EN_ 	          (0x00400000)	// R/W
#define INT_EN_TIOC_INT_EN_            	(0x00200000)	// R/W
#define INT_EN_RXD_INT_EN_		          (0x00100000)	// R/W
#define INT_EN_GPT_INT_EN_	          	(0x00080000)	// R/W
#define INT_EN_PHY_INT_EN_		          (0x00040000)	// R/W
#define INT_EN_PME_INT_EN_	           	(0x00020000)	// R/W
#define INT_EN_TXSO_EN_ 		            (0x00010000)	// R/W
#define INT_EN_RWT_EN_		              (0x00008000)	// R/W
#define INT_EN_RXE_EN_		            	(0x00004000)	// R/W
#define INT_EN_TXE_EN_		             	(0x00002000)	// R/W
#define INT_EN_ERX_EN_			            (0x00001000)	// R/W
#define INT_EN_TDFU_EN_ 	            	(0x00000800)	// R/W
#define INT_EN_TDFO_EN_ 	            	(0x00000400)	// R/W
#define INT_EN_TDFA_EN_ 		            (0x00000200)	// R/W
#define INT_EN_TSFF_EN_ 	            	(0x00000100)	// R/W
#define INT_EN_TSFL_EN_ 		            (0x00000080)	// R/W
#define INT_EN_RDFO_EN_ 	            	(0x00000040)	// R/W
#define INT_EN_RDFL_EN_             		(0x00000020)	// R/W
#define INT_EN_RSFF_EN_ 	            	(0x00000010)	// R/W
#define INT_EN_RSFL_EN_ 		            (0x00000008)	// R/W
#define INT_EN_GPIO2_INT_		            (0x00000004)	// R/W
#define INT_EN_GPIO1_INT_		            (0x00000002)	// R/W
#define INT_EN_GPIO0_INT_	            	(0x00000001)	// R/W
/*-------------------------------------------------------------------------*/
#define DMA_CFG 			                  (0x60)

#define DMA_CFG_DRQ1_DEAS_	          	(0xFF000000)	// R/W
#define DMA_CFG_DMA1_MODE_		          (0x00200000)	// R/W
#define DMA_CFG_DMA1_FUNC_		          (0x00180000)	// R/W
#define DMA_CFG_DMA1_FUNC_DISABLED_   	(0x000000000) // R/W
#define DMA_CFG_DMA1_FUNC_TX_DMA_		    (0x000800000) // R/W
#define DMA_CFG_DMA1_FUNC_RX_DMA_		    (0x001000000) // R/W
#define DMA_CFG_DRQ1_BUFF_		          (0x00040000)	// R/W
#define DMA_CFG_DRQ1_POL_		            (0x00020000)	// R/W
#define DMA_CFG_DAK1_POL_		            (0x00010000)	// R/W
#define DMA_CFG_DRQ0_DEAS_	          	(0x0000FF00)	// R/W
#define DMA_CFG_DMA0_MODE_		          (0x00000020)	// R/W
#define DMA_CFG_DMA0_FUNC_		          (0x00000018)	// R/W
#define DMA_CFG_DMA0_FUNC_FIFO_SEL_ 	  (0x000000000) // R/W
#define DMA_CFG_DMA0_FUNC_TX_DMA_		    (0x000000008) // R/W
#define DMA_CFG_DMA0_FUNC_RX_DMA_		    (0x000000010) // R/W
#define DMA_CFG_DRQ0_BUFF_	          	(0x00000004)	// R/W
#define DMA_CFG_DRQ0_POL_	            	(0x00000002)	// R/W
#define DMA_CFG_DAK0_POL_	            	(0x00000001)	// R/W
/*-------------------------------------------------------------------------*/
#define BYTE_TEST			                  (0x64)	// RO default 0x87654321
/*-------------------------------------------------------------------------*/
#define FIFO_INT			                  (0x68)

#define FIFO_INT_TX_AVAIL_LEVEL_	      (0xFF000000)	// R/W
#define FIFO_INT_TX_STS_LEVEL_		      (0x00FF0000)	// R/W
#define FIFO_INT_RX_AVAIL_LEVEL_	      (0x0000FF00)	// R/W
#define FIFO_INT_RX_STS_LEVEL_		      (0x000000FF)	// R/W
/*-------------------------------------------------------------------------*/
#define RX_CFG				                  (0x6C)

#define RX_CFG_RX_END_ALGN_ 	          (0xC0000000)	// R/W
#define RX_CFG_RX_END_ALGN4_		        (0x00000000)	// R/W
#define RX_CFG_RX_END_ALGN16_		        (0x40000000)	// R/W
#define RX_CFG_RX_END_ALGN32_		        (0x80000000)	// R/W
#define RX_CFG_RX_DMA_CNT_		          (0x0FFF0000)	// R/W
#define RX_CFG_RX_DUMP_ 		            (0x00008000)	// R/W
#define RX_CFG_RXDOFF_		            	(0x00001F00)	// R/W
#define RX_CFG_RXBAD_		              	(0x00000001)	// R/W
/*-------------------------------------------------------------------------*/
#define TX_CFG			                  	(0x70)

#define TX_CFG_TX_DMA_LVL_	           	(0xE0000000)	// R/W
#define TX_CFG_TX_DMA_CNT_		          (0x0FFF0000)	// R/W Self Clearing
#define TX_CFG_TXS_DUMP_		            (0x00008000)	// Self Clearing
#define TX_CFG_TXD_DUMP_		            (0x00004000)	// Self Clearing
#define TX_CFG_TXSAO_			              (0x00000004)	// R/W
#define TX_CFG_TX_ON_			              (0x00000002)	// R/W
#define TX_CFG_STOP_TX_ 		            (0x00000001)	// Self Clearing
/*-------------------------------------------------------------------------*/
#define HW_CFG				                  (0x74)

#define HW_CFG_TTM_ 			              (0x00200000)	// R/W
#define HW_CFG_SF_				              (0x00100000)	// R/W
#define HW_CFG_TX_FIF_SZ_		            (0x000F0000)	// R/W
#define HW_CFG_TR_				              (0x00003000)	// R/W
#define HW_CFG_PHY_CLK_SEL_		          (0x00000060)  // R/W
#define HW_CFG_PHY_CLK_SEL_INT_PHY_	    (0x00000000) 	// R/W
#define HW_CFG_PHY_CLK_SEL_EXT_PHY_	    (0x00000020) 	// R/W
#define HW_CFG_PHY_CLK_SEL_CLK_DIS_   	(0x00000040) 	// R/W
#define HW_CFG_SMI_SEL_			            (0x00000010)  // R/W
#define HW_CFG_EXT_PHY_DET_		          (0x00000008)  // RO
#define HW_CFG_EXT_PHY_EN_		          (0x00000004)  // R/W
#define HW_CFG_SRST_TO_			            (0x00000002)  // RO
#define HW_CFG_SRST_			              (0x00000001)	// Self Clearing
/*-------------------------------------------------------------------------*/
#define RX_DP_CTL			                  (0x78)

#define RX_DP_CTL_FFWD_BUSY_	          (0x80000000)	// R/?
#define RX_DP_CTL_RX_FFWD_		          (0x00000FFF)	// R/W
/*-------------------------------------------------------------------------*/
#define RX_FIFO_INF 		                (0x7C)

#define RX_FIFO_INF_RXSUSED_	          (0x00FF0000)	// RO
#define RX_FIFO_INF_RXDUSED_	          (0x0000FFFF)	// RO
/*-------------------------------------------------------------------------*/
#define TX_FIFO_INF 		                (0x80)

#define TX_FIFO_INF_TSFREE_ 	          (0x00FF0000)	// RO for PAS V.1.3
#define TX_FIFO_INF_TSUSED_ 	          (0x00FF0000)	// RO for PAS V.1.4
#define TX_FIFO_INF_TDFREE_ 	          (0x0000FFFF)	// RO
/*-------------------------------------------------------------------------*/
#define PMT_CTRL			                  (0x84)

#define PMT_CTRL_PM_MODE_			          (0x00003000)	// Self Clearing
#define PMT_CTRL_PM_MODE_GP_		        (0x00003000)	// Self Clearing
#define PMT_CTRL_PM_MODE_ED_		        (0x00002000)	// Self Clearing
#define PMT_CTRL_PM_MODE_WOL_		        (0x00001000)	// Self Clearing
#define PMT_CTRL_PHY_RST_			          (0x00000400)	// Self Clearing
#define PMT_CTRL_WOL_EN_			          (0x00000200)	// R/W
#define PMT_CTRL_ED_EN_ 			          (0x00000100)	// R/W
#define PMT_CTRL_PME_TYPE_			        (0x00000040)	// R/W Not Affected by SW Reset
#define PMT_CTRL_WUPS_				          (0x00000030)	// R/WC
#define PMT_CTRL_WUPS_NOWAKE_		        (0x00000000)	// R/WC
#define PMT_CTRL_WUPS_ED_			          (0x00000010)	// R/WC
#define PMT_CTRL_WUPS_WOL_			        (0x00000020)	// R/WC
#define PMT_CTRL_WUPS_MULTI_		        (0x00000030)	// R/WC
#define PMT_CTRL_PME_IND_		            (0x00000008)	// R/W
#define PMT_CTRL_PME_POL_		            (0x00000004)	// R/W
#define PMT_CTRL_PME_EN_		            (0x00000002)	// R/W Not Affected by SW Reset
#define PMT_CTRL_READY_ 		            (0x00000001)	// RO
/*-------------------------------------------------------------------------*/
#define GPIO_CFG			                  (0x88)

#define GPIO_CFG_LED3_EN_		            (0x40000000)	// R/W
#define GPIO_CFG_LED2_EN_		            (0x20000000)	// R/W
#define GPIO_CFG_LED1_EN_		            (0x10000000)	// R/W
#define GPIO_CFG_GPIO2_INT_POL_         (0x04000000)	// R/W
#define GPIO_CFG_GPIO1_INT_POL_         (0x02000000)	// R/W
#define GPIO_CFG_GPIO0_INT_POL_         (0x01000000)	// R/W
#define GPIO_CFG_EEPR_EN_		            (0x00700000)	// R/W
#define GPIO_CFG_GPIOBUF2_		          (0x00040000)	// R/W
#define GPIO_CFG_GPIOBUF1_		          (0x00020000)	// R/W
#define GPIO_CFG_GPIOBUF0_		          (0x00010000)	// R/W
#define GPIO_CFG_GPIODIR2_		          (0x00000400)	// R/W
#define GPIO_CFG_GPIODIR1_		          (0x00000200)	// R/W
#define GPIO_CFG_GPIODIR0_		          (0x00000100)	// R/W
#define GPIO_CFG_GPIOD4_		            (0x00000020)	// R/W
#define GPIO_CFG_GPIOD3_		            (0x00000010)	// R/W
#define GPIO_CFG_GPIOD2_		            (0x00000004)	// R/W
#define GPIO_CFG_GPIOD1_		            (0x00000002)	// R/W
#define GPIO_CFG_GPIOD0_		            (0x00000001)	// R/W
/*-------------------------------------------------------------------------*/
#define GPT_CFG 			                  (0x8C)

#define GPT_CFG_TIMER_EN_		            (0x20000000)	// R/W
#define GPT_CFG_GPT_LOAD_	            	(0x0000FFFF)	// R/W
/*-------------------------------------------------------------------------*/
#define GPT_CNT 			                  (0x90)

#define GPT_CNT_GPT_CNT_		            (0x0000FFFF)	// RO
/*-------------------------------------------------------------------------*/
#define FPGA_REV			                  (0x94)

#define FPGA_REV_FPGA_REV_		          (0x0000FFFF)	// RO
/*-------------------------------------------------------------------------*/
#define WORD_SWAP				                (0x98)	// R/W Not Affected by SW Reset
/*-------------------------------------------------------------------------*/
#define FREE_RUN			                  (0x9C)	// RO
/*-------------------------------------------------------------------------*/
#define RX_DROP 			                  (0xA0)	// R/WC
/*-------------------------------------------------------------------------*/
#define MAC_CSR_CMD 		                (0xA4)

#define MAC_CSR_CMD_CSR_BUSY_	          (0x80000000)	// Self Clearing
#define MAC_CSR_CMD_R_NOT_W_	          (0x40000000)	// R/W
#define MAC_CSR_CMD_CSR_ADDR_	          (0x000000FF)	// R/W
/*-------------------------------------------------------------------------*/
#define MAC_CSR_DATA		                (0xA8)	// R/W
/*-------------------------------------------------------------------------*/
#define AFC_CFG 			                  (0xAC)

#define AFC_CFG_AFC_HI_ 		            (0x00FF0000)	// R/W
#define AFC_CFG_AFC_LO_ 		            (0x0000FF00)	// R/W
#define AFC_CFG_BACK_DUR_		            (0x000000F0)	// R/W
#define AFC_CFG_FCMULT_ 		            (0x00000008)	// R/W
#define AFC_CFG_FCBRD_			            (0x00000004)	// R/W
#define AFC_CFG_FCADD_			            (0x00000002)	// R/W
#define AFC_CFG_FCANY_			            (0x00000001)	// R/W
/*-------------------------------------------------------------------------*/
#define E2P_CMD 			                  (0xB0)
#define E2P_CMD_EPC_BUSY_		            (0x80000000)	// Self Clearing
#define E2P_CMD_EPC_CMD_		            (0x70000000)	// R/W
#define E2P_CMD_EPC_CMD_READ_	          (0x00000000)	// R/W
#define E2P_CMD_EPC_CMD_EWDS_	          (0x10000000)	// R/W
#define E2P_CMD_EPC_CMD_EWEN_	          (0x20000000)	// R/W
#define E2P_CMD_EPC_CMD_WRITE_	        (0x30000000)	// R/W
#define E2P_CMD_EPC_CMD_WRAL_	          (0x40000000)	// R/W
#define E2P_CMD_EPC_CMD_ERASE_	        (0x50000000)	// R/W
#define E2P_CMD_EPC_CMD_ERAL_	          (0x60000000)	// R/W
#define E2P_CMD_EPC_CMD_RELOAD_         (0x70000000)	// R/W
#define E2P_CMD_EPC_TIMEOUT_	          (0x08000000)	// RO
#define E2P_CMD_E2P_PROG_GO_	          (0x00000200)	// WO
#define E2P_CMD_E2P_PROG_DONE_ 	        (0x00000100)	// RO
#define E2P_CMD_EPC_ADDR_		            (0x000000FF)	// R/W
/*-------------------------------------------------------------------------*/
#define E2P_DATA			                  (0xB4) //EEPROM Data

#define E2P_DATA_EEPROM_DATA_	          (0x000000FF)	// R/W
/*-------------------------------------------------------------------------*/
#define TEST_REG_A			                (0xC0)

#define TEST_REG_A_FR_CNT_BYP_	        (0x00000008)	// R/W
#define TEST_REG_A_PME50M_BYP_	        (0x00000004)	// R/W
#define TEST_REG_A_PULSE_BYP_	          (0x00000002)	// R/W
#define TEST_REG_A_PS_BYP_		          (0x00000001)	// R/W

#define LAN_REGISTER_EXTENT 		        (0x00000100)
/*
 ****************************************************************************
 ****************************************************************************
 *	MAC Control and Status Register (Indirect Address)
 *	Offset (through the MAC_CSR CMD and DATA port)
 ****************************************************************************
 ****************************************************************************
 *
 */
#define MAC_CR				                (0x01)	// R/W

/* MAC_CR - MAC Control Register */
#define MAC_CR_RXALL_		              (0x80000000)
#define MAC_CR_HBDIS_		              (0x10000000)
#define MAC_CR_RCVOWN_		            (0x00800000)
#define MAC_CR_LOOPBK_		            (0x00200000)
#define MAC_CR_FDPX_		              (0x00100000)
#define MAC_CR_MCPAS_		              (0x00080000)
#define MAC_CR_PRMS_		              (0x00040000)
#define MAC_CR_INVFILT_ 	            (0x00020000)
#define MAC_CR_PASSBAD_ 	            (0x00010000)
#define MAC_CR_HFILT_		              (0x00008000)
#define MAC_CR_HPFILT_		            (0x00002000)
#define MAC_CR_LCOLL_		              (0x00001000)
#define MAC_CR_BCAST_		              (0x00000800)
#define MAC_CR_DISRTY_		            (0x00000400)
#define MAC_CR_PADSTR_		            (0x00000100)
#define MAC_CR_BOLMT_MASK_	          (0x000000C0)
#define MAC_CR_DFCHK_		              (0x00000020)
#define MAC_CR_TXEN_		              (0x00000008)
#define MAC_CR_RXEN_		              (0x00000004)

#define ADDRH				                  (0x02)	// R/W mask 0x0000FFFF
#define ADDRL				                  (0x03)	// R/W mask 0xFFFFFFFF
#define HASHH				                  (0x04)	// R/W
#define HASHL				                  (0x05)	// R/W

#define MII_ACC 			                (0x06)	// R/W

#define MII_ACC_PHY_ADDR_           	(0x0000F800)
#define MII_ACC_MIIRINDA_	            (0x000007C0)
#define MII_ACC_MII_WRITE_	          (0x00000002)
#define MII_ACC_MII_BUSY_	            (0x00000001)

#define MII_DATA			                (0x07)	// R/W mask 0x0000FFFF

#define FLOW				                  (0x08)	// R/W

#define FLOW_FCPT_			              (0xFFFF0000)
#define FLOW_FCPASS_		              (0x00000004)
#define FLOW_FCEN_			              (0x00000002)
#define FLOW_FCBSY_ 		              (0x00000001)

#define VLAN1				                  (0x09)	// R/W mask 0x0000FFFF
#define VLAN2				                  (0x0A)	// R/W mask 0x0000FFFF

#define WUFF				                  (0x0B)	// WO

#define FILTER3_COMMAND 	            (0x0F000000)
#define FILTER2_COMMAND 	            (0x000F0000)
#define FILTER1_COMMAND 	            (0x00000F00)
#define FILTER0_COMMAND 	            (0x0000000F)
#define FILTER3_ADDR_TYPE	            (0x04000000)
#define FILTER3_ENABLE	              (0x01000000)
#define FILTER2_ADDR_TYPE	            (0x00040000)
#define FILTER2_ENABLE	              (0x00010000)
#define FILTER1_ADDR_TYPE	            (0x00000400)
#define FILTER1_ENABLE	              (0x00000100)
#define FILTER0_ADDR_TYPE	            (0x00000004)
#define FILTER0_ENABLE	              (0x00000001)
#define FILTER3_OFFSET	            	(0xFF000000)
#define FILTER2_OFFSET		            (0x00FF0000)
#define FILTER1_OFFSET		            (0x0000FF00)
#define FILTER0_OFFSET		            (0x000000FF)

#define FILTER3_CRC 		              (0xFFFF0000)
#define FILTER2_CRC 		              (0x0000FFFF)
#define FILTER1_CRC 		              (0xFFFF0000)
#define FILTER0_CRC 		              (0x0000FFFF)

#define WUCSR				                  (0x0C)	// R/W

#define WUCSR_GUE_		              	(0x00000200)
#define WUCSR_WUFR_ 	              	(0x00000040)
#define WUCSR_MPR_			              (0x00000020)
#define WUCSR_WAKE_EN_		            (0x00000004)
#define WUCSR_MPEN_ 		              (0x00000002)


#define COE_CR				                (0x0D)	// R/W

#define TXCOE_EN_		              	  (0x00010000)
#define RXCOE_MODE_ 	              	(0x00000002)
#define RXCOE_EN_			                (0x00000001)
/*
 ****************************************************************************
 *	Chip Specific MII Defines
 ****************************************************************************
 *
 *	Phy register offsets and bit definitions
 *
 */
#define LAN911X_PHY_ID	(0x00C0001C)
/*-------------------------------------------------------------------------*/
#define PHY_BCR 	                  ((uint32_t)0)      //BCR寄存器
#define PHY_BCR_RESET_				      ((uint16_t)0x8000) //MII PHY复位
#define PHY_BCR_SPEED_SELECT_		    ((uint16_t)0x2000) //速度选择
#define PHY_BCR_AUTO_NEG_ENABLE_	  ((uint16_t)0x1000) //自动协调机制使能
#define PHY_BCR_POWER_DOWN_			    ((uint16_t)0x0800) //掉电
#define PHY_BCR_RESTART_AUTO_NEG_	  ((uint16_t)0x0200) //重新开始自动协调机制
#define PHY_BCR_DUPLEX_MODE_		    ((uint16_t)0x0100) //双工模式
/*-------------------------------------------------------------------------*/
#define PHY_BSR 	                  ((uint32_t)1)      //BSR寄存器
#define PHY_BSR_LINK_STATUS_	      ((uint16_t)0x0004) //连接状态
#define PHY_BSR_REMOTE_FAULT_	      ((uint16_t)0x0010) //远程故障
#define PHY_BSR_AUTO_NEG_COMP_	    ((uint16_t)0x0020) //自动协调机制比较
#define PHY_BSR_ANEG_ABILITY_	      ((uint16_t)0x0008) //自动协调机制能力
/*-------------------------------------------------------------------------*/
#define PHY_ID_1	                  ((uint32_t)2)
#define PHY_ID_2	                  ((uint32_t)3)
/*-------------------------------------------------------------------------*/
#define PHY_ANEG_ADV	              ((uint32_t)4)
#define PHY_ANEG_ADV_PAUSE_OP_		  ((uint16_t)0x0C00)
#define PHY_ANEG_ADV_ASYM_PAUSE_	  ((uint16_t)0x0800)
#define PHY_ANEG_ADV_SYM_PAUSE_ 	  ((uint16_t)0x0400)
#define PHY_ANEG_ADV_10H_			      ((uint16_t)0x0020)
#define PHY_ANEG_ADV_10F_			      ((uint16_t)0x0040)
#define PHY_ANEG_ADV_100H_			    ((uint16_t)0x0080)
#define PHY_ANEG_ADV_100F_			    ((uint16_t)0x0100)
#define PHY_ANEG_ADV_SPEED_ 		    ((uint16_t)0x01E0) 
/*-------------------------------------------------------------------------*/
#define PHY_ANEG_LPA	              ((uint32_t)5)
#define PHY_ANEG_LPA_100FDX_	      ((uint16_t)0x0100)
#define PHY_ANEG_LPA_100HDX_	      ((uint16_t)0x0080)
#define PHY_ANEG_LPA_10FDX_ 	      ((uint16_t)0x0040)
#define PHY_ANEG_LPA_10HDX_ 	      ((uint16_t)0x0020)
/*-------------------------------------------------------------------------*/
#define PHY_ANEG_EXP	              ((uint32_t)6)
#define PHY_ANEG_EXP_PDF_			      ((uint16_t)0x0010)
#define PHY_ANEG_EXP_LPNPA_ 		    ((uint16_t)0x0008)
#define PHY_ANEG_EXP_NPA_			      ((uint16_t)0x0004)
#define PHY_ANEG_EXP_PAGE_RX_		    ((uint16_t)0x0002)
#define PHY_ANEG_EXP_LPANEG_ABLE_	  ((uint16_t)0x0001)
/*-------------------------------------------------------------------------*/
#define PHY_MODE_CTRL_STS		        ((uint32_t)17) // Mode Control/Status Register
#define MODE_CTRL_STS_FASTRIP_		  ((uint16_t)0x4000)
#define MODE_CTRL_STS_EDPWRDOWN_	  ((uint16_t)0x2000)
#define MODE_CTRL_STS_LOWSQEN_		  ((uint16_t)0x0800)
#define MODE_CTRL_STS_MDPREBP_		  ((uint16_t)0x0400)
#define MODE_CTRL_STS_FARLOOPBACK_  ((uint16_t)0x0200)
#define MODE_CTRL_STS_FASTEST_		  ((uint16_t)0x0100)
#define MODE_CTRL_STS_REFCLKEN_ 	  ((uint16_t)0x0010)
#define MODE_CTRL_STS_PHYADBP_		  ((uint16_t)0x0008)
#define MODE_CTRL_STS_FORCE_G_LINK_ ((uint16_t)0x0004)
#define MODE_CTRL_STS_ENERGYON_ 	  ((uint16_t)0x0002)
/*-------------------------------------------------------------------------*/
#define PHY_INT_SRC 		            ((uint32_t)29)
#define PHY_INT_SRC_ENERGY_ON_			((uint16_t)0x0080)
#define PHY_INT_SRC_ANEG_COMP_			((uint16_t)0x0040)
#define PHY_INT_SRC_REMOTE_FAULT_		((uint16_t)0x0020)
#define PHY_INT_SRC_LINK_DOWN_			((uint16_t)0x0010)
/*-------------------------------------------------------------------------*/
#define PHY_INT_MASK		            ((uint32_t)30)
#define PHY_INT_MASK_ENERGY_ON_ 	  ((uint16_t)0x0080)
#define PHY_INT_MASK_ANEG_COMP_ 	  ((uint16_t)0x0040)
#define PHY_INT_MASK_REMOTE_FAULT_	((uint16_t)0x0020)
#define PHY_INT_MASK_LINK_DOWN_ 	  ((uint16_t)0x0010)
/*-------------------------------------------------------------------------*/
#define PHY_SPECIAL 		            ((uint32_t)31)
#define PHY_SPECIAL_SPD_	          ((uint16_t)0x001C)
#define PHY_SPECIAL_SPD_10HALF_ 	  ((uint16_t)0x0004)
#define PHY_SPECIAL_SPD_10FULL_ 	  ((uint16_t)0x0014)
#define PHY_SPECIAL_SPD_100HALF_	  ((uint16_t)0x0008)
#define PHY_SPECIAL_SPD_100FULL_	  ((uint16_t)0x0018)
/*-------------------------------------------------------------------------*/
#define TIMEOUT_VALUE           2000        // 2 seconds.
/*-------------------------------------------------------------------------*/
#define LINK_NO_LINK			  (0)
#define LINK_10MPS_HALF 		(1)
#define LINK_10MPS_FULL 		(2)
#define LINK_100MPS_HALF		(3)
#define LINK_100MPS_FULL		(4)

/*-------------------------------------------------------------------------*/
// 64MB =0X0400 0000
// BANK1 0X6000 0000 ~ 0X63FF FFFF  64MB
// BANK2 0X6400 0000 ~ 0X67FF FFFF  64MB
// BANK3 0X6800 0000 ~ 0X6CFF FFFF  64MB
// BANK4 0X6C00 0000 ~ 0X6FFF FFFF  64MB

#define Bank1_SRAM1_ADDR      ((uint32_t)0x60000000)
//#define Bank1_SRAM2_ADDR    ((uint32_t)0x64000000)
//#define Bank1_SRAM3_ADDR		((uint32_t)0x68000000)
//#define Bank1_SRAM4_ADDR    ((uint32_t)0x6C000000)
/*-------------------------------------------------------------------------*/

void bsp_InitExtEthernet(void);
uint8_t lan9220_Init(void);
void DumpAllRegs(void);

void lan9220_SendFrame(uint8_t *pBuffer, uint16_t length);
uint16_t lan9220_GetFrame(uint8_t *pBuffer);

uint8_t Get_FIFO_status(void);

void lan9220_EnableInts(void);
void lan9220_DisableInts(void);

//void lan9220_CurrentPacketFilter(uint32_t filter);
//void lan9220_MulticastList(uint8_t *pAddresses, uint32_t count);

void lan9220_SetLED(void);

void Lan_SetMacRegDW(const uint32_t dwCSR_Addr, const uint32_t dwVal);
uint32_t Lan_GetMacRegDW(const uint32_t dwCSR_Addr);

uint16_t Lan_GetPhyRegW(const uint32_t dwMiiIndex);
void SetRegDW(const uint32_t dwOffset, const uint32_t dwVal);
uint32_t GetRegDW(const uint32_t dwOffset);

void Eeprom_EnableAccess(void);
void Eeprom_DisableAccess(void);
BYTE Eeprom_ReadLocation(BYTE address);
uint8_t Eeprom_EnableEraseAndWrite(void);
uint8_t Eeprom_DisableEraseAndWrite(void);
uint8_t Eeprom_WriteLocation(BYTE address,BYTE data);
uint8_t Eeprom_EraseAll(void);
uint8_t Eeprom_Reload(void);
uint8_t Eeprom_SaveMacAddress(const uint8_t *pBuffer);

/*-------------------------------------------------------------------------*/
#endif /* __LAN9220_H__ */
