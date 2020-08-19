#pragma once

using namespace RE;

namespace ActorValueUtil {
	ActorValueInfo* GetActorValueInfo(ActorValue av);
	BSTArray<BGSPerk*> GetAllPerkRanks(BGSPerk* perk);
	BSTArray<BGSPerk*> GetSkillPerks(ActorValue av);
	BGSSkillPerkTreeNode* GetSkillPerkTree(ActorValue av);
}