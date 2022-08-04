

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class CorSplash : public UnitBase
{
public:
	// constrcuter destructer
	CorSplash();
	~CorSplash();

	// delete Function
	CorSplash(const CorSplash& _Other) = delete;
	CorSplash(CorSplash&& _Other) noexcept = delete;
	CorSplash& operator=(const CorSplash& _Other) = delete;
	CorSplash& operator=(CorSplash&& _Other) noexcept = delete;

public:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;
	GameEngineActor* TarGet;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	bool	DamCheck;
	float Speed;
	float4 m_Dir;

};
