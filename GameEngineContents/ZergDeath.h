


#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class ZergDeath : public GameEngineActor
{
public:
	// constrcuter destructer
	ZergDeath();
	~ZergDeath();

	// delete Function
	ZergDeath(const ZergDeath& _Other) = delete;
	ZergDeath(ZergDeath&& _Other) noexcept = delete;
	ZergDeath& operator=(const ZergDeath& _Other) = delete;
	ZergDeath& operator=(ZergDeath&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
