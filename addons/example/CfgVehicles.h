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
    genericNames = "EnglishMen";
    identityTypes[] = {
        "LanguageENG_F",
        "Head_Euro",
        "G_NATO_casual"
    };
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setLoadout);
    };
};

class FACTION(team_leader) : FACTION(template) {
    scope = 2;
    displayName = "Team Leader";
    icon = "iconManLeader";
};

class FACTION(rifleman) : FACTION(template) {
    scope = 2;
    displayName = "Rifleman";
    icon = "iconMan";
};

class FACTION(rifleman_at) : FACTION(template) {
    scope = 2;
    displayName = "Rifleman AT";
    icon = "iconManAT";
};

class FACTION(machinegunner) : FACTION(template) {
    scope = 2;
    displayName = "Machine Gunner";
    icon = "iconManMG";
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

class B_LSV_01_unarmed_F;
class FACTION(prowler) : B_LSV_01_unarmed_F {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(rifleman);
};

class B_APC_Wheeled_01_cannon_F;
class FACTION(marshall) : B_APC_Wheeled_01_cannon_F {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(crew);
};
