

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class TerranBaseBullet : public UnitBase
{
public:
	// constrcuter destructer
	TerranBaseBullet();
	~TerranBaseBullet();

	// delete Function
	TerranBaseBullet(const TerranBaseBullet& _Other) = delete;
	TerranBaseBullet(TerranBaseBullet&& _Other) noexcept = delete;
	TerranBaseBullet& operator=(const TerranBaseBullet& _Other) = delete;
	TerranBaseBullet& operator=(TerranBaseBullet&& _Other) noexcept = delete;

public:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;
	GameEngineTextureRenderer* Renderer;
	GameEngineActor* TarGet;
	float4 Color;

private:
	bool	DamCheck;
	float Speed;
	float4 m_Dir;

};
