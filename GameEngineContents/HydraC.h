

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Sunken;
class GameEngineTextureRenderer;
class HydraC : public UnitBase
{
public:
	// constrcuter destructer
	HydraC();
	~HydraC();

	// delete Function
	HydraC(const HydraC& _Other) = delete;
	HydraC(HydraC&& _Other) noexcept = delete;
	HydraC& operator=(const HydraC& _Other) = delete;
	HydraC& operator=(HydraC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;



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

