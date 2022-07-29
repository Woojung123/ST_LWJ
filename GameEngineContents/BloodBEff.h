

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class BloodBEff : public UnitBase
{
public:
	// constrcuter destructer
	BloodBEff();
	~BloodBEff();

	// delete Function
	BloodBEff(const BloodBEff& _Other) = delete;
	BloodBEff(BloodBEff&& _Other) noexcept = delete;
	BloodBEff& operator=(const BloodBEff& _Other) = delete;
	BloodBEff& operator=(BloodBEff&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
