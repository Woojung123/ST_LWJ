
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class BloodBullet : public UnitBase
{
public:
	// constrcuter destructer
	BloodBullet();
	~BloodBullet();

	// delete Function
	BloodBullet(const BloodBullet& _Other) = delete;
	BloodBullet(BloodBullet&& _Other) noexcept = delete;
	BloodBullet& operator=(const BloodBullet& _Other) = delete;
	BloodBullet& operator=(BloodBullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;
	bool	DamCheck;
	
public:
	GameEngineActor* TarGet;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

