class CfgPatches {
    class cnto_factions_shared {
        units[] = {};
        weapons[] = {};
        requiredAddons[] = {};
    };
};

class CfgFunctions {
    class cnto_factions {
        class all {
            file = "\cnto\factions\shared";
            class hasModifiedLoadout;
        };
    };
};
