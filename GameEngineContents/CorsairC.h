
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class CorSplash;
class GameEngineTextureRenderer;
class CorsairC : public UnitBase
{
public:
	// constrcuter destructer
	CorsairC();
	~CorsairC();

	// delete Function
	CorsairC(const CorsairC& _Other) = delete;
	CorsairC(CorsairC&& _Other) noexcept = delete;
	CorsairC& operator=(const CorsairC& _Other) = delete;
	CorsairC& operator=(CorsairC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	CorSplash* TestUni;
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

