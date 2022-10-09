#include "details.h"
#include "\cnto\factions\shared\include.h"

class CfgPatches {
    class FACTION_CLASSNAME {
        units[] = {
            // soldiers
            FACTION(team_leader),
            FACTION(rifleman),
            FACTION(rifleman_at),
            FACTION(machinegunner),
            FACTION(medic),
            FACTION(crew),
            // land vehicles
            FACTION(prowler),
            FACTION(marshall)
        };
        weapons[] = {};
        requiredAddons[] = {
            "cnto_factions_shared",
            "A3_Characters_F",
            "A3_Soft_F_Exp_LSV_01",
            "A3_Armor_F_Beta_APC_Wheeled_01"
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
        };
    };
};
