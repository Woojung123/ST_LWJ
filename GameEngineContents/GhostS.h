
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class SGbullet;
class GameEngineTextureRenderer;
class GhostS : public UnitBase
{
public:
	// constrcuter destructer
	GhostS();
	~GhostS();

	// delete Function
	GhostS(const GhostS& _Other) = delete;
	GhostS(GhostS&& _Other) noexcept = delete;
	GhostS& operator=(const GhostS& _Other) = delete;
	GhostS& operator=(GhostS&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	void AttEnd(const FrameAnimation_DESC& _Info);

	//TerranBaseBullet
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* AuraRenderer;


	SGbullet* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;


	int	BulletType;
	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;
};

