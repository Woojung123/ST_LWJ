

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class DraBallEff : public UnitBase
{
public:
	// constrcuter destructer
	DraBallEff();
	~DraBallEff();

	// delete Function
	DraBallEff(const DraBallEff& _Other) = delete;
	DraBallEff(DraBallEff&& _Other) noexcept = delete;
	DraBallEff& operator=(const DraBallEff& _Other) = delete;
	DraBallEff& operator=(DraBallEff&& _Other) noexcept = delete;

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
