
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class RiverBoom : public UnitBase
{
public:
	// constrcuter destructer
	RiverBoom();
	~RiverBoom();

	// delete Function
	RiverBoom(const RiverBoom& _Other) = delete;
	RiverBoom(RiverBoom&& _Other) noexcept = delete;
	RiverBoom& operator=(const RiverBoom& _Other) = delete;
	RiverBoom& operator=(RiverBoom&& _Other) noexcept = delete;

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
