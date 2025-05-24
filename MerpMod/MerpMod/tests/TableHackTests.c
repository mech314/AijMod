/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

//Tests for TableHack Code
//
#include "EcuHacks.h"
#include "Tests.h"

// All test functions must be explicitly put into the Misc section, otherwise
// the compiler/linker will put them in an address range that conflicts with
// ECU code.

// Test the rev limiter hack.
#if TIMING_HACKS

void TimingHackUnitTests()
{
	PopulateRamVariables();
	
	*pEngineSpeed = 3000;
	*pEngineLoad = 1.0;
	*pVehicleSpeed = 1.0;

#if SWITCH_HACKS

//TODO: Write switch unit tests

#else
	
	pRamVariables.MapSwitchingInputMode = MapSwitchingInputModeSiDrive;
	pRamVariables.TGVLeftVolts = 1;
	InputUpdate();
	pRamVariables.TimingHackEnabled = HackEnabled;
	pRamVariables.LCTimingLock = 20;

	pRamVariables.MapBlendRatio = 0;
	TimingHack();
	Assert(AreCloseEnough(pRamVariables.TimingOutput, -12.96875), "check timing map 1 is used");
	
	pRamVariables.MapBlendRatio = 1;
	TimingHack();
	Assert(pRamVariables.TimingOutput == -20, "check timing map 2 is used");
	
	pRamVariables.MapBlendRatio = 0.5;
	TimingHack();
	Assert(pRamVariables.TimingOutput == (0.5*(-12.96875 - 20)), "check blended value between timing maps 1 and 2 is used");
	
	pRamVariables.LCTimingMode = LCTimingModeLocked;		//Set locked timing, default is +20

#endif

}
#endif


// Test the primary open loop fuel table hack.
#if POLF_HACKS
void PolfHackUnitTests()
{
	PopulateRamVariables();
	
	*pEngineSpeed = 3000;
	*pEngineLoad = 1.0;
	*pThrottlePlate = 0;

	pRamVariables.PolfHackEnabled = HackEnabled;

	POLFHack();
	Assert(pRamVariables.MapBlendRatio == DefaultBlend, "Check for init Blend");
	Assert(pRamVariables.LCFuelLock == DefaultLCFuelLock, "Check for init LCFuelLock");
	Assert(pRamVariables.LCFuelMode == DefaultLCFuelMode, "Check for init FuelMode");
	
	*pIAM = 0;
	POLFHack();
	float ftff = 0;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ftff), "Check IAM Failsafe Map is used");
	
	*pEngineSpeed = 7000;
	POLFHack();
	ftff = 0.3203125;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ftff), "Check IAM Failsafe Map is used");
	
	*pIAM = 1;//TODO 1byte/4byte
	POLFHack();
	float ft1 = 0.3203125;	
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ft1), "Check map 1 is used");
	
	*pEngineSpeed = 3000;
	*pIAM = 1;
	POLFHack();
	ft1 = 0;	
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ft1), "Check map 1 is used");
	
	pRamVariables.MapBlendRatio = 1;
	POLFHack();
	float ft2 = 0;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ft2), "Check map 2 is used");
	
	*pEngineSpeed = 7000;
	pRamVariables.MapBlendRatio = 1;
	POLFHack();
	ft2 = 0.3203125;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ft2), "Check map 2 is used");
	
	pRamVariables.MapBlendRatio = 0.5;
	POLFHack();
	float ftb = 0.3203125;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, ftb), "Check Blending Value");
	
	pRamVariables.LCFuelMode = LCFuelModeLocked; //Lock the fueling target
	*pEngineSpeed  = (pRamVariables.LaunchControlCut - pRamVariables.LaunchControlHyst - 25);
	#if !AUTO_TRANS
	SetClutch(1);
	#endif
	*pVehicleSpeed = 0.0f;
	*pThrottlePlate = LCMinimumThrottle + 1;
	RevLimCode();	//init the rev limiter stuff
	POLFHack();
	float locked = 0.35;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, locked), "Check Locked Value");
	
	*pEngineSpeed = 7000;
	#if !AUTO_TRANS
	SetClutch(0);
	#endif
	RevLimCode();	
	pRamVariables.LCFuelMode = LCFuelModeCompensated; //Set to compensation
	pRamVariables.MapBlendRatio = 0;
	POLFHack();
	float comp = 0.5625;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, comp), "Check Comp Value");
	
	
	pRamVariables.LCFuelMode = LCFuelModeDisabled;
	POLFHack();
	float mine = 0.3203125;
	Assert(AreCloseEnough(pRamVariables.PolfOutput, mine), "Check Comp Value");
	
}
#endif
