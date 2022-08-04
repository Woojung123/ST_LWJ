

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SGExBig : public UnitBase
{
public:
	// constrcuter destructer
	SGExBig();
	~SGExBig();

	// delete Function
	SGExBig(const SGExBig& _Other) = delete;
	SGExBig(SGExBig&& _Other) noexcept = delete;
	SGExBig& operator=(const SGExBig& _Other) = delete;
	SGExBig& operator=(SGExBig&& _Other) noexcept = delete;

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
