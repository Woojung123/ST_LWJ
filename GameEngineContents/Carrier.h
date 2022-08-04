
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class mutalBullet;
class GameEngineTextureRenderer;
class Carrier : public UnitBase
{
public:
	// constrcuter destructer
	Carrier();
	~Carrier();

	// delete Function
	Carrier(const Carrier& _Other) = delete;
	Carrier(Carrier&& _Other) noexcept = delete;
	Carrier& operator=(const Carrier& _Other) = delete;
	Carrier& operator=(Carrier&& _Other) noexcept = delete;

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
	mutalBullet* TestUni;
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

