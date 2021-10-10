// include this file *after* details.h
//

//
// misc macros
//
#define QUOTE(x) #x
#define SQUOTE(x) '##x##'
#define QQUOTE(x) QUOTE(QUOTE(x))

//
// "join" macros as you can't use ## or connect defines with literal strings
// without using a macro
//
#define JOIN2(a,b) a##b
#define JOIN3(a,b,c) a##b##c
#define JOIN4(a,b,c,d) a##b##c##d
#define JOIN5(a,b,c,d,e) a##b##c##d##e
#define JOIN6(a,b,c,d,e,f) a##b##c##d##e##f
#define JOIN7(a,b,c,d,e,f,g) a##b##c##d##e##f##g
#define JOIN8(a,b,c,d,e,f,g,h) a##b##c##d##e##f##g##h
#define JOIN9(a,b,c,d,e,f,g,h,i) a##b##c##d##e##f##g##h##i

//
// automatically generated per-faction defines
//
#define FACTION_CLASSNAME JOIN2(cnto_factions_,FACTION_ID)
#define FACTION_DISPLAYNAME QUOTE(JOIN3(CNTO, ,FACTION_HUMAN))
#define FACTION_PATH JOIN2(\cnto\factions\,FACTION_ID)
#define FACTION(id) JOIN3(FACTION_CLASSNAME,_,id)
#define QFACTION(id) QUOTE(FACTION(id))

#define FACTION_INITFUNC(id) \
    class FACTION(JOIN4(initfunc_,id,_,__LINE__)) { \
        init = QUOTE(JOIN4(_this call ,FACTION_CLASSNAME,_fnc_,id)); \
    }

#define FACTION_XEH_FACEWEAR(classname, facewear) \
    class FACTION(classname) { \
        class FACTION(set_custom_facewear) { \
            init = QUOTE(JOIN2((_this select 0) addGoggles ,SQUOTE(facewear))); \
        }; \
    }

#ifdef FACTION_SIDE_WEST
#define FACTION_SIDE_NR 1
#define FACTION_GRP_CLASS West
#define FACTION_NATO_LETTER b
#endif
#ifdef FACTION_SIDE_EAST
#define FACTION_SIDE_NR 0
#define FACTION_GRP_CLASS East
#define FACTION_NATO_LETTER o
#endif
#ifdef FACTION_SIDE_GUER
#define FACTION_SIDE_NR 2
#define FACTION_GRP_CLASS Indep
#define FACTION_NATO_LETTER n
#endif
#ifdef FACTION_SIDE_CIV
#define FACTION_SIDE_NR 3
#define FACTION_GRP_CLASS Empty
#define FACTION_NATO_LETTER c
#endif

// type: b_inf, b_hq, o_mortar, etc.
#define GRP_ICON(path) QUOTE(JOIN3(\A3\ui_f\data\map\markers\nato\,path,.paa))
#define NATO_ICON(type) QUOTE(JOIN5(\A3\ui_f\data\map\markers\nato\,FACTION_NATO_LETTER,_,type,.paa))

//
// these can be used multiple times on the same id, try varying classnames
// a bit using pseudorandom strings - cnt and __LINE__
//
#define TWEAPON(cnt, id) class id##cnt##__LINE__ { weapon = id; count = cnt; }
#define TMAGAZINE(cnt, id) class id##cnt##__LINE__ { magazine = id; count = cnt; }
#define TITEM(cnt, id) class id##cnt##__LINE__ { name = id; count = cnt; }
#define TBACKPACK(cnt, id) class id##cnt##__LINE__ { backpack = id; count = cnt; }

#define EMPTY_CARGO_LOADOUT \
    class TransportWeapons {}; \
    class TransportMagazines {}; \
    class TransportItems {}; \
    class TransportBackpacks {}

#define VEHICLE_CREW(soldier) \
    crew = FACTION(soldier); \
    typicalCargo[] = { FACTION(soldier) }
