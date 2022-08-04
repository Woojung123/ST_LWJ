
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SGExMid : public UnitBase
{
public:
	// constrcuter destructer
	SGExMid();
	~SGExMid();

	// delete Function
	SGExMid(const SGExMid& _Other) = delete;
	SGExMid(SGExMid&& _Other) noexcept = delete;
	SGExMid& operator=(const SGExMid& _Other) = delete;
	SGExMid& operator=(SGExMid&& _Other) noexcept = delete;

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
