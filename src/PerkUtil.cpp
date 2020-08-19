#include "PerkUtil.h"
#include "ActorValueUtil.h"

namespace PerkUtil {
	BSTArray<BGSPerk*> Append(BSTArray<BGSPerk*> array, BSTArray<BGSPerk*> appendix) {
		for (BGSPerk* perk : appendix) {
			array.push_back(perk);
		}
		return array;
	}
	BSTArray<BGSSkillPerkTreeNode*> Append(BSTArray<BGSSkillPerkTreeNode*> array, BSTArray<BGSSkillPerkTreeNode*> appendix) {
		for (BGSSkillPerkTreeNode* node : appendix) {
			array.push_back(node);
		}
		return array;
	}
	BSTArray<BGSSkillPerkTreeNode*> DFS(BGSSkillPerkTreeNode* root, BSTArray<BGSSkillPerkTreeNode*> visitedNodes) {
		visitedNodes.push_back(root);
		for (BGSSkillPerkTreeNode* child : root->children) {
			if (!Visited(child, visitedNodes))
				visitedNodes = DFS(child, visitedNodes);
		}
		return visitedNodes;
	}
	BSTArray<BGSPerk*> GetAllSkillPerks() {
		BSTArray<BGSPerk*> perks;
		constexpr int startingSkillIndex = to_underlying(ActorValue::kOneHanded);
		int numSkills = TESNPC::Skills::kTotal;
		for (int i = startingSkillIndex; i < startingSkillIndex + numSkills; i++) {
			perks = Append(perks, ActorValueUtil::GetSkillPerks(static_cast<ActorValue>(i)));
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