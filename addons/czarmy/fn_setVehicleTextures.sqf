#include "details.h"
#include "\cnto\factions\shared\include.h"

params ["_unit"];
if (!local _unit) exitWith {};

switch (typeOf _unit) do {

    case QFACTION(uaz): {
        _unit setObjectTextureGlobal [6, "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"];
        _unit setObjectTextureGlobal [7, "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"];
    };

    case QFACTION(truck): {
        _unit setObjectTextureGlobal [9, "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"];
        _unit setObjectTextureGlobal [10, "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"];
    };

    case QFACTION(bvp): {
        _unit setObjectTextureGlobal [9, "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"];
        // randomization was disabled in CfgVehicles.h, but we still need to
        // actually hide the crates
        _unit animateSource ["crate_l1_unhide", 1, true];
        _unit animateSource ["crate_l2_unhide", 1, true];
        _unit animateSource ["crate_l3_unhide", 1, true];
        _unit animateSource ["crate_r1_unhide", 1, true];
        _unit animateSource ["crate_r2_unhide", 1, true];
        _unit animateSource ["crate_r3_unhide", 1, true];
        _unit animateSource ["wood_1_unhide", 1, true];
    };
};
