
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SGbullet : public UnitBase
{
public:
	// constrcuter destructer
	SGbullet();
	~SGbullet();

	// delete Function
	SGbullet(const SGbullet& _Other) = delete;
	SGbullet(SGbullet&& _Other) noexcept = delete;
	SGbullet& operator=(const SGbullet& _Other) = delete;
	SGbullet& operator=(SGbullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

public:
	float Speed;
	int		EffType;
	bool	DamCheck;
	float4 m_Dir;
	GameEngineActor* TarGet;
public:
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

