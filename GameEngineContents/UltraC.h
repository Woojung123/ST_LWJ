
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class GameEngineTextureRenderer;
class UltraC : public UnitBase
{
public:
	// constrcuter destructer
	UltraC();
	~UltraC();

	// delete Function
	UltraC(const UltraC& _Other) = delete;
	UltraC(UltraC&& _Other) noexcept = delete;
	UltraC& operator=(const UltraC& _Other) = delete;
	UltraC& operator=(UltraC&& _Other) noexcept = delete;

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

