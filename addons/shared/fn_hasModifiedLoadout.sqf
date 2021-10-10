//
// return true if a soldier unit has loadout different to its Config-defined one
//

private _current = getUnitLoadout _this;

// don't use configOf here, getUnitLoadout returns bad data
private _default = getUnitLoadout typeOf _this;

// don't compare facewear, it's always different
_current deleteAt 7;
_default deleteAt 7;

_current isNotEqualTo _default;
