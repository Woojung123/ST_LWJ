

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SGExSmall : public UnitBase
{
public:
	// constrcuter destructer
	SGExSmall();
	~SGExSmall();

	// delete Function
	SGExSmall(const SGExSmall& _Other) = delete;
	SGExSmall(SGExSmall&& _Other) noexcept = delete;
	SGExSmall& operator=(const SGExSmall& _Other) = delete;
	SGExSmall& operator=(SGExSmall&& _Other) noexcept = delete;

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
