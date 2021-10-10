#include "details.h"
#include "\cnto\factions\shared\include.h"

////////////////////////////////////////////////////////////////////////////////

//
// This faction is intentionally simple and straightforward - no custom weapons,
// no EventHandlers (init lines), nothing too special.
//

class B_Soldier_base_F;

class FACTION(template) : B_Soldier_base_F {
    scope = 0;
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    genericNames = "CzechMen";
    identityTypes[] = {
        "LanguageCZ",
        "Head_Euro",
        "NoGlasses"
    };
    icon = "iconMan";
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setLoadout);
    };
};

class FACTION(squad_leader) : FACTION(template) {
    scope = 2;
    displayName = "Squad Leader";
    icon = "iconManLeader";
};

class FACTION(team_leader) : FACTION(template) {
    scope = 2;
    displayName = "Team Leader";
    icon = "iconManLeader";
};

class FACTION(rifleman) : FACTION(template) {
    scope = 2;
    displayName = "Rifleman";
};

class FACTION(rifleman_at) : FACTION(template) {
    scope = 2;
    displayName = "Rifleman AT (RPG-75)";
    icon = "iconManAT";
};

class FACTION(rifleman_ammo) : FACTION(template) {
    scope = 2;
    displayName = "Ammo Bearer";
};

class FACTION(machinegunner) : FACTION(template) {
    scope = 2;
    displayName = "Machine Gunner (7.62)";
    icon = "iconManMG";
};

class FACTION(marksman) : FACTION(template) {
    scope = 2;
    displayName = "Marksman (SVD)";
};

class FACTION(antitank) : FACTION(template) {
    scope = 2;
    displayName = "Anti-tank (RPG-7)";
    icon = "iconManAT";
};

class FACTION(medic) : FACTION(template) {
    scope = 2;
    displayName = "Medic";
    icon = "iconManMedic";
    attendant = 1;
};

class FACTION(crew) : FACTION(template) {
    scope = 2;
    displayName = "Crew";
    icon = "iconManEngineer";
    engineer = 1;
};

////////////////////////////////////////////////////////////////////////////////

//
// vehicles (wheeled, tracked, airborne, naval, etc.)
//

class rhsgref_cdf_reg_uaz;
class FACTION(uaz) : rhsgref_cdf_reg_uaz {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(rifleman);
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setVehicleTextures);
    };
    // remove medkits
    EMPTY_CARGO_LOADOUT;
};

class rhsgref_cdf_gaz66;
class FACTION(truck) : rhsgref_cdf_gaz66 {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(rifleman);
    // classify under Car (next to the UAZ) instead of Truck
    editorSubcategory = "rhs_EdSubcat_car";
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setVehicleTextures);
    };
    // remove medkits
    EMPTY_CARGO_LOADOUT;
}

class rhsgref_cdf_bmp2;
class FACTION(bvp) : rhsgref_cdf_bmp2 {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(crew);
    displayName = "BVP-2";
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setVehicleTextures);
    };
    // we're reusing platoon label for flag, so disable RHS platoon/army randomization
    // - not needed with CDF version of the BMP
    //rhs_decalParameters[] = { "['Number', cBMP3NumberPlaces, 'Default']" };
    // no reactive armor crates blocking flag/number
    rhs_habarType = 0;
    rhs_randomizedHabar[] = {};
    // RHS BMPs carry a lot of various stuff
    EMPTY_CARGO_LOADOUT;
};

////////////////////////////////////////////////////////////////////////////////

//
// crates
//

class Box_FIA_Ammo_F;

class FACTION(resupply) : Box_FIA_Ammo_F {
    editorSubcategory = FACTION_CLASSNAME;
    displayName = "Camo Resupply Box";
    class TransportWeapons {
        TWEAPON(5, rhs_weap_rpg75);
    };
    class TransportMagazines {
        TMAGAZINE(25, rhs_30Rnd_762x39mm_Savz58);
        TMAGAZINE(8, rhs_30Rnd_762x39mm_Savz58_tracer);
        TMAGAZINE(10, rhssaf_mag_15Rnd_9x19_FMJ);
        TMAGAZINE(12, rhs_mag_f1);
        TMAGAZINE(8, SmokeShellYellow);
        TMAGAZINE(15, rhsusf_100Rnd_762x51);
        TMAGAZINE(10, rhs_10Rnd_762x54mmR_7N1);
        TMAGAZINE(6, rhs_rpg7_PG7VL_mag);
    };
    class TransportItems {
        TITEM(5, ACE_Can_Franta);
        TITEM(5, ACE_Can_Spirit);
        TITEM(30, ACE_fieldDressing);
        TITEM(4, ACE_morphine);
        TITEM(4, ACE_epinephrine);
        TITEM(4, ACE_bloodIV_500);
    };
    class TransportBackpacks {};
};
