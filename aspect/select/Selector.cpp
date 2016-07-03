#include "../../Engine.hpp"

namespace cc {
	
	bool Selector::runSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		nEntity->startSelect(mSelectId);
		
		ConditionEngine& conditionEngine_ = ConditionEngine::instance();
		int8_t result_ = conditionEngine_.runCondition(mConditionId, nEntity, nValue);
		if ( (0x1 & result_) > 0 ) {
			RewardEngine& rewardEngine_ = RewardEngine::instance();
			rewardEngine_.runReward(mRewardId, nEntity, nValue);
		}
		return ( (0x2 & result_) > 0 );
	}
	
	int8_t Selector::getKey()
	{
		return mSelectId;
	}
	
	Selector::Selector()
		: mConditionId (0)
		, mRewardId (0)
		, mSelectId (0)
	{
	}
	
	Selector::~Selector()
	{
		mConditionId = 0;
		mRewardId = 0;
		mSelectId = 0;
	}
	
}
