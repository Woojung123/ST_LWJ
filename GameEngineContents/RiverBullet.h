

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class RiverBullet : public UnitBase
{
public:
	// constrcuter destructer
	RiverBullet();
	~RiverBullet();

	// delete Function
	RiverBullet(const RiverBullet& _Other) = delete;
	RiverBullet(RiverBullet&& _Other) noexcept = delete;
	RiverBullet& operator=(const RiverBullet& _Other) = delete;
	RiverBullet& operator=(RiverBullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;
	float TrailTime;
	bool	DamCheck;

public:
	GameEngineActor* TarGet;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

