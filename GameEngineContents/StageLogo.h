
#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class StageLogo : public GameEngineLevel
{
public:
	// constrcuter destructer
	StageLogo();
	~StageLogo();

	// delete Function
	StageLogo(const StageLogo& _Other) = delete;
	StageLogo(StageLogo&& _Other) noexcept = delete;
	StageLogo& operator=(const StageLogo& _Other) = delete;
	StageLogo& operator=(StageLogo&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

};

