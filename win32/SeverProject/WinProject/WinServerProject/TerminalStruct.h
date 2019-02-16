/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �����ѻ��������޹�˾

 ******************************************************************************
  �� �� ��   : TerminalStruct.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2018��12��24��
  ����޸�   :
  ��������   : �ն˽ṹ��ͨ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��12��24��
    ��    ��   : ����
    �޸�����   : �����ļ�

******************************************************************************/
#define VOS_SOCK_IPADDR_LEN 16
/******************************************************************/
/************************* ͨ�ö��� *******************************/
/******************************************************************/
/************************* ͨ�ýṹ *******************************/
/*����ͨ��ͷ: 12�ֽ�*/
typedef struct tagBaseCmdHead
{
    unsigned int    iCommunType;        //ǰ��ͨ��������: BASECMD_MTYPE_E
    unsigned int    iSubType;           //ǰ��ͨ��������: BASECMD_STYPE_CFG_E/
    unsigned int    iDataLen;           //ǰ��ͨ�����ݰ�����:
}BASE_CMDHEAD_S, *PBASE_CMDHEAD_S;

/*DMM��RAM����ͨ��ͷ�ṹ*/
typedef struct tagBaseQueHead
{
    BASE_CMDHEAD_S  stBaseCmd;
    unsigned int    nBdIndex;
    unsigned int    nAction;
}BASE_QUEHEAD_S, *PBASE_QUEHEAD_S;

/******************************************************************/
/*************************  (1)������  ****************************/
/******************************************************************/
/*�������͵�DIͨ����Ϣ*/
typedef struct tagDIIOChConfig
{
    unsigned int iSignalDictCode;       // �ź��ֵ���
    unsigned int chStart;               // ͨ����ʼ,����: chStart=1,û�о�0xFF����
    unsigned int chEnd;                 // ͨ������,����: chEnd=2, û�о�0xFF����
}DIIO_CHCFG_S, *PDIIO_CHCFG_S;

typedef struct tagAIIOChConfig
{
    unsigned int iSignalDictCode;       // �ź��ֵ���
    unsigned int iAIChID;               // ͨ��ID
}AIIO_CHCFG_S, *PAIIO_CHCFG_S;

/*�������͵Ļ�����Ϣ: 228*/
typedef struct tagBaseCommConfig
{
    unsigned int    uiMID;                          //����ID
    char            acNCID[TC_MAXLEN_NCID];         //NC��ID
    unsigned int    uiCHID;                         //NC��ͨ��ID
    unsigned int    uiAIID;                         //AI��ID
    AIIO_CHCFG_S    stAICHID[TC_MAXNUMS_AICH];      //AI��ͨ��ֵ:����: acAICHID[0]=1, acAICHID[1]=0xFF(��0xFF��β)
    unsigned int    uiDIID;                         //DI��ID
    DIIO_CHCFG_S    stDICHID[TC_MAXNUMS_DICH];      //DI��ͨ��ֵ
}BASE_COMMCFG_S, *PBASE_COMMCFG_S;

/*Baseͨ�õĻ�����Ϣͷ�ṹ����*/
typedef struct tagBaseCommHead
{
    BASE_CMDHEAD_S  stCmdHead;          /*����ͷ��*/
    BASE_COMMCFG_S   stComInfo;         /*ͨ��������Ϣ*/
}BASE_COMMHEAD_S, *PBASE_COMMHEAD_S;

typedef struct _TcComm_TagTime
{
    unsigned short  usYear;         //��
    unsigned char   ucMonth;        //��
    unsigned char   ucDay;          //��
    unsigned char   ucHour;         //ʱ
    unsigned char   ucMinute;       //��
    unsigned char   ucSecond;       //��
    unsigned char   cRsv[3];        //�������ֽڶ���
    unsigned short  usMilliS;       //����
}TCCOMM_TAGTIME_S, *PTCCOMM_TAGTIME_S;      // TCͨ��ʱ���  (12�ֽ�)

/************************* 1.�豸ϵͳ���� ****************************/
//NC�豸ϵͳ������Ϣ
typedef struct tagNCDevSysConfig
{
    unsigned int    unMid;
    char   acNCID[TC_MAXLEN_NCID];              //NC��ID
    unsigned int    eMFactoryType;              //�豸����------����:DEV_MFACTORY_E
    unsigned int    eMFClassType;               //�豸����ϵ��--����:DEV_MFCLS_E
    char   acNCIP[VOS_SOCK_IPADDR_LEN];         //NC��IP��ַ
    unsigned int    uiNCPort;                   //NC�Ķ˿�
    unsigned int    uiNCFreq;                   //NC�ɼ�Ƶ��
}NCDEV_SYSCFG_S, *PNCDEV_SYSCFG_S;

/*NC�豸ϵͳ������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagNCDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_DEVINFO_NC
    unsigned int    uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    NCDEV_SYSCFG_S  stSysCfgInfo;               //NCϵͳ������Ϣ
}NCDEV_CFGMSG_S, *PNCDEV_CFGMSG_S;  

//ADIO�豸ϵͳ������Ϣ
typedef struct tagADIODevSysConfig
{
    unsigned int    uiADIOID;                   //ADIO ID ����ָ��
    unsigned int    eMFactoryType;              //�豸����------����:DEV_MFACTORY_E
    unsigned int    eMFClassType;               //�豸����ϵ��--����:DEV_MFCLS_E
    unsigned int    uiADIOConnType;             //USB/����
    unsigned int    uiADIOFreq;                 //ADIO�ɼ�Ƶ��
    unsigned int    uiAIEnable;                 //AI�ɼ��Ƿ�ʹ��
    unsigned int    uiDIEnable;                 //DI�ɼ��Ƿ�ʹ��
}ADIODEV_SYSCFG_S, *PADIODEV_SYSCFG_S;

/*ADIO�豸ϵͳ������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagAdioDevSysCfgMessage
{
    BASE_COMMHEAD_S     stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_DEVINFO_ADIO
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    ADIODEV_SYSCFG_S    stSysCfgInfo;               //ADIOϵͳ������Ϣ
}ADIODEV_CFGMSG_S, *PADIODEV_CFGMSG_S;

/************************* 2.DMM�豸���� ****************************/
/*DMM�豸ϵͳ������Ϣ*/
typedef struct tagDmmDevSysConfig
{
    BASE_COMMCFG_S      stCommHead;                 // ͨ��ͷ��ʽ(�������BDͷ����)
    unsigned int      usVersion;                  // BD�汾��Ϣ
    unsigned int        uiMasterSyncType;           // ��ͬ��Դ����--����: DEVSYNC_TYPE_E
}DMMDEV_SYSCFG_S, *PDMMDEV_SYSCFG_S;

/*DMM�豸ϵͳ������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagDmmDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_DMMINFO
    unsigned int    uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    DMMDEV_SYSCFG_S stSysCfgInfo;               //DMMϵͳ������Ϣ
}DMMDEV_CFGMSG_S, *PDMMDEV_CFGMSG_S;

/*DMM�豸ϵͳ��������*/
typedef struct tagDmmDevCtrlParam
{
    unsigned int  uiDevType;                    //�豸����      (DEV_TYPE_E)
    char acParam[TC_MAXLEN_SIZE32];             //����
    unsigned int  unValue;                      //ֵ
}DMMDEV_CTLPARAM_S, *PDMMDEV_CTLPARAM_S;
/*DMM�豸ϵͳ��������*/
typedef struct tagDmmDevCtrlCfg
{
    unsigned int        uiCtrlType;                     //��������  (DEVCTRL_TYPE_E)
    unsigned int        uiNums;                         //�����������
    DMMDEV_CTLPARAM_S   stCtlParmCmd[TC_MAXNUMS_DEVCTL];//�������
}DMMDEV_CTRLCFG_S,*PDMMDEV_CTRLCFG_S;
/*��Ϣ*/
typedef struct tagDmmDevCtrlCfgMessage
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_DMMCTRL
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    DMMDEV_CTRLCFG_S    stCtrlCfg;                  //DMMϵͳ������Ϣ
}DMMDEV_CTRLCFGMSG_S, *PDMMDEV_CTRLCFGMSG_S;

/************************* 3.EAM������������ ****************************/
typedef struct tagEAMMethodConfig
{
    unsigned int    uiClassType;        //�ֶ���        (EVT_PROCESSANALYZE_E)
    unsigned int    uiSignalDictCode;       // ״̬:F                 
    unsigned int    uiMethodType;  //����:��ֵ      (cjwangTODO)
    unsigned int    uiMethodValue; //��ֵ��ֵ
}EAM_METHCFG_S, *PEAM_METHCFG_S;

/*EAM������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagEAMMethodCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_EAMINFO
    unsigned int    uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    EAM_METHCFG_S   stCfgInfo;                  //EAM������������
}EAM_CFGMSG_S, *PEAM_CFGMSG_S;

/************************* 4.RAM������������ ****************************/
typedef struct tagRAMCfgEntry
{
    unsigned int    uiSignalDictCode;   // ״̬:F                 (BDDATA_TYPE_E)
    unsigned int    uiMethodType;       // ����:��ֵ       
    unsigned int    uiMethodAttrType;   // ������ֵ/������ֵ
    unsigned int    uiDelayTime;        // �ӳ�ʱ�� ����
}RAM_CFGENTRY_S, *PRAM_CFGENTRY_S;

typedef struct tagRAMMethodConfig
{
    int        uiMMTypeID;                     //MMTypeΨһ��ʶ
    unsigned int        uiClassType;                    //�ֶ���           (EVT_PROCESSANALYZE_E)
    unsigned int        unNums;
    RAM_CFGENTRY_S      stRAMCfgEnty[RAMCFG_MTHNUMS];   //����ͨ��������
}RAM_METHCFG_S, *PRAM_METHCFG_S;

/*RAM������Ϣ:��Ϣͨ�Žṹ 140*/
typedef struct tagRamDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                         //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_RAMINFO
    unsigned int    uiActionType;                   //����: Add or Delete (BASECMD_ACTION_E)
    RAM_METHCFG_S   stCfgInfo;                      //RAM������������
}RAM_CFGMSG_S, *PRAM_CFGMSG_S;

/************************* 4.RMM������������ ****************************/
/*a. RMM��ع���Ĭ��������Ϣ*/
typedef struct tagRMMCfgMonitorProcess
{
    unsigned    int     uiMID;                              // ����id
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        // ͨ��ID
    int                 iMMTypeID;                         // ��ط�������
    unsigned    int     uiSigCode;    // �źű���
    unsigned    int     uiFeatureType;                     // �������� 32
    int                 iLearnCnt;                         // ѧϰ����
    int                 iLearnType;                        // ѧϰ����       
    TCCOMM_TAGTIME_S    stCfgTime;                          // ��������ʱ��
}RMMCFG_MNPROC_S, *PRMMCFG_MNPROC_S;

/*a. RMM��ع���������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagRMMCfgMonitorProcessMessage
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_RMMPROC
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNPROC_S     stCfgInfo;                  //RMM��ع���������Ϣ
}RMMCFG_MNPROCMSG_S, *PRMMCFG_MNPROCMSG_S;

/*b. RMM��ع���MMID ���ɷ�ʽ*/
typedef struct tagMMProcessMMIDFormTypeCfg
{
    unsigned    int     uiMID;                              // ����id
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        	// ͨ��ID
    int                 iMMTypeID;                         	// ��ط�������
    int                 iMMIDForm;                          // MMID���ɷ�ʽ
    char                acUsrDefMMID[TC_MAXLNE_USRMMID];    // �û��Զ���MMID  
    TCCOMM_TAGTIME_S    sCfgTime;                           // ��������ʱ��
}RMMCFG_MMIDTYPE_S, *PRMMCFG_MMIDTYPE_S;

/*b. RMM��ع���MMID ���ɷ�ʽ:��Ϣͨ�Žṹ*/
typedef struct tagMMProcessMMIDFormTypeCfgMsg
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_RMMPROCMMID
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MMIDTYPE_S     stCfgInfo;                  //RMM��ع���MMID ���ɷ�ʽ
}RMMCFG_MMIDTYPEMSG_S, *PRMMCFG_MMIDTYPEMSG_S;


/*c. RMM�����������������Ϣ*/
typedef struct tagRMMCfgMonitorEvalRule
{
    unsigned int   unFeatureType;                             // ��������
    int   iUpperLimitDiagRlt;                       // ��Ͻ���(������) 
    int   iMidLimitDiagRlt;                         // ��Ͻ���(δ����) 
    int   iLowerLimitDiagRlt;                       // ��Ͻ���(������) 
}RMMCFG_MNEVRULE_S, *PRMMCFG_MNEVRULE_S;

/*c. RMM�����������������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagRMMCfgMonitorEvalRuleMessage
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_RMMEVLRULE
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNEVRULE_S     stCfgInfo;                  //RMM�������������Ϣ
}RMMCFG_MNEVRULEMSG_S, *PRMMCFG_MNEVRULEMSG_S;

/*d. RMM��ؾ��߹���������Ϣ*/
typedef struct tagRMMCfgMonitorDeciRule
{
    int     iSourceID;  // �¼���Դ:ģ����
    int     iEvtType;                           // �¼�����
    int     iDiagResult;                        // ��Ͻ���
    int     iDecisionType;                      // ��������
    int     iExecEnable;                        // ִ�п��� 
}RMMCFG_MNDECIRULE_S, *PRMMCFG_MNDECIRULE_S;

/*d. RMM��ؾ��߹���������Ϣ:��Ϣͨ�Žṹ*/
typedef struct tagRMMCfgMonitorDeciRuleMessage
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_CFG_RMMDECIRULE
    unsigned int        uiActionType;               //����: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNDECIRULE_S     stCfgInfo;                  //RMM��ؾ���������Ϣ
}RMMCFG_MNDECIRULEMSG_S, *PRMMCFG_MNDECIRULEMSG_S;

/******************************************************************/
/*************************  (2)��Ϣ��  ****************************/
/******************************************************************/
/*NC̽������*/
typedef struct tagNCProbeRequestInfo
{
    unsigned int    uiMID;                          //����ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    eMFactoryType;                  //�豸����      DEV_MFACTORY_E
    unsigned int    eMFClassType;                   //����ϵ��      DEV_MFCLS_E
    unsigned char   acNCIP[VOS_SOCK_IPADDR_LEN];    //NC��IPV4��ַ
    unsigned int    uiNCPort;                       //NC�Ķ˿�
    unsigned int    uiNCFreq;                       //NC�Ĳɼ�Ƶ��
}NCPROBE_REQINFO_S, *PNCPROBE_REQINFO_S;

typedef struct tagNCProbeRequest
{
    BASE_CMDHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_NCPROB_RESQ
    NCPROBE_REQINFO_S   stProbeReqInfo;             //̽��������Ϣ
}NCPROB_REQMSG_S, *PNCPROB_REQMSG_S;

/*NC̽����Ӧ*/
typedef struct tagNCProbeResponseInfo
{
    unsigned int    uiMID;                          //����ID
    char            acNCID[TC_MAXLEN_NCID];         //���
    unsigned int    eMFactoryType;                  //�豸����      DEV_MFACTORY_E
    unsigned int    eMFClassType;                   //����ϵ��      DEV_MFCLS_E
    unsigned int    uiCHNums;                       //NC��ͨ������
}NCPROBE_RESPINFO_S, *PNCPROBE_RESPINFO_S;

typedef struct  tagNCProbeResponse
{
    BASE_CMDHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_NCPROB_RESP
    NCPROBE_RESPINFO_S  stProbeRespInfo;            //̽��������Ӧ
}NCPROB_RESPMSG_S, *PNCPROB_RESPMSG_S;

/*ADIO̽������*/
typedef struct tagADIOProbeRequestInfo
{
    unsigned int    uiMID;                      //����ID
    unsigned int    uiADIOID;                   //����ָ��
    unsigned int    eMFactoryType;              //�豸����      DEV_MFACTORY_E
    unsigned int    eMFClassType;               //����ϵ��      DEV_MFCLS_E
    unsigned int    uiADIOFreq;                 //ADIO�ɼ�Ƶ��
}ADIOPROBE_REQINFO_S, *PADIOPROBE_REQINFO_S;

typedef struct tagADIOProbeRequest
{
    BASE_CMDHEAD_S          stHead;                 //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_ADIOPROB_RESQ
    ADIOPROBE_REQINFO_S     stProbeReqInfo;         //̽��������Ϣ
}ADIOPROB_REQMSG_S, *PADIOPROB_REQMSG_S;

/*ADIO̽����Ӧ*/
typedef struct tagADIOProbeResponseInfo
{
    unsigned int    uiMID;                      //����ID
    unsigned int    uiADIOID;                   //���
    unsigned int    eMFactoryType;              //�豸����      DEV_MFACTORY_E
    unsigned int    eMFClassType;               //����ϵ��      DEV_MFCLS_E
    unsigned int    uiAICHNums;                 //AIͨ������
    unsigned int    uiDICHNums;                 //DIͨ������
}ADIOPROBE_RESPINFO_S, *PADIOPROBE_RESPINFO_S;

typedef struct  tagADIOProbeResponse
{
    BASE_CMDHEAD_S          stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_ADIOPROB_RESP
    ADIOPROBE_RESPINFO_S    stProbeRespInfo;            //̽��������Ӧ
}ADIOPROB_RESPMSG_S, *PADIOPROB_RESPMSG_S;


/*��ع�������*/
typedef struct tagRMMConfigProcUpdateInfo
{
    unsigned    int     iMID;                               // ����id
    char                acPnNum[TC_MAXLEN_PROGRAMNO];       // �����
    char                acToolNum[TC_MAXLEN_TOOLID];        // ���ߺ�
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChanID;                           // ͨ��ID
    int                 iMMType;                           // ��ط�������
    char                acMMID[TCAMCFG_MAXLEN_MMID];        // MMID
    unsigned    int     uiSigCode;                          // �źű���
    unsigned    int     uiFeatureType;                      // ��������
    int                 iLearnCnt;                         // ѧϰ����
    int                 iLearnType;                        // ѧϰ����
    int                 iAbnDetectLastTime;	   			    // �����쳣��ⶨʱ����ʱʱ��               ��λ:����
    int                 iStateRegEnable;                    // �Աȿ���     0: ���Ա�      1: �Ա�
    int                 iAlarmEnable;                       // ��������     0: �����ر� 1: ������
    int                 iReLearnFlag;                       // ����ѧϰ��־   0: ������ѧϰ  1: ����ѧϰ 
    int                 iOfflineReLearnFlag;                // ������ѧϰ��־ 0: ����������ѧϰ 1��������ѧϰ
    float               fupperLimitScal;                    // �������ű���
    float               fLowerLimitScal;                    // �������ű���
    int                 iPeekExpansionParams;               // �������Ͳ���
    int                 iCfgValid;                          // �����Ƿ���Ч   0: ��Ч 1����Ч
    TCCOMM_TAGTIME_S    stCfgTime;                          // ��������ʱ��
}RMM_MMIDPROCCFG_INFO_S, *PRMM_MMIDPROCCFG_INFO_S;


typedef struct  tagRmmConfigUpdateMessage
{
    BASE_CMDHEAD_S              stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_RMMUPDATE
    RMM_MMIDPROCCFG_INFO_S      stUpdateInfo;               //������Ϣ
}RMM_MMIDPROCCFG_INFOMSG_S, *PRMM_MMIDPROCCFG_INFOMSG_S;


/*�豸������Ϣ����*/
typedef struct tagDmmCtrlRequestInfo
{
    unsigned int    uiMID;                      //����ID
    char            acNCID[TC_MAXLEN_NCID];     //NCID
    unsigned char   acCHID;                     //CHID
    unsigned int    nCtrlType;                  //�������      DEVCTRL_TYPE_E
}DMMCTL_REQINFO_S, *PDMMCTL_REQINFO_S;

typedef struct tagDmmCtrlRequestInfoMessage
{
    BASE_CMDHEAD_S      stHead;                 //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_DEVCTRL_RESQ
    DMMCTL_REQINFO_S   stProbeReqInfo;          //̽��������Ϣ
}DMMCTL_REQINFOMSG_S, *PDMMCTL_REQINFOMSG_S;

/*�豸������Ӧ*/
typedef struct tagDMMCtrlResponseInfo
{
    unsigned int    uiMID;                      //����ID
    char            acNCID[TC_MAXLEN_NCID];     //NCID
    unsigned char   acCHID;                     //CHID
    unsigned int    nCtrlResult;                //������ƽ��            cjwangTODO
}DMMCTL_RESPINFO_S, *PDMMCTL_RESPINFO_S;

typedef struct  tagDMMCtrlResponseInfoMessage
{
    BASE_CMDHEAD_S     stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_DEVCTRL_RESP
    DMMCTL_RESPINFO_S  stProbeRespInfo;             //�豸������Ӧ
}DMMCTL_RESPINFOMSG_S, *PDMMCTL_RESPINFOMSG_S;

/*���ݿ���Ϣ-����*/
typedef struct tagDBMCtrlRequestInfo
{
    unsigned int    uiCtrlCode;                     //������
}DBMDB_INFOREQ_S, *PDBMDB_INFOREQ_S;

typedef struct tagDbmCtrlRequestInfoMessage
{
    BASE_CMDHEAD_S    stHead;                 //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_DBMINFO_RESQ
    DBMDB_INFOREQ_S   stReqInfo;         //̽��������Ϣ
}DBMDB_INFOREQMSG_S, *PDBMDB_INFOREQMSG_S;

/*���ݿ���Ϣ-��Ӧ*/
typedef struct tagDBMCtrlResponseInfo
{
    unsigned int    uiCtrlCode;                      //�ڲ�����Ϣ��
    unsigned char   acEventDBDir[TC_MAX_PATH];       //�¼����ݿ�·��
    unsigned char   acAlgmDBDir[TC_MAX_PATH];        //�㷨���ݿ�·��
}DBMDB_INFORESP_S, *PDBMDB_INFORESP_S;

/*���ݿ�Ŀ�����Ϣ*/
typedef struct  tagDBMCtrlResponseInfoMessage
{
    BASE_CMDHEAD_S     stHead;                      //��Ϣ����ͷ ������    BASECMD_STYPE_MSG_DBMINFO_RESP
    DBMDB_INFORESP_S  stMsgInfo;                   //��Ϣ����
}DBMDB_INFORESPMSG_S, *PDBMDB_INFORESPMSG_S;


/******************************************************************/
/*************************  (3)�¼���  ****************************/
/******************************************************************/
//�豸״̬�¼�: BASECMD_STYPE_MSG_E
typedef struct tagDevStatusEvtBaseInfo
{
    TCCOMM_TAGTIME_S    stTime;           //ʱ���
    unsigned int    uiMID;                          //����ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    uiCHID;                         //ͨ��ID
    unsigned int    uiADIOID;                       //ADIO��ID
    char            acPnNo[TC_MAXLEN_PROGRAMNO];      //����ID
    char            acToolNum[TC_MAXLEN_TOOLID];        // ���ߺ�
    unsigned int    uiBatchNum;                     // ���������
    unsigned int    uiDevEvtType;                     //�¼�����
    unsigned int    uiEventSource;                  // �¼�������Դ
}EVTSTAT_BASEINFO_S, *PEVTSTAT_BASEINFO_S;

typedef struct  tagDevStatusEventMessage
{
    BASE_COMMHEAD_S      stHead;                     //��Ϣ����ͷ ������    BASECMD_STYPE_EVT_PROCESSDEVICE
    EVTSTAT_BASEINFO_S   stEvtBaseInfo;             //�豸״̬�¼���Ϣ
}EVTSTAT_BASEINFOMSG_S, *PEVTSTAT_BASEINFOMSG_S;

//���̷����¼�: BASECMD_STYPE_MSG_E
typedef struct tagProcAnalyzeEvtBaseInfo
{
    TCCOMM_TAGTIME_S    stTime;           //ʱ���
    unsigned int    uiMID;                          //����ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    uiCHID;                         //ͨ��ID
    unsigned int    uiIOID;                         //ADIO��ID
    char            acProgramNo[TC_MAXLEN_PROGRAMNO];      //����ID
    char            acToolNum[TC_MAXLEN_TOOLID];        // ���ߺ�
    unsigned int    uiBatchNum;                     // ���������
    
    unsigned int    uiClassType;                    // �ֶ�����
    unsigned int    uiSignalDictCode;               //T F S ���ߺ�
    char            acSignalValue[TC_MAXLEN_SIZE32];//��ǰ��ѡ���źŵ�ֵ
    unsigned int    uiStatusMethodType;             //״̬��������:�仯
    unsigned int    uiResultValue;                  //�жϽ��ֵ:0/1

    unsigned int    uiEventSource;                  // �¼�������Դ
}PROCANALZE_BASEINFO_S, *PPROCANALZE_BASEINFO_S;

typedef struct  tagProcAnalyzeEvtBaseInfoMessage
{
    BASE_COMMHEAD_S          stHead;                //��Ϣ����ͷ ������    BASECMD_STYPE_EVT_PROCESSANALYZE
    PROCANALZE_BASEINFO_S   stEvtBaseInfo;          //���̷����¼���Ϣ
}PROCALZE_BASEINFOMSG_S, *PPROCALZE_BASEINFOMSG_S;

// ����¼�
typedef struct tagMonitorMMIDEvent
{
    unsigned int    uiMID;                           		// ����ID
    int    			iEvtType;                       		// �¼�����
    char            acPnNum[TC_MAXLEN_PROGRAMNO];   		// ����ID
    char            acToolNum[TC_MAXLEN_TOOLID];    		// ���ߺ�
    char            acMMID[TCAMCFG_MAXLEN_MMID];    		// MMID
    TCCOMM_TAGTIME_S    stMonitorStartTime;                     	// ��ع��̿�ʼ�¼�
    unsigned int    uiSignalCode; 							// �źű���
    unsigned int    uiFeatureType;           				// ��������
    int             iMonitorState;          				// ���״̬ 0���� 1���� 2��learning 3���۲�ģʽ
    int             iDiagRlt;             					// ��Ͻ���
    TCCOMM_TAGTIME_S    stEventTime;             			// �¼�����ʱ��

    unsigned int    uiEventSource;                          // �¼�������Դ, ����ҵ�����
}ALGOMONITOREVENT_S, *PALGOMONITOREVENT_S;


// �����������ĵļ���¼�
typedef struct tagDCMMonitorMMIDEvent
{
    unsigned int    uiMID;                           		// ����ID
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // �����¼���ģ����
    int             iEvtSrc;                                // �¼���Դ ��BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// �¼�����
    char            acPnNum[TC_MAXLEN_PROGRAMNO];   		// ����ID
    char            acToolNum[TC_MAXLEN_TOOLID];    		// ���ߺ�
    char            acNcID[TC_MAXLEN_NCID];             	// NCid
    int             iChanID;                           		// ͨ��ID
    char            acMMID[TCAMCFG_MAXLEN_MMID];    		// MMID
    TCCOMM_TAGTIME_S    iStartTime;                     	// ��ع��̿�ʼ�¼�
    unsigned int    uiSignalCode; 							// �źű���
    unsigned int    uiFeatureType;           				// ��������
    int             iMonitorState;          				// ���״̬ 0���� 1���� 2��learning 3���۲�ģʽ
    int             iDiagRlt;             					// ��Ͻ���
    int                 iAlarmEnable;                       // ��������     0: �����ر� 1: ������
    TCCOMM_TAGTIME_S    iEventTime;             			// �¼�����ʱ��
}DCM_ALGOMONITOREVENT_S, *DCM_PALGOMONITOREVENT_S;

// �����������ĵ��豸״̬�¼�
typedef struct tagDeviceStatusEvent
{
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // �����¼���ģ����
    int             iEvtSrc;                                // �¼���Դ ��BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// �¼�����
	// Add other member
    TCCOMM_TAGTIME_S    iEventTime;             			// �¼�����ʱ��
}DCM_DEVICE_STATUS_EVENT_S, *DCM_PDEVICE_STATUS_EVENT_S;

// �����������ĵĹ��̷����¼�
typedef struct tagProcessAnalysisEvent
{
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // �¼���Դ: ģ����
    int             iEvtSrc;                                // �¼���Դ ��BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// �¼�����
	// Add other member
    TCCOMM_TAGTIME_S    iEventTime;             			// �¼�����ʱ��
}DCM_PROCESS_ANALYSIS_EVENT_S, *DCM_PPROCESS_ANALYSIS_EVENT_S;


/******************************************************************/
/*************************  (4)������  ****************************/
/******************************************************************/
typedef struct _AiData
{
    unsigned int    nAiCh;                  // AIͨ����
    float           fAiValue;               // Ai��ֵ
}AIDATA_S, *PAIDATA_S;                      //AI���ݽṹ(��Ҫ����4�ֽڶ���)

typedef struct _DiData
{
    unsigned char   ucDiChs;                // Di��ʼͨ����
    unsigned char   ucDiChe;                // Di��ֹͨ����
    unsigned short  usDiValue;              // Di��ֵ
}DIDATA_S, *PDIDATA_S;                      //DI���ݽṹ(��Ҫ����4�ֽڶ���)

typedef struct tagNCBaseDataInfo
{
    char    cDeviceAlarm;                   //NC��������״̬ 0��ʾ�ޱ�����1��ʾ�б���
    char    cDeviceEmergency;               //NC�����Ƿ�ͣ 0��ʾ�޼�ͣ��1��ʾ�м�ͣ
    short   sRev;                           //Ԥ��
    short   sDeviceRun;                     //NC��������״̬
    short   sDeviceAut;

    float   fAbsPosX;                       //NC������������X��λ��
    float   fAbsPosY;                       //NC������������Y��λ��
    float   fAbsPosZ;                       //NC������������Z��λ��
    float   fRestPosX;                      //NC����ʣ������X��λ��
    float   fRestPosY;                      //NC����ʣ������Y��λ��
    float   fRestPosZ;                      //NC����ʣ������Z��λ��

    unsigned int    unBatchNum;             //NC������������������
    char            acMainProgName[TC_MAXLEN_PROGRAMNO];     //NC�����������
    unsigned int    unCurProgName;          //NC�������г����к�

    float           fSpeedOverride;         //NC����������ת����
    float           fFeedOverride;          //NC������������
    unsigned int    unActSpSpeed;           //NC��������ʵ��ת��
    unsigned int    unActFeedrate;          //NC��������ʵ��ת��
    unsigned int    unSetSpSpeed;           //NC���������趨ת��
    unsigned int    unSetFeedrate;          //NC���������趨�ٶ�

    char            acToolNumber[TC_MAXLEN_TOOLID]; //NC�������ߺ�
    unsigned int    unToolOffset;           //NC����������

    float   fSpLoad;                        //NC�������Ḻ��
    float   fSpLoad2;                       //NC�������Ḻ��2
    float   fServoLoadX;                    //NC����X���ŷ�����
    float   fServoLoadY;                    //NC����Y���ŷ�����
    float   fServoLoadZ;                    //NC����Z���ŷ�����
    float   fServoLoadC;                    //NC����C���ŷ�����
    float   fServoLoadB;                    //NC����B���ŷ�����

    unsigned int   unGState;                //NC�����ӹ�״̬(G����)
    unsigned int   unCycTime;               //NC��������ѭ��ʱ��(����)
    int   nServoTemp;                       //NC�����ŷ��¶�
    int   nSpTemp;                          //NC���������¶�
}NCBASEDATA_INFO_S, *PNCBASEDATA_INFO_S;    //(��Ҫ����4�ֽڶ���)

typedef struct _Base_Data
{
    TCCOMM_TAGTIME_S    stTagSample;          // ���ݲɼ�ʱ���

    /*BASEDATA_NCSYS_INFO_S�а����������*/
    unsigned int        unVersion;                  //basedata�汾��
    unsigned int        unMID;                      //����ΨһID
    char       acNCID[TC_MAXLEN_NCID];     //NC����ϵͳΨһID
    unsigned char       cCHID;                      //NC����ͨ����
    /*BASEDATA_NCSYS_INFO_S�а����������*/

    /*BASEDATA_NCDATA_S�а����������*/
    unsigned char       cNCFreq;                    //NC����Ƶ�ʱ�־ 0��ʾ��������Ϊ���ƣ�1��ʾ�������ݸոո���
    unsigned char       cRev[2];                    //Ԥ�������ֽڶ���
    NCBASEDATA_INFO_S   stNCData;                   //NC�Ĳɼ�����
    unsigned char       cCheckRun;                  //ת�����NC����״̬
    unsigned char       cRev1[3];                   //Ԥ��
    /*BASEDATA_NCDATA_S�а����������*/

    /*RAM��ʹ���������*/
    unsigned int        unMMTypeID;                 //MMtypeΨһID
    unsigned char       cMMTypeValue;               //MMtype��ֵ
    unsigned char       cTCount;                    //�������
    unsigned char       cProcessCount;              //�������
    unsigned char       cProcessStatus;             //����״̬
    unsigned char       cCutStatus;                 //����״̬
    unsigned char       cRev2[3];                   //Ԥ��
    float               fFilterValue[4];            //Ԥ����ֵ
    /*RAM��ʹ���������*/

    /*AI��ʹ���������*/
    unsigned int        unAiId;                     //AI�豸��ID
    int                 nAiChNums;                  //AI��ͨ������
    AIDATA_S            stAiData[TC_MAXNUMS_AICH];  //AI����
    /*AI��ʹ���������*/

    /*DI��ʹ���������*/
    unsigned int        unDiId;                     //DI�豸��ID
    int                 nDiChNums;                  //DI��ͨ������
    DIDATA_S            stDiData[TC_MAXNUMS_DICH];  //DI����
    /*DI��ʹ���������*/
}BASE_DATA_S, *PBASE_DATA_S;                        //BaseData����(��Ҫ����4�ֽڶ���)

typedef struct _Dmm_DataComm
{
    bool                bDataStatus;                //�����Ƿ���ȷ 0:Ϊ����1:Ϊ��ȷ
    bool                bBdSyncFlag;                //Bd�Ƿ���Ҫͬ����װBd����
    unsigned short      nBdIndex;                   //Bd�������
}DMM_DATACOMM_S, *PDMM_DATACOMM_S;                  //Dmmģ������ͨ��ͷ��ʽ(��Ҫ����4�ֽڶ���)

typedef struct _BaseData_AiData
{
    DMM_DATACOMM_S      stDmmDataComm;              //Dmmģ������ͨ��ͷ��ʽ
    TCCOMM_TAGTIME_S    stTagSample;                // ���ݲɼ�ʱ���
    unsigned int        nAiId;                      // AiΨһID
    int                 nAiNums;                    // Aiͨ����
    AIDATA_S            stAiData[TC_MAXNUMS_AICH];  // Ai����
}BASEDATA_AIDATA_S, *PBASEDATA_AIDATA_S;            //AI����(��Ҫ����4�ֽڶ���)

typedef struct _BaseData_DiData
{
    DMM_DATACOMM_S      stDmmDataComm;              //Dmmģ������ͨ��ͷ��ʽ
    TCCOMM_TAGTIME_S    stTagSample;                // ���ݲɼ�ʱ���
    unsigned int        nDiId;                      // DiΨһID
    int                 nDiNums;                    // Diͨ����
    DIDATA_S            stDiData[TC_MAXNUMS_DICH];  // Di����
}BASEDATA_DIDATA_S, *PBASEDATA_DIDATA_S;            //DI����(��Ҫ����4�ֽڶ���)

typedef struct _BaseData_NcSysInfo
{
    DMM_DATACOMM_S  stDmmDataComm;
    unsigned int    eMFactoryType;                      //�豸����------����:DEV_MFACTORY_E
    unsigned int    eMFClassType;                       //�豸����ϵ��--����:DEV_MFCLS_E
    char            acCncType[TC_MAXLEN_CNC_TYPE];      //cnc����
    char            acCncVersion[TC_MAXLEN_CNC_VER];    //cnc�汾
    unsigned int    unCncAxis;                          //cnc����
    unsigned int    unVersion;                          //Basedata�汾
    unsigned int    unMID;                              //����ΨһID
    char            acNCID[TC_MAXLEN_NCID];             //NCϵͳΨһID
    int             iCHID;                             //NC����ͨ����
}BASEDATA_NCSYSINFO_S, *PBASEDATA_NCSYSINFO_S;          //ncϵͳ��Ϣ(��Ҫ����4�ֽڶ���)

typedef struct _BaseData_NcData
{
    DMM_DATACOMM_S          stDmmDataComm;              // Dmmģ������ͨ��ͷ��ʽ
    TCCOMM_TAGTIME_S        stTagSample;                // ���ݲɼ�ʱ���
    unsigned int            unNCFreq;                   // NC����Ƶ�ʱ�־ 0��ʾ��������Ϊ���ƣ�1��ʾ�������ݸոո���

    NCBASEDATA_INFO_S       stNCBaseData;               //NC�Ĳɼ�����
    unsigned int            unCheckRun;                 //ת�����NC����״̬��0xFFΪ�������ݲɼ��쳣
}BASEDATA_NCDATA_S, *PBASEDATA_NCDATA_S;                //NC����(��Ҫ����4�ֽڶ���)

/* �㷨���ģ��*/
typedef struct tagMMIdModleInfo_t
{
    unsigned    int     uiMID;                              // ����id
    char                acPnNum[TC_MAXLEN_PROGRAMNO];     	// �����
    char                acToolNum[TC_MAXLEN_TOOLID];        // ���ߺ�
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        	// ͨ��ID
    int                 iMMTypeID;                         	// ��ط�������
    char                acMMID[TCAMCFG_MAXLEN_MMID];        // MMid
    unsigned    int     uiSigCode;                      	// �źű���
    unsigned    int     uiFeatureType;                      // ��������
                int     iFreqofSampling;                   	// ����Ƶ�� ��λHZ
    unsigned    int     uiModelLen;                         // ģ�ͳ��� 
    char*               pModelData;                         // ģ������
    unsigned    int     uiStartTimeLen;                     // ��ʼʱ�䳤��
    char*               piStartTime;                        // ָ��ÿ������ѧϰ�Ĺ�������ʱ���	
    TCCOMM_TAGTIME_S    stModleTime;                        // ģ������ʱ��
}RMM_MMIDMODULE_INFO, *PRMM_MMIDMODULE_INFO;

