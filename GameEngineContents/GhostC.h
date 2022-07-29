
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class BloodBullet;
class GameEngineTextureRenderer;
class GhostC : public UnitBase
{
public:
	// constrcuter destructer
	GhostC();
	~GhostC();

	// delete Function
	GhostC(const GhostC& _Other) = delete;
	GhostC(GhostC&& _Other) noexcept = delete;
	GhostC& operator=(const GhostC& _Other) = delete;
	GhostC& operator=(GhostC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	void AttEnd(const FrameAnimation_DESC& _Info);

	//TerranBaseBullet
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

