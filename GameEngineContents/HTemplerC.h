#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Sunken;
class GameEngineTextureRenderer;
class HTemplerC : public UnitBase
{
public:
	// constrcuter destructer
	HTemplerC();
	~HTemplerC();

	// delete Function
	HTemplerC(const HTemplerC& _Other) = delete;
	HTemplerC(HTemplerC&& _Other) noexcept = delete;
	HTemplerC& operator=(const HTemplerC& _Other) = delete;
	HTemplerC& operator=(HTemplerC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	Sunken* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;

	bool	AttCheck;
	bool	ListLastCheck;
};

