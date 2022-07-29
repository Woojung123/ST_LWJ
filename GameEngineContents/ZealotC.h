
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Sunken;
class GameEngineTextureRenderer;
class ZealotC : public UnitBase
{
public:
	// constrcuter destructer
	ZealotC();
	~ZealotC();

	// delete Function
	ZealotC(const ZealotC& _Other) = delete;
	ZealotC(ZealotC&& _Other) noexcept = delete;
	ZealotC& operator=(const ZealotC& _Other) = delete;
	ZealotC& operator=(ZealotC&& _Other) noexcept = delete;

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

