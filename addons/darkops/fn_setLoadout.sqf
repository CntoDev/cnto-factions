#include "details.h"
#include "\cnto\factions\shared\include.h"

//
// This file is an SQF script called on initialization of every soldier unit
//

params ["_unit"];
if (!local _unit) exitWith {};

// don't override Arsenal-customized loadout
if (_unit call cnto_factions_fnc_hasModifiedLoadout) exitWith {};


private _uniform = [
    "CamoU_Black",
    [
        ["ACE_packingBandage",6],
        ["ACE_morphine",1],
        ["ACE_epinephrine",2],
        ["acc_flashlight",1],
        ["ACE_CableTie",6],
        ["ACE_IR_Strobe_Item",2],
        ["ACE_MapTools",1],
        ["SmokeShellGreen",2,1],
        ["HandGrenade", 1, 1]
    ]
];

private _linked_items = [
    "ItemMap",
    "ItemGPS",
    "ItemRadio",
    "ItemCompass",
    "ItemWatch",
    "NVGoggles_OPFOR"
];

private _loadout = switch (typeOf _unit) do {

    case QFACTION(cqb): {
        [
            ["SMG_02_F", "muzzle_snds_L", "acc_pointer_IR", "optic_Aco", ["30Rnd_9x21_Mag", 30], [], ""],
            [],
            [],
            _uniform,
            [
                "AAFVest01_l_black",
                [
                    ["30Rnd_9x21_Mag", 8, 30],
                    ["ACE_M84", 8, 1]
                ]
            ],
            [
                "B_AssaultPack_blk",
                [
                    ["30Rnd_9x21_Mag", 8, 30],
                    ["MiniGrenade", 4, 1],
                    ["ACE_M84", 12, 1]
                ]
            ],
            "rhsusf_protech_helmet",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

    case QFACTION(grenadier): {
        [
            ["arifle_Katiba_GL_F", "muzzle_snds_H", "acc_pointer_IR", "optic_Aco", ["30Rnd_65x39_caseless_green", 30], ["1Rnd_HE_Grenade_shell", 1], ""],
            [],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_m_black",
                [
                    ["30Rnd_65x39_caseless_green", 8, 30],
                    ["ACE_30Rnd_65x39_caseless_green_mag_Tracer_Dim", 2, 30]
                ]
            ],
            [
                "B_AssaultPack_blk",
                [
                    ["ACE_HuntIR_monitor", 1],
                    ["1Rnd_HE_Grenade_shell", 12, 1],
                    ["1Rnd_Smoke_Grenade_shell", 4, 1],
                    ["UGL_FlareWhite_F", 4, 1],
                    ["ACE_HuntIR_M203", 8, 1],
                    ["B_IR_Grenade", 2, 1]
                ]
            ],
            "rhsusf_protech_helmet",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

    case QFACTION(mark): {
        [
            ["srifle_DMR_04_F", "", "", "", ["10Rnd_127x54_Mag", 10], [], ""],
            ["rhs_weap_m72a7", "", "", "", [], [], ""],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_l_black",
                [
                    ["10Rnd_127x54_Mag", 6, 10],
                    ["16Rnd_9x21_Mag", 3, 17]
                ]
            ],
            [
                "B_AssaultPack_blk",
                [
                    ["ToolKit", 1],
                    ["ACE_wirecutter", 1]
                ]
            ],
            "H_Watchcap_blk",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

    case QFACTION(demo): {
        [
            ["arifle_Katiba_F", "muzzle_snds_H", "acc_pointer_IR", "optic_Aco", ["30Rnd_65x39_caseless_green", 30], [], ""],
            [],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_m_black",
                [
                    ["ACE_DeadManSwitch", 1],
                    ["ACE_DefusalKit", 1],
                    ["30Rnd_65x39_caseless_green", 8, 30],
                    ["ACE_30Rnd_65x39_caseless_green_mag_Tracer_Dim", 2, 30]
                ]
            ],
            [
                "B_FieldPack_blk",
                [
                    ["DemoCharge_Remote_Mag", 6, 1],
                    ["SLAMDirectionalMine_Wire_Mag", 2, 1],
                    ["IEDUrbanSmall_Remote_Mag", 1, 1]
                ]
            ],
            "H_Beret_blk",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]

    };

    case QFACTION(scout): {
        [
            ["hgun_PDW2000_F", "muzzle_snds_L", "", "optic_Aco", ["30Rnd_9x21_Mag", 30], [], ""],
            [],
            [],
            _uniform,
            [
                "TacVest_black",
                [
                    ["B_UavTerminal", 1],
                    ["ACE_microDAGR", 1],
                    [["ACE_MX2A","","","",[],[],""],1],
                    ["30Rnd_9x21_Mag", 4, 30]
                ]
            ],
            [],
            "BoonieH_black",
            "",
            ["Laserdesignator_03", "", "", "", ["Laserbatteries", 1], [], ""],
            _linked_items
        ]

    };

    case QFACTION(sniper): {
        [
            ["srifle_GM6_F", "", "", "optic_lrps", ["5Rnd_127x108_APDS_Mag", 5], [], ""],
            [],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_l_black",
                [
                    ["ACE_ATragMX", 1],
                    ["ACE_Kestrel4500", 1],
                    ["optic_NVS", 1],
                    ["5Rnd_127x108_APDS_Mag", 5, 5],
                    ["16Rnd_9x21_Mag", 2, 17]
                ]
            ],
            [],
            "BoonieH_black",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

    case QFACTION(mg): {
        [
            ["hlc_lmg_M60E4", "", "", "", ["rhsusf_100Rnd_762x51_m61_ap", 100], [], ""],
            [],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_m_black",
                [
                    ["ACE_EarPlugs", 1],
                    ["16Rnd_9x21_Mag", 2, 17],
                    ["rhsusf_100Rnd_762x51_m61_ap", 3, 100]
                ]
            ],
            [
                "B_FieldPack_blk",
                [
                    ["rhsusf_100Rnd_762x51_m61_ap", 6, 100]
                ]
            ],
            "H_Bandanna_gry",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

    case QFACTION(missile): {
        [
            ["arifle_Katiba_F", "muzzle_snds_H", "acc_pointer_IR", "optic_Aco", ["30Rnd_65x39_caseless_green", 30], [], ""],
            ["launch_I_Titan_short_F", "", "", "", ["Titan_AT", 1], [], ""],
            ["hgun_P07_snds_F", "muzzle_snds_L", "", "", ["16Rnd_9x21_Mag", 17], [], ""],
            _uniform,
            [
                "AAFVest01_m_black",
                [
                    ["30Rnd_65x39_caseless_green", 4, 30],
                    ["ACE_30Rnd_65x39_caseless_green_mag_Tracer_Dim", 2, 30]
                ]
            ],
            [
                "cnto_vanilla_carryall_blk",
                [
                    ["Titan_AT", 2, 1]
                ]
            ],
            "H_Bandanna_gry",
            "",
            ["ACE_Vector", "", "", "", [], [], ""],
            _linked_items
        ]
    };

};

private _facewear = goggles _unit;
_unit setUnitLoadout [_loadout, false];
_unit addGoggles _facewear;
