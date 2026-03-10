#pragma once
#include "../../SDK/SDK.h"

Enum(Bind, Key, Class, WeaponType, ItemSlot, Misc, ClassAndKey, UnderHP, PlayerCount, ExactWeapon, Charging, IfOptionOn, Ticks, GameMode)
namespace BindEnum
{
	Enum(Key, Hold, Toggle, DoubleClick)
	Enum(Class, Scout, Soldier, Pyro, Demoman, Heavy, Engineer, Medic, Sniper, Spy)
	Enum(WeaponType, Hitscan, Projectile, Melee, Throwable)
	Enum(Misc, Spectated, SpectatedFirst, SpectatedThird, Zoomed, Aiming)
	Enum(GameMode, Casual, Private)
}
Enum(BindVisibility, Always, WhileActive, Hidden)

struct Bind_t
{
	std::string m_sName = "";
	int m_iType = 0;
	int m_iInfo = 0;
	int m_iKey = 0;

	bool m_bEnabled = true;
	int m_iVisibility = BindVisibilityEnum::Always;
	bool m_bNot = false;
	bool m_bActive = false;
	KeyStorage m_tKeyStorage = {};

	int m_iParent = DEFAULT_BIND;

	std::vector<BaseVar*> m_vVars = {};

	// Extra data for configurable bind types
	int m_iExtraInt = 0;       // used by UnderHP (hp threshold), PlayerCount (count), Ticks (tick count)
	int m_iExtraInt2 = 0;      // used by ClassAndKey (class enum)
	int m_iExtraKey = 0;       // used by ClassAndKey (second key)
	int m_iExtraWeaponID = 0;  // used by ExactWeapon (item def index)
	std::string m_sOptionName = ""; // used by IfOptionOn (var name)
};

class CBinds
{
public:
	void Run();
	void SetVars(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, bool bManage = true);

	bool GetBind(int iID, Bind_t* pBind);

	void AddBind(int iBind, Bind_t& tCond);
	void RemoveBind(int iBind, bool bForce = true);
	int GetParent(int iBind);
	bool HasChildren(int iBind);
	bool WillBeEnabled(int iBind);

	void Move(int i1, int i2);

	std::vector<Bind_t> m_vBinds = {};
	bool m_bDisplay = false;
};

ADD_FEATURE(CBinds, Binds);