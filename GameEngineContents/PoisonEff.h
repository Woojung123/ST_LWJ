
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class PoisonEff : public UnitBase
{
public:
	// constrcuter destructer
	PoisonEff();
	~PoisonEff();

	// delete Function
	PoisonEff(const PoisonEff& _Other) = delete;
	PoisonEff(PoisonEff&& _Other) noexcept = delete;
	PoisonEff& operator=(const PoisonEff& _Other) = delete;
	PoisonEff& operator=(PoisonEff&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

	float m_dotDam;
	
public:
	GameEngineActor* TarGet;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

