

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class RiverBullet;
class GameEngineTextureRenderer;
class River : public UnitBase
{
public:
	// constrcuter destructer
	River();
	~River();

	// delete Function
	River(const River& _Other) = delete;
	River(River&& _Other) noexcept = delete;
	River& operator=(const River& _Other) = delete;
	River& operator=(River&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	void AttEnd(const FrameAnimation_DESC& _Info);

	//TerranBaseBullet
	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* AuraRenderer;
	RiverBullet* TestUni;
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

