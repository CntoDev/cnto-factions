#include "details.h"
#include "\cnto\factions\shared\include.h"

//
// This file is an SQF script called on initialization of every soldier unit
//

params ["_unit"];
if (!local _unit) exitWith {};

// don't override Arsenal-customized loadout
if (_unit call cnto_factions_fnc_hasModifiedLoadout) exitWith {};

//
// The big blocks of text below are from ACE arsenal "EXPORT"
// (updated 2022/10 for new ACE3 arsenal syntax)
//

private _loadout = switch (typeOf _unit) do {

    case QFACTION(team_leader): {
[[["SMG_03_TR_black","","","optic_Aco",["50Rnd_570x28_SMG_03",50],[],""],[],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1_black",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1],["50Rnd_570x28_SMG_03",1,50]]],["V_Rangemaster_belt",[["50Rnd_570x28_SMG_03",3,50]]],[],"H_Cap_blk_CMMG","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

    case QFACTION(rifleman): {
[[["SMG_03_TR_camo","","","optic_Aco",["50Rnd_570x28_SMG_03",50],[],""],[],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1_red",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1],["50Rnd_570x28_SMG_03",1,50]]],["V_Rangemaster_belt",[["50Rnd_570x28_SMG_03",3,50]]],[],"H_Cap_red","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

    case QFACTION(rifleman_at): {
[[["SMG_03_TR_khaki","","","optic_Aco",["50Rnd_570x28_SMG_03",50],[],""],["launch_RPG32_F","","","",["RPG32_F",1],[],""],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1_blue",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1],["50Rnd_570x28_SMG_03",1,50]]],["V_Rangemaster_belt",[["50Rnd_570x28_SMG_03",3,50]]],["B_AssaultPack_cbr",[["RPG32_F",2,1]]],"H_Cap_khaki_specops_UK","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

    case QFACTION(machinegunner): {
[[["LMG_Mk200_F","","","",["200Rnd_65x39_cased_Box",200],[],""],[],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1_blue",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1]]],["V_Rangemaster_belt",[["HandGrenade",2,1]]],["B_AssaultPack_blk",[["200Rnd_65x39_cased_Box",2,200]]],"H_Cap_police","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

    case QFACTION(medic): {
[[["SMG_03_TR_hex","","","optic_Aco",["50Rnd_570x28_SMG_03",50],[],""],[],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1_yellow",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1],["SmokeShell",1,1],["50Rnd_570x28_SMG_03",1,50]]],["V_Rangemaster_belt",[["SmokeShell",1,1],["50Rnd_570x28_SMG_03",3,50]]],["B_Kitbag_tan",[["ACE_elasticBandage",20],["ACE_packingBandage",20],["ACE_quikclot",10],["ACE_fieldDressing",10],["ACE_bloodIV",4],["ACE_epinephrine",15],["ACE_surgicalKit",1],["ACE_morphine",15]]],"H_Cap_surfer","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

    case QFACTION(crew): {
[[["SMG_03C_TR_black","","","optic_Aco",["50Rnd_570x28_SMG_03",50],[],""],[],["hgun_P07_F","","","",["16Rnd_9x21_Mag",17],[],""],["U_C_Driver_1",[["ACE_fieldDressing",1],["ACE_packingBandage",1],["ACE_morphine",1],["ACE_tourniquet",1],["50Rnd_570x28_SMG_03",1,50]]],["V_Rangemaster_belt",[["50Rnd_570x28_SMG_03",2,50]]],["B_AssaultPack_rgr",[["ToolKit",1],["SmokeShellGreen",2,1],["SmokeShellBlue",1,1],["SmokeShell",4,1]]],"H_Cap_grn_BI","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadioAcreFlagged","ItemCompass","Itemwatch",""]], []]
    };

};

private _facewear = goggles _unit;
_unit setUnitLoadout [_loadout select 0, false];
_unit addGoggles _facewear;
