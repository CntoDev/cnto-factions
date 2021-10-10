#include "details.h"
#include "\cnto\factions\shared\include.h"

if (is3DEN) exitWith {};

params ["_quad"];

if (!local _quad) exitWith {};

private _box = createVehicle [QFACTION(mines_box), [0,0,-9500], [], 0, 'NONE'];
_box attachTo [_quad, [-0.0410,-0.8242,-0.2548]];
