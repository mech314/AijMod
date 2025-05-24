
//stock ROM image info
#define ECU_IDENTIFIER 4E12584107
#define ECU_CALID_BASE A8DK 
#define ECU_CALID_REV 100I
#define ECU_CALIBRATION_ID CONCAT(ECU_CALID_BASE, ECU_CALID_REV)
#define ECU_IDENTIFIER_CHARS (10)
#define ECU_CALIBRATION_CHARS (8)
#define AUTO_TRANS 0
#define SD_DMAP		0
//#define TARGETBOOST_THROTTLEPLATE 1

//mod info
#define MOD_VERSION CAN1
#define MOD_YEAR 24
#define MOD_MONTH 02
#define MOD_DAY 21

// HACK CONFIGURATION
#define MEMORY_HACKS 1
#define VIN_HACKS 0
#define VIN_TEST_LOG 0
#define SWITCH_HACKS 1
#define SD_HACKS 1
#define REVLIM_HACKS 1
#define LC_ADJ_HACKS 1
#define PROG_MODE 1
#define SPARK_HACKS 0
#define CEL_HACKS 1
#define BOOST_HACKS 1
#define TIMING_HACKS 1
#define POLF_HACKS 1
#define PGWG_HACKS 1
#define INJECTOR_HACKS 1
#define REQTORQUE_HACKS 0
#define E85_HACKS 1
#define AVCS_HACKS 0
#define CAN_HACKS 1
#define RAM_PERSIST 0
#define DYN_RAMTUNING 0
#define RAM_HOLE_SCANNER 0

#define EXPECTED_MAF_SENSOR 3.301016f
#define EXPECTED_MAF_SD 3.73053f
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000) 
#define dEcuId (0x000D0064) 
#define dRomHoleStart (0x000E1400) 
#define pRamHoleStart (0xFFFFB4EC) 
#define pRamHoleEnd (0xFFFFBF82)    
#define sPull2DFloat (0x000020AC) 
#define sPull3DFloat (0x00002160) 

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0E) 
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C10) 
#define pRearO2Voltage ((float*)0xFFFF5CC4) 
#define sShortToFloat (0x25A4) 
#define hPull2DTipInEnrich (0x34524) 
#define tTipInEnrich (0x9E6BC) 
#define tTipInEnrich2 (0x9E6BC) 
#define hPull2DCrankingFuel (0x2C164) 
#define tCrankingFuelA (0x0009E16C) 
#define tCrankingFuelB (0x0009E180) 
#define tCrankingFuelC (0x0009E194) 
#define tCrankingFuelD (0x0009E1A8) 
#define tCrankingFuelE (0x0009E1BC) 
#define tCrankingFuelF (0x0009E1D0) 
#define hPull3DStartupEnrich1 (0x2CDA4) 
#define tStartupEnrich1Cruise (0x9E84C) 
#define tStartupEnrich1NonCruise (0x9E830)  
#define hPull2DStartupEnrich2 (0x2CC78) 
#define tStartupEnrich2_1A (0x0009E240) 
#define tStartupEnrich2_1B (0x0009E268) 
#define tStartupEnrich2_2A (0x0009E254) 
#define tStartupEnrich2_2B (0x0009E27C) 
#define hPull2DStartupEnrich3 (0x2CA9C) 
#define tStartupEnrich3_1A (0x0009E1F0) 
#define tStartupEnrich3_1B (0x0009E204) 
#define tStartupEnrich3_2A (0x0009E218) 
#define tStartupEnrich3_2B (0x0009E22C) 
#define tFrontO2Scaling (0x0009FAF0)    
#define tIntakeTempCompensation (0x0009ECB0)    
#define hPull2DIntakeTempCompensation (0x39754) 

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000154EC)  
#define sRevLimStart (0x00035084)   
#define sRevLimEnd (0x000350BA) 
#define pFlagsRevLim ((unsigned char*)0xFFFF75BC)   
#define RevLimBitMask (0x80)    

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008498)   
#define sMafCalc (0x0000843C)   

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8608)   
#define hInjectorScaling (0x0002C878)   

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00090310)    
#define hCelSignal (0x00090428) 
#define pCelSignalOem ((unsigned char*)0xFFFF9722)  

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00017E80)   
#define hTableTargetBoost (0x00017E94)  
#define tTargetBoost (0x0009CDD4)   
#define hTableTargetBoostAlt (0x00017E88)   
#define tTargetBoostAlt (0x0009CDB8)    

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00018320)  
#define hWgdc (0x00014F7C)  
#define sWgdc (0x00017990)  
#define sJsrWgdcInitial (0x0001820C)    
#define hTableWgdcInitial (0x00018328)  
#define tWgdcInitial (0x0009CD2C)   
#define tTableWgdcInitialAlt (0x00018330)   
#define tTableWgdcInitialAlt (0x0009CD10)   
#define hJsrWgdcMax (0x0001826E)    
#define hTableWgdcMax (0x00018364)  
#define tWgdcMax (0x0009CD64)   
#define tWgdcMaxAlt (0x0009CD48)    

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF73F4) 
#define hPull3DPolf (0x00031930)    
#define tPolf (0x0009E8A0)  
#define hTablePolf (0x0003193C) 
#define hJsrPolf (0x000317A8)   
#define hPolf (0x00015518)  
#define sPolf (0x000316FC)  
#define pPolfEnrich (0xFFFF73F4)    

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x000155D8)    
#define hTableBaseTiming (0x00039220)   
#define tBaseTiming (0x0009F018)    
#define pBaseTiming (0xFFFF777C)    
#define sBaseTiming (0x000390B2)    
#define hPull3DTiming (0x0003921C)  
#define hSubKca (0x00038A98)    
#define pKcaIam (0xFFFF7918)    
#define hFBKCRetardValue (0x0003B9DC)   
#define dFBKCRetardValue ((float*)0x000CBD58)   
#define hFBKCRetardValueAlternate (0x0003B9BC)  
#define dFBKCRetardValueAlternate ((float*)0x000CBD5C)  

/////////////////////
// AVCS Hacks
/////////////////////


/////////////////////
// Spark Cut
/////////////////////

#define sSparkCutOcrStart (0x0000A8CE)  
#define sSparkCutOcrEnd (0x0000A8E4)    
#define sSparkCutGrStart (0x0000A93E)   
#define sSparkCutGrEnd (0x0000A946) 

/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF650C)   
#define ResumeBitMask ((unsigned char)0x04) 
#define pCoastFlags ((unsigned char*)0xFFFF650C)    
#define CoastBitMask ((unsigned char)0x02)  
#define pBrakeFlags ((unsigned char*)0xFFFF650C)    
#define BrakeBitMask ((unsigned char)0x80)  
#define pClutchFlags ((unsigned char*)0xFFFF6A95)   
#define ClutchBitMask ((unsigned char)0x80) 
#define pTestModeFlags ((unsigned char*)0xFFFF6A90) 
#define TestModeBitMask ((unsigned char)0x20)   
#define pDefogFlags ((unsigned char*)0xFFFF6A93)    
#define DefogBitMask ((unsigned char)0x20)  
#define pSSMResetByte ((unsigned char*)0xFFFF308A)  

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6C18) 
#define pFbkc4 ((float*)0xFFFF78D4) 
#define pIam1 ((unsigned char*)0xFFFF6C1D)  
#define pIam4 ((float*)0xFFFF2E38)  
#define pEngineSpeed ((float*)0xFFFF6AC4)   
#define pVehicleSpeed ((float*)0xFFFF6AB4)  
#define pCoolantTemp ((float*)0xFFFF684C)   
#define pAtmoPress ((float*)0xFFFF863C) 
#define pManifoldAbsolutePressure ((float*)0xFFFF671C)  
#define pManifoldRelativePressure ((float*)0xFFFF6720)  
#define pInjectorPulseWidth ((float*)0xFFFF7640)    
#define pInjectorLatency ((float*)0xFFFF7654)   
#define pIntakeAirTemp ((float*)0xFFFF5CA4) 
#define pMassAirFlow ((float*)0xFFFF5CD8)   
#define pMafSensorVoltage ((short*)0xFFFF5C02)  
#define pEngineLoad ((float*)0xFFFF68D8)    
#define pReqTorque ((float*)0xFFFF7BC8) 
#define pThrottlePlate ((float*)0xFFFF67C0) 
#define pWgdc4 ((float*)0xFFFF63F4) 
#define pCurrentGear ((unsigned char*)0xFFFF6BCD)   
#define pAf1Res ((float*)0xFFFF5F10)    
#define pDeltaMap ((float*)0xFFFF6710)  

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)  

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C23D4)    
#define dLoadSmoothingB (0x000C23D8)    
#define dLoadSmoothingFinal (0x000C23E4)    

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FA9C)   
#define hMemoryReset (0x0000DD58)   
#define pMemoryResetLimit (0xFFFFBFBB)  
#define hMemoryResetLimit (0x000124C0)  

/////////////////////
// Dynamic RAM Tuning
/////////////////////

