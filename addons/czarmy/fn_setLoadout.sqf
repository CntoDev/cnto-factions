#include "details.h"
#include "\cnto\factions\shared\include.h"

//
// This file is an SQF script called on initialization of every soldier unit
//

params ["_unit"];
if (!local _unit) exitWith {};

// don't override Arsenal-customized loadout
if (_unit call cnto_factions_fnc_hasModifiedLoadout) exitWith {};

private _loadout = switch (typeOf _unit) do {

    case QFACTION(squad_leader): {
[["rhs_weap_savz58p_black","","","",["rhs_30Rnd_762x39mm_Savz58_tracer",30],[],""],[],["rhs_weap_cz99_etched","","","",["rhssaf_mag_15Rnd_9x19_FMJ",15],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["ACE_MRE_CreamTomatoSoup",1],["ACE_Can_Franta",1],["rhssaf_mag_15Rnd_9x19_FMJ",1,15],["SmokeShellYellow",2,1]]],["rhssaf_vest_md99_md2camo_radio",[["rhs_30Rnd_762x39mm_Savz58_tracer",5,30]]],[],"rhsgref_helmet_pasgt_erdl","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadio","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(team_leader): {
[["rhs_weap_savz58p_black","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],[],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["SmokeShellYellow",2,1],["rhs_mag_f1",1,1]]],["rhssaf_vest_md99_md2camo_rifleman_radio",[["rhs_30Rnd_762x39mm_Savz58",5,30],["rhs_mag_f1",1,1]]],[],"rhsgref_helmet_pasgt_erdl","",["Binocular","","","",[],[],""],["ItemMap","","ItemRadio","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(rifleman): {
[["rhs_weap_savz58p","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],[],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_mag_f1",2,1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_30Rnd_762x39mm_Savz58",6,30]]],[],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(rifleman_at): {
[["rhs_weap_savz58p","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],["rhs_weap_rpg75","","","",[],[],""],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_mag_f1",2,1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_30Rnd_762x39mm_Savz58",6,30]]],[],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(rifleman_ammo): {
[["rhs_weap_savz58p","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],[],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_mag_f1",2,1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_30Rnd_762x39mm_Savz58",6,30]]],["rhssaf_alice_md2camo",[["rhs_30Rnd_762x39mm_Savz58",10,30],["rhs_30Rnd_762x39mm_Savz58_tracer",4,30],["rhsgref_20rnd_765x17_vz61",4,20],["rhs_mag_f1",6,1],["SmokeShellYellow",4,1]]],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(machinegunner): {
[["rhs_weap_fnmag","","","",["rhsusf_100Rnd_762x51",100],[],""],[],[],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhsusf_100Rnd_762x51",2,100]]],["rhssaf_kitbag_md2camo",[["rhsusf_100Rnd_762x51",4,100]]],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(marksman): {
[["rhs_weap_svdp_pso1","","","rhs_acc_pso1m2",["rhs_10Rnd_762x54mmR_7N1",10],[],""],[],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_10Rnd_762x54mmR_7N1",3,10]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_10Rnd_762x54mmR_7N1",10,10],["rhsgref_20rnd_765x17_vz61",2,20]]],[],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(antitank): {
[["rhs_weap_savz58p","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],["rhs_weap_rpg7","","","",["rhs_rpg7_PG7VL_mag",1],[],""],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_mag_f1",2,1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_30Rnd_762x39mm_Savz58",6,30]]],["rhssaf_kitbag_md2camo",[["rhs_rpg7_PG7VL_mag",4,1]]],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(medic): {
[["rhs_weap_savz58p","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],[],["rhs_weap_savz61_folded","","","",["rhsgref_20rnd_765x17_vz61",20],[],""],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_mag_f1",2,1]]],["rhssaf_vest_md99_md2camo_rifleman",[["rhs_30Rnd_762x39mm_Savz58",6,30]]],["rhssaf_kitbag_md2camo",[["ACE_fieldDressing",10],["ACE_elasticBandage",15],["ACE_packingBandage",15],["ACE_morphine",5],["ACE_epinephrine",10],["ACE_bloodIV_500",5],["ACE_bodyBag",2],["ACE_Can_Spirit",1]]],"rhsgref_helmet_pasgt_erdl","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]
    };

    case QFACTION(crew): {
[["rhs_weap_savz58v","","","",["rhs_30Rnd_762x39mm_Savz58",30],[],""],[],[],["rhsgref_uniform_ERDL",[["ACE_fieldDressing",4],["ACE_morphine",1],["ACE_epinephrine",1],["ACE_Flashlight_MX991",1],["ACE_MapTools",1],["rhs_30Rnd_762x39mm_Savz58",2,30]]],[],[],"rhs_tsh4","",[],["ItemMap","","ItemRadio","ItemCompass","ItemWatch",""]]
    };

};

private _facewear = goggles _unit;
_unit setUnitLoadout [_loadout, false];
_unit addGoggles _facewear;
