
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class mutalBullet : public UnitBase
{
public:
	// constrcuter destructer
	mutalBullet();
	~mutalBullet();

	// delete Function
	mutalBullet(const mutalBullet& _Other) = delete;
	mutalBullet(mutalBullet&& _Other) noexcept = delete;
	mutalBullet& operator=(const mutalBullet& _Other) = delete;
	mutalBullet& operator=(mutalBullet&& _Other) noexcept = delete;

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
	int		TarGetNum;
public:
	GameEngineActor* TarGet;
	GameEngineActor* TarGet2;
	GameEngineActor* TarGet3;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

