

#ifndef _SOCP_BALONG_H
#define _SOCP_BALONG_H

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
  头文件包含
**************************************************************************/

#include <soc_memmap.h>
#include <product_config.h>
#include "hi_socp.h"
#include <osl_common.h>
#include <bsp_sram.h>
#include "bsp_memmap.h"
#include "soc_memmap.h"
#include "soc_interrupts.h"
#include "bsp_shared_ddr.h"
#include <bsp_socp.h>
#include <bsp_om.h>


/**************************************************************************
  宏定义
**************************************************************************/
/*系统控制器*/
#define INTEGRATOR_SC_BASE			HI_SYSCTRL_BASE_ADDR
#define SOCP_REG_BASEADDR           HI_SOCP_REGBASE_ADDR_VIRT
/* interrupt definations*/
#define INT_LVL_SOCP  				(M3_SOCP_INT0)  /* 只处理APP的中断*/

/**************************************************************************
  寄存器定义,偏移地址
**************************************************************************/
#define SOCP_REG_GBLRST             (HI_SOCP_GLOBAL_SRST_CTRL_OFFSET)
#define SOCP_REG_INTTIMEOUT         (HI_SOCP_INT_TIMEOUT_OFFSET)
#define SOCP_REG_BUFTIMEOUT         (HI_SOCP_BUFFER_TIMEOUT_OFFSET)
#define SOCP_REG_DEC_PKTLEN         (HI_SOCP_DEC_PKT_LEN_CFG_OFFSET)
#define SOCP_REG_GBL_INTSTAT        (HI_SOCP_GLOBAL_INT_STATUS_OFFSET)

    /* 编码器 中断寄存器*/
#define SOCP_REG_ENC_MASK0          (HI_SOCP_ENC_CORE0_MASK0_OFFSET)
#define SOCP_REG_ENC_RAWINT0        (HI_SOCP_ENC_CORE0_RAWINT0_OFFSET)
#define SOCP_REG_ENC_INTSTAT0       (HI_SOCP_ENC_CORE0_INT0_OFFSET)
#define SOCP_REG_APP_MASK1          (HI_SOCP_ENC_CORE0_MASK1_OFFSET)
#define SOCP_REG_MODEM_MASK1        (HI_SOCP_ENC_CORE1_MASK1_OFFSET)
#define SOCP_REG_ENC_RAWINT1        (HI_SOCP_ENC_RAWINT1_OFFSET)
#define SOCP_REG_APP_INTSTAT1       (HI_SOCP_ENC_CORE0_INT1_OFFSET)
#define SOCP_REG_MODEM_INTSTAT1     (HI_SOCP_ENC_CORE1_INT1_OFFSET)
#define SOCP_REG_ENC_MASK2          (HI_SOCP_ENC_CORE0_MASK2_OFFSET)
#define SOCP_REG_ENC_RAWINT2        (HI_SOCP_ENC_CORE0_RAWINT2_OFFSET)
#define SOCP_REG_ENC_INTSTAT2       (HI_SOCP_ENC_CORE0_INT2_OFFSET)
#define SOCP_REG_APP_MASK3          (HI_SOCP_ENC_CORE0_MASK3_OFFSET)
#define SOCP_REG_MODEM_MASK3        (HI_SOCP_ENC_CORE1_MASK3_OFFSET)
#define SOCP_REG_ENC_RAWINT3        (HI_SOCP_ENC_RAWINT3_OFFSET)
#define SOCP_REG_APP_INTSTAT3       (HI_SOCP_ENC_CORE0_INT3_OFFSET)
#define SOCP_REG_MODEM_INTSTAT3     (HI_SOCP_ENC_CORE1_INT3_OFFSET)
#define SOCP_REG_ENC_CORE1_MASK0    (HI_SOCP_ENC_CORE1_MASK0_OFFSET)
#define SOCP_REG_ENC_CORE1_INT0     (HI_SOCP_ENC_CORE1_INT0_OFFSET)
#define SOCP_REG_ENC_CORE1_MASK2    (HI_SOCP_ENC_CORE1_MASK2_OFFSET)
#define SOCP_REG_ENC_CORE1_INT2     (HI_SOCP_ENC_CORE1_INT2_OFFSET)

/* 解码器中断寄存器*/
#define SOCP_REG_DEC_CORE0MASK0     (HI_SOCP_DEC_CORE0_MASK0_OFFSET)
#define SOCP_REG_DEC_MASK1          (HI_SOCP_DEC_CORE0_MASK1_OFFSET)
#define SOCP_REG_DEC_CORE0MASK2     (HI_SOCP_DEC_CORE0_MASK2_OFFSET)

/*编码器通道buffer寄存器*/
#define SOCP_REG_ENCSRC_BUFWPTR(m)  (HI_SOCP_ENC_SRC_BUFM_WPTR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_BUFRPTR(m)  (HI_SOCP_ENC_SRC_BUFM_RPTR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_BUFADDR(m)  (HI_SOCP_ENC_SRC_BUFM_ADDR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_BUFCFG0(m)  (HI_SOCP_ENC_SRC_BUFM_CFG0_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_BUFCFG1(m)  (HI_SOCP_ENC_SRC_BUFM_CFG1_0_OFFSET + m*0x40)

#define SOCP_REG_ENCSRC_RDQWPTR(m)  (HI_SOCP_ENC_SRC_RDQ_WPTR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_RDQRPTR(m)  (HI_SOCP_ENC_SRC_RDQ_RPTR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_RDQADDR(m)  (HI_SOCP_ENC_SRC_RDQ_BADDR_0_OFFSET + m*0x40)
#define SOCP_REG_ENCSRC_RDQCFG(m)   (HI_SOCP_ENC_SRC_RDQ_CFG_0_OFFSET + m*0x40)

#define SOCP_REG_ENCDEST_BUFWPTR(n) (HI_SOCP_ENC_DEST_BUFN_WPTR_0_OFFSET + n*0x20)
#define SOCP_REG_ENCDEST_BUFRPTR(n) (HI_SOCP_ENC_DEST_BUFN_RPTR_0_OFFSET + n*0x20)
#define SOCP_REG_ENCDEST_BUFADDR(n) (HI_SOCP_ENC_DEST_BUFN_ADDR_0_OFFSET + n*0x20)
#define SOCP_REG_ENCDEST_BUFCFG(n)  (HI_SOCP_ENC_DEST_BUFN_CFG_0_OFFSET + n*0x20)
#define SOCP_REG_ENCDEST_BUFTHRH(n) (HI_SOCP_ENC_DEST_BUFN_THRH_0_OFFSET + n*0x20)

/*解码器通道buffer寄存器*/
#define SOCP_REG_DECSRC_BUFWPTR(x)  (HI_SOCP_DEC_SRC_BUFX_WPTR_0_OFFSET + x*0x40)
#define SOCP_REG_DECSRC_BUFRPTR(x)  (HI_SOCP_DEC_SRC_BUFX_RPTR_0_OFFSET + x*0x40)
#define SOCP_REG_DECSRC_BUFADDR(x)  (HI_SOCP_DEC_SRC_BUFX_ADDR_0_OFFSET + x*0x40)
#define SOCP_REG_DECSRC_BUFCFG0(x)  (HI_SOCP_DEC_SRC_BUFX_CFG0_0_OFFSET + x*0x40)
#define SOCP_REG_DEC_BUFSTAT0(x)    (HI_SOCP_DEC_BUFX_STATUS0_0_OFFSET + x*0x40)
#define SOCP_REG_DEC_BUFSTAT1(x)    (HI_SOCP_DEC_BUFX_STATUS1_0_OFFSET + x*0x40)

#define SOCP_REG_DECDEST_BUFWPTR(y) (HI_SOCP_DEC_DEST_BUFY_WPTR_0_OFFSET + y*0x10)
#define SOCP_REG_DECDEST_BUFRPTR(y) (HI_SOCP_DEC_DEST_BUFY_RPTR_0_OFFSET + y*0x10)
#define SOCP_REG_DECDEST_BUFADDR(y) (HI_SOCP_DEC_DEST_BUFY_ADDR_0_OFFSET + y*0x10)
#define SOCP_REG_DECDEST_BUFCFG(y)  (HI_SOCP_DEC_DEST_BUFY_CFG0_0_OFFSET + y*0x10)


/**************************************************************************
  寄存器位域定义
**************************************************************************/
#define SOCP_APP_ENC_OUTOVFINT_MASK ((s32)(1 << 12))      /* 编码RDBUFFER完成中断 */
#define SOCP_APP_ENC_TFRINT_MASK ((s32)(1 << 15))      /* 编码MODEMCPU包头检测错误中断 */

/**************************************************************************
  通道最大值定义
**************************************************************************/
#define SOCP_MAX_ENCSRC_CHN             (0x20)
#define SOCP_MAX_ENCDST_CHN             (0x07)
#define SOCP_MAX_DECSRC_CHN             (0x04)
#define SOCP_MAX_DECDST_CHN             (0x10)

#define SOCP_ENCSRC_LPM3_BASE           (12)  /* LPM3 */
#define SOCP_ENCSRC_IOM3_BASE           (13)  /* IOM3  */
#define SOCP_ENCSRC_M3_NUM              (2)   /* add IOM3 */

#define SOCP_M3_CHN_SIZE			(0x2000)

#ifdef K3V3_LPM3_HAS_MODEM_FEATURE
/* K3V3需要保存安全寄存器 */
#define SOCP_DRX_REG_GBLRST_NUM     (16)
#else
#define SOCP_DRX_REG_GBLRST_NUM     (12)
#endif
#define SOCP_DRX_REG_ENCINT_NUM     (17)
#define SOCP_DRX_REG_DECINT_NUM     (19)

#define SOCP_REG_ADDR_DRX(addr)  (addr + SOCP_REG_BASEADDR)

#define SOCP_TRANS_TIMEOUT_DEFAULT      (0x17)     /*dec:23*/
#define SOCP_OVERFLOW_TIMEOUT_DEFAULT   (0x5969)   /*dec:22889*/

#define SOCP_DEC_PKTLGTH_MAX            (0x04)     /*dec:4096, 单位为KB*/
#define SOCP_DEC_PKTLGTH_MIN            (0x06)     /*dec:6, 单位为字节*/
#define SOCP_TIMEOUT_MAX                (0xffff)
#define SOCP_DEC_MAXPKT_MAX             (0x1000)
#define SOCP_DEC_MINPKT_MAX             (0x1f)
#define SOCP_ENC_SRC_BUFLGTH_MAX        (0x7ffffff)
#define SOCP_ENC_SRC_RDLGTH_MAX         (0xffff)
#define SOCP_ENC_DST_BUFLGTH_MAX        (0x1fffff)
#define SOCP_ENC_DST_TH_MAX             (0x7ff)
#define SOCP_DEC_SRC_BUFLGTH_MAX        (0xffff)
#define SOCP_DEC_SRC_RDLGTH_MAX         (0xffff)
#define SOCP_DEC_DST_BUFLGTH_MAX        (0xffff)
#define SOCP_DEC_DST_TH_MAX             (0xff)

/* 编码目的buffer上溢中断状态寄存器16-22位指示阈值溢出中断*/
#define SOCP_ENC_DST_BUFF_THRESHOLD_OVF_MASK    (0x007f0000)
#define SOCP_ENC_DST_BUFF_OVF_MASK              (0x0000007f)
/* 阈值中断寄存器起始位*/
#define SOCP_ENC_DST_BUFF_THRESHOLD_OVF_BEGIN   (16)
/* 指示SOCP状态的系统控制器偏移地址*/
#define SOCP_STATE_SC_OFFSET            0x668
#define SOCP_STATE_SC_MASK              0x00000001

#define SOCP_RESET_TIME                 (1000)
#define SOCP_GBLRESET_TIME              (100)


/* channel buffer ddr and regs backup ddr */
#ifdef K3V3_LPM3_HAS_MODEM_FEATURE
#define SOCP_DRX_BACKUP_DDR_ADDR        0x00026800//from lowpowerM3\lpm3.ld: AON_SOCP  //SHM_MEM_M3_MNTN_ADDR
#else
#define SOCP_DRX_BACKUP_DDR_ADDR        SHM_MEM_M3_MNTN_ADDR
#endif
#define SOCP_DRX_BACKUP_DDR_SIZE        (1024 *2)

#define SOCP_M3_LPM3_ENCSRC_ADDR        (SHM_MEM_M3_MNTN_ADDR + SOCP_DRX_BACKUP_DDR_SIZE)
#define SOCP_M3_IOM3_ENCSRC_ADDR        (SOCP_M3_LPM3_ENCSRC_ADDR + SOCP_M3_CHN_SIZE)

#ifdef K3V3_LPM3_HAS_MODEM_FEATURE
#define K3V3_SHARRED_DDR_SHIFT          (0x20000000)
#endif

/* 检测是否初始化的宏定义 */
#define SOCP_CHECK_INIT() \
    do {\
        if (!g_strSocpStat.bInitFlag)\
        {\
            return BSP_ERR_SOCP_NOT_INIT; \
        } \
    } while (0)

#define SOCP_CHECK_PARA(para) \
			do {\
				if (0 == para)\
				{\
					return BSP_ERR_SOCP_NULL; \
				} \
			} while (0)

/**************************************************************************
  结构定义
**************************************************************************/

/* 通道状态结构体，共四类 */
typedef struct tagSOCP_RING_BUF_S
{
    u32 u32Start;
    u32 u32End;
    u32 u32Write;
    u32 u32Read;
    u32 u32Length;
    u32 u32IdleSize;
} SOCP_RING_BUF_S;

/* 全局状态结构体 */
typedef struct tagSOCP_GBL_STATE
{
    int                 bInitFlag;
	u32                	u32IntEncDstTfr;
} SOCP_GBL_STATE;

/* 低功耗相关 begin */
typedef struct tagSOCP_DRX_ENCSRC_S
{
	u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32StartAddr;
	u32 u32Config0;
	u32 u32Config1;
	u32 u32RDWriteAddr;
	u32 u32RDReadAddr;
	u32 u32RDStartAddr;
	u32 u32RDConfig;
}SOCP_DRX_ENCSRC_S;

typedef struct tagSOCP_DRX_ENCDST_S
{
	u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32StartAddr;
	u32 u32Config;
	u32 u32Thrh;
}SOCP_DRX_ENCDST_S;


typedef struct tagSOCP_DRX_DECSRC_S
{
	u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32StartAddr;
	u32 u32Config;
}SOCP_DRX_DECSRC_S;

typedef struct tagSOCP_DRX_DECDST_S
{
	u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32StartAddr;
	u32 u32Config;
}SOCP_DRX_DECDST_S;

typedef struct tagBBPDMA_DRX_LOG_S
{
	u32 u32StartAddr;
    u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32Config;
}BBPDMA_DRX_LOG_S;

typedef struct tagBBPDMA_DRX_DS_S
{
	u32 u32StartAddr;
    u32 u32WriteAddr;
	u32 u32ReadAddr;
	u32 u32Config;
    u32 u32RegStart;
    u32 u32ChEn;
}BBPDMA_DRX_DS_S;
/* 低功耗相关 end */

/**************************************************************************
  函数声明
**************************************************************************/

s32 bsp_socp_get_write_buff(u32 u32SrcChanID, SOCP_BUFFER_RW_S *pBuff);
s32 bsp_socp_write_done(u32 u32SrcChanID, u32 u32WrtSize);
s32 bsp_socp_suspend(void);
void bsp_socp_resume(void);
void bsp_socp_enable(u32 u32SrcChanId);
void socp_memcpy(u32 *_dst, const u32 *_src, u32 len);
void socp_m3_init(void);

#ifdef K3V3_LPM3_HAS_MODEM_FEATURE
void bsp_socp_ccore_reset_stop_channel(void);
#endif

//#define BSP_REG(base, reg) (*(volatile u32 *)((u32)base + (reg)))

#define BSP_REG_SETBITS(base, reg, pos, bits, val) (BSP_REG(base, reg) = (BSP_REG(base, reg) & (~((((u32)1 << (bits)) - 1) << (pos)))) \
                                                                         | ((u32)((val) & (((u32)1 << (bits)) - 1)) << (pos)))
#define BSP_REG_GETBITS(base, reg, pos, bits) ((BSP_REG(base, reg) >> (pos)) & (((u32)1 << (bits)) - 1))

#define SOCP_REG_WRITE(reg, data) (writel(data, (SOCP_REG_BASEADDR + reg)))
#define SOCP_REG_READ(reg, result) (result = readl(SOCP_REG_BASEADDR + reg))
#define SOCP_REG_SETBITS(reg, pos, bits, val) BSP_REG_SETBITS(SOCP_REG_BASEADDR, reg, pos, bits, val)
#define SOCP_REG_GETBITS(reg, pos, bits) BSP_REG_GETBITS(SOCP_REG_BASEADDR, reg, pos, bits)

#ifdef __cplusplus
}
#endif

#endif

