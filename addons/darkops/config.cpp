#include "details.h"
#include "\cnto\factions\shared\include.h"

class CfgPatches {
    class FACTION_CLASSNAME {
        units[] = {
            // soldiers
            FACTION(cqb),
            FACTION(grenadier),
            FACTION(mark),
            FACTION(demo),
            FACTION(scout),
            FACTION(sniper),
            FACTION(mg),
            FACTION(missile),
            // cars
            FACTION(quadbike_mines)
        };
        weapons[] = {};
        requiredAddons[] = {
            "cnto_factions_shared",
            "A3_Characters_F",
            "A3_Soft_F_Quadbike_01",
            "A3_Supplies_F_Exp_Ammoboxes"
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
            class attachMinesBox;
        };
    };
};

class Extended_InitPost_EventHandlers {
    FACTION_XEH_FACEWEAR(cqb,cnto_flecktarn_f_bala_forest);
    FACTION_XEH_FACEWEAR(grenadier,cnto_flecktarn_f_bala_forest);
    FACTION_XEH_FACEWEAR(mark,G_Bandanna_blk);
    FACTION_XEH_FACEWEAR(demo,G_Balaclava_blk);
    FACTION_XEH_FACEWEAR(scout,G_Balaclava_blk);
    FACTION_XEH_FACEWEAR(sniper,G_Balaclava_blk);
    FACTION_XEH_FACEWEAR(mg,G_Bandanna_blk);
    FACTION_XEH_FACEWEAR(missile,G_Bandanna_blk);
};
