/******************************************************************************

                  ��Ȩ���� (C), 2018-2028, �����ѻ��������޹�˾

 ******************************************************************************
  �� �� ��   : TerminalComm.h
  �� �� ��   : ����
  ��    ��   : ����
  ��������   : 2018��10��23��
  ����޸�   :
  ��������   : �ն˵Ķ����ͨ�õ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��10��23��
    ��    ��   : ����
    �޸�����   : �����ļ�
  2.��    ��: 2018��10��26��
    ��    ��: yifangKong
    �޸�����   : (1). ����RMMģ����ض���
              (2). ���RMMģ�����¼�����

******************************************************************************/
typedef enum
{
	MODULE_TYPE_NULL = 0,
	MODULE_TYPE_RMM        // ���߼��ģ��
	// Pls. Add other module type below
	
}MODULE_TYPE_E;



/*BD����(�ź�״̬��)�붨��*/
typedef enum
{
    BDSIGNAL_CODE_UNKNOW = 0,             /*δ֪*/
    BDSIGNAL_CODE_DEVALM,                 /*1.  �豸����*/
    BDSIGNAL_CODE_DEVRUN,                 /*2.  �豸����״̬*/
    BDSIGNAL_CODE_DEVAUT,                 /*3.  �豸�Զ�ģʽ*/
    BDSIGNAL_CODE_DEVEMG,                 /*4.  �豸�Ƿ�ͣ*/
    BDSIGNAL_CODE_ABSPOSX,                /*5.  x���������*/
    BDSIGNAL_CODE_ABSPOSY,                /*6.  y���������*/
    BDSIGNAL_CODE_ABSPOSZ,                /*7.  z���������*/
    BDSIGNAL_CODE_RESTPOSX,               /*8.  x���е����*/
    BDSIGNAL_CODE_RESTPOSY,               /*9.  y���е����*/
    BDSIGNAL_CODE_RESTPOSZ,               /*10. z���е����*/
    BDSIGNAL_CODE_BATCHNUMS,              /*11. ������������*/
    BDSIGNAL_CODE_MPROGNAME,              /*12. ��������*/
    BDSIGNAL_CODE_CPROGNAME,              /*13. ��ǰ���г����*/
    BDSIGNAL_CODE_SPOV,                   /*14. ���ᱶ��*/
    BDSIGNAL_CODE_FVOV,                   /*15. ��������*/
    BDSIGNAL_CODE_ACTSP,                  /*16. ����ʵ��ת��*/
    BDSIGNAL_CODE_ACTFV,                  /*17. ����ʵ��ת��*/
    BDSIGNAL_CODE_SETSP,                  /*18. �����趨�ٶ�*/
    BDSIGNAL_CODE_SETFV,                  /*19. �����趨�ٶ�*/
    BDSIGNAL_CODE_TNUMBER,                /*20. ��ǰ���ߺ�*/
    BDSIGNAL_CODE_TOFFSET,                /*21. ��ǰ������*/
    BDSIGNAL_CODE_SPLOAD,                 /*22. ���Ḻ��*/
    BDSIGNAL_CODE_SPLOAD2,                /*23. ����2����*/
    BDSIGNAL_CODE_SERVOLOADX,             /*24. �ŷ�x�Ḻ��*/
    BDSIGNAL_CODE_SERVOLOADY,             /*25. �ŷ�y�Ḻ��*/
    BDSIGNAL_CODE_SERVOLOADZ,             /*26. �ŷ�z�Ḻ��*/
    BDSIGNAL_CODE_SERVOLOADC,             /*27. �ŷ�C�Ḻ��*/
    BDSIGNAL_CODE_SERVOLOADB,             /*28. �ŷ�B�Ḻ��*/
    BDSIGNAL_CODE_GSTATE,                 /*29. G����״̬*/
    BDSIGNAL_CODE_CYCTIME,                /*30. �豸ѭ��ʱ��*/
    BDSIGNAL_CODE_SERVOTEMP,              /*31. �ŷ��¶�*/
    BDSIGNAL_CODE_SPTEMP,                 /*32. �����¶�*/
    BDSIGNAL_CODE_CHECKRUN,               /*33. �ӹ��¼�״̬*/
    BDSIGNAL_CODE_FILTERV0,               /*34. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV1,               /*35. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV2,               /*36. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV3,               /*37. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV4,               /*38. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV5,               /*39. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV6,               /*40. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV7,               /*41. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV8,               /*42. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV9,               /*43. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV10,              /*44. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV11,              /*45. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV12,              /*46. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV13,              /*47. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV14,              /*48. Ԥ����Ԥ��*/
    BDSIGNAL_CODE_FILTERV15,              /*49. Ԥ����Ԥ��*/
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

/*ͨ�ó��ȶ���*/
#define     TC_MAXLEN_SIZE8         8       
#define     TC_MAXLEN_SIZE16        16   
#define     TC_MAXLEN_SIZE24        24
#define     TC_MAXLEN_SIZE32        32

#define     TC_MAXLEN_TIME          24


// ϵͳ���ԭʼ��������
#define     TC_MAXLEN_COMPONENTID   32      //���ID��󳤶�
#define     TC_MAXLEN_NCID          36      // NCID ��󳤶�
#define     TC_MAXLEN_TOOLID        12      //����ID��󳤶�
#define     TC_MAXLEN_PROGRAMNO     28      //�����
#define     TC_MAXLEN_PARAMCODE     32      //��������
#define     TC_MAXLEN_PARAMNAME     32      //������
#define     TC_MAXLEN_PARAMVALUE    32      //����ֵ

#define     TC_MAXLEN_COMMON        64      //ͨ�õĳ���
#define     TC_MAXLEN_CNC_TYPE      20      //NC������󳤶�
#define     TC_MAXLEN_CNC_VER       20      //NC�汾����󳤶�
#define     TC_MAXLEN_NC_ALM_MSG    300     //NC������Ϣ��󳤶�
#define     TC_MAXLEN_DEV_VER       2       //�豸�汾����󳤶�
#define     TC_MAXLEN_DEV_SSN       32      //�豸SSN����󳤶�

#define     TC_MAXNUMS_AICH         16      //����BD�������16��AIͨ������
#define     TC_MAXNUMS_DICH         4       //����BD�������4��DI����
#define     TC_MAXNUMS_DEVCTL       4       //�豸�������Ĳ����������

#define     ADIODEV_MAXAICH_NUMS    32      //adio�豸Ai���ͨ����
#define     ADIODEV_MAXDICH_NUMS    32      //adio�豸Di���ͨ����
#define     NCDEV_MAXCH_NUMS        8       //nc�豸���ͨ����

#define     TC_MAX_PATH             260

#define     TC_INVALID_VALCHAR       0xFF
#define     TC_INVALID_VALSHORT      0xFFFF
#define     TC_INVALID_VALINT32      0xFFFFFFFF

/*���ݿ�����*/
#define     TC_SQL_MAXLEN_CONNECTSTR    MATC_MAX_PATHX_PATH
#define     TC_SQL_MAXLEN_USERNAME      32
#define     TC_SQL_MAXLEN_PASSWORD      32

/*ϵͳ�������*/
/******************ϵͳ�������������**********************/
#define     TCMNCFG_MAXNUMS                 8
/******************ADIO�豸������**********************/
#define     TCMNCFG_MAXNUMS_DEVADIO         8
/******************NC�豸������***********************/
#define     TCMNCFG_MAXNUMS_NCDEV           4
/*******************EAM�����������**********************/
#define     TCMNCFG_MAXNUMS_EAM             16
/*******************RAM�����������***********************/
#define     TCMNCFG_MAXNUMS_RAM             16
/*******************DEVCTRL�����������***********************/
#define     TCMNCFG_MAXNUMS_DEVCTRL         8
/*******************RMM�������������������***********************/
#define     TCMNCFG_MAXNUMS_RMMEVARUL       32
/*******************RMM���߹��������������***********************/
#define     TCMNCFG_MAXNUMS_RMMDECRUL       16

/*******************�㷨ģ��MMID��󳤶�**************************/
#define     TCAMCFG_MAXLEN_MMID             256
/*RAM��MMtype�µĶ�������������ø���*/
#define     RAMCFG_MTHNUMS                  8

/*�㷨������Ϣ*/
#define     TC_MAXLEN_SIGNALNAME            (64)      	/*�㷨�ź�������*/


#define     TC_MAXLNE_USRMMID               (64)  		/* �Զ����MMID���� */
 
#define     TC_MAXLNE_MODULE_NAME           (8)        /* ģ������󳤶� */
 

/*BD�İ汾��*/
typedef enum
{
    BASEDATA_VERSION_UNKNOW = 0,
    BASEDATA_VERSION_1_0,           /*BD�İ汾��: V1.0*/

}BASEDATA_VERN_E;
/***************************�豸����**********************************/
typedef enum
{
    DEV_TYPE_UNKOWN = 0,
    DEV_TYPE_NC,                //��ʾNC�豸
    DEV_TYPE_ADIO,              //��ʾADIO�豸

    DEV_TYPE_NUMS
}DEV_TYPE_E;

/*****************************�豸���̴���*******************************/
typedef enum {
    DEV_MF_UNKOWN = 0,
    DEV_MF_NC_FANUC,            //��ʾNC��FANUC����
    DEV_MF_NC_SIEMENS,          //��ʾNC�������ӳ���
    DEV_MF_NC_MITSUBISHI,       //��ʾNC��MITSUBISHI����
    DEV_MF_NC_HEIDENHAIN,       //��ʾNC��HEIDENHAIN����

    DEV_MF_ADIO_UJ,             //��ʾADIO��UJ����
    DEV_MF_ADIO_YAV,            //��ʾADIO��YAV����

    DEV_MF_NUMS,
}DEV_MFACTORY_E;

/****************************�豸����ϵ�д���********************************/
typedef enum {
    DEV_MFCLS_UNKOWN = 0,
    DEV_MFCLS_NC_FANUC_1_0,         //֧��FANUC��1.0ϵ��
    DEV_MFCLS_NC_FANUC_1_1,         //֧��FANUC��1.1ϵ��
    DEV_MFCLS_NC_FANUC_1_2,         //֧��FANUC��1.2ϵ��
    DEV_MFCLS_NC_SIEMENS_1_0,       //֧��SIEMENS��1.0ϵ��
    DEV_MFCLS_NC_MITSUBISHI_1_0,    //֧��MITSUBISHI��1.0ϵ��
    DEV_MFCLS_NC_HEIDENHAIN_1_0,    //֧��HEIDENHAIN��1.0ϵ��

    DEV_MF_ADIO_UJ_USB,             //֧��UJ��USB�ӿ�
    DEV_MF_ADIO_UJ_RS485,           //֧��UJ��RS485�ӿ�
    DEV_MF_ADIO_YAV_USB,            //֧��YAV��USB�ӿ�
    DEV_MF_ADIO_YAV_RS485,          //֧��YAV��RS485�ӿ�

    DEV_MFCLS_NUMS,
}DEV_MFCLS_E;


/***************************NC�豸����״̬**********************************/
typedef enum {
    DEV_NCCHECKRUN_UNKOWN = 0,
    DEV_NCCHECKRUN_CONNECTERR,      /*���ӳ���*/
    DEV_NCCHECKRUN_AUTOSTART,       /*�Զ����п�ʼ*/
    DEV_NCCHECKRUN_AUTOSTOP,        /*�Զ�����ֹͣ*/

    DEV_NCCHECKRUN_NUMS,
}DEV_NCCHECKRUN_E;
/***************************AI�豸����״̬**********************************/
typedef enum {
    DEV_AINUM_UNKOWN = 128,
    DEV_AINUM_CONNECTERR,      /*���ӳ���*/

    DEV_AINUM_NUMS,
}DEV_AINUM_E;

/***************************DI�豸����״̬**********************************/
typedef enum {
    DEV_DINUM_UNKOWN = 128,
    DEV_DINUM_CONNECTERR,      /*���ӳ���*/

    DEV_DINUM_NUMS,
}DEV_DINUM_E;


/******************************** SWM ***************************************/
/*ͨ������������*/
typedef enum
{
    BASECMD_MTYPE_UNKNOW = 0,           //δ֪
    BASECMD_MTYPE_CFG,                  //������-������
    BASECMD_MTYPE_EVT,                  //������-�¼���pAdioCollect->m_pstDmmConfig->devSysConfig[nBdIndex].m_CommHead.stAICHID[nChCount].
    BASECMD_MTYPE_MSG,                  //������-��Ϣ��
    BASECMD_MTYPE_CTL,                  //����Ϣ-������

    BASECMD_MTYPE_NUMS,
}BASECMD_MTYPE_E;

/*����������������*/
typedef enum
{
    BASECMD_STYPE_CFG_UNKNOW = 0,
    BASECMD_STYPE_CFG_DEVINFO_NC,       //NC�豸ϵͳ��Ϣ
    BASECMD_STYPE_CFG_DEVINFO_ADIO,     //ADIO�豸ϵͳ��Ϣ
    BASECMD_STYPE_CFG_DMMINFO,          //DMM�豸ϵͳ������Ϣ
    BASECMD_STYPE_CFG_DMMCTRL,          //DMM�豸ϵͳ��������
    BASECMD_STYPE_CFG_EAMINFO,          //EAM������������
    BASECMD_STYPE_CFG_RAMINFO,          //RAM������������
    BASECMD_STYPE_CFG_RMMPROC,          //RMM��ع���Ĭ��������Ϣ
    BASECMD_STYPE_CFG_RMMPROCMMID,      //RMM��ع���MMID ���ɷ�ʽ
    BASECMD_STYPE_CFG_RMMEVLRULE,       //RMM�����������������Ϣ
    BASECMD_STYPE_CFG_RMMDECIRULE,      //RMM��ؾ��߹���������Ϣ

    BASECMD_STYPE_CFG_NUMS
}BASECMD_STYPE_CFG_E;

/*��Ϣ������������*/
typedef enum
{
    BASECMD_STYPE_MSG_UNKNOW = 0,
    BASECMD_STYPE_MSG_NCPROB_RESQ,          /*NC̽������*/
    BASECMD_STYPE_MSG_NCPROB_RESP,          /*NC̽����Ӧ*/
    BASECMD_STYPE_MSG_ADIOPROB_RESQ,        /*ADIO̽������*/
    BASECMD_STYPE_MSG_ADIOPROB_RESP,        /*ADIO̽����Ӧ*/
    BASECMD_STYPE_MSG_RMMUPDATE,            /*�㷨���ø���*/
    BASECMD_STYPE_MSG_DEVCTRL_RESQ,         /*�豸��������*/
    BASECMD_STYPE_MSG_DEVCTRL_RESP,         /*�豸������Ӧ*/
    BASECMD_STYPE_MSG_DBMINFO_RESQ,         /*DBM·��������Ϣ*/
    BASECMD_STYPE_MSG_DBMINFO_RESP,         /*DBM·��������Ӧ��Ϣ*/

    BASECMD_STYPE_MSG_NUMS
}BASECMD_STYPE_MSG_E;

/*�¼�������������*/
typedef enum
{
    BASECMD_STYPE_EVT_UNKNOW = 0,
    BASECMD_STYPE_EVT_PROCESSDEVICE,        /*�豸�����¼�*/
    BASECMD_STYPE_EVT_PROCESSANALYZE,       /*���̷����¼�*/
    BASECMD_STYPE_EVT_RMM,                  /*���߼���¼�*/

    BBASECMD_STYPE_EVT_NUMS
}BASECMD_STYPE_EVT_E;


/*���������*/
typedef enum
{
    BASECMD_ACTION_UNKNOW=0,
    BASECMD_ACTION_ADD,                 /*��Ӷ���*/
    BASECMD_ACTION_DEL,                 /*ɾ������*/

    BASECMD_ACTION_NUMS,
}BASECMD_ACTION_E;

/******************************** DMM/DPM ***************************************/
/*BD��ͬ��Դ����ѡ��*/
typedef enum
{
    DEVSYNC_TYPE_UNKNOW=0,              /*δ֪*/
    DEVSYNC_TYPE_NC,                    /*ͬ��ԴΪNC����*/
    DEVSYNC_TYPE_AI,                    /*ͬ��ԴΪAI����*/
    DEVSYNC_TYPE_DI,                    /*ͬ��ԴΪDI����*/

    DEVSYNC_TYPE_NUMS
}DEVSYNC_TYPE_E;

/* �豸������Դ*/
typedef enum
{
    DEVCTRL_SRC_UNKNOW = 0,             /*δ֪*/
    DEVCTRL_SRC_SWM,                    /*SWM*/
    DEVCTRL_SRC_DCM,                    /*DCM*/

    DEVCTRL_SRC_NUMS
}DEVCTRL_SRC_E;

/* �豸���ƽ��*/
typedef enum
{
    DEVCTRL_RET_UNKNOW = 0,             /*δ֪*/
    DEVCTRL_RET_OK,                     /*����ִ�гɹ�*/
    DEVCTRL_RET_ERR,                    /*����ִ��ʧ��*/

    DEVCTRL_RET_NUMS
}DEVCTRL_RET_E;


/****************************** EAM/RAM/RMM ************************************/
/**** DMM/SWM/RMM ****/
typedef enum
{
    DEVCTRL_TYPE_UNKNOW = 0,            /*δ֪*/
    DEVCTRL_TYPE_ALM,                   /*����*/
    DEVCTRL_TYPE_STOP,                  /*ͣ��*/
    DEVCTRL_TYPE_RESET,                 /*��λ*/
    DEVCTRL_TYPE_FVHOLD,                /*��������*/
    DEVCTRL_TYPE_FVOVEDIT,              /*��������*/
    DEVCTRL_TYPE_SPOVEDIT,              /*ת�ٱ���*/

    DEVCTRL_TYPE_NUMS
}DEVCTRL_TYPE_E;

/**** EAM ****/
/*BASECMD_STYPE_EVT_E������Ϊ���¼����ͷ���*/
/*�豸״̬�¼��������Ͷ���*/
typedef enum
{
    EVT_DEVICEPROCESS_UNKNOW = 0,       /*δ֪*/
    EVT_DEVICEPROCESS_TCPOWERON,        /*�ն˿���*/
    EVT_DEVICEPROCESS_TCPOWEROFF,       /*�ն˹ػ�*/
    EVT_DEVICEPROCESS_NCDISCONNECT,     /*NC�Ͽ�*/
    EVT_DEVICEPROCESS_AIDISCONNECT,     /*AI�Ͽ�*/
    EVT_DEVICEPROCESS_AICONNECT,        /*AI����*/
    EVT_DEVICEPROCESS_DIDISCONNECT,     /*DI�Ͽ�*/
    EVT_DEVICEPROCESS_DICONNECT,        /*DI����*/
    EVT_DEVICEPROCESS_ALARMTYPE,        /*����*/
    EVT_DEVICEPROCESS_EMERGENCY,        /*��ͣ*/
    EVT_DEVICEPROCESS_RUNSTART,         /*��ʼ�ӹ�*/
    EVT_DEVICEPROCESS_RUNSTOP,          /*�����ӹ�*/

    EVT_DEVICEPROCESS_NUM
}EVT_DEVICEPROCESS_E;

/*���̷����¼��������Ͷ���*/
typedef enum 
{
    EVT_STATUSPROCESS_NORMAL = 0,               /*����*/
    EVT_STATUSPROCESS_THRESHOLD_LOWER,          /* ������ֵ*/
    EVT_STATUSPROCESS_THRESHOLD_UPPER,          /* ������ֵ*/
    EVT_STATUSPROCESS_CHANGED,                  /* �仯*/

    EVT_STATUSPROCESS_NUMS
}EVT_STATUSPROC_THRESHOLD_E;

typedef enum
{
    EVT_PROCESSANALYZE_UNKNOW = 0,
    EVT_PROCESSANALYZE_SEGM,            /* �ֶ���*/
    EVT_PROCESSANALYZE_MARK,            /* ��Ǳ仯����*/

}EVT_PROCESSANALYZE_E;

typedef enum 
{
    EVT_SEGM_METHOD_UNKNOW = 0,
    EVT_SEGM_METHOD_THRESHOLD,      /*��ֵ����*/

    EVT_SEGM_METHOD_NUMS
}EVT_SEGM_METHOD_E;

typedef enum 
{
    EVT_MARK_METHOD_UNKNOW = 0,
    EVT_MARK_METHOD_CHANGE,         /*�仯����*/

    EVT_MARK_METHOD_NUMS

}EVT_MARK_METHOD_E;


// RMM ����¼�����
typedef enum 
{  
	EVT_RMM_None                      = 0,    
	// ��ع�������¼�
	EVT_RMM_ProcNormalEnd,            		// ��ع������������¼�
	EVT_RMM_DataInRangeofLimit,       		// ���������±߽���
    EVT_RMM_AboveUpperLimit,          		// ���ݳ������¼�
    EVT_RMM_BelowLowerLimit,          		// ���ݵ��������¼�
    EVT_RMM_AboveUpperLimitAlarm,     		// ���ݳ������ޱ����¼�
	EVT_RMM_BelowLowerLimitAlarm,           // ���ݵ������ޱ����¼�
	
	// ��������¼�
	EVT_RMM_DecStart                  = 20,           
    EVT_RMM_DecHalt,                      	// ����ͣ���¼�
    EVT_RMM_DecAlarm,                     	// ���߸澯�¼�    
}EVT_RMM_E;




/**** RMM ****/
// ����Ԥ������    
#define PrePROC_meanValFilter       (0x00000001)    // ����ƽ���˲�
#define PrePROC_movingAveFilter     (0x00000002)    // ����ƽ���˲�
#define PrePROC_deExtremumAveFilter (0x00000004)    // ȥ��ֵƽ���˲�	
#define PrePROC_medianFilter        (0x00000008)    // ��ֵ�˲�
#define PrePROC_derProcess          (0x00000010)    // ��������

// �������Ͷ���
#define FEATURE_TYPE_MEAN       (0x00000001)        // ��ֵ����
#define FEATURE_TYPE_MAX_VAL    (0x00000002)        // ���ֵ����
#define FEATURE_TYPE_AREA       (0x00000004)        // ���ֵ����

/** MMID���ɷ�ʽ����
    0: ����ID + MM����+ �Զ���MMID
	1: ����ID + MM����+ PN + TN
	2: ����ID + MM����+ PN + TN + Tindex + ����index 
	    + Ŀ��S+Ŀ��F + ʵ������ת�ٱ��� + ʵ�ʽ�������
**/
typedef enum 
{
	MMID_FORM_TYPE_usrDef = 0,   
	MMID_FORM_TYPE_1, 
	MMID_FORM_TYPE_2
}RMM_MMID_FORM_TYPE_E;

// ���״̬ 
typedef enum 
{
	MONIT_STATE_opened = 0,    // ��
	MONIT_STATE_closed,        // ��
	MONIT_STATE_learning,      // ѧϰ��
	MONIT_STATE_observer       // �۲�ģʽ 
}RMM_MONIT_STATE_E;

// ��Ͻ��۶���
typedef enum 
{
    DIAG_RLT_none = 0,         // ��
    DIAG_RLT_normal,	       // ��Ͻ���     ����
    DIAG_RLT_fault,            // ��Ͻ��� ����    
}RMM_DIAG_RLT_E; 


// ����ִ��ʹ�ܿ���
typedef enum 
{   
    DECISION_exeClosed  = 0,   // ����ִ�йر�
    DECISION_exeOpened  = 1    // ����ִ�п���              
}RMM_DECISION_ExeENABLE_E;


// �������Ͷ���
typedef enum 
{   
    DECISION_TYPE_unknow = 0, 
    DECISION_TYPE_ignore,      // ����
    DECISION_TYPE_warn,        // ����
    DECISION_TYPE_stop         // ֹͣ
}RMM_DECISION_TYPE_E;

// ״̬ʶ��Ա�ʹ�ܿ���
typedef enum 
{   
    STATE_RECOG_Disable = 0,   // ʹ�ܿ��عر�״̬
    STATE_RECOG_Enable  = 1    // ʹ�ܿ��ش�״̬      
}RMM_STATE_RECOG_ENABLE_E;

// ״̬ʶ��澯ʹ�ܿ���
typedef enum 
{   
    STATE_RECOG_ALARM_Disable = 0,   // �澯ʹ�ܿ���: �ر�״̬
    STATE_RECOG_ALARM_Enable  = 1    // �澯ʹ�ܿ���: ��״̬      
}RMM_STATE_RECOG_ALARM_ENABLE_E;

// ģ��ѧϰ����
typedef enum 
{
    MODLE_LEARN_TYPE_FIXED = 0   	 // �̶�ѧϰ��ʽ
    // Add other type below
    
}RMM_MODLE_LEARN_TYPE_E;

// ����ѧϰ��־����������ѧϰ��־
typedef enum 
{
    MODLE_ReLEARN_NO = 0,   		// ��������ѧϰ
    MODLE_ReLEARN_YES          	 	// ��Ҫ����ѧϰ
}RMM_MODLE_ReLEARN_FLAG_E;

// ��ع���������ЧFLAG
typedef enum 
{
    MM_CFG_NO_EFFECT = 0,   		// ���ò���Ч
    MM_CFG_EFFECT = 1          	 	// ������Ч
}RMM_CFG_FLAG_E;


// DBM·���������
#define     DATABASE_PATHNAME               "DataBase"

#define     ORIGDB_FILEPATHNAME             "OrigData"

#define     ALGODB_FILEPATHNAME             "AlgmData"

#define     EVENTDB_FILEPATHNAME            "EventData"

/****************************************************************************/








