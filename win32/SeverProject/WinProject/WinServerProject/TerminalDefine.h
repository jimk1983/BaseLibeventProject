/******************************************************************************

                  版权所有 (C), 2018-2028, 杭州友机技术有限公司

 ******************************************************************************
  文 件 名   : TerminalComm.h
  版 本 号   : 初稿
  作    者   : 蒋康
  生成日期   : 2018年10月23日
  最近修改   :
  功能描述   : 终端的定义的通用的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2018年10月23日
    作    者   : 蒋康
    修改内容   : 创建文件
  2.日    期: 2018年10月26日
    作    者: yifangKong
    修改内容   : (1). 增加RMM模块相关定义
              (2). 添加RMM模块监控事件类型

******************************************************************************/
typedef enum
{
	MODULE_TYPE_NULL = 0,
	MODULE_TYPE_RMM        // 在线监控模块
	// Pls. Add other module type below
	
}MODULE_TYPE_E;



/*BD数据(信号状态编)码定义*/
typedef enum
{
    BDSIGNAL_CODE_UNKNOW = 0,             /*未知*/
    BDSIGNAL_CODE_DEVALM,                 /*1.  设备报警*/
    BDSIGNAL_CODE_DEVRUN,                 /*2.  设备运行状态*/
    BDSIGNAL_CODE_DEVAUT,                 /*3.  设备自动模式*/
    BDSIGNAL_CODE_DEVEMG,                 /*4.  设备是否急停*/
    BDSIGNAL_CODE_ABSPOSX,                /*5.  x轴绝对坐标*/
    BDSIGNAL_CODE_ABSPOSY,                /*6.  y轴绝对坐标*/
    BDSIGNAL_CODE_ABSPOSZ,                /*7.  z轴绝对坐标*/
    BDSIGNAL_CODE_RESTPOSX,               /*8.  x轴机械坐标*/
    BDSIGNAL_CODE_RESTPOSY,               /*9.  y轴机械坐标*/
    BDSIGNAL_CODE_RESTPOSZ,               /*10. z轴机械坐标*/
    BDSIGNAL_CODE_BATCHNUMS,              /*11. 生产工件数量*/
    BDSIGNAL_CODE_MPROGNAME,              /*12. 主程序名*/
    BDSIGNAL_CODE_CPROGNAME,              /*13. 当前运行程序号*/
    BDSIGNAL_CODE_SPOV,                   /*14. 主轴倍率*/
    BDSIGNAL_CODE_FVOV,                   /*15. 进给倍率*/
    BDSIGNAL_CODE_ACTSP,                  /*16. 主轴实际转速*/
    BDSIGNAL_CODE_ACTFV,                  /*17. 进给实际转速*/
    BDSIGNAL_CODE_SETSP,                  /*18. 主轴设定速度*/
    BDSIGNAL_CODE_SETFV,                  /*19. 进给设定速度*/
    BDSIGNAL_CODE_TNUMBER,                /*20. 当前刀具号*/
    BDSIGNAL_CODE_TOFFSET,                /*21. 当前刀补号*/
    BDSIGNAL_CODE_SPLOAD,                 /*22. 主轴负载*/
    BDSIGNAL_CODE_SPLOAD2,                /*23. 主轴2负载*/
    BDSIGNAL_CODE_SERVOLOADX,             /*24. 伺服x轴负载*/
    BDSIGNAL_CODE_SERVOLOADY,             /*25. 伺服y轴负载*/
    BDSIGNAL_CODE_SERVOLOADZ,             /*26. 伺服z轴负载*/
    BDSIGNAL_CODE_SERVOLOADC,             /*27. 伺服C轴负载*/
    BDSIGNAL_CODE_SERVOLOADB,             /*28. 伺服B轴负载*/
    BDSIGNAL_CODE_GSTATE,                 /*29. G代码状态*/
    BDSIGNAL_CODE_CYCTIME,                /*30. 设备循环时间*/
    BDSIGNAL_CODE_SERVOTEMP,              /*31. 伺服温度*/
    BDSIGNAL_CODE_SPTEMP,                 /*32. 主轴温度*/
    BDSIGNAL_CODE_CHECKRUN,               /*33. 加工事件状态*/
    BDSIGNAL_CODE_FILTERV0,               /*34. 预处理预留*/
    BDSIGNAL_CODE_FILTERV1,               /*35. 预处理预留*/
    BDSIGNAL_CODE_FILTERV2,               /*36. 预处理预留*/
    BDSIGNAL_CODE_FILTERV3,               /*37. 预处理预留*/
    BDSIGNAL_CODE_FILTERV4,               /*38. 预处理预留*/
    BDSIGNAL_CODE_FILTERV5,               /*39. 预处理预留*/
    BDSIGNAL_CODE_FILTERV6,               /*40. 预处理预留*/
    BDSIGNAL_CODE_FILTERV7,               /*41. 预处理预留*/
    BDSIGNAL_CODE_FILTERV8,               /*42. 预处理预留*/
    BDSIGNAL_CODE_FILTERV9,               /*43. 预处理预留*/
    BDSIGNAL_CODE_FILTERV10,              /*44. 预处理预留*/
    BDSIGNAL_CODE_FILTERV11,              /*45. 预处理预留*/
    BDSIGNAL_CODE_FILTERV12,              /*46. 预处理预留*/
    BDSIGNAL_CODE_FILTERV13,              /*47. 预处理预留*/
    BDSIGNAL_CODE_FILTERV14,              /*48. 预处理预留*/
    BDSIGNAL_CODE_FILTERV15,              /*49. 预处理预留*/
    BDSIGNAL_CODE_AI0,                    /*50. AI*/
    BDSIGNAL_CODE_AI1,                    /*51. AI*/
    BDSIGNAL_CODE_AI2,                    /*52. AI*/
    BDSIGNAL_CODE_AI3,                    /*53. AI*/
    BDSIGNAL_CODE_AI4,                    /*54. AI*/
    BDSIGNAL_CODE_AI5,                    /*55. AI*/
    BDSIGNAL_CODE_AI6,                    /*56. AI*/
    BDSIGNAL_CODE_AI7,                    /*57. AI*/
    BDSIGNAL_CODE_AI8,                    /*58. AI*/
    BDSIGNAL_CODE_AI9,                    /*59. AI*/
    BDSIGNAL_CODE_AI10,                   /*60. AI*/
    BDSIGNAL_CODE_AI11,                   /*61. AI*/
    BDSIGNAL_CODE_AI12,                   /*62. AI*/
    BDSIGNAL_CODE_AI13,                   /*63. AI*/
    BDSIGNAL_CODE_AI14,                   /*64. AI*/
    BDSIGNAL_CODE_AI15,                   /*65. AI*/
    BDSIGNAL_CODE_AI16,                   /*66. AI*/
    BDSIGNAL_CODE_AI17,                   /*67. AI*/
    BDSIGNAL_CODE_AI18,                   /*68. AI*/
    BDSIGNAL_CODE_AI19,                   /*69. AI*/
    BDSIGNAL_CODE_AI20,                   /*70. AI*/
    BDSIGNAL_CODE_AI21,                   /*71. AI*/
    BDSIGNAL_CODE_AI22,                   /*72. AI*/
    BDSIGNAL_CODE_AI23,                   /*73. AI*/
    BDSIGNAL_CODE_AI24,                   /*74. AI*/
    BDSIGNAL_CODE_AI25,                   /*75. AI*/
    BDSIGNAL_CODE_AI26,                   /*76. AI*/
    BDSIGNAL_CODE_AI27,                   /*77. AI*/
    BDSIGNAL_CODE_AI28,                   /*78. AI*/
    BDSIGNAL_CODE_AI29,                   /*79. AI*/
    BDSIGNAL_CODE_AI30,                   /*80. AI*/
    BDSIGNAL_CODE_AI31,                   /*81. AI*/
    BDSIGNAL_CODE_AI32,                   /*82. AI*/
    BDSIGNAL_CODE_AI33,                   /*83. AI*/
    BDSIGNAL_CODE_AI34,                   /*84. AI*/
    BDSIGNAL_CODE_AI35,                   /*85. AI*/
    BDSIGNAL_CODE_AI36,                   /*86. AI*/
    BDSIGNAL_CODE_AI37,                   /*87. AI*/
    BDSIGNAL_CODE_AI38,                   /*88. AI*/
    BDSIGNAL_CODE_AI39,                   /*89. AI*/
    BDSIGNAL_CODE_AI40,                   /*90. AI*/
    BDSIGNAL_CODE_AI41,                   /*91. AI*/
    BDSIGNAL_CODE_AI42,                   /*92. AI*/
    BDSIGNAL_CODE_AI43,                   /*93. AI*/
    BDSIGNAL_CODE_AI44,                   /*94. AI*/
    BDSIGNAL_CODE_AI45,                   /*95. AI*/
    BDSIGNAL_CODE_AI46,                   /*96. AI*/
    BDSIGNAL_CODE_AI47,                   /*97. AI*/
    BDSIGNAL_CODE_AI48,                   /*98. AI*/
    BDSIGNAL_CODE_AI49,                   /*99. AI*/
    BDSIGNAL_CODE_AI50,                   /*100.AI*/
    BDSIGNAL_CODE_AI51,                   /*101.AI*/
    BDSIGNAL_CODE_AI52,                   /*102.AI*/
    BDSIGNAL_CODE_AI53,                   /*103.AI*/
    BDSIGNAL_CODE_AI54,                   /*104.AI*/
    BDSIGNAL_CODE_AI55,                   /*105.AI*/
    BDSIGNAL_CODE_AI56,                   /*106.AI*/
    BDSIGNAL_CODE_AI57,                   /*107.AI*/
    BDSIGNAL_CODE_AI58,                   /*108.AI*/
    BDSIGNAL_CODE_AI59,                   /*109.AI*/
    BDSIGNAL_CODE_AI60,                   /*110.AI*/
    BDSIGNAL_CODE_AI61,                   /*111.AI*/
    BDSIGNAL_CODE_AI62,                   /*112.AI*/
    BDSIGNAL_CODE_AI63,                   /*113.AI*/
    BDSIGNAL_CODE_DI0,                    /*114.DI*/
    BDSIGNAL_CODE_DI1,                    /*115.DI*/
    BDSIGNAL_CODE_DI2,                    /*116.DI*/
    BDSIGNAL_CODE_DI3,                    /*117.DI*/
    BDSIGNAL_CODE_DI4,                    /*118.DI*/
    BDSIGNAL_CODE_DI5,                    /*119.DI*/
    BDSIGNAL_CODE_DI6,                    /*120.DI*/
    BDSIGNAL_CODE_DI7,                    /*121.DI*/
    BDSIGNAL_CODE_DI8,                    /*122.DI*/
    BDSIGNAL_CODE_DI9,                    /*123.DI*/
    BDSIGNAL_CODE_DI10,                   /*124.DI*/
    BDSIGNAL_CODE_DI11,                   /*125.DI*/
    BDSIGNAL_CODE_DI12,                   /*126.DI*/
    BDSIGNAL_CODE_DI13,                   /*127.DI*/
    BDSIGNAL_CODE_DI14,                   /*128.DI*/
    BDSIGNAL_CODE_DI15,                   /*129.DI*/
    BDSIGNAL_CODE_DI16,                   /*130.DI*/
    BDSIGNAL_CODE_DI17,                   /*131.DI*/
    BDSIGNAL_CODE_DI18,                   /*132.DI*/
    BDSIGNAL_CODE_DI19,                   /*133.DI*/
    BDSIGNAL_CODE_DI20,                   /*134.DI*/
    BDSIGNAL_CODE_DI21,                   /*135.DI*/
    BDSIGNAL_CODE_DI22,                   /*136.DI*/
    BDSIGNAL_CODE_DI23,                   /*137.DI*/
    BDSIGNAL_CODE_DI24,                   /*138.DI*/
    BDSIGNAL_CODE_DI25,                   /*139.DI*/
    BDSIGNAL_CODE_DI26,                   /*140.DI*/
    BDSIGNAL_CODE_DI27,                   /*141.DI*/
    BDSIGNAL_CODE_DI28,                   /*142.DI*/
    BDSIGNAL_CODE_DI29,                   /*143.DI*/
    BDSIGNAL_CODE_DI30,                   /*144.DI*/
    BDSIGNAL_CODE_DI31,                   /*145.DI*/
    BDSIGNAL_CODE_DI32,                   /*146.DI*/
    BDSIGNAL_CODE_DI33,                   /*147.DI*/
    BDSIGNAL_CODE_DI34,                   /*148.DI*/
    BDSIGNAL_CODE_DI35,                   /*149.DI*/
    BDSIGNAL_CODE_DI36,                   /*150.DI*/
    BDSIGNAL_CODE_DI37,                   /*151.DI*/
    BDSIGNAL_CODE_DI38,                   /*152.DI*/
    BDSIGNAL_CODE_DI39,                   /*153.DI*/
    BDSIGNAL_CODE_DI40,                   /*154.DI*/
    BDSIGNAL_CODE_DI41,                   /*155.DI*/
    BDSIGNAL_CODE_DI42,                   /*156.DI*/
    BDSIGNAL_CODE_DI43,                   /*157.DI*/
    BDSIGNAL_CODE_DI44,                   /*158.DI*/
    BDSIGNAL_CODE_DI45,                   /*159.DI*/
    BDSIGNAL_CODE_DI46,                   /*160.DI*/
    BDSIGNAL_CODE_DI47,                   /*161.DI*/
    BDSIGNAL_CODE_DI48,                   /*162.DI*/
    BDSIGNAL_CODE_DI49,                   /*163.DI*/
    BDSIGNAL_CODE_DI50,                   /*164.DI*/
    BDSIGNAL_CODE_DI51,                   /*165.DI*/
    BDSIGNAL_CODE_DI52,                   /*166.DI*/
    BDSIGNAL_CODE_DI53,                   /*167.DI*/
    BDSIGNAL_CODE_DI54,                   /*168.DI*/
    BDSIGNAL_CODE_DI55,                   /*169.DI*/
    BDSIGNAL_CODE_DI56,                   /*170.DI*/
    BDSIGNAL_CODE_DI57,                   /*171.DI*/
    BDSIGNAL_CODE_DI58,                   /*172.DI*/
    BDSIGNAL_CODE_DI59,                   /*173.DI*/
    BDSIGNAL_CODE_DI60,                   /*174.DI*/
    BDSIGNAL_CODE_DI61,                   /*175.DI*/
    BDSIGNAL_CODE_DI62,                   /*176.DI*/
    BDSIGNAL_CODE_DI63,                   /*177.DI*/

    BDSIGNAL_CODE_NUMS                    
}BDSIGNAL_CODE_E;

/*通用长度定义*/
#define     TC_MAXLEN_SIZE8         8       
#define     TC_MAXLEN_SIZE16        16   
#define     TC_MAXLEN_SIZE24        24
#define     TC_MAXLEN_SIZE32        32

#define     TC_MAXLEN_TIME          24


// 系统监控原始数据配置
#define     TC_MAXLEN_COMPONENTID   32      //零件ID最大长度
#define     TC_MAXLEN_NCID          36      // NCID 最大长度
#define     TC_MAXLEN_TOOLID        12      //刀具ID最大长度
#define     TC_MAXLEN_PROGRAMNO     28      //程序号
#define     TC_MAXLEN_PARAMCODE     32      //变量编码
#define     TC_MAXLEN_PARAMNAME     32      //变量名
#define     TC_MAXLEN_PARAMVALUE    32      //变量值

#define     TC_MAXLEN_COMMON        64      //通用的长度
#define     TC_MAXLEN_CNC_TYPE      20      //NC类型最大长度
#define     TC_MAXLEN_CNC_VER       20      //NC版本号最大长度
#define     TC_MAXLEN_NC_ALM_MSG    300     //NC报警信息最大长度
#define     TC_MAXLEN_DEV_VER       2       //设备版本号最大长度
#define     TC_MAXLEN_DEV_SSN       32      //设备SSN号最大长度

#define     TC_MAXNUMS_AICH         16      //单条BD数据最大16个AI通道数据
#define     TC_MAXNUMS_DICH         4       //单条BD数据最大4个DI数据
#define     TC_MAXNUMS_DEVCTL       4       //设备控制最大的参数组合数量

#define     ADIODEV_MAXAICH_NUMS    32      //adio设备Ai最大通道数
#define     ADIODEV_MAXDICH_NUMS    32      //adio设备Di最大通道数
#define     NCDEV_MAXCH_NUMS        8       //nc设备最大通道数

#define     TC_MAX_PATH             260

#define     TC_INVALID_VALCHAR       0xFF
#define     TC_INVALID_VALSHORT      0xFFFF
#define     TC_INVALID_VALINT32      0xFFFFFFFF

/*数据库配置*/
#define     TC_SQL_MAXLEN_CONNECTSTR    MATC_MAX_PATHX_PATH
#define     TC_SQL_MAXLEN_USERNAME      32
#define     TC_SQL_MAXLEN_PASSWORD      32

/*系统监控配置*/
/******************系统监控配置最大个数**********************/
#define     TCMNCFG_MAXNUMS                 8
/******************ADIO设备最大个数**********************/
#define     TCMNCFG_MAXNUMS_DEVADIO         8
/******************NC设备最大个数***********************/
#define     TCMNCFG_MAXNUMS_NCDEV           4
/*******************EAM配置最大数量**********************/
#define     TCMNCFG_MAXNUMS_EAM             16
/*******************RAM配置最大数量***********************/
#define     TCMNCFG_MAXNUMS_RAM             16
/*******************DEVCTRL配置最大数量***********************/
#define     TCMNCFG_MAXNUMS_DEVCTRL         8
/*******************RMM评估规则配置最大数量***********************/
#define     TCMNCFG_MAXNUMS_RMMEVARUL       32
/*******************RMM决策规则配置最大数量***********************/
#define     TCMNCFG_MAXNUMS_RMMDECRUL       16

/*******************算法模型MMID最大长度**************************/
#define     TCAMCFG_MAXLEN_MMID             256
/*RAM的MMtype下的多个分析方法配置个数*/
#define     RAMCFG_MTHNUMS                  8

/*算法配置信息*/
#define     TC_MAXLEN_SIGNALNAME            (64)      	/*算法信号名长度*/


#define     TC_MAXLNE_USRMMID               (64)  		/* 自定义的MMID长度 */
 
#define     TC_MAXLNE_MODULE_NAME           (8)        /* 模块名最大长度 */
 

/*BD的版本号*/
typedef enum
{
    BASEDATA_VERSION_UNKNOW = 0,
    BASEDATA_VERSION_1_0,           /*BD的版本号: V1.0*/

}BASEDATA_VERN_E;
/***************************设备大类**********************************/
typedef enum
{
    DEV_TYPE_UNKOWN = 0,
    DEV_TYPE_NC,                //表示NC设备
    DEV_TYPE_ADIO,              //表示ADIO设备

    DEV_TYPE_NUMS
}DEV_TYPE_E;

/*****************************设备厂商大类*******************************/
typedef enum {
    DEV_MF_UNKOWN = 0,
    DEV_MF_NC_FANUC,            //表示NC的FANUC厂商
    DEV_MF_NC_SIEMENS,          //表示NC的西门子厂商
    DEV_MF_NC_MITSUBISHI,       //表示NC的MITSUBISHI厂商
    DEV_MF_NC_HEIDENHAIN,       //表示NC的HEIDENHAIN厂商

    DEV_MF_ADIO_UJ,             //表示ADIO的UJ厂商
    DEV_MF_ADIO_YAV,            //表示ADIO的YAV厂商

    DEV_MF_NUMS,
}DEV_MFACTORY_E;

/****************************设备厂商系列大类********************************/
typedef enum {
    DEV_MFCLS_UNKOWN = 0,
    DEV_MFCLS_NC_FANUC_1_0,         //支持FANUC的1.0系列
    DEV_MFCLS_NC_FANUC_1_1,         //支持FANUC的1.1系列
    DEV_MFCLS_NC_FANUC_1_2,         //支持FANUC的1.2系列
    DEV_MFCLS_NC_SIEMENS_1_0,       //支持SIEMENS的1.0系列
    DEV_MFCLS_NC_MITSUBISHI_1_0,    //支持MITSUBISHI的1.0系列
    DEV_MFCLS_NC_HEIDENHAIN_1_0,    //支持HEIDENHAIN的1.0系列

    DEV_MF_ADIO_UJ_USB,             //支持UJ的USB接口
    DEV_MF_ADIO_UJ_RS485,           //支持UJ的RS485接口
    DEV_MF_ADIO_YAV_USB,            //支持YAV的USB接口
    DEV_MF_ADIO_YAV_RS485,          //支持YAV的RS485接口

    DEV_MFCLS_NUMS,
}DEV_MFCLS_E;


/***************************NC设备运行状态**********************************/
typedef enum {
    DEV_NCCHECKRUN_UNKOWN = 0,
    DEV_NCCHECKRUN_CONNECTERR,      /*连接出错*/
    DEV_NCCHECKRUN_AUTOSTART,       /*自动运行开始*/
    DEV_NCCHECKRUN_AUTOSTOP,        /*自动运行停止*/

    DEV_NCCHECKRUN_NUMS,
}DEV_NCCHECKRUN_E;
/***************************AI设备运行状态**********************************/
typedef enum {
    DEV_AINUM_UNKOWN = 128,
    DEV_AINUM_CONNECTERR,      /*连接出错*/

    DEV_AINUM_NUMS,
}DEV_AINUM_E;

/***************************DI设备运行状态**********************************/
typedef enum {
    DEV_DINUM_UNKOWN = 128,
    DEV_DINUM_CONNECTERR,      /*连接出错*/

    DEV_DINUM_NUMS,
}DEV_DINUM_E;


/******************************** SWM ***************************************/
/*通信主命令类型*/
typedef enum
{
    BASECMD_MTYPE_UNKNOW = 0,           //未知
    BASECMD_MTYPE_CFG,                  //主类型-配置类
    BASECMD_MTYPE_EVT,                  //主类型-事件类pAdioCollect->m_pstDmmConfig->devSysConfig[nBdIndex].m_CommHead.stAICHID[nChCount].
    BASECMD_MTYPE_MSG,                  //主类型-消息类
    BASECMD_MTYPE_CTL,                  //主消息-控制类

    BASECMD_MTYPE_NUMS,
}BASECMD_MTYPE_E;

/*配置类子命令类型*/
typedef enum
{
    BASECMD_STYPE_CFG_UNKNOW = 0,
    BASECMD_STYPE_CFG_DEVINFO_NC,       //NC设备系统信息
    BASECMD_STYPE_CFG_DEVINFO_ADIO,     //ADIO设备系统信息
    BASECMD_STYPE_CFG_DMMINFO,          //DMM设备系统配置信息
    BASECMD_STYPE_CFG_DMMCTRL,          //DMM设备系统控制配置
    BASECMD_STYPE_CFG_EAMINFO,          //EAM分析方法配置
    BASECMD_STYPE_CFG_RAMINFO,          //RAM分析方法配置
    BASECMD_STYPE_CFG_RMMPROC,          //RMM监控过程默认配置信息
    BASECMD_STYPE_CFG_RMMPROCMMID,      //RMM监控过程MMID 生成方式
    BASECMD_STYPE_CFG_RMMEVLRULE,       //RMM监控评估规则配置信息
    BASECMD_STYPE_CFG_RMMDECIRULE,      //RMM监控决策规则配置信息

    BASECMD_STYPE_CFG_NUMS
}BASECMD_STYPE_CFG_E;

/*消息类子命令类型*/
typedef enum
{
    BASECMD_STYPE_MSG_UNKNOW = 0,
    BASECMD_STYPE_MSG_NCPROB_RESQ,          /*NC探测请求*/
    BASECMD_STYPE_MSG_NCPROB_RESP,          /*NC探测响应*/
    BASECMD_STYPE_MSG_ADIOPROB_RESQ,        /*ADIO探测请求*/
    BASECMD_STYPE_MSG_ADIOPROB_RESP,        /*ADIO探测响应*/
    BASECMD_STYPE_MSG_RMMUPDATE,            /*算法配置更新*/
    BASECMD_STYPE_MSG_DEVCTRL_RESQ,         /*设备控制请求*/
    BASECMD_STYPE_MSG_DEVCTRL_RESP,         /*设备控制响应*/
    BASECMD_STYPE_MSG_DBMINFO_RESQ,         /*DBM路径请求消息*/
    BASECMD_STYPE_MSG_DBMINFO_RESP,         /*DBM路径内容响应消息*/

    BASECMD_STYPE_MSG_NUMS
}BASECMD_STYPE_MSG_E;

/*事件类子命令类型*/
typedef enum
{
    BASECMD_STYPE_EVT_UNKNOW = 0,
    BASECMD_STYPE_EVT_PROCESSDEVICE,        /*设备过程事件*/
    BASECMD_STYPE_EVT_PROCESSANALYZE,       /*过程分析事件*/
    BASECMD_STYPE_EVT_RMM,                  /*在线监控事件*/

    BBASECMD_STYPE_EVT_NUMS
}BASECMD_STYPE_EVT_E;


/*命令动作类型*/
typedef enum
{
    BASECMD_ACTION_UNKNOW=0,
    BASECMD_ACTION_ADD,                 /*添加动作*/
    BASECMD_ACTION_DEL,                 /*删除动作*/

    BASECMD_ACTION_NUMS,
}BASECMD_ACTION_E;

/******************************** DMM/DPM ***************************************/
/*BD的同步源类型选择*/
typedef enum
{
    DEVSYNC_TYPE_UNKNOW=0,              /*未知*/
    DEVSYNC_TYPE_NC,                    /*同步源为NC类型*/
    DEVSYNC_TYPE_AI,                    /*同步源为AI类型*/
    DEVSYNC_TYPE_DI,                    /*同步源为DI类型*/

    DEVSYNC_TYPE_NUMS
}DEVSYNC_TYPE_E;

/* 设备控制来源*/
typedef enum
{
    DEVCTRL_SRC_UNKNOW = 0,             /*未知*/
    DEVCTRL_SRC_SWM,                    /*SWM*/
    DEVCTRL_SRC_DCM,                    /*DCM*/

    DEVCTRL_SRC_NUMS
}DEVCTRL_SRC_E;

/* 设备控制结果*/
typedef enum
{
    DEVCTRL_RET_UNKNOW = 0,             /*未知*/
    DEVCTRL_RET_OK,                     /*命令执行成功*/
    DEVCTRL_RET_ERR,                    /*命令执行失败*/

    DEVCTRL_RET_NUMS
}DEVCTRL_RET_E;


/****************************** EAM/RAM/RMM ************************************/
/**** DMM/SWM/RMM ****/
typedef enum
{
    DEVCTRL_TYPE_UNKNOW = 0,            /*未知*/
    DEVCTRL_TYPE_ALM,                   /*报警*/
    DEVCTRL_TYPE_STOP,                  /*停机*/
    DEVCTRL_TYPE_RESET,                 /*复位*/
    DEVCTRL_TYPE_FVHOLD,                /*进给保持*/
    DEVCTRL_TYPE_FVOVEDIT,              /*进给倍率*/
    DEVCTRL_TYPE_SPOVEDIT,              /*转速倍率*/

    DEVCTRL_TYPE_NUMS
}DEVCTRL_TYPE_E;

/**** EAM ****/
/*BASECMD_STYPE_EVT_E定义作为主事件类型分类*/
/*设备状态事件的子类型定义*/
typedef enum
{
    EVT_DEVICEPROCESS_UNKNOW = 0,       /*未知*/
    EVT_DEVICEPROCESS_TCPOWERON,        /*终端开机*/
    EVT_DEVICEPROCESS_TCPOWEROFF,       /*终端关机*/
    EVT_DEVICEPROCESS_NCDISCONNECT,     /*NC断开*/
    EVT_DEVICEPROCESS_AIDISCONNECT,     /*AI断开*/
    EVT_DEVICEPROCESS_AICONNECT,        /*AI连接*/
    EVT_DEVICEPROCESS_DIDISCONNECT,     /*DI断开*/
    EVT_DEVICEPROCESS_DICONNECT,        /*DI连接*/
    EVT_DEVICEPROCESS_ALARMTYPE,        /*报警*/
    EVT_DEVICEPROCESS_EMERGENCY,        /*紧停*/
    EVT_DEVICEPROCESS_RUNSTART,         /*开始加工*/
    EVT_DEVICEPROCESS_RUNSTOP,          /*结束加工*/

    EVT_DEVICEPROCESS_NUM
}EVT_DEVICEPROCESS_E;

/*过程分析事件的子类型定义*/
typedef enum 
{
    EVT_STATUSPROCESS_NORMAL = 0,               /*正常*/
    EVT_STATUSPROCESS_THRESHOLD_LOWER,          /* 低于阈值*/
    EVT_STATUSPROCESS_THRESHOLD_UPPER,          /* 超过阈值*/
    EVT_STATUSPROCESS_CHANGED,                  /* 变化*/

    EVT_STATUSPROCESS_NUMS
}EVT_STATUSPROC_THRESHOLD_E;

typedef enum
{
    EVT_PROCESSANALYZE_UNKNOW = 0,
    EVT_PROCESSANALYZE_SEGM,            /* 分段类*/
    EVT_PROCESSANALYZE_MARK,            /* 标记变化点类*/

}EVT_PROCESSANALYZE_E;

typedef enum 
{
    EVT_SEGM_METHOD_UNKNOW = 0,
    EVT_SEGM_METHOD_THRESHOLD,      /*阈值方法*/

    EVT_SEGM_METHOD_NUMS
}EVT_SEGM_METHOD_E;

typedef enum 
{
    EVT_MARK_METHOD_UNKNOW = 0,
    EVT_MARK_METHOD_CHANGE,         /*变化方法*/

    EVT_MARK_METHOD_NUMS

}EVT_MARK_METHOD_E;


// RMM 监控事件类型
typedef enum 
{  
	EVT_RMM_None                      = 0,    
	// 监控过程相关事件
	EVT_RMM_ProcNormalEnd,            		// 监控过程正常结束事件
	EVT_RMM_DataInRangeofLimit,       		// 数据在上下边界内
    EVT_RMM_AboveUpperLimit,          		// 数据超上限事件
    EVT_RMM_BelowLowerLimit,          		// 数据低于下限事件
    EVT_RMM_AboveUpperLimitAlarm,     		// 数据超出上限报警事件
	EVT_RMM_BelowLowerLimitAlarm,           // 数据低于下限报警事件
	
	// 决策相关事件
	EVT_RMM_DecStart                  = 20,           
    EVT_RMM_DecHalt,                      	// 决策停机事件
    EVT_RMM_DecAlarm,                     	// 决策告警事件    
}EVT_RMM_E;




/**** RMM ****/
// 数据预处理方法    
#define PrePROC_meanValFilter       (0x00000001)    // 算术平均滤波
#define PrePROC_movingAveFilter     (0x00000002)    // 滑动平均滤波
#define PrePROC_deExtremumAveFilter (0x00000004)    // 去极值平均滤波	
#define PrePROC_medianFilter        (0x00000008)    // 中值滤波
#define PrePROC_derProcess          (0x00000010)    // 导数处理

// 特征类型定义
#define FEATURE_TYPE_MEAN       (0x00000001)        // 均值特征
#define FEATURE_TYPE_MAX_VAL    (0x00000002)        // 最大值特征
#define FEATURE_TYPE_AREA       (0x00000004)        // 面积值特征

/** MMID生成方式类型
    0: 基础ID + MM类型+ 自定义MMID
	1: 基础ID + MM类型+ PN + TN
	2: 基础ID + MM类型+ PN + TN + Tindex + 过程index 
	    + 目标S+目标F + 实际主轴转速倍率 + 实际进给倍率
**/
typedef enum 
{
	MMID_FORM_TYPE_usrDef = 0,   
	MMID_FORM_TYPE_1, 
	MMID_FORM_TYPE_2
}RMM_MMID_FORM_TYPE_E;

// 监控状态 
typedef enum 
{
	MONIT_STATE_opened = 0,    // 开
	MONIT_STATE_closed,        // 关
	MONIT_STATE_learning,      // 学习中
	MONIT_STATE_observer       // 观察模式 
}RMM_MONIT_STATE_E;

// 诊断结论定义
typedef enum 
{
    DIAG_RLT_none = 0,         // 无
    DIAG_RLT_normal,	       // 诊断结论     正常
    DIAG_RLT_fault,            // 诊断结论 故障    
}RMM_DIAG_RLT_E; 


// 决策执行使能开关
typedef enum 
{   
    DECISION_exeClosed  = 0,   // 决策执行关闭
    DECISION_exeOpened  = 1    // 决策执行开启              
}RMM_DECISION_ExeENABLE_E;


// 决策类型定义
typedef enum 
{   
    DECISION_TYPE_unknow = 0, 
    DECISION_TYPE_ignore,      // 忽略
    DECISION_TYPE_warn,        // 报警
    DECISION_TYPE_stop         // 停止
}RMM_DECISION_TYPE_E;

// 状态识别对比使能开关
typedef enum 
{   
    STATE_RECOG_Disable = 0,   // 使能开关关闭状态
    STATE_RECOG_Enable  = 1    // 使能开关打开状态      
}RMM_STATE_RECOG_ENABLE_E;

// 状态识别告警使能开关
typedef enum 
{   
    STATE_RECOG_ALARM_Disable = 0,   // 告警使能开关: 关闭状态
    STATE_RECOG_ALARM_Enable  = 1    // 告警使能开关: 打开状态      
}RMM_STATE_RECOG_ALARM_ENABLE_E;

// 模型学习类型
typedef enum 
{
    MODLE_LEARN_TYPE_FIXED = 0   	 // 固定学习方式
    // Add other type below
    
}RMM_MODLE_LEARN_TYPE_E;

// 重新学习标志或离线重新学习标志
typedef enum 
{
    MODLE_ReLEARN_NO = 0,   		// 不用重新学习
    MODLE_ReLEARN_YES          	 	// 需要重新学习
}RMM_MODLE_ReLEARN_FLAG_E;

// 监控过程配置生效FLAG
typedef enum 
{
    MM_CFG_NO_EFFECT = 0,   		// 配置不生效
    MM_CFG_EFFECT = 1          	 	// 配置生效
}RMM_CFG_FLAG_E;


// DBM路径相关配置
#define     DATABASE_PATHNAME               "DataBase"

#define     ORIGDB_FILEPATHNAME             "OrigData"

#define     ALGODB_FILEPATHNAME             "AlgmData"

#define     EVENTDB_FILEPATHNAME            "EventData"

/****************************************************************************/








