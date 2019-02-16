/******************************************************************************

                  版权所有 (C), 2018-2028, 杭州友机技术有限公司

 ******************************************************************************
  文 件 名   : TerminalStruct.h
  版 本 号   : 初稿
  作    者   : 蒋康
  生成日期   : 2018年12月24日
  最近修改   :
  功能描述   : 终端结构的通用头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2018年12月24日
    作    者   : 蒋康
    修改内容   : 创建文件

******************************************************************************/
#define VOS_SOCK_IPADDR_LEN 16
/******************************************************************/
/************************* 通用定义 *******************************/
/******************************************************************/
/************************* 通用结构 *******************************/
/*命令通用头: 12字节*/
typedef struct tagBaseCmdHead
{
    unsigned int    iCommunType;        //前端通信主类型: BASECMD_MTYPE_E
    unsigned int    iSubType;           //前端通信子类型: BASECMD_STYPE_CFG_E/
    unsigned int    iDataLen;           //前端通信数据包长度:
}BASE_CMDHEAD_S, *PBASE_CMDHEAD_S;

/*DMM、RAM队列通用头结构*/
typedef struct tagBaseQueHead
{
    BASE_CMDHEAD_S  stBaseCmd;
    unsigned int    nBdIndex;
    unsigned int    nAction;
}BASE_QUEHEAD_S, *PBASE_QUEHEAD_S;

/******************************************************************/
/*************************  (1)配置类  ****************************/
/******************************************************************/
/*配置类型的DI通道信息*/
typedef struct tagDIIOChConfig
{
    unsigned int iSignalDictCode;       // 信号字典码
    unsigned int chStart;               // 通道起始,例如: chStart=1,没有就0xFF结束
    unsigned int chEnd;                 // 通道结束,例如: chEnd=2, 没有就0xFF结束
}DIIO_CHCFG_S, *PDIIO_CHCFG_S;

typedef struct tagAIIOChConfig
{
    unsigned int iSignalDictCode;       // 信号字典码
    unsigned int iAIChID;               // 通道ID
}AIIO_CHCFG_S, *PAIIO_CHCFG_S;

/*配置类型的基础信息: 228*/
typedef struct tagBaseCommConfig
{
    unsigned int    uiMID;                          //机器ID
    char            acNCID[TC_MAXLEN_NCID];         //NC的ID
    unsigned int    uiCHID;                         //NC的通道ID
    unsigned int    uiAIID;                         //AI的ID
    AIIO_CHCFG_S    stAICHID[TC_MAXNUMS_AICH];      //AI的通道值:例如: acAICHID[0]=1, acAICHID[1]=0xFF(以0xFF结尾)
    unsigned int    uiDIID;                         //DI的ID
    DIIO_CHCFG_S    stDICHID[TC_MAXNUMS_DICH];      //DI的通道值
}BASE_COMMCFG_S, *PBASE_COMMCFG_S;

/*Base通用的基础信息头结构定义*/
typedef struct tagBaseCommHead
{
    BASE_CMDHEAD_S  stCmdHead;          /*命令头部*/
    BASE_COMMCFG_S   stComInfo;         /*通用配置信息*/
}BASE_COMMHEAD_S, *PBASE_COMMHEAD_S;

typedef struct _TcComm_TagTime
{
    unsigned short  usYear;         //年
    unsigned char   ucMonth;        //月
    unsigned char   ucDay;          //日
    unsigned char   ucHour;         //时
    unsigned char   ucMinute;       //分
    unsigned char   ucSecond;       //秒
    unsigned char   cRsv[3];        //保留，字节对齐
    unsigned short  usMilliS;       //毫秒
}TCCOMM_TAGTIME_S, *PTCCOMM_TAGTIME_S;      // TC通用时间戳  (12字节)

/************************* 1.设备系统配置 ****************************/
//NC设备系统配置信息
typedef struct tagNCDevSysConfig
{
    unsigned int    unMid;
    char   acNCID[TC_MAXLEN_NCID];              //NC的ID
    unsigned int    eMFactoryType;              //设备厂商------定义:DEV_MFACTORY_E
    unsigned int    eMFClassType;               //设备厂商系列--定义:DEV_MFCLS_E
    char   acNCIP[VOS_SOCK_IPADDR_LEN];         //NC的IP地址
    unsigned int    uiNCPort;                   //NC的端口
    unsigned int    uiNCFreq;                   //NC采集频率
}NCDEV_SYSCFG_S, *PNCDEV_SYSCFG_S;

/*NC设备系统配置信息:消息通信结构*/
typedef struct tagNCDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_DEVINFO_NC
    unsigned int    uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    NCDEV_SYSCFG_S  stSysCfgInfo;               //NC系统配置信息
}NCDEV_CFGMSG_S, *PNCDEV_CFGMSG_S;  

//ADIO设备系统配置信息
typedef struct tagADIODevSysConfig
{
    unsigned int    uiADIOID;                   //ADIO ID 配置指定
    unsigned int    eMFactoryType;              //设备厂商------定义:DEV_MFACTORY_E
    unsigned int    eMFClassType;               //设备厂商系列--定义:DEV_MFCLS_E
    unsigned int    uiADIOConnType;             //USB/串口
    unsigned int    uiADIOFreq;                 //ADIO采集频率
    unsigned int    uiAIEnable;                 //AI采集是否使能
    unsigned int    uiDIEnable;                 //DI采集是否使能
}ADIODEV_SYSCFG_S, *PADIODEV_SYSCFG_S;

/*ADIO设备系统配置信息:消息通信结构*/
typedef struct tagAdioDevSysCfgMessage
{
    BASE_COMMHEAD_S     stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_DEVINFO_ADIO
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    ADIODEV_SYSCFG_S    stSysCfgInfo;               //ADIO系统配置信息
}ADIODEV_CFGMSG_S, *PADIODEV_CFGMSG_S;

/************************* 2.DMM设备配置 ****************************/
/*DMM设备系统配置信息*/
typedef struct tagDmmDevSysConfig
{
    BASE_COMMCFG_S      stCommHead;                 // 通用头格式(根据这个BD头索引)
    unsigned int      usVersion;                  // BD版本信息
    unsigned int        uiMasterSyncType;           // 主同步源类型--定义: DEVSYNC_TYPE_E
}DMMDEV_SYSCFG_S, *PDMMDEV_SYSCFG_S;

/*DMM设备系统配置信息:消息通信结构*/
typedef struct tagDmmDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_DMMINFO
    unsigned int    uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    DMMDEV_SYSCFG_S stSysCfgInfo;               //DMM系统配置信息
}DMMDEV_CFGMSG_S, *PDMMDEV_CFGMSG_S;

/*DMM设备系统控制配置*/
typedef struct tagDmmDevCtrlParam
{
    unsigned int  uiDevType;                    //设备类型      (DEV_TYPE_E)
    char acParam[TC_MAXLEN_SIZE32];             //参数
    unsigned int  unValue;                      //值
}DMMDEV_CTLPARAM_S, *PDMMDEV_CTLPARAM_S;
/*DMM设备系统控制配置*/
typedef struct tagDmmDevCtrlCfg
{
    unsigned int        uiCtrlType;                     //控制类型  (DEVCTRL_TYPE_E)
    unsigned int        uiNums;                         //参数组合数量
    DMMDEV_CTLPARAM_S   stCtlParmCmd[TC_MAXNUMS_DEVCTL];//参数组合
}DMMDEV_CTRLCFG_S,*PDMMDEV_CTRLCFG_S;
/*消息*/
typedef struct tagDmmDevCtrlCfgMessage
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_DMMCTRL
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    DMMDEV_CTRLCFG_S    stCtrlCfg;                  //DMM系统配置信息
}DMMDEV_CTRLCFGMSG_S, *PDMMDEV_CTRLCFGMSG_S;

/************************* 3.EAM分析方法配置 ****************************/
typedef struct tagEAMMethodConfig
{
    unsigned int    uiClassType;        //分段类        (EVT_PROCESSANALYZE_E)
    unsigned int    uiSignalDictCode;       // 状态:F                 
    unsigned int    uiMethodType;  //方法:阈值      (cjwangTODO)
    unsigned int    uiMethodValue; //阈值的值
}EAM_METHCFG_S, *PEAM_METHCFG_S;

/*EAM配置信息:消息通信结构*/
typedef struct tagEAMMethodCfgMessage
{
    BASE_COMMHEAD_S  stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_EAMINFO
    unsigned int    uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    EAM_METHCFG_S   stCfgInfo;                  //EAM分析方法配置
}EAM_CFGMSG_S, *PEAM_CFGMSG_S;

/************************* 4.RAM分析方法配置 ****************************/
typedef struct tagRAMCfgEntry
{
    unsigned int    uiSignalDictCode;   // 状态:F                 (BDDATA_TYPE_E)
    unsigned int    uiMethodType;       // 方法:阈值       
    unsigned int    uiMethodAttrType;   // 超过阈值/低于阈值
    unsigned int    uiDelayTime;        // 延迟时间 毫秒
}RAM_CFGENTRY_S, *PRAM_CFGENTRY_S;

typedef struct tagRAMMethodConfig
{
    int        uiMMTypeID;                     //MMType唯一标识
    unsigned int        uiClassType;                    //分段类           (EVT_PROCESSANALYZE_E)
    unsigned int        unNums;
    RAM_CFGENTRY_S      stRAMCfgEnty[RAMCFG_MTHNUMS];   //可以通过多个组合
}RAM_METHCFG_S, *PRAM_METHCFG_S;

/*RAM配置信息:消息通信结构 140*/
typedef struct tagRamDevSysCfgMessage
{
    BASE_COMMHEAD_S  stHead;                         //消息命令头 子类型    BASECMD_STYPE_CFG_RAMINFO
    unsigned int    uiActionType;                   //操作: Add or Delete (BASECMD_ACTION_E)
    RAM_METHCFG_S   stCfgInfo;                      //RAM分析方法配置
}RAM_CFGMSG_S, *PRAM_CFGMSG_S;

/************************* 4.RMM分析方法配置 ****************************/
/*a. RMM监控过程默认配置信息*/
typedef struct tagRMMCfgMonitorProcess
{
    unsigned    int     uiMID;                              // 机器id
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        // 通道ID
    int                 iMMTypeID;                         // 监控方法类型
    unsigned    int     uiSigCode;    // 信号编码
    unsigned    int     uiFeatureType;                     // 特征类型 32
    int                 iLearnCnt;                         // 学习次数
    int                 iLearnType;                        // 学习类型       
    TCCOMM_TAGTIME_S    stCfgTime;                          // 配置生成时间
}RMMCFG_MNPROC_S, *PRMMCFG_MNPROC_S;

/*a. RMM监控过程配置信息:消息通信结构*/
typedef struct tagRMMCfgMonitorProcessMessage
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_RMMPROC
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNPROC_S     stCfgInfo;                  //RMM监控过程配置信息
}RMMCFG_MNPROCMSG_S, *PRMMCFG_MNPROCMSG_S;

/*b. RMM监控过程MMID 生成方式*/
typedef struct tagMMProcessMMIDFormTypeCfg
{
    unsigned    int     uiMID;                              // 机器id
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        	// 通道ID
    int                 iMMTypeID;                         	// 监控方法类型
    int                 iMMIDForm;                          // MMID构成方式
    char                acUsrDefMMID[TC_MAXLNE_USRMMID];    // 用户自定义MMID  
    TCCOMM_TAGTIME_S    sCfgTime;                           // 配置生成时间
}RMMCFG_MMIDTYPE_S, *PRMMCFG_MMIDTYPE_S;

/*b. RMM监控过程MMID 生成方式:消息通信结构*/
typedef struct tagMMProcessMMIDFormTypeCfgMsg
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_RMMPROCMMID
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MMIDTYPE_S     stCfgInfo;                  //RMM监控过程MMID 生成方式
}RMMCFG_MMIDTYPEMSG_S, *PRMMCFG_MMIDTYPEMSG_S;


/*c. RMM监控评估规则配置信息*/
typedef struct tagRMMCfgMonitorEvalRule
{
    unsigned int   unFeatureType;                             // 特征类型
    int   iUpperLimitDiagRlt;                       // 诊断结论(超上限) 
    int   iMidLimitDiagRlt;                         // 诊断结论(未超限) 
    int   iLowerLimitDiagRlt;                       // 诊断结论(超下限) 
}RMMCFG_MNEVRULE_S, *PRMMCFG_MNEVRULE_S;

/*c. RMM监控评估规则配置信息:消息通信结构*/
typedef struct tagRMMCfgMonitorEvalRuleMessage
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_RMMEVLRULE
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNEVRULE_S     stCfgInfo;                  //RMM监控评估配置信息
}RMMCFG_MNEVRULEMSG_S, *PRMMCFG_MNEVRULEMSG_S;

/*d. RMM监控决策规则配置信息*/
typedef struct tagRMMCfgMonitorDeciRule
{
    int     iSourceID;  // 事件来源:模块名
    int     iEvtType;                           // 事件类型
    int     iDiagResult;                        // 诊断结论
    int     iDecisionType;                      // 决策类型
    int     iExecEnable;                        // 执行开关 
}RMMCFG_MNDECIRULE_S, *PRMMCFG_MNDECIRULE_S;

/*d. RMM监控决策规则配置信息:消息通信结构*/
typedef struct tagRMMCfgMonitorDeciRuleMessage
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_CFG_RMMDECIRULE
    unsigned int        uiActionType;               //操作: Add or Delete (BASECMD_ACTION_E)
    RMMCFG_MNDECIRULE_S     stCfgInfo;                  //RMM监控决策配置信息
}RMMCFG_MNDECIRULEMSG_S, *PRMMCFG_MNDECIRULEMSG_S;

/******************************************************************/
/*************************  (2)消息类  ****************************/
/******************************************************************/
/*NC探测请求*/
typedef struct tagNCProbeRequestInfo
{
    unsigned int    uiMID;                          //机器ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    eMFactoryType;                  //设备厂商      DEV_MFACTORY_E
    unsigned int    eMFClassType;                   //厂商系列      DEV_MFCLS_E
    unsigned char   acNCIP[VOS_SOCK_IPADDR_LEN];    //NC的IPV4地址
    unsigned int    uiNCPort;                       //NC的端口
    unsigned int    uiNCFreq;                       //NC的采集频率
}NCPROBE_REQINFO_S, *PNCPROBE_REQINFO_S;

typedef struct tagNCProbeRequest
{
    BASE_CMDHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_MSG_NCPROB_RESQ
    NCPROBE_REQINFO_S   stProbeReqInfo;             //探测请求信息
}NCPROB_REQMSG_S, *PNCPROB_REQMSG_S;

/*NC探测响应*/
typedef struct tagNCProbeResponseInfo
{
    unsigned int    uiMID;                          //机器ID
    char            acNCID[TC_MAXLEN_NCID];         //结果
    unsigned int    eMFactoryType;                  //设备厂商      DEV_MFACTORY_E
    unsigned int    eMFClassType;                   //厂商系列      DEV_MFCLS_E
    unsigned int    uiCHNums;                       //NC的通道数量
}NCPROBE_RESPINFO_S, *PNCPROBE_RESPINFO_S;

typedef struct  tagNCProbeResponse
{
    BASE_CMDHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_MSG_NCPROB_RESP
    NCPROBE_RESPINFO_S  stProbeRespInfo;            //探测请求响应
}NCPROB_RESPMSG_S, *PNCPROB_RESPMSG_S;

/*ADIO探测请求*/
typedef struct tagADIOProbeRequestInfo
{
    unsigned int    uiMID;                      //机器ID
    unsigned int    uiADIOID;                   //配置指定
    unsigned int    eMFactoryType;              //设备厂商      DEV_MFACTORY_E
    unsigned int    eMFClassType;               //厂商系列      DEV_MFCLS_E
    unsigned int    uiADIOFreq;                 //ADIO采集频率
}ADIOPROBE_REQINFO_S, *PADIOPROBE_REQINFO_S;

typedef struct tagADIOProbeRequest
{
    BASE_CMDHEAD_S          stHead;                 //消息命令头 子类型    BASECMD_STYPE_MSG_ADIOPROB_RESQ
    ADIOPROBE_REQINFO_S     stProbeReqInfo;         //探测请求信息
}ADIOPROB_REQMSG_S, *PADIOPROB_REQMSG_S;

/*ADIO探测响应*/
typedef struct tagADIOProbeResponseInfo
{
    unsigned int    uiMID;                      //机器ID
    unsigned int    uiADIOID;                   //结果
    unsigned int    eMFactoryType;              //设备厂商      DEV_MFACTORY_E
    unsigned int    eMFClassType;               //厂商系列      DEV_MFCLS_E
    unsigned int    uiAICHNums;                 //AI通道数量
    unsigned int    uiDICHNums;                 //DI通道数量
}ADIOPROBE_RESPINFO_S, *PADIOPROBE_RESPINFO_S;

typedef struct  tagADIOProbeResponse
{
    BASE_CMDHEAD_S          stHead;                     //消息命令头 子类型    BASECMD_STYPE_MSG_ADIOPROB_RESP
    ADIOPROBE_RESPINFO_S    stProbeRespInfo;            //探测请求响应
}ADIOPROB_RESPMSG_S, *PADIOPROB_RESPMSG_S;


/*监控过程配置*/
typedef struct tagRMMConfigProcUpdateInfo
{
    unsigned    int     iMID;                               // 机器id
    char                acPnNum[TC_MAXLEN_PROGRAMNO];       // 程序号
    char                acToolNum[TC_MAXLEN_TOOLID];        // 刀具号
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChanID;                           // 通道ID
    int                 iMMType;                           // 监控方法类型
    char                acMMID[TCAMCFG_MAXLEN_MMID];        // MMID
    unsigned    int     uiSigCode;                          // 信号编码
    unsigned    int     uiFeatureType;                      // 特征类型
    int                 iLearnCnt;                         // 学习次数
    int                 iLearnType;                        // 学习类型
    int                 iAbnDetectLastTime;	   			    // 数据异常检测定时器定时时间               单位:毫秒
    int                 iStateRegEnable;                    // 对比开关     0: 不对比      1: 对比
    int                 iAlarmEnable;                       // 报警开关     0: 报警关闭 1: 报警打开
    int                 iReLearnFlag;                       // 重新学习标志   0: 不重新学习  1: 重新学习 
    int                 iOfflineReLearnFlag;                // 离线再学习标志 0: 不用离线再学习 1：离线再学习
    float               fupperLimitScal;                    // 上限缩放比例
    float               fLowerLimitScal;                    // 下限缩放比例
    int                 iPeekExpansionParams;               // 波峰膨胀参数
    int                 iCfgValid;                          // 配置是否有效   0: 无效 1：有效
    TCCOMM_TAGTIME_S    stCfgTime;                          // 配置生成时间
}RMM_MMIDPROCCFG_INFO_S, *PRMM_MMIDPROCCFG_INFO_S;


typedef struct  tagRmmConfigUpdateMessage
{
    BASE_CMDHEAD_S              stHead;                     //消息命令头 子类型    BASECMD_STYPE_MSG_RMMUPDATE
    RMM_MMIDPROCCFG_INFO_S      stUpdateInfo;               //更新信息
}RMM_MMIDPROCCFG_INFOMSG_S, *PRMM_MMIDPROCCFG_INFOMSG_S;


/*设备控制消息请求*/
typedef struct tagDmmCtrlRequestInfo
{
    unsigned int    uiMID;                      //机器ID
    char            acNCID[TC_MAXLEN_NCID];     //NCID
    unsigned char   acCHID;                     //CHID
    unsigned int    nCtrlType;                  //命令控制      DEVCTRL_TYPE_E
}DMMCTL_REQINFO_S, *PDMMCTL_REQINFO_S;

typedef struct tagDmmCtrlRequestInfoMessage
{
    BASE_CMDHEAD_S      stHead;                 //消息命令头 子类型    BASECMD_STYPE_MSG_DEVCTRL_RESQ
    DMMCTL_REQINFO_S   stProbeReqInfo;          //探测请求信息
}DMMCTL_REQINFOMSG_S, *PDMMCTL_REQINFOMSG_S;

/*设备控制响应*/
typedef struct tagDMMCtrlResponseInfo
{
    unsigned int    uiMID;                      //机器ID
    char            acNCID[TC_MAXLEN_NCID];     //NCID
    unsigned char   acCHID;                     //CHID
    unsigned int    nCtrlResult;                //命令控制结果            cjwangTODO
}DMMCTL_RESPINFO_S, *PDMMCTL_RESPINFO_S;

typedef struct  tagDMMCtrlResponseInfoMessage
{
    BASE_CMDHEAD_S     stHead;                     //消息命令头 子类型    BASECMD_STYPE_MSG_DEVCTRL_RESP
    DMMCTL_RESPINFO_S  stProbeRespInfo;             //设备控制响应
}DMMCTL_RESPINFOMSG_S, *PDMMCTL_RESPINFOMSG_S;

/*数据库信息-请求*/
typedef struct tagDBMCtrlRequestInfo
{
    unsigned int    uiCtrlCode;                     //请求码
}DBMDB_INFOREQ_S, *PDBMDB_INFOREQ_S;

typedef struct tagDbmCtrlRequestInfoMessage
{
    BASE_CMDHEAD_S    stHead;                 //消息命令头 子类型    BASECMD_STYPE_MSG_DBMINFO_RESQ
    DBMDB_INFOREQ_S   stReqInfo;         //探测请求信息
}DBMDB_INFOREQMSG_S, *PDBMDB_INFOREQMSG_S;

/*数据库信息-响应*/
typedef struct tagDBMCtrlResponseInfo
{
    unsigned int    uiCtrlCode;                      //内部的消息码
    unsigned char   acEventDBDir[TC_MAX_PATH];       //事件数据库路径
    unsigned char   acAlgmDBDir[TC_MAX_PATH];        //算法数据库路径
}DBMDB_INFORESP_S, *PDBMDB_INFORESP_S;

/*数据库的控制消息*/
typedef struct  tagDBMCtrlResponseInfoMessage
{
    BASE_CMDHEAD_S     stHead;                      //消息命令头 子类型    BASECMD_STYPE_MSG_DBMINFO_RESP
    DBMDB_INFORESP_S  stMsgInfo;                   //消息内容
}DBMDB_INFORESPMSG_S, *PDBMDB_INFORESPMSG_S;


/******************************************************************/
/*************************  (3)事件类  ****************************/
/******************************************************************/
//设备状态事件: BASECMD_STYPE_MSG_E
typedef struct tagDevStatusEvtBaseInfo
{
    TCCOMM_TAGTIME_S    stTime;           //时间戳
    unsigned int    uiMID;                          //机器ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    uiCHID;                         //通道ID
    unsigned int    uiADIOID;                       //ADIO的ID
    char            acPnNo[TC_MAXLEN_PROGRAMNO];      //程序ID
    char            acToolNum[TC_MAXLEN_TOOLID];        // 刀具号
    unsigned int    uiBatchNum;                     // 零件产生数
    unsigned int    uiDevEvtType;                     //事件类型
    unsigned int    uiEventSource;                  // 事件产生来源
}EVTSTAT_BASEINFO_S, *PEVTSTAT_BASEINFO_S;

typedef struct  tagDevStatusEventMessage
{
    BASE_COMMHEAD_S      stHead;                     //消息命令头 子类型    BASECMD_STYPE_EVT_PROCESSDEVICE
    EVTSTAT_BASEINFO_S   stEvtBaseInfo;             //设备状态事件信息
}EVTSTAT_BASEINFOMSG_S, *PEVTSTAT_BASEINFOMSG_S;

//过程分析事件: BASECMD_STYPE_MSG_E
typedef struct tagProcAnalyzeEvtBaseInfo
{
    TCCOMM_TAGTIME_S    stTime;           //时间戳
    unsigned int    uiMID;                          //机器ID
    char            acNCID[TC_MAXLEN_NCID];         //NCID
    unsigned int    uiCHID;                         //通道ID
    unsigned int    uiIOID;                         //ADIO的ID
    char            acProgramNo[TC_MAXLEN_PROGRAMNO];      //程序ID
    char            acToolNum[TC_MAXLEN_TOOLID];        // 刀具号
    unsigned int    uiBatchNum;                     // 零件产生数
    
    unsigned int    uiClassType;                    // 分段类型
    unsigned int    uiSignalDictCode;               //T F S 刀具号
    char            acSignalValue[TC_MAXLEN_SIZE32];//当前的选定信号的值
    unsigned int    uiStatusMethodType;             //状态方法类型:变化
    unsigned int    uiResultValue;                  //判断结果值:0/1

    unsigned int    uiEventSource;                  // 事件产生来源
}PROCANALZE_BASEINFO_S, *PPROCANALZE_BASEINFO_S;

typedef struct  tagProcAnalyzeEvtBaseInfoMessage
{
    BASE_COMMHEAD_S          stHead;                //消息命令头 子类型    BASECMD_STYPE_EVT_PROCESSANALYZE
    PROCANALZE_BASEINFO_S   stEvtBaseInfo;          //过程分析事件信息
}PROCALZE_BASEINFOMSG_S, *PPROCALZE_BASEINFOMSG_S;

// 监控事件
typedef struct tagMonitorMMIDEvent
{
    unsigned int    uiMID;                           		// 机器ID
    int    			iEvtType;                       		// 事件类型
    char            acPnNum[TC_MAXLEN_PROGRAMNO];   		// 程序ID
    char            acToolNum[TC_MAXLEN_TOOLID];    		// 刀具号
    char            acMMID[TCAMCFG_MAXLEN_MMID];    		// MMID
    TCCOMM_TAGTIME_S    stMonitorStartTime;                     	// 监控过程开始事件
    unsigned int    uiSignalCode; 							// 信号编码
    unsigned int    uiFeatureType;           				// 特征类型
    int             iMonitorState;          				// 监控状态 0：开 1：关 2：learning 3：观察模式
    int             iDiagRlt;             					// 诊断结论
    TCCOMM_TAGTIME_S    stEventTime;             			// 事件产生时间

    unsigned int    uiEventSource;                          // 事件产生来源, 按照业务分类
}ALGOMONITOREVENT_S, *PALGOMONITOREVENT_S;


// 发往决策中心的监控事件
typedef struct tagDCMMonitorMMIDEvent
{
    unsigned int    uiMID;                           		// 机器ID
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // 发送事件的模块名
    int             iEvtSrc;                                // 事件来源 见BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// 事件类型
    char            acPnNum[TC_MAXLEN_PROGRAMNO];   		// 程序ID
    char            acToolNum[TC_MAXLEN_TOOLID];    		// 刀具号
    char            acNcID[TC_MAXLEN_NCID];             	// NCid
    int             iChanID;                           		// 通道ID
    char            acMMID[TCAMCFG_MAXLEN_MMID];    		// MMID
    TCCOMM_TAGTIME_S    iStartTime;                     	// 监控过程开始事件
    unsigned int    uiSignalCode; 							// 信号编码
    unsigned int    uiFeatureType;           				// 特征类型
    int             iMonitorState;          				// 监控状态 0：开 1：关 2：learning 3：观察模式
    int             iDiagRlt;             					// 诊断结论
    int                 iAlarmEnable;                       // 报警开关     0: 报警关闭 1: 报警打开
    TCCOMM_TAGTIME_S    iEventTime;             			// 事件产生时间
}DCM_ALGOMONITOREVENT_S, *DCM_PALGOMONITOREVENT_S;

// 发往决策中心的设备状态事件
typedef struct tagDeviceStatusEvent
{
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // 发送事件的模块名
    int             iEvtSrc;                                // 事件来源 见BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// 事件类型
	// Add other member
    TCCOMM_TAGTIME_S    iEventTime;             			// 事件产生时间
}DCM_DEVICE_STATUS_EVENT_S, *DCM_PDEVICE_STATUS_EVENT_S;

// 发往决策中心的过程分析事件
typedef struct tagProcessAnalysisEvent
{
    char            acSourceID[TC_MAXLNE_MODULE_NAME];      // 事件来源: 模块名
    int             iEvtSrc;                                // 事件来源 见BASECMD_STYPE_EVT_E
    int    			iEvtType;                       		// 事件类型
	// Add other member
    TCCOMM_TAGTIME_S    iEventTime;             			// 事件产生时间
}DCM_PROCESS_ANALYSIS_EVENT_S, *DCM_PPROCESS_ANALYSIS_EVENT_S;


/******************************************************************/
/*************************  (4)数据类  ****************************/
/******************************************************************/
typedef struct _AiData
{
    unsigned int    nAiCh;                  // AI通道号
    float           fAiValue;               // Ai的值
}AIDATA_S, *PAIDATA_S;                      //AI数据结构(需要保持4字节对齐)

typedef struct _DiData
{
    unsigned char   ucDiChs;                // Di起始通道号
    unsigned char   ucDiChe;                // Di终止通道号
    unsigned short  usDiValue;              // Di的值
}DIDATA_S, *PDIDATA_S;                      //DI数据结构(需要保持4字节对齐)

typedef struct tagNCBaseDataInfo
{
    char    cDeviceAlarm;                   //NC机床报警状态 0表示无报警，1表示有报警
    char    cDeviceEmergency;               //NC机床是否急停 0表示无急停，1表示有急停
    short   sRev;                           //预留
    short   sDeviceRun;                     //NC机床运行状态
    short   sDeviceAut;

    float   fAbsPosX;                       //NC机床绝对坐标X的位置
    float   fAbsPosY;                       //NC机床绝对坐标Y的位置
    float   fAbsPosZ;                       //NC机床绝对坐标Z的位置
    float   fRestPosX;                      //NC机床剩余坐标X的位置
    float   fRestPosY;                      //NC机床剩余坐标Y的位置
    float   fRestPosZ;                      //NC机床剩余坐标Z的位置

    unsigned int    unBatchNum;             //NC机床总生产工件数据
    char            acMainProgName[TC_MAXLEN_PROGRAMNO];     //NC机床主程序号
    unsigned int    unCurProgName;          //NC机床运行程序行号

    float           fSpeedOverride;         //NC机床主轴旋转倍率
    float           fFeedOverride;          //NC机床进给倍率
    unsigned int    unActSpSpeed;           //NC机床主轴实际转速
    unsigned int    unActFeedrate;          //NC机床进给实际转速
    unsigned int    unSetSpSpeed;           //NC机床主轴设定转速
    unsigned int    unSetFeedrate;          //NC机床进给设定速度

    char            acToolNumber[TC_MAXLEN_TOOLID]; //NC机床刀具号
    unsigned int    unToolOffset;           //NC机床刀补号

    float   fSpLoad;                        //NC机床主轴负载
    float   fSpLoad2;                       //NC机床主轴负载2
    float   fServoLoadX;                    //NC机床X轴伺服负载
    float   fServoLoadY;                    //NC机床Y轴伺服负载
    float   fServoLoadZ;                    //NC机床Z轴伺服负载
    float   fServoLoadC;                    //NC机床C轴伺服负载
    float   fServoLoadB;                    //NC机床B轴伺服负载

    unsigned int   unGState;                //NC机床加工状态(G代码)
    unsigned int   unCycTime;               //NC机床程序循环时间(毫秒)
    int   nServoTemp;                       //NC机床伺服温度
    int   nSpTemp;                          //NC机床主轴温度
}NCBASEDATA_INFO_S, *PNCBASEDATA_INFO_S;    //(需要保持4字节对齐)

typedef struct _Base_Data
{
    TCCOMM_TAGTIME_S    stTagSample;          // 数据采集时间戳

    /*BASEDATA_NCSYS_INFO_S中包含这段数据*/
    unsigned int        unVersion;                  //basedata版本号
    unsigned int        unMID;                      //机床唯一ID
    char       acNCID[TC_MAXLEN_NCID];     //NC机床系统唯一ID
    unsigned char       cCHID;                      //NC机床通道号
    /*BASEDATA_NCSYS_INFO_S中包含这段数据*/

    /*BASEDATA_NCDATA_S中包含这段数据*/
    unsigned char       cNCFreq;                    //NC数据频率标志 0表示本条数据为复制，1表示本条数据刚刚更新
    unsigned char       cRev[2];                    //预留保持字节对齐
    NCBASEDATA_INFO_S   stNCData;                   //NC的采集数据
    unsigned char       cCheckRun;                  //转化后的NC运行状态
    unsigned char       cRev1[3];                   //预留
    /*BASEDATA_NCDATA_S中包含这段数据*/

    /*RAM中使用这段数据*/
    unsigned int        unMMTypeID;                 //MMtype唯一ID
    unsigned char       cMMTypeValue;               //MMtype的值
    unsigned char       cTCount;                    //刀具序号
    unsigned char       cProcessCount;              //过程序号
    unsigned char       cProcessStatus;             //过程状态
    unsigned char       cCutStatus;                 //切削状态
    unsigned char       cRev2[3];                   //预留
    float               fFilterValue[4];            //预处理值
    /*RAM中使用这段数据*/

    /*AI中使用这段数据*/
    unsigned int        unAiId;                     //AI设备的ID
    int                 nAiChNums;                  //AI的通道数量
    AIDATA_S            stAiData[TC_MAXNUMS_AICH];  //AI数据
    /*AI中使用这段数据*/

    /*DI中使用这段数据*/
    unsigned int        unDiId;                     //DI设备的ID
    int                 nDiChNums;                  //DI的通道数量
    DIDATA_S            stDiData[TC_MAXNUMS_DICH];  //DI数据
    /*DI中使用这段数据*/
}BASE_DATA_S, *PBASE_DATA_S;                        //BaseData数据(需要保持4字节对齐)

typedef struct _Dmm_DataComm
{
    bool                bDataStatus;                //数据是否正确 0:为错误，1:为正确
    bool                bBdSyncFlag;                //Bd是否需要同步组装Bd数据
    unsigned short      nBdIndex;                   //Bd索引标记
}DMM_DATACOMM_S, *PDMM_DATACOMM_S;                  //Dmm模块数据通用头格式(需要保持4字节对齐)

typedef struct _BaseData_AiData
{
    DMM_DATACOMM_S      stDmmDataComm;              //Dmm模块数据通用头格式
    TCCOMM_TAGTIME_S    stTagSample;                // 数据采集时间戳
    unsigned int        nAiId;                      // Ai唯一ID
    int                 nAiNums;                    // Ai通道数
    AIDATA_S            stAiData[TC_MAXNUMS_AICH];  // Ai数据
}BASEDATA_AIDATA_S, *PBASEDATA_AIDATA_S;            //AI数据(需要保持4字节对齐)

typedef struct _BaseData_DiData
{
    DMM_DATACOMM_S      stDmmDataComm;              //Dmm模块数据通用头格式
    TCCOMM_TAGTIME_S    stTagSample;                // 数据采集时间戳
    unsigned int        nDiId;                      // Di唯一ID
    int                 nDiNums;                    // Di通道数
    DIDATA_S            stDiData[TC_MAXNUMS_DICH];  // Di数据
}BASEDATA_DIDATA_S, *PBASEDATA_DIDATA_S;            //DI数据(需要保持4字节对齐)

typedef struct _BaseData_NcSysInfo
{
    DMM_DATACOMM_S  stDmmDataComm;
    unsigned int    eMFactoryType;                      //设备厂商------定义:DEV_MFACTORY_E
    unsigned int    eMFClassType;                       //设备厂商系列--定义:DEV_MFCLS_E
    char            acCncType[TC_MAXLEN_CNC_TYPE];      //cnc类型
    char            acCncVersion[TC_MAXLEN_CNC_VER];    //cnc版本
    unsigned int    unCncAxis;                          //cnc轴数
    unsigned int    unVersion;                          //Basedata版本
    unsigned int    unMID;                              //机床唯一ID
    char            acNCID[TC_MAXLEN_NCID];             //NC系统唯一ID
    int             iCHID;                             //NC机床通道号
}BASEDATA_NCSYSINFO_S, *PBASEDATA_NCSYSINFO_S;          //nc系统信息(需要保持4字节对齐)

typedef struct _BaseData_NcData
{
    DMM_DATACOMM_S          stDmmDataComm;              // Dmm模块数据通用头格式
    TCCOMM_TAGTIME_S        stTagSample;                // 数据采集时间戳
    unsigned int            unNCFreq;                   // NC数据频率标志 0表示本条数据为复制，1表示本条数据刚刚更新

    NCBASEDATA_INFO_S       stNCBaseData;               //NC的采集数据
    unsigned int            unCheckRun;                 //转化后的NC运行状态，0xFF为本条数据采集异常
}BASEDATA_NCDATA_S, *PBASEDATA_NCDATA_S;                //NC数据(需要保持4字节对齐)

/* 算法监控模型*/
typedef struct tagMMIdModleInfo_t
{
    unsigned    int     uiMID;                              // 机器id
    char                acPnNum[TC_MAXLEN_PROGRAMNO];     	// 程序号
    char                acToolNum[TC_MAXLEN_TOOLID];        // 刀具号
    char                acNcID[TC_MAXLEN_NCID];             // NCid
    int                 iChannelID;                        	// 通道ID
    int                 iMMTypeID;                         	// 监控方法类型
    char                acMMID[TCAMCFG_MAXLEN_MMID];        // MMid
    unsigned    int     uiSigCode;                      	// 信号编码
    unsigned    int     uiFeatureType;                      // 特征类型
                int     iFreqofSampling;                   	// 采样频率 单位HZ
    unsigned    int     uiModelLen;                         // 模型长度 
    char*               pModelData;                         // 模型数据
    unsigned    int     uiStartTimeLen;                     // 起始时间长度
    char*               piStartTime;                        // 指向每次用于学习的过程数据时间戳	
    TCCOMM_TAGTIME_S    stModleTime;                        // 模型生成时间
}RMM_MMIDMODULE_INFO, *PRMM_MMIDMODULE_INFO;

