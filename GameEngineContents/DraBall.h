
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class DraBall : public UnitBase
{
public:
	// constrcuter destructer
	DraBall();
	~DraBall();

	// delete Function
	DraBall(const DraBall& _Other) = delete;
	DraBall(DraBall&& _Other) noexcept = delete;
	DraBall& operator=(const DraBall& _Other) = delete;
	DraBall& operator=(DraBall&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;
	GameEngineActor* TarGet;
public:
	void SetTarGet(GameEngineActor* _TarGet) 
	{
		TarGet = _TarGet;
	}
};

