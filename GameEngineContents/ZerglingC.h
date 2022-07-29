
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Sunken;
class GameEngineTextureRenderer;
class ZerglingC : public UnitBase
{
public:
	// constrcuter destructer
	ZerglingC();
	~ZerglingC();

	// delete Function
	ZerglingC(const ZerglingC& _Other) = delete;
	ZerglingC(ZerglingC&& _Other) noexcept = delete;
	ZerglingC& operator=(const ZerglingC& _Other) = delete;
	ZerglingC& operator=(ZerglingC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);

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
	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;
};

