


#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Storm;
class GameEngineTextureRenderer;
class HighT : public UnitBase
{
public:
	// constrcuter destructer
	HighT();
	~HighT();

	// delete Function
	HighT(const HighT& _Other) = delete;
	HighT(HighT&& _Other) noexcept = delete;
	HighT& operator=(const HighT& _Other) = delete;
	HighT& operator=(HighT&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;



	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* BiconRenderer;

	Storm* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;


	bool	BATTDelayTime;
	float	FATTDelayTime;
	bool	AttCheck;
	bool	ListLastCheck;
};

