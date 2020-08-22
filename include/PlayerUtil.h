#pragma once

#include "ActorUtil.h"

namespace PlayerUtil {
	class ActorToPlayerCopier : public ActorUtil::ActorCopier {
	public:
		ActorToPlayerCopier(PlayerCharacter* player, Actor* actor);

		void AddTeachableSpells();
		void CopyAppearance();
		void CopyRace();
	private:
		PlayerCharacter* player;
		Actor* actor;
	};

	void ModPerkPoints(PlayerCharacter* player, int mod);
	void RefundPerks(PlayerCharacter* player);
	void ResetPlayerTintMasks(PlayerCharacter* player);
}