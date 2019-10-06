#pragma once

#include <zenload/zCModelScript.h>
#include <Tempest/Matrix4x4>

#include "game/constants.h"
#include "pfxobjects.h"
#include "staticobjects.h"

class Serialize;
class Npc;
class Item;

class MdlVisual final {
  public:
    MdlVisual();
    MdlVisual(const MdlVisual&)=delete;

    void                           save(Serialize& fout);
    void                           load(Serialize& fin, Npc &npc);

    void                           setPos(const Tempest::Matrix4x4 &m);
    void                           setVisual(const Skeleton *visual);
    void                           setVisualBody(StaticObjects::Mesh &&h, StaticObjects::Mesh &&body);

    void                           setArmour     (StaticObjects::Mesh&& body);
    void                           setSword      (StaticObjects::Mesh&& sword);
    void                           setRangeWeapon(StaticObjects::Mesh&& bow);
    void                           setMagicWeapon(PfxObjects::Emitter&& spell);
    bool                           setFightMode(const ZenLoad::EFightMode mode);

    bool setToFightMode(const WeaponState ws);
    void                           updateWeaponSkeleton(const Item *sword, const Item *bow);
    void                           updateAnimation(Pose &pose);

    const Skeleton*                skeleton=nullptr;
    Tempest::Matrix4x4             pos;

  private:
    StaticObjects::Mesh            head;
    StaticObjects::Mesh            view;
    StaticObjects::Mesh            sword, bow;
    PfxObjects::Emitter            pfx;

    WeaponState                    fightMode=WeaponState::NoWeapon;
  };

