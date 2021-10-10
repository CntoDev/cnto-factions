#include "details.h"
#include "\cnto\factions\shared\include.h"

////////////////////////////////////////////////////////////////////////////////

class B_Soldier_base_F;

class FACTION(template) : B_Soldier_base_F {
    scope = 0;
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    editorSubcategory = "EdSubcat_Personnel_SpecialForces";
    nameSound = "veh_infantry_SF_s";
    genericNames = "EnglishMen";
    identityTypes[] = {
        "LanguageENGB_F",
        "Head_NATO",
        "NoGlasses"
    };
    icon = "iconMan";
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(setLoadout);
    };
    // hard to see by other AI
    camouflage = 0.1;
};

class FACTION(cqb) : FACTION(template) {
    scope = 2;
    displayName = "CQB Specialist";
};

class FACTION(grenadier) : FACTION(template) {
    scope = 2;
    displayName = "Grenadier";
};

class FACTION(mark) : FACTION(template) {
    scope = 2;
    displayName = "Marksman (AT/Utility)";
    engineer = 1;
};

class FACTION(demo) : FACTION(template) {
    scope = 2;
    displayName = "Demo Expert";
    engineer = 1;
    canDeactivateMines = 1;
    icon = "iconManExplosive";
};

class FACTION(scout) : FACTION(template) {
    scope = 2;
    displayName = "Scout";
    uavHacker = 1;
    icon = "iconManRecon";
};

class FACTION(sniper) : FACTION(template) {
    scope = 2;
    displayName = "Support Sniper";
};

class FACTION(mg) : FACTION(template) {
    scope = 2;
    displayName = "Support Gunner";
    icon = "iconManMG";
};

class FACTION(missile) : FACTION(template) {
    scope = 2;
    displayName = "Missile Master (AT)";
    icon = "iconManAT";
};

////////////////////////////////////////////////////////////////////////////////


class C_Quadbike_01_F;
class FACTION(quadbike_mines) : C_Quadbike_01_F {
    side = FACTION_SIDE_NR;
    faction = FACTION_CLASSNAME;
    VEHICLE_CREW(demo);
    displayName = "Quadbike with mines";
    // limit texture/color randomization to just the black texture
    textureList[] =  { "Black", 1 };
    // attach ammo box with mines
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(attachMinesBox);
    };
};

class Box_IED_Exp_F;
class FACTION(mines_box) : Box_IED_Exp_F {
    scope = 1;
    // clear out any weapons/items/backpacks
    class TransportWeapons {};
    class TransportMagazines {
        TMAGAZINE(10, ATMine_Range_Mag);
        TMAGAZINE(20, APERSBoundingMine_Range_Mag);
        TMAGAZINE(10, IEDUrbanBig_Remote_Mag);
        TMAGAZINE(15, IEDUrbanSmall_Remote_Mag);
        TMAGAZINE(10, IEDLandBig_Remote_Mag);
        TMAGAZINE(15, IEDLandSmall_Remote_Mag);
    };
    class TransportItems {};
    class TransportBackpacks {};
};
