#include "PerkUtil.h"
#include "ActorValueUtil.h"
#include "BSTArrayUtil.h"

namespace PerkUtil {
	BSTArray<BGSSkillPerkTreeNode*> DFS(BGSSkillPerkTreeNode* root, BSTArray<BGSSkillPerkTreeNode*> visitedNodes) {
		if (root) {
			visitedNodes.push_back(root);
			for (BGSSkillPerkTreeNode* child : root->children) {
				if (!Visited(child, visitedNodes))
					visitedNodes = DFS(child, visitedNodes);
			}
		}
		return visitedNodes;
	}
	BSTArray<BGSPerk*> GetAllSkillPerks() {
		BSTArray<BGSPerk*> perks;
		constexpr int startingSkillIndex = RE::to_underlying(ActorValue::kOneHanded);
		int numSkills = TESNPC::Skills::kTotal;
		for (int i = startingSkillIndex; i < startingSkillIndex + numSkills; i++) {
			perks = BSTArrayUtil::Append<BGSPerk>(perks, ActorValueUtil::GetSkillPerks(static_cast<ActorValue>(i)));
		}
		return perks;
	}
	bool Visited(BGSSkillPerkTreeNode* node, BSTArray<BGSSkillPerkTreeNode*> visitedNodes) {
		for (BGSSkillPerkTreeNode* visitedNode : visitedNodes)
			if (node == visitedNode)
				return true;
		return false;
	}
}