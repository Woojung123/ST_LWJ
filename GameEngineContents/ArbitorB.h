
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class BloodBullet;
class GameEngineTextureRenderer;
class ArbitorB : public UnitBase
{
public:
	// constrcuter destructer
	ArbitorB();
	~ArbitorB();

	// delete Function
	ArbitorB(const ArbitorB& _Other) = delete;
	ArbitorB(ArbitorB&& _Other) noexcept = delete;
	ArbitorB& operator=(const ArbitorB& _Other) = delete;
	ArbitorB& operator=(ArbitorB&& _Other) noexcept = delete;

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
	BloodBullet* TestUni;
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

