#include "details.h"
#include "\cnto\factions\shared\include.h"

class Infantry {
    name = "Infantry";
    class Fireteam {
        name = "Fireteam";
        icon = NATO_ICON(inf);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(team_leader);   position[] = {0,0,0};     rank = "CORPORAL"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(rifleman_at);   position[] = {5,-5,0};    rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(machinegunner); position[] = {-5,-5,0};   rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(rifleman);      position[] = {10,-10,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
    };
    class Squad {
        name = "Squad";
        icon = NATO_ICON(inf);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(team_leader);   position[] = {0,0,0};     rank = "SERGEANT"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(rifleman_at);   position[] = {5,-5,0};    rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(medic);         position[] = {-5,-5,0};   rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(machinegunner); position[] = {10,-10,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit4 { vehicle = FACTION(rifleman);      position[] = {-10,-10,0}; rank = "CORPORAL"; side = FACTION_SIDE_NR; };
        class Unit5 { vehicle = FACTION(machinegunner); position[] = {15,-15,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit6 { vehicle = FACTION(rifleman_at);   position[] = {-15,-15,0}; rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit7 { vehicle = FACTION(rifleman);      position[] = {20,-20,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
    };
};

class Motorized {
    name = "Motorized Infantry";
    class Patrol {
        name = "Patrol (Prowler)";
        icon = NATO_ICON(motor_inf);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(team_leader);   position[] = {0,0,0};     rank = "CORPORAL"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(rifleman_at);   position[] = {5,-5,0};    rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(machinegunner); position[] = {-5,-5,0};   rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(medic);         position[] = {10,-10,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit4 { vehicle = FACTION(prowler);       position[] = {-10,-10,0}; rank = "PRIVATE";  side = FACTION_SIDE_NR; };
    };
    class Squad {
        name = "Squad (Marshall)";
        icon = NATO_ICON(motor_inf);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(team_leader);   position[] = {0,0,0};     rank = "SERGEANT"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(rifleman_at);   position[] = {5,-5,0};    rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(medic);         position[] = {-5,-5,0};   rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(machinegunner); position[] = {10,-10,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit4 { vehicle = FACTION(rifleman);      position[] = {-10,-10,0}; rank = "CORPORAL"; side = FACTION_SIDE_NR; };
        class Unit5 { vehicle = FACTION(machinegunner); position[] = {15,-15,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit6 { vehicle = FACTION(rifleman_at);   position[] = {-15,-15,0}; rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit7 { vehicle = FACTION(rifleman);      position[] = {20,-20,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit8 { vehicle = FACTION(marshall);      position[] = {25,-25,0};  rank = "PRIVATE";  side = FACTION_SIDE_NR; };
    };
};
