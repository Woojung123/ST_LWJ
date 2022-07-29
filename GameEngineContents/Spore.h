

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class Spore : public UnitBase
{
public:
	// constrcuter destructer
	Spore();
	~Spore();

	// delete Function
	Spore(const Spore& _Other) = delete;
	Spore(Spore&& _Other) noexcept = delete;
	Spore& operator=(const Spore& _Other) = delete;
	Spore& operator=(Spore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

public:
	float Speed;
	bool	DamCheck;
	float4 m_Dir;
	GameEngineActor* TarGet;
public:
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

