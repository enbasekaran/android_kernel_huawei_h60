

/*****************************************************************************
  1 Include HeadFile
*****************************************************************************/
#include    "NasEsmInclude.h"

/*lint -e767*/
#define    THIS_FILE_ID        PS_FILE_ID_NASESMNWMSGDECODE_C
/*lint +e767*/


/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  2 Declare the Global Variable
*****************************************************************************/
NAS_ESM_MSG_IE_STRU                     g_ActDefltEpsbReq[] = {
{NAS_ESM_MSG_EPS_QOS_IEI,    0x00, NAS_MSG_FORMAT_LV,  1, 2, 10, NAS_ESM_DecodeNwSdfQosValue   },
{NAS_ESM_MSG_APN_IEI,        0x00, NAS_MSG_FORMAT_LV,  1, 2, 101,NAS_ESM_DecodeNwAPNValue      },
{NAS_ESM_MSG_PDN_IEI,        0x00, NAS_MSG_FORMAT_LV,  1, 6, 14, NAS_ESM_DecodeNwPDNValue      },
{NAS_ESM_MSG_TI_IEI,         0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 4 , NAS_ESM_DecodeTransactionId   },
{NAS_ESM_MSG_NQOS_IEI,       0xFF, NAS_MSG_FORMAT_TLV, 2, 14,18, NAS_ESM_DecodeNegotiatedQos   },
{NAS_ESM_MSG_NLS_IEI,        0xFF, NAS_MSG_FORMAT_TV,  1, 2, 2,  NAS_ESM_DecodeLlcSapi         },
{NAS_ESM_MSG_RADIO_PRIO_IEI, 0xF0, NAS_MSG_FORMAT_TV,  1, 1, 1,  NAS_ESM_DecodeRadioPriority   },
{NAS_ESM_MSG_PFI_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 3,  NAS_ESM_DecodePacketFlowId    },
{NAS_ESM_MSG_APN_AMBR_IEI,   0xFF, NAS_MSG_FORMAT_TLV, 2, 4, 8,  NAS_ESM_DecodeNwApnAmbrValue  },
{NAS_ESM_MSG_ESM_CAU_IEI,    0xFF, NAS_MSG_FORMAT_TV,  1, 2, 2,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,NAS_ESM_DecodeNwPco           }
};
#define  ACT_DEFLT_EPSB_REQ_MSG_IE_NUM  (sizeof(g_ActDefltEpsbReq)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_ActDedictEpsbReq[] = {
{NAS_ESM_MSG_EPS_QOS_IEI,    0x00, NAS_MSG_FORMAT_LV,  1, 2, 10, NAS_ESM_DecodeNwSdfQosValue   },
{NAS_ESM_MSG_TFT_IEI,        0xFF, NAS_MSG_FORMAT_LV,  1, 2, 256,NAS_ESM_DecodeNwTftValue      },
{NAS_ESM_MSG_TI_IEI,         0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 4,  NAS_ESM_DecodeTransactionId   },
{NAS_ESM_MSG_NQOS_IEI,       0xFF, NAS_MSG_FORMAT_TLV, 2,14, 18, NAS_ESM_DecodeNegotiatedQos   },
{NAS_ESM_MSG_NLS_IEI,        0xFF, NAS_MSG_FORMAT_TV,  1, 2, 2,  NAS_ESM_DecodeLlcSapi         },
{NAS_ESM_MSG_RADIO_PRIO_IEI, 0xF0, NAS_MSG_FORMAT_TV,  1, 1, 1,  NAS_ESM_DecodeRadioPriority   },
{NAS_ESM_MSG_PFI_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 3,  NAS_ESM_DecodePacketFlowId    },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR                  }
};
#define  ACT_DEDICT_EPSB_REQ_MSG_IE_NUM (sizeof(g_ActDedictEpsbReq)/sizeof(NAS_ESM_MSG_IE_STRU))


NAS_ESM_MSG_IE_STRU                     g_ModEpsbReq[] = {
{NAS_ESM_MSG_EPS_QOS_IEI,    0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 11, NAS_ESM_DecodeNwSdfQosValue   },
{NAS_ESM_MSG_TFT_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 257,NAS_ESM_DecodeNwTftValue      },
{NAS_ESM_MSG_NQOS_IEI,       0xFF, NAS_MSG_FORMAT_TLV, 2,14, 18, NAS_ESM_DecodeNegotiatedQos   },
{NAS_ESM_MSG_NLS_IEI,        0xFF, NAS_MSG_FORMAT_TV,  1, 2, 2,  NAS_ESM_DecodeLlcSapi         },
{NAS_ESM_MSG_RADIO_PRIO_IEI, 0xF0, NAS_MSG_FORMAT_TV,  1, 1, 1,  NAS_ESM_DecodeRadioPriority   },
{NAS_ESM_MSG_PFI_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 3,  NAS_ESM_DecodePacketFlowId    },
{NAS_ESM_MSG_APN_AMBR_IEI,   0xFF, NAS_MSG_FORMAT_TLV, 2, 4, 8,  NAS_ESM_DecodeNwApnAmbrValue  },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR                  }
};
#define  MOD_EPSB_REQ_MSG_IE_NUM (sizeof(g_ModEpsbReq)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_BearerResAllocRej[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR        }
};
#define  BEARER_RES_ALLOC_REJ_MSG_IE_NUM (sizeof(g_BearerResAllocRej)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_BearerResModRej[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR        }
};
#define  BEARER_RES_MOD_REJ_MSG_IE_NUM (sizeof(g_BearerResModRej)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_DeactEpsbReq[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR        }
};
#define  DEACT_EPSB_REQ_MSG_IE_NUM  (sizeof(g_DeactEpsbReq)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_PdnConRej[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR        }
};
#define  PDN_CON_REJ_MSG_IE_NUM  (sizeof(g_PdnConRej)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_PdnDisConRej[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        },
{NAS_ESM_MSG_PCO_IEI,        0xFF, NAS_MSG_FORMAT_TLV, 2, 3, 253,VOS_NULL_PTR        }
};
#define  PDN_DISCON_REJ_MSG_IE_NUM (sizeof(g_PdnDisConRej)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_EsmStatus[] = {
{NAS_ESM_MSG_ESM_CAU_IEI,    0x00, NAS_MSG_FORMAT_V,   0, 1, 1,  NAS_ESM_DecodeEsmCause        }
};
#define  ESM_STATUS_MSG_IE_NUM  (sizeof(g_EsmStatus)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_MSG_IE_STRU                     g_EsmNotification[] = {
{NAS_ESM_MSG_NI_IEI,         0x00, NAS_MSG_FORMAT_LV,  1, 2, 2,  NAS_ESM_DecodeNotificationIndicator}
};
#define  ESM_NOTIFICATION_MSG_IE_NUM  (sizeof(g_EsmNotification)/sizeof(NAS_ESM_MSG_IE_STRU))

NAS_ESM_DECODE_TABLE_STRU               g_EsmDecodeTable[] = {
{NAS_ESMCN_MSG_TYPE_ACT_DEFLT_EPS_BEARER_CNTXT_REQ,  0, ESM_ACT_DEFLT_EPS_BEARER_CNTXT_REQ,
 ACT_DEFLT_EPSB_REQ_MSG_IE_NUM,                      g_ActDefltEpsbReq                      },

{NAS_ESMCN_MSG_TYPE_ACT_DEDICTD_EPS_BEARER_CNTXT_REQ,1, ESM_ACT_DEDICT_EPS_BEARER_CNTXT_REQ,
 ACT_DEDICT_EPSB_REQ_MSG_IE_NUM,                     g_ActDedictEpsbReq                     },

{NAS_ESMCN_MSG_TYPE_MOD_EPS_BEARER_CNTXT_REQ,        0, ESM_MOD_EPS_BEARER_CNTXT_REQ,
 MOD_EPSB_REQ_MSG_IE_NUM,                            g_ModEpsbReq                           },

{NAS_ESMCN_MSG_TYPE_DEACT_EPS_BEARER_CNTXT_REQ,      0, ESM_DEACT_EPS_BEARER_CNTXT_REQ,
 DEACT_EPSB_REQ_MSG_IE_NUM,                          g_DeactEpsbReq                         },

{NAS_ESMCN_MSG_TYPE_PDN_CONNECT_REJ,                 0, ESM_PDN_CONNECT_REJ,
 PDN_CON_REJ_MSG_IE_NUM,                             g_PdnConRej                            },

{NAS_ESMCN_MSG_TYPE_PDN_DISCONNECT_REJ,              0, ESM_PDN_DISCONNECT_REJ,
 PDN_DISCON_REJ_MSG_IE_NUM,                          g_PdnDisConRej                         },

{NAS_ESMCN_MSG_TYPE_BEARER_RES_ALLOC_REJ,            0, ESM_BEARER_RESOUCE_ALLOC_REJ,
 BEARER_RES_ALLOC_REJ_MSG_IE_NUM,                    g_BearerResAllocRej                    },

{NAS_ESMCN_MSG_TYPE_BEARER_RES_MOD_REJ,              0, ESM_BEARER_RESOUCE_MOD_REJ,
 BEARER_RES_MOD_REJ_MSG_IE_NUM,                      g_BearerResModRej                      },

{NAS_ESMCN_MSG_TYPE_ESM_INFORMATION_REQ,             0, ESM_INFO_REQ,
 0,                                                  VOS_NULL_PTR                           },

{NAS_ESMCN_MSG_TYPE_ESM_STATUS,                      0, ESM_STUS_MT,
 ESM_STATUS_MSG_IE_NUM,                              g_EsmStatus                            },

{NAS_ESMCN_MSG_TYPE_ESM_NOTIFICATION,                0, ESM_NOTIFICATION_MT,
 ESM_NOTIFICATION_MSG_IE_NUM,                        g_EsmNotification                      }
};

#define g_EsmDecodeTableSize (sizeof(g_EsmDecodeTable)/sizeof(NAS_ESM_DECODE_TABLE_STRU))

/*****************************************************************************
  3 Function
*****************************************************************************/

VOS_UINT32  NAS_ESM_CheckIeLen
(
    const NAS_ESM_MSG_IE_STRU          *pstEsmMsgIe,
    VOS_UINT16                          usIeLen,
    VOS_UINT16                         *pusIeValueLen
)
{
    VOS_UINT16                          usFormatLen = NAS_ESM_NULL;
    VOS_UINT16                          usMinLen = pstEsmMsgIe->usMinLen;
    VOS_UINT16                          usMaxLen = pstEsmMsgIe->usMaxLen;

    usFormatLen = pstEsmMsgIe->ucFormatLen;

    /* 对于只有半字Type信元 ,需要加1 */
    if (0xf0 == pstEsmMsgIe->ucMask)
    {
        *pusIeValueLen = 1;
        return NAS_ESM_CAUSE_SUCCESS;
    }

    /* 对于没有长度指示的信元按照协议规定长度填写*/
    if ((NAS_MSG_FORMAT_TV == pstEsmMsgIe->enType)
     || (NAS_MSG_FORMAT_V == pstEsmMsgIe->enType))
    {
        *pusIeValueLen = usMinLen - usFormatLen;
        return NAS_ESM_CAUSE_SUCCESS;
    }

    *pusIeValueLen = usIeLen;

    /* 对于含有长度指示的信元按照协议规定长度进行检查*/
    if ((usMinLen > (usIeLen + usFormatLen)) || (usMaxLen < (usIeLen + usFormatLen)))
    {
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeMandatoryIei
(
    const NAS_ESM_MSG_IE_STRU           *pstEsmMsgIe,
    VOS_UINT16                          *pulSum,
    const VOS_UINT8                     *pucRcvNwMsg,
    VOS_UINT32                           ulRemainLen,
    NAS_ESM_NW_MSG_STRU                 *pstNwMsgRecord
)
{
    VOS_UINT16                          usIeValueLen = 0;
    NAS_ESM_CAUSE_ENUM_UINT8            enRst;

    /* 必选信元解码是必须的 */
    if (VOS_NULL_PTR == pstEsmMsgIe->pfDecodeFun)
    {
        return NAS_ESM_CAUSE_FEATURE_NOT_SUPPORTED;
    }

    /* 校验信元长度是否合法，并返回IE Value长度 */
    if (NAS_ESM_CAUSE_SUCCESS != NAS_ESM_CheckIeLen(pstEsmMsgIe,
                                                    pucRcvNwMsg[*pulSum],
                                                    &usIeValueLen))
    {
         return NAS_ESM_CAUSE_INVALID_MANDATORY_INFORMATION;
    }

    /* 剩余未译码长度小于要译码的信元长度，返回失败 */
    if ((usIeValueLen + pstEsmMsgIe->ucFormatLen) > ulRemainLen)
    {
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    if (NAS_MSG_FORMAT_LV == pstEsmMsgIe->enType)
    {
        /* 跳过L */
        *pulSum = *pulSum + 1;
    }

    /* 解码具体信元 */
    enRst = pstEsmMsgIe->pfDecodeFun(usIeValueLen,&pucRcvNwMsg[*pulSum],pstNwMsgRecord);

    if (NAS_ESM_CAUSE_SUCCESS == enRst)
    {
        *pulSum += usIeValueLen;
    }

    return enRst;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeOptinalIei
(
    const NAS_ESM_MSG_IE_STRU           *pstEsmMsgIe,
    VOS_UINT16                          *pulSum,
    const VOS_UINT8                     *pucRcvNwMsg,
    VOS_UINT32                           ulRemainLen,
    NAS_ESM_NW_MSG_STRU                 *pstNwMsgRecord
)
{
    VOS_UINT16                          usIeValueLen = 0;
    VOS_UINT16                          usIeLen      = 0;
    NAS_ESM_CAUSE_ENUM_UINT8            enRst;

    if (pstEsmMsgIe->ucIei != (pucRcvNwMsg[*pulSum] & pstEsmMsgIe->ucMask))
    {
        /* 忽略此信元 */
        return NAS_ESM_CAUSE_ERROR;
    }
    else
    {
        /* 普通掩码跳过Type字段 */
        if (0xF0 != pstEsmMsgIe->ucMask)
        {
            *pulSum = *pulSum + 1;
        }
    }

    /* 校验信元长度是否合法，并返回IE Value长度 */
    if (NAS_ESM_CAUSE_SUCCESS != NAS_ESM_CheckIeLen(pstEsmMsgIe,
                                                    pucRcvNwMsg[*pulSum],
                                                    &usIeValueLen))
    {
        *pulSum = *pulSum + 1 + usIeValueLen;
         return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    if (NAS_MSG_FORMAT_TLV == pstEsmMsgIe->enType)
    {
        /* 跳过L */
        *pulSum = *pulSum + 1;
    }

    /* 计算整个信元长度(如果有T和L，也包括T和L的长度) */
    if (0xF0 != pstEsmMsgIe->ucMask)
    {
        usIeLen = usIeValueLen + pstEsmMsgIe->ucFormatLen;
    }
    else
    {
        usIeLen = usIeValueLen;
    }

    /* 剩余未译码长度小于要译码的信元长度，返回失败 */
    if (usIeLen > ulRemainLen)
    {
        *pulSum  += usIeValueLen;
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    /* 不需要的可选信元可以直接跳过 */
    if (VOS_NULL_PTR == pstEsmMsgIe->pfDecodeFun)
    {
        *pulSum  += usIeValueLen;
        return NAS_ESM_CAUSE_SUCCESS;
    }

    /* 解码具体信元 */
    enRst = pstEsmMsgIe->pfDecodeFun(usIeValueLen,&pucRcvNwMsg[*pulSum],pstNwMsgRecord);

    /*if (NAS_ESM_CAUSE_SUCCESS == enRst)
    {
        *pulSum += usIeValueLen;
    }*/
    *pulSum += usIeValueLen;

    return enRst;
}


/*lint -e960*/
/*lint -e961*/
NAS_ESM_CAUSE_ENUM_UINT8    NAS_ESM_DecodeNwMsgIei
(
    VOS_UINT8                           ucIeMaxNum,
    VOS_UINT32                          ulRemainMsgLen,
    VOS_UINT32                         *pulDecodeMsgLen,
    const VOS_UINT8                    *pucRcvNwMsg,
    const NAS_ESM_MSG_IE_STRU          *pstEsmMsgIe,
    NAS_ESM_NW_MSG_STRU                *pstNwMsgRecord
)
{
    VOS_UINT16                          ulSum  = NAS_ESM_NULL;
    VOS_UINT8                           ucLoop = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enDecodeRst;

    VOS_UINT32                          ulDecodedIE = NAS_ESM_NULL;    /*记录已经解的信元 */
    VOS_UINT32                          ulDecodingIE = NAS_ESM_BIT_0;  /*记录正在解的信元 */
    VOS_UINT32                          ulTmpPos    = NAS_ESM_BIT_0;
    VOS_UINT16                          usIeValueLen = NAS_ESM_NULL;  /*跳过的信元IEI的长度 */
    VOS_UINT16                          usIeLen      = NAS_ESM_NULL; /*跳过的信元总长度 */

    /* 循环解析必选信元 */
    while ((NAS_ESM_IsMandatoryIei(pstEsmMsgIe[ucLoop].enType)) && (ulRemainMsgLen > ulSum))
    {
        enDecodeRst = NAS_ESM_DecodeMandatoryIei(&pstEsmMsgIe[ucLoop],
                                                 &ulSum,
                                                 pucRcvNwMsg,
                                                 ulRemainMsgLen - ulSum,
                                                 pstNwMsgRecord);

        if (NAS_ESM_CAUSE_SUCCESS != enDecodeRst)
        {
            *pulDecodeMsgLen = ulSum;

            if (NAS_ESM_CAUSE_PROTOCOL_ERROR == enDecodeRst)
            {
                enDecodeRst = NAS_ESM_CAUSE_INVALID_MANDATORY_INFORMATION;
            }

            return enDecodeRst;
        }

        ucLoop++;
    }

    /* 循环解析可选信元 */
    while (ulRemainMsgLen > ulSum)
    {
        ulDecodingIE = NAS_ESM_BIT_0;
        ulTmpPos    = NAS_ESM_BIT_0;

        for (ucLoop = 0; ucLoop < ucIeMaxNum; ucLoop++)
        {

            /*只要信元已经被解到过,直接跳过信元 */
            if (((ulDecodingIE | ulDecodedIE) == ulDecodedIE)&&
                ((pstEsmMsgIe + ucLoop)->ucIei == (pucRcvNwMsg[ulSum] & (pstEsmMsgIe+ucLoop)->ucMask)))
            {
                /* 校验信元长度是否合法，如果不合法直接返回，停止解码 */
                if (NAS_ESM_CAUSE_SUCCESS != NAS_ESM_CheckIeLen(&pstEsmMsgIe[ucLoop],
                                                                pucRcvNwMsg[ulSum + 1],
                                                                &usIeValueLen))
                {
                    *pulDecodeMsgLen = ulSum;
                    return NAS_ESM_SUCCESS;
                }

                /*计算跳过的信元的总长度 */
                usIeLen = (0xF0 != (pstEsmMsgIe+ucLoop)->ucMask)
                                ? (usIeValueLen + (pstEsmMsgIe+ucLoop)->ucFormatLen)
                                : (usIeValueLen);

                /*码流直接平移 */
                ulSum += usIeLen;

                NAS_ESM_LOG1("NAS_ESM_DecodeOptinalIei  skip repeated IEI: ", (pstEsmMsgIe+ucLoop)->ucIei);
                break;

            }

            /*记录正在解的信元 */
            ulDecodingIE = ulDecodingIE << 1;

            /*解码信元 */
            enDecodeRst = NAS_ESM_DecodeOptinalIei(&pstEsmMsgIe[ucLoop],
                                                   &ulSum,
                                                   pucRcvNwMsg,
                                                   ulRemainMsgLen - ulSum,
                                                   pstNwMsgRecord);


            if (NAS_ESM_CAUSE_SUCCESS != enDecodeRst)
            {
                continue;
            }

            /*记录已经解的信元 */
            ulDecodedIE |=  (ulTmpPos << ucLoop);

            break;
        }
        /*无法识别收到的NAS消息中的信元,也无法知道跳过码流的长度,可选信元解码失败
         不会影响正常功能,所以按照解码成功处理 */
        if (ucLoop >= ucIeMaxNum)
        {
            NAS_ESM_WARN_LOG("NAS_ESM_DecodeOptinalIei :(WARN)Some IEI not specified!");
            *pulDecodeMsgLen = ulSum;
            return NAS_ESM_CAUSE_SUCCESS;
        }
    }
    *pulDecodeMsgLen = ulSum;

    return NAS_ESM_CAUSE_SUCCESS;

}


VOS_VOID NAS_ESM_GetDecodeTableIndex( NAS_ESMCN_MSG_TYPE_ENUM_UINT8 enMsgType, VOS_UINT32 *pulIndex )
{
    VOS_UINT32                     ulLoop = NAS_ESM_NULL;

    for (ulLoop = 0; ulLoop < g_EsmDecodeTableSize; ulLoop++)
    {
        if (enMsgType == g_EsmDecodeTable[ulLoop].enMsgTyep)
        {
            break;
        }
    }

    *pulIndex = ulLoop;

     return;
}


NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeNwMsgValue
(
    VOS_UINT8                           *pucMsg,
    VOS_UINT32                          *pulDecodeLen,
    VOS_UINT32                          *pulDecodeTableIndex,
    NAS_ESM_NW_MSG_STRU                 *pstMsgIE
)
{
    VOS_UINT32                          ulIndex = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause      =  NAS_ESM_CAUSE_SUCCESS;
    VOS_UINT32                          ulSum           =  NAS_ESM_NULL;
    VOS_UINT32                          ulUnDecodeMsgLen = *pulDecodeLen;
    VOS_UINT32                          ulDecodeMsgLen  = NAS_ESM_NULL;
    VOS_UINT8*                          pucTmpMsg       =  pucMsg;
    NAS_ESM_NW_MSG_STRU                *pstTmpMsgIE     =  pstMsgIE;
    NAS_ESMCN_MSG_TYPE_ENUM_UINT8       enMsgType;

    /* 获取网络消息类型 */
    enMsgType = pucTmpMsg[ulSum];

    /* 根据消息类型得到解码表索引*/
    NAS_ESM_GetDecodeTableIndex(enMsgType,&ulIndex);

    /* 不在解码表中的消息类型直接返回错误 */
    if (ulIndex >= g_EsmDecodeTableSize)
    {
        NAS_ESM_NORM_LOG("NAS_ESM_DecodeNwMsgValue:this msg type not implement!");
        return NAS_ESM_CAUSE_MESSAGE_TYPE_NON_EXIST_OR_NOT_IMPLEMENTED;
    }

    *pulDecodeTableIndex = ulIndex;

    /*保存消息类型*/
    pstTmpMsgIE->enEsmCnMsgType = enMsgType;

    /*跳过Message type*/
    ulSum++;
    ulUnDecodeMsgLen--;

    if (g_EsmDecodeTable[ulIndex].ulWithLinkEpsb)
    {
        /*记录Linked EPS bearer identity*/
        pstTmpMsgIE->ucLinkedEpsbId     = pucTmpMsg[ulSum++] & NAS_ESM_MSG_LOW_BIT;
        pstTmpMsgIE->bitOpLinkedEpsbId  = NAS_ESM_OP_TRUE;
        ulUnDecodeMsgLen--;
    }

    /* 没有定义解码表的消息只存在已解码公共信息，此时已经解码结束 */
    if (VOS_NULL_PTR == g_EsmDecodeTable[ulIndex].pstEsmMsgIE)
    {
        *pulDecodeLen = ulSum;
        return NAS_ESM_CAUSE_SUCCESS;
    }

    /* 调用公共解码函数 */
    enEsmCause = NAS_ESM_DecodeNwMsgIei(g_EsmDecodeTable[ulIndex].ucMsgTableSize,
                                       ulUnDecodeMsgLen,
                                       &ulDecodeMsgLen,
                                       pucTmpMsg+ulSum,
                                       g_EsmDecodeTable[ulIndex].pstEsmMsgIE,
                                       pstTmpMsgIE);

    *pulDecodeLen = ulSum + ulDecodeMsgLen;
    return enEsmCause;

}


NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNwMsg(VOS_UINT8 *pucMsg,
                                         VOS_UINT32 *pulMsgLen,
                                         NAS_ESM_NW_MSG_STRU *pstMsgIE)
{
    VOS_UINT8                          *pucTmpMsg           = pucMsg;
    VOS_UINT8                           ucTmpBearerId       = NAS_ESM_NULL;
    VOS_UINT32                          ulSum               = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause          = NAS_ESM_NULL;
    VOS_UINT32                          ulUnDecodeMsgLength = *pulMsgLen;
    VOS_UINT32                          ulMsgLenTmp         = NAS_ESM_NULL;
    NAS_ESM_NW_MSG_STRU                *pstTmpMsgIE         = pstMsgIE;
    VOS_UINT32                          ulIndex             = NAS_ESM_NULL;

    /*打印进入该函数*/
    NAS_ESM_INFO_LOG("NAS_ESM_DecodeNwMsg is entered.");

    /*入口参数检查(pucMsg)*/
    if(ulUnDecodeMsgLength < NAS_ESM_MSG_MIN_LEN)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodeNwMsg:WARNING:->SM MSG is null!");
        return NAS_ESM_CAUSE_MSG_TOO_SHORT;
    }

    /*判断Protocol discriminator*/
    if(NAS_ESM_MSG_PD != (pucTmpMsg[ulSum] & NAS_ESM_MSG_LOW_BIT))
    {
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeNwMsg:WARNING:->SM MSG Protocol discriminator wrong!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    /*记录ucEPSBearerID*/
    /*信元检测,取消息第一字节中的5-8位为pulEpsbId
    ，判断是否符合协议，0000-0100为协议保留。*/
    ucTmpBearerId = (pucTmpMsg[ulSum] >> NAS_ESM_MOVEMENT_4_BITS)& NAS_ESM_MSG_LOW_BIT;

    /*保存pulEpsbId*/
    pstTmpMsgIE->ucEpsbId = ucTmpBearerId;


    /*跳过Protocol discriminator和EPS bearer identity*/
    ulSum++;

    /*保存PTI，跳过Procedure transaction identifier单元*/
    pstTmpMsgIE->ucPti = pucTmpMsg[ulSum];

    /*跳过PTI*/
    ulSum++;

    *pulMsgLen = ulSum;
    ulUnDecodeMsgLength -= NAS_ESM_SUM_LEN_OF_PD_EBI_PTI;
    ulMsgLenTmp = ulUnDecodeMsgLength;

    enEsmCause = NAS_ESM_DecodeNwMsgValue(pucMsg + ulSum,&ulMsgLenTmp,&ulIndex,pstTmpMsgIE);

    *pulMsgLen = *pulMsgLen + ulMsgLenTmp;

    if (NAS_ESM_CAUSE_MESSAGE_TYPE_NON_EXIST_OR_NOT_IMPLEMENTED != enEsmCause)
    {
        NAS_ESM_SndAirMsgReportInd(pucMsg,*pulMsgLen,
                                   NAS_ESM_AIR_MSG_DIR_ENUM_DOWN,
                                   g_EsmDecodeTable[ulIndex].enAirMsgId);
    }

    return enEsmCause;

}

VOS_UINT32 NAS_ESM_DecodeNwEsmMsgGetEsmCause(VOS_UINT8 *pucMsg,
                                         VOS_UINT32 ulMsgLen,
                                         NAS_ESM_CAUSE_ENUM_UINT8 *enEsmCause)
{
    VOS_UINT8                          *pucTmpMsg           = pucMsg;
    VOS_UINT8                           ucTmpBearerId       = NAS_ESM_NULL;
    VOS_UINT32                          ulSum               = NAS_ESM_NULL;
    VOS_UINT32                          ulUnDecodeMsgLength = ulMsgLen;
    VOS_UINT32                          ulMsgLenTmp         = NAS_ESM_NULL;
    NAS_ESM_NW_MSG_STRU                *pstTmpMsgIE;
    VOS_UINT32                          ulIndex             = NAS_ESM_NULL;

    /*打印进入该函数*/
    NAS_ESM_INFO_LOG("NAS_ESM_DecodeNwEsmMsgGetEsmCause is entered.");

    /*入口参数检查(pucMsg)*/
    if(ulUnDecodeMsgLength < NAS_ESM_MSG_MIN_LEN)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodeNwEsmMsgGetEsmCause:WARNING:->SM MSG is null!");
        return VOS_ERR;
    }

    /*判断Protocol discriminator*/
    if(NAS_ESM_MSG_PD != (pucTmpMsg[ulSum] & NAS_ESM_MSG_LOW_BIT))
    {
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeNwEsmMsgGetEsmCause:WARNING:->SM MSG Protocol discriminator wrong!");
        return VOS_ERR;
    }
    pstTmpMsgIE = (VOS_VOID *)NAS_ESM_MEM_ALLOC(sizeof(NAS_ESM_NW_MSG_STRU));
    if (VOS_NULL_PTR == pstTmpMsgIE)
    {
        NAS_ESM_ERR_LOG(" NAS_ESM_DecodeNwEsmMsgGetEsmCause: MSG ALLOC VOS_NULL_PTR  Null!");
        return VOS_ERR;
    }
    NAS_ESM_MEM_SET(pstTmpMsgIE,0,sizeof(NAS_ESM_NW_MSG_STRU));

    if( ulUnDecodeMsgLength > ESM_MAX_MSG_CONTAINER_CNTNTS_LEN )
    {
         NAS_ESM_WARN_LOG("NAS_ESM_DecodeNwEsmMsgGetEsmCause:WARNING:EMM->SM Message NW Msg over-long!");
         ulUnDecodeMsgLength = ESM_MAX_MSG_CONTAINER_CNTNTS_LEN;
    }

    /*记录ucEPSBearerID*/
    /*信元检测,取消息第一字节中的5-8位为pulEpsbId
    ，判断是否符合协议，0000-0100为协议保留。*/
    ucTmpBearerId = (pucTmpMsg[ulSum] >> NAS_ESM_MOVEMENT_4_BITS)& NAS_ESM_MSG_LOW_BIT;

    /*保存pulEpsbId*/
    pstTmpMsgIE->ucEpsbId = ucTmpBearerId;


    /*跳过Protocol discriminator和EPS bearer identity*/
    ulSum++;

    /*保存PTI，跳过Procedure transaction identifier单元*/
    pstTmpMsgIE->ucPti = pucTmpMsg[ulSum];

    /*跳过PTI*/
    ulSum++;

    ulUnDecodeMsgLength -= NAS_ESM_SUM_LEN_OF_PD_EBI_PTI;
    ulMsgLenTmp = ulUnDecodeMsgLength;

    if(NAS_ESM_CAUSE_SUCCESS == NAS_ESM_DecodeNwMsgValue(pucMsg + ulSum,&ulMsgLenTmp,&ulIndex,pstTmpMsgIE))
    {   if(NAS_ESM_OP_TRUE == pstTmpMsgIE->bitOpEsmCause)
        {
            *enEsmCause = pstTmpMsgIE->enEsmCau;
        }
        NAS_ESM_MEM_FREE(pstTmpMsgIE);
        return VOS_OK;
    }
    else
    {
        NAS_ESM_MEM_FREE(pstTmpMsgIE);
        return VOS_ERR;
    }
}


NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeTftNoOperation
(
    NAS_ESM_NW_MSG_STRU                *pstMsgIE,
    VOS_UINT8                          *pucMsg
)
{
    VOS_UINT8                           ucCnt       = NAS_ESM_NULL;
    VOS_UINT8                          *pTmp        = pucMsg;
    NAS_ESM_CONTEXT_TFT_STRU           *pstTftInfo  = VOS_NULL_PTR;

    if (pTmp[NAS_ESM_PARAMETER_ID_OFFSET] != NAS_ESM_TFT_PARA_LIST_ID)
    {
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeTftNoOperation:NW->TFT para list id is illegal!");
        return NAS_ESM_CAUSE_SEMANTIC_ERR_IN_TFT;
    }

    /*解码NO OPERATION*/
    pstMsgIE->stTadInfo.enTftOpType = NAS_ESM_TFT_OP_TYPE_NO_OP;
    pstMsgIE->stTadInfo.ucSdfPfNum  = pTmp[NAS_ESM_PARAMETER_LEN_OFFSET];

    for (ucCnt = NAS_ESM_NULL; ucCnt < pstMsgIE->stTadInfo.ucSdfPfNum; ucCnt++)
    {
        pstTftInfo = &pstMsgIE->stTadInfo.astSdfPfInfo[ucCnt];
        pstTftInfo->ucNwPacketFilterId = (pTmp[NAS_ESM_PARAMETER_LEN_OFFSET + 1 + ucCnt])
                                        &(NAS_ESM_MSG_LOW_BIT);
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeTftDeleteFilter
(
    NAS_ESM_NW_MSG_STRU                *pstMsgIE,
    VOS_UINT8                          *pucMsg
)
{
    VOS_UINT8                           ucCnt       = NAS_ESM_NULL;
    VOS_UINT8                           ucPfNum     = NAS_ESM_NULL;
    VOS_UINT8                          *pTmp        = pucMsg;
    NAS_ESM_CONTEXT_TFT_STRU           *pstTftInfo  = VOS_NULL_PTR;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    /* OCTET4 Packet filter identifier 1 */
    for (ucCnt = NAS_ESM_NULL; ucCnt < ucPfNum; ucCnt++)
    {
        pstTftInfo = &pstMsgIE->stTadInfo.astSdfPfInfo[ucCnt];
        pstTftInfo->ucNwPacketFilterId = (pTmp[NAS_ESM_PACKET_FILTER_ID_OFFSET + ucCnt])&(NAS_ESM_MSG_LOW_BIT);
    }

    pstMsgIE->stTadInfo.enTftOpType = NAS_ESM_TFT_OP_TYPE_DELETE_FILTER;
    pstMsgIE->stTadInfo.ucSdfPfNum = ucPfNum;

    return NAS_ESM_CAUSE_SUCCESS;
}

NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeFilterContent
(
    NAS_ESM_NW_MSG_STRU           *pstMsgIE,
    VOS_UINT8                     *pucMsg
)
{
    VOS_UINT8                           ucTad       = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause  = NAS_ESM_CAUSE_SUCCESS;
    VOS_UINT8                          *pTmp        = pucMsg;

    /*获取TFT操作码*/
    ucTad = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_HIGH_BIT;

    switch(ucTad)
    {
        case NAS_ESM_TFT_ADD_FILTER:
        case NAS_ESM_TFT_CREATE_TFT:
        case NAS_ESM_TFT_REPLACE_FILTER:
            enEsmCause = NAS_ESM_DecodeTftAddFilter(pstMsgIE, pTmp);
            break;
        case NAS_ESM_TFT_NO_OPERATION:
            enEsmCause = NAS_ESM_DecodeTftNoOperation(pstMsgIE, pTmp);
            break;
        case NAS_ESM_TFT_DELETE_TFT:
            pstMsgIE->stTadInfo.enTftOpType = NAS_ESM_TFT_OP_TYPE_DELETE_TFT;
            enEsmCause = NAS_ESM_CAUSE_SUCCESS;
            break;
        case NAS_ESM_TFT_DELETE_FILTER:
            enEsmCause = NAS_ESM_DecodeTftDeleteFilter(pstMsgIE, pTmp);
            break;
        default:
            return NAS_ESM_CAUSE_SEMANTIC_ERR_IN_TFT;
    }

    return enEsmCause;
}
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeTftAddFilter
(
    NAS_ESM_NW_MSG_STRU                *pstMsgIE,
    VOS_UINT8                          *pTmp
)
{
    VOS_UINT8                     ucPfNum     = NAS_ESM_NULL;
    VOS_UINT8                     ucTad       = NAS_ESM_NULL;
    VOS_UINT8                     ucLoop      = NAS_ESM_NULL;
    VOS_UINT8                     *pucTmp     = VOS_NULL_PTR;
    VOS_UINT8                     ucPfLength  = NAS_ESM_NULL;
    NAS_ESM_CONTEXT_TFT_STRU      *pstTftInfo = VOS_NULL_PTR;
    NAS_ESM_CAUSE_ENUM_UINT8      enEsmCause  = NAS_ESM_CAUSE_SUCCESS;

    /*获取TFT操作码*/
    ucTad = (pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_HIGH_3_BIT)
                                                    >> NAS_ESM_MOVEMENT_5_BITS;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    pucTmp = &(pTmp[NAS_ESM_PACKET_FILTER_ID_OFFSET]);

    /* 译码所有packet filter */
    for ( ucLoop = 0; ucLoop < ucPfNum; ucLoop++ )
    {
        pstTftInfo = &pstMsgIE->stTadInfo.astSdfPfInfo[ucLoop];

        /* 译码当前packet filter */
        enEsmCause = NAS_ESM_DecodeAddOneFilterTFT(pstTftInfo, pucTmp, &ucPfLength);

        if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
        {
            NAS_ESM_WARN_LOG( "NAS_ESM_DecodeTftAddFilter:WARNING:NW->TFT parse Err!");
            return enEsmCause;
        }

        /* 将指针指到下一个packet filter的起始位置 */
        pucTmp = pucTmp + ucPfLength + NAS_ESM_PACKET_FILTER_LEN_OFFSET;
    }

    /* 保存操作码和packet filter的个数 */
    pstMsgIE->stTadInfo.enTftOpType = ucTad;
    pstMsgIE->stTadInfo.ucSdfPfNum = ucPfNum;

    return NAS_ESM_CAUSE_SUCCESS;
}


NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftLenAddFilter
(
    VOS_UINT8                          *pucMsg,
    VOS_UINT8                           ucTftLength
)
{
    VOS_UINT8                           ucPfNum         = NAS_ESM_NULL;
    VOS_UINT8                           ucLoop          = NAS_ESM_NULL;
    VOS_UINT8                           ucAllPfLength   = NAS_ESM_NULL;
    VOS_UINT8                           ucPrePfLength   = NAS_ESM_NULL;
    VOS_UINT8                          *pTmp            = pucMsg;
    VOS_UINT8                          *pucTemp         = VOS_NULL_PTR;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    if(ucPfNum == NAS_ESM_NULL)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenAddFilter:PF number is zero!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    /* 判断长度是否合法 */
    if(ucTftLength < (NAS_ESM_TAD_BYTE + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN))
    {
         NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenAddFilter:WARNING:NW->SM TFT Length less than the least length!");
         return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    pucTemp = &(pTmp[NAS_ESM_PACKET_FILTER_LEN_OFFSET]);

    /* 获取所有packet filter所占总字节数 */
    ucPrePfLength = pTmp[NAS_ESM_PACKET_FILTER_LEN_OFFSET];
    ucAllPfLength = ucPrePfLength + (NAS_ESM_TAD_BYTE + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN);
    for ( ucLoop = 1; ucLoop < ucPfNum; ucLoop++ )
    {
         /* 判断长度是否合法 */
         if ((ucAllPfLength + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN) > ucTftLength)
         {
             NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenAddFilter:TFT Length Incorrect!");
             return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
         }

         /* 累加下一个packet filter的长度 */
         ucAllPfLength = ucAllPfLength +
                         pucTemp[ucPrePfLength + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN]
                         + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN;

         /* 将指针指到下一个packet filter的长度信元的位置 */
         pucTemp = &(pucTemp[ucPrePfLength + NAS_ESM_SUM_LEN_OF_PFID_PRECEDENCE_LEN]);

         /* 保存下一个packet filter的长度信元的值 */
         ucPrePfLength = *pucTemp;
    }

    /* 验证长度是否合法 */
    if (ucTftLength != ucAllPfLength)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenAddFilter: TFT Length mismatch!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}


NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftLenNoOperation
(
    VOS_UINT8                          *pucMsg,
    VOS_UINT8                           ucTftLength
)
{
    VOS_UINT8                           *pTmp       = pucMsg;
    VOS_UINT8                            ucPfNum    = NAS_ESM_NULL;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    if((pTmp[NAS_ESM_PARAMETER_LEN_OFFSET] != (ucTftLength - (NAS_ESM_PARAMETER_LEN_OFFSET + 1)))
        ||( NAS_ESM_NULL != ucPfNum))
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenNoOperation:NW->SM TFT Length Error!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftLenDeleteTft
(
    VOS_UINT8                          *pucMsg,
    VOS_UINT8                           ucTftLength
)
{
    VOS_UINT8                            ucPfNum    = NAS_ESM_NULL;
    VOS_UINT8                           *pTmp       = pucMsg;

    (VOS_VOID)ucTftLength;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    if(ucPfNum != NAS_ESM_NULL)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenDeleteTft:PF number is not zero!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftLenDeleteFilter
(
    VOS_UINT8                          *pucMsg,
    VOS_UINT8                           ucTftLength
)
{
    VOS_UINT8                            ucPfNum    = NAS_ESM_NULL;
    VOS_UINT8                           *pTmp       = pucMsg;

    /*获取packet filter个数*/
    ucPfNum = pTmp[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_LOW_BIT;

    if(ucPfNum == NAS_ESM_NULL)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenDeleteFilter:PF number is zero!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    if (ucTftLength != (ucPfNum + 1))
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidateTftLenDeleteFilter:NW->SM TFT Length Error!");
        return NAS_ESM_CAUSE_SYNTACTIC_ERR_IN_TFT;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftLen
(
    VOS_UINT8                          *pucMsg,
    VOS_UINT8                           ucTftLength
)
{
    VOS_UINT8                           ucTad       = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause  = NAS_ESM_CAUSE_SUCCESS;

    /*获取TFT操作码*/
    ucTad = pucMsg[NAS_ESM_TAD_PFNUM_OFFSET] & NAS_ESM_MSG_HIGH_BIT;

    switch(ucTad)
    {
        case NAS_ESM_TFT_ADD_FILTER:
        case NAS_ESM_TFT_CREATE_TFT:
        case NAS_ESM_TFT_REPLACE_FILTER:

            enEsmCause = NAS_ESM_ValidateTftLenAddFilter(pucMsg, ucTftLength);
            break;
        case NAS_ESM_TFT_NO_OPERATION:

            enEsmCause = NAS_ESM_ValidateTftLenNoOperation(pucMsg, ucTftLength);
            break;
        case NAS_ESM_TFT_DELETE_TFT:

            enEsmCause = NAS_ESM_ValidateTftLenDeleteTft(pucMsg, ucTftLength);
            break;
        case NAS_ESM_TFT_DELETE_FILTER:

            enEsmCause = NAS_ESM_ValidateTftLenDeleteFilter(pucMsg, ucTftLength);
            break;
        default:
            return NAS_ESM_CAUSE_SEMANTIC_ERR_IN_TFT;
    }

    return enEsmCause;
}
VOS_UINT32 NAS_ESM_IsExistSamePfIdInTft
(
    VOS_UINT32                          ulPfNum,
    const NAS_ESM_CONTEXT_TFT_STRU     *pstTFT
)
{
    VOS_UINT32                          ulCnt1 = NAS_ESM_NULL;
    VOS_UINT32                          ulCnt2 = NAS_ESM_NULL;

    for (ulCnt1 = NAS_ESM_NULL;ulCnt1 < ulPfNum;ulCnt1++)
    {
        for (ulCnt2 = ulCnt1 + 1 ;ulCnt2 < ulPfNum;ulCnt2++)
        {
            if (pstTFT[ulCnt1].ucNwPacketFilterId == pstTFT[ulCnt2].ucNwPacketFilterId)
            {
                return NAS_ESM_SUCCESS;
            }
        }
    }

    return NAS_ESM_FAILURE;
}
/*****************************************************************************
 Function Name   : NAS_ESM_ValidateTftIeAfterDecode
 Description     : TFT译码结束之后，马上对译码后的TFT信元进行合法性检测
 Input           : None
 Output          : None
 Return          : NAS_ESM_CAUSE_ENUM_UINT8

 History         :
    1.lihong00150010      2010-6-7  Draft Enact

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateTftIeAfterDecode
(
    const NAS_ESM_NW_MSG_STRU          *pstMsgIE
)
{
    VOS_UINT32                          ulRslt        = NAS_ESM_FAILURE;
    VOS_UINT32                          ulCnt         = NAS_ESM_NULL;
    const NAS_ESM_CONTEXT_TFT_STRU     *pstTmpTftInfo = VOS_NULL_PTR;

    /* 检测TFT信元中的packet filter id是否有重复 */
    ulRslt = NAS_ESM_IsExistSamePfIdInTft(pstMsgIE->stTadInfo.ucSdfPfNum,
                                          pstMsgIE->stTadInfo.astSdfPfInfo);
    if (NAS_ESM_SUCCESS == ulRslt)
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_ValidateTftIeAfterDecode:Same PfId in Cn msg !");
        return NAS_ESM_CAUSE_SYNCTACTIC_ERR_IN_PACKET_FILTER;
    }

    /* 若TAD码为CREATE_TFT或ADD_FILTER或REPLACE_FILTER，则检测TFT信元中的优先级
       是否有重复 */
    if ((NAS_ESM_TFT_OP_TYPE_CREATE_TFT == pstMsgIE->stTadInfo.enTftOpType)
        || (NAS_ESM_TFT_OP_TYPE_ADD_FILTER == pstMsgIE->stTadInfo.enTftOpType)
        || (NAS_ESM_TFT_OP_TYPE_REPLACE_FILTER == pstMsgIE->stTadInfo.enTftOpType))
    {
        /* 检测TFT信元中的precedence 是否有重复 */
        ulRslt = NAS_ESM_IsExistSamePrecedenceInTft(pstMsgIE->stTadInfo.ucSdfPfNum,
                                                    pstMsgIE->stTadInfo.astSdfPfInfo);
        if (NAS_ESM_SUCCESS == ulRslt)
        {
            /*返回消息检测失败*/
            NAS_ESM_WARN_LOG( "NAS_ESM_ValidateTftIeAfterDecode:Same precence in Cn msg !");
            return NAS_ESM_CAUSE_SYNCTACTIC_ERR_IN_PACKET_FILTER;
        }
    }

    /* 检查网络同时设置端口号和端口范围的错误 */
    for (ulCnt = NAS_ESM_NULL; ulCnt < pstMsgIE->stTadInfo.ucSdfPfNum ; ulCnt++)
    {
        pstTmpTftInfo = &pstMsgIE->stTadInfo.astSdfPfInfo[ulCnt];

        if(((NAS_ESM_OP_TRUE == pstTmpTftInfo->bitOpLocalPortRange)
            && (NAS_ESM_OP_TRUE == pstTmpTftInfo->bitOpSingleLocalPort))
         || ((NAS_ESM_OP_TRUE == pstTmpTftInfo->bitOpSingleRemotePort)
            && (NAS_ESM_OP_TRUE == pstTmpTftInfo->bitOpRemotePortRange)))
        {
            NAS_ESM_WARN_LOG( "NAS_ESM_ValidateTftIeAfterDecode:packetfilter port error !");
            return NAS_ESM_CAUSE_SEMANTIC_ERR_IN_PACKET_FILTER;
        }
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeNwTftValue
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause        = NAS_ESM_CAUSE_SUCCESS;
    VOS_UINT32                          ulSum             = NAS_ESM_NULL;
    const VOS_UINT8                    *pucTmpMsg         = pucMsg;
    VOS_UINT8                          *pTmp              = VOS_NULL_PTR;

    /*打印进入该函数*/
    NAS_ESM_INFO_LOG("NAS_ESM_DecodeEsmTft is entered.");

    pTmp     = (VOS_UINT8*) &(pucTmpMsg[ulSum]);

    /* 检测TAD码与PF个数的错误情况*/
    enEsmCause = NAS_ESM_ValidateTftLen(pTmp,(VOS_UINT8)usMsgLen);
    if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeEsmTft:NAS_ESM_ValidateTftLen failed!");
        return enEsmCause;
    }


    /* 根据TAD码分情况译码TFT */
    enEsmCause = NAS_ESM_DecodeFilterContent(pstMsgIE, pTmp);
    if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeEsmTft:NAS_ESM_DecodeFilterContent run Err!");
        return enEsmCause;
    }
    enEsmCause = NAS_ESM_ValidateTftIeAfterDecode(pstMsgIE);
    if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeEsmTft:NAS_ESM_ValidateTftIeAfterDecode failed!");
        return enEsmCause;
    }

    pstMsgIE->bitOpTadInfo = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}


VOS_VOID  NAS_ESM_EpsQosRateTranTo32
(
    VOS_UINT16                          usRate16,
    VOS_UINT32                         *pulRate32
)
{
    VOS_UINT8                           ucHigh = NAS_ESM_NULL;
    VOS_UINT8                           ucLow  = NAS_ESM_NULL;

    if (NAS_ESM_NULL == usRate16)
    {
        *pulRate32 = NAS_ESM_NULL;
        return;
    }

    ucHigh = (VOS_UINT8)((usRate16 & NAS_ESM_HIGH_BYTE) >> NAS_ESM_MOVEMENT_8_BITS);
    ucLow = (VOS_UINT8)(usRate16 & NAS_ESM_LOW_BYTE);

    /* 判断高8位是否为0 */
    if (NAS_ESM_NULL == ucHigh)
    {
        if (NAS_ESM_EPS_QOS_NULL_RATE2 == ucLow)
        {
            *pulRate32 = NAS_ESM_NULL;
            return;
        }

        /* 判断ucLow的第8位是否为0 */
        if (NAS_ESM_NULL != (ucLow >> NAS_ESM_MOVEMENT_7_BITS))
        {
            *pulRate32 = ((ucLow - (1 << NAS_ESM_MOVEMENT_7_BITS)) *
                            NAS_ESM_QOS_RATE_GRANULARITY_64KB) + NAS_ESM_QOS_RATE_576KB;
            return;
        }

        /* 判断ucLow的第7位是否为0 */
        if (NAS_ESM_NULL != (ucLow >> NAS_ESM_MOVEMENT_6_BITS))
        {
            *pulRate32 = ((ucLow - (1 << NAS_ESM_MOVEMENT_6_BITS)) *
                            NAS_ESM_QOS_RATE_GRANULARITY_8KB) + NAS_ESM_QOS_RATE_64KB;
            return;
        }

        *pulRate32 = ucLow;
    }
    else
    {
        /* 和01001010比较 */
        if (ucHigh <= NAS_ESM_QOS_RATE_RANGE_16000KB_GRANULARITY_64KB)
        {
            *pulRate32 = (ucHigh * NAS_ESM_QOS_RATE_GRANULARITY_100KB) +
                                                    NAS_ESM_QOS_RATE_8600KB;
            return;
        }

        /* 和10111010比较 */
        if (ucHigh <= NAS_ESM_QOS_RATE_RANGE_128MB_GRANULARITY_1MB)
        {
            *pulRate32 = ((ucHigh - NAS_ESM_QOS_RATE_RANGE_16000KB_GRANULARITY_64KB)
                            * NAS_ESM_QOS_RATE_GRANULARITY_1MB) + NAS_ESM_QOS_RATE_16MB;
            return;
        }

        /* 和11111010比较 */
        if (ucHigh <= NAS_ESM_QOS_RATE_RANGE_256MB_GRANULARITY_2MB)
        {
            *pulRate32 = ((ucHigh - NAS_ESM_QOS_RATE_RANGE_128MB_GRANULARITY_1MB)
                            * NAS_ESM_QOS_RATE_GRANULARITY_2MB) + NAS_ESM_QOS_RATE_128MB;
            return;
        }

        *pulRate32 = NAS_ESM_QOS_RATE_256MB;
    }
}
/*****************************************************************************
 Function Name   : NAS_ESM_DecodePcoIpItem
 Description     : 译码PCO信元中的IP项，如P-CSCF IPV4 ADDRESS，P-CSCF IPV6
                   ADDRESS，DNS SERVER IPV4 ADDRESS,DNS SERVER IPV6 ADDRESS
                   等
 Input           : None
 Output          : None
 Return          : NAS_ESM_CAUSE_ENUM_UINT8

 History         :
    1.lihong00150010      2010-6-13  Draft Enact

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodePcoIpItem
(
    const VOS_UINT8                     *pucMsg,
    NAS_ESM_CONTEXT_IP_ADDR_STRU        *pstIpAddr
)
{
    VOS_UINT8                           ucItemLen = NAS_ESM_NULL;
    VOS_UINT32                          ulSum     = NAS_ESM_NULL;

    /* 记录并跳过IP项长度 */
    ucItemLen = pucMsg[ulSum++];

    if (ucItemLen == APP_MAX_IPV4_ADDR_LEN)
    {
        pstIpAddr->ucIpType = NAS_ESM_PDN_IPV4;

        NAS_ESM_MEM_CPY(pstIpAddr->aucIpV4Addr,
                        &pucMsg[ulSum],
                        APP_MAX_IPV4_ADDR_LEN);
    }
    else if (ucItemLen == APP_MAX_IPV6_ADDR_LEN)
    {
        pstIpAddr->ucIpType = NAS_ESM_PDN_IPV6;

        NAS_ESM_MEM_CPY(pstIpAddr->aucIpV6Addr,
                        &pucMsg[ulSum],
                        APP_MAX_IPV6_ADDR_LEN);
    }
    else
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoIpItem:IP address length is illegal");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodePcoIpv4Item
 Description     : 译码PCO信元中的IP项，如P-CSCF IPV4 ADDRESS，P-CSCF IPV6
                   ADDRESS，DNS SERVER IPV4 ADDRESS,DNS SERVER IPV6 ADDRESS
                   等
 Input           : None
 Output          : None
 Return          : NAS_ESM_CAUSE_ENUM_UINT8

 History         :
    1.lihong00150010      2010-6-13  Draft Enact

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodePcoIpv4Item
(
    const VOS_UINT8                     *pucMsg,
    NAS_ESM_IPV4_ADDR_STRU              *pstIpAddr
)
{
    VOS_UINT8                           ucItemLen = NAS_ESM_NULL;
    VOS_UINT32                          ulSum     = NAS_ESM_NULL;

    /* 记录并跳过IP项长度 */
    ucItemLen = pucMsg[ulSum++];

    if (ucItemLen == APP_MAX_IPV4_ADDR_LEN)
    {
        NAS_ESM_MEM_CPY(pstIpAddr->aucIpV4Addr,
                        &pucMsg[ulSum],
                        APP_MAX_IPV4_ADDR_LEN);
    }
    else
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoIpv4Item:IP address length is illegal");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodePcoIpv6Item
 Description     : 译码PCO信元中的IP项，如P-CSCF IPV6 ADDRESS，DNS SERVER IPV6 ADDRESS
                   等
 Input           : None
 Output          : None
 Return          : NAS_ESM_CAUSE_ENUM_UINT8

 History         :
    1.lihong00150010      2010-6-13  Draft Enact

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodePcoIpv6Item
(
    const VOS_UINT8                     *pucMsg,
    NAS_ESM_IPV6_ADDR_STRU              *pstIpAddr
)
{
    VOS_UINT8                           ucItemLen = NAS_ESM_NULL;
    VOS_UINT32                          ulSum     = NAS_ESM_NULL;

    /* 记录并跳过IP项长度 */
    ucItemLen = pucMsg[ulSum++];

    if (ucItemLen == APP_MAX_IPV6_ADDR_LEN)
    {
        NAS_ESM_MEM_CPY(pstIpAddr->aucIpV6Addr,
                        &pucMsg[ulSum],
                        APP_MAX_IPV6_ADDR_LEN);
    }
    else
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoIpv6Item:IP address length is illegal");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}


/*****************************************************************************
 Function Name   : NAS_ESM_DecodePcoBcm
 Description     : 译码PCO信元中的BCM
 Input           : pucMsg
 Output          : pstPco
 Return          : VOS_VOID

 History         :
    1.lihong00150010      2011-04-27  Draft Enact

*****************************************************************************/
VOS_VOID  NAS_ESM_DecodePcoBcm
(
    const VOS_UINT8                     *pucMsg,
    NAS_ESM_CONTEXT_PCO_STRU            *pstPco
)
{
    VOS_UINT8                           ucItemLen = NAS_ESM_NULL;
    VOS_UINT32                          ulSum     = NAS_ESM_NULL;

    /* 记录并跳过IP项长度 */
    ucItemLen = pucMsg[ulSum++];

    /* 协议规定BCM的内容长度为1，若不为1，则忽略此项 */
    if (1 != ucItemLen)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoBcm:BCM len illegal!");
        return ;
    }

    /* 协议规定BCM的合法值为SM_ESM_BCM_MS_ONLY和SM_ESM_BCM_MS_NW */
    if ((SM_ESM_BCM_MS_ONLY!= pucMsg[ulSum]) && (SM_ESM_BCM_MS_NW != pucMsg[ulSum]))
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoBcm:BCM value illegal!");
        return ;
    }

    pstPco->enBcm       = pucMsg[ulSum];
    pstPco->bitOpBcm    = NAS_ESM_OP_TRUE;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidateIpcpLen
(
    const VOS_UINT8                    *pucMsg
)
{
    VOS_UINT8                           ucTmpLength         = NAS_ESM_NULL;
    const VOS_UINT8                    *pucTmpMsg           = pucMsg;
    VOS_UINT8                           ucSum               = NAS_ESM_NULL;

    /* 获取总长度 */
    ucTmpLength |= (VOS_UINT8)((pucTmpMsg[2] << 8));
    ucTmpLength |= pucTmpMsg[3];

    /* 判断是否可以读取长度 */
    if (ucTmpLength < (ucSum + NAS_ESM_IPCP_PACKET_HEAD_LEN))
    {
        NAS_ESM_INFO_LOG("NAS_ESM_ValidateIpcpLen:IPCP length is illegal!");

        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }
#if 0
    /* 判断长度是否合法 */
    if (ucTmpLength != pucTmpMsg[NAS_ESM_IPCP_PACKET_HEAD_LEN])
    {
        NAS_ESM_INFO_LOG("NAS_ESM_ValidateIpcpLen:Length is illegal!");

        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }
#endif
    /* 跳过IPCP的头长度 */
    ucSum += NAS_ESM_IPCP_PACKET_HEAD_LEN;

    /* 统计所有的长度 */
    while (ucTmpLength > ucSum)
    {
        /* 判断是否可以读取长度 */
        if (ucTmpLength < ((ucSum + NAS_ESM_IPCP_OPTION_HEAD_LEN) - 1))
        {
            NAS_ESM_INFO_LOG("NAS_ESM_ValidateIpcpLen:IPCP Opt length is illegal!");

            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
        }

        /* 判断长度不能为0，避免死循环 */
        if (NAS_ESM_NULL == pucTmpMsg[(ucSum + NAS_ESM_IPCP_OPTION_HEAD_LEN) - 1])
        {
            NAS_ESM_INFO_LOG("NAS_ESM_ValidateIpcpLen:IPCP Opt length is 0!");

            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
        }
        ucSum += pucTmpMsg[(ucSum + NAS_ESM_IPCP_OPTION_HEAD_LEN) -1];
    }

    /* 判断总长度是否相等 */
    if (ucTmpLength != ucSum)
    {
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_IsIpcpTypeValid
 Description     : 判断IPCP类型是否合法
 Input           : ucIpcpType       -- IPCP类型
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2010-09-13  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_ESM_IsIpcpTypeValid
(
    VOS_UINT8                          ucIpcpType
)
{
    if((ucIpcpType == NAS_ESM_IPCP_OPTIONS_PRI_DNS_ADDR)
       ||(ucIpcpType == NAS_ESM_IPCP_OPTIONS_SEC_DNS_ADDR))
    {
        return NAS_ESM_SUCCESS;
    }

    return NAS_ESM_FAILURE;
}


VOS_UINT8 NAS_ESM_CheckIpv4AddrIsEmpty(const NAS_ESM_IPV4_ADDR_STRU *pstIpAddr)
{
    if ( (0 == pstIpAddr->aucIpV4Addr[0])
        && (0 == pstIpAddr->aucIpV4Addr[1])
        && (0 == pstIpAddr->aucIpV4Addr[2])
        && (0 == pstIpAddr->aucIpV4Addr[3]))
    {
        return PS_TRUE;
    }

    return PS_FALSE;

}

VOS_VOID NAS_ESM_OptimizeDnsServer
(
    NAS_ESM_CONTEXT_PCO_STRU            *pstPco
)
{
    VOS_UINT8          ucPriDnsNoExist = PS_TRUE;
    VOS_UINT8          ucSecDnsNoExist = PS_TRUE;

    ucPriDnsNoExist = NAS_ESM_CheckIpv4AddrIsEmpty(&(pstPco->astIpv4DnsServer[0]));
    ucSecDnsNoExist = NAS_ESM_CheckIpv4AddrIsEmpty(&(pstPco->astIpv4DnsServer[1]));

    if ((PS_TRUE == ucPriDnsNoExist) && (PS_FALSE == ucSecDnsNoExist))
    {
        pstPco->ucIpv4DnsSerNum = 1;
        NAS_ESM_MEM_CPY((VOS_VOID*)&(pstPco->astIpv4DnsServer[0]),
                        (VOS_VOID*)&(pstPco->astIpv4DnsServer[1]),
                        sizeof(NAS_ESM_IPV4_ADDR_STRU));
        return;
    }

    if ((PS_FALSE == ucPriDnsNoExist) && (PS_TRUE == ucSecDnsNoExist))
    {
        pstPco->ucIpv4DnsSerNum = 1;
        return;
    }

    if ((PS_TRUE == ucPriDnsNoExist) && (PS_TRUE == ucSecDnsNoExist))
    {
        pstPco->ucIpv4DnsSerNum = 0;
        return;
    }

    if ((PS_FALSE == ucPriDnsNoExist) && (PS_FALSE == ucSecDnsNoExist))
    {
        pstPco->ucIpv4DnsSerNum = 2;
        return;
    }

}


NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeIpcpOptionContent
(
    const VOS_UINT8                     *pucMsg,
    VOS_UINT32                          *pulSum,
    NAS_ESM_CONTEXT_PCO_STRU            *pstPco

)
{
    const VOS_UINT8                    *pucTmpMsg           = pucMsg;
    NAS_ESM_CAUSE_ENUM_UINT8            enRslt;
    VOS_UINT32                          ulOptionLen = NAS_ESM_NULL;
    VOS_UINT32                          ulTempSum = *pulSum;


    NAS_ESM_INFO_LOG1("NAS_ESM_DecodeIpcpContent:configure-type:", pucMsg[*pulSum]);

    /* 检查当前的可选项总长度正确 */
    enRslt = NAS_ESM_ValidateIpcpLen(pucMsg + ulTempSum);
    if (NAS_ESM_CAUSE_SUCCESS != enRslt)
    {
        NAS_ESM_INFO_LOG("NAS_ESM_DecodeIpcpOptionContent:Lenth is illegal!");

        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }


    /*计算该IPCP option长度 */
    ulOptionLen |= (VOS_UINT8)((pucTmpMsg[ulTempSum + 2] << 8));
    ulOptionLen |= pucTmpMsg[ulTempSum + 3];


    /* 跳过头部结构 */
    ulTempSum += NAS_ESM_IPCP_PACKET_HEAD_LEN;

    while (ulTempSum < (*pulSum + ulOptionLen))
    {
        switch (pucTmpMsg[ulTempSum])
        {
            /* 译码主DNS Server信息 */
            case NAS_ESM_IPCP_OPTIONS_PRI_DNS_ADDR:

                /*跳过type字节*/
                ulTempSum++;

                /* 判断长度是否合法 */
                if (NAS_ESM_IPCP_OPTION_DNS_LEN != pucTmpMsg[ulTempSum])
                {
                    NAS_ESM_INFO_LOG("NAS_ESM_DecodeIpcpContent:DNS Lenth is illegal!");
                    *pulSum = ulTempSum;
                    return NAS_ESM_CAUSE_PROTOCOL_ERROR;
                }

                /*跳过length字节*/
                ulTempSum++;

                NAS_ESM_MEM_CPY((VOS_VOID*)pstPco->astIpv4DnsServer[0].aucIpV4Addr,
                                    (VOS_VOID*)&pucTmpMsg[ulTempSum],
                                    APP_MAX_IPV4_ADDR_LEN);


                /* 跳过IP地址 */
                ulTempSum += APP_MAX_IPV4_ADDR_LEN;

                break;


            case NAS_ESM_IPCP_OPTIONS_SEC_DNS_ADDR:

                /*跳过type字节*/
                ulTempSum++;

                /* 判断长度是否合法 */
                if (NAS_ESM_IPCP_OPTION_DNS_LEN != pucTmpMsg[ulTempSum])
                {
                    NAS_ESM_INFO_LOG("NAS_ESM_DecodeIpcpContent:DNS Lenth is illegal!");
                    *pulSum = ulTempSum;
                    return NAS_ESM_CAUSE_PROTOCOL_ERROR;
                }

                /*跳过length字节*/
                ulTempSum++;

                NAS_ESM_MEM_CPY((VOS_VOID*)pstPco->astIpv4DnsServer[1].aucIpV4Addr,
                                                    (VOS_VOID*)&pucTmpMsg[ulTempSum],
                                                    APP_MAX_IPV4_ADDR_LEN);


                /* 跳过IP地址 */
                ulTempSum += APP_MAX_IPV4_ADDR_LEN;

                break;

            default:
                /* 判断长度不能为0，避免死循环 */
                if (NAS_ESM_NULL == pucTmpMsg[ulTempSum + 1])
                {
                    *pulSum = ulTempSum;
                    return NAS_ESM_CAUSE_PROTOCOL_ERROR;
                }

                /* 跳过信元长度 */
                ulTempSum += pucTmpMsg[ulTempSum + 1];

                break;
        }
    }
    *pulSum = ulTempSum;
    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodeIpcpContent
 Description     : 译码IPCP的码流
IPCP
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|     Code      |  Identifier   |            Length             |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
| Options ...
+-+-+-+-+

IP:
  0                   1                   2                   3
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |     Type      |    Length     |           IP-Address
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
         IP-Address (cont)       |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

DNS Server Address
  0                   1                   2                   3
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |     Type      |    Length     |      Primary-NBNS-Address
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    Primary-NBNS-Address (cont)  |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

NBNS Server Address
  0                   1                   2                   3
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 |     Type      |    Length     |      Secondary-NBNS-Address
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   Secondary-NBNS-Address (cont) |
 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.sunbing49683      2010-7-15  Draft Enact
    2.yangfan00159566   2011-6-2   Modify

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeIpcpContent
(
    const VOS_UINT8                     *pucMsg,
    NAS_ESM_CONTEXT_PCO_STRU            *pstPco
)
{
    NAS_ESM_CAUSE_ENUM_UINT8            enRslt              = NAS_ESM_CAUSE_ERROR;
    VOS_UINT8                           ucTmpLength         = NAS_ESM_NULL;
    VOS_UINT32                          ulSum               = NAS_ESM_NULL;
    const VOS_UINT8                    *pucTmpMsg           = pucMsg;

    /* 获取length项 */
    ucTmpLength = pucTmpMsg[ulSum++];

#if 0
    /* 判断类型是否为CONFIGURE_NAK,为增强网络兼容性,可解码NAK/ACK/REJ/REQ*/
    if(pucTmpMsg[ulSum] != NAS_ESM_IPCP_MSG_TYPE_CONFIGURE_NAK)
    {
        NAS_ESM_INFO_LOG("NAS_ESM_DecodeIpcpContent:code is illegal!");
    }
#endif

    /* 判断总长度是否合法 */
    if (ucTmpLength < NAS_ESM_IPCP_PACKET_HEAD_LEN)
    {
        NAS_ESM_INFO_LOG("NAS_ESM_DecodeIpcpContent:IPCP length is illegal!");

        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    while (ucTmpLength > (ulSum -1))
    {
        enRslt = NAS_ESM_DecodeIpcpOptionContent(pucTmpMsg, &ulSum, pstPco);
        if (NAS_ESM_CAUSE_SUCCESS != enRslt)
        {
            return enRslt;
        }
    }

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_ValidatePcoLen
 Description     : 判断PCO信元长度的合法性
 Input           : pucMsg      -- 空口消息码流
                   ucPcoLength -- PCO结构长度
 Output          : None
 Return          : NAS_ESM_CAUSE_ENUM_UINT8

 History         :
    1.lihong00150010      2010-09-13  Draft Enact

*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_ValidatePcoLen
(
    const VOS_UINT8                    *pucMsg,
    VOS_UINT8                           ucPcoLength
)
{
    VOS_UINT8                           ucAllPcoLength  = NAS_ESM_NULL;
    VOS_UINT8                           ucPrePcoLength  = NAS_ESM_NULL;
    const VOS_UINT8                    *pTmp            = pucMsg;
    const VOS_UINT8                    *pucTemp         = VOS_NULL_PTR;

    /* 如果PCO长度为0，则返回失败 */
    if (NAS_ESM_NULL == ucPcoLength)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidatePcoLen:Pco length is 0!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    /* 如果PCO信元只包含配置协议项，则返回成功 */
    if (NAS_ESM_PCO_LEN_ONLY_CONFIGURAION_PROTOCOL == ucPcoLength)
    {
        return NAS_ESM_CAUSE_SUCCESS;
    }

    /* 判断长度是否合法 */
    if(ucPcoLength < (NAS_ESM_PCO_LEN_ONLY_CONFIGURAION_PROTOCOL + NAS_ESM_SUM_LEN_OF_ID_LEN))
    {
         NAS_ESM_WARN_LOG("NAS_ESM_ValidatePcoLen:Pco length is between (1,4)!");
         return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    pucTemp = &(pTmp[NAS_ESM_PCO_ITEM_LEN_OFFSET]);

    /* 获取所有packet filter所占总字节数 */
    ucPrePcoLength = pTmp[NAS_ESM_PCO_ITEM_LEN_OFFSET];
    ucAllPcoLength = ucPrePcoLength + (NAS_ESM_PCO_LEN_ONLY_CONFIGURAION_PROTOCOL
                                                    + NAS_ESM_SUM_LEN_OF_ID_LEN);
    while (ucPcoLength > ucAllPcoLength)
    {
         /* 判断长度是否合法 */
         if ((ucAllPcoLength + NAS_ESM_SUM_LEN_OF_ID_LEN) > ucPcoLength)
         {
             NAS_ESM_WARN_LOG("NAS_ESM_ValidatePcoLen:Pco Length Incorrect!");
             return NAS_ESM_CAUSE_PROTOCOL_ERROR;
         }

         /* 累加下一项的长度 */
         ucAllPcoLength =   ucAllPcoLength +
                            pucTemp[ucPrePcoLength + NAS_ESM_SUM_LEN_OF_ID_LEN]
                            + NAS_ESM_SUM_LEN_OF_ID_LEN;

         /* 将指针指到下一项的长度信元的位置 */
         pucTemp = &(pucTemp[ucPrePcoLength + NAS_ESM_SUM_LEN_OF_ID_LEN]);

         /* 保存下一项的长度信元的值 */
         ucPrePcoLength = *pucTemp;
    }

    /* 验证长度是否合法 */
    if (ucPcoLength != ucAllPcoLength)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_ValidatePcoLen: Pco Length mismatch!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodePcoContent
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulSum               = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause          = NAS_ESM_CAUSE_SUCCESS;
    const VOS_UINT8                    *pucTmpMsg           = pucMsg;
    NAS_ESM_CONTEXT_PCO_STRU           *pstPco              = &pstMsgIE->stPcoInfo;
    VOS_UINT16                          usPcoItemId         = NAS_ESM_NULL;
    /* lihong00150010 ims begin */
    NAS_ESM_IPV6_ADDR_STRU              stEmptyIpv6Addr     = {NAS_ESM_NULL};
    NAS_ESM_IPV4_ADDR_STRU              stEmptyIpv4Addr     = {NAS_ESM_NULL};
    /* lihong00150010 ims end */

    /* 如果PCO功能已关闭，则直接跳过PCO内容并返回成功 */
    if (NAS_ESM_PCO_OFF  == NAS_ESM_GetPcoFlag())
    {
        NAS_ESM_NORM_LOG("NAS_ESM_DecodePcoContent:PCO fuction is closed!");

        return NAS_ESM_SUCCESS;
    }

    /* 判断PCO携带的协议是否正确 */
    if (NAS_ESM_PCO_CONFIG_PROTOCOL != (pucTmpMsg[ulSum++] & NAS_ESM_HIGH_5_BIT_MASK))
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoContent:Pco Configaration Proctocol error!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    NAS_ESM_MEM_SET(&stEmptyIpv6Addr, NAS_ESM_NULL, sizeof(NAS_ESM_IPV6_ADDR_STRU));
    NAS_ESM_MEM_SET(&stEmptyIpv4Addr, NAS_ESM_NULL, sizeof(NAS_ESM_IPV4_ADDR_STRU));

    /* 逐一译码PCO所携带的各项内容 */
    while (usMsgLen > ulSum)
    {
        usPcoItemId = ((VOS_UINT16)pucTmpMsg[ulSum++] << NAS_ESM_MOVEMENT_8_BITS);
        usPcoItemId = usPcoItemId | (pucTmpMsg[ulSum++]);

        switch (usPcoItemId)
        {
            case NAS_ESM_PCO_ITEM_TYPE_DNS_SERVER_IPV6:

                /* DNS SERVER存储已满，则跳过此项 */
                if (pstPco->ucIpv6DnsSerNum >= NAS_ESM_MAX_DNS_SERVER_NUM)
                {
                    ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                    break;
                }

                enEsmCause = NAS_ESM_DecodePcoIpv6Item( &pucTmpMsg[ulSum],
                                                        &pstPco->astIpv6DnsServer[pstPco->ucIpv6DnsSerNum]);
                if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
                {
                    return enEsmCause;
                }
                /* 如果获取的IPv6 DNS内容为全零，代表网侧无此DNS，则不增加DNS数量 */
                if (NAS_ESM_MEM_CMP(&pstPco->astIpv6DnsServer[pstPco->ucIpv6DnsSerNum],
                                    &stEmptyIpv6Addr,
                                    sizeof(NAS_ESM_IPV6_ADDR_STRU)))
                {
                    pstPco->ucIpv6DnsSerNum++;
                }
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;
            case NAS_ESM_PCO_ITEM_TYPE_PCSCF_IPV4:

                /* P-CSCF存储已满，则跳过此项 */
                if (pstPco->ucIpv4PcscfNum >= NAS_ESM_MAX_PCSCF_NUM)
                {
                    ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                    break;
                }

                enEsmCause = NAS_ESM_DecodePcoIpv4Item(&pucTmpMsg[ulSum], &pstPco->astIpv4Pcscf[pstPco->ucIpv4PcscfNum]);
                if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
                {
                    return enEsmCause;
                }
                 /* lihong00150010 ims begin */
                /* 如果获取的IPv4 P-CSCF内容为全零，代表网侧无此P-CSCF，则不增加P-CSCF数量 */
                if (NAS_ESM_MEM_CMP(&pstPco->astIpv4Pcscf[pstPco->ucIpv4PcscfNum],
                                    &stEmptyIpv4Addr,
                                    sizeof(NAS_ESM_IPV4_ADDR_STRU)))
                {
                    pstPco->ucIpv4PcscfNum++;
                }
                 /* lihong00150010 ims end */
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;
            case NAS_ESM_PCO_ITEM_TYPE_BCM:
                NAS_ESM_DecodePcoBcm(&pucTmpMsg[ulSum], pstPco);
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;

            case NAS_ESM_PCO_ITEM_TYPE_DNS_SERVER_IPV4:

                /* DNS SERVER存储已满，则跳过此项 */
                if (pstPco->ucIpv4DnsSerNum >= NAS_ESM_MAX_DNS_SERVER_NUM)
                {
                    ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                    break;
                }

                enEsmCause = NAS_ESM_DecodePcoIpv4Item(&pucTmpMsg[ulSum], &pstPco->astIpv4DnsServer[pstPco->ucIpv4DnsSerNum]);
                if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
                {
                    return enEsmCause;
                }

                /* 如果获取的IPv4 DNS内容为全零，代表网侧无此DNS，则不增加DNS数量 */
                if (NAS_ESM_MEM_CMP(&pstPco->astIpv4DnsServer[pstPco->ucIpv4DnsSerNum],
                                    &stEmptyIpv4Addr,
                                    sizeof(NAS_ESM_IPV4_ADDR_STRU)))
                {
                    pstPco->ucIpv4DnsSerNum++;
                }
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;

            case NAS_ESM_PCO_ITEM_TYPE_IPCP:
                /*LV格式译码*/
                enEsmCause = NAS_ESM_DecodeIpcpContent(&pucTmpMsg[ulSum],pstPco);
                if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
                {
                    return enEsmCause;
                }

                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;

            /* lihong00150010 ims begin */
            case NAS_ESM_PCO_ITEM_TYPE_PCSCF_IPV6:

                /* P-CSCF存储已满，则跳过此项 */
                if (pstPco->ucIpv6PcscfNum >= NAS_ESM_MAX_PCSCF_NUM)
                {
                    ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                    break;
                }

                enEsmCause = NAS_ESM_DecodePcoIpv6Item(&pucTmpMsg[ulSum], &pstPco->astIpv6Pcscf[pstPco->ucIpv6PcscfNum]);
                if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
                {
                    return enEsmCause;
                }

                /* 如果获取的IPv6 P-CSCF内容为全零，代表网侧无此P-CSCF，则不增加P-CSCF数量 */
                if (NAS_ESM_MEM_CMP(&pstPco->astIpv6Pcscf[pstPco->ucIpv6PcscfNum],
                                    &stEmptyIpv6Addr,
                                    sizeof(NAS_ESM_IPV6_ADDR_STRU)))
                {
                    pstPco->ucIpv6PcscfNum++;
                }

                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;
            case NAS_ESM_PCO_ITEM_TYPE_IM_CN_SIGNAL_FLAG:
                pstPco->bitOpImsCnSignalFlag = NAS_ESM_OP_TRUE;
                pstPco->enImsCnSignalFlag = APP_ESM_PDP_FOR_IMS_CN_SIG_ONLY;
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;
            /* lihong00150010 ims end */
            default:

                /* 跳过此项内容 */
                ulSum += (pucTmpMsg[ulSum] + NAS_ESM_LEN_IE_OCTETS);
                break;
        }
    }
    /*重新调整DNS */
    NAS_ESM_OptimizeDnsServer(pstPco);

    /* 判断PCO各项内容之和是否等于PCO 长度IE */
    if (usMsgLen != ulSum)
    {
        NAS_ESM_WARN_LOG("NAS_ESM_DecodePcoContent:Pco length error!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}


/*lint -e415 -e416 -e661 -e662*/
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeNwPco
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    NAS_ESM_CAUSE_ENUM_UINT8            enEsmCause          = NAS_ESM_CAUSE_SUCCESS;

    /*打印进入该函数*/
    NAS_ESM_INFO_LOG("NAS_ESM_DecodeNwPco is entered.");

    enEsmCause = NAS_ESM_ValidatePcoLen(pucMsg,(VOS_UINT8)usMsgLen);
    if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeNwPco:NAS_ESM_ValidatePcoLen failed!");
        return enEsmCause;
    }

    enEsmCause = NAS_ESM_DecodePcoContent(usMsgLen, pucMsg, pstMsgIE);
    if (NAS_ESM_CAUSE_SUCCESS != enEsmCause)
    {
        return enEsmCause;
    }

    pstMsgIE->bitOpPco = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}/*lint +e415 +e416 +e661 +e662*/


NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNwPDNValue
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulSum            = NAS_ESM_NULL;
    const VOS_UINT8                    *pucTmpMsg        = pucMsg;
    NAS_ESM_CONTEXT_IP_ADDR_STRU       *pstPDNInfo       = &pstMsgIE->stPdnAddrInfo;

    (VOS_VOID)usMsgLen;

    #if 0
    /*判断PDN ADDRESS内容长度是否符合协议规范，目前只考虑IPV4的地址*/
    if (NAS_ESM_PDN_IPV4 != pucTmpMsg[ulSum])
    {
        /*返回消息检测失败*/
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }
    #endif

    /*内存空间初始化*/
    NAS_ESM_MEM_SET((VOS_VOID*)pstPDNInfo, 0, sizeof(NAS_ESM_CONTEXT_IP_ADDR_STRU));

    /*保存PDN地址内型*/
    pstPDNInfo->ucIpType = pucTmpMsg[ulSum++];

    switch(pstPDNInfo->ucIpType)
    {
        /*如果是IPV4内型地址，则保存，IPV4地址有4个字节*/
        case NAS_ESM_PDN_IPV4:
            NAS_ESM_MEM_CPY(pstPDNInfo->aucIpV4Addr, &pucTmpMsg[ulSum], APP_MAX_IPV4_ADDR_LEN);
            break;

        /*如果是IPV6内型地址，则保存，IPV4地址有16个字节,保留*/
        case NAS_ESM_PDN_IPV6:
            /*存放IPV6格式的地址*/
            NAS_ESM_MEM_CPY(pstPDNInfo->aucIpV6Addr + NAS_ESM_IPV6_IF_OFFSET, \
                            &pucTmpMsg[ulSum], NAS_ESM_IPV6_IF_LEN);
            break;

        /*如果支持IPV4和IPV6地址，按位保存，保留*/
        case NAS_ESM_PDN_IPV4_IPV6:
            /*依次存放IPV4和IPV6地址*/
            NAS_ESM_MEM_CPY(pstPDNInfo->aucIpV6Addr + NAS_ESM_IPV6_IF_OFFSET, \
                &pucTmpMsg[ulSum], NAS_ESM_IPV6_IF_LEN);
            NAS_ESM_MEM_CPY(pstPDNInfo->aucIpV4Addr, &pucTmpMsg[ulSum+NAS_ESM_IPV6_IF_LEN], APP_MAX_IPV4_ADDR_LEN);

            break;
        default:
            NAS_ESM_WARN_LOG("NAS_ESM_DecodeEsmPDN:WARNING:NW->SM Invalid mandatory information1!");
            NAS_ESM_MEM_SET((VOS_VOID*)pstPDNInfo,
                             0,
                             sizeof(NAS_ESM_CONTEXT_IP_ADDR_STRU));
            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    pstMsgIE->bitOpPdnAddr  = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNwAPNValue
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulRslt           = NAS_ESM_CAUSE_SUCCESS;
    const VOS_UINT8                    *pucTmpMsg        = pucMsg;
    NAS_ESM_CONTEXT_APN_STRU            stTmpAPNInfo;

    /*记录APN的长度,跳过APN的长度*/
    stTmpAPNInfo.ucApnLen = (VOS_UINT8)((usMsgLen)&0xFF);

    NAS_ESM_MEM_CPY(    stTmpAPNInfo.aucApnName,
                        &pucTmpMsg[0],
                        stTmpAPNInfo.ucApnLen);

    /* 译码APN */
    ulRslt = NAS_ESM_ApnReverseTransformation(&pstMsgIE->stApnInfo, &stTmpAPNInfo);

    if(NAS_ESM_SUCCESS != ulRslt)
    {
        /*打印异常信息*/
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    pstMsgIE->bitOpApn = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_SdfQosRateTran
(
    VOS_UINT8                           ucTmpLength,
    const VOS_UINT8                    *pucTmpMsg,
    NAS_ESM_CONTEXT_LTE_QOS_STRU       *pstTmpSdfQosInfo,
    VOS_UINT32                         *pulIndex
)
{
    VOS_UINT16                          usULMaxRateTmp   = NAS_ESM_NULL;
    VOS_UINT16                          usDLMaxRateTmp   = NAS_ESM_NULL;
    VOS_UINT16                          usULGMaxRateTmp  = NAS_ESM_NULL;
    VOS_UINT16                          usDLGMaxRateTmp  = NAS_ESM_NULL;
    VOS_UINT32                          ulSum            = NAS_ESM_NULL;
    VOS_UINT32                          ulIndex          = NAS_ESM_NULL;

    ulSum = ucTmpLength - 1;

    switch(ucTmpLength)
    {
        case NAS_ESM_QOS_OFFSET_ULMAXRATE:
            usULMaxRateTmp = pucTmpMsg[ulSum];
            ulIndex++;
            NAS_ESM_EpsQosRateTranTo32(usULMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulULMaxRate);
            break;
        case NAS_ESM_QOS_OFFSET_DLMAXRATE:
            usDLMaxRateTmp = pucTmpMsg[ulSum];
            ulIndex++;
            NAS_ESM_EpsQosRateTranTo32(usDLMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulDLMaxRate);
            break;
        case NAS_ESM_QOS_OFFSET_ULGMAXRATE:
            usULGMaxRateTmp = pucTmpMsg[ulSum];
            ulIndex++;
            NAS_ESM_EpsQosRateTranTo32(usULGMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulULGMaxRate);
            break;
        case NAS_ESM_QOS_OFFSET_DLGMAXRATE:
            usDLGMaxRateTmp = pucTmpMsg[ulSum];
            ulIndex++;
            NAS_ESM_EpsQosRateTranTo32(usDLGMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulDLGMaxRate);
            break;
        case NAS_ESM_QOS_OFFSET_ULMAXRATE_EXT:
            usULMaxRateTmp |= ((VOS_UINT16)pucTmpMsg[ulSum]) << NAS_ESM_MOVEMENT_8_BITS;
            ulIndex++;
            if (NAS_ESM_NULL != usULMaxRateTmp)
            {
                NAS_ESM_EpsQosRateTranTo32(usULMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulULMaxRate);
            }
            break;
        case NAS_ESM_QOS_OFFSET_DLMAXRATE_EXT:
            usDLMaxRateTmp |= ((VOS_UINT16)pucTmpMsg[ulSum]) << NAS_ESM_MOVEMENT_8_BITS;
            ulIndex++;
            if (NAS_ESM_NULL != usDLMaxRateTmp)
            {
                NAS_ESM_EpsQosRateTranTo32(usDLMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulDLMaxRate);
            }
            break;
        case NAS_ESM_QOS_OFFSET_ULGMAXRATE_EXT:
            usULGMaxRateTmp |= ((VOS_UINT16)pucTmpMsg[ulSum]) << NAS_ESM_MOVEMENT_8_BITS;
            ulIndex++;
            if (NAS_ESM_NULL != usULGMaxRateTmp)
            {
                NAS_ESM_EpsQosRateTranTo32(usULGMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulULGMaxRate);
            }
            break;
        case NAS_ESM_QOS_OFFSET_DLGMAXRATE_EXT:
            usDLGMaxRateTmp |= ((VOS_UINT16)pucTmpMsg[ulSum]) << NAS_ESM_MOVEMENT_8_BITS;
            ulIndex++;
            if (NAS_ESM_NULL != usDLGMaxRateTmp)
            {
                NAS_ESM_EpsQosRateTranTo32(usDLGMaxRateTmp, &pstTmpSdfQosInfo->stQosInfo.ulDLGMaxRate);
            }
            break;
        default:
            NAS_ESM_WARN_LOG("NAS_ESM_SdfQosRateTran:WARNING:Illegal Qos Offset!");
            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    *pulIndex = ulIndex;

    return NAS_ESM_CAUSE_SUCCESS;

}


VOS_VOID NAS_ESM_MapNwQciToStandardQci
(
    NAS_ESM_CONTEXT_LTE_QOS_STRU               *pstQosInfo,
    VOS_UINT8                                   ucQosLength
)
{
    if ((pstQosInfo->ucNwQCI >= NAS_ESM_QCI_TYPE_QCI1_GBR)
     && (pstQosInfo->ucNwQCI <= NAS_ESM_QCI_TYPE_QCI9_NONGBR))
    {
        /* 如果QCI在1~9之间那么网络的QCI就是标准的QCI */
        pstQosInfo->stQosInfo.ucQCI = pstQosInfo->ucNwQCI;
    }
    else if (NAS_ESM_QOS_LEN_ONLY_QCI == ucQosLength)
    {
        NAS_ESM_INFO_LOG("NAS_ESM_MapNwQciToStandardQci:network QCI is NO_GBR QCI.");

        /* 如果Qos的长度 等于3，那么网络QCI是NO_GBR的QOS */
        pstQosInfo->stQosInfo.ucQCI = NAS_ESM_QCI_TYPE_QCI6_NONGBR;
    }
    else
    {
        NAS_ESM_INFO_LOG("NAS_ESM_MapNwQciToStandardQci:network QCI is GBR QCI.");
        pstQosInfo->stQosInfo.ucQCI = NAS_ESM_QCI_TYPE_QCI2_GBR;
    }

}


NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNwSdfQosValue
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulSum            = NAS_ESM_NULL;
    VOS_UINT8                           ucCnt            = NAS_ESM_NULL;
    NAS_ESM_CAUSE_ENUM_UINT8            enRslt           = NAS_ESM_CAUSE_SUCCESS;
    const VOS_UINT8                    *pucTmpMsg        = pucMsg;
    NAS_ESM_CONTEXT_LTE_QOS_STRU       *pstTmpSdfQosInfo = VOS_NULL_PTR;

    if ((usMsgLen != NAS_ESM_QOS_LEN_ONLY_QCI)
     && (usMsgLen != NAS_ESM_QOS_LEN_NO_EXT)
     && (usMsgLen != NAS_ESM_QOS_LEN_ALL_QOS))
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_DecodeNwSdfQosValue:QOS length is not 1,5,9.");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }

    pstTmpSdfQosInfo = &pstMsgIE->stSdfQosInfo;

    pstTmpSdfQosInfo->ucNwQCI = pucTmpMsg[ulSum++];

    NAS_ESM_MapNwQciToStandardQci(pstTmpSdfQosInfo,(VOS_UINT8)usMsgLen);

    pucTmpMsg = pucTmpMsg + ulSum;

    ulSum = 0;

    /* 当GBR QOS 包含ULMaxRate和DLMaxRate时*/
    /* 则它们不能同时为0，否则返回错误*/
    if(usMsgLen > 2)
    {
        if (NAS_ESM_QOS_IS_NULL_RATE(pucTmpMsg[ulSum])
         && NAS_ESM_QOS_IS_NULL_RATE(pucTmpMsg[ulSum+1])
         && (PS_TRUE == NAS_ESM_IsGbrBearer(pstTmpSdfQosInfo->stQosInfo.ucQCI)))
        {
            NAS_ESM_WARN_LOG("NAS_ESM_DecodeEsmSdfQos:WARNING:NW->SDF QOS req null rate for both uplink and downlink!");
            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
        }
    }

    for(ucCnt = 1; ucCnt < usMsgLen; ucCnt++)
    {
        enRslt = NAS_ESM_SdfQosRateTran(ucCnt,pucTmpMsg,pstTmpSdfQosInfo,&ulSum);

        if ( NAS_ESM_CAUSE_SUCCESS!= enRslt)
        {
            return enRslt;
        }
    }

    pstMsgIE->bitOpEpsQos = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;

}
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_CheckNwApnAmbr
(
    VOS_UINT32                           ulMsgLen,
    const VOS_UINT8                     *pucMsg
)
{
#if 0
    VOS_UINT32                           ulSum              = NAS_ESM_NULL;
#endif
    /*判断APN AMBR长度是否符合协议*/
    if ((ulMsgLen != NAS_ESM_APN_AMBR_LEN_NO_EXT)
     && (ulMsgLen != NAS_ESM_APN_AMBR_LEN_EXT1)
     && (ulMsgLen != NAS_ESM_APN_AMBR_LEN_EXT2))
    {
        /*返回消息检测失败*/
        NAS_ESM_WARN_LOG( "NAS_ESM_CheckNwApnAmbr:APN AMBR decode Err!");
        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }
    (void)pucMsg;
#if 0
    /*协议并未说明APN-AMBR速率不能为零。故暂时先去掉此判断 */
    if ((NAS_ESM_APN_AMBR_IS_NULL_RATE(pucMsg[ulSum]))
     && (NAS_ESM_APN_AMBR_IS_NULL_RATE(pucMsg[ulSum + 1])))
    {
        NAS_ESM_WARN_LOG("NAS_ESM_CheckNwApnAmbr:APN AMBR req null rate for both uplink and downlink!");

        return NAS_ESM_CAUSE_PROTOCOL_ERROR;
    }
#endif
    return NAS_ESM_CAUSE_SUCCESS;
}
NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeNwApnAmbrValue
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulSum  = NAS_ESM_NULL;
    VOS_UINT16                          usLoop;
    NAS_ESM_CAUSE_ENUM_UINT8            enRslt              = NAS_ESM_CAUSE_SUCCESS;
    NAS_ESM_CONTEXT_APN_AMBR_STRU      *pstApnAmbrInfo      = &pstMsgIE->stApnAmbrInfo;;

    enRslt = NAS_ESM_CheckNwApnAmbr(usMsgLen,pucMsg);

    if ( NAS_ESM_CAUSE_SUCCESS != enRslt )
    {
        return enRslt;
    }

    for(usLoop = 0; usLoop < usMsgLen; usLoop++)
    {
        switch(usLoop)
        {
            case NAS_ESM_APN_AMBR_OFFSET_DLRATE:
                pstApnAmbrInfo->ucDLApnAmbr = pucMsg[ulSum++];
                break;
            case NAS_ESM_APN_AMBR_OFFSET_ULRATE:
                pstApnAmbrInfo->ucULApnAmbr = pucMsg[ulSum++];
                break;
            case NAS_ESM_APN_AMBR_OFFSET_DLEXT1:
                pstApnAmbrInfo->bitOpDLApnAmbrExt = NAS_ESM_OP_TRUE;
                pstApnAmbrInfo->ucDLApnAmbrExt = pucMsg[ulSum++];
                break;
            case NAS_ESM_APN_AMBR_OFFSET_ULEXT1:
                pstApnAmbrInfo->bitOpULApnAmbrExt = NAS_ESM_OP_TRUE;
                pstApnAmbrInfo->ucULApnAmbrExt = pucMsg[ulSum++];
                break;
            case NAS_ESM_APN_AMBR_OFFSET_DLEXT2:
                pstApnAmbrInfo->bitOpDLApnAmbrExt2 = NAS_ESM_OP_TRUE;
                pstApnAmbrInfo->ucDLApnAmbrExt2 = pucMsg[ulSum++];
                break;
            case NAS_ESM_APN_AMBR_OFFSET_ULEXT2:
                pstApnAmbrInfo->bitOpULApnAmbrExt2 = NAS_ESM_OP_TRUE;
                pstApnAmbrInfo->ucULApnAmbrExt2 = pucMsg[ulSum++];
                break;

            default:
                NAS_ESM_WARN_LOG("NAS_ESM_DecodeEsmApnAmbr:WARNING:Illegal APN-AMBR Offset!");
                return NAS_ESM_CAUSE_PROTOCOL_ERROR;
        }
    }

    pstMsgIE->bitOpApnAmbr = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}


NAS_ESM_CAUSE_ENUM_UINT8  NAS_ESM_DecodeEsmCause
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    (VOS_VOID)usMsgLen;
    pstMsgIE->bitOpEsmCause = NAS_ESM_OP_TRUE;
    pstMsgIE->enEsmCau      = pucMsg[0];

    /* xiongxianghui00253310 modify for ftmerrlog begin */
    #if (FEATURE_PTM == FEATURE_ON)
    NAS_ESM_GetFtmInfoEsmCause() = pstMsgIE->enEsmCau;
    #endif
    /* xiongxianghui00253310 modify for ftmerrlog end  */

    return NAS_ESM_CAUSE_SUCCESS;
}



NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeAddOneFilterTFT
(
    NAS_ESM_CONTEXT_TFT_STRU           *pstTFTInfo,
    const VOS_UINT8                    *pucTFTMsg,
    VOS_UINT8                          *pucLength
)
{
    VOS_UINT8                           ucCnt       = NAS_ESM_NULL;
    VOS_UINT8                           ucTmp       = NAS_ESM_NULL;
    VOS_UINT8                           ucLength    = NAS_ESM_NULL;
    const VOS_UINT8                    *pTmp        = pucTFTMsg;

    /*判断消息内容的合法性，如果不合法，则退出;
      pTmp[3]    = filter1中的所有4个components的长度和
                 = TFT码流数组的字节数- TFT码流前边4个域的字节数*/
    /* 判断TFT是否是uplink only */
    ucTmp = (pTmp[ucCnt] >> NAS_ESM_MOVEMENT_4_BITS) & NAS_ESM_LOW_2_BIT_MASK;

    /* OCTET4 Packet filter identifier 1 */
    pstTFTInfo->ucNwPacketFilterId = (pTmp[ucCnt])&(NAS_ESM_MSG_LOW_BIT);

    pstTFTInfo->enDirection      = ucTmp;

    /* OCTET5 ,Packet filter evaluation precedence 1 */
    ucCnt = ucCnt + 1;
    pstTFTInfo->ucPrecedence = pTmp[ucCnt++];

    /* 取出Length of Pactket fileter contents1*/
    ucLength = pTmp[ucCnt++];


    while(ucLength > (ucCnt - NAS_ESM_PACKET_FILTER_LEN_OFFSET))
    {
        switch(pTmp[ucCnt++])
        {
            /* component 是 IPv4 source address type */
            case NAS_ESM_TFT_IPV4_ADDR:
                pstTFTInfo->bitOpRmtIpv4AddrAndMask = NAS_ESM_OP_TRUE;
                pstTFTInfo->aucRmtIpv4Address[0] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Address[1] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Address[2] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Address[3] = pTmp[ucCnt++ ];

                pstTFTInfo->aucRmtIpv4Mask[0] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Mask[1] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Mask[2] = pTmp[ucCnt++ ];
                pstTFTInfo->aucRmtIpv4Mask[3] = pTmp[ucCnt++ ];
                break;

            case NAS_ESM_TFT_IPV6_ADDR:

            /*存放IPV6格式的地址和mask*/
                pstTFTInfo->bitOpRmtIpv6AddrAndMask = NAS_ESM_OP_TRUE;
                pstTFTInfo->aucRmtIpv6Address[0] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[1] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[2] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[3] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[4] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[5] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[6] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[7] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[8] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[9] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[10] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[11] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[12] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[13] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[14] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Address[15] = pTmp[ucCnt++];

                pstTFTInfo->aucRmtIpv6Mask[0] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[1] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[2] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[3] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[4] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[5] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[6] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[7] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[8] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[9] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[10] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[11] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[12] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[13] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[14] = pTmp[ucCnt++];
                pstTFTInfo->aucRmtIpv6Mask[15] = pTmp[ucCnt++];
            break;

            /* component是 Protocol identifier/Next header type*/
            case NAS_ESM_TFT_PROTOCOL_ID:
                pstTFTInfo->bitOpProtocolId = NAS_ESM_OP_TRUE;
                pstTFTInfo->ucProtocolId = pTmp[ucCnt++ ];
                break;

            /* component是 Single Destination port type */
            case NAS_ESM_TFT_SINGLE_LOCAL_PORT:
                pstTFTInfo->bitOpSingleLocalPort= NAS_ESM_OP_TRUE;

                pstTFTInfo->usSingleLcPort= (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usSingleLcPort= pstTFTInfo->usSingleLcPort
                        |pTmp[ucCnt++ ] ;
                break;

            /* component是 Destination port range type */
            case NAS_ESM_TFT_LOCAL_PORT_RANG:
                pstTFTInfo->bitOpLocalPortRange= NAS_ESM_OP_TRUE;

                /*port range low limit先收到*/
                pstTFTInfo->usLcPortLowLimit= (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usLcPortLowLimit = pstTFTInfo->usLcPortLowLimit
                        |pTmp[ucCnt++ ] ;
                pstTFTInfo->usLcPortHighLimit= (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usLcPortHighLimit= pstTFTInfo->usLcPortHighLimit
                        |pTmp[ucCnt++ ] ;
                break;

            /* component是 Single Source port type */
            case NAS_ESM_TFT_SINGLE_REMOTE_PORT:
                pstTFTInfo->bitOpSingleRemotePort= NAS_ESM_OP_TRUE;

                pstTFTInfo->usSingleRmtPort= (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usSingleRmtPort= pstTFTInfo->usSingleRmtPort
                        |pTmp[ucCnt++ ] ;
                break;

            /* component是 Source port range type */
            case NAS_ESM_TFT_REMOTE_PORT_RANG:
                pstTFTInfo->bitOpRemotePortRange = NAS_ESM_OP_TRUE;

                /*port range low limit先收到*/
                pstTFTInfo->usRmtPortLowLimit = (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usRmtPortLowLimit = pstTFTInfo->usRmtPortLowLimit
                        |pTmp[ucCnt++ ] ;
                pstTFTInfo->usRmtPortHighLimit= (VOS_UINT16)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->usRmtPortHighLimit= pstTFTInfo->usRmtPortHighLimit
                        |pTmp[ucCnt++ ] ;
                break;

            /* component是 Security parameter Index type */
            case NAS_ESM_TFT_SPI:
                pstTFTInfo->bitOpSecuParaIndex = NAS_ESM_OP_TRUE;

                pstTFTInfo->ulSecuParaIndex = (VOS_UINT32)(pTmp[ucCnt++ ]
                        << NAS_ESM_MOVEMENT_24_BITS);
                pstTFTInfo->ulSecuParaIndex = pstTFTInfo->ulSecuParaIndex
                        |(pTmp[ucCnt++] << NAS_ESM_MOVEMENT_16_BITS);
                pstTFTInfo->ulSecuParaIndex = pstTFTInfo->ulSecuParaIndex
                        |(pTmp[ucCnt++] << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->ulSecuParaIndex = pstTFTInfo->ulSecuParaIndex
                        | pTmp[ucCnt++];
                break;

            /* component是 Type of service/Traffic class type */
            case NAS_ESM_TFT_TOS:
                pstTFTInfo->bitOpTypeOfService = NAS_ESM_OP_TRUE;

                pstTFTInfo->ucTypeOfService = pTmp[ucCnt++];
                pstTFTInfo->ucTypeOfServiceMask = pTmp[ucCnt++];
                break;

            /* component是 "Flow label type"*/
            case NAS_ESM_TFT_FLOW_LABLE:
                pstTFTInfo->bitOpFlowLabelType = NAS_ESM_OP_TRUE;

                pstTFTInfo->ulFlowLabelType = (VOS_UINT32)(pTmp[ucCnt++]
                           << NAS_ESM_MOVEMENT_16_BITS);
                pstTFTInfo->ulFlowLabelType = pstTFTInfo->ulFlowLabelType
                           | (pTmp[ucCnt++] << NAS_ESM_MOVEMENT_8_BITS);
                pstTFTInfo->ulFlowLabelType = pstTFTInfo->ulFlowLabelType
                           | pTmp[ucCnt++];

                break;

            default:
                NAS_ESM_WARN_LOG("NAS_ESM_DecodeAddOneFilterTFT:WARNING:NW->SM Invalid mandatory information1!");

                NAS_ESM_MEM_SET((VOS_VOID*)pstTFTInfo,
                            0,
                            sizeof(NAS_ESM_CONTEXT_TFT_STRU));
                return NAS_ESM_CAUSE_SYNCTACTIC_ERR_IN_PACKET_FILTER;
        }
    }
    *pucLength = ucLength;
    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodeLlcSapi
 Description     : LLC SAPI解码 (合法性由GU模的SM来做)
 Input           :  VOS_UINT16             usMsgLen
                    VOS_UINT8             *pucMsg
 Output          :  NAS_ESM_NW_MSG_STRU   *pstMsgIE
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-04-26  Draft Enact
*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeLlcSapi
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    /*
    8   7   6   5   4   3   2   1
    LLC SAPI IEI
    0   0   0   0   LLC SAPI value
    */

    (VOS_VOID)usMsgLen;
    pstMsgIE->bitOpLlcSapi  = NAS_ESM_OP_TRUE;
    pstMsgIE->ucLlcSapi     = (pucMsg[0] & NAS_ESM_MSG_LOW_BIT);
    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodePacketFlowId
 Description     : Packet Flow Identifier解码 (合法性由GU模的SM来做)
 Input           :  VOS_UINT16             usMsgLen
                    VOS_UINT8             *pucMsg
 Output          :  NAS_ESM_NW_MSG_STRU   *pstMsgIE
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-04-26  Draft Enact
*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodePacketFlowId
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    /*
    8   7   6   5   4   3   2   1
    Packet Flow Identifier IEI
    Length of Packet Flow Identifier IE
    0   Packet Flow Identifier value
    */

    (VOS_VOID)usMsgLen;
    pstMsgIE->bitOpPacketFlowId = NAS_ESM_OP_TRUE;
    pstMsgIE->ucPacketFlowId    = (pucMsg[0] & 0x7f);
    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodeRadioPriority
 Description     : Radio Priority解码
 Input           :  VOS_UINT16             usMsgLen
                    VOS_UINT8             *pucMsg
 Output          :  NAS_ESM_NW_MSG_STRU   *pstMsgIE
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-04-27  Draft Enact
*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeRadioPriority
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    /*
    8       7       6       5       4       3       2       1
    Radio priority IEI              0       Radio priority level value
    */

    (VOS_VOID)usMsgLen;
    pstMsgIE->bitOpRadioPriority    = NAS_ESM_OP_TRUE;
    pstMsgIE->ucRadioPriority       = (pucMsg[0] & 0x07);

    /* 如果不是位于【1,4】,则认为是4 */
    if ((NAS_ESM_RADIO_PRIORITY_LEVEL1 > pstMsgIE->ucRadioPriority)
        || (NAS_ESM_RADIO_PRIORITY_LEVEL4 < pstMsgIE->ucRadioPriority))
    {
        pstMsgIE->ucRadioPriority = NAS_ESM_RADIO_PRIORITY_LEVEL4;
    }

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodeTransactionId
 Description     : Transaction identifier解码
 Input           :  VOS_UINT16             usMsgLen
                    VOS_UINT8             *pucMsg
 Output          :  NAS_ESM_NW_MSG_STRU   *pstMsgIE
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-04-27  Draft Enact
*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeTransactionId
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT8                           ucTiValue = NAS_ESM_NULL;

    /*
    8       7       6       5       4       3       2       1
    Linked TI IEI
    Length of Linked TI IE
    TI flag TI value                0       0       0       0
    1       TI value
    */

    /* 协议规定第一字节中的TI VALUE若小于7，则TI值以第一字节中的TI VALUE为准；
       若第一字节中的TI VALUE为7，则必须存在第二字节，TI值以第二字节中的TI值
       为准，忽略第一字节中的TI值 */

    /* 获取第一字节中的TI VALUE */
    ucTiValue = (pucMsg[0] & 0x70) >> NAS_ESM_MOVEMENT_4_BITS;

    /* 如果第一字节中的TI VALUE为7，但不存在第二字节，则认为此信元有误，
       忽略此信元 */
    if (7 == ucTiValue)
    {
        if (1 == usMsgLen)
        {
            /*返回消息检测失败*/
            NAS_ESM_WARN_LOG( "NAS_ESM_DecodeTransactionId:len error!");
            return NAS_ESM_CAUSE_PROTOCOL_ERROR;
        }

        /* TI值设为第二字节中的TI VALUE */
        pstMsgIE->stTransId.ucTiValue = (pucMsg[1] & 0x7f);
    }
    else
    {
        /* TI值设为第一字节中的TI VALUE */
        pstMsgIE->stTransId.ucTiValue  = ucTiValue;
    }

    pstMsgIE->stTransId.ucTiFlag    = (pucMsg[0] & 0x80) >> NAS_ESM_MOVEMENT_7_BITS;
    pstMsgIE->bitOpTransId          = NAS_ESM_OP_TRUE;

    return NAS_ESM_CAUSE_SUCCESS;
}

/*****************************************************************************
 Function Name   : NAS_ESM_DecodeNegotiatedQos
 Description     : Negotiated Qos解码(代码取自GU模)
 Input           :  VOS_UINT16             usMsgLen
                    VOS_UINT8             *pucMsg
 Output          :  NAS_ESM_NW_MSG_STRU   *pstMsgIE
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-04-27  Draft Enact
*****************************************************************************/
NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNegotiatedQos
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    VOS_UINT32                          ulSum            = NAS_ESM_NULL;
    const VOS_UINT8                    *pucTmpMsg        = pucMsg;
    NAS_ESM_CONTEXT_QOS_STRU           *pstTmpPdpQosInfo = VOS_NULL_PTR;

    pstTmpPdpQosInfo = &pstMsgIE->stCntxtQosInfo;

    pstTmpPdpQosInfo->ucDelayClass  = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_DELAY_CLASS) >> NAS_ESM_MOVEMENT_3_BITS;
    pstTmpPdpQosInfo->ucReliabClass = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_RELIABILITY_CLASS);

    pstTmpPdpQosInfo->ucPeakThrough          = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_PEAK_THROUGHPUT) >> NAS_ESM_MOVEMENT_4_BITS;
    pstTmpPdpQosInfo->ucPrecedenceClass      = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_PRECEDENCE_CLASS);

    pstTmpPdpQosInfo->ucMeanThrough          = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_MEAN_THROUGHPUT);

    if (usMsgLen > 3)
    {
        pstTmpPdpQosInfo->ucTrafficClass     = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_TRAFFIC_CLASS)>>5;
        pstTmpPdpQosInfo->ucDeliverOrder     = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_DELIVERY_ORDER)>>3;
        pstTmpPdpQosInfo->ucDeliverOfErrSdu  = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_DELIVERY_ERRORNEOUS_SDU);
    }

    if (usMsgLen > 4)
    {
        pstTmpPdpQosInfo->ucMaximSduSize     = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 5)
    {
        pstTmpPdpQosInfo->ucMaxBitRateForUp  = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 6)
    {
        pstTmpPdpQosInfo->ucMaxBitRateForDown = pucTmpMsg[ulSum++];;
    }

    if (usMsgLen > 7)
    {
        pstTmpPdpQosInfo->ucResidualBer      = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_RESIDUAL_BER) >> NAS_ESM_MOVEMENT_4_BITS;
        pstTmpPdpQosInfo->ucSduErrRatio      = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_SDU_ERROR_RATIO);
    }

    if (usMsgLen > 8)
    {
        pstTmpPdpQosInfo->ucTransDelay           = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_TRANSFER_DELAY) >> NAS_ESM_MOVEMENT_2_BITS;
        pstTmpPdpQosInfo->ucTraffHandlPrior      = (pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_TRAFFIC_HANDLING_PRIORITY);
    }

    if (usMsgLen > 9)
    {
        pstTmpPdpQosInfo->ucGuarantBitRateForUp  = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 10)
    {
       pstTmpPdpQosInfo->ucGuarantBitRateForDown = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 11)
    {
        pstTmpPdpQosInfo->ucSrcStatisticsDescriptor = (pucTmpMsg[ulSum] & NAS_ESM_PDP_QOS_SSD);

        /* Signalling-Indication 的值只取该字节的第5位 */
        pstTmpPdpQosInfo->ucSignallingIndication    = ((pucTmpMsg[ulSum++] & NAS_ESM_PDP_QOS_SIGNALLING_INDICATION) >> NAS_ESM_MOVEMENT_4_BITS);
    }

    if (usMsgLen > 12)
    {
        pstTmpPdpQosInfo->ucMaxBitRateForDownExt    = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 13)
    {
        pstTmpPdpQosInfo->ucGuarantBitRateForDownExt = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 14)
    {
        pstTmpPdpQosInfo->ucMaxBitRateForUpExt     = pucTmpMsg[ulSum++];
    }

    if (usMsgLen > 15)
    {
        pstTmpPdpQosInfo->ucGuarantBitRateForUpExt = pucTmpMsg[ulSum++];
    }

    pstMsgIE->bitOpNegQos = NAS_ESM_OP_TRUE;
    return NAS_ESM_CAUSE_SUCCESS;
}
/*lint +e961*/
/*lint +e960*/

NAS_ESM_CAUSE_ENUM_UINT8 NAS_ESM_DecodeNotificationIndicator
(
    VOS_UINT16                          usMsgLen,
    const VOS_UINT8                    *pucMsg,
    NAS_ESM_NW_MSG_STRU                *pstMsgIE
)
{
    NAS_ESM_NOTIFICATION_IND_STRU   *pstNotificationInd = VOS_NULL_PTR;
    (VOS_VOID)usMsgLen;

    pstMsgIE->bitOpNotificationInd = NAS_ESM_OP_TRUE;
    pstNotificationInd = &pstMsgIE->stNotificationInd;

    pstNotificationInd->ucValue = pucMsg[0];

    return  NAS_ESM_CAUSE_SUCCESS;
}




#ifdef __cplusplus
    #if __cplusplus
                                                }
    #endif
#endif

