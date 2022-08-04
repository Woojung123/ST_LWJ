

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class RiverTrail : public UnitBase
{
public:
	// constrcuter destructer
	RiverTrail();
	~RiverTrail();

	// delete Function
	RiverTrail(const RiverTrail& _Other) = delete;
	RiverTrail(RiverTrail&& _Other) noexcept = delete;
	RiverTrail& operator=(const RiverTrail& _Other) = delete;
	RiverTrail& operator=(RiverTrail&& _Other) noexcept = delete;

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
