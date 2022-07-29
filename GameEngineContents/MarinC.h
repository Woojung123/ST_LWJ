
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class TerranBaseBullet;
class GameEngineTextureRenderer;
class MarinC : public UnitBase
{
public:
	// constrcuter destructer
	MarinC();
	~MarinC();

	// delete Function
	MarinC(const MarinC& _Other) = delete;
	MarinC(MarinC&& _Other) noexcept = delete;
	MarinC& operator=(const MarinC& _Other) = delete;
	MarinC& operator=(MarinC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}


	void AttEnd(const FrameAnimation_DESC& _Info);
	


	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	TerranBaseBullet* TestUni;
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

