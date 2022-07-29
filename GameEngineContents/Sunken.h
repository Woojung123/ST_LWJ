


#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class Sunken : public UnitBase
{
public:
	// constrcuter destructer
	Sunken();
	~Sunken();

	// delete Function
	Sunken(const Sunken& _Other) = delete;
	Sunken(Sunken&& _Other) noexcept = delete;
	Sunken& operator=(const Sunken& _Other) = delete;
	Sunken& operator=(Sunken&& _Other) noexcept = delete;

public:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;
	GameEngineActor* TarGet;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	bool	DamCheck;
	float Speed;
	float4 m_Dir;

};
