#include "EcuHacks.h"

/////////////////
//Constants
/////////////////
#if CAN_HACKS


unsigned short CANBusECAUpdateCount CANDATA = 45;


CanMessageSetupStruct ccm00 CANDATA = {.id = 0x0EC, .ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 19,	.mcs = mcsReceive, 	.nmc = 1, .rate =   0, .callback = 0};
CanMessageSetupStruct ccm01 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 20,	.mcs = mcsTrans, 	.nmc = 0, .rate =  	0, .callback = 0}; 
CanMessageSetupStruct ccm02 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 21,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0}; 
CanMessageSetupStruct ccm03 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 22,	.mcs = mcsTrans,    .nmc = 0, .rate =   0, .callback = 0}; 
CanMessageSetupStruct ccm04 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 23,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0};
CanMessageSetupStruct ccm05 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 24,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0};
CanMessageSetupStruct ccm06 CANDATA = {.id = 0x000, .ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 25,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0};
CanMessageSetupStruct ccm07 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 0,	.bus = 0,	.mailBox = 26,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0};
CanMessageSetupStruct ccm08 CANDATA = {.id = 0x420,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 27,	.mcs = mcsTrans, 	.nmc = 0, .rate =  10, .callback = 0};
CanMessageSetupStruct ccm09 CANDATA = {.id = 0x421,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 28,	.mcs = mcsTrans, 	.nmc = 0, .rate =  10, .callback = (unsigned long)&counterCallBack};
CanMessageSetupStruct ccm10 CANDATA = {.id = 0x422,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 29,	.mcs = mcsTrans, 	.nmc = 0, .rate =  10, .callback = 0};
CanMessageSetupStruct ccm11 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 30,	.mcs = mcsTrans, 	.nmc = 0, .rate =   0, .callback = 0};

unsigned char dataLinkedInRam  __attribute__ ((section ("RamHole")));

unsigned long cmDTaddr[cmDTCount] CANDATA = {
	(unsigned long)&pRamVariables.m420_b0,(unsigned long)&pRamVariables.m420_b1,(unsigned long)&pRamVariables.m420_b2,(unsigned long)&pRamVariables.m420_b3,(unsigned long)&pRamVariables.m420_b5,(unsigned long)&pRamVariables.m420_b6,(unsigned long)&pRamVariables.m420_b7,
	(unsigned long)&pRamVariables.m421_b0,(unsigned long)&pRamVariables.m421_b3,
	(unsigned long)&pRamVariables.m422_b2,(unsigned long)&pRamVariables.m422_b7};


//format conversion prior to transmitting
// this controls whether the address table cmdtaddr is checked.
// it is also the input to the format conversion	
unsigned char cmDTtypeIn[cmDTCount] CANDATA = {
	dtChar,dtChar,dtChar,dtChar,dtChar,dtChar,dtChar,
	dtChar,dtChar,
	dtChar,dtChar};

unsigned char cmDTtypeOut[cmDTCount] CANDATA = {
	dtChar,dtChar,dtChar,dtChar,dtChar,dtChar,dtChar,
	dtChar,dtChar,
	dtChar,dtChar};
	
unsigned char cmDTccm[cmDTCount] CANDATA = {
	8,8,8,8,8,8,8,
	9,9,
	10,10};
	
unsigned char cmDTpos[cmDTCount] CANDATA = {
	0,1,2,3,5,6,7,
	0,3,
	2,7};

	
float cmDTscale[cmDTCount] CANDATA = {
	0,0,0,0,0,0,0,
	0,0,
	0,0};
	
float cmDToffset[cmDTCount] CANDATA = {
	0,0,0,0,0,0,0,
	0,0,
	0,0};

#endif