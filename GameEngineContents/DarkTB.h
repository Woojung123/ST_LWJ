

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class GameEngineTextureRenderer;
class DarkTB : public UnitBase
{
public:
	// constrcuter destructer
	DarkTB();
	~DarkTB();

	// delete Function
	DarkTB(const DarkTB& _Other) = delete;
	DarkTB(DarkTB&& _Other) noexcept = delete;
	DarkTB& operator=(const DarkTB& _Other) = delete;
	DarkTB& operator=(DarkTB&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}


	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* BiconRenderer;
	GameEngineTextureRenderer* Renderer;

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	int		AttCount;
	int		AttCountMax;
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

