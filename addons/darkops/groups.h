#include "details.h"
#include "\cnto\factions\shared\include.h"

class Infantry {
    name = "Infantry";
    class Everyone {
        name = "Everyone";
        icon = NATO_ICON(inf);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(cqb);       position[] = {0,0,0};     rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(grenadier); position[] = {5,-5,0};    rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(mark);      position[] = {-5,-5,0};   rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(scout);     position[] = {10,-10,0};  rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit4 { vehicle = FACTION(sniper);    position[] = {-10,-10,0}; rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit5 { vehicle = FACTION(mg);        position[] = {15,-15,0};  rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
        class Unit6 { vehicle = FACTION(missile);   position[] = {-15,-15,0}; rank = "LIEUTENANT"; side = FACTION_SIDE_NR; };
    };
};
