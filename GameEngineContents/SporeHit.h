
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SporeHit : public UnitBase
{
public:
	// constrcuter destructer
	SporeHit();
	~SporeHit();

	// delete Function
	SporeHit(const SporeHit& _Other) = delete;
	SporeHit(SporeHit&& _Other) noexcept = delete;
	SporeHit& operator=(const SporeHit& _Other) = delete;
	SporeHit& operator=(SporeHit&& _Other) noexcept = delete;

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
