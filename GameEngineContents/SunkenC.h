
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Sunken;
class GameEngineTextureRenderer;
class SunkenC : public UnitBase
{
public:
	// constrcuter destructer
	SunkenC();
	~SunkenC();

	// delete Function
	SunkenC(const SunkenC& _Other) = delete;
	SunkenC(SunkenC&& _Other) noexcept = delete;
	SunkenC& operator=(const SunkenC& _Other) = delete;
	SunkenC& operator=(SunkenC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}


	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* Renderer;
	Sunken* TestUni;


	int		AttCount;
	int		AttCountMax;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;

	bool	AttCheck;
	bool	ListLastCheck;
};

