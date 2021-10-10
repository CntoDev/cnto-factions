#include "details.h"
#include "\cnto\factions\shared\include.h"

class CfgPatches {
    class FACTION_CLASSNAME {
        units[] = {
            // soldiers
            FACTION(squad_leader),
            FACTION(team_leader),
            FACTION(rifleman),
            FACTION(rifleman_at),
            FACTION(rifleman_ammo),
            FACTION(machinegunner),
            FACTION(marksman),
            FACTION(antitank),
            FACTION(medic),
            FACTION(crew),
            // land vehicles
            FACTION(uaz),
            FACTION(truck),
            FACTION(bvp),
            // crates
            FACTION(resupply)
        };
        weapons[] = {};
        requiredAddons[] = {
            "cnto_factions_shared",
            "A3_Characters_F",
            "rhsgref_c_vehicles_ret",
            "A3_Weapons_F_Bootcamp_Ammoboxes"
        };
    };
};

class CfgFactionClasses {
    class FACTION_CLASSNAME {
        displayName = FACTION_DISPLAYNAME;
        side = FACTION_SIDE_NR;
    };
};
class CfgEditorSubcategories {
    class FACTION_CLASSNAME {
        displayName = FACTION_DISPLAYNAME;
    };
};

class EventHandlers;
class CfgVehicles {
#include "CfgVehicles.h"
};

class CfgGroups {
    class FACTION_GRP_CLASS {
        class FACTION_CLASSNAME {
            name = FACTION_DISPLAYNAME;
#include "groups.h"
        };
    };
};

class CfgFunctions {
    class FACTION_CLASSNAME {
        class all {
            file = FACTION_PATH;
            class setLoadout;
            class setVehicleTextures;
        };
    };
};
