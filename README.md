# CNTO Factions

These are AI (and maybe player) factions used by CNTO, with some basic
definitions created via the Arma 3 game engine configs, but with loadout
done though scripting (`setUnitLoadout`) because it avoids 20 years of
bad design decisions.

In case you're wondering - yes, you can customize individuals using the
in-editor Arsenal and your changes will persist, though the loadout of
arsenal-modified soldiers won't get updated with new changes to this
factions mod.

## Table of contents

* [Basic layout](#basic-layout)
  * [Preprocessor macros](#preprocessor-macros)
  * [Macros as used by factions](#macros-as-used-by-factions)
  * [Classes](#classes)
* [Soldier definitions](#soldier-definitions)
  * [Addon dependencies](#addon-dependencies)
  * [Unit list](#unit-list)
* [EventHandlers (init lines)](#eventhandlers-init-lines)
* [Loadouts (gear)](#loadouts-gear)
* [Medic, engineer, etc.](#medic-engineer-etc)
* [Soldier names](#soldier-names)
* [Identities (voice, face, glasses)](#identities-voice-face-glasses)
  * [Commonly used `identityTypes` tags](#commonly-used-identitytypes-tags)
  * [Radio reports](#radio-reports)
* [Editor factions and subcategories](#editor-factions-and-subcategories)
  * [Subcategory for crates](#subcategory-for-crates)
* [Vehicle cargo and crates](#vehicle-cargo-and-crates)
* [Soldier and group icons](#soldier-and-group-icons)
* [Groups](#groups)
  * [Assigned vehicles](#assigned-vehicles)
* [Specific soldier facewear](#specific-soldier-facewear)

## Basic layout

Each faction is a folder under `addons`, with `shared` being an exception,
holding shared helper definitions/scripts for creating factions. To make this
work, each faction also needs its `$PBOPREFIX$` file with

```
cnto\faction\your_faction_here
```

and a copy of `$PBOPREFIX$` named `$PREFIX$` (for compatibility with PBO Manager
which doesn't respect `$PBOPREFIX$`).

Each faction also needs a `details.h` file, outlining

* a faction identifier (lowercase, without special characters other than
  underscore), which must be the same as `your_faction_here` in `$PBOPREFIX$`
* a human-readable faction name (may contain spaces, will show up in editor,
  Zeus and other places)
* a faction side (used for categorization in editor/Zeus, etc.)

Another important file is `CfgVehicles.h`, defining soldiers, cars, planes,
boxes, and any other objects.

Groups (formations) are then defined in `groups.h`, using the soldiers/cars/etc.
created in `CfgVehicles.h`.

And all this nicely fits together into `config.cpp`, which "includes" everything
mentioned above - you could indeed define everything inside `config.cpp`, but,
for readability, we split it into multiple files.

All of this is much, much easier if you copy/paste an existing faction and
use it as a base for your new one.

### Preprocessor macros

Preprocessor is some logic that pre-processes the files on game start, ie. if
you do

```cpp
#define POOP Sagu
soldier_name = POOP;
```

the pre-processor deletes the first line and replaces `POOP` with `Sagu` in the
second line - this is done **before** the main game engine starts, so the game
sees just

```cpp
soldier_name = Sagu;
```

Macros can also appear as "functions" with parameters, ie.

```cpp
#define POOP(id) soldier_name = id
POOP(Sagu);
```

In this case, the output is the same as in the first example, but it's much
easier to substitute a different name or use the `POOP()` macro multiple times
with different names.

Read more on
[the BI wiki page](https://community.bistudio.com/wiki/PreProcessor_Commands).

### Macros as used by factions

You can see the full list in [shared/include.h](addons/shared/include.h),
but that's a big file, so here is a simple example.

Your `CfgVehicles.h` file has, at the top,

```cpp
#include "details.h"
#include "\cnto\factions\shared\include.h"
```

This makes it first include the contents of `details.h`, followed by the generic
helpers from `shared`. This results in ie.

```
#define FACTION_ID czarmy
...
#define JOIN2(a,b) a##b
#define JOIN3(a,b,c) a##b##c
...
#define FACTION_CLASSNAME JOIN2(cnto_factions_,FACTION_ID)
...
#define FACTION(id) JOIN3(FACTION_CLASSNAME,_,id)
```

(The `##` just means "concatenate what's on the left with what's on the right".)

So whenever you see `FACTION(blabla)`, it gets automatically transcribed by the
pre-processor to `cnto_factions_czarmy_blabla`.

This makes the files/code highly copy-pastable, as it's not "hardcoding" the
faction name anywhere except in `$PBOPREFIX$`, `$PREFIX$` and `details.h`.
It also makes the code slightly easier to read.

### Classes

The game engine uses a system of "classes" to define configuration for various
things - from soldiers, to smoke particles, to UI elements, and even the game
"video options" in the menu. This is done in a hierarchy - each "class" can have
sub-classes, and each of those can also have subclasses, etc.  
Any class can also have "attributes", which are numbers, strings, sets (arrays)
of the actual useful values.

```cpp
class CNTO {
    type = "community";
    game = "Arma 3";
    class Members {
        class Sagu {
            nick = "Sagu";
            rank = "Reservist";
            accent = "PL";
            skill = 2;
        };
    };
};
```

(Sometimes, the opening `{` is present on the next line, though this is purely
a stylistical choice, it has no effect on functionality.)

These classes can sometimes "inherit" each other, forming a parent/child
relation - this allows you to easily create a new class based off of another one
and overwrite only the differences.

```cpp
class CNTO {
    type = "community";
    game = "Arma 3";
    class Members {
        class Sagu {
            nick = "Sagu";
            role = "entertainer";
            rank = "reservist";
            skill = 2;
        };
        class Garf : Sagu {
            nick = "Garf";
            rank = "specialist";
        };
    };
};
```

Here, `Garf` in fact has all 4 attributes, but `role` and `skill` were inherited
from `Sagu`, so they're the same. Only `nick` and `rank` were overwriten.


## Soldier definitions

Again - see one of the existing factions for a much easier way to understand
this.

Soldiers are defined in `CfgVehicles.h` and they all inherit from
`B_Sodlier_base_F`, which is a baseline for what a soldier is, as defined in the
vanilla game files by BI.  
This baseline is further tweaked into a "template" soldier for your factions,
which is then used (inherited) to create the actual faction soldiers.

```cpp
class B_Soldier_base_F;

class FACTION(template) : B_Soldier_base_F {
    scope = 0;
    ... face, voice, icons, etc. here ...
};

class FACTION(squad_leader) : FACTION(template) {
    scope = 2;
    ... squad leader specifics here ...
};

class FACTION(demo) : FACTION(template) {
    scope = 2;
    ... demolition expert specifics here ...
};

...
```

The `scope = 0` causes the class to exist only for inheritance and not be used
in the game - you cannot spawn a soldier with `scope = 0`.  
Using `scope = 1` makes the classname exist (spawnable via scripting), but
hidden from editor, Zeus and any visible places.  
Finally, `scope = 2` makes it fully visible.

We use these to hide our template (incomplete soldier) and show only the fully
defined, completed soldiers.

### Addon dependencies

The first line in the example above tells the game engine that
`B_Soldier_base_F` is something defined elsewhere. Otherwise the engine would
yell at us that we never filled in any `B_Soldier_base_F`.

To be able to reference external classes like this, their `.pbo`s need to be
loaded first (they need to be already loaded by the game). This could be done
by adjusting mod load order (ie. in A3S), but there is a more universal
solution.

The `config.cpp` file specifies `requiredAddons[]` - these are "addon" (pbo)
names which must be loaded **before** your addon (faction), guaranteeing that
the classes you use from them are available.

To get the addon name for another soldier (car/plane/box/whatever) class, run
this in the debug console, ie. "Tools -> Debug Console" in the editor:

```sqf
configSourceAddonList (configFile >> "CfgVehicles" >> "B_Soldier_base_F") select 0;
```

This will return something like

```sqf
"A3_Characters_F"
```

This is why `A3_Characters_F` is already in your `config.cpp` - we need it to
be able to use `B_Soldier_base_F`.

You will need to do this for anything else that doesn't inherit from
`B_Soldier_base_F` or its children, ie. you will need it for cars, APCs, tanks,
boxes, and so on.

### Unit list

`config.cpp` also contains `units[]` under `CfgPatches`, which is a list of your
newly created soldier class names. This is only really used by Zeus, but without
this, units/groups wouldn't show up in it.

No big deal, just a bit annoying.

## EventHandlers (init lines)

You can define any custom code to be executed like if it was run from the editor
"init" code box. You can do more (run code when the soldier enters a vehicle,
fires a gun, etc.), but initialization is the most common.

To do this, use `class EventHandlers` in your soldier config, though make sure
to inherit any `EventHandlers` from the parent class, preserving CBA
functionality.

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    class EventHandlers : EventHandlers {
        class FACTION(something_unique_here) {
            init = "your_code";
        };
    };
    ...
};
```

If the code is more complex than a simple line, define your own function in
`config.cpp`, create it as a file, and then call it using a macro:

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    class EventHandlers : EventHandlers {
        FACTION_INITFUNC(yourFunction);
    };
    ...
};
```

This is just a shorthand for ie.

```cpp
        class FACTION(something_random_but_deterministic) {
            init = "_this call cnto_factions_czarmy_fnc_yourFunction";
        };
```

You can also specify multiple `FACTION_INITFUNC` lines (calling multiple
different functions).

## Loadouts (gear)

Soldier loadouts are done using a `setLoadout` function, called exactly as
outlined above, via `FACTION_INITFUNC(setLoadout)`. This is specified **in the
soldier template**, so it's called for all soldiers.

The function is then in its own file, `fn_setLoadout.sqf`, and figures out
which soldier classname it was called for and selects the appropriate loadout.

Because `setUnitLoadout` is used, the loadout array is standard and **identical
to ACE Arsenal EXPORT functionality**, meaning if you want the dirty and easy
way to do loadout, just IMPORT/EXPORT to/from ACE Arsenal.  
Make sure you do this while in editor, not when in a running game, otherwise
ACRE2 will mess it up by replacing radios.

## Medic, engineer, etc.

This is easy - these are just 0/1 switches in the soldier class, just with
somewhat unintuitive names.

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    // medic (considered "doctor" by ACE)
    attendant = 1;
    // engineer (repairing, etc.)
    engineer = 1;
    // explosive specialist (demining)
    canDeactivateMines = 1;
    // can convert a landed UAV to its own side
    uavHacker = 1;
    ...
};
```

## Soldier names

These are randomly picked from `GenericNames` under class `CfgWorlds` -
the first name and last name are selected independently.

Some common categories under `GenericNames` include `RussianMen`,
`RussianWomen`, `EnglishMen`, `EnglishWomen`, `CzechMen`,
`CzechWomen`, `TakistaniMen`, `TakistaniWomen`, `GreekMen`,
`GreekWomen`, `NATOMen` (default), `AfroMen`, `AsianMen`,
`TanoanMen`, `ChineseMen`, `EnochMen` (Polish).

(These are all in the vanilla game.)

To use them, set ie.

```cpp
class FACTION(template) : B_Soldier_base_F {
    ...
    genericNames = "ChineseMen";
    ...
};
```

## Identities (voice, face, glasses)

The game contains something called `identityTypes`, which are "tags" used by
(referenced from) multiple subsystems, linking each other together. For example
a soldier class can specify

```cpp
class FACTION(template) : B_Soldier_base_F {
    ...
    identityTypes[] = {
        "LanguageENG_F",
        "Head_NATO",
        "G_NATO_default"
    };
    ...
};
```

with the first being a "tag" used by `CfgVoice` in its definitions, ie.

```cpp
class CfgVoice {
    ...
    class ENG : Base {
        protocol = "RadioProtocolENG";
        identityTypes[] = {
            "default",
            "Head_USMC",
            "Head_USMC_CO",
            ...
            "Head_Special",
            "LanguageENG_F"
        };
        ...
```

the second being a "tag" in `CfgFaces`, ie.

```cpp
class CfgFaces {
    ...
    class Man_A3 : Default {
        ...
        class WhiteHead_01 : Default {
            ...
            identityTypes[] = {
                "Head_NATO",
                "Head_Euro"
            };
            ...
```

and the third one referring to a "tag" in `CfgGlasses` with (presumably)
weighted ratios, ie.

```cpp
class CfgGlasses {
    ...
    class None {
        ...
        identityTypes[] = {
            "G_RUS_SF",
            50,
            "G_CIVIL_aidworker",
            200,
            ...
            "NoGlasses",
            1000,
            "G_NATO_default",
            300,
            ...
        };
    };
    class G_Shades_Black : None {
        identityTypes[] = {
            "G_CIVIL_aidworker",
            100,
            "G_CIVIL_constructionworker",
            120,
            "G_CIVIL_man",
            80,
            ...
```

So the way you assemble `identityTypes` for your soldiers is kinda indirectly -
you don't specify classnames, but indirect "tags" the other `Cfg*` declare as
well.  
This allows for randomization based on, well, "identity types", but makes it
hard to ie. always get specific glasses - if you need that, see
[a section specifically dedicated to it](#specific-soldier-facewear).

Nb. faces are actually under the `Man_A3` subclass (as you can see above), which
is set via `faceType` string property in the soldier class. Unless you're making
a fireteam of rabbits, don't worry about it.

### Commonly used `identityTypes` tags

* Voices
  * vanilla: `LanguageENG_F`, `LanguageCHI_F`, `LanguageGRE_F`, `LanguageFRE_F`,
    `LanguageENGFRE_F`, `LanguageENGB_F`, `LanguagePER_F`, `LanguageRUS_F`,
    `LanguagePOL_F`
    * (PER seems CSAT, POL are Polish Contact DLC voices)
    * (newer RHS just re-uses vanilla `LanguageRUS_F`)
  * 3CB: `LanguageCZ`
    * (3CB re-uses vanilla `LanguagePER_F` for Takistan forces)
* Faces
  * vanilla: `Head_NATO`, `Head_Greek`, `Head_Tanoan`, `Head_TK`, `Head_Enoch`,
    `Head_Russian`, `Head_NATO_camo_lush`, `Head_NATO_camo_semiarid`,
    `Head_NATO_camo_arid`
    * (`_camo_*` also exist for other heads)
    * (TK is CSAT, Enoch is Contact DLC)
    * or more generic categories: `Head_African`, `Head_Euro`, `Head_Asian`
* Glasses
  * vanilla: `G_NATO_default`, `G_NATO_pilot`, `G_NATO_diver`, `G_NATO_sniper`,
    `G_CIVIL_male`, `NoGlasses`, `G_GUERIL_default`, `G_HAF_default`,
    `G_NATO_casual`, `G_HAF_default`, `G_IRAN_default`, `G_IRAN_diver`,
    `G_CIV_exp`, `G_RUS_SF`
    * (IRAN are CSAT, "exp" is Apex/Tanoa DLC)
  * RHS: `rhs_scarf`, `rhsusf_g_army`, `rhsusf_g_usmc`

### Radio reports

"Contact, 12 o'clock, AT soldier, 200" - the "AT soldier" part is `textSingular`,
`textPlural` and `nameSound`, specified in the soldier class.  

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    nameSound = "veh_infantry_AT_s";
    textPlural = "AT soldiers";
    textSingular = "AT soldier";
    ...
};
```

Some commonly used values are:

```cpp
nameSound = "veh_infantry_s";
textPlural = "infantry";
textSingular = "infantry";

nameSound = "veh_infantry_MG_s";
textPlural = "machinegunners";
textSingular = "machinegunner";

nameSound = "veh_infantry_AT_s";
textPlural = "AT soldiers";
textSingular = "AT soldier";

nameSound = "veh_infantry_medic_s";
textPlural = "medics";
textSingular = "medic";

nameSound = "veh_infantry_sniper_s";
textPlural = "snipers";
textSingular = "sniper";

nameSound = "veh_infantry_SF_s";
textPlural = "specops";
textSingular = "specop";
```

For CNTO specifically, you don't really need to specify these, as we configure
ACE to silence any AI radio reports.

## Editor factions and subcategories

Editor (main) categories come from the old 2D editor concept of "factions".
These come from `CfgFactionClasses` and have names like `BLU_F`, `OPF_F`,
`IND_F`, `BLU_G_F`, etc. These are the "NATO", "CSAT", "CTRG", etc. main unit
categories in editor/Zeus.  
You could just place your soldiers under NATO, but we create one new faction
class per one faction `pbo` automatically, see `config.cpp`.

To use them, your soldier config must specify `faction =`. To automatically
pre-fill it with the one created for you, use `FACTION_CLASSNAME`:

```cpp
class FACTION(template) : B_Soldier_base_F {
    ...
    faction = FACTION_CLASSNAME;
    ...
};
```

Subcategories are the "Man", "Drones", "Helicopters", "Cars", etc. under the
main categories and are a new concept in Eden, defined in
`CfgEditorSubcategories`, for example `EdSubcat_Personnel`, `EdSubcat_Cars`,
`EdSubcat_APCs`, `EdSubcat_Personnel_SpecialForces`, etc.  
You should probably re-use these without creating custom ones, by specifying
the appropriate one in the soldier config, ie.

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    editorSubcategory = "EdSubcat_Personnel_SpecialForces";
    ...
};
```

(Or you can just leave the default, inherited from parents, which is "Man"
for `B_Soldier_base_F` and will be "Car", "IFVs", etc. for vehicles you
define, specified by whatever you inherit.)

If you really need your custom one, do (in `config.cpp`):

```cpp
class CfgEditorSubcategories {
    ...
    class FACTION(memers) {
        displayName = "Memers";
    };
};
```

and then use it as `editorSubcategory = FACTION(memers);`.

### Subcategory for crates

Note that `config.cpp` actually does create a new subcategory named after your
faction - that one is for crates / supply boxes, to categorize them under
Supplies -> Your Faction Name, instead of Ammo, which is overcrowded with other
vanilla/modded boxes.

To use it for your crate, specify it like for a soldier above:

```cpp
class FACTION(test_crate) : Box_NATO_WpsSpecial_F {
    ...
    editorSubcategory = FACTION_CLASSNAME;
    ...
};
```

## Vehicle cargo and crates

"Cargo", as the engine calls it, has its own loadout definition incompatible
with `setUnitLoadout` used for soldiers.

This is split into `TransportWeapons`, `TransportMagazines`, `TransportItems`
and `TransportBackpacks`.  
Note that hand grenades/smokes are actually magazines for a hidden Throw weapon
and plantable explosives are magazines for a hidden Put weapon, neither are
"items".

Inside these `Transport*` classes, use the `TWEAPON`, `TMAGAZINE`, `TITEM`
and `TBACKPACK` macros, which will make life much easier for you.

In `CfgVehicles.h`, somewhere below all the soldiers:

```cpp
class Box_NATO_WpsSpecial_F;

class FACTION(test_crate) : Box_NATO_WpsSpecial_F {
    ...
    class TransportWeapons {
        TWEAPON(1, arifle_Katiba_GL_F);
        TWEAPON(1, arifle_Katiba_ACO_pointer_snds_F);
    };
    class TransportMagazines {
        TMAGAZINE(10, 30Rnd_65x39_caseless_green);
        TMAGAZINE(4, 30Rnd_65x39_caseless_green_mag_Tracer);
        TMAGAZINE(4, 1Rnd_Smoke_Grenade_shell);
        TMAGAZINE(2, HandGrenade);
        TMAGAZINE(4, MiniGrenade);
        TMAGAZINE(6, SmokeShellOrange);
    };
    class TransportItems {
        TITEM(1, optic_DMS);
        TITEM(2, U_B_CTRG_1);
        TITEM(2, V_PlateCarrierGL_rgr);
        TITEM(2, H_HelmetB_grass);
        TITEM(1, Binocular);
        TITEM(1, Laserdesignator);
    };
    class TransportBackpacks {
        TBACKPACK(2, B_AssaultPack_dgtl);
    };
};
```

(This would need `"A3_Weapons_F_Ammoboxes"` in `requiredAddons[]` in
our `config.cpp`, so that we can inherit from `Box_NATO_WpsSpecial_F`.)

To clear out an existing `Transport*` class, simply specify it as empty,
overriding anything inherited, ie.

```cpp
    class TransportItems {};
```

To clear out all cargo, there's a shorthand macro that is just all 4 of the
`Transport*` classes defined as empty:

```cpp
    EMPTY_CARGO_LOADOUT;
```

(Obviously, you cannot combine this with any `Transport*` definition, so
use it only if you really want an empty crate.)

Finally, note that vehicle / box cargo is customizable by the mission maker
in editor attributes and all of the above works smoothly with the customization.

## Soldier and group icons

Soldier icons are the things visible on squad radar hud, and also in the soldier
list in editor/Zeus (circle with upwards arrow).  
They are defined in `CfgVehicleIcons` and some commonly used values include
`iconMan`, `iconManLeader`, `iconManOfficer`, `iconManAT`, `iconManMedic`,
`iconManMG`, `iconManEngineer`, `iconManExplosive`, but there are many more for
parachutes, cars, APCs, supply boxes, etc.

```cpp
class FACTION(mysoldier) : FACTION(template) {
    ...
    icon = "iconManOfficer";
    ...
};
```

Group icons are NATO symbols for infantry, HQ, etc. and they reside in
`cfgGroupIcons`, for example `b_inf`, `b_air`, `n_mortar`, `o_naval`, etc.
There are some standard sets of icons for BLUFOR (`b`), GREENFOR/NEURAL (`n`)
and OPFOR (`o`), and some non-standard extra icons (ie. for civilians).

All three sets (`b`/`o`/`n`) support `air`, `antiair`, `armor`, `art`, `hq`,
`inf`, `installation`, `maint`, `mech_inf`, `med`, `mortar`, `motor_inf`,
`naval`, `plane`, `recon`, `service`, `support`, `uav`, `unknown`.

Group definitions unfortunately accept only full `.paa` paths, but you can use
the custom `GRP_ICON` macro to make this a non-issue.

```cpp
...
class Infantry {
    ...
    class Officer_Gang {
        ...
        icon = GRP_ICON(b_inf);
        ...
    };
};
```

To automatically prefix `b_` / `o_` / `n_` depending on your faction side,
use the `NATO_ICON` macro instead, ie. `NATO_ICON(inf)`.

## Groups

Groups are defined in `CfgGroups` under a per-faction namespace.
While units require editor categories/subcategories to be already existing
(or created explicitly by you), group categories are completely free-form -
you can freely name them as well as the groups themselves.

Each group needs `Unit0` .. `UnitN` specifications and (unfortunately) position
of each unit within the group formation - this is best set to the default wedge,
ie.

```
{0,0,0}
{5,-5,0}
{-5,-5,0}
{10,-10,0}
{-10,-10,0}
{15,-15,0}
{-15,-15,0}
{20,-20,0}
...
```

If you use anything else, the group will spawn according to your placement,
but the AI units will quickly start moving and forming a wedge (see RHS squads),
so it's best to prevent this movement by the values above.

Each unit also has `rank`, which is (from lowest to highest)

```
PRIVATE
CORPORAL
SERGEANT
LIEUTENANT
CAPTAIN
MAJOR
COLONEL
```

The only unfortunate thing is repeating of `faction` and `side`, both required
by Zeus and/or some 3rd party mission scripts.

For example,

```cpp
class Infantry {
    name = "Infantry";
    class Fireteam {
        name = "Fireteam";
        icon = NATO_ICON(recon);
        faction = FACTION_CLASSNAME;
        side = FACTION_SIDE_NR;
        class Unit0 { vehicle = FACTION(ft_leader);    position[] = {0,0,0};    rank = "SERGEANT"; side = FACTION_SIDE_NR; };
        class Unit1 { vehicle = FACTION(autorifleman); position[] = {5,-5,0};   rank = "PRIVATE";  side = FACTION_SIDE_NR; };
        class Unit2 { vehicle = FACTION(ar_assist);    position[] = {-5,-5,0};  rank = "CORPORAL"; side = FACTION_SIDE_NR; };
        class Unit3 { vehicle = FACTION(antitank);     position[] = {10,-10,0}; rank = "PRIVATE";  side = FACTION_SIDE_NR; };
    };
    class Squad {
        ...
```

### Assigned vehicles

Arma 3 has a concept of an "assigned" vehicle in a group - there are scripting
commands to assign/unassign a vehicle to/from a group. When assigned, the group
will use the vehicle for transport - ie. as motorized infantry.

You don't need to do anything special to make this work, simply put the vehicle
classname where a soldier classname would be in a group.

Note that this has to be your custom version of the vehicle if you want it to be
pre-filled with your own crew (defined in the vehicle class as `crew`).

## Specific soldier facewear

The facewear (glasses) from `identityTypes[]` don't mesh well together with
the ones in a `setUnitLoadout` (ACE Arsenal) loadout:

* editor-placed units get facewear from `identityTypes[]` while in editor
* editor-placed units use `setUnitLoadout` on actual game start
* zeus-placed get `identityTypes[]`

This inconsistency is "fixed" by the `setLoadout` function saving/restoring
facewear before/after `setUnitLoadout`, making `identityTypes[]` be always
used.

If you don't want the randomization of `identityTypes[]` and need to set
specific facewear, do in `config.cpp`:

```cpp
class Extended_InitPost_EventHandlers {
    class FACTION(template) {
        class FACTION(set_custom_facewear) {
            init = "(_this select 0) addGoggles 'G_Tactical_Clear'";
        };
    };
};
```

or using a macro (no space after `,`):

```cpp
class Extended_InitPost_EventHandlers {
    XEH_FACEWEAR(template,G_Tactical_Clear);
};
```

This will force specific facewear **after** the soldier initialization,
overriding anything else (even player facewear if the soldier is a playable
unit). The facewear won't appear while in editor, but it always is correctly
assigned when the game starts, and to anything Zeus-spawned.

When doing this, specify `"NoGlasses"` in `identityTypes[]` in place of the
glasses/facewear, so that the randomization never happens.

If you need different facewear for different soldiers, simply specify their
classnames instead of the template:

```cpp
class Extended_InitPost_EventHandlers {
    FACTION_XEH_FACEWEAR(squad_leader,G_Bandanna_aviator);
    FACTION_XEH_FACEWEAR(fireteam_leader,G_Squares_Tinted);
};
```
