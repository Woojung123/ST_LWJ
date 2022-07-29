

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class ProDeath : public GameEngineActor
{
public:
	// constrcuter destructer
	ProDeath();
	~ProDeath();

	// delete Function
	ProDeath(const ProDeath& _Other) = delete;
	ProDeath(ProDeath&& _Other) noexcept = delete;
	ProDeath& operator=(const ProDeath& _Other) = delete;
	ProDeath& operator=(ProDeath&& _Other) noexcept = delete;

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
