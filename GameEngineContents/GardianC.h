
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Spore;
class GameEngineTextureRenderer;
class GardianC : public UnitBase
{
public:
	// constrcuter destructer
	GardianC();
	~GardianC();

	// delete Function
	GardianC(const GardianC& _Other) = delete;
	GardianC(GardianC&& _Other) noexcept = delete;
	GardianC& operator=(const GardianC& _Other) = delete;
	GardianC& operator=(GardianC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;

	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* AuraRenderer;
	Spore* TestUni;
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




	int		AttCount;
	int		AttCountMax;




};

