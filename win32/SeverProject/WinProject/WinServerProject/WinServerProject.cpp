// WinServerProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <fcntl.h>
#include <errno.h>

#include "TerminalDefine.h"
#include "TerminalStruct.h"

#include <event2/queue.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>


#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libevent.lib")

struct client {
    int fd;
    struct bufferevent *buf_ev;
    //  TAILQ_ENTRY(client) entries;
};
struct event_base *evbase = NULL;

#define VALUE_MID       111
#define VALUE_AIID      222
#define VALUE_CHID      1

INT32   Event_SendHandler(int sockfd, char *pcData, int iLen)
{
    int ierr = 0;
    int ileft = 0;
    int isendlen = 0;

    ileft = iLen;
    while (TRUE)
    {
        ierr = send(sockfd, (CHAR *)(pcData + isendlen), ileft, 0);
        if (ierr > 0)
        {
            ileft -= ierr;
            isendlen += ierr;

            if (0 == ileft)
            {
                return iLen;
            }
            else if (ileft < 0)
            {
                return -1;
            }
            else
            {
                continue;
            }
        }
        else if (ierr == -35)
        {
            continue;
        }
        else
        {
            printf("VOS_SOCK_Send error=%d!\n", GetLastError());
            return -1;
        }
    }

    return iLen;
}

void sendtestconfigure(struct client *clientinfo)
{
    int iSendLen = 0;
    int istrctlen = 0;
    /*********** 1.NC配置 **********/
    NCDEV_CFGMSG_S  stNCData = {0};
    
    stNCData.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);
    stNCData.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_DEVINFO_NC);
    istrctlen = sizeof(NCDEV_CFGMSG_S) - 12;
    stNCData.stHead.stCmdHead.iDataLen = htonl(istrctlen);

    stNCData.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stNCData.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stNCData.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    //strcpy_s(stNCData.stHead.stComInfo.acNCID, TC_MAXLEN_NCID - 1, "HelloWorld");
    stNCData.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stNCData.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stNCData.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stNCData.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stNCData.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stNCData.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stNCData.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stNCData.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stNCData.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stNCData.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);

    stNCData.uiActionType = htonl(1);

    stNCData.stSysCfgInfo.unMid = htonl(VALUE_MID);
    strcpy_s(stNCData.stSysCfgInfo.acNCIP, VOS_SOCK_IPADDR_LEN-1, "192.168.1.1");
    stNCData.stSysCfgInfo.eMFactoryType = htonl(DEV_MF_NC_FANUC);
    stNCData.stSysCfgInfo.eMFClassType = htonl(DEV_MFCLS_UNKOWN);
    stNCData.stSysCfgInfo.uiNCPort = htonl(12345);
    stNCData.stSysCfgInfo.uiNCFreq = htonl(5);

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stNCData, sizeof(stNCData));
    
    printf("bufferevent_write--->NCData =%d\n", iSendLen);
    /*********** 2.ADIO配置 **********/
    ADIODEV_CFGMSG_S  stADIOData = { 0 };
    stADIOData.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stADIOData.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_DEVINFO_ADIO); 
    /*********/
    istrctlen = sizeof(ADIODEV_CFGMSG_S) - 12;
    stADIOData.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stADIOData.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stADIOData.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stADIOData.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    //strcpy_s(stADIOData.stHead.stComInfo.acNCID, TC_MAXLEN_NCID - 1, "HelloWorld");
    stADIOData.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stADIOData.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stADIOData.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stADIOData.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stADIOData.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stADIOData.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stADIOData.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stADIOData.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stADIOData.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stADIOData.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stADIOData.uiActionType = htonl(1);

    stADIOData.stSysCfgInfo.eMFactoryType = htonl(DEV_MF_ADIO_YAV);
    stADIOData.stSysCfgInfo.eMFClassType = htonl(DEV_MFCLS_UNKOWN);
    stADIOData.stSysCfgInfo.uiADIOFreq = 20;
    stADIOData.stSysCfgInfo.uiAIEnable = 1;

    //bufferevent_write(clientinfo->buf_ev, &stADIOData, sizeof(stADIOData));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stADIOData, sizeof(stADIOData));

    printf("bufferevent_write--->stADIOData =%d\n", iSendLen);
    /*********** 3.DMM同步源 **********/
    DMMDEV_CFGMSG_S stDmmDev = {0};
    stDmmDev.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stDmmDev.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_DMMINFO);
    
    /*********/
    istrctlen = sizeof(DMMDEV_CFGMSG_S) - 12;
    stDmmDev.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stDmmDev.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stDmmDev.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stDmmDev.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    //strcpy_s(stDmmDev.stHead.stComInfo.acNCID, TC_MAXLEN_NCID - 1, "HelloWorld");
    stDmmDev.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stDmmDev.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stDmmDev.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stDmmDev.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stDmmDev.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stDmmDev.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stDmmDev.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stDmmDev.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stDmmDev.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stDmmDev.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stDmmDev.uiActionType = htonl(1);


    stDmmDev.stSysCfgInfo.stCommHead.uiMID = htonl(VALUE_MID);
    stDmmDev.stSysCfgInfo.stCommHead.uiCHID = htonl(VALUE_CHID);
    stDmmDev.stSysCfgInfo.stCommHead.uiAIID = htonl(VALUE_AIID);
    //strcpy_s(stDmmDev.stSysCfgInfo.stCommHead.acNCID, TC_MAXLEN_NCID - 1, "HelloWorld");
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[0].iSignalDictCode = htonl(50);
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[0].iAIChID = htonl(3);
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[1].iSignalDictCode = htonl(51);
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[1].iAIChID = htonl(1);
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stDmmDev.stSysCfgInfo.stCommHead.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stDmmDev.stSysCfgInfo.stCommHead.uiDIID = htonl(TC_INVALID_VALINT32);
    stDmmDev.stSysCfgInfo.stCommHead.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stDmmDev.stSysCfgInfo.stCommHead.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stDmmDev.stSysCfgInfo.stCommHead.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);


    stDmmDev.stSysCfgInfo.usVersion = htonl(BASEDATA_VERSION_1_0);
    stDmmDev.stSysCfgInfo.uiMasterSyncType = htonl(DEVSYNC_TYPE_AI);

    //bufferevent_write(clientinfo->buf_ev, &stDmmDev, sizeof(stDmmDev));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stDmmDev, sizeof(stDmmDev));

    printf("bufferevent_write--->stDmmDev =%d\n", iSendLen);
    /*********** 4.EAM配置**********/
    EAM_CFGMSG_S    stEamCfg001 = {0};
    stEamCfg001.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stEamCfg001.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_EAMINFO);

    /*********/
    istrctlen = sizeof(EAM_CFGMSG_S) - 12;
    stEamCfg001.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stEamCfg001.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stEamCfg001.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stEamCfg001.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    //strcpy_s(stEamCfg001.stHead.stComInfo.acNCID, TC_MAXLEN_NCID - 1, "HelloWorld");
    stEamCfg001.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stEamCfg001.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stEamCfg001.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stEamCfg001.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stEamCfg001.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg001.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stEamCfg001.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stEamCfg001.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg001.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stEamCfg001.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stEamCfg001.uiActionType = htonl(1);

    stEamCfg001.stCfgInfo.uiClassType = htonl(EVT_PROCESSANALYZE_SEGM);
    stEamCfg001.stCfgInfo.uiSignalDictCode = htonl(BDSIGNAL_CODE_SETFV);
    stEamCfg001.stCfgInfo.uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stEamCfg001.stCfgInfo.uiMethodValue = htonl(100);


    //bufferevent_write(clientinfo->buf_ev, &stEamCfg001, sizeof(stEamCfg001));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stEamCfg001, sizeof(stEamCfg001));
    printf("bufferevent_write--->stEamCfg001 =%d\n", iSendLen);

    EAM_CFGMSG_S    stEamCfg002 = { 0 };
    stEamCfg002.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stEamCfg002.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_EAMINFO);
    /*********/
    istrctlen = sizeof(EAM_CFGMSG_S) - 12;
    stEamCfg002.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stEamCfg002.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stEamCfg002.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stEamCfg002.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stEamCfg002.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stEamCfg002.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stEamCfg002.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stEamCfg002.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stEamCfg002.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg002.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stEamCfg002.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stEamCfg002.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg002.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stEamCfg002.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stEamCfg002.uiActionType = htonl(1);

    stEamCfg002.stCfgInfo.uiClassType = htonl(EVT_PROCESSANALYZE_SEGM);
    stEamCfg002.stCfgInfo.uiSignalDictCode = htonl(BDSIGNAL_CODE_SETSP);
    stEamCfg002.stCfgInfo.uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stEamCfg002.stCfgInfo.uiMethodValue = htonl(1000);


    //bufferevent_write(clientinfo->buf_ev, &stEamCfg002, sizeof(stEamCfg002));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stEamCfg002, sizeof(stEamCfg002));
    printf("bufferevent_write--->stEamCfg002 =%d\n", iSendLen);

    EAM_CFGMSG_S    stEamCfg003 = { 0 };
    stEamCfg003.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stEamCfg003.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_EAMINFO);
    /*********/
    istrctlen = sizeof(EAM_CFGMSG_S) - 12;
    stEamCfg003.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stEamCfg003.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stEamCfg003.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stEamCfg003.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stEamCfg003.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stEamCfg003.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stEamCfg003.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stEamCfg003.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stEamCfg003.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg003.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stEamCfg003.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stEamCfg003.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stEamCfg003.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stEamCfg003.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stEamCfg003.uiActionType = htonl(1);

    stEamCfg003.stCfgInfo.uiClassType = htonl(EVT_PROCESSANALYZE_MARK);
    stEamCfg003.stCfgInfo.uiSignalDictCode = htonl(BDSIGNAL_CODE_TNUMBER);
    stEamCfg003.stCfgInfo.uiMethodType = htonl(EVT_MARK_METHOD_CHANGE);
    stEamCfg003.stCfgInfo.uiMethodValue = htonl(0);

    //bufferevent_write(clientinfo->buf_ev, &stEamCfg003, sizeof(stEamCfg003));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stEamCfg003, sizeof(stEamCfg003));
    printf("bufferevent_write--->stEamCfg003 =%d\n", iSendLen);
    /*********** 5.RAM配置 **********/

    //第一个MMTypeID: F+S
    RAM_CFGMSG_S    stRamCfg001 = { 0 };
    stRamCfg001.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRamCfg001.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RAMINFO);
    /*********/
    istrctlen = sizeof(RAM_CFGMSG_S) - 12;
    stRamCfg001.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    printf("stRamCfg001-->datalen=%d\n", istrctlen);
    /********/
    stRamCfg001.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRamCfg001.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRamCfg001.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRamCfg001.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRamCfg001.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRamCfg001.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRamCfg001.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRamCfg001.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg001.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRamCfg001.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRamCfg001.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg001.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRamCfg001.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRamCfg001.uiActionType = htonl(1);

    stRamCfg001.stCfgInfo.uiMMTypeID = htonl(1);
    stRamCfg001.stCfgInfo.unNums = htonl(2);
    stRamCfg001.stCfgInfo.uiClassType = htonl(1);

    stRamCfg001.stCfgInfo.stRAMCfgEnty[0].uiSignalDictCode = htonl(BDSIGNAL_CODE_SETSP);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[0].uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[0].uiMethodAttrType = htonl(EVT_STATUSPROCESS_THRESHOLD_UPPER);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[0].uiDelayTime = htonl(0);

    stRamCfg001.stCfgInfo.stRAMCfgEnty[1].uiSignalDictCode = htonl(BDSIGNAL_CODE_SETFV);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[1].uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[1].uiMethodAttrType = htonl(EVT_STATUSPROCESS_THRESHOLD_UPPER);
    stRamCfg001.stCfgInfo.stRAMCfgEnty[1].uiDelayTime = htonl(0);

    //bufferevent_write(clientinfo->buf_ev, &stRamCfg001, sizeof(stRamCfg001));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRamCfg001, sizeof(stRamCfg001));
    printf("bufferevent_write--->stRamCfg001 =%d\n", iSendLen);

    //第二个MMTypeID: F
    RAM_CFGMSG_S    stRamCfg002 = { 0 };
    stRamCfg002.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRamCfg002.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RAMINFO);
    /*********/
    istrctlen = sizeof(RAM_CFGMSG_S) - 12;
    stRamCfg002.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRamCfg002.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRamCfg002.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRamCfg002.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRamCfg002.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRamCfg002.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRamCfg002.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRamCfg002.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRamCfg002.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg002.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRamCfg002.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRamCfg002.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg002.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRamCfg002.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRamCfg002.uiActionType = htonl(1);

    stRamCfg002.stCfgInfo.uiMMTypeID = htonl(2);
    stRamCfg002.stCfgInfo.unNums = htonl(1);
    stRamCfg002.stCfgInfo.uiClassType = htonl(EVT_PROCESSANALYZE_SEGM);

    stRamCfg002.stCfgInfo.stRAMCfgEnty[0].uiSignalDictCode = htonl(BDSIGNAL_CODE_SETFV);
    stRamCfg002.stCfgInfo.stRAMCfgEnty[0].uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stRamCfg002.stCfgInfo.stRAMCfgEnty[0].uiMethodAttrType = htonl(EVT_STATUSPROCESS_THRESHOLD_UPPER);
    stRamCfg002.stCfgInfo.stRAMCfgEnty[0].uiDelayTime = htonl(0);

    //bufferevent_write(clientinfo->buf_ev, &stRamCfg002, sizeof(stRamCfg002));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRamCfg002, sizeof(stRamCfg002));
    printf("bufferevent_write--->stRamCfg002 =%d\n", iSendLen);

    //第三个MMTypeID: S
    RAM_CFGMSG_S    stRamCfg003 = { 0 };
    stRamCfg003.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRamCfg003.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RAMINFO);
    /*********/
    istrctlen = sizeof(RAM_CFGMSG_S) - 12;
    stRamCfg003.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRamCfg003.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRamCfg003.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRamCfg003.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRamCfg003.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRamCfg003.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRamCfg003.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRamCfg003.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRamCfg003.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg003.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRamCfg003.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRamCfg003.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRamCfg003.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRamCfg003.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRamCfg003.uiActionType = htonl(1);

    stRamCfg003.stCfgInfo.uiMMTypeID = htonl(3);
    stRamCfg003.stCfgInfo.unNums = htonl(1);
    stRamCfg003.stCfgInfo.uiClassType = htonl(EVT_PROCESSANALYZE_SEGM);

    stRamCfg003.stCfgInfo.stRAMCfgEnty[0].uiSignalDictCode = htonl(BDSIGNAL_CODE_SETSP);
    stRamCfg003.stCfgInfo.stRAMCfgEnty[0].uiMethodType = htonl(EVT_SEGM_METHOD_THRESHOLD);
    stRamCfg003.stCfgInfo.stRAMCfgEnty[0].uiMethodAttrType = htonl(EVT_STATUSPROCESS_THRESHOLD_UPPER);
    stRamCfg003.stCfgInfo.stRAMCfgEnty[0].uiDelayTime = htonl(0);


    //bufferevent_write(clientinfo->buf_ev, &stRamCfg003, sizeof(stRamCfg003));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRamCfg003, sizeof(stRamCfg003));
    printf("bufferevent_write--->stRamCfg003 =%d\n", iSendLen);

    /*********** 6.RMM配置 **********/
    //第一个MMTYpe下的MMID生成方式
    RMMCFG_MMIDTYPEMSG_S stRmmMMidCfg = {0};
    stRmmMMidCfg.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRmmMMidCfg.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RMMPROCMMID);
    /*********/
    istrctlen = sizeof(RMMCFG_MMIDTYPEMSG_S) - 12;
    stRmmMMidCfg.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRmmMMidCfg.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRmmMMidCfg.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRmmMMidCfg.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg.uiActionType = htonl(1);

    stRmmMMidCfg.stCfgInfo.uiMID = htonl(VALUE_MID);
    stRmmMMidCfg.stCfgInfo.iChannelID = htonl(VALUE_CHID);
    stRmmMMidCfg.stCfgInfo.iMMTypeID = htonl(1);
    stRmmMMidCfg.stCfgInfo.iMMIDForm = htonl(1);
    //bufferevent_write(clientinfo->buf_ev, &stRmmMMidCfg, sizeof(stRmmMMidCfg));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRmmMMidCfg, sizeof(stRmmMMidCfg));
    printf("bufferevent_write--->stRmmMMidCfg =%d\n", iSendLen);

    //RMM下的第一个MMType的第一条默认监控配置
    RMMCFG_MNPROCMSG_S stRmmdefaultMonitorCfg = { 0 };
    stRmmdefaultMonitorCfg.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRmmdefaultMonitorCfg.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RMMPROC);
    /*********/
    istrctlen = sizeof(RMMCFG_MNPROCMSG_S) - 12;
    stRmmdefaultMonitorCfg.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRmmdefaultMonitorCfg.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRmmdefaultMonitorCfg.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg.uiActionType = htonl(1);

    stRmmdefaultMonitorCfg.stCfgInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg.stCfgInfo.iChannelID = htonl(1);
    stRmmdefaultMonitorCfg.stCfgInfo.iMMTypeID = htonl(1);
    stRmmdefaultMonitorCfg.stCfgInfo.uiSigCode = htonl(BDSIGNAL_CODE_SPLOAD);
    stRmmdefaultMonitorCfg.stCfgInfo.uiFeatureType = htonl(1);
    stRmmdefaultMonitorCfg.stCfgInfo.iLearnCnt = htonl(1);
    stRmmdefaultMonitorCfg.stCfgInfo.iLearnType = htonl(1);

    //bufferevent_write(clientinfo->buf_ev, &stRmmdefaultMonitorCfg, sizeof(stRmmdefaultMonitorCfg));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRmmdefaultMonitorCfg, sizeof(stRmmdefaultMonitorCfg));
    printf("bufferevent_write--->stRmmdefaultMonitorCfg =%d\n", iSendLen);

    //第二个MMTYpe下的MMID生成方式
    RMMCFG_MMIDTYPEMSG_S stRmmMMidCfg002 = { 0 };
    stRmmMMidCfg002.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRmmMMidCfg002.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RMMPROCMMID);
    /*********/
    istrctlen = sizeof(RMMCFG_MMIDTYPEMSG_S) - 12;
    stRmmMMidCfg002.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRmmMMidCfg002.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRmmMMidCfg002.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRmmMMidCfg002.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRmmMMidCfg002.uiActionType = htonl(1);

    stRmmMMidCfg002.stCfgInfo.uiMID = htonl(VALUE_MID);
    stRmmMMidCfg002.stCfgInfo.iChannelID = htonl(VALUE_CHID);
    stRmmMMidCfg002.stCfgInfo.iMMTypeID = htonl(2);
    stRmmMMidCfg002.stCfgInfo.iMMIDForm = htonl(1);

    //bufferevent_write(clientinfo->buf_ev, &stRmmMMidCfg002, sizeof(stRmmMMidCfg002));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRmmMMidCfg002, sizeof(stRmmMMidCfg002));
    printf("bufferevent_write--->stRmmMMidCfg002 =%d\n", iSendLen);

    //RMM下的第二个MMType的第一条默认监控配置
    RMMCFG_MNPROCMSG_S stRmmdefaultMonitorCfg_002 = { 0 };
    stRmmdefaultMonitorCfg_002.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRmmdefaultMonitorCfg_002.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RMMPROC);
    /*********/
    istrctlen = sizeof(RMMCFG_MNPROCMSG_S) - 12;
    stRmmdefaultMonitorCfg_002.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_002.uiActionType = htonl(1);

    stRmmdefaultMonitorCfg_002.stCfgInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg_002.stCfgInfo.iChannelID = htonl(1);
    stRmmdefaultMonitorCfg_002.stCfgInfo.iMMTypeID = htonl(2);
    stRmmdefaultMonitorCfg_002.stCfgInfo.uiSigCode = htonl(BDSIGNAL_CODE_SPLOAD);
    stRmmdefaultMonitorCfg_002.stCfgInfo.uiFeatureType = htonl(1);
    stRmmdefaultMonitorCfg_002.stCfgInfo.iLearnCnt = htonl(1);
    stRmmdefaultMonitorCfg_002.stCfgInfo.iLearnType = htonl(1);

    //bufferevent_write(clientinfo->buf_ev, &stRmmdefaultMonitorCfg_002, sizeof(stRmmdefaultMonitorCfg_002));

    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRmmdefaultMonitorCfg_002, sizeof(stRmmdefaultMonitorCfg_002));
    printf("bufferevent_write--->stRmmdefaultMonitorCfg_002 =%d\n", iSendLen);
    RMMCFG_MNPROCMSG_S stRmmdefaultMonitorCfg_003 = { 0 };
    stRmmdefaultMonitorCfg_003.stHead.stCmdHead.iCommunType = htonl(BASECMD_MTYPE_CFG);

    stRmmdefaultMonitorCfg_003.stHead.stCmdHead.iSubType = htonl(BASECMD_STYPE_CFG_RMMPROC);
    /*********/
    istrctlen = sizeof(RMMCFG_MNPROCMSG_S) - 12;
    stRmmdefaultMonitorCfg_003.stHead.stCmdHead.iDataLen = htonl(istrctlen);
    /********/
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.uiCHID = htonl(VALUE_CHID);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.uiAIID = htonl(VALUE_AIID);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[0].iSignalDictCode = htonl(50);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[0].iAIChID = htonl(3);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[1].iSignalDictCode = htonl(51);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[1].iAIChID = htonl(1);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[2].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stAICHID[2].iAIChID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.uiDIID = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stDICHID[0].iSignalDictCode = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stDICHID[0].chStart = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.stHead.stComInfo.stDICHID[0].chEnd = htonl(TC_INVALID_VALINT32);
    stRmmdefaultMonitorCfg_003.uiActionType = htonl(1);

    stRmmdefaultMonitorCfg_003.stCfgInfo.uiMID = htonl(VALUE_MID);
    stRmmdefaultMonitorCfg_003.stCfgInfo.iChannelID = htonl(1);
    stRmmdefaultMonitorCfg_003.stCfgInfo.iMMTypeID = htonl(2);
    stRmmdefaultMonitorCfg_003.stCfgInfo.uiSigCode = htonl(BDSIGNAL_CODE_ACTSP);
    stRmmdefaultMonitorCfg_003.stCfgInfo.uiFeatureType = htonl(1);
    stRmmdefaultMonitorCfg_003.stCfgInfo.iLearnCnt = htonl(1);
    stRmmdefaultMonitorCfg_003.stCfgInfo.iLearnType = htonl(1);


    //bufferevent_write(clientinfo->buf_ev, &stRmmdefaultMonitorCfg_003, sizeof(stRmmdefaultMonitorCfg_003));


    iSendLen = Event_SendHandler(clientinfo->fd, (CHAR *)&stRmmdefaultMonitorCfg_003, sizeof(stRmmdefaultMonitorCfg_003));
    printf("bufferevent_write--->stRmmdefaultMonitorCfg_003 =%d\n", iSendLen);

}



void buffered_on_read(struct bufferevent *bev, void *arg)
{
    struct client *client = (struct client *)arg;
    //    struct client *this_client;
    unsigned char data[8192] = { 0 };
    size_t n=0;

    

    /* Read 8k at a time and send it to all connected clients. */
    for (;;) 
    {
        n = bufferevent_read(bev, data, sizeof(data));
        if (n <= 0) {
            /* Done. */
            printf("bufferevent read error=%zu, Getlasterror=%d\n", n, GetLastError());

            bufferevent_socket_new(evbase, client->fd, BEV_OPT_CLOSE_ON_FREE);
            closesocket(client->fd);
            break;
        }

        /* Send data to all connected clients except for the
         * client that sent the data. */

         // TAILQ_FOREACH(client, &client_tailq_head, entries) {
              //if (client != this_client) {
        //bufferevent_write(client->buf_ev, data, n);
        printf("bufferevent read n=%d\n", n);
        //}
    //}
    }
    printf("buffer out the for cycle!\n");
}

void on_accept(int fd, short ev, void *arg)
{
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    //struct client *clientinfo;

    client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        printf("accept failed!errno=%d\n", errno);
        return;
    }

#if 0
    /* Set the client socket to non-blocking mode. */
    //if (setnonblock(client_fd) < 0)
   //     warn("failed to set client socket non-blocking");
    
    evutil_make_socket_nonblocking(client_fd);

    /* We've accepted a new client, create a client object. */
    clientinfo = (struct client*)calloc(1, sizeof(struct client));
    if (clientinfo == NULL)
        printf("malloc failed\n");
    clientinfo->fd = client_fd;

    clientinfo->buf_ev = bufferevent_socket_new(evbase, client_fd, 0);
    bufferevent_setcb(clientinfo->buf_ev, buffered_on_read, NULL, NULL, clientinfo);

    /* We have to enable it before our callbacks will be
    * called. */
    bufferevent_enable(clientinfo->buf_ev, EV_READ | EV_CLOSED);

    /* Add the new client to the tailq. */
   // TAILQ_INSERT_TAIL(&client_tailq_head, client, entries);
    printf("Accepted connection from sin_addr=%s\n", inet_ntoa(client_addr.sin_addr));
    sendtestconfigure(clientinfo);
#else 

    printf("Accepted connection from sin_addr=%s:%d\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    char data[8192] = { 0 };
    size_t n = 0;
    int iret = recv(client_fd, data, 8192, 0);
    if (iret > 0)
    {
        printf("recv data len=%d\n", iret);
        closesocket(client_fd);
    }

#endif

}

int main001(int argc, char **argv)
{
    int listen_fd;
    struct sockaddr_in listen_addr;
    struct event ev_accept;
    int reuseaddr_on;

    WORD      wVersionRequested;
    WSADATA wsaData;
    INT32       err;

    /*请求2.2版本的winsock库*/
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (0 != err)
    {
        return -1;
    }

    /* Initialize libevent. */
    evbase = event_base_new();

    /* Initialize the tailq. */
    //TAILQ_INIT(&client_tailq_head);

    /* Create our listening socket. */
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
        printf("socket failed, Error=%d\n", GetLastError());

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8899);

    reuseaddr_on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuseaddr_on, sizeof(int));

    if (bind(listen_fd, (struct sockaddr *)&listen_addr,
        sizeof(listen_addr)) < 0)
        printf("bind failed, Error=%d\n", GetLastError());

    if (listen(listen_fd, 5) < 0)
        printf("listen failed, Error=%d\n", GetLastError());


    reuseaddr_on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuseaddr_on, sizeof(reuseaddr_on));

    /* Set the socket to non-blocking, this is essential in event
     * based programming with libevent. */
     //if (setnonblock(listen_fd) < 0)
     //err(1, "failed to set server socket to non-blocking");

     /* We now have a listening socket, we create a read event to
     * be notified when a client connects. */
    event_assign(&ev_accept, evbase, listen_fd, EV_READ | EV_PERSIST, on_accept, NULL);
    event_add(&ev_accept, NULL);

    /* Start the event loop. */
    event_base_dispatch(evbase);

    return 0;
}